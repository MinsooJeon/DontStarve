// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventoryItemStruct.generated.h"

//아이템 구조체
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	//아이템 아이디
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;

	//아이템 양
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity;

	//아이템 아이콘
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* ItemIcon;

	//생성자 함수
	FInventoryItem() : ItemID(NAME_None), Quantity(0), ItemIcon(nullptr) {}
		
};


class DONTSTARVECOPYCAT_API InventoryItemStruct
{
public:
	InventoryItemStruct();
	~InventoryItemStruct();
};
