// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_StatWidget.h"

#include "DS_Player.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Slate/SlateBrushAsset.h"

void UDS_StatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//처음에 숨김
	HungryText->SetVisibility(ESlateVisibility::Hidden);
	HealthText->SetVisibility(ESlateVisibility::Hidden);
	SanityText->SetVisibility(ESlateVisibility::Hidden);

	//ProgressBar Type
	HungryImageFillBar->SetBarFillType(EProgressBarFillType::BottomToTop);
	HealthImageFillBar->SetBarFillType(EProgressBarFillType::BottomToTop);
	SanityImageFillBar->SetBarFillType(EProgressBarFillType::BottomToTop);

	//마우스 바인딩
	if (HungryButton)
	{
		HungryButton->OnHovered.AddDynamic(this, &UDS_StatWidget::OnHungerHovered);
		HungryButton->OnUnhovered.AddDynamic(this, &UDS_StatWidget::OnHungerUnhovered);
	}
	if (HealthButton)
	{
		HealthButton->OnHovered.AddDynamic(this, &UDS_StatWidget::OnHealthHovered);
		HealthButton->OnUnhovered.AddDynamic(this, &UDS_StatWidget::OnHealthUnhovered);
	}
	if (SanityButton)
	{
		SanityButton->OnHovered.AddDynamic(this, &UDS_StatWidget::OnSanityHovered);
		SanityButton->OnUnhovered.AddDynamic(this, &UDS_StatWidget::OnSanityUnhovered);
	}

	//플레이어
	Player = Cast<ADS_Player>(GetWorld()->GetFirstPlayerController()->GetCharacter());
}

void UDS_StatWidget::UpdateStatBar(float HungerRatio, float HealthRatio, float SanityRatio)
{
	if (HungryImageFillBar)
	{
		HungryImageFillBar->SetPercent(HungerRatio);
	}
	if (HealthImageFillBar)
	{
		HealthImageFillBar->SetPercent(HealthRatio);
	}
	if (SanityImageFillBar)
	{
		SanityImageFillBar->SetPercent(SanityRatio);
	}
}

void UDS_StatWidget::OnHungerHovered()
{
	HungryText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentHungerValue))));
	HungryText->SetVisibility((ESlateVisibility::Visible));
}

void UDS_StatWidget::OnHungerUnhovered()
{
	HungryText->SetVisibility((ESlateVisibility::Hidden));
}

void UDS_StatWidget::OnHealthHovered()
{
	HealthText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentHealthValue))));
	HealthText->SetVisibility((ESlateVisibility::Visible));
}

void UDS_StatWidget::OnHealthUnhovered()
{
	HealthText->SetVisibility((ESlateVisibility::Hidden));
}

void UDS_StatWidget::OnSanityHovered()
{
	SanityText->SetText(FText::FromString(FString::Printf(TEXT("%d"), FMath::FloorToInt(Player->CurrentSanityValue))));
	SanityText->SetVisibility((ESlateVisibility::Visible));
}

void UDS_StatWidget::OnSanityUnhovered()
{
	SanityText->SetVisibility((ESlateVisibility::Hidden));
}

// void UDS_StatWidget::UpdateStatBar(float Ratio)
// {
// 	if (!HungryImageFillBar || Ratio < 0.f || Ratio > 1.f)
// 		return;

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
	
//}

