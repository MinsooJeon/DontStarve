// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GatherableItem.h"
#include "GameFramework/Actor.h"
#include "GatherableTwigs.generated.h"


UCLASS()
class DONTSTARVECOPYCAT_API AGatherableTwigs : public AGatherableItem
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AGatherableTwigs();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
