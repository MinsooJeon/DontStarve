// Fill out your copyright notice in the Description page of Project Settings.


#include "DontStarveCopyCat/Public/DS_Player.h"

#include "DS_PlayerAnim.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GatherableBush.h"
#include "GatherableFlint.h"
#include "GatherableTree.h"
#include "GatherableTwigs.h"
#include "InputMappingContext.h"
#include "InventoryComponent.h"
#include "Components/DecalComponent.h"
#include "Blueprint/UserWidget.h"
#include "DS_InventoryWidget.h"

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
	SpringArmComp->SetWorldRotation(FRotator(-35.f, 0, 0));
	//카메라 암 길이
	SpringArmComp->TargetArmLength = 1400.f;
	//카메라 클리핑 해제
	SpringArmComp->bDoCollisionTest = false;
	//카메라 Lag 활성화(지연을 통한 자연스러운 이동) 속도 7
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 7.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	//카메라 FOV 55 설정
	CameraComp->SetFieldOfView(100.f);

	//플레이어 최대속도
	GetCharacterMovement()->MaxWalkSpeed =  300.f;
	//자동회전속도 0으로 회전 해제시키기
	GetCharacterMovement()->RotationRate = FRotator(0.f, 0.f, 0.f);

	//플레이어 그림자 제거
	GetMesh()->CastShadow = false;
	
	//Shadow Decal
	ShadowDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("ShadowDecal"));
	ShadowDecal->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UMaterialInstance> ShadowMat(TEXT("/Script/Engine.Material'/Game/DontStarveCopyCat/Materials/M_ShadowDecal'"));
	if (ShadowMat.Succeeded())
	{
		ShadowDecal->SetDecalMaterial(ShadowMat.Object);
	}
	
	ShadowDecal->DecalSize = FVector(64.f, 150.f, 64.f);
	ShadowDecal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	ShadowDecal->SetRelativeRotation(FRotator(90.f, 0.f, 90.f));

	//player Widgets
	static ConstructorHelpers::FClassFinder<UUserWidget> Menutemp(TEXT("/Game/DontStarveCopyCat/UI/WBP_DS_MenuWidget.WBP_DS_MenuWidget"));
	if (Menutemp.Succeeded())
	{
		MenuWidgetClass = Menutemp.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> Inventorytemp(TEXT("/Game/DontStarveCopyCat/UI/WBP_DS_InventoryWidget.WBP_DS_InventoryWidget"));
	if (Inventorytemp.Succeeded())
	{
		InventoryWidgetClass = Inventorytemp.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> Stattemp(TEXT("/Game/DontStarveCopyCat/UI/WBP_DS_StatWidget.WBP_DS_StatWidget"));
	if (Stattemp.Succeeded())
	{
		StatWidgetClass = Stattemp.Class;
	}

	//인벤토리
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));

	//도끼 생성(왼쪽 손)
	AxeMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxeMeshComp"));
	AxeMeshComp->SetupAttachment(GetMesh(), TEXT("hand_l"));
	AxeMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ConstructorHelpers::FObjectFinder<UStaticMesh> AxeTemp(TEXT("/Game/DontStarveCopyCat/Models/SM_MyAxe"));
	if (AxeTemp.Succeeded())
	{
		AxeMeshComp->SetStaticMesh(AxeTemp.Object);
	}
	//도끼 그림자 제거
	AxeMeshComp->CastShadow = false;
	//처음은 안보이게 세팅
	AxeMeshComp->SetVisibility(false);

	//횃불 생성(왼쪽 손)
	TorchMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorchMeshComp"));
	TorchMeshComp->SetupAttachment(GetMesh(), TEXT("TorchSocket"));
	TorchMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TorchTemp(TEXT("/Game/DontStarveCopyCat/Models/Torch"));
	if (TorchTemp.Succeeded())
	{
		TorchMeshComp->SetStaticMesh(TorchTemp.Object);
	}
	//횃불 그림자 제거
	TorchMeshComp->CastShadow = false;
	//처음은 안보이게 세팅
	TorchMeshComp->SetVisibility(false);

	//횃불 VFX 생성
	TorchFlameVFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TorchFlameVFX"));
	TorchFlameVFX->SetupAttachment(GetMesh(), TEXT("TorchSocket"));
	TorchFlameVFX->SetRelativeLocationAndRotation(FVector(-2.f,-2.5f,-50.f), FRotator(180.f,0.f,0.f));
	
	TorchFlameVFX->bAutoActivate = false; //처음엔 비활성화

	ConstructorHelpers::FObjectFinder<UNiagaraSystem> TorchVFXTemp(TEXT("/Game/DontStarveCopyCat/VFX/NS_Torch"));
	if (TorchVFXTemp.Succeeded())
	{
		TorchFlameVFX->SetAsset(TorchVFXTemp.Object);
	}

	//Point Light 생성
	TorchLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("TorchLight"));
	TorchLight->SetupAttachment(TorchFlameVFX);
	TorchLight->SetVisibility(false); //처음엔 비활성화

	//빛 세부 조정
	TorchLight->SetIntensity(5000.0f);
	TorchLight->SetAttenuationRadius(700.0f);
	TorchLight->SetLightColor(FColor::Orange);
}

