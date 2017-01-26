
#pragma once

#include "OneSignalSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UOneSignalSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UOneSignalSettings(const FObjectInitializer& ObjectInitializer);
	
	// SDK Ids

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Id"))
	FString AppId;


	
};
