// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "slate/SlateBrushAsset.h"
#include "DS_StatWidget.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDS_StatWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//생성자 함수
	virtual void NativeConstruct() override;

	//이미지, 프로그래스바, 버튼, 텍스트 바인딩
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HungryImage;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HealthImage;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* SanityImage;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HungryImageFillBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthImageFillBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* SanityImageFillBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* HungryButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* HealthButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* SanityButton;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HungryText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HealthText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SanityText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ADS_Player* Player;
	
	//수치 업데이트 함수
	void UpdateStatBar(float HungerRatio, float HealthRatio, float SanityRatio);

	//마우스 이벤트 함수
	UFUNCTION()
	void OnHungerHovered();
	UFUNCTION()
	void OnHungerUnhovered();

	UFUNCTION()
	void OnHealthHovered();
	UFUNCTION()
	void OnHealthUnhovered();

	UFUNCTION()
	void OnSanityHovered();
	UFUNCTION()
	void OnSanityUnhovered();
	
};
