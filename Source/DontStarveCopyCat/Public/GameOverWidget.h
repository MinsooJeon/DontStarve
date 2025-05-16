// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* RetryButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void OnClickRestart();
	UFUNCTION()
	void OnClickQuit();

	UFUNCTION()
	void SetActiveGameOver(bool bActive);
	
};
