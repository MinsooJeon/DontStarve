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

	//플레이어 움직임 함수
	void OnActionMove(const FInputActionValue& value);

	//Action
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputMappingContext* IMC_DontStarve;
	
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Move;
};
