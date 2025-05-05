// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_InventoryWidget.h"

#include "IDetailTreeNode.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UDS_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CacheSlotWidgets();
}

void UDS_InventoryWidget::CacheSlotWidgets()
{
	InventoryButtons = {
		InventoryButton1,InventoryButton2,InventoryButton3,InventoryButton4,InventoryButton5,
		InventoryButton6,InventoryButton7,InventoryButton8,InventoryButton9,InventoryButton10,
		InventoryButton11,InventoryButton12,InventoryButton13,InventoryButton14,InventoryButton15
	};

	InventoryImages = {
		InventoryImage1,InventoryImage2,InventoryImage3,InventoryImage4,InventoryImage5,
		InventoryImage6,InventoryImage7,InventoryImage8,InventoryImage9,InventoryImage10,
		InventoryImage11,InventoryImage12,InventoryImage13,InventoryImage14, InventoryImage15
	};

	InventoryTextCounts = {
		TopText1,TopText2,TopText3,TopText4,TopText5,
		TopText6,TopText7,TopText8,TopText9,TopText10,
		TopText11,TopText12,TopText13,TopText14,TopText15
	};
}

void UDS_InventoryWidget::UpdateAllSlots(const TArray<FInventoryItem>& InventoryItems)
{
	//전체 인벤토리 아이템을 검색해서, 해당 아이템들 모두 이미지와 갯수 보여주기
	for (int32 i = 0; i< InventoryImages.Num(); i++)
	{
		if (i < InventoryItems.Num())
		{
			const FInventoryItem& Item = InventoryItems[i];
			if (InventoryImages[i])
			{
				InventoryImages[i]->SetBrushFromTexture(Item.ItemIcon);
				InventoryImages[i]->SetVisibility(ESlateVisibility::Visible);
			}
			if (InventoryTextCounts[i])
			{
				InventoryTextCounts[i]->SetText(FText::AsNumber(Item.Quantity));
				InventoryTextCounts[i]->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else
		{
			//빈 슬롯이면 빈 이미지, 텍스트 제거 후 안보이게 숨기기
			if (InventoryImages[i])
			{
				InventoryImages[i]->SetBrushFromTexture(nullptr);
				InventoryImages[i]->SetVisibility(ESlateVisibility::Hidden);
			}
			if (InventoryTextCounts[i])
			{
				InventoryTextCounts[i]->SetText(FText::GetEmpty());
				InventoryTextCounts[i]->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}
