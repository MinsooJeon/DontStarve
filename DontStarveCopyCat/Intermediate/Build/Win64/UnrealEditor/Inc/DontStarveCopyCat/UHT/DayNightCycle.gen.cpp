// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/DayNightCycle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDayNightCycle() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADayNightCycle();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADayNightCycle_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_ADirectionalLight_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AExponentialHeightFog_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class ADayNightCycle
void ADayNightCycle::StaticRegisterNativesADayNightCycle()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADayNightCycle);
UClass* Z_Construct_UClass_ADayNightCycle_NoRegister()
{
	return ADayNightCycle::StaticClass();
}
struct Z_Construct_UClass_ADayNightCycle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DayNightCycle.h" },
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DayLength_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xea\xb2\x8c\xec\x9e\x84\xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84\xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTime_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xed\x98\x84\xec\x9e\xac\xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac\xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunLight_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Directional Light\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Directional Light" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SunInitialRotation_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Directional Light \xec\xb4\x88\xea\xb8\xb0 \xed\x9a\x8c\xec\xa0\x84\xea\xb0\x92\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Directional Light \xec\xb4\x88\xea\xb8\xb0 \xed\x9a\x8c\xec\xa0\x84\xea\xb0\x92" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsNight_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xeb\xb0\xa4 \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\xa4 \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fog_MetaData[] = {
		{ "Category", "GameDirectionalLight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//ExponentialHeightFog \xec\x95\x88\xea\xb0\x9c\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ExponentialHeightFog \xec\x95\x88\xea\xb0\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightIntensityCurve_MetaData[] = {
		{ "Category", "Curve" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xa1\xb0\xeb\xaa\x85, \xec\x95\x88\xea\xb0\x9c \xeb\xb0\x9d\xea\xb8\xb0 \xeb\x86\x8d\xeb\x8f\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa1\xb0\xeb\xaa\x85, \xec\x95\x88\xea\xb0\x9c \xeb\xb0\x9d\xea\xb8\xb0 \xeb\x86\x8d\xeb\x8f\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FogDensityCurve_MetaData[] = {
		{ "Category", "Curve" },
		{ "ModuleRelativePath", "Public/DayNightCycle.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DayLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SunLight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SunInitialRotation;
	static void NewProp_IsNight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsNight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Fog;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LightIntensityCurve;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FogDensityCurve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADayNightCycle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_DayLength = { "DayLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, DayLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DayLength_MetaData), NewProp_DayLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, CurrentTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTime_MetaData), NewProp_CurrentTime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_SunLight = { "SunLight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, SunLight), Z_Construct_UClass_ADirectionalLight_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunLight_MetaData), NewProp_SunLight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_SunInitialRotation = { "SunInitialRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, SunInitialRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SunInitialRotation_MetaData), NewProp_SunInitialRotation_MetaData) };
void Z_Construct_UClass_ADayNightCycle_Statics::NewProp_IsNight_SetBit(void* Obj)
{
	((ADayNightCycle*)Obj)->IsNight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_IsNight = { "IsNight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADayNightCycle), &Z_Construct_UClass_ADayNightCycle_Statics::NewProp_IsNight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsNight_MetaData), NewProp_IsNight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_Fog = { "Fog", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, Fog), Z_Construct_UClass_AExponentialHeightFog_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fog_MetaData), NewProp_Fog_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_LightIntensityCurve = { "LightIntensityCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, LightIntensityCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightIntensityCurve_MetaData), NewProp_LightIntensityCurve_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADayNightCycle_Statics::NewProp_FogDensityCurve = { "FogDensityCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADayNightCycle, FogDensityCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FogDensityCurve_MetaData), NewProp_FogDensityCurve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADayNightCycle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_DayLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_CurrentTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_SunLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_SunInitialRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_IsNight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_Fog,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_LightIntensityCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADayNightCycle_Statics::NewProp_FogDensityCurve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADayNightCycle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADayNightCycle_Statics::ClassParams = {
	&ADayNightCycle::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADayNightCycle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADayNightCycle_Statics::Class_MetaDataParams), Z_Construct_UClass_ADayNightCycle_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADayNightCycle()
{
	if (!Z_Registration_Info_UClass_ADayNightCycle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADayNightCycle.OuterSingleton, Z_Construct_UClass_ADayNightCycle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADayNightCycle.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<ADayNightCycle>()
{
	return ADayNightCycle::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADayNightCycle);
ADayNightCycle::~ADayNightCycle() {}
// End Class ADayNightCycle

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DayNightCycle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADayNightCycle, ADayNightCycle::StaticClass, TEXT("ADayNightCycle"), &Z_Registration_Info_UClass_ADayNightCycle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADayNightCycle), 3883819239U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DayNightCycle_h_3561937424(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DayNightCycle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DayNightCycle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
