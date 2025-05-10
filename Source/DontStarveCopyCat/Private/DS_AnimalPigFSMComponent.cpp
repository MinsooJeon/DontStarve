// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_AnimalPigFSMComponent.h"

#include "DS_AnimalPig.h"
#include "DS_Player.h"
#include "AIController.h"
#include "DS_PigAnim.h"
#include "NavigationSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values for this component's properties
UDS_AnimalPigFSMComponent::UDS_AnimalPigFSMComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDS_AnimalPigFSMComponent::BeginPlay()
{
	Super::BeginPlay();
	
	//AnimalPig 찾기
	AnimalPig = Cast<ADS_AnimalPig>(GetOwner());

	//움직이는 방향으로 회전 가능하도록
	AnimalPig->GetCharacterMovement()->bOrientRotationToMovement = true;

	//애니메이션 받아오기
	PigAnim = Cast<UDS_PigAnim>(AnimalPig->GetMesh()->GetAnimInstance());

	//AIController 받아오기
	AIController = Cast<AAIController>(AnimalPig->Controller);
	//순찰할 장소 업데이트
	UpdatePatrolLocation(AnimalPig->GetActorLocation(), 300.f, PatrolLocation);
	
	//플레이어 찾기
	auto* c = Cast<ADS_Player>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	Player = c;
}


// Called every frame
void UDS_AnimalPigFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//상태 전환
	switch (PigState)
	{
	case EAnimalPigState::Idle:
		TickIdle();
		break;
	case EAnimalPigState::Move:
		TickMove();
		break;
	case EAnimalPigState::Attack:
		TickAttack();
		break;
	case EAnimalPigState::Damage:
		TickDamage();
		break;
	case EAnimalPigState::Die:
		TickIdle();
		break;;
	}

	if (PigAnim)
	{
		//Pig에 Log 실시간 로그 찍어서 보여주기
		//FString log = UEnum::GetValueAsString(PigState);
		FString log = FString::Printf(TEXT("State : %s\nbAttack : %d"), *UEnum::GetValueAsString(PigState), PigAnim->bAttack);
		DrawDebugString(GetWorld(), AnimalPig->GetActorLocation(), log, nullptr, FColor::Yellow, 0, true, 1);
	}
}

bool UDS_AnimalPigFSMComponent::UpdatePatrolLocation(FVector origin, float radius, FVector& outLocation)
{
	auto* ns = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	FNavLocation location;
	if (ns->GetRandomReachablePointInRadius(origin, radius, location))
	{
		outLocation = location.Location;
		return true;
	}
	
	return false;
}

void UDS_AnimalPigFSMComponent::TickIdle()
{
	if (Player)
	{
		PigAnim->bMove = true;
		SetState(EAnimalPigState::Move);
	}

}

void UDS_AnimalPigFSMComponent::TickMove()
{
	//플레이어쪽으로 방향 찾기
	FVector Destination = Player->GetActorLocation();
	FVector Dir = Destination - AnimalPig->GetActorLocation();

	//AnimalPig->AddMovementInput(Dir.GetSafeNormal2D(), MoveSpeed * GetWorld()->GetDeltaSeconds());
	//AI를 이용해서 길찾기
	//플레이어가 길 위에 있는지
	UNavigationSystemV1* ns = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	FPathFindingQuery query;
	FAIMoveRequest request;
	request.SetAcceptanceRadius(50.f);
	request.SetGoalLocation(Destination); //플레이어 위치

	AIController->BuildPathfindingQuery(request,query);

	FPathFindingResult findPathResult = ns->FindPathSync(query);

	//플레이어가 길 위에 있는지
	if (findPathResult.IsSuccessful())
	{
		//플레이어 위치를 향해 이동
		AIController->MoveToLocation(Destination, 50.f);
	}
	//길 위가 아니라면
	else
	{
		//랜덤 위치로 이동
		EPathFollowingRequestResult::Type requestResult = AIController->MoveToLocation(PatrolLocation, 50.f);
		//만약 랜덤 위치에 도착하면
		if (requestResult == EPathFollowingRequestResult::Type::AlreadyAtGoal || requestResult == EPathFollowingRequestResult::Type::Failed)
		{
			//성공한 경우는 알아서 가기에 무시
			//랜덤한 위치를 재설정
			UpdatePatrolLocation(AnimalPig->GetActorLocation(), 300.f, PatrolLocation);
		}
	}
	
	//공격 가능한 거리라면 공격 상태로 상태전환
	float Dist = Dir.Length();
	if (Dist < AttackRange)
	{
		PigAnim->bAttack = true;
		PigAnim->bMove = false;
		SetState(EAnimalPigState::Attack);
	}
}

void UDS_AnimalPigFSMComponent::TickAttack()
{
	//시간 계산
	CurrentTime += GetWorld()->GetDeltaSeconds();
	//공격 딜레이 계산
	if (CurrentTime > AttackDelayTime)
	{
		CurrentTime = 0.0f;
		FVector Dir = Player->GetActorLocation() - AnimalPig->GetActorLocation();
		//공격 가능한 거리 계산
		if (Dir.Length() < AttackRange)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Attack");
		}
		//거리가 안되면 플레이어 따라가기
		else
		{
			PigAnim->bAttack = false;
			PigAnim->bMove = true;
			SetState(EAnimalPigState::Move);
		}
	}
}

void UDS_AnimalPigFSMComponent::TickDamage()
{
	
}

void UDS_AnimalPigFSMComponent::TickDie()
{
	
}

void UDS_AnimalPigFSMComponent::OnMyTakeDamage(int32 damage)
{
	
}

void UDS_AnimalPigFSMComponent::SetState(EAnimalPigState state)
{
	PigState = state;
	CurrentTime = 0;
	//Move 상태 아닐 때 플레이어에게 맞거나 하면 AI는 움직이고 있어서 움직임 방지
	if (state != EAnimalPigState::Move) 
	{
		AIController->StopMovement();
	}
}

