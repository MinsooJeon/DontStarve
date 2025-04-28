// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GatherableItem.h"
#include "GatherableBush.generated.h"

UCLASS()
class DONTSTARVECOPYCAT_API AGatherableBush : public AGatherableItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGatherableBush();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//상속받은 채집함수
	virtual void OnGather() override;

};
