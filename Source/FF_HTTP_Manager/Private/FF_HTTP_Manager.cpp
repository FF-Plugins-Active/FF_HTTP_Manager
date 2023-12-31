// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_Manager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFF_HTTP_ManagerModule"

void FFF_HTTP_ManagerModule::StartupModule()
{
#if defined(_WIN64) && LIBHV_SHARED == 1

	const FString BasePluginDir = IPluginManager::Get().FindPlugin("FF_HTTP_Manager")->GetBaseDir();
	const FString DLL_Path = FPaths::Combine(*BasePluginDir, TEXT("Source/LibHv/Win64/lib/hv.dll"));
	Libhv_Handle = FPlatformProcess::GetDllHandle(*DLL_Path);

	if (Libhv_Handle != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("hv.dll loaded successfully."));
	}

	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("hv.dll failed to load !"));
	}

#endif
}

void FFF_HTTP_ManagerModule::ShutdownModule()
{
#if defined(_WIN64) && LIBHV_SHARED == 1
	FPlatformProcess::FreeDllHandle(Libhv_Handle);
	Libhv_Handle = nullptr;
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFF_HTTP_ManagerModule, FF_HTTP_Manager)