// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
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
	class UTextBlock* HungryText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HealthText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SanityText;

	//현재 수치, 최대 수치
	UPROPERTY(EditAnywhere)
	int32 CurrentHungerValue;
	UPROPERTY(editAnywhere)
	int32 MaxHungerValue;

	UPROPERTY(EditAnywhere)
	int32 CurrentHealthValue;
	UPROPERTY(EditAnywhere)
	int32 MaxHealthValue;
	
	UPROPERTY(EditAnywhere)
	int32 CurrentSanityValue;
	UPROPERTY(EditAnywhere)
	int32 MaxSanityValue;
	
	
	//수치값 설정 함수
	void SetStats(int32 HungerValue, int32 HealthValue, int32 SanityValue);
	
};
