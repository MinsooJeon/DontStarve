// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DS_AnimalPigFSMComponent.generated.h"

//상태 Enum
UENUM(BlueprintType)
enum class EAnimalPigState : uint8
{
	Idle UMETA(DisplayName = "대기상태"),
	Move UMETA(DisplayName = "이동상태"),
	Attack UMETA(DisplayName = "공격상태"),
	Damage UMETA(DisplayName = "데미지상태"),
	Die UMETA(DisplayName = "죽음상태"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONTSTARVECOPYCAT_API UDS_AnimalPigFSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDS_AnimalPigFSMComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//상태 Enum 변수
	EAnimalPigState PigState;

	//플레이어
	UPROPERTY()
	class ADS_Player* Player;
	//Pig
	UPROPERTY()
	class ADS_AnimalPig* AnimalPig;

	UPROPERTY()
	class UDS_PigAnim* PigAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "AnimSequence")
	class UAnimSequence* PigMoveAnimation;

	UPROPERTY()
	class AAIController* AIController;
	
	//공격가능거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackRange = 100.f;
	//공격대기시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDelayTime = 1.f;
	//시간 계산
	float CurrentTime;

	//이동 속도
	float MoveSpeed = 50.f;

	//체력
	float curHp = 2.f;
	float MaxHp = 2.f;

	//순찰을 위한 랜덤위치를 기억하기
	FVector PatrolLocation;

	//랜덤위치를 정하는 기능 만들기
	bool UpdatePatrolLocation(FVector origin, float radius, FVector& outLocation);
	
	//상태 함수
	void TickIdle();
	void TickMove();
	void TickAttack();
	void TickDamage();
	void TickDie();

	//받은 데미지 함수
	void OnMyTakeDamage(int32 damage);

	//상태 변화 함수
	void SetState(EAnimalPigState state);
};
