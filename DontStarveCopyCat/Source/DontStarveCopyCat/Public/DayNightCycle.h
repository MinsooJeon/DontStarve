// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightCycle.generated.h"

UCLASS()
class DONTSTARVECOPYCAT_API ADayNightCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADayNightCycle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//조명 변화 함수
	UFUNCTION()
	void UpdateLighting(float CurrentTime); 
	
	//Directional Light
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameLight")
	class ADirectionalLight* SunLight;
	
	//Directional Light 초기 회전값
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameLight")
	FRotator SunInitialRotation;
	
	//ExponentialHeightFog 안개
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLight")
	class AExponentialHeightFog* Fog;

	//SkyLight
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLight")
	class ASkyLight* SkyLight;

	//PostProcess
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLight")
	class APostProcessVolume* PostProcessVolume;
	
	//게임시간
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameLight")
	float DayLength;
	
	//현재시간
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameLight")
	float CurrentTime;
	
	//밤 여부
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameLight")
	bool IsNight;
	
	//Curve 조명, 안개 밝기 농도
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Curve")
	UCurveFloat* LightIntensityCurve;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Curve")
	UCurveFloat* FogDensityCurve;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Curve")
	UCurveFloat* SkyLightIntensityCurve;

	//PostProcess Color
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Curve")
	UCurveFloat* ColorGradingCurve;
};
