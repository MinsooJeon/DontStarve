// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_StatWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Slate/SlateBrushAsset.h"

void UDS_StatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//처음에 숨김
	HungryText->SetVisibility(ESlateVisibility::Hidden);
	HealthText->SetVisibility(ESlateVisibility::Hidden);
	SanityText->SetVisibility(ESlateVisibility::Hidden);

	StatHungryTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/DontStarveCopyCat/UI/Images/hunger_level-0.hunger_level-0'"));
	
}

void UDS_StatWidget::UpdateStatBar(float Ratio)
{
	if (!HungryImageFill || Ratio < 0.f || Ratio > 1.f)
		return;

	// //UVRegion 세팅
	// FBox2D UVRegion;
	// UVRegion.Min = FVector2D(0.f, 1.f - Ratio); //위에서부터 차오르게
	// UVRegion.Max = FVector2D(1.f, 1.f);
	//
	// //새로운 브러시 생성
	// FSlateBrush NewBrush;
	// NewBrush.SetResourceObject(StatHungryTexture);
	// NewBrush.ImageSize = FVector2D(136.f, 136.f);
	// NewBrush.DrawAs = ESlateBrushDrawType::Type::Image;
	// NewBrush.SetUVRegion(UVRegion);
	//
	// //브러시 갱신
	// HungryImageFill->SetBrush(NewBrush);
	//
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Hungry image");
	
}

