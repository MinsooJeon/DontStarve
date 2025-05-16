// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PlayerAnim.h"

#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"
#include "DS_InventoryWidget.h"
#include "DS_Player.h"
#include "DS_StatWidget.h"

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

	//먹은 고기 아이템 삭제
	Player->InventoryWidget->DeleteInventoryItem("GatherableMeat");
	
	//플레이어 허기짐에서 일부 회복, 체력 일부 회복, 정신력 감소 및 UI 업데이트
	Player->CurrentHungerValue += 30;
	Player->CurrentHungerValue = FMath::Clamp(Player->CurrentHungerValue, 0.f, Player->MaxHungerValue);

	Player->CurrentHealthValue += 10;
	Player->CurrentHealthValue = FMath::Clamp(Player->CurrentHealthValue, 0.f, Player->MaxHealthValue);
	
	Player->CurrentSanityValue -= 10;
	Player->CurrentSanityValue = FMath::Clamp(Player->CurrentSanityValue, 0.f, Player->MaxSanityValue);

	if (Player->StatsWidget)
	{
		//UI Progress Bar 업데이트
		Player->HungryRatio = Player->CurrentHungerValue / Player->MaxHungerValue;
		Player->HealthRatio = Player->CurrentHealthValue / Player->MaxHealthValue;
		Player->SanityRatio = Player->CurrentSanityValue / Player->MaxSanityValue;
		
		Player->StatsWidget->UpdateStatBar(Player->HungryRatio, Player->HealthRatio, Player->SanityRatio);

		//TEXT 업데이트
		Player->StatsWidget->HungryText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentHungerValue))));
		Player->StatsWidget->HealthText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentHealthValue))));
		Player->StatsWidget->SanityText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentSanityValue))));

		//아이콘이미지 업데이트
		Player->StatsWidget->UpdateStatIcon(Player->StatsWidget->HungryImage, Player->CurrentHungerValue, Player->StatsWidget->HungryIconHigh, Player->StatsWidget->HungryIconMid, Player->StatsWidget->HungryIconLow);
		Player->StatsWidget->UpdateStatIcon(Player->StatsWidget->HealthImage, Player->CurrentHealthValue, Player->StatsWidget->HealthIconHigh, Player->StatsWidget->HealthIconMid, Player->StatsWidget->HealthIconLow);
		Player->StatsWidget->UpdateStatIcon(Player->StatsWidget->SanityImage, Player->CurrentSanityValue, Player->StatsWidget->SanityIconHigh, Player->StatsWidget->SanityIconMid, Player->StatsWidget->SanityIconLow);
		
	}
}
