
#include "OneSignalPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;


void UOneSignalFunctions::InitJavaFunctions()
{
	
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOneSignalNotificationReceived(String CustomKeyValue);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOneSignalNotificationReceived(JNIEnv* jenv, jobject thiz, jstring CustomKeyValue)
{
	FString KeyValue;

	const char* charsKeyValue = jenv->GetStringUTFChars(CustomKeyValue, 0);
	KeyValue = FString(UTF8_TO_TCHAR(charsKeyValue));
	jenv->ReleaseStringUTFChars(CustomKeyValue, charsKeyValue);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UOneSignalComponent::OneSignalNotificationReceivedDelegate.Broadcast(KeyValue);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOneSignalIdsAvailable(String UserId, String RegistrationId );"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOneSignalIdsAvailable(JNIEnv* jenv, jobject thiz, jstring UserId)//, jstring RegistrationId
{
	FString UserID;
	FString RegistrationID;

	const char* charsUserID = jenv->GetStringUTFChars(UserId, 0);
	UserID = FString(UTF8_TO_TCHAR(charsUserID));
	jenv->ReleaseStringUTFChars(UserId, charsUserID);

	//const char* charsRegistrationID = jenv->GetStringUTFChars(RegistrationId, 0);
	//RegistrationID = FString(UTF8_TO_TCHAR(charsRegistrationID));
	//jenv->ReleaseStringUTFChars(RegistrationId, charsRegistrationID);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		//UOneSignalComponent::OneSignalIdsAvailableDelegate.Broadcast(UserID);//, RegistrationID
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


#endif

