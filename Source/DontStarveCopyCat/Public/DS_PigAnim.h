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
	// 태어날 때 Pig를 가져와서 기억하기
	virtual void NativeBeginPlay() override;
	
	UPROPERTY()
	class ADS_AnimalPig* Me;

	UPROPERTY()
	class ADS_Player* Player;
	
	//돼지 이동 여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Animation)
	bool bMove;
	
	//돼지->플레이어 공격 여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Animation)
	bool bAttack;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float AlphaValue = 0.f;

	FTimerHandle BlurTimerHandle;

	bool bIsAttacking = false;
	
	//돼지 공격 몽타주 Notify
	UFUNCTION()
	void AnimNotify_PigAttack();

	//돼지 공격 몽타주 End Notify
	UFUNCTION()
	void AnimNotify_PigAttackEnd();

	//Blur 위젯 업데이트 함수
	UFUNCTION()
	void UpdateBlurAlpha();
};
