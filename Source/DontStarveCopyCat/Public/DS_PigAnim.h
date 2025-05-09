// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DS_PigAnim.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDS_PigAnim : public UAnimInstance
{
	GENERATED_BODY()

public:

	//돼지->플레이어 공격 여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Animation)
	bool bAttack;
};
