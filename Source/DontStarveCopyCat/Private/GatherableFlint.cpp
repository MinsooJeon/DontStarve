// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableFlint.h"
#include "Components/BoxComponent.h"

AGatherableFlint::AGatherableFlint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//콜라이더 사이즈
	BoxComp->SetBoxExtent(FVector(50.f));
	//부싯돌 메시 위치 조정
	MeshComp->SetRelativeLocation(FVector(0, 0, -50.f));
	
	//부싯돌 메시 가져오기
	ConstructorHelpers::FObjectFinder<UStaticMesh> FlintTemp(TEXT("/Game/DontStarveCopyCat/Models/SM_MyFlint.SM_MyFlint"));
	if (FlintTemp.Succeeded())
	{
		MeshComp->SetStaticMesh(FlintTemp.Object);
	}
	//Flint 이름
	ItemID = TEXT("GatherableFlint");

	//부싯돌 아이콘
	ConstructorHelpers::FObjectFinder<UTexture2D> IconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/Flint"));
	if (IconTemp.Succeeded())
	{
		ItemIcon = IconTemp.Object;
	}
}

void AGatherableFlint::BeginPlay()
{
	Super::BeginPlay();
}

void AGatherableFlint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGatherableFlint::OnPickUp()
{
	Super::OnPickUp();

	//줍기 충돌완료 디버그메세지
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "GatherableFlint");
}
