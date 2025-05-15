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
	//플레이어를 시작할때 기억하기
	virtual void NativeBeginPlay() override;

	UPROPERTY()
	class ADS_Player* Player;
	
	//움직임 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerMove;

	//Bush 채집 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlayerGatherBush;

	//돼지 도끼질 End Notify
	UFUNCTION()
	void AnimNotify_PigChoppingEnd();
};
