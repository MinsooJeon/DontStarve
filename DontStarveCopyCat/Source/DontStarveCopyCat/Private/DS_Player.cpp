// Fill out your copyright notice in the Description page of Project Settings.


#include "DontStarveCopyCat/Public/DS_Player.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Components/BoxComponent.h"

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
	
}

// Called when the game starts or when spawned
void ADS_Player::BeginPlay()
{
	Super::BeginPlay();
	
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
	}

}

void ADS_Player::OnActionMove(const FInputActionValue& value)
{
	//플레이어 상하좌우 이동
	FVector2D v2D = value.Get<FVector2D>();
	Direction.X = v2D.X;
	Direction.Y = v2D.Y;
	Direction.Normalize();
	
}

