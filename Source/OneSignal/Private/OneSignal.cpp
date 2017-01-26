
#include "OneSignalPrivatePCH.h"
#include "OneSignalSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogOneSignal);

#define LOCTEXT_NAMESPACE "OneSignal"

class FOneSignal : public IOneSignal
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FOneSignal, OneSignal )

void FOneSignal::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "OneSignal",
										 LOCTEXT("RuntimeSettingsName", "OneSignal"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the OneSignal plugin"),
										 GetMutableDefault<UOneSignalSettings>()
										 );
	}

#if PLATFORM_ANDROID
	UOneSignalFunctions::InitJavaFunctions();
#endif
}


void FOneSignal::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
