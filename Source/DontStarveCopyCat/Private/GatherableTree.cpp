// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableTree.h"
#include "Components/BoxComponent.h"

// Sets default values
AGatherableTree::AGatherableTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//콜라이더 사이즈
	BoxComp->SetBoxExtent(FVector(50.f));
	//메시 위치, 사이즈
	MeshComp->SetRelativeLocation(FVector(0,0,-49.f));
	MeshComp->SetRelativeScale3D(FVector(40.f));
	//트리 위쪽 메시
	ConstructorHelpers::FObjectFinder<UStaticMesh> treeTemp(TEXT("/Script/Engine.StaticMesh'/Game/MyContent/Models/WorldStuff/Trees/TreeTop.TreeTop'"));
	if (treeTemp.Succeeded())
	{
		MeshComp->SetStaticMesh(treeTemp.Object);
	}
	
	//서브 메시 생성
	MeshCompBottom = CreateDefaultSubobject<UStaticMeshComponent>("MeshCompBottom");
	MeshCompBottom->SetupAttachment(BoxComp);
	MeshCompBottom->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshCompBottom->SetRelativeLocation(FVector(0,0,-49.f));
	MeshCompBottom->SetRelativeScale3D(FVector(40.f));
	//트리 Trunk 메시
	ConstructorHelpers::FObjectFinder<UStaticMesh> trunkTemp(TEXT("/Script/Engine.StaticMesh'/Game/DontStarveCopyCat/Models/TreeTrunk.TreeTrunk'"));
	if (trunkTemp.Succeeded())
	{
		MeshCompBottom->SetStaticMesh(trunkTemp.Object);
	}

	ItemID = TEXT("GatherableTree");

}

// Called when the game starts or when spawned
void AGatherableTree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGatherableTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGatherableTree::OnChopping()
{
	Super::OnChopping();

	//도끼질 충돌완료 디버그메세지
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "GatherableTree");
}


