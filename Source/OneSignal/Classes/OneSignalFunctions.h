
#pragma once

#include "OneSignalFunctions.generated.h"



UCLASS(NotBlueprintable)
class UOneSignalFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

