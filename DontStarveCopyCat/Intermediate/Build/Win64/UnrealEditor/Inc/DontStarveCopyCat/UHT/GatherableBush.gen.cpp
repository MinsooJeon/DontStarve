// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/GatherableBush.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGatherableBush() {}

// Begin Cross Module References
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_AGatherableBush();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_AGatherableBush_NoRegister();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_AGatherableItem();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class AGatherableBush
void AGatherableBush::StaticRegisterNativesAGatherableBush()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGatherableBush);
UClass* Z_Construct_UClass_AGatherableBush_NoRegister()
{
	return AGatherableBush::StaticClass();
}
struct Z_Construct_UClass_AGatherableBush_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GatherableBush.h" },
		{ "ModuleRelativePath", "Public/GatherableBush.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGatherableBush>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGatherableBush_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGatherableItem,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableBush_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGatherableBush_Statics::ClassParams = {
	&AGatherableBush::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableBush_Statics::Class_MetaDataParams), Z_Construct_UClass_AGatherableBush_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGatherableBush()
{
	if (!Z_Registration_Info_UClass_AGatherableBush.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGatherableBush.OuterSingleton, Z_Construct_UClass_AGatherableBush_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGatherableBush.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<AGatherableBush>()
{
	return AGatherableBush::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGatherableBush);
AGatherableBush::~AGatherableBush() {}
// End Class AGatherableBush

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableBush_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGatherableBush, AGatherableBush::StaticClass, TEXT("AGatherableBush"), &Z_Registration_Info_UClass_AGatherableBush, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGatherableBush), 2292222298U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableBush_h_123882844(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableBush_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableBush_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
