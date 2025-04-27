// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DontStarveCopyCat/Public/GatherableItem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGatherableItem() {}

// Begin Cross Module References
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_AGatherableItem();
DONTSTARVECOPYCAT_API UClass* Z_Construct_UClass_AGatherableItem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_DontStarveCopyCat();
// End Cross Module References

// Begin Class AGatherableItem Function OnGather
struct Z_Construct_UFunction_AGatherableItem_OnGather_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xb1\x84\xec\xa7\x91\xed\x95\xa8\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb1\x84\xec\xa7\x91\xed\x95\xa8\xec\x88\x98" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGatherableItem_OnGather_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGatherableItem, nullptr, "OnGather", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGatherableItem_OnGather_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGatherableItem_OnGather_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGatherableItem_OnGather()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGatherableItem_OnGather_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGatherableItem::execOnGather)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGather();
	P_NATIVE_END;
}
// End Class AGatherableItem Function OnGather

// Begin Class AGatherableItem
void AGatherableItem::StaticRegisterNativesAGatherableItem()
{
	UClass* Class = AGatherableItem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnGather", &AGatherableItem::execOnGather },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGatherableItem);
UClass* Z_Construct_UClass_AGatherableItem_NoRegister()
{
	return AGatherableItem::StaticClass();
}
struct Z_Construct_UClass_AGatherableItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GatherableItem.h" },
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDestroyOnGather_MetaData[] = {
		{ "Category", "GatherableItem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xb1\x84\xec\xa7\x91\xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb1\x84\xec\xa7\x91\xec\x97\xac\xeb\xb6\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "GatherableItem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xec\x9d\xb4\xeb\xa6\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xec\x9d\xb4\xeb\xa6\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxComp_MetaData[] = {
		{ "Category", "GatherableItem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xeb\xa9\x94\xec\x89\xac\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xeb\xa9\x94\xec\x89\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[] = {
		{ "Category", "GatherableItem" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GatherableItem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bDestroyOnGather_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDestroyOnGather;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoxComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGatherableItem_OnGather, "OnGather" }, // 1097128567
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGatherableItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AGatherableItem_Statics::NewProp_bDestroyOnGather_SetBit(void* Obj)
{
	((AGatherableItem*)Obj)->bDestroyOnGather = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGatherableItem_Statics::NewProp_bDestroyOnGather = { "bDestroyOnGather", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGatherableItem), &Z_Construct_UClass_AGatherableItem_Statics::NewProp_bDestroyOnGather_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDestroyOnGather_MetaData), NewProp_bDestroyOnGather_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AGatherableItem_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGatherableItem, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGatherableItem_Statics::NewProp_BoxComp = { "BoxComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGatherableItem, BoxComp), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxComp_MetaData), NewProp_BoxComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGatherableItem_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGatherableItem, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComp_MetaData), NewProp_MeshComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGatherableItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGatherableItem_Statics::NewProp_bDestroyOnGather,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGatherableItem_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGatherableItem_Statics::NewProp_BoxComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGatherableItem_Statics::NewProp_MeshComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGatherableItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_DontStarveCopyCat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGatherableItem_Statics::ClassParams = {
	&AGatherableItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AGatherableItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGatherableItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AGatherableItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGatherableItem()
{
	if (!Z_Registration_Info_UClass_AGatherableItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGatherableItem.OuterSingleton, Z_Construct_UClass_AGatherableItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGatherableItem.OuterSingleton;
}
template<> DONTSTARVECOPYCAT_API UClass* StaticClass<AGatherableItem>()
{
	return AGatherableItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGatherableItem);
AGatherableItem::~AGatherableItem() {}
// End Class AGatherableItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableItem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGatherableItem, AGatherableItem::StaticClass, TEXT("AGatherableItem"), &Z_Registration_Info_UClass_AGatherableItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGatherableItem), 360892433U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableItem_h_422725109(TEXT("/Script/DontStarveCopyCat"),
	Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Minsoo_Documents_GitHub_DontStarve_DontStarveCopyCat_Source_DontStarveCopyCat_Public_GatherableItem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
