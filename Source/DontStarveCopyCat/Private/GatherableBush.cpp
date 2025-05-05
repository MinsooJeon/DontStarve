// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableBush.h"
#include "Components/BoxComponent.h"

// Sets default values
AGatherableBush::AGatherableBush()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//콜라이더 박스크기
	BoxComp->SetBoxExtent(FVector(50.f));
	//메시 위치
	MeshComp->SetRelativeLocation(FVector(40.f, -10, -60.f));
	//수풀 메시 가져오기
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Game/DontStarveCopyCat/Models/SM_MyBush.SM_MyBush"));
	if (tempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(tempMesh.Object);
		//OutlineMesh->SetStaticMesh(tempMesh.Object);
	}
	//수풀 메시 이름
	ItemID = TEXT("GatherableBush");

	//수풀 아이콘
	ConstructorHelpers::FObjectFinder<UTexture2D> IconTemp(TEXT("/Game/DontStarveCopyCat/UI/Images/Cut_Grass"));
	if (IconTemp.Succeeded())
	{
		ItemIcon = IconTemp.Object;
	}
}

// Called when the game starts or when spawned
void AGatherableBush::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGatherableBush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGatherableBush::OnGather()
{
	Super::OnGather();

	//채집 충돌완료 디버그메세지
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "GatherableBush");
}