// Called when the game starts or when spawned
void ADS_Player::BeginPlay()
{
	Super::BeginPlay();

	//초기 시작을 화면을 바라보는 방향에서 시작
	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += 180.f;
	SetActorRotation(newRotation);

	//Widgets 화면에 보이기
	MenuWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), MenuWidgetClass);
	MenuWidget->AddToViewport();
	InventoryWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), InventoryWidgetClass);
	InventoryWidget->AddToViewport();
	StatWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), StatWidgetClass);
	StatWidget->AddToViewport();
	//인벤토리 슬롯 C++로 캐스팅
	InventorySlotWidget = Cast<UDS_InventoryWidget>(InventoryWidget);

	//플레이어 애니메이션 캐스팅
	PlayerAnim = Cast<UDS_PlayerAnim>(GetMesh()->GetAnimInstance());

	//마우스 커서 표시
	if (APlayerController* pc = Cast<APlayerController>(GetController()))
	{
		pc->bShowMouseCursor = true;

		//UI와 게임 모두 입력 받을 수 있도록 설정
		FInputModeGameAndUI InputMode;
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		InputMode.SetHideCursorDuringCapture(false);

		//적용
		pc->SetInputMode(InputMode);
	}

	//인벤토리에 초기 도끼, 횃불 아이템 저장 후 UI에 띄우기
	if (InventoryComp)
	{
		InventoryComp->InitializeDefaultItems();
	}
	if (InventorySlotWidget)
	{
		InventorySlotWidget->UpdateAllSlots(InventoryComp->Items);
	}
	
}

void ADS_Player::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	//현재 컨트롤러가 플레이어컨트롤러가 맞다면
	if (auto* pc = Cast<APlayerController>(Controller))
	{
		//UEnhancedInputLocalPlayerSubSystem를 가져와서
		auto* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());

		//AddMappingContext를 한다.
		subsystem->RemoveMappingContext(IMC_DontStarve);
		subsystem->AddMappingContext(IMC_DontStarve, 0);
	}
}

// Called every frame
void ADS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//ControlRotation값으로 Transform을 만들고 그것을 기준으로 방향을 변경하고
	//AddMovementInput 한다.
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
		input->BindAction(IA_DS_Chop, ETriggerEvent::Started, this, &ADS_Player::TryChopping);
		input->BindAction(IA_DS_PickUp, ETriggerEvent::Started, this, &ADS_Player::TryPickUp);
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

	//움직임이 시작되면 몽타주를 실행하고 있으면 몽타주를 멈추고싶다.
	if (PlayerAnim)
	{
		//채집 몽타주 멈추기
		if (bGatherBush)
		{
			PlayerAnim->Montage_Stop(0.1f, GatherMontage);
			bGatherBush = false;
			if (IsPlayingHoldingToolMontage)
			{
				PlayerAnim->Montage_Play(HoldingToolMontage);
			}
		}
		//도끼질 몽타주 멈추기
		if (bChopTree)
		{
			PlayerAnim->Montage_Stop(0.1f, ChopMontage);
			bChopTree = false;
			if (IsPlayingHoldingToolMontage)
			{
				PlayerAnim->Montage_Play(HoldingToolMontage);
			}
		}
		//줍기 몽타주 멈추기
		if (bPickUp)
		{
			PlayerAnim->Montage_Stop(0.1f, PickUpMontage);
			bPickUp = false;
			if (IsPlayingHoldingToolMontage)
			{
				PlayerAnim->Montage_Play(HoldingToolMontage);
			}
		}
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

void ADS_Player::TryGather()
{
	//플레이어 위치 시작 -> 플레이어 앞방향 거리 끝
	FVector Start = this->GetActorLocation();
	FVector End = Start + this->GetActorForwardVector() * InteractionRange;

	//LineTrace Hit, 본인 제외
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	//LineTrace해서 True면 채집 시작, 몽타주 실행
	if (bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		//Bush 채집
		Bush = Cast<AGatherableBush>(Hit.GetActor());
		if (Bush)
		{
			//Gather 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				//몽타주를 실행하고 있지 않으면 몽타주 실행하고싶다.
				if (false == bGatherBush)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
						//IsPlayingHoldingToolMontage = false;
					}
					PlayerAnim->Montage_Play(GatherMontage);
					//채집 애니메이션 시작 - bGatherBush = false는 애니메이션 끝날때 AnimNotify에 추가
					bGatherBush = true;

					//채집 충돌완료 디버그메세지
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Gathering...");
				}
			}
			
		}
	}
	else
	{
		//거리안에 아이템 없을시 LineTrace 그려주기
		//DrawDebugLine(GetWorld(), Start,End, FColor::Red,true);
	}
}

