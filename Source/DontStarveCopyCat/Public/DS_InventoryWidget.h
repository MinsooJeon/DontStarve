// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemStruct.h"
#include "DS_InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDS_InventoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	//슬롯 초기화 함수
	void CacheSlotWidgets();
	
public:
	
	//슬롯 바인드
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton1;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton2;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton3;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton4;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton5;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton6;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton7;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton8;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton9;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton10;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton11;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton12;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton13;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton14;
	UPROPERTY(meta = (BindWidget))
	class UButton* InventoryButton15;

	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage1;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage2;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage3;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage4;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage5;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage6;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage7;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage8;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage9;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage10;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage11;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage12;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage13;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage14;
	UPROPERTY(meta = (BindWidget))
	class UImage* InventoryImage15;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText1;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText2;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText3;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText4;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText5;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText6;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText7;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText8;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText9;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText10;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText11;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText12;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText13;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText14;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TopText15;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText1;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText2;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText3;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText4;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText5;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText6;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText7;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText8;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText9;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText10;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText11;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText12;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText13;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText14;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BottomText15;

	

	//배열로 활용
	UPROPERTY()
	TArray<UButton*> InventoryButtons;

	UPROPERTY()
	TArray<UImage*> InventoryImages;

	UPROPERTY()
	TArray<UTextBlock*> InventoryTextCounts;

	UPROPERTY()
	TArray<UTextBlock*> InventoryTextPercents;

	//장비 인벤토리 슬롯
	UPROPERTY(meta = (BindWidget))
	class UImage* EquipImage1;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* EquipText1;

	//플레이어 포인터 저장
	class ADS_Player* PlayerRef;

	//인벤토리 데이터 참조
	TArray<FInventoryItem>* InventoryData;

	//슬롯 전체 업데이트
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateAllSlots(const TArray<FInventoryItem>& InventoryItems);

	//바인딩 함수
	UFUNCTION()
	void OnInventory0SlotClicked();
	UFUNCTION()
	void OnInventory1SlotClicked();
	UFUNCTION()
	void OnInventory2SlotClicked();
	UFUNCTION()
	void OnInventory3SlotClicked();
	UFUNCTION()
	void OnInventory4SlotClicked();
	UFUNCTION()
	void OnInventory5SlotClicked();
	UFUNCTION()
	void OnInventory6SlotClicked();
	UFUNCTION()
	void OnInventory7SlotClicked();
	UFUNCTION()
	void OnInventory8SlotClicked();
	UFUNCTION()
	void OnInventory9SlotClicked();
	UFUNCTION()
	void OnInventory10SlotClicked();
	UFUNCTION()
	void OnInventory11SlotClicked();
	UFUNCTION()
	void OnInventory12SlotClicked();
	UFUNCTION()
	void OnInventory13SlotClicked();
	UFUNCTION()
	void OnInventory14SlotClicked();
	
	UFUNCTION()
	void OnInventorySlotClicked(int32 SlotIndex);
	
};




