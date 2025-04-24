// Fill out your copyright notice in the Description page of Project Settings.


#include "DayNightCycle.h"

#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/ExponentialHeightFog.h"

// Sets default values
ADayNightCycle::ADayNightCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADayNightCycle::BeginPlay()
{
	Super::BeginPlay();
	
	DayLength = 120.f; //하루 120초
	CurrentTime = 0.0f;

	if (SunLight)
	{
		SunInitialRotation = SunLight->GetActorRotation(); //Directional Light 시작 회전값
	}
	
}

// Called every frame
void ADayNightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재시간을 누적해서 하루 시간으로 나눠서 구분
	CurrentTime += DeltaTime / DayLength; 

	//하루 지난면 현재시간 초기화
	if (CurrentTime > 1.f)
	{
		CurrentTime = 0.f;
	}

	//Directional Light 회전값 계산
	FRotator NewSunRotation = SunInitialRotation;
	NewSunRotation.Pitch += CurrentTime * 360.f;
	SunLight->SetActorRotation(NewSunRotation);
	//
	// float LightIntensity = 1.f;
	// float FogDensity = 0.02f;
	//
	// if (LightIntensityCurve)
	// {
	// 	LightIntensity = LightIntensityCurve->GetFloatValue(CurrentTime);
	// }
	// if (FogDensityCurve)
	// {
	// 	FogDensity = FogDensityCurve->GetFloatValue(CurrentTime);
	// }

	// if (SunLight)
	// {
	// 	SunLight->SetBrightness(LightIntensity * 100.f);
	//
	// 	if (LightIntensity <= 0.01f)
	// 	{
	// 		//SunLight-> // 완전히 꺼버림
	// 	}
	// 	else
	// 	{
	// 		//SunLight->SetVisibility(true);
	// 	}
	// }
	// if (Fog)
	// {
	// 	Fog->GetComponent()->SetFogDensity(FogDensity);
	// }
	
}

