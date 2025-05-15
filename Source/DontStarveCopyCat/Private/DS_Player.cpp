// Fill out your copyright notice in the Description page of Project Settings.


#include "DontStarveCopyCat/Public/DS_Player.h"

#include "DayNightCycle.h"
#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"
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
#include "DS_MenuWidget.h"
#include "DS_StatWidget.h"
#include "GatherableMeat.h"
#include "NiagaraSystem.h"
#include "Engine/DirectionalLight.h"
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

	ConstructorHelpers::FObjectFinder<UMaterial> ShadowMat(TEXT("/Game/DontStarveCopyCat/Materials/M_ShadowDecal.M_ShadowDecal"));
	if (ShadowMat.Succeeded())
	{
		ShadowDecal->SetDecalMaterial(ShadowMat.Object);
	}
	
	ShadowDecal->DecalSize = FVector(64.f, 150.f, 64.f);
	ShadowDecal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	ShadowDecal->SetRelativeRotation(FRotator(90.f, 0.f, 90.f));

	//player Widgets
	static ConstructorHelpers::FClassFinder<UDS_MenuWidget> Menutemp(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DontStarveCopyCat/UI/WBP_DS_MenuWidget.WBP_DS_MenuWidget_C'"));
	if (Menutemp.Succeeded())
	{
		MenuWidgetClass = Menutemp.Class;
	}

	static ConstructorHelpers::FClassFinder<UDS_InventoryWidget> Inventorytemp(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DontStarveCopyCat/UI/WBP_DS_InventoryWidget.WBP_DS_InventoryWidget_C'"));
	if (Inventorytemp.Succeeded())
	{
		InventoryWidgetClass = Inventorytemp.Class;
	}

	static ConstructorHelpers::FClassFinder<UDS_StatWidget> Stattemp(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/DontStarveCopyCat/UI/WBP_DS_StatWidget.WBP_DS_StatWidget_C'"));
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
	MenuWidget = CreateWidget<UDS_MenuWidget>(GetWorld(), MenuWidgetClass);
	MenuWidget->AddToViewport();
	InventoryWidget = CreateWidget<UDS_InventoryWidget>(GetWorld(), InventoryWidgetClass);
	InventoryWidget->AddToViewport();
	StatWidget = CreateWidget<UDS_StatWidget>(GetWorld(), StatWidgetClass);
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

	//플레이어 스탯 초기화
	MaxHungerValue = 100.f;
	CurrentHungerValue = 100.f;
	
	MaxHealthValue = 100.f;
	CurrentHealthValue = 100.f;
	
	MaxSanityValue = 100.f;
	CurrentSanityValue = 100.f;

	//stat Widget C++ 캐스팅
	StatsWidget = Cast<UDS_StatWidget>(StatWidget);
	//초기 꽉찬 Bar
	if (StatsWidget)
	{
		HungryRatio = CurrentHungerValue / MaxHungerValue;
		HealthRatio = CurrentHealthValue / MaxHealthValue;
		SanityRatio = CurrentSanityValue / MaxSanityValue;
	}
	//Bar Update
	StatsWidget->UpdateStatBar(HungryRatio,HealthRatio,SanityRatio);

	//배고픔 감소 타이머 시작. 1초에 한번씩 반복
	GetWorldTimerManager().SetTimer(HungerTimerHandle, this, &ADS_Player::DecreaseHunger, HungerDecreaseDelayTime, true);

	//월드 시간 액터 찾아 가져오기
	DayNight = Cast<ADayNightCycle>(UGameplayStatics::GetActorOfClass(GetWorld(), ADayNightCycle::StaticClass()));
	
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

	
	//월드 시간 각도에 따른 낮과 밤 분류, 정신력 감소 적용
	FVector SunDirection = DayNight->SunLight->GetActorForwardVector();
	float VerticalValue = FVector::DotProduct(SunDirection, FVector::DownVector); //지면방향 비교
	//VerticalValue가 양수일수록 낮, 음수면 밤
	if (VerticalValue > 0.3f)
	{
		//낮
		StopSanityTimer();
	}
	else
	{
		//밤
		StartSanityTimer();
	}
	
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

		//돼지 도끼질
		Pig = Cast<ADS_AnimalPig>(Hit.GetActor());
		if (Pig)
		{
			//Chop 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				if (false == bIsChoppingPig)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
					}

					//도끼질 애니메이션 시작, bIsChoppingPig = false는 몽타주 마지막에 AnimNotify로 추가
					PlayerAnim->Montage_Play(ChopMontage);
					bIsChoppingPig = true;
					//돼지 데미지 입히기
					Pig->AnimalPigFSM->OnMyTakeDamage(1);
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

		//고기 Meat 줍기
		Meat = Cast<AGatherableMeat>(Hit.GetActor());
		if (Meat)
		{
			//줍기 애니메이션 몽타주 실행
			if (PlayerAnim)
			{
				if (false == bPickUp)
				{
					if (IsPlayingHoldingToolMontage)
					{
						PlayerAnim->Montage_Stop(0.1f, HoldingToolMontage);
					}

					PlayerAnim->Montage_Play(PickUpMontage);
					bPickUp = true;
					
					//고기 충돌완료 디버그메세지
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Meat Picking Up...");
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
	if (Meat)
	{
		//인벤토리에 아이템 추가
		InventoryComp->AddItem(Meat->ItemID, Meat->ItemIcon, Meat->IsEquip, Meat->Quantity);

		//UI 갱신
		if (InventorySlotWidget)
		{
			InventorySlotWidget->UpdateAllSlots(InventoryComp->Items);
		}
		
		Meat->OnPickUp();
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, "PickUpEnd");
	bPickUp = false;
	
	//Holding 몽타주 중이였다면
	if (IsPlayingHoldingToolMontage)
	{
		PlayerAnim->Montage_Play(HoldingToolMontage);
	}
}

void ADS_Player::DecreaseHunger()
{
	//1초마다 0.5씩 감소
	CurrentHungerValue -= HungerDecreaseValue;
	CurrentHungerValue = FMath::Clamp(CurrentHungerValue, 0.f, MaxHungerValue);

	//배고픔이 0이면 체력 감소
	if (CurrentHungerValue <= 0.f)
	{
		CurrentHealthValue -= StarvationDamageHPValue; // 초당 2씩 체력 감소
		CurrentHealthValue = FMath::Clamp(CurrentHealthValue, 0.f, MaxHealthValue);

		//체력이 0이 되면
		if (CurrentHealthValue <= 0.f)
		{
			//플레이어 사망 함수
			PlayerDie();
		}
	}
	
	if (StatsWidget)
	{
		//UI Progress Bar 업데이트
		HungryRatio = CurrentHungerValue / MaxHungerValue;
		HealthRatio = CurrentHealthValue / MaxHealthValue;
		SanityRatio = CurrentSanityValue / MaxSanityValue;
		
		StatsWidget->UpdateStatBar(HungryRatio, HealthRatio, SanityRatio);

		//TEXT 업데이트
		StatsWidget->HungryText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(CurrentHungerValue))));
		StatsWidget->HealthText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(CurrentHealthValue))));

		//아이콘이미지 업데이트
		StatsWidget->UpdateStatIcon(StatsWidget->HungryImage, CurrentHungerValue, StatsWidget->HungryIconHigh, StatsWidget->HungryIconMid, StatsWidget->HungryIconLow);
		StatsWidget->UpdateStatIcon(StatsWidget->HealthImage, CurrentHealthValue, StatsWidget->HealthIconHigh, StatsWidget->HealthIconMid, StatsWidget->HealthIconLow);
		
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%f"), CurrentHungerValue));
	}

	// 추가: 배고픔 0이면 데미지 같은 페널티도 여기에 추가 가능
}

