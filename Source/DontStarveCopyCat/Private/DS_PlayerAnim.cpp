// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PlayerAnim.h"

#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"
#include "DS_Player.h"

void UDS_PlayerAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ADS_Player>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void UDS_PlayerAnim::AnimNotify_PigChoppingEnd()
{
	Player->bIsChoppingPig = false;
	
	if (Player->AxeMeshComp->IsVisible() || Player->TorchMeshComp->IsVisible())
	{
		Player->PlayerAnim->Montage_Play(Player->HoldingToolMontage);
	}

}

void UDS_PlayerAnim::AnimNotify_Hit()
{
	//돼지 데미지 입히기
	Player->Pig->AnimalPigFSM->OnMyTakeDamage(1);
}
