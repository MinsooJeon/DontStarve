// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DS_PlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDS_PlayerAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	//움직임 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerMove;

	//Bush 채집 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerGatherBush;
};
