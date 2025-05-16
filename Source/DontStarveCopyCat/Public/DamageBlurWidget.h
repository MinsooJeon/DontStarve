// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DamageBlurWidget.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDamageBlurWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* BloodScreen;
	
};
