// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_StatWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/TextBlock.h"

void UDS_StatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//처음에 숨김
	HungryText->SetVisibility(ESlateVisibility::Hidden);
	HealthText->SetVisibility(ESlateVisibility::Hidden);
	SanityText->SetVisibility(ESlateVisibility::Hidden);
	
}

void UDS_StatWidget::SetStats(int32 HungerValue, int32 HealthValue, int32 SanityValue)
{
	CurrentHungerValue = HungerValue;
	CurrentHealthValue = HealthValue;
	CurrentSanityValue = SanityValue;
}

