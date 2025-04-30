// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GatherableItem.h"
#include "GameFramework/Actor.h"
#include "GatherableTree.generated.h"

UCLASS()
class DONTSTARVECOPYCAT_API AGatherableTree : public AGatherableItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGatherableTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//나무 밑둥 Trunk Mesh 추가
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* MeshCompBottom;

	//상속받은 도끼질함수
	virtual void OnChopping() override;
};