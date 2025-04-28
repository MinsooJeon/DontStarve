// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/DS_PlayerAnimNotify.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDS_PlayerAnimNotify() {}

// Begin Cross Module References
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_UDS_PlayerAnimNotify();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_UDS_PlayerAnimNotify_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class UDS_PlayerAnimNotify
void UDS_PlayerAnimNotify::StaticRegisterNativesUDS_PlayerAnimNotify()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDS_PlayerAnimNotify);
UClass* Z_Construct_UClass_UDS_PlayerAnimNotify_NoRegister()
{
	return UDS_PlayerAnimNotify::StaticClass();
}
struct Z_Construct_UClass_UDS_PlayerAnimNotify_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "DS_PlayerAnimNotify.h" },
		{ "ModuleRelativePath", "Public/DS_PlayerAnimNotify.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDS_PlayerAnimNotify>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimNotify,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::ClassParams = {
	&UDS_PlayerAnimNotify::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001120A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::Class_MetaDataParams), Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDS_PlayerAnimNotify()
{
	if (!Z_Registration_Info_UClass_UDS_PlayerAnimNotify.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDS_PlayerAnimNotify.OuterSingleton, Z_Construct_UClass_UDS_PlayerAnimNotify_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDS_PlayerAnimNotify.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<UDS_PlayerAnimNotify>()
{
	return UDS_PlayerAnimNotify::StaticClass();
}
UDS_PlayerAnimNotify::UDS_PlayerAnimNotify(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDS_PlayerAnimNotify);
UDS_PlayerAnimNotify::~UDS_PlayerAnimNotify() {}
// End Class UDS_PlayerAnimNotify

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnimNotify_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDS_PlayerAnimNotify, UDS_PlayerAnimNotify::StaticClass, TEXT("UDS_PlayerAnimNotify"), &Z_Registration_Info_UClass_UDS_PlayerAnimNotify, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDS_PlayerAnimNotify), 361989194U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnimNotify_h_3918994232(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnimNotify_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnimNotify_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
