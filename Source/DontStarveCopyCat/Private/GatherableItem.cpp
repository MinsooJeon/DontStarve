// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableItem.h"
#include "Components/BoxComponent.h"

// Sets default values
AGatherableItem::AGatherableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//기본 콜라이더 생성. 콜라이더 이름 Gatherable
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	//BoxComp->SetBoxExtent(FVector(50.f));
	BoxComp->SetCollisionProfileName(TEXT("Gatherable"));
	//기본 메시 생성
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(BoxComp);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//MeshComp->SetRelativeLocation(FVector(40.f, -10, -60.f));
	
	
	// ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Game/DontStarveCopyCat/Models/SM_MyBush.SM_MyBush"));
	// if (tempMesh.Succeeded())
	// {
	// 	MeshComp->SetStaticMesh(tempMesh.Object);
	// }

	// //외곽선 전용
	// OutlineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OutlineMesh"));
	// OutlineMesh->SetupAttachment(MeshComp);
	// //MeshComp보다 살짝 크게 키움
	// OutlineMesh->SetRelativeScale3D(FVector(1.05f));
	// //검은색 머터리얼 사용
	// OutlineMesh->SetMaterial(0, BlackMaterial);
	// //항상 MeshComp보다 뒤에 그려지게 설정
	// OutlineMesh->SetRenderCustomDepth(true);
	// OutlineMesh->CustomDepthStencilValue = 1;
	// OutlineMesh->SetCastShadow(false);
	// OutlineMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

void AGatherableItem::OnChopping()
{
	bOnChopping = true;

	//도끼질 완료 여부
	if (bOnChopping)
	{
		this->Destroy();
	}
}

void AGatherableItem::OnPickUp()
{
	bOnPickUp = true;

	//줍기 완료 여부
	if (bOnPickUp)
	{
		this->Destroy();
	}
}

