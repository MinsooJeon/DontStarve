// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	ConstructorHelpers::FObjectFinder<UTexture2D> AxeIconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/Axe"));
	if (AxeIconTemp.Succeeded())
	{
		AxeIcon = AxeIconTemp.Object;
	}
	ConstructorHelpers::FObjectFinder<UTexture2D> TorchIconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/Torch"));
	if (TorchIconTemp.Succeeded())
	{
		TorchIcon = TorchIconTemp.Object;
	}
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

		//빈공간 찾아서 채워서 아이템 추가
		AddItemToFirstEmptySlot(NewItem);
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
	Axe.ItemIcon = AxeIcon;
	Axe.IsEquip = true;
	
	AddItem(Axe.ItemID, Axe.ItemIcon, Axe.IsEquip, Axe.Quantity);

	FInventoryItem Torch;
	Torch.ItemID = FName(TEXT("Torch"));
	Torch.Quantity = 1;
	Torch.ItemIcon = TorchIcon;
	Torch.IsEquip = true;
	
	AddItem(Torch.ItemID, Torch.ItemIcon, Torch.IsEquip, Torch.Quantity);
}

void UInventoryComponent::RemoveItem(int32 Index)
{
	if (Items.IsValidIndex(Index))
	{
		Items[Index] = FInventoryItem();
	}
}

bool UInventoryComponent::AddItemToFirstEmptySlot(const FInventoryItem& NewItem)
{
	for (int32 i = 0; i< Items.Num(); i++)
	{
		if (Items[i].Quantity == 0)
		{
			Items[i] = NewItem;
			return true;
		}
	}

	//빈자리 없으면 확장
	Items.Add(NewItem);
	return true;
}

