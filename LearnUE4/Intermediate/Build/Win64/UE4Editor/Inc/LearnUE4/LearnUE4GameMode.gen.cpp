// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LearnUE4/LearnUE4GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLearnUE4GameMode() {}
// Cross Module References
	LEARNUE4_API UClass* Z_Construct_UClass_ALearnUE4GameMode_NoRegister();
	LEARNUE4_API UClass* Z_Construct_UClass_ALearnUE4GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LearnUE4();
// End Cross Module References
	void ALearnUE4GameMode::StaticRegisterNativesALearnUE4GameMode()
	{
	}
	UClass* Z_Construct_UClass_ALearnUE4GameMode_NoRegister()
	{
		return ALearnUE4GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ALearnUE4GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALearnUE4GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LearnUE4,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALearnUE4GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LearnUE4GameMode.h" },
		{ "ModuleRelativePath", "LearnUE4GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALearnUE4GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALearnUE4GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALearnUE4GameMode_Statics::ClassParams = {
		&ALearnUE4GameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ALearnUE4GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALearnUE4GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALearnUE4GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALearnUE4GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALearnUE4GameMode, 2511961295);
	template<> LEARNUE4_API UClass* StaticClass<ALearnUE4GameMode>()
	{
		return ALearnUE4GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALearnUE4GameMode(Z_Construct_UClass_ALearnUE4GameMode, &ALearnUE4GameMode::StaticClass, TEXT("/Script/LearnUE4"), TEXT("ALearnUE4GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALearnUE4GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
