// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_AnimalPigFSMComponent.h"

#include "DS_AnimalPig.h"
#include "DS_Player.h"
#include "MaterialHLSLTree.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	//Pig에 Log 실시간 로그 찍어서 보여주기
	FString log = UEnum::GetValueAsString(PigState);
	DrawDebugString(GetWorld(), AnimalPig->GetActorLocation(), log, nullptr, FColor::Yellow, 0, true, 1);
	
}

void UDS_AnimalPigFSMComponent::TickIdle()
{
	if (Player)
		SetState(EAnimalPigState::Move);
}

void UDS_AnimalPigFSMComponent::TickMove()
{
	//플레이어쪽으로 방향 찾기
	FVector Destination = Player->GetActorLocation();
	FVector Dir = Destination - AnimalPig->GetActorLocation();

	AnimalPig->AddMovementInput(Dir.GetSafeNormal2D(), MoveSpeed * GetWorld()->GetDeltaSeconds());

	//공격 가능한 거리라면 공격 상태로 상태전환
	float Dist = Dir.Length();
	if (Dist < AttackRange)
	{
		SetState(EAnimalPigState::Attack);
	}
}

void UDS_AnimalPigFSMComponent::TickAttack()
{
	
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
}

