// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/DS_Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDS_Player() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADS_Player();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_ADS_Player_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDecalComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class ADS_Player
void ADS_Player::StaticRegisterNativesADS_Player()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADS_Player);
UClass* Z_Construct_UClass_ADS_Player_NoRegister()
{
	return ADS_Player::StaticClass();
}
struct Z_Construct_UClass_ADS_Player_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "DS_Player.h" },
		{ "ModuleRelativePath", "Public/DS_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x8a\xa4\xed\x94\x84\xeb\xa7\x81\xec\x95\x94, \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x8a\xa4\xed\x94\x84\xeb\xa7\x81\xec\x95\x94, \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DS_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "Category", "DS_Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9d\xb4\xeb\x8f\x99\xeb\xb0\xa9\xed\x96\xa5\n" },
#endif
		{ "ModuleRelativePath", "Public/DS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9d\xb4\xeb\x8f\x99\xeb\xb0\xa9\xed\x96\xa5" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMC_DontStarve_MetaData[] = {
		{ "Category", "DS_PlayerInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Action\n" },
#endif
		{ "ModuleRelativePath", "Public/DS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_DS_Move_MetaData[] = {
		{ "Category", "DS_PlayerInput" },
		{ "ModuleRelativePath", "Public/DS_Player.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowDecal_MetaData[] = {
		{ "Category", "Shadow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Shadow Decal\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DS_Player.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shadow Decal" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_DontStarve;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_DS_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShadowDecal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADS_Player>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComp_MetaData), NewProp_SpringArmComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraComp_MetaData), NewProp_CameraComp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_IMC_DontStarve = { "IMC_DontStarve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, IMC_DontStarve), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMC_DontStarve_MetaData), NewProp_IMC_DontStarve_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_IA_DS_Move = { "IA_DS_Move", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, IA_DS_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_DS_Move_MetaData), NewProp_IA_DS_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADS_Player_Statics::NewProp_ShadowDecal = { "ShadowDecal", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADS_Player, ShadowDecal), Z_Construct_UClass_UDecalComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowDecal_MetaData), NewProp_ShadowDecal_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADS_Player_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_SpringArmComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_CameraComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_Direction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_IMC_DontStarve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_IA_DS_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADS_Player_Statics::NewProp_ShadowDecal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADS_Player_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADS_Player_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADS_Player_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADS_Player_Statics::ClassParams = {
	&ADS_Player::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADS_Player_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADS_Player_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADS_Player_Statics::Class_MetaDataParams), Z_Construct_UClass_ADS_Player_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADS_Player()
{
	if (!Z_Registration_Info_UClass_ADS_Player.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADS_Player.OuterSingleton, Z_Construct_UClass_ADS_Player_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADS_Player.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<ADS_Player>()
{
	return ADS_Player::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADS_Player);
ADS_Player::~ADS_Player() {}
// End Class ADS_Player

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_Player_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADS_Player, ADS_Player::StaticClass, TEXT("ADS_Player"), &Z_Registration_Info_UClass_ADS_Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADS_Player), 1975660759U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_Player_h_2911786198(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_DS_Player_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
