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

	//채집여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bDestroyOnGather;

	//아이템이름
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString ItemName;

	//아이템메쉬
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* MeshComp;

	//채집함수
	UFUNCTION()
	virtual void OnGather();
	
};

