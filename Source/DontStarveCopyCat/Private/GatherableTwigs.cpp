// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableTwigs.h"
#include "Components/BoxComponent.h"

AGatherableTwigs::AGatherableTwigs()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//콜라이더 사이즈
	BoxComp->SetBoxExtent(FVector(50.f));
	//나뭇가지 메시 위치 조정
	MeshComp->SetRelativeLocation(FVector(0, 0, -50.f));
	
	//나뭇가지 메시 가져오기
	ConstructorHelpers::FObjectFinder<UStaticMesh> TwigsTemp(TEXT("/Game/DontStarveCopyCat/Models/SM_MyTwigs.SM_MyTwigs"));
	if (TwigsTemp.Succeeded())
	{
		MeshComp->SetStaticMesh(TwigsTemp.Object);
	}
	//Flint 이름
	ItemID = TEXT("GatherableTwigs");

	//나뭇가지 아이콘
	ConstructorHelpers::FObjectFinder<UTexture2D> IconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/Twigs"));
	if (IconTemp.Succeeded())
	{
		ItemIcon = IconTemp.Object;
	}

	IsEquip = false;
}

void AGatherableTwigs::BeginPlay()
{
	Super::BeginPlay();
}

void AGatherableTwigs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGatherableTwigs::OnPickUp()
{
	Super::OnPickUp();

	//줍기 충돌완료 디버그메세지
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "GatherableTwigs");
}
