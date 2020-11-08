// CVI wrapper source file for .NET assembly: SwabianInstruments.TimeTagger, Version=2.6.8.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7

#include "SwabNet.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "SwabianInstruments.TimeTagger, Version=2.6.8.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static int CVIFUNC SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
	SwabianInstruments_TimeTagger_CoincidenceTimestamp * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_State__Create(
	SwabianInstruments_TimeTagger_State * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);
static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...);

// Global Functions
int CVIFUNC Initialize_SwabianInstruments_TimeTagger(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_SwabianInstruments_TimeTagger(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.AverageChannel
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel__Create(
	SwabianInstruments_TimeTagger_AverageChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTagger tagger,
	int input_channel,
	int * combined_channels,
	ssize_t __combined_channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle combined_channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTagger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: input_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &input_channel;

	// Pre-process parameter: combined_channels
	if (combined_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__combined_channelsLength, 
			combined_channels, 
			&combined_channels__));
	__parameterTypeNames[2] = "System.Int32[]";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[2] = &combined_channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (combined_channels__)
		CDotNetDiscardHandle(combined_channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_getChannel(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_Dispose(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_start(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_startFor(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_startFor_1(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_stop(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_clear(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_isRunning(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.AverageChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Coincidence
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle channels__ = 0;
	CDotNetHandle timestamp__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &coincidenceWindow;

	// Pre-process parameter: timestamp
	__errChk(SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
		&timestamp, 
		&timestamp__, 
		__exception));
	__parameterTypeNames[3] = "SwabianInstruments.TimeTagger.CoincidenceTimestamp";
	__parameterTypes[3] = (CDOTNET_ENUM);
	__parameters[3] = &timestamp__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	if (timestamp__)
		CDotNetDiscardHandle(timestamp__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create_1(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &coincidenceWindow;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create_2(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getChannel(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_setCoincidenceWindow(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &coincidenceWindow;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setCoincidenceWindow", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getChannels(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannels", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_Dispose(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_start(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_startFor(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_startFor_1(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_stop(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_clear(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_isRunning(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getCaptureDuration(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Coincidences
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences__Create(
	SwabianInstruments_TimeTagger_Coincidences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle timestamp__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: coincidenceGroups
	__parameterTypeNames[1] = "System.Int32[][]";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &coincidenceGroups;

	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &coincidenceWindow;

	// Pre-process parameter: timestamp
	__errChk(SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
		&timestamp, 
		&timestamp__, 
		__exception));
	__parameterTypeNames[3] = "SwabianInstruments.TimeTagger.CoincidenceTimestamp";
	__parameterTypes[3] = (CDOTNET_ENUM);
	__parameters[3] = &timestamp__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (timestamp__)
		CDotNetDiscardHandle(timestamp__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences__Create_1(
	SwabianInstruments_TimeTagger_Coincidences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: coincidenceGroups
	__parameterTypeNames[1] = "System.Int32[][]";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &coincidenceGroups;

	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &coincidenceWindow;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_setCoincidenceWindow(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &coincidenceWindow;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setCoincidenceWindow", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_getChannels(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannels", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_Dispose(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_start(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_startFor(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_startFor_1(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_stop(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_clear(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_isRunning(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_getCaptureDuration(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Combiner
int CVIFUNC SwabianInstruments_TimeTagger_Combiner__Create(
	SwabianInstruments_TimeTagger_Combiner * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getChannel(
	SwabianInstruments_TimeTagger_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getData(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_Dispose(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_start(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_startFor(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_startFor_1(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_stop(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_clear(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_isRunning(
	SwabianInstruments_TimeTagger_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getCaptureDuration(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.ConstantFractionDiscriminator
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator__Create(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 search_window,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Pre-process parameter: search_window
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &search_window;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_getChannels(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannels", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_Dispose(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_start(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_startFor(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_startFor_1(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_stop(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_clear(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_isRunning(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_getCaptureDuration(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Correlation
int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channel_1
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &channel_1;

	// Pre-process parameter: channel_2
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &channel_2;

	// Pre-process parameter: binwidth
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_1(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channel_1
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &channel_1;

	// Pre-process parameter: channel_2
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &channel_2;

	// Pre-process parameter: binwidth
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_2(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channel_1
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &channel_1;

	// Pre-process parameter: channel_2
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &channel_2;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_3(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channel_1
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &channel_1;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getData(
	SwabianInstruments_TimeTagger_Correlation __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getDataNormalized(
	SwabianInstruments_TimeTagger_Correlation __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataNormalized", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getIndex(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_Dispose(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_start(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_startFor(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_startFor_1(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_stop(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_clear(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_isRunning(
	SwabianInstruments_TimeTagger_Correlation __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getCaptureDuration(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.CountBetweenMarkers
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	int n_values,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: begin_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &begin_channel;

	// Pre-process parameter: end_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &end_channel;

	// Pre-process parameter: n_values
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &n_values;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create_1(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: begin_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &begin_channel;

	// Pre-process parameter: end_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &end_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create_2(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: begin_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &begin_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_ready(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getData(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getBinWidths(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getBinWidths", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getIndex(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_Dispose(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_start(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_startFor(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_startFor_1(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_stop(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_clear(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_isRunning(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getCaptureDuration(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Counter
int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	int n_values,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Pre-process parameter: binwidth
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &binwidth;

	// Pre-process parameter: n_values
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &n_values;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create_1(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Pre-process parameter: binwidth
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create_2(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_getData(
	SwabianInstruments_TimeTagger_Counter __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_getIndex(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_Dispose(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_start(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_startFor(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_startFor_1(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_stop(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_clear(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_isRunning(
	SwabianInstruments_TimeTagger_Counter __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Counter_getCaptureDuration(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Countrate
int CVIFUNC SwabianInstruments_TimeTagger_Countrate__Create(
	SwabianInstruments_TimeTagger_Countrate * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getData(
	SwabianInstruments_TimeTagger_Countrate __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getCountsTotal(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCountsTotal", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_Dispose(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_start(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_startFor(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_startFor_1(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_stop(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_clear(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_isRunning(
	SwabianInstruments_TimeTagger_Countrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getCaptureDuration(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_register_channel(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"register_channel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_unregister_channel(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"unregister_channel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_finalize_init(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"finalize_init", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_is_running(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"is_running", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase__lock(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"_lock", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase__unlock(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"_unlock", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_Dispose(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_start(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_startFor(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_startFor_1(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_stop(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_clear(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_isRunning(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_getCaptureDuration(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.DelayedChannel
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel__Create(
	SwabianInstruments_TimeTagger_DelayedChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	__int64 delay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: input_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &input_channel;

	// Pre-process parameter: delay
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &delay;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_getChannel(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_setDelay(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 delay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: delay
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &delay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_Dispose(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_start(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_startFor(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_startFor_1(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_stop(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_clear(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_isRunning(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Dump
int CVIFUNC SwabianInstruments_TimeTagger_Dump__Create(
	SwabianInstruments_TimeTagger_Dump * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: filename
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &filename;

	// Pre-process parameter: max_tags
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &max_tags;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[3] = "System.Int32[]";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[3] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump__Create_1(
	SwabianInstruments_TimeTagger_Dump * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: filename
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &filename;

	// Pre-process parameter: max_tags
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &max_tags;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_Dispose(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_start(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_startFor(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_startFor_1(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_stop(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_clear(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_isRunning(
	SwabianInstruments_TimeTagger_Dump __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Dump_getCaptureDuration(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Event
int CVIFUNC SwabianInstruments_TimeTagger_Event__Create(
	SwabianInstruments_TimeTagger_Event * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Event_Get_time(
	SwabianInstruments_TimeTagger_Event __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"time", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Event_Set_time(
	SwabianInstruments_TimeTagger_Event __instance,
	__int64 value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"time", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Event_Get_state(
	SwabianInstruments_TimeTagger_Event __instance,
	SwabianInstruments_TimeTagger_State * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"state", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Event_Set_state(
	SwabianInstruments_TimeTagger_Event __instance,
	SwabianInstruments_TimeTagger_State value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(SwabianInstruments_TimeTagger_State__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.State";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"state", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Event_Dispose(
	SwabianInstruments_TimeTagger_Event __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Event", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.EventGenerator
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	unsigned __int64 divider_offset,
	int stop_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle pattern__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &trigger_channel;

	// Pre-process parameter: pattern
	if (pattern)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__patternLength, 
			pattern, 
			&pattern__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pattern__;

	// Pre-process parameter: trigger_divider
	__parameterTypeNames[3] = "System.UInt64";
	__parameterTypes[3] = (CDOTNET_UINT64);
	__parameters[3] = &trigger_divider;

	// Pre-process parameter: divider_offset
	__parameterTypeNames[4] = "System.UInt64";
	__parameterTypes[4] = (CDOTNET_UINT64);
	__parameters[4] = &divider_offset;

	// Pre-process parameter: stop_channel
	__parameterTypeNames[5] = "System.Int32";
	__parameterTypes[5] = (CDOTNET_INT32);
	__parameters[5] = &stop_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		0, 
		0, 
		__instance, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (pattern__)
		CDotNetDiscardHandle(pattern__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_1(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	unsigned __int64 divider_offset,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle pattern__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &trigger_channel;

	// Pre-process parameter: pattern
	if (pattern)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__patternLength, 
			pattern, 
			&pattern__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pattern__;

	// Pre-process parameter: trigger_divider
	__parameterTypeNames[3] = "System.UInt64";
	__parameterTypes[3] = (CDOTNET_UINT64);
	__parameters[3] = &trigger_divider;

	// Pre-process parameter: divider_offset
	__parameterTypeNames[4] = "System.UInt64";
	__parameterTypes[4] = (CDOTNET_UINT64);
	__parameters[4] = &divider_offset;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (pattern__)
		CDotNetDiscardHandle(pattern__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_2(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle pattern__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &trigger_channel;

	// Pre-process parameter: pattern
	if (pattern)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__patternLength, 
			pattern, 
			&pattern__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pattern__;

	// Pre-process parameter: trigger_divider
	__parameterTypeNames[3] = "System.UInt64";
	__parameterTypes[3] = (CDOTNET_UINT64);
	__parameters[3] = &trigger_divider;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (pattern__)
		CDotNetDiscardHandle(pattern__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_3(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle pattern__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &trigger_channel;

	// Pre-process parameter: pattern
	if (pattern)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__patternLength, 
			pattern, 
			&pattern__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pattern__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (pattern__)
		CDotNetDiscardHandle(pattern__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_getChannel(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_Dispose(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_start(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_startFor(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_startFor_1(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_stop(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_clear(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_isRunning(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_getCaptureDuration(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.FileReader
int CVIFUNC SwabianInstruments_TimeTagger_FileReader__Create(
	SwabianInstruments_TimeTagger_FileReader * __instance,
	char ** filenames,
	ssize_t __filenamesLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle filenames__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: filenames
	if (filenames)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__filenamesLength, 
			filenames, 
			&filenames__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &filenames__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (filenames__)
		CDotNetDiscardHandle(filenames__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader__Create_1(
	SwabianInstruments_TimeTagger_FileReader * __instance,
	char * filename,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filename;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader_Dispose(
	SwabianInstruments_TimeTagger_FileReader __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader_hasData(
	SwabianInstruments_TimeTagger_FileReader __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"hasData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getData(
	SwabianInstruments_TimeTagger_FileReader __instance,
	unsigned int n_events,
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: n_events
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &n_events;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getConfiguration(
	SwabianInstruments_TimeTagger_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConfiguration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getLastMarker(
	SwabianInstruments_TimeTagger_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileReader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getLastMarker", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.FileWriter
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter__Create(
	SwabianInstruments_TimeTagger_FileWriter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: filename
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &filename;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[2] = "System.Int32[]";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[2] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_split(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	char * new_filename,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: new_filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &new_filename;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"split", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_split_1(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"split", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_setMaxFileSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 max_file_size,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: max_file_size
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &max_file_size;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setMaxFileSize", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getMaxFileSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getMaxFileSize", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getTotalEvents(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTotalEvents", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getTotalSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTotalSize", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_setMarker(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	char * marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setMarker", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_Dispose(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_start(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_startFor(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_startFor_1(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_stop(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_clear(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_isRunning(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getCaptureDuration(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Flim
int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	__int64 binwidth,
	int n_bins,
	int n_pixels,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.Int32";
	__parameterTypes[5] = (CDOTNET_INT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[6] = "System.Int32";
	__parameterTypes[6] = (CDOTNET_INT32);
	__parameters[6] = &n_pixels;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		0, 
		0, 
		__instance, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_1(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.Int32";
	__parameterTypes[5] = (CDOTNET_INT32);
	__parameters[5] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		0, 
		0, 
		__instance, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_2(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_3(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_Dispose(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_start(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_startFor(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_startFor_1(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_stop(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_clear(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_getCaptureDuration(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_getData(
	SwabianInstruments_TimeTagger_Flim __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Flim_getIndex(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.FrequencyMultiplier
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier__Create(
	SwabianInstruments_TimeTagger_FrequencyMultiplier * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	int multiplier,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: input_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &input_channel;

	// Pre-process parameter: multiplier
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &multiplier;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getChannel(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getMultiplier(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getMultiplier", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_Dispose(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_start(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_startFor(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_startFor_1(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_stop(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_clear(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_isRunning(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getCaptureDuration(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.GatedChannel
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel__Create(
	SwabianInstruments_TimeTagger_GatedChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	int gate_start_channel,
	int gate_stop_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: input_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &input_channel;

	// Pre-process parameter: gate_start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &gate_start_channel;

	// Pre-process parameter: gate_stop_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &gate_stop_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_getChannel(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_Dispose(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_start(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_startFor(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_startFor_1(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_stop(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_clear(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_isRunning(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Histogram
int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_1(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_2(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_3(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_Dispose(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_start(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_startFor(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_startFor_1(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_stop(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_clear(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getCaptureDuration(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_isRunning(
	SwabianInstruments_TimeTagger_Histogram __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getData(
	SwabianInstruments_TimeTagger_Histogram __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getIndex(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Histogram2D
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D__Create(
	SwabianInstruments_TimeTagger_Histogram2D * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int start_channel,
	int stop_channel_1,
	int stop_channel_2,
	__int64 binwidth_1,
	__int64 binwidth_2,
	int n_bins_1,
	int n_bins_2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: start_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &start_channel;

	// Pre-process parameter: stop_channel_1
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &stop_channel_1;

	// Pre-process parameter: stop_channel_2
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &stop_channel_2;

	// Pre-process parameter: binwidth_1
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &binwidth_1;

	// Pre-process parameter: binwidth_2
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &binwidth_2;

	// Pre-process parameter: n_bins_1
	__parameterTypeNames[6] = "System.Int32";
	__parameterTypes[6] = (CDOTNET_INT32);
	__parameters[6] = &n_bins_1;

	// Pre-process parameter: n_bins_2
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &n_bins_2;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		0, 
		0, 
		__instance, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getData(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	ssize_t * ____returnValueLength3,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;
	if (__returnValue)
		*____returnValueLength3 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				2, 
				____returnValueLength3));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			3, 
			____returnValueLength1, 
			____returnValueLength2, 
			____returnValueLength3);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex_1(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex_1", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex_2(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex_2", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_Dispose(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_start(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_startFor(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_startFor_1(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_stop(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_clear(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_isRunning(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getCaptureDuration(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.HistogramLogBins
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins__Create(
	SwabianInstruments_TimeTagger_HistogramLogBins * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	double exp_start,
	double exp_stop,
	int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: exp_start
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &exp_start;

	// Pre-process parameter: exp_stop
	__parameterTypeNames[4] = "System.Double";
	__parameterTypes[4] = (CDOTNET_DOUBLE);
	__parameters[4] = &exp_stop;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.Int32";
	__parameterTypes[5] = (CDOTNET_INT32);
	__parameters[5] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		0, 
		0, 
		__instance, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getData(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_UINT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_UINT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getDataNormalizedCountsPerPs(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataNormalizedCountsPerPs", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getDataNormalizedG2(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataNormalizedG2", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getBinEdges(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getBinEdges", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_Dispose(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_start(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_startFor(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_startFor_1(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_stop(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_clear(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_isRunning(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getCaptureDuration(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Iterator
int CVIFUNC SwabianInstruments_TimeTagger_Iterator__Create(
	SwabianInstruments_TimeTagger_Iterator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_next(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"next", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_size(
	SwabianInstruments_TimeTagger_Iterator __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"size", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_Dispose(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_start(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_startFor(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_startFor_1(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_stop(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_clear(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_isRunning(
	SwabianInstruments_TimeTagger_Iterator __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Iterator_getCaptureDuration(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.IteratorBase
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_Dispose(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_start(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_startFor(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_startFor_1(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_stop(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_clear(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_isRunning(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_getCaptureDuration(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.Scope
int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	int n_traces,
	int n_max_events,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle event_channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: event_channels
	if (event_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__event_channelsLength, 
			event_channels, 
			&event_channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &event_channels__;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &trigger_channel;

	// Pre-process parameter: window_size
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &window_size;

	// Pre-process parameter: n_traces
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &n_traces;

	// Pre-process parameter: n_max_events
	__parameterTypeNames[5] = "System.Int32";
	__parameterTypes[5] = (CDOTNET_INT32);
	__parameters[5] = &n_max_events;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		0, 
		0, 
		__instance, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (event_channels__)
		CDotNetDiscardHandle(event_channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_1(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	int n_traces,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle event_channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: event_channels
	if (event_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__event_channelsLength, 
			event_channels, 
			&event_channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &event_channels__;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &trigger_channel;

	// Pre-process parameter: window_size
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &window_size;

	// Pre-process parameter: n_traces
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &n_traces;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (event_channels__)
		CDotNetDiscardHandle(event_channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_2(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle event_channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: event_channels
	if (event_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__event_channelsLength, 
			event_channels, 
			&event_channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &event_channels__;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &trigger_channel;

	// Pre-process parameter: window_size
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &window_size;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (event_channels__)
		CDotNetDiscardHandle(event_channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_3(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle event_channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: event_channels
	if (event_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__event_channelsLength, 
			event_channels, 
			&event_channels__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &event_channels__;

	// Pre-process parameter: trigger_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &trigger_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (event_channels__)
		CDotNetDiscardHandle(event_channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_ready(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_triggered(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"triggered", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_getWindowSize(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getWindowSize", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_getData(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_Dispose(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_start(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_startFor(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_startFor_1(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_stop(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_clear(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_isRunning(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_Scope_getCaptureDuration(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.StartStop
int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create_1(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create_2(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_getData(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_Dispose(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_start(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_startFor(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_startFor_1(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_stop(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_clear(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_isRunning(
	SwabianInstruments_TimeTagger_StartStop __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_StartStop_getCaptureDuration(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.SynchronizedMeasurements
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements__Create(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_Dispose(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_registerMeasurement(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_IteratorBase measurement,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurement
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.IteratorBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &measurement;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"registerMeasurement", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_unregisterMeasurement(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_IteratorBase measurement,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurement
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.IteratorBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &measurement;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"unregisterMeasurement", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_clear(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_start(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_stop(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_startFor(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_startFor_1(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_isRunning(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_getTagger(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTagger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TT
int CVIFUNC SwabianInstruments_TimeTagger_TT__Create(
	SwabianInstruments_TimeTagger_TT * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_add_logEvent(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TT+TimeTaggerLogger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &value;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"add_logEvent", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_remove_logEvent(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TT+TimeTaggerLogger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &value;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"remove_logEvent", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_addLogger(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: handler
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TT+TimeTaggerLogger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &handler;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"addLogger", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_setLogger(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: handler
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TT+TimeTaggerLogger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &handler;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setLogger", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_removeAllLogger(
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"removeAllLogger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_hasLogger(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"hasLogger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_getVersion(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"getVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTagger(
	char * serial,
	SwabianInstruments_TimeTagger_TimeTagger * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &serial;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"createTimeTagger", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTagger_1(
	SwabianInstruments_TimeTagger_TimeTagger * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"createTimeTagger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTaggerVirtual(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"createTimeTaggerVirtual", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_setCustomBitFileName(
	char * bitFileName,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: bitFileName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &bitFileName;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setCustomBitFileName", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_freeTimeTagger(
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"freeTimeTagger", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_freeAllTimeTagger(
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"freeAllTimeTagger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_getTimeTaggerModel(
	char * serial,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &serial;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"getTimeTaggerModel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_setTimeTaggerChannelNumberScheme(
	int scheme,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: scheme
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &scheme;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setTimeTaggerChannelNumberScheme", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_getTimeTaggerChannelNumberScheme(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"getTimeTaggerChannelNumberScheme", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_hasTimeTaggerVirtualLicense(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"hasTimeTaggerVirtualLicense", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_scanTimeTagger(
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING | CDOTNET_ARRAY;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"scanTimeTagger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_STRING, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_STRING, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TIMETAGGER_VERSION(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TIMETAGGER_VERSION", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__CHANNEL_UNUSED(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"CHANNEL_UNUSED", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__CHANNEL_UNUSED_OLD(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"CHANNEL_UNUSED_OLD", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_AUTO(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_NUMBER_SCHEME_AUTO", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_ZERO(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_NUMBER_SCHEME_ZERO", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_ONE(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_NUMBER_SCHEME_ONE", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_RISING_AND_FALLING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_RISING_AND_FALLING_EDGES", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_RISING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_RISING_EDGES", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_FALLING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TT_CHANNEL_FALLING_EDGES", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TT+TimeTaggerLogger
static int CVICALLBACK SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t)reserved)(
		callbackData,
		*(int*) parameters[0],
		*(char **) parameters[1]));

__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Create(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger * __instance,
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Get_Method(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Method", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Get_Target(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Target", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Invoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: level
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &level;

	// Pre-process parameter: message
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &message;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_BeginInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: level
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &level;

	// Pre-process parameter: message
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &message;

	// Pre-process parameter: callback
	__parameterTypeNames[2] = "System.AsyncCallback";
	__parameterTypes[2] = (CDOTNET_OBJECT);
	__parameters[2] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[3] = "System.Object";
	__parameterTypes[3] = (CDOTNET_OBJECT);
	__parameters[3] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_EndInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: result
	__parameterTypeNames[0] = "System.IAsyncResult";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &result;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EndInvoke", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetObjectData(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: info
	__parameterTypeNames[0] = "System.Runtime.Serialization.SerializationInfo";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &info;

	// Pre-process parameter: context
	__parameterTypeNames[1] = "System.Runtime.Serialization.StreamingContext";
	__parameterTypes[1] = (CDOTNET_STRUCT);
	__parameters[1] = &context;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetObjectData", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Equals(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: obj
	__parameterTypeNames[0] = "System.Object";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &obj;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Equals", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetInvocationList(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetInvocationList", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_OBJECT, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_OBJECT, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetHashCode(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetHashCode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_DynamicInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle args__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: args
	if (args)
		__errChk(CDotNetCreateArray(
			CDOTNET_OBJECT, 
			1, 
			0, 
			&__argsLength, 
			args, 
			&args__));
	__parameterTypeNames[0] = "System.Object[]";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &args__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DynamicInvoke", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (args__)
		CDotNetDiscardHandle(args__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Clone(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT+TimeTaggerLogger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clone", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeDifferences
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	int n_bins,
	int n_histograms,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: sync_channel
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &sync_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[6] = "System.Int32";
	__parameterTypes[6] = (CDOTNET_INT32);
	__parameters[6] = &n_bins;

	// Pre-process parameter: n_histograms
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &n_histograms;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_1(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: sync_channel
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &sync_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[6] = "System.Int32";
	__parameterTypes[6] = (CDOTNET_INT32);
	__parameters[6] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_2(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: sync_channel
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &sync_channel;

	// Pre-process parameter: binwidth
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_3(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Pre-process parameter: sync_channel
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &sync_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_4(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &next_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_5(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_6(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_setMaxCounts(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	unsigned __int64 max_counts,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: max_counts
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
	__parameters[0] = &max_counts;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setMaxCounts", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getCounts(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCounts", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_ready(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getData(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getIndex(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_Dispose(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_start(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_startFor(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_startFor_1(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_stop(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_clear(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_isRunning(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeDifferencesND
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND__Create(
	SwabianInstruments_TimeTagger_TimeDifferencesND * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int * next_channels,
	ssize_t __next_channelsLength,
	int * sync_channels,
	ssize_t __sync_channelsLength,
	int * n_histograms,
	ssize_t __n_histogramsLength,
	__int64 binwidth,
	unsigned int n_bins,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle next_channels__ = 0;
	CDotNetHandle sync_channels__ = 0;
	CDotNetHandle n_histograms__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: click_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &click_channel;

	// Pre-process parameter: start_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &start_channel;

	// Pre-process parameter: next_channels
	if (next_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__next_channelsLength, 
			next_channels, 
			&next_channels__));
	__parameterTypeNames[3] = "System.Int32[]";
	__parameterTypes[3] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[3] = &next_channels__;

	// Pre-process parameter: sync_channels
	if (sync_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__sync_channelsLength, 
			sync_channels, 
			&sync_channels__));
	__parameterTypeNames[4] = "System.Int32[]";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[4] = &sync_channels__;

	// Pre-process parameter: n_histograms
	if (n_histograms)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__n_histogramsLength, 
			n_histograms, 
			&n_histograms__));
	__parameterTypeNames[5] = "System.Int32[]";
	__parameterTypes[5] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[5] = &n_histograms__;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: n_bins
	__parameterTypeNames[7] = "System.UInt32";
	__parameterTypes[7] = (CDOTNET_UINT32);
	__parameters[7] = &n_bins;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		0, 
		0, 
		__instance, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (next_channels__)
		CDotNetDiscardHandle(next_channels__);
	if (sync_channels__)
		CDotNetDiscardHandle(sync_channels__);
	if (n_histograms__)
		CDotNetDiscardHandle(n_histograms__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getData(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getIndex(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_Dispose(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_start(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_startFor(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_startFor_1(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_stop(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_clear(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_isRunning(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeTagStream
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream__Create(
	SwabianInstruments_TimeTagger_TimeTagStream * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	unsigned int n_max_events,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: n_max_events
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &n_max_events;

	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[2] = "System.Int32[]";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[2] = &channels__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream__Create_1(
	SwabianInstruments_TimeTagger_TimeTagStream * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	unsigned int n_max_events,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTaggerBase";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: n_max_events
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &n_max_events;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getCounts(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCounts", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getData(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_Dispose(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_start(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"start", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_startFor(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Pre-process parameter: clear
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_startFor_1(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: capture_duration
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &capture_duration;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startFor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_stop(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_clear(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_isRunning(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isRunning", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCaptureDuration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeTagStreamBuffer
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer__Create(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_size(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"size", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_size(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"size", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_hasOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"hasOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_hasOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"hasOverflows", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_tStart(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"tStart", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_tStart(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"tStart", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_tGetData(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"tGetData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_tGetData(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"tGetData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Dispose(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_BYTE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getChannels(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannels", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getTimestamps(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTimestamps", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getMissedEvents(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT16 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getMissedEvents", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_UINT16, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_UINT16, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getEventTypes(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStreamBuffer", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getEventTypes", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_BYTE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeTagger
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_reset(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"reset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignalDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int divider,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: divider
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &divider;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignalDivider", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTestSignalDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTestSignalDivider", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTriggerLevel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	double voltage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: voltage
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &voltage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTriggerLevel", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTriggerLevel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTriggerLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getHardwareDelayCompensation(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHardwareDelayCompensation", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setInputMux(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int mux_mode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: mux_mode
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &mux_mode;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputMux", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInputMux(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputMux", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_clearConditionalFilter(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clearConditionalFilter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setNormalization(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setNormalization", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getNormalization(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getNormalization", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setHardwareBufferSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int size,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: size
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &size;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setHardwareBufferSize", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getHardwareBufferSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHardwareBufferSize", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setStreamBlockSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int max_events,
	int max_latency,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: max_events
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &max_events;

	// Pre-process parameter: max_latency
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &max_latency;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setStreamBlockSize", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getStreamBlockSizeEvents(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getStreamBlockSizeEvents", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getStreamBlockSizeLatency(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getStreamBlockSizeLatency", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setEventDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	unsigned int divider,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: divider
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &divider;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setEventDivider", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getEventDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getEventDivider", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getSerial(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSerial", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getModel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getModel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelNumberScheme(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannelNumberScheme", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getPsPerClock(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getPsPerClock", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getPcbVersion(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getPcbVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getFirmwareVersion(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFirmwareVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getSensorData(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSensorData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setLED(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	unsigned int bitmask,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: bitmask
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &bitmask;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setLED", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_factoryAccess(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	unsigned int pw,
	unsigned int addr,
	unsigned int data,
	unsigned int mask,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pw
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &pw;

	// Pre-process parameter: addr
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &addr;

	// Pre-process parameter: data
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &data;

	// Pre-process parameter: mask
	__parameterTypeNames[3] = "System.UInt32";
	__parameterTypes[3] = (CDOTNET_UINT32);
	__parameters[3] = &mask;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"factoryAccess", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setConditionalFilter(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	int hardwareDelayCompensation,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle trigger__ = 0;
	CDotNetHandle filtered__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: trigger
	if (trigger)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__triggerLength, 
			trigger, 
			&trigger__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &trigger__;

	// Pre-process parameter: filtered
	if (filtered)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__filteredLength, 
			filtered, 
			&filtered__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &filtered__;

	// Pre-process parameter: hardwareDelayCompensation
	__parameterTypeNames[2] = "System.Boolean";
	__parameterTypes[2] = (CDOTNET_BOOLEAN);
	__parameters[2] = &hardwareDelayCompensation;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setConditionalFilter", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (trigger__)
		CDotNetDiscardHandle(trigger__);
	if (filtered__)
		CDotNetDiscardHandle(filtered__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setConditionalFilter_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle trigger__ = 0;
	CDotNetHandle filtered__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: trigger
	if (trigger)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__triggerLength, 
			trigger, 
			&trigger__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &trigger__;

	// Pre-process parameter: filtered
	if (filtered)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__filteredLength, 
			filtered, 
			&filtered__));
	__parameterTypeNames[1] = "System.Int32[]";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[1] = &filtered__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setConditionalFilter", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (trigger__)
		CDotNetDiscardHandle(trigger__);
	if (filtered__)
		CDotNetDiscardHandle(filtered__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConditionalFilterTrigger(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConditionalFilterTrigger", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConditionalFilterFiltered(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConditionalFilterFiltered", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_autoCalibration(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"autoCalibration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDACRange(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDACRange", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDistributionCount(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDistributionCount", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDistributionPSecs(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDistributionPSecs", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT64, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT64, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelList(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: type
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &type;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannelList", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelList_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannelList", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_INT32, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_INT32, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_Dispose(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_sync(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInvertedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isUnusedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConfiguration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: delay
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &delay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputDelay", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: deadtime
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &deadtime;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDeadtime", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDeadtime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTestSignal", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getOverflows(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clearOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowsAndClear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channel__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	if (channel)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelLength, 
			channel, 
			&channel__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channel__;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (channel__)
		CDotNetDiscardHandle(channel__);
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeTaggerBase
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_Dispose(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_sync(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInvertedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isUnusedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConfiguration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: delay
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &delay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputDelay", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: deadtime
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &deadtime;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDeadtime", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDeadtime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTestSignal", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clearOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowsAndClear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channel__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	if (channel)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelLength, 
			channel, 
			&channel__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channel__;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (channel__)
		CDotNetDiscardHandle(channel__);
	return __error;
}


// Type: SwabianInstruments.TimeTagger.TimeTaggerVirtual
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	int queue,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file;

	// Pre-process parameter: begin
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &begin;

	// Pre-process parameter: duration
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &duration;

	// Pre-process parameter: queue
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &queue;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"replay", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file;

	// Pre-process parameter: begin
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &begin;

	// Pre-process parameter: duration
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &duration;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"replay", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_2(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file;

	// Pre-process parameter: begin
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &begin;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"replay", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_3(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"replay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_stop(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"stop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	int timeout,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ID
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
	__parameters[0] = &ID;

	// Pre-process parameter: timeout
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForCompletion", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ID
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
	__parameters[0] = &ID;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForCompletion", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion_2(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForCompletion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setReplaySpeed(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	double speed,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: speed
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &speed;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setReplaySpeed", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getReplaySpeed(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReplaySpeed", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_Dispose(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Dispose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_sync(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInvertedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isUnusedChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getConfiguration", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: delay
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &delay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputDelay", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: deadtime
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &deadtime;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDeadtime", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDeadtime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTestSignal", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clearOverflows", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowsAndClear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channel__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	if (channel)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelLength, 
			channel, 
			&channel__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channel__;

	// Pre-process parameter: enabled
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTestSignal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (channel__)
		CDotNetDiscardHandle(channel__);
	return __error;
}


// Type: SwabianInstruments.TimeTagger.CoincidencesFactory
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory__Create(
	SwabianInstruments_TimeTagger_CoincidencesFactory * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CoincidencesFactory", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_addCoincidenceGroup(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	int * array1d,
	ssize_t __array1dLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle array1d__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: array1d
	if (array1d)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__array1dLength, 
			array1d, 
			&array1d__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &array1d__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CoincidencesFactory", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"addCoincidenceGroup", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (array1d__)
		CDotNetDiscardHandle(array1d__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_getChannels(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CoincidencesFactory", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannels", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_addCoincidenceGroups(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	int * array2d,
	ssize_t __array2dLength1,
	ssize_t __array2dLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle array2d__ = 0;
	ssize_t __array2dLengths[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: array2d
	__array2dLengths[0] = __array2dLength1;
	__array2dLengths[1] = __array2dLength2;
	if (array2d)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			2, 
			0, 
			__array2dLengths, 
			array2d, 
			&array2d__));
	__parameterTypeNames[0] = "System.Int32[,]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &array2d__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CoincidencesFactory", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"addCoincidenceGroups", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (array2d__)
		CDotNetDiscardHandle(array2d__);
	return __error;
}

int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_createCoincidences(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	SwabianInstruments_TimeTagger_TimeTagger tagger,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_Coincidences * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: tagger
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.TimeTagger";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &tagger;

	// Pre-process parameter: coincidenceWindow
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &coincidenceWindow;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CoincidencesFactory", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"createCoincidences", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}



// Internal functions
static int CVIFUNC SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
	SwabianInstruments_TimeTagger_CoincidenceTimestamp * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"SwabianInstruments.TimeTagger.CoincidenceTimestamp", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC SwabianInstruments_TimeTagger_State__Create(
	SwabianInstruments_TimeTagger_State * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"SwabianInstruments.TimeTagger.State", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId)
{
	if (!*(void **)scalar)
		return;

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING) {
		CDotNetFreeMemory(*(char **)scalar);
		*(char **)scalar = 0;
	}
	else if (typeId == CDOTNET_OBJECT || typeId == CDOTNET_STRUCT) {
		CDotNetDiscardHandle(*(CDotNetHandle *)scalar);
		*(CDotNetHandle *)scalar = 0;
	}
}

static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...)
{
	size_t i;
	ssize_t totalLength = 1;
	va_list list;

	if (!*(void **)array)
		return;

	va_start(list, nDims);
	for (i = 0; i < nDims; ++i) {
		ssize_t * lenPtr = va_arg(list, ssize_t*);

		totalLength *= *lenPtr;
		*lenPtr = 0;
	}
	va_end(list);

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING)
		while (--totalLength >= 0)
			CDotNetFreeMemory((*(char ***)array)[totalLength]);
	else if (typeId > CDOTNET_ENUM)
		while (--totalLength >= 0)
			CDotNetDiscardHandle((*(CDotNetHandle **)array)[totalLength]);

	CDotNetFreeMemory(*(void**)array);
	*(void**)array = 0;
}

