// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_MenuWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"

void UDS_MenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//메뉴 버튼들 이벤트 바인딩
	if (MenuButton1)
	{
		MenuButton1->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention1);
	}
	if (MenuButton2)
	{
		MenuButton2->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention2);
	}
	if (MenuButton3)
	{
		MenuButton3->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention3);
	}
	if (MenuButton4)
	{
		MenuButton4->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention4);
	}
	if (MenuButton5)
	{
		MenuButton5->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention5);
	}
	if (MenuButton6)
	{
		MenuButton6->OnClicked.AddDynamic(this, &UDS_MenuWidget::OnOpenMenuExtention6);
	}

	//메뉴 세부 창 배열로 묶기
	MenuExtention = {
		MenuExtentionTop, MenuExtentionBottom, Board0, Board1, Board2, Board3, Board4, Board5, Board6,
		RopeL0, RopeL1, RopeL2, RopeL3, RopeL4, RopeL5, RopeR0, RopeR1, RopeR2, RopeR3, RopeR4, RopeR5
	};
	//메뉴 별 Open 여부 배열
	bIsOpenMenus = {
		bIsOpenMenu1, bIsOpenMenu2, bIsOpenMenu3, bIsOpenMenu4,bIsOpenMenu5,bIsOpenMenu6
	};
}

void UDS_MenuWidget::OnOpenMenuExtention1()
{
	MenuButtonClicked(0);
}

void UDS_MenuWidget::OnOpenMenuExtention2()
{
	MenuButtonClicked(1);
}

void UDS_MenuWidget::OnOpenMenuExtention3()
{
	MenuButtonClicked(2);
}

void UDS_MenuWidget::OnOpenMenuExtention4()
{
	MenuButtonClicked(3);
}

void UDS_MenuWidget::OnOpenMenuExtention5()
{
	MenuButtonClicked(4);
}

void UDS_MenuWidget::OnOpenMenuExtention6()
{
	MenuButtonClicked(5);
}

void UDS_MenuWidget::MenuButtonClicked(int32 Index)
{
	//메뉴 세부 창 닫혀있으면
	if (false == bIsOpenMenus[Index])
	{
		//이미 열려 있는 세부 창 고려해서 나머지는 창은 모두 false
		for (int i = 0; i< bIsOpenMenus.Num(); i++)
		{
			if (Index == i)
				bIsOpenMenus[i] = true;
			else
				bIsOpenMenus[i] = false;
		}
		//SlideInAnimation 실행
		if (SlideInAnimation)
		{
			PlayAnimation(SlideInAnimation);
		}
	}
	//메뉴 세부 창 열려있으면.
	else
	{
		//해당 세부 창 닫기
		bIsOpenMenus[Index] = false;

		if (SlideOutAnimation)
		{
			PlayAnimation(SlideOutAnimation);
		}
	}
}
