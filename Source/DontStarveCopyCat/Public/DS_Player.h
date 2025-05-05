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

	// //camera 회전 각도
	// UPROPERTY(EditAnywhere, Category = "Camera")
	// float CameraRotateAmount = 45.0f;
	
	//상호작용 가능 거리
	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRange = 50.f;

	//Bush 채집 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bGatherBush;

	//Tree 도끼질 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bChopTree;

	//줍기 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bPickUp;
	
	//채집 중인 Bush 액터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	class AGatherableBush* Bush;

	//도끼질 중인 Tree 액터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	class AGatherableTree* Tree;

	//줍기 중인 Flint 액터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	class AGatherableFlint* Flint;

	//줍기 중인 Twigs 액터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	class AGatherableTwigs* Twigs;
	
	//도끼 메시 장착
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* AxeMeshComp;

	//횃불 메시 장착
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* TorchMeshComp;
	
	//Action
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputMappingContext* IMC_DontStarve;
	
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Move;

	// UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	// class UInputAction* IA_DS_CameraRotation;
	
	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Gather;

	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_Chop;

	UPROPERTY(EditAnywhere, Category = "DS_PlayerInput")
	class UInputAction* IA_DS_PickUp;

	//플레이어 애니메이션
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDS_PlayerAnim* PlayerAnim;

	//채집 몽타주
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMontage")
	class UAnimMontage* GatherMontage;

	//도끼질 몽타주
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMontage")
	class UAnimMontage* ChopMontage;

	//줍기 몽타주
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMontage")
	class UAnimMontage* PickUpMontage;
	
	//플레이어 움직임 함수
	void OnActionMove(const FInputActionValue& value);

	// //카메라 좌우 회전
	// void OnActionCameraRotation(const FInputActionValue& value);
	
	//채집 시도 함수
	UFUNCTION()
	void TryGather();
	
	//채집 끝 AnimNotify
	UFUNCTION()
	void GatherEndNotify();

	//도끼질 시도 함수
	UFUNCTION()
	void TryChopping();

	//도끼질 끝 AnimNotify
	UFUNCTION()
	void ChopEndNotify();

	//줍기 시도 함수
	UFUNCTION()
	void TryPickUp();

	//줍기 끝 AnimNotify
	UFUNCTION()
	void PickUpEndNotify();


	//인게임 UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DS_Widget")
	TSubclassOf<class UUserWidget> MenuWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DS_Widget")
	TSubclassOf<class UUserWidget> InventoryWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DS_Widget")
	TSubclassOf<class UUserWidget> StatWidgetClass;
	
	UPROPERTY()
	UUserWidget* MenuWidget;
	UPROPERTY()
	UUserWidget* InventoryWidget;
	UPROPERTY()
	UUserWidget* StatWidget;

	UPROPERTY()
	class UDS_InventoryWidget* InventorySlotWidget;
	
	//인벤토리 컴포넌트 붙이기
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TObjectPtr<class UInventoryComponent> InventoryComp;
	
};


