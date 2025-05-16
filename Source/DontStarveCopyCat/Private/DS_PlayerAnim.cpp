// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PlayerAnim.h"

#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"
#include "DS_InventoryWidget.h"
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

void UDS_PlayerAnim::AnimNotify_EatingEnd()
{
	Player->bIsEating = false;

	//장비 들고 있으면 홀딩 몽타주 실행
	if (Player->IsPlayingHoldingToolMontage)
	{
		Player->PlayerAnim->Montage_Play(Player->HoldingToolMontage);
	}

	//플레이어 허기짐에서 채워짐, 체력 일부 채워짐 및 UI 업데이트
	Player->CurrentHungerValue += 30;
	Player->CurrentHungerValue = FMath::Clamp(Player->CurrentHungerValue, 0.f, Player->MaxHungerValue);

	Player->CurrentHealthValue += 10;
	Player->CurrentHealthValue = FMath::Clamp(Player->CurrentHealthValue, 0.f, Player->MaxHealthValue);
	

	//먹은 고기 아이템 삭제
	Player->InventoryWidget->DeleteInventoryItem("GatherableMeat");
	
}
