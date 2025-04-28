// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/DS_PlayerAnim.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDS_PlayerAnim() {}

// Begin Cross Module References
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_UDS_PlayerAnim();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_UDS_PlayerAnim_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class UDS_PlayerAnim
void UDS_PlayerAnim::StaticRegisterNativesUDS_PlayerAnim()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDS_PlayerAnim);
UClass* Z_Construct_UClass_UDS_PlayerAnim_NoRegister()
{
	return UDS_PlayerAnim::StaticClass();
}
struct Z_Construct_UClass_UDS_PlayerAnim_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "DS_PlayerAnim.h" },
		{ "ModuleRelativePath", "Public/DS_PlayerAnim.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerMove_MetaData[] = {
		{ "Category", "DS_PlayerAnim" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\x9b\x80\xec\xa7\x81\xec\x9e\x84 \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/DS_PlayerAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x80\xec\xa7\x81\xec\x9e\x84 \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerGatherBush_MetaData[] = {
		{ "Category", "DS_PlayerAnim" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Bush \xec\xb1\x84\xec\xa7\x91 \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/DS_PlayerAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bush \xec\xb1\x84\xec\xa7\x91 \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bPlayerMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerMove;
	static void NewProp_bPlayerGatherBush_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerGatherBush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDS_PlayerAnim>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerMove_SetBit(void* Obj)
{
	((UDS_PlayerAnim*)Obj)->bPlayerMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerMove = { "bPlayerMove", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDS_PlayerAnim), &Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayerMove_MetaData), NewProp_bPlayerMove_MetaData) };
void Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerGatherBush_SetBit(void* Obj)
{
	((UDS_PlayerAnim*)Obj)->bPlayerGatherBush = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerGatherBush = { "bPlayerGatherBush", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDS_PlayerAnim), &Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerGatherBush_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayerGatherBush_MetaData), NewProp_bPlayerGatherBush_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDS_PlayerAnim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDS_PlayerAnim_Statics::NewProp_bPlayerGatherBush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnim_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDS_PlayerAnim_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnim_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDS_PlayerAnim_Statics::ClassParams = {
	&UDS_PlayerAnim::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDS_PlayerAnim_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnim_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDS_PlayerAnim_Statics::Class_MetaDataParams), Z_Construct_UClass_UDS_PlayerAnim_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDS_PlayerAnim()
{
	if (!Z_Registration_Info_UClass_UDS_PlayerAnim.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDS_PlayerAnim.OuterSingleton, Z_Construct_UClass_UDS_PlayerAnim_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDS_PlayerAnim.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<UDS_PlayerAnim>()
{
	return UDS_PlayerAnim::StaticClass();
}
UDS_PlayerAnim::UDS_PlayerAnim(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDS_PlayerAnim);
UDS_PlayerAnim::~UDS_PlayerAnim() {}
// End Class UDS_PlayerAnim

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnim_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDS_PlayerAnim, UDS_PlayerAnim::StaticClass, TEXT("UDS_PlayerAnim"), &Z_Registration_Info_UClass_UDS_PlayerAnim, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDS_PlayerAnim), 3653830621U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnim_h_1015408000(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnim_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_PlayerAnim_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
