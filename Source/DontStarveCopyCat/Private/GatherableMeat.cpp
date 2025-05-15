// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableMeat.h"

#include "Components/BoxComponent.h"

AGatherableMeat::AGatherableMeat()
{
	PrimaryActorTick.bCanEverTick = true;

	//콜라이더 박스크기
	BoxComp->SetBoxExtent(FVector(50.f));
	//메시 위치
	MeshComp->SetRelativeLocation(FVector(0.f, 0.f, -50.f));
	MeshComp->SetRelativeScale3D(FVector(8.f));
	//고기 메시 가져오기
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Game/DontStarveCopyCat/Models/MorselRaw.MorselRaw"));
	if (tempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(tempMesh.Object);
	}
	//고기 메시 이름
	ItemID = TEXT("GatherableMeat");

	//고기 아이콘
	ConstructorHelpers::FObjectFinder<UTexture2D> IconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/meat_small01-0.meat_small01-0"));
	if (IconTemp.Succeeded())
	{
		ItemIcon = IconTemp.Object;
	}

	IsEquip = false;
}

void AGatherableMeat::BeginPlay()
{
	Super::BeginPlay();
}

void AGatherableMeat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGatherableMeat::OnPickUp()
{
	Super::OnPickUp();
}