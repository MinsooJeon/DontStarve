// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PlayerAnim.h"

#include "DS_Player.h"

void UDS_PlayerAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ADS_Player>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void UDS_PlayerAnim::AnimNotify_PigChoppingEnd()
{
	Player->bIsChoppingPig = false;
}
