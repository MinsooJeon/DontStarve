// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DS_MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DONTSTARVECOPYCAT_API UDS_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	//메뉴 버튼
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton3;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton4;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton5;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (BindWidget))
	class UButton* MenuButton6;

	//메뉴 세부 창
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* MenuExtentionTop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* MenuExtentionBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Board6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeL5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* RopeR5;

	//메뉴 세부 창 배열
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UImage*> MenuExtention;

	//메뉴 세부 창 Open 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu1 = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu2 = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu3 = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu4 = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu5 = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenMenu6 = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<bool> bIsOpenMenus;

	//애니메이션 바인딩
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* SlideInAnimation;
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* SlideOutAnimation;
	
	//메뉴 세부 창 열기 함수
	UFUNCTION()
	void OnOpenMenuExtention1();
	UFUNCTION()
	void OnOpenMenuExtention2();
	UFUNCTION()
	void OnOpenMenuExtention3();
	UFUNCTION()
	void OnOpenMenuExtention4();
	UFUNCTION()
	void OnOpenMenuExtention5();
	UFUNCTION()
	void OnOpenMenuExtention6();
	//버튼 공통 함수
	UFUNCTION()
	void MenuButtonClicked(int32 Index);
	
};
