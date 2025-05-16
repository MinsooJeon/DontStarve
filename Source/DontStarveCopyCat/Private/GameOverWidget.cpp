// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RetryButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnClickRestart);
	QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnClickQuit);

	SetActiveGameOver(false);
}

void UGameOverWidget::OnClickRestart()
{
	FString levelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UGameplayStatics::OpenLevel(GetWorld(), FName(*levelName));
	
}

void UGameOverWidget::OnClickQuit()
{
	auto* pc = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), pc, EQuitPreference::Quit, false);
}

void UGameOverWidget::SetActiveGameOver(bool bActive)
{
	this->SetVisibility(bActive ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
