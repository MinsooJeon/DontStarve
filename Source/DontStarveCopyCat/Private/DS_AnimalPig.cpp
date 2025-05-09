// Fill out your copyright notice in the Description page of Project Settings.


#include "DS_AnimalPig.h"

#include "DS_AnimalPigFSMComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADS_AnimalPig::ADS_AnimalPig()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Pig 모델 생성
	ConstructorHelpers::FObjectFinder<USkeletalMesh> PigMeshTemp(TEXT("/Game/DontStarveCopyCat/Models/pig"));
	if (PigMeshTemp.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(PigMeshTemp.Object);
		GetMesh()->SetRelativeScale3D(FVector(0.5f));
		GetMesh()->SetRelativeLocationAndRotation(FVector(0,0,-90.f), FRotator(0,-90.f,0));
		GetMesh()->CastShadow = false;
		GetCharacterMovement()->MaxWalkSpeed =  200.f;
	}

	AnimalPigFSM = CreateDefaultSubobject<UDS_AnimalPigFSMComponent>(TEXT("AnimalPigFSM"));

	//Shadow Decal
	ShadowDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("ShadowDecal"));
	ShadowDecal->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UMaterialInstance> ShadowMat(TEXT("/Game/DontStarveCopyCat/Materials/M_ShadowDecal"));
	if (ShadowMat.Succeeded())
	{
		ShadowDecal->SetDecalMaterial(ShadowMat.Object);
	}
	
	ShadowDecal->DecalSize = FVector(64.f, 150.f, 64.f);
	ShadowDecal->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	ShadowDecal->SetRelativeRotation(FRotator(90.f, 0.f, 90.f));
	
}

// Called when the game starts or when spawned
void ADS_AnimalPig::BeginPlay()
{
	Super::BeginPlay();

	//초기 시작을 화면을 바라보는 방향에서 시작
	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += 180.f;
	SetActorRotation(newRotation);
	
}

// Called every frame
void ADS_AnimalPig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADS_AnimalPig::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

