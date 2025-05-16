// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_PigAnim.h"

#include "DamageBlurWidget.h"
#include "DS_AnimalPig.h"
#include "DS_AnimalPigFSMComponent.h"
#include "DS_Player.h"
#include "Components/Image.h"

void UDS_PigAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Me = Cast<ADS_AnimalPig>(TryGetPawnOwner());
	Player = Cast<ADS_Player>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void UDS_PigAnim::AnimNotify_PigAttack()
{
	//애니메이션 몽타주의 공격 시점에 플레이어 데미지 주기
	Me->AnimalPigFSM->AttackPlayer();
}

void UDS_PigAnim::AnimNotify_PigAttackEnd()
{
	//blur 투명도 처리 타이머 시작
	GetWorld()->GetTimerManager().SetTimer(BlurTimerHandle, this, &UDS_PigAnim::UpdateBlurAlpha, 0.1f, true);
}

void UDS_PigAnim::UpdateBlurAlpha()
{
	FLinearColor CurrentColor = Player->DamageBlurWidget->BloodScreen->GetColorAndOpacity();
	float NewAlpha = FMath::Clamp(CurrentColor.A - GetWorld()->GetDeltaSeconds() * 10.f, 0.f, 1.f);
	CurrentColor.A = NewAlpha;
	Player->DamageBlurWidget->BloodScreen->SetColorAndOpacity(CurrentColor);

	//blur 투명도 0되면 타이머 정지
	if (CurrentColor.A <= 0.f)
	{
		CurrentColor.A = 1.f;
		Player->DamageBlurWidget->BloodScreen->SetColorAndOpacity(CurrentColor);
		Player->DamageBlurWidget->SetVisibility(ESlateVisibility::Hidden); //Damage Blur 끄기
		GetWorld()->GetTimerManager().ClearTimer(BlurTimerHandle);
	}
}
