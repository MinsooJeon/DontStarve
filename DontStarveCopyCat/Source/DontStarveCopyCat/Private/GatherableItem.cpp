// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableItem.h"

#include "Components/BoxComponent.h"

// Sets default values
AGatherableItem::AGatherableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	BoxComp->SetBoxExtent(FVector(50.f));
	BoxComp->SetCollisionProfileName(TEXT("Gatherable"));
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(BoxComp);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//MeshComp->SetRelativeLocation(FVector(40.f, -10, -60.f));
	
	
	// ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Game/DontStarveCopyCat/Models/SM_MyBush.SM_MyBush"));
	// if (tempMesh.Succeeded())
	// {
	// 	MeshComp->SetStaticMesh(tempMesh.Object);
	// }
	
}

// Called when the game starts or when spawned
void AGatherableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGatherableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGatherableItem::OnGather()
{
	bDestroyOnGather = true;

	//채집 완료 여부
	if (bDestroyOnGather)
	{
		this->Destroy();
	}
}

