// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_InventoryWidget.h"
#include "InventoryComponent.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "DS_Player.h"
#include "DS_PlayerAnim.h"

void UDS_InventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CacheSlotWidgets();

	//인벤토리 슬롯 버튼 클릭
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

	//장비 슬롯 버튼 클릭
	if (EquipButton1)
	{
		EquipButton1->OnClicked.AddDynamic(this, &UDS_InventoryWidget::OnEquipInventorySlotClicked);
	}

	//Cast 플레이어
	PlayerRef = Cast<ADS_Player>(UGameplayStatics::GetPlayerCharacter(this, 0));
	InventoryData = &PlayerRef->InventoryComp->Items;
	EquipData = &PlayerRef->InventoryComp->EquipItems;
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
			if (InventoryImages[i] && Item.Quantity != 0)
			{
				InventoryImages[i]->SetBrushFromTexture(Item.ItemIcon);
				InventoryImages[i]->SetVisibility(ESlateVisibility::Visible);
			}
			//채집 아이템 일때
			if (false == Item.IsEquip)
			{
				if (InventoryTextCounts[i] && Item.Quantity != 0)
				{
					InventoryTextCounts[i]->SetText(FText::AsNumber(Item.Quantity));
					InventoryTextCounts[i]->SetVisibility(ESlateVisibility::Visible);
				}
			}
			//도구 아이템 일때
			else
			{
				if (InventoryTextPercents[i] && Item.Quantity != 0)
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

void UDS_InventoryWidget::OnEquipInventorySlotClicked()
{
	if (!EquipData || false == EquipData->IsValidIndex(0))
		return;

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Equip Delete");
	//장비 슬롯에 있는 아이템 정보 인벤토리 구조체에 임시저장
	FInventoryItem NewItem;
	NewItem.ItemID = (*EquipData)[0].EquipItemID;
	NewItem.Quantity = (*EquipData)[0].EquipQuantity;
	NewItem.ItemIcon = (*EquipData)[0].EquipItemIcon;
	NewItem.IsEquip = (*EquipData)[0].IsEquip;

	//장비 슬롯에 있는 이미지, 내구도 % 지우기
	EquipImage1->SetBrushFromTexture(nullptr);
	EquipImage1->SetVisibility(ESlateVisibility::Hidden);
	EquipText1->SetText(FText::AsPercent(0.f)); //0%
	EquipText1->SetVisibility(ESlateVisibility::Hidden);

	//장비 슬롯 구조체에서 값 초기화
	(*EquipData)[0] = FInventoryEquip();

	//인벤토리 데이터에 빈 슬롯에 저장하기
	PlayerRef->InventoryComp->AddItemToFirstEmptySlot(NewItem);

	//인벤토리 업데이트하기
	UpdateAllSlots((*InventoryData));

	//플레이어 장비 아이템 장착 끄기
	if (NewItem.ItemID == "Axe")
	{
		if (PlayerRef->AxeMeshComp->IsVisible())
		{
			PlayerRef->AxeMeshComp->SetVisibility(false);
		}
		if (PlayerRef->PlayerAnim->Montage_IsPlaying(PlayerRef->HoldingToolMontage))
		{
			PlayerRef->PlayerAnim->Montage_Stop(0.1f, PlayerRef->HoldingToolMontage);
			PlayerRef->IsPlayingHoldingToolMontage = false;
		}
	}
	if (NewItem.ItemID == "Torch")
	{
		if (PlayerRef->TorchMeshComp->IsVisible())
		{
			PlayerRef->TorchMeshComp->SetVisibility(false);
			PlayerRef->TorchFlameVFX->SetVisibility(false);
			PlayerRef->TorchFlameVFX->Deactivate();
			PlayerRef->TorchLight->SetVisibility(false);
		}
		if (PlayerRef->PlayerAnim->Montage_IsPlaying(PlayerRef->HoldingToolMontage))
		{
			PlayerRef->PlayerAnim->Montage_Stop(0.1f, PlayerRef->HoldingToolMontage);
			PlayerRef->IsPlayingHoldingToolMontage = false;
		}
	}
	
}

void UDS_InventoryWidget::OnInventorySlotClicked(int32 SlotIndex)
{
	if (!InventoryData || false == InventoryData->IsValidIndex(SlotIndex))
		return;

	//선택한 아이템
	FInventoryItem ClickedItem = (*InventoryData)[SlotIndex];

	//아무것도 없을 때 아무 행동하지 않음
	if (ClickedItem.ItemID == NAME_None)
		return;

	//장비 아이템일 경우에만
	if (ClickedItem.IsEquip)
	{
		//이미 장비 교체한 이력이 있으면
		if (EquipData->IsValidIndex(1))
		{
			(*EquipData)[1].EquipItemID = ClickedItem.ItemID;
			(*EquipData)[1].EquipQuantity = ClickedItem.Quantity;
			(*EquipData)[1].EquipItemIcon =ClickedItem.ItemIcon;
			(*EquipData)[1].IsEquip = ClickedItem.IsEquip;
		}
		//장비교체 이력이 없으면
		else
		{
			//장비 배열에 저장
			FInventoryEquip NewEquip;
			NewEquip.EquipItemID = ClickedItem.ItemID;
			NewEquip.EquipQuantity = ClickedItem.Quantity;
			NewEquip.EquipItemIcon = ClickedItem.ItemIcon;
			NewEquip.IsEquip = ClickedItem.IsEquip;
			EquipData->Add(NewEquip);
		}
		
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
		
		//장비슬롯에 이미 장비가 있으면
		if (EquipData->IsValidIndex(1))
		{
			//임시 인벤토리 데이터 저장
			FInventoryItem NewItem;
			NewItem.ItemID = (*EquipData)[0].EquipItemID;
			NewItem.Quantity = (*EquipData)[0].EquipQuantity;
			NewItem.ItemIcon = (*EquipData)[0].EquipItemIcon;
			NewItem.IsEquip = (*EquipData)[0].IsEquip;

			//0번자리 장비 데이터에 1번자리 장비 데이터 덮어씌우고 1번자리 초기화
			(*EquipData)[0].EquipItemID = (*EquipData)[1].EquipItemID;
			(*EquipData)[0].EquipQuantity = (*EquipData)[1].EquipQuantity;
			(*EquipData)[0].EquipItemIcon =(*EquipData)[1].EquipItemIcon;
			(*EquipData)[0].IsEquip = (*EquipData)[1].IsEquip;
			
			(*EquipData)[1] = FInventoryEquip();
			
			//인벤토리 빈 슬롯에 저장
			PlayerRef->InventoryComp->AddItemToFirstEmptySlot(NewItem);
			//다시 인벤토리 갱신
			UpdateAllSlots(*InventoryData);
		}
		
		//손에 장비 보여주기
		//도끼
		if (ClickedItem.ItemID == "Axe")
		{
			if (PlayerRef->TorchMeshComp->IsVisible())
			{
				PlayerRef->TorchMeshComp->SetVisibility(false);
				PlayerRef->TorchFlameVFX->SetVisibility(false);
				PlayerRef->TorchFlameVFX->Deactivate();
				PlayerRef->TorchLight->SetVisibility(false);
			}
			PlayerRef->AxeMeshComp->SetVisibility(true);

			if (false == PlayerRef->PlayerAnim->Montage_IsPlaying(PlayerRef->HoldingToolMontage))
			{
				PlayerRef->PlayerAnim->Montage_Play(PlayerRef->HoldingToolMontage);
				PlayerRef->IsPlayingHoldingToolMontage = true;
			}
			
		}
		//횃불
		if (ClickedItem.ItemID == "Torch")
		{
			if (PlayerRef->AxeMeshComp->IsVisible())
			{
				PlayerRef->AxeMeshComp->SetVisibility(false);
			}
			PlayerRef->TorchMeshComp->SetVisibility(true);
			PlayerRef->TorchFlameVFX->SetVisibility(true);
			PlayerRef->TorchFlameVFX->Activate();
			PlayerRef->TorchLight->SetVisibility(true);
			if (false == PlayerRef->PlayerAnim->Montage_IsPlaying(PlayerRef->HoldingToolMontage))
			{
				PlayerRef->PlayerAnim->Montage_Play(PlayerRef->HoldingToolMontage);
				PlayerRef->IsPlayingHoldingToolMontage = true;
			}
		}
	}
}