void ADS_Player::GatherEndNotify()
{
	if (!InventoryComp || !Bush)
		return;

	//인벤토리에 아이템 추가
	InventoryComp->AddItem(Bush->ItemID, Bush->ItemIcon, Bush->IsEquip, Bush->Quantity);

	//UI 갱신
	if (InventorySlotWidget)
	{
		InventorySlotWidget->UpdateAllSlots(InventoryComp->Items);
	}
	
	//수풀 채집 완료일 때, 수풀을 없애기.(Destroy)
	Bush->OnGather();
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, "GatherEnd");
	bGatherBush = false;

	//Holding 몽타주 중이였다면
	if (IsPlayingHoldingToolMontage)
	{
		PlayerAnim->Montage_Play(HoldingToolMontage);
	}
}

void ADS_Player::TryChopping()
{
	//플레이어 위치 시작 -> 플레이어 앞방향 거리 끝
	FVector Start = this->GetActorLocation();
	FVector End = Start + this->GetActorForwardVector() * InteractionRange;

	//LineTrace Hit, 본인 제외
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	//LineTrace해서 True면 도끼질 시작
	if (bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		//Tree 도끼질
		Tree = Cast<AGatherableTree>(Hit.GetActor());
		if (Tree)
		{
			//AxeChop 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				if (false == bChopTree)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
						//IsPlayingHoldingToolMontage = false;
					}
					
					PlayerAnim->Montage_Play(ChopMontage);
					//도끼질 애니메이션 시작, bChopTree = false는 몽타주 마지막에 AnimNotify로 추가
					bChopTree = true;

					//도끼질 충돌완료 디버그메세지
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Chopping...");
				}
			}
			
		}
	}
	else
	{
		//거리안에 아이템 없을시 LineTrace 그려주기
		//DrawDebugLine(GetWorld(), Start,End, FColor::Red,true);
	}
}

void ADS_Player::ChopEndNotify()
{
	if (!InventoryComp || !Tree)
		return;
	
	//인벤토리에 아이템 추가(목재를 땅에서 줍는 기능 구현하고나서 하기)
	//InventoryComp->AddItem(Tree->ItemID, Tree->ItemIcon, Tree->IsEquip, Tree->Quantity);
	
	//나무 도끼질 몽타주 완료일 때
	Tree->OnChopping();

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, "ChopEnd");
	bChopTree = false;

	//Holding 몽타주 중이였다면
	if (IsPlayingHoldingToolMontage)
	{
		PlayerAnim->Montage_Play(HoldingToolMontage);
	}
}

void ADS_Player::TryPickUp()
{
	//플레이어 위치 시작 -> 플레이어 앞방향 거리 끝
	FVector Start = this->GetActorLocation();
	FVector End = Start + this->GetActorForwardVector() * InteractionRange;

	//LineTrace Hit, 본인 제외
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	//LineTrace해서 True면 줍기 시작
	if (bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		//부싯돌 Flint 줍기
		Flint = Cast<AGatherableFlint>(Hit.GetActor());
		if (Flint)
		{
			//줍기 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				if (false == bPickUp)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
						//IsPlayingHoldingToolMontage = false;
					}
					
					PlayerAnim->Montage_Play(PickUpMontage);
					bPickUp = true;
				
					//부싯돌 충돌완료 디버그메세지
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Flint Picking Up...");
				}
			}
		}

		//나뭇가지 Twigs 줍기
		Twigs = Cast<AGatherableTwigs>(Hit.GetActor());
		if (Twigs)
		{
			//줍기 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				if (false == bPickUp)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
						//IsPlayingHoldingToolMontage = false;
					}
					
					PlayerAnim->Montage_Play(PickUpMontage);
					bPickUp = true;
				
					//나뭇가지 충돌완료 디버그메세지
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Twigs Picking Up...");
				}
			}
		}
	}
	else
	{
		//거리안에 아이템 없을시 LineTrace 그려주기
		//DrawDebugLine(GetWorld(), Start,End, FColor::Red,true);
	}
}

void ADS_Player::PickUpEndNotify()
{
	if (!InventoryComp)
		return;
	
	//줍기 몽타주 완료할 때
	if (Flint)
	{
		//인벤토리에 아이템 추가
		InventoryComp->AddItem(Flint->ItemID, Flint->ItemIcon, Flint->IsEquip, Flint->Quantity);

		//UI 갱신
		if (InventorySlotWidget)
		{
			InventorySlotWidget->UpdateAllSlots(InventoryComp->Items);
		}
		
		Flint->OnPickUp();
	}
	if (Twigs)
	{
		//인벤토리에 아이템 추가
		InventoryComp->AddItem(Twigs->ItemID, Twigs->ItemIcon, Twigs->IsEquip, Twigs->Quantity);

		//UI 갱신
		if (InventorySlotWidget)
		{
			InventorySlotWidget->UpdateAllSlots(InventoryComp->Items);
		}
		
		Twigs->OnPickUp();
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, "PickUpEnd");
	bPickUp = false;
	
	//Holding 몽타주 중이였다면
	if (IsPlayingHoldingToolMontage)
	{
		PlayerAnim->Montage_Play(HoldingToolMontage);
	}
}
