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

	//이미지, 텍스트 바인딩
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HungryImage;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HealthImage;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* SanityImage;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HungryImageFill;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HealthImageFill;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* SanityImageFill;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HungryText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HealthText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SanityText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	class UTexture2D* StatHungryTexture;
	
	//수치 업데이트 함수
	void UpdateStatBar(float Ratio);
	
};
