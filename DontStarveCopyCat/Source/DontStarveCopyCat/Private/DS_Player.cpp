// Fill out your copyright notice in the Description page of Project Settings.


#include "DontStarveCopyCat/Public/DS_Player.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ADS_Player::ADS_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	//카메라 암 절대회전 
	SpringArmComp->SetUsingAbsoluteRotation(true);
	//위에서 아래로 바라보기
	SpringArmComp->SetWorldRotation(FRotator(-50.f, 0, 0));
	//카메라 암 길이
	SpringArmComp->TargetArmLength = 1400.f;
	//카메라 클리핑 해제
	SpringArmComp->bDoCollisionTest = false;
	//카메라 Lag 활성화(지연을 통한 자연스러운 이동) 속도 3
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 3.f;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	//카메라 FOV 55 설정
	CameraComp->SetFieldOfView(55.f);
}

// Called when the game starts or when spawned
void ADS_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

