// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PigAnim.h"

#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"

void UDS_PigAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Me = Cast<ADS_AnimalPig>(TryGetPawnOwner());
}

void UDS_PigAnim::AnimNotify_PigAttack()
{
	//애니메이션 몽타주의 공격 시점에 플레이어 데미지 주기
	Me->AnimalPigFSM->AttackPlayer();
}
