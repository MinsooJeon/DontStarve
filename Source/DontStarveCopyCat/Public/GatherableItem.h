// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GatherableItem.generated.h"

UCLASS()
class DONTSTARVECOPYCAT_API AGatherableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGatherableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//아이템메쉬
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* MeshComp;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite)
	//class UStaticMeshComponent* OutlineMesh;

	// //메쉬 아웃라인 머터리얼
	// UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Outline")
	// TObjectPtr<UMaterialInterface> BlackMaterial;
	
	//아이템이름
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString ItemName;
	
	//채집여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bDestroyOnGather;
	//도끼질여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bOnChopping;
	//줍기여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bOnPickUp;
	
	//채집함수
	UFUNCTION()
	virtual void OnGather();
	//도끼질함수
	UFUNCTION()
	virtual void OnChopping();
	//줍기함수
	UFUNCTION()
	virtual void OnPickUp();
};

