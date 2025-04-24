// Fill out your copyright notice in the Description page of Project Settings.


#include "DayNightCycle.h"

#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/SkyLightComponent.h"
#include "Engine/DirectionalLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/SkyLight.h"
#include "Kismet/KismetSystemLibrary.h"

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
	
	DayLength = 20.f; //하루 300초
	CurrentTime = 0.f;

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

	//조명 업데이트
	UpdateLighting(CurrentTime);
}

void ADayNightCycle::UpdateLighting(float CurTime)
{
	//Directional Light 회전값 계산
	FRotator NewSunRotation = SunInitialRotation;
	NewSunRotation.Pitch += CurTime * 360.f; //Y축
	NewSunRotation.Yaw = -45.f; //Z축
	NewSunRotation.Roll = 0.f; //X축
	SunLight->SetActorRotation(NewSunRotation);
	
	float LightIntensity = 1.f;
	float FogDensity = 0.02f;
	
	if (LightIntensityCurve)
	{
		LightIntensity = LightIntensityCurve->GetFloatValue(CurTime);
	}
	if (SunLight)
	{
		//조명 농도
		SunLight->GetLightComponent()->SetIntensity(LightIntensity * 6.f);
		
		if (LightIntensity <= 0.01f)
		{
			SunLight->GetLightComponent()->SetVisibility(false);// 완전히 꺼버림
		}
		else
		{
			SunLight->GetLightComponent()->SetVisibility(true);
		}
	}

	//안개 농도
	if (FogDensityCurve)
	{
		FogDensity = FogDensityCurve->GetFloatValue(CurTime);
	}
	if (Fog)
	{
		Fog->GetComponent()->SetFogDensity(FogDensity);
		
	}

	//SkyLight
	if (SkyLight)
	{
		float SkyLightIntensity = SkyLightIntensityCurve->GetFloatValue(CurTime);
		SkyLight->GetLightComponent()->SetIntensity(SkyLightIntensity);
		SkyLight->GetLightComponent()->MarkRenderStateDirty();
	}
	
	//PostProcessVolume 채도 변화
	if (PostProcessVolume)
	{
		float Saturation = ColorGradingCurve->GetFloatValue(CurTime);
		FPostProcessSettings& Settings = PostProcessVolume->Settings;

		Settings.ColorSaturation = FVector4(Saturation, Saturation, Saturation, 1.f);
	}
}

