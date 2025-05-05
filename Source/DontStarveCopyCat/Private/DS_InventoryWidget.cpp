// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_InventoryWidget.h"
#include "InventoryComponent.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "DS_Player.h"

void UDS_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CacheSlotWidgets();

	if (InventoryButtons[0])
	{
		InventoryButtons[0]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory0SlotClicked);
	}
	if (InventoryButtons[1])
	{
		InventoryButtons[1]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory1SlotClicked);
	}
	if (InventoryButtons[2])
	{
		InventoryButtons[2]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory2SlotClicked);
	}
	if (InventoryButtons[3])
	{
		InventoryButtons[3]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory3SlotClicked);
	}
	if (InventoryButtons[4])
	{
		InventoryButtons[4]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory4SlotClicked);
	}
	if (InventoryButtons[5])
	{
		InventoryButtons[5]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory5SlotClicked);
	}
	if (InventoryButtons[6])
	{
		InventoryButtons[6]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory6SlotClicked);
	}
	if (InventoryButtons[7])
	{
		InventoryButtons[7]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory7SlotClicked);
	}
	if (InventoryButtons[8])
	{
		InventoryButtons[8]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory8SlotClicked);
	}
	if (InventoryButtons[9])
	{
		InventoryButtons[9]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory9SlotClicked);
	}
	if (InventoryButtons[10])
	{
		InventoryButtons[10]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory10SlotClicked);
	}
	if (InventoryButtons[11])
	{
		InventoryButtons[11]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory11SlotClicked);
	}
	if (InventoryButtons[12])
	{
		InventoryButtons[12]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory12SlotClicked);
	}
	if (InventoryButtons[13])
	{
		InventoryButtons[13]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory13SlotClicked);
	}
	if (InventoryButtons[14])
	{
		InventoryButtons[14]->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnInventory14SlotClicked);
	}

	//Cast 플레이어
	PlayerRef = Cast<ADS_Player>(UGameplayStatics::GetPlayerCharacter(this, 0));
	InventoryData = &PlayerRef->InventoryComp->Items;
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

	InventoryTextPercents = {
		BottomText1,BottomText2,BottomText3,BottomText4,BottomText5,
		BottomText6,BottomText7,BottomText8,BottomText9,BottomText10,
		BottomText11,BottomText12,BottomText13,BottomText14,BottomText15
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
			//채집 아이템 일때
			if (false == Item.IsEquip)
			{
				if (InventoryTextCounts[i])
				{
					InventoryTextCounts[i]->SetText(FText::AsNumber(Item.Quantity));
					InventoryTextCounts[i]->SetVisibility(ESlateVisibility::Visible);
				}
			}
			//도구 아이템 일때
			else
			{
				if (InventoryTextPercents[i])
				{
					InventoryTextPercents[i]->SetText(FText::AsPercent(1.f)); // 100%
					InventoryTextPercents[i]->SetVisibility(ESlateVisibility::Visible);
				}
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
			if (InventoryTextPercents[i])
			{
				InventoryTextPercents[i]->SetText(FText::GetEmpty());
				InventoryTextPercents[i]->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

void UDS_InventoryWidget::OnInventory0SlotClicked()
{
	OnInventorySlotClicked(0);
}

void UDS_InventoryWidget::OnInventory1SlotClicked()
{
	OnInventorySlotClicked(1);
}

void UDS_InventoryWidget::OnInventory2SlotClicked()
{
	OnInventorySlotClicked(2);
}

void UDS_InventoryWidget::OnInventory3SlotClicked()
{
	OnInventorySlotClicked(3);
}

void UDS_InventoryWidget::OnInventory4SlotClicked()
{
	OnInventorySlotClicked(4);
}

void UDS_InventoryWidget::OnInventory5SlotClicked()
{
	OnInventorySlotClicked(5);
}

void UDS_InventoryWidget::OnInventory6SlotClicked()
{
	OnInventorySlotClicked(6);
}

void UDS_InventoryWidget::OnInventory7SlotClicked()
{
	OnInventorySlotClicked(7);
}

void UDS_InventoryWidget::OnInventory8SlotClicked()
{
	OnInventorySlotClicked(8);
}

void UDS_InventoryWidget::OnInventory9SlotClicked()
{
	OnInventorySlotClicked(9);
}

void UDS_InventoryWidget::OnInventory10SlotClicked()
{
	OnInventorySlotClicked(10);
}

void UDS_InventoryWidget::OnInventory11SlotClicked()
{
	OnInventorySlotClicked(11);
}

void UDS_InventoryWidget::OnInventory12SlotClicked()
{
	OnInventorySlotClicked(12);
}

void UDS_InventoryWidget::OnInventory13SlotClicked()
{
	OnInventorySlotClicked(13);
}

void UDS_InventoryWidget::OnInventory14SlotClicked()
{
	OnInventorySlotClicked(14);
}

void UDS_InventoryWidget::OnInventorySlotClicked(int32 SlotIndex)
{
	if (!InventoryData || !InventoryData->IsValidIndex(SlotIndex))
		return;

	//선택한 아이템
	FInventoryItem ClickedItem = (*InventoryData)[SlotIndex];

	//아무것도 없을 때 아무 행동하지 않음
	if (ClickedItem.ItemID == NAME_None)
		return;

	//장비 아이템일 경우에만
	if (ClickedItem.IsEquip)
	{
		//장비 슬롯에 표시
		EquipImage1->SetBrushFromTexture(ClickedItem.ItemIcon);
		EquipImage1->SetVisibility(ESlateVisibility::Visible);
		EquipText1->SetText(FText::AsPercent(1.f)); //100%
		EquipText1->SetVisibility(ESlateVisibility::Visible);

		//기존 슬롯 UI 초기화
		InventoryImages[SlotIndex]->SetBrushFromTexture(nullptr);
		InventoryImages[SlotIndex]->SetVisibility(ESlateVisibility::Hidden);
		InventoryTextPercents[SlotIndex]->SetText(FText::GetEmpty());
		InventoryTextPercents[SlotIndex]->SetVisibility(ESlateVisibility::Hidden);

		//데이터 삭제
		(*InventoryData)[SlotIndex] = FInventoryItem();

		//손에 장비 보여주기
		if (ClickedItem.ItemID == "Axe")
		{
			PlayerRef->AxeMeshComp->SetVisibility(true);
		}
	}
}


