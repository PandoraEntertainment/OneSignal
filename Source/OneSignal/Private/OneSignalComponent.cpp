
#include "OneSignalPrivatePCH.h"

void UOneSignalComponent::OnRegister()
{
	Super::OnRegister();
	

	UOneSignalComponent::OneSignalNotificationReceivedDelegate.AddUObject(this, &UOneSignalComponent::OneSignalNotificationReceived_Handler);

	UOneSignalComponent::OneSignalIdsAvailableDelegate.AddUObject(this, &UOneSignalComponent::OneSignalIdsAvailable_Handler);

}

void UOneSignalComponent::OnUnregister()
{
	Super::OnUnregister();
	

	UOneSignalComponent::OneSignalNotificationReceivedDelegate.RemoveAll(this);

	UOneSignalComponent::OneSignalIdsAvailableDelegate.RemoveAll(this);
}

UOneSignalComponent::FOneSignalNotificationReceivedDelegate UOneSignalComponent::OneSignalNotificationReceivedDelegate;

UOneSignalComponent::FOneSignalIdsAvailableDelegate UOneSignalComponent::OneSignalIdsAvailableDelegate;
