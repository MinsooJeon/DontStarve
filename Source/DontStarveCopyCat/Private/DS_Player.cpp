// Fill out your copyright notice in the Description page of Project Settings.


#include "DontStarveCopyCat/Public/DS_Player.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GatherableBush.h"
#include "InputMappingContext.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADS_Player::ADS_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	//카메라 암 절대회전 
	SpringArmComp->SetUsingAbsoluteRotation(true);
	//위에서 아래로 바라보기
	SpringArmComp->SetWorldRotation(FRotator(-50.f, 0, 0));
	//카메라 암 길이
	SpringArmComp->TargetArmLength = 1400.f;
	//카메라 클리핑 해제
	SpringArmComp->bDoCollisionTest = false;
	//카메라 Lag 활성화(지연을 통한 자연스러운 이동) 속도 3
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 7.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	//카메라 FOV 55 설정
	CameraComp->SetFieldOfView(55.f);

	//플레이어 최대속도
	GetCharacterMovement()->MaxWalkSpeed =  300.f;
	//자동회전속도 0으로 회전 해제시키기
	GetCharacterMovement()->RotationRate = FRotator(0.f, 0.f, 0.f);

	//플레이어 그림자 제거
	GetMesh()->CastShadow = false;
	
	//Shadow Decal
	ShadowDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("ShadowDecal"));
	ShadowDecal->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UMaterialInstance> ShadowMat(TEXT("/Game/DontStarveCopyCat/Materials/M_ShadowDecal.M_ShadowDecal"));
	if (ShadowMat.Succeeded())
	{
		ShadowDecal->SetDecalMaterial(ShadowMat.Object);
	}
	
	ShadowDecal->DecalSize = FVector(64.f, 150.f, 64.f);
	ShadowDecal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	ShadowDecal->SetRelativeRotation(FRotator(90.f, 0.f, 90.f));


}

// Called when the game starts or when spawned
void ADS_Player::BeginPlay()
{
	Super::BeginPlay();

	//초기 시작을 화면을 바라보는 방향에서 시작
	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += 180.f;
	SetActorRotation(newRotation);
	
}

void ADS_Player::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	//현재 컨트롤러가 플레이어컨트롤러가 맞다면
	if (auto* pc = Cast<APlayerController>(Controller))
	{
		//UEnhancedInputLocalPlayerSubSystem를 가져와서
		auto* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());

		//AddMappingContext를 하고싶다.
		subsystem->RemoveMappingContext(IMC_DontStarve);
		subsystem->AddMappingContext(IMC_DontStarve, 0);
	}
}

// Called every frame
void ADS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//ControlRotation값으로 Transform을 만들고 그것을 기준으로 방향을 변경하고
	//AddMovementInput 하고싶다.
	FTransform tf = FTransform(GetControlRotation());
	Direction = tf.TransformVector(Direction);
	AddMovementInput(Direction);

	//입력받았을때 한번 움직이고 안움직이게처리.
	Direction = FVector::ZeroVector;

}

// Called to bind functionality to input
void ADS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Action Bind
	if (auto* input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		input->BindAction(IA_DS_Move, ETriggerEvent::Triggered, this, &ADS_Player::OnActionMove);
		//input->BindAction(IA_DS_CameraRotation, ETriggerEvent::Triggered, this, &ADS_Player::OnActionCameraRotation);
		input->BindAction(IA_DS_Gather, ETriggerEvent::Started, this, &ADS_Player::TryGather);
	}

}

void ADS_Player::OnActionMove(const FInputActionValue& value)
{
	//플레이어 상하좌우 이동
	FVector2D v2D = value.Get<FVector2D>();
	Direction.X = v2D.X;
	Direction.Y = v2D.Y;
	Direction.Normalize();

	//입력이 있을 때만 회전
	if (!Direction.IsNearlyZero())
	{
		FRotator TargetRotation = Direction.Rotation();
		FRotator MoveRotation(0.f, TargetRotation.Yaw, 0.f);

		FRotator SmoothRotation = FMath::RInterpTo(GetActorRotation(), MoveRotation, GetWorld()->GetDeltaSeconds(), 10.f);
		SetActorRotation(SmoothRotation);
	}
}

//현재 카메라가 월드로 되어있어서, 카메라 회전이 이상함
// void ADS_Player::OnActionCameraRotation(const FInputActionValue& value)
// {
// 	FRotator CurrentRotation = GetControlRotation();
// 	FRotator TargetRotation = CurrentRotation;
// 	TargetRotation.Yaw += CameraRotateAmount;
//
// 	FRotator newRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, GetWorld()->GetDeltaSeconds(), 5.f);
// 	GetController()->SetControlRotation(newRotation);
// }

inline void ADS_Player::TryGather()
{
	//플레이어 위치 시작 -> 플레이어 앞방향 거리 끝
	FVector Start = this->GetActorLocation();
	FVector End = Start + this->GetActorForwardVector() * GatherRange;

	//LineTrace Hit, 본인 제외
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	//LineTrace해서 True면 Item 습득 및 파괴 
	if (bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		//채집 충돌완료 디버그메세지
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Gathering...");

		//Bush 채집
		AGatherableBush* Bush = Cast<AGatherableBush>(Hit.GetActor());
		if (Bush)
		{
			//채집 애니메이션 시작 - bGatherBush = false는 애니메이션 끝날때 AnimNotify 추가하기
			bGatherBush = true;
			Bush->OnGather();
		}
	}
	else
	{
		//거리안에 아이템 없을시 LineTrace 그려주기
		DrawDebugLine(GetWorld(), Start,End, FColor::Red,true);
	}
}
