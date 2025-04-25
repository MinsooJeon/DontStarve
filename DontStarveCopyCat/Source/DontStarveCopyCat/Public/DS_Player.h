// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "DS_Player.generated.h"

UCLASS()
class DONTSTARVECOPYCAT_API ADS_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADS_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//플레이어 소유
	virtual void NotifyControllerChanged() override;
	
	//플레이어 스프링암, 카메라
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TObjectPtr<class USpringArmComponent> SpringArmComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TObjectPtr<class UCameraComponent> CameraComp;
	
	//플레이어 이동방향
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction;
	
	//Shadow Decal
	UPROPERTY(EditAnywhere, Category = "Shadow")
	class UDecalComponent* ShadowDecal;

	//채집 가능 거리
	UPROPERTY(EditAnywhere, Category = "Interaction")
	float GatherRange = 50.f;

	//Action
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputMappingContext* IMC_DontStarve;
	
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Move;

	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Gather;
	
	//플레이어 움직임 함수
	void OnActionMove(const FInputActionValue& value);
	
	//채집 시도 함수
	UFUNCTION()
	void TryGather();
};


