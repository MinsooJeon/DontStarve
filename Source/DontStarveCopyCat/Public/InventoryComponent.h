// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemStruct.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONTSTARVECOPYCAT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	//인벤토리 배열
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventoryItem> Items;

	//아이템 추가 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(FName ItemID, UTexture2D* ItemIcon, bool IsEquip, int32 Quantity = 1);

	//아이템 찾기 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 FindItemIndex(FName ItemID) const;


	//초기 아이템 설정
	void InitializeDefaultItems();

	//인벤토리 아이템 제거 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(int32 Index);

	//빈 슬롯을 찾아서 넣는 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemToFirstEmptySlot(const FInventoryItem& NewItem);
};