void ADS_Player::PlayerDie()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("PlayerDie")));
	// 애니메이션 정지, 입력 막기, 리스폰 처리 등
	//DisableInput(nullptr);
	// 죽음 애니메이션, 게임오버 UI 등 필요시 추가
}

void ADS_Player::StartSanityTimer()
{
	//밤이 되고 타이머가 작동중이 아니면 정신력 감소 타이머 작동
	//정신력 타이머 2초에 한번씩 실행

	//횃불을 들고 있지 않으면 작동
	if (false == bIsHoldingTorch)
	{
		if (false == bIsSanityTimerActive)
		{
			GetWorldTimerManager().SetTimer(SanityTimerHandle, this, &ADS_Player::DecreaseSanity, SanityDecreaseDelayTime, true);
			bIsSanityTimerActive = true;

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("밤: 정신력 감소 시작")));
		}
	}
	//횃불을 들고 있으면 정신력 감소 x
	else
	{
		GetWorldTimerManager().ClearTimer(SanityTimerHandle);
		bIsSanityTimerActive = false;

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("밤: 횃불로 인해 정신력 유지")));
	}
}

void ADS_Player::StopSanityTimer()
{
	//낮이 되고 타이머가 작동중이라면 정신력 감소 멈춤 타이머 작동
	//정신력 타이머 정지
	if (bIsSanityTimerActive)
	{
		GetWorldTimerManager().ClearTimer(SanityTimerHandle);
		bIsSanityTimerActive = false;

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("낮: 정신력 감소 중단")));
	}
}

void ADS_Player::DecreaseSanity()
{
	CurrentSanityValue -= SanityDecreaseValue; //정신력 초당 0.25 감소
	CurrentSanityValue = FMath::Clamp(CurrentSanityValue, 0.f, MaxSanityValue);

	if (StatsWidget)
	{
		//UI Progress Bar 업데이트
		HungryRatio = CurrentHungerValue / MaxHungerValue;
		HealthRatio = CurrentHealthValue / MaxHealthValue;
		SanityRatio = CurrentSanityValue / MaxSanityValue;
		
		StatsWidget->UpdateStatBar(HungryRatio, HealthRatio, SanityRatio);

		//TEXT 업데이트
		StatsWidget->SanityText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(CurrentSanityValue))));

		//아이콘 이미지 업데이트
		StatsWidget->UpdateStatIcon(StatsWidget->SanityImage, CurrentSanityValue, StatsWidget->SanityIconHigh, StatsWidget->SanityIconMid, StatsWidget->SanityIconLow);
	}

	//정신력이 0이 되면
	if (CurrentSanityValue <= 0.f)
	{
		// 정신력이 0일 때 효과 적용 (공황 상태, 환각)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Sanity Depleted!")));
	}
}

void ADS_Player::DoDamageFromPig(int32 damage)
{
	//만약 체력이 0이하면
	if (CurrentHealthValue <= 0.f)
		return;

	CurrentHealthValue -= damage;
	
	if (CurrentHealthValue <= 0.f)
	{
		//플레이어 사망 함수
		PlayerDie();
	}
}
