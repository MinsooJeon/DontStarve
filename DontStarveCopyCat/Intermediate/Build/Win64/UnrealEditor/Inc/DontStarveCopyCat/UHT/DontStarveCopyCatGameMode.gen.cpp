// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/DontStarveCopyCatGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDontStarveCopyCatGameMode() {}

// Begin Cross Module References
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADontStarveCopyCatGameMode();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADontStarveCopyCatGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class ADontStarveCopyCatGameMode
void ADontStarveCopyCatGameMode::StaticRegisterNativesADontStarveCopyCatGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADontStarveCopyCatGameMode);
UClass* Z_Construct_UClass_ADontStarveCopyCatGameMode_NoRegister()
{
	return ADontStarveCopyCatGameMode::StaticClass();
}
struct Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "DontStarveCopyCatGameMode.h" },
		{ "ModuleRelativePath", "DontStarveCopyCatGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADontStarveCopyCatGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::ClassParams = {
	&ADontStarveCopyCatGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADontStarveCopyCatGameMode()
{
	if (!Z_Registration_Info_UClass_ADontStarveCopyCatGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADontStarveCopyCatGameMode.OuterSingleton, Z_Construct_UClass_ADontStarveCopyCatGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADontStarveCopyCatGameMode.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<ADontStarveCopyCatGameMode>()
{
	return ADontStarveCopyCatGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADontStarveCopyCatGameMode);
ADontStarveCopyCatGameMode::~ADontStarveCopyCatGameMode() {}
// End Class ADontStarveCopyCatGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_DontStarveCopyCatGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADontStarveCopyCatGameMode, ADontStarveCopyCatGameMode::StaticClass, TEXT("ADontStarveCopyCatGameMode"), &Z_Registration_Info_UClass_ADontStarveCopyCatGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADontStarveCopyCatGameMode), 1344341554U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_DontStarveCopyCatGameMode_h_273790510(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_DontStarveCopyCatGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_DontStarveCopyCatGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
