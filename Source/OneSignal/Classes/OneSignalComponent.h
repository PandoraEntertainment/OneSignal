
#pragma once

#include "OneSignalFunctions.h"
#include "OneSignalComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UOneSignalComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalNotificationReceivedDelegate, FString);

	static FOneSignalNotificationReceivedDelegate OneSignalNotificationReceivedDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalNotificationReceivedDynDelegate, FString, KeyValue);

	UPROPERTY(BlueprintAssignable)
	FOneSignalNotificationReceivedDynDelegate OneSignalNotificationReceived;

	DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalIdsAvailableDelegate, FString);

	static FOneSignalIdsAvailableDelegate OneSignalIdsAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalIdsAvailableDynDelegate, FString, UserID);

	UPROPERTY(BlueprintAssignable)
	FOneSignalIdsAvailableDynDelegate OneSignalIdsAvailable;


	/*
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOneSignalIdsAvailableDelegate, FString, FString);

	static FOneSignalIdsAvailableDelegate OneSignalIdsAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOneSignalIdsAvailableDynDelegate, FString, UserID, FString , RegistrationID);

	UPROPERTY(BlueprintAssignable)
    FOneSignalIdsAvailableDynDelegate OneSignalIdsAvailable;
	*/


	void OnRegister() override;
	void OnUnregister() override;
	
private:	
	

	void OneSignalNotificationReceived_Handler(FString KeyValue) { OneSignalNotificationReceived.Broadcast(KeyValue); }
	void OneSignalIdsAvailable_Handler(FString UserID) { OneSignalIdsAvailable.Broadcast(UserID); }
	//void OneSignalIdsAvailable_Handler(FString UserID, FString RegistrationID) { OneSignalIdsAvailable.Broadcast(UserID, RegistrationID); }

	
	

};
