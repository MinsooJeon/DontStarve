// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddItem(FName ItemID, UTexture2D* ItemIcon, bool IsEquip, int32 Quantity)
{
	//아이템 인덱스 찾기
	int32 Index = FindItemIndex(ItemID);

	//아이템이 있다면 갯수 추가
	if (Index != INDEX_NONE)
	{
		Items[Index].Quantity += Quantity;
	}
	//아이템이 없으면 새로 추가
	else
	{
		FInventoryItem NewItem;
		NewItem.ItemID = ItemID;
		NewItem.Quantity = Quantity;
		NewItem.ItemIcon = ItemIcon;
		NewItem.IsEquip = IsEquip;

		Items.Add(NewItem);
	}
}

int32 UInventoryComponent::FindItemIndex(FName ItemID) const
{
	//아이템 인덱스 찾기
	for (int32 i = 0; i<Items.Num(); i++)
	{
		if (Items[i].ItemID == ItemID)
		{
			return i;
		}
	}
	return INDEX_NONE;
}

void UInventoryComponent::InitializeDefaultItems()
{
	//도끼와 횃불 아이템 세팅
	FInventoryItem Axe;
	Axe.ItemID = FName(TEXT("Axe"));
	Axe.Quantity = 1;
	Axe.ItemIcon = LoadObject<UTexture2D>(nullptr, TEXT("/Game/DontStarveCopyCat/UI/Images/Axe"));
	Axe.IsEquip = true;
	
	AddItem(Axe.ItemID, Axe.ItemIcon, Axe.IsEquip, Axe.Quantity);

	FInventoryItem Torch;
	Torch.ItemID = FName(TEXT("Torch"));
	Torch.Quantity = 1;
	Torch.ItemIcon = LoadObject<UTexture2D>(nullptr, TEXT("/Game/DontStarveCopyCat/UI/Images/Torch"));
	Torch.IsEquip = true;
	
	AddItem(Torch.ItemID, Torch.ItemIcon, Torch.IsEquip, Torch.Quantity);
}

