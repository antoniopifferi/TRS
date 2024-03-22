// CVI wrapper source file for .NET assembly: SwabianInstruments.TimeTagger, Version=2.16.2.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7

#include "SwabNET.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "SwabianInstruments.TimeTagger, Version=2.16.2.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static int CVIFUNC SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
	Swab_TimeTag_CoincidenceTimestamp * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_State__Create(
	Swab_TimeTag_State * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_GatedChannelInitial__Create(
	Swab_TimeTag_GatedChannelInitial * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_Resolution__Create(
	Swab_TimeTag_Resolution * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_LanguageUsed__Create(
	Swab_TimeTag_LanguageUsed * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_FrontendType__Create(
	Swab_TimeTag_FrontendType * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_UsageStatisticsStatus__Create(
	Swab_TimeTag_UsageStatisticsStatus * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_ChannelEdge__Create(
	Swab_TimeTag_ChannelEdge * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_FpgaLinkInterface__Create(
	Swab_TimeTag_FpgaLinkInterface * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_AccessMode__Create(
	Swab_TimeTag_AccessMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC SwabianInstruments_TimeTagger_TagType__Create(
	Swab_TimeTag_TagType * value,
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


// Type: SwabianInstruments.TimeTagger.Coincidence
int CVIFUNC Swab_TimeTag_Coincidence__Create(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp timestamp,
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

int CVIFUNC Swab_TimeTag_Coincidence__Create_1(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Coincidence__Create_2(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Coincidence_getChannel(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_getChannels(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_setCoincidenceWindow(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_Dispose(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_start(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_startFor(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_startFor_1(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_waitUntilFinished(
	Swab_TimeTag_Coincidence __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidence", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Coincidence_waitUntilFinished_1(
	Swab_TimeTag_Coincidence __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Coincidence_stop(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_clear(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_isRunning(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_getCaptureDuration(
	Swab_TimeTag_Coincidence __instance,
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

int CVIFUNC Swab_TimeTag_Coincidence_getConfiguration(
	Swab_TimeTag_Coincidence __instance,
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
		"SwabianInstruments.TimeTagger.Coincidence", 
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


// Type: SwabianInstruments.TimeTagger.Coincidences
int CVIFUNC Swab_TimeTag_Coincidences__Create(
	Swab_TimeTag_Coincidences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp timestamp,
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

int CVIFUNC Swab_TimeTag_Coincidences__Create_1(
	Swab_TimeTag_Coincidences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Coincidences_getChannels(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_setCoincidenceWindow(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_Dispose(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_start(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_startFor(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_startFor_1(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_waitUntilFinished(
	Swab_TimeTag_Coincidences __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Coincidences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Coincidences_waitUntilFinished_1(
	Swab_TimeTag_Coincidences __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Coincidences_stop(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_clear(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_isRunning(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_getCaptureDuration(
	Swab_TimeTag_Coincidences __instance,
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

int CVIFUNC Swab_TimeTag_Coincidences_getConfiguration(
	Swab_TimeTag_Coincidences __instance,
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
		"SwabianInstruments.TimeTagger.Coincidences", 
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


// Type: SwabianInstruments.TimeTagger.Combiner
int CVIFUNC Swab_TimeTag_Combiner__Create(
	Swab_TimeTag_Combiner * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Combiner_getChannelCounts(
	Swab_TimeTag_Combiner __instance,
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
		"getChannelCounts", 
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

int CVIFUNC Swab_TimeTag_Combiner_getData(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_getChannel(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_Dispose(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_start(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_startFor(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_startFor_1(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_waitUntilFinished(
	Swab_TimeTag_Combiner __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Combiner", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Combiner_waitUntilFinished_1(
	Swab_TimeTag_Combiner __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Combiner_stop(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_clear(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_isRunning(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_getCaptureDuration(
	Swab_TimeTag_Combiner __instance,
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

int CVIFUNC Swab_TimeTag_Combiner_getConfiguration(
	Swab_TimeTag_Combiner __instance,
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
		"SwabianInstruments.TimeTagger.Combiner", 
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


// Type: SwabianInstruments.TimeTagger.ConstantFractionDiscriminator
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator__Create(
	Swab_TimeTag_ConstantFractionDiscriminator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getChannels(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_Dispose(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_start(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_startFor(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_startFor_1(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_waitUntilFinished(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_waitUntilFinished_1(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_stop(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_clear(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_isRunning(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getCaptureDuration(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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

int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getConfiguration(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
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
		"SwabianInstruments.TimeTagger.ConstantFractionDiscriminator", 
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


// Type: SwabianInstruments.TimeTagger.Correlation
int CVIFUNC Swab_TimeTag_Correlation__Create(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Correlation__Create_1(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Correlation__Create_2(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Correlation__Create_3(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Correlation_getData(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_getDataNormalized(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_getIndex(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_Dispose(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_start(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_startFor(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_startFor_1(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_waitUntilFinished(
	Swab_TimeTag_Correlation __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Correlation", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Correlation_waitUntilFinished_1(
	Swab_TimeTag_Correlation __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Correlation_stop(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_clear(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_isRunning(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_getCaptureDuration(
	Swab_TimeTag_Correlation __instance,
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

int CVIFUNC Swab_TimeTag_Correlation_getConfiguration(
	Swab_TimeTag_Correlation __instance,
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
		"SwabianInstruments.TimeTagger.Correlation", 
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


// Type: SwabianInstruments.TimeTagger.CountBetweenMarkers
int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create_1(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create_2(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_ready(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getData(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getBinWidths(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getIndex(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_Dispose(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_start(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_startFor(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_startFor_1(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_waitUntilFinished(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_waitUntilFinished_1(
	Swab_TimeTag_CountBetweenMarkers __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_stop(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_clear(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_isRunning(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getCaptureDuration(
	Swab_TimeTag_CountBetweenMarkers __instance,
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

int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getConfiguration(
	Swab_TimeTag_CountBetweenMarkers __instance,
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
		"SwabianInstruments.TimeTagger.CountBetweenMarkers", 
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


// Type: SwabianInstruments.TimeTagger.Counter
int CVIFUNC Swab_TimeTag_Counter__Create(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Counter__Create_1(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Counter__Create_2(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Counter_getData(
	Swab_TimeTag_Counter __instance,
	int rolling,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process parameter: rolling
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &rolling;

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

int CVIFUNC Swab_TimeTag_Counter_getData_1(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_getDataNormalized(
	Swab_TimeTag_Counter __instance,
	int rolling,
	double ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process parameter: rolling
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &rolling;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataNormalized", 
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
				CDOTNET_DOUBLE, 
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
			CDOTNET_DOUBLE, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Counter_getDataNormalized_1(
	Swab_TimeTag_Counter __instance,
	double ** __returnValue,
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
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
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
			CDOTNET_DOUBLE, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Counter_getDataTotalCounts(
	Swab_TimeTag_Counter __instance,
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
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataTotalCounts", 
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

int CVIFUNC Swab_TimeTag_Counter_getIndex(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_getDataObject(
	Swab_TimeTag_Counter __instance,
	int remove,
	Swab_TimeTag_CounterData * __returnValue,
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


	// Pre-process parameter: remove
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &remove;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataObject", 
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

int CVIFUNC Swab_TimeTag_Counter_getDataObject_1(
	Swab_TimeTag_Counter __instance,
	Swab_TimeTag_CounterData * __returnValue,
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
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataObject", 
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

int CVIFUNC Swab_TimeTag_Counter_Dispose(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_start(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_startFor(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_startFor_1(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_waitUntilFinished(
	Swab_TimeTag_Counter __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Counter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Counter_waitUntilFinished_1(
	Swab_TimeTag_Counter __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Counter_stop(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_clear(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_isRunning(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_getCaptureDuration(
	Swab_TimeTag_Counter __instance,
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

int CVIFUNC Swab_TimeTag_Counter_getConfiguration(
	Swab_TimeTag_Counter __instance,
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
		"SwabianInstruments.TimeTagger.Counter", 
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


// Type: SwabianInstruments.TimeTagger.CounterData
int CVIFUNC Swab_TimeTag_CounterData_Get_size(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
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

int CVIFUNC Swab_TimeTag_CounterData_Get_dropped_bins(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"dropped_bins", 
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

int CVIFUNC Swab_TimeTag_CounterData_Get_overflow(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"overflow", 
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

int CVIFUNC Swab_TimeTag_CounterData_Dispose(
	Swab_TimeTag_CounterData __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CounterData", 
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

int CVIFUNC Swab_TimeTag_CounterData_getData(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
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

int CVIFUNC Swab_TimeTag_CounterData_getDataNormalized(
	Swab_TimeTag_CounterData __instance,
	double ** __returnValue,
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
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CounterData", 
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
			CDOTNET_DOUBLE, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_CounterData_getDataTotalCounts(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataTotalCounts", 
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

int CVIFUNC Swab_TimeTag_CounterData_getIndex(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
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

int CVIFUNC Swab_TimeTag_CounterData_getTime(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTime", 
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

int CVIFUNC Swab_TimeTag_CounterData_getOverflowMask(
	Swab_TimeTag_CounterData __instance,
	char ** __returnValue,
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
	__returnValueTypeId = CDOTNET_SBYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CounterData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowMask", 
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
				CDOTNET_SBYTE, 
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
			CDOTNET_SBYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_CounterData_getChannels(
	Swab_TimeTag_CounterData __instance,
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
		"SwabianInstruments.TimeTagger.CounterData", 
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


// Type: SwabianInstruments.TimeTagger.Countrate
int CVIFUNC Swab_TimeTag_Countrate__Create(
	Swab_TimeTag_Countrate * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Countrate_getData(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_getCountsTotal(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_Dispose(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_start(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_startFor(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_startFor_1(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_waitUntilFinished(
	Swab_TimeTag_Countrate __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Countrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Countrate_waitUntilFinished_1(
	Swab_TimeTag_Countrate __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Countrate_stop(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_clear(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_isRunning(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_getCaptureDuration(
	Swab_TimeTag_Countrate __instance,
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

int CVIFUNC Swab_TimeTag_Countrate_getConfiguration(
	Swab_TimeTag_Countrate __instance,
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
		"SwabianInstruments.TimeTagger.Countrate", 
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase
int CVIFUNC Swab_TimeTag_CustomMeasBase_stop_all_custom_measurements(
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"stop_all_custom_measurements", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_register_channel(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_unregister_channel(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_finalize_init(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_is_running(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase__lock(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase__unlock(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_Dispose(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_start(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_startFor(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_startFor_1(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_waitUntilFinished(
	Swab_TimeTag_CustomMeasBase __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_waitUntilFinished_1(
	Swab_TimeTag_CustomMeasBase __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_stop(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_clear(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_isRunning(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_getCaptureDuration(
	Swab_TimeTag_CustomMeasBase __instance,
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_getConfiguration(
	Swab_TimeTag_CustomMeasBase __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase", 
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0
static int CVICALLBACK SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback_t)reserved)(
		callbackData));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
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


	// Pre-process parameter: callback
	__parameterTypeNames[0] = "System.AsyncCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[1] = "System.Object";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0", 
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1
static int CVICALLBACK SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback_t)reserved)(
		callbackData));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
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


	// Pre-process parameter: callback
	__parameterTypeNames[0] = "System.AsyncCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[1] = "System.Object";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1", 
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2
static int CVICALLBACK SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback_t)reserved)(
		callbackData));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
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


	// Pre-process parameter: callback
	__parameterTypeNames[0] = "System.AsyncCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[1] = "System.Object";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2", 
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3
static int CVICALLBACK SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback_t)reserved)(
		callbackData,
		*(void **) parameters[0],
		*(unsigned __int64*) parameters[1],
		*(__int64*) parameters[2],
		*(__int64*) parameters[3]));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	void * tags_ptr,
	unsigned __int64 num_tags,
	__int64 begin_time,
	__int64 end_time,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: tags_ptr
	__parameterTypeNames[0] = "System.IntPtr";
	__parameterTypes[0] = (CDOTNET_INTPTR);
	__parameters[0] = &tags_ptr;

	// Pre-process parameter: num_tags
	__parameterTypeNames[1] = "System.UInt64";
	__parameterTypes[1] = (CDOTNET_UINT64);
	__parameters[1] = &num_tags;

	// Pre-process parameter: begin_time
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &begin_time;

	// Pre-process parameter: end_time
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &end_time;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	void * tags_ptr,
	unsigned __int64 num_tags,
	__int64 begin_time,
	__int64 end_time,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: tags_ptr
	__parameterTypeNames[0] = "System.IntPtr";
	__parameterTypes[0] = (CDOTNET_INTPTR);
	__parameters[0] = &tags_ptr;

	// Pre-process parameter: num_tags
	__parameterTypeNames[1] = "System.UInt64";
	__parameterTypes[1] = (CDOTNET_UINT64);
	__parameters[1] = &num_tags;

	// Pre-process parameter: begin_time
	__parameterTypeNames[2] = "System.Int64";
	__parameterTypes[2] = (CDOTNET_INT64);
	__parameters[2] = &begin_time;

	// Pre-process parameter: end_time
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &end_time;

	// Pre-process parameter: callback
	__parameterTypeNames[4] = "System.AsyncCallback";
	__parameterTypes[4] = (CDOTNET_OBJECT);
	__parameters[4] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[5] = "System.Object";
	__parameterTypes[5] = (CDOTNET_OBJECT);
	__parameters[5] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
		0, 
		0, 
		6, 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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

int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3", 
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


// Type: SwabianInstruments.TimeTagger.DelayedChannel
int CVIFUNC Swab_TimeTag_DelayedChannel__Create(
	Swab_TimeTag_DelayedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_getChannel(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_setDelay(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_Dispose(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_start(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_startFor(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_startFor_1(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_waitUntilFinished(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.DelayedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_DelayedChannel_waitUntilFinished_1(
	Swab_TimeTag_DelayedChannel __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_DelayedChannel_stop(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_clear(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_isRunning(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_getCaptureDuration(
	Swab_TimeTag_DelayedChannel __instance,
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

int CVIFUNC Swab_TimeTag_DelayedChannel_getConfiguration(
	Swab_TimeTag_DelayedChannel __instance,
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
		"SwabianInstruments.TimeTagger.DelayedChannel", 
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


// Type: SwabianInstruments.TimeTagger.Dump
int CVIFUNC Swab_TimeTag_Dump__Create(
	Swab_TimeTag_Dump * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Dump__Create_1(
	Swab_TimeTag_Dump * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Dump_Dispose(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_start(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_startFor(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_startFor_1(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_waitUntilFinished(
	Swab_TimeTag_Dump __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Dump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Dump_waitUntilFinished_1(
	Swab_TimeTag_Dump __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Dump_stop(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_clear(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_isRunning(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_getCaptureDuration(
	Swab_TimeTag_Dump __instance,
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

int CVIFUNC Swab_TimeTag_Dump_getConfiguration(
	Swab_TimeTag_Dump __instance,
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
		"SwabianInstruments.TimeTagger.Dump", 
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


// Type: SwabianInstruments.TimeTagger.Event
int CVIFUNC Swab_TimeTag_Event__Create(
	Swab_TimeTag_Event * __instance,
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

int CVIFUNC Swab_TimeTag_Event_Get_time(
	Swab_TimeTag_Event __instance,
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

int CVIFUNC Swab_TimeTag_Event_Set_time(
	Swab_TimeTag_Event __instance,
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

int CVIFUNC Swab_TimeTag_Event_Get_state(
	Swab_TimeTag_Event __instance,
	Swab_TimeTag_State * __returnValue,
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

int CVIFUNC Swab_TimeTag_Event_Set_state(
	Swab_TimeTag_Event __instance,
	Swab_TimeTag_State value,
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

int CVIFUNC Swab_TimeTag_Event_Dispose(
	Swab_TimeTag_Event __instance,
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
int CVIFUNC Swab_TimeTag_EventGenerator__Create(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_EventGenerator__Create_1(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_EventGenerator__Create_2(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_EventGenerator__Create_3(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_EventGenerator_getChannel(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_Dispose(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_start(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_startFor(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_startFor_1(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_waitUntilFinished(
	Swab_TimeTag_EventGenerator __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.EventGenerator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_EventGenerator_waitUntilFinished_1(
	Swab_TimeTag_EventGenerator __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_EventGenerator_stop(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_clear(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_isRunning(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_getCaptureDuration(
	Swab_TimeTag_EventGenerator __instance,
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

int CVIFUNC Swab_TimeTag_EventGenerator_getConfiguration(
	Swab_TimeTag_EventGenerator __instance,
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
		"SwabianInstruments.TimeTagger.EventGenerator", 
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


// Type: SwabianInstruments.TimeTagger.FileReader
int CVIFUNC Swab_TimeTag_FileReader__Create(
	Swab_TimeTag_FileReader * __instance,
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

int CVIFUNC Swab_TimeTag_FileReader__Create_1(
	Swab_TimeTag_FileReader * __instance,
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

int CVIFUNC Swab_TimeTag_FileReader_Dispose(
	Swab_TimeTag_FileReader __instance,
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

int CVIFUNC Swab_TimeTag_FileReader_hasData(
	Swab_TimeTag_FileReader __instance,
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

int CVIFUNC Swab_TimeTag_FileReader_getData(
	Swab_TimeTag_FileReader __instance,
	unsigned __int64 n_events,
	Swab_TimeTag_TimeTagStreamBuffer * __returnValue,
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
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
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

int CVIFUNC Swab_TimeTag_FileReader_getConfiguration(
	Swab_TimeTag_FileReader __instance,
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

int CVIFUNC Swab_TimeTag_FileReader_getChannelList(
	Swab_TimeTag_FileReader __instance,
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
		"SwabianInstruments.TimeTagger.FileReader", 
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

int CVIFUNC Swab_TimeTag_FileReader_getLastMarker(
	Swab_TimeTag_FileReader __instance,
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
int CVIFUNC Swab_TimeTag_FileWriter__Create(
	Swab_TimeTag_FileWriter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_FileWriter_split(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_split_1(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_setMaxFileSize(
	Swab_TimeTag_FileWriter __instance,
	unsigned __int64 max_file_size,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: max_file_size
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
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

int CVIFUNC Swab_TimeTag_FileWriter_getMaxFileSize(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_getTotalEvents(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_getTotalSize(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_setMarker(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_Dispose(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_start(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_startFor(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_startFor_1(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_waitUntilFinished(
	Swab_TimeTag_FileWriter __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FileWriter", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FileWriter_waitUntilFinished_1(
	Swab_TimeTag_FileWriter __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FileWriter_stop(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_clear(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_isRunning(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_getCaptureDuration(
	Swab_TimeTag_FileWriter __instance,
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

int CVIFUNC Swab_TimeTag_FileWriter_getConfiguration(
	Swab_TimeTag_FileWriter __instance,
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
		"SwabianInstruments.TimeTagger.FileWriter", 
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


// Type: SwabianInstruments.TimeTagger.FlimAbstract_internal
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_isAcquiring(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isAcquiring", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_Dispose(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_start(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_startFor(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_startFor_1(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_waitUntilFinished(
	Swab_TimeTag_FlimAbstract_internal __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_waitUntilFinished_1(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_stop(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_clear(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_isRunning(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_getCaptureDuration(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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

int CVIFUNC Swab_TimeTag_FlimAbstract_internal_getConfiguration(
	Swab_TimeTag_FlimAbstract_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimAbstract_internal", 
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


// Type: SwabianInstruments.TimeTagger.FlimBase_internal
int CVIFUNC Swab_TimeTag_FlimBase_internal__Create(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	int pre_initialize,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Pre-process parameter: pre_initialize
	__parameterTypeNames[11] = "System.Boolean";
	__parameterTypes[11] = (CDOTNET_BOOLEAN);
	__parameters[11] = &pre_initialize;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		0, 
		0, 
		__instance, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_1(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[11] = {0};
	unsigned int __parameterTypes[11];
	void * __parameters[11];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		0, 
		0, 
		__instance, 
		11, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_2(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		0, 
		0, 
		__instance, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_3(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		0, 
		0, 
		__instance, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_4(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_5(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
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

	// Pre-process parameter: start_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &start_channel;

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_initialize(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"initialize", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_isAcquiring(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isAcquiring", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_Dispose(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_start(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_startFor(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_startFor_1(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_waitUntilFinished(
	Swab_TimeTag_FlimBase_internal __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_waitUntilFinished_1(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_stop(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_clear(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_isRunning(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_getCaptureDuration(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_getConfiguration(
	Swab_TimeTag_FlimBase_internal __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal", 
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


// Type: SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0
static int CVICALLBACK SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback_t)reserved)(
		callbackData,
		*(unsigned int*) parameters[0],
		*(void **) parameters[1],
		*(void **) parameters[2],
		*(void **) parameters[3],
		*(__int64*) parameters[4],
		*(__int64*) parameters[5]));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0__Create(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 * __instance,
	SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Get_Method(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Get_Target(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Invoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	__parameterTypeNames[1] = "System.IntPtr";
	__parameterTypes[1] = (CDOTNET_INTPTR);
	__parameters[1] = &data;

	// Pre-process parameter: pixel_begin_times
	__parameterTypeNames[2] = "System.IntPtr";
	__parameterTypes[2] = (CDOTNET_INTPTR);
	__parameters[2] = &pixel_begin_times;

	// Pre-process parameter: pixel_end_times
	__parameterTypeNames[3] = "System.IntPtr";
	__parameterTypes[3] = (CDOTNET_INTPTR);
	__parameters[3] = &pixel_end_times;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_BeginInvoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	__parameterTypeNames[1] = "System.IntPtr";
	__parameterTypes[1] = (CDOTNET_INTPTR);
	__parameters[1] = &data;

	// Pre-process parameter: pixel_begin_times
	__parameterTypeNames[2] = "System.IntPtr";
	__parameterTypes[2] = (CDOTNET_INTPTR);
	__parameters[2] = &pixel_begin_times;

	// Pre-process parameter: pixel_end_times
	__parameterTypeNames[3] = "System.IntPtr";
	__parameterTypes[3] = (CDOTNET_INTPTR);
	__parameters[3] = &pixel_end_times;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Pre-process parameter: callback
	__parameterTypeNames[6] = "System.AsyncCallback";
	__parameterTypes[6] = (CDOTNET_OBJECT);
	__parameters[6] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[7] = "System.Object";
	__parameterTypes[7] = (CDOTNET_OBJECT);
	__parameters[7] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
		0, 
		0, 
		8, 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_EndInvoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetObjectData(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Equals(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetInvocationList(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetHashCode(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_DynamicInvoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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

int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Clone(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0", 
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


// Type: SwabianInstruments.TimeTagger.FlimFrameInfo
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_pixels(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"pixels", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_pixels(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"pixels", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_bins(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"bins", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_bins(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"bins", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_frame_number(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"frame_number", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_frame_number(
	Swab_TimeTag_FlimFrameInfo __instance,
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
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"frame_number", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_pixel_position(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"pixel_position", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_pixel_position(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"pixel_position", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_valid(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"valid", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_valid(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"valid", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_Dispose(
	Swab_TimeTag_FlimFrameInfo __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getFrameNumber(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFrameNumber", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_isValid(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isValid", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelPosition(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getPixelPosition", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getHistograms(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int ** __returnValue,
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
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHistograms", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getIntensities(
	Swab_TimeTag_FlimFrameInfo __instance,
	float ** __returnValue,
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
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIntensities", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getSummedCounts(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedCounts", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelBegins(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getPixelBegins", 
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

int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelEnds(
	Swab_TimeTag_FlimFrameInfo __instance,
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
		"SwabianInstruments.TimeTagger.FlimFrameInfo", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getPixelEnds", 
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


// Type: SwabianInstruments.TimeTagger.Flim_internal
int CVIFUNC Swab_TimeTag_Flim_internal__Create(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	int pre_initialize,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Pre-process parameter: pre_initialize
	__parameterTypeNames[11] = "System.Boolean";
	__parameterTypes[11] = (CDOTNET_BOOLEAN);
	__parameters[11] = &pre_initialize;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		0, 
		0, 
		__instance, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal__Create_1(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[11] = {0};
	unsigned int __parameterTypes[11];
	void * __parameters[11];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		0, 
		0, 
		__instance, 
		11, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal__Create_2(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		0, 
		0, 
		__instance, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal__Create_3(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		0, 
		0, 
		__instance, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal__Create_4(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	int pixel_end_channel,
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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal__Create_5(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
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

	// Pre-process parameter: start_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &start_channel;

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.Int64";
	__parameterTypes[6] = (CDOTNET_INT64);
	__parameters[6] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_initialize(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"initialize", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrame(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process parameter: index
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &index;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrame", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrame_1(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
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
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrame", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameIntensity(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	float ** __returnValue,
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


	// Pre-process parameter: index
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &index;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrameIntensity", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameIntensity_1(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
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
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrameIntensity", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrame(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
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
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCurrentFrame", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrameIntensity(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
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
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCurrentFrameIntensity", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
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


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process parameter: clear_summed
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear_summed;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFrames", 
		0, 
		0, 
		2, 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFrames", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames_2(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
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
	__returnValueTypeId = CDOTNET_UINT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFrames", 
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
				CDOTNET_UINT32, 
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
			CDOTNET_UINT32, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process parameter: clear_summed
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear_summed;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesIntensity", 
		0, 
		0, 
		2, 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	float ** __returnValue,
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


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesIntensity", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity_2(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
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
	__returnValueTypeId = CDOTNET_SINGLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesIntensity", 
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
				CDOTNET_SINGLE, 
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
			CDOTNET_SINGLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameEx(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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


	// Pre-process parameter: index
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &index;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrameEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameEx_1(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getReadyFrameEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrameEx(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCurrentFrameEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process parameter: clear_summed
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &clear_summed;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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


	// Pre-process parameter: only_ready_frames
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &only_ready_frames;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx_2(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSummedFramesEx", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getFramesAcquired(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFramesAcquired", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getIndex(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_isAcquiring(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isAcquiring", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_Dispose(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_start(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_startFor(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_startFor_1(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_waitUntilFinished(
	Swab_TimeTag_Flim_internal __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_waitUntilFinished_1(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_stop(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_clear(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_isRunning(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getCaptureDuration(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_getConfiguration(
	Swab_TimeTag_Flim_internal __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal", 
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


// Type: SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0
static int CVICALLBACK SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;



	__errChk(((SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback_t)reserved)(
		callbackData,
		*(unsigned int*) parameters[0],
		*(void **) parameters[1],
		*(void **) parameters[2],
		*(void **) parameters[3],
		*(__int64*) parameters[4],
		*(__int64*) parameters[5]));

__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0__Create(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 * __instance,
	SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Get_Method(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Get_Target(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Invoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	__parameterTypeNames[1] = "System.IntPtr";
	__parameterTypes[1] = (CDOTNET_INTPTR);
	__parameters[1] = &data;

	// Pre-process parameter: pixel_begin_times
	__parameterTypeNames[2] = "System.IntPtr";
	__parameterTypes[2] = (CDOTNET_INTPTR);
	__parameters[2] = &pixel_begin_times;

	// Pre-process parameter: pixel_end_times
	__parameterTypeNames[3] = "System.IntPtr";
	__parameterTypes[3] = (CDOTNET_INTPTR);
	__parameters[3] = &pixel_end_times;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_BeginInvoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	__parameterTypeNames[1] = "System.IntPtr";
	__parameterTypes[1] = (CDOTNET_INTPTR);
	__parameters[1] = &data;

	// Pre-process parameter: pixel_begin_times
	__parameterTypeNames[2] = "System.IntPtr";
	__parameterTypes[2] = (CDOTNET_INTPTR);
	__parameters[2] = &pixel_begin_times;

	// Pre-process parameter: pixel_end_times
	__parameterTypeNames[3] = "System.IntPtr";
	__parameterTypes[3] = (CDOTNET_INTPTR);
	__parameters[3] = &pixel_end_times;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Pre-process parameter: callback
	__parameterTypeNames[6] = "System.AsyncCallback";
	__parameterTypes[6] = (CDOTNET_OBJECT);
	__parameters[6] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[7] = "System.Object";
	__parameterTypes[7] = (CDOTNET_OBJECT);
	__parameters[7] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
		0, 
		0, 
		8, 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_EndInvoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetObjectData(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Equals(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetInvocationList(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetHashCode(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_DynamicInvoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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

int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Clone(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
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
		"SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0", 
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


// Type: SwabianInstruments.TimeTagger.FrequencyMultiplier
int CVIFUNC Swab_TimeTag_FrequencyMultiplier__Create(
	Swab_TimeTag_FrequencyMultiplier * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getChannel(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getMultiplier(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_Dispose(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_start(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_startFor(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_startFor_1(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_waitUntilFinished(
	Swab_TimeTag_FrequencyMultiplier __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_waitUntilFinished_1(
	Swab_TimeTag_FrequencyMultiplier __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_stop(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_clear(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_isRunning(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getCaptureDuration(
	Swab_TimeTag_FrequencyMultiplier __instance,
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

int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getConfiguration(
	Swab_TimeTag_FrequencyMultiplier __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyMultiplier", 
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


// Type: SwabianInstruments.TimeTagger.FrequencyStability
int CVIFUNC Swab_TimeTag_FrequencyStability__Create(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	__int64 average,
	unsigned __int64 trace_len,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle steps__ = 0;

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

	// Pre-process parameter: steps
	if (steps)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT64, 
			1, 
			0, 
			&__stepsLength, 
			steps, 
			&steps__));
	__parameterTypeNames[2] = "System.UInt64[]";
	__parameterTypes[2] = (CDOTNET_UINT64 | CDOTNET_ARRAY);
	__parameters[2] = &steps__;

	// Pre-process parameter: average
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &average;

	// Pre-process parameter: trace_len
	__parameterTypeNames[4] = "System.UInt64";
	__parameterTypes[4] = (CDOTNET_UINT64);
	__parameters[4] = &trace_len;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (steps__)
		CDotNetDiscardHandle(steps__);
	return __error;
}

int CVIFUNC Swab_TimeTag_FrequencyStability__Create_1(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	__int64 average,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle steps__ = 0;

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

	// Pre-process parameter: steps
	if (steps)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT64, 
			1, 
			0, 
			&__stepsLength, 
			steps, 
			&steps__));
	__parameterTypeNames[2] = "System.UInt64[]";
	__parameterTypes[2] = (CDOTNET_UINT64 | CDOTNET_ARRAY);
	__parameters[2] = &steps__;

	// Pre-process parameter: average
	__parameterTypeNames[3] = "System.Int64";
	__parameterTypes[3] = (CDOTNET_INT64);
	__parameters[3] = &average;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		0, 
		0, 
		__instance, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (steps__)
		CDotNetDiscardHandle(steps__);
	return __error;
}

int CVIFUNC Swab_TimeTag_FrequencyStability__Create_2(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle steps__ = 0;

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

	// Pre-process parameter: steps
	if (steps)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT64, 
			1, 
			0, 
			&__stepsLength, 
			steps, 
			&steps__));
	__parameterTypeNames[2] = "System.UInt64[]";
	__parameterTypes[2] = (CDOTNET_UINT64 | CDOTNET_ARRAY);
	__parameters[2] = &steps__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		0, 
		0, 
		__instance, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (steps__)
		CDotNetDiscardHandle(steps__);
	return __error;
}

int CVIFUNC Swab_TimeTag_FrequencyStability_getDataObject(
	Swab_TimeTag_FrequencyStability __instance,
	Swab_TimeTag_FrequencyStabilityData * __returnValue,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataObject", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_Dispose(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_start(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_startFor(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_startFor_1(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_waitUntilFinished(
	Swab_TimeTag_FrequencyStability __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_waitUntilFinished_1(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_stop(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_clear(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_isRunning(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_getCaptureDuration(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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

int CVIFUNC Swab_TimeTag_FrequencyStability_getConfiguration(
	Swab_TimeTag_FrequencyStability __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStability", 
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


// Type: SwabianInstruments.TimeTagger.FrequencyStabilityData
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_Dispose(
	Swab_TimeTag_FrequencyStabilityData __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getSTDD(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSTDD", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getADEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getADEV", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getMDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getMDEV", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTDEV", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getHDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHDEV", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getADEVScaled(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getADEVScaled", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getHDEVScaled(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHDEVScaled", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTau(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTau", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTracePhase(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTracePhase", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequency(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTraceFrequency", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequencyAbsolute(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double input_frequency,
	double ** __returnValue,
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


	// Pre-process parameter: input_frequency
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &input_frequency;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTraceFrequencyAbsolute", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequencyAbsolute_1(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTraceFrequencyAbsolute", 
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

int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceIndex(
	Swab_TimeTag_FrequencyStabilityData __instance,
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
		"SwabianInstruments.TimeTagger.FrequencyStabilityData", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getTraceIndex", 
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


// Type: SwabianInstruments.TimeTagger.GatedChannel
int CVIFUNC Swab_TimeTag_GatedChannel__Create(
	Swab_TimeTag_GatedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int gate_start_channel,
	int gate_stop_channel,
	Swab_TimeTag_GatedChannelInitial initial,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle initial__ = 0;

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

	// Pre-process parameter: initial
	__errChk(SwabianInstruments_TimeTagger_GatedChannelInitial__Create(
		&initial, 
		&initial__, 
		__exception));
	__parameterTypeNames[4] = "SwabianInstruments.TimeTagger.GatedChannelInitial";
	__parameterTypes[4] = (CDOTNET_ENUM);
	__parameters[4] = &initial__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (initial__)
		CDotNetDiscardHandle(initial__);
	return __error;
}

int CVIFUNC Swab_TimeTag_GatedChannel__Create_1(
	Swab_TimeTag_GatedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_GatedChannel_getChannel(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_Dispose(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_start(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_startFor(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_startFor_1(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_waitUntilFinished(
	Swab_TimeTag_GatedChannel __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.GatedChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_GatedChannel_waitUntilFinished_1(
	Swab_TimeTag_GatedChannel __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_GatedChannel_stop(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_clear(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_isRunning(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_getCaptureDuration(
	Swab_TimeTag_GatedChannel __instance,
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

int CVIFUNC Swab_TimeTag_GatedChannel_getConfiguration(
	Swab_TimeTag_GatedChannel __instance,
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
		"SwabianInstruments.TimeTagger.GatedChannel", 
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


// Type: SwabianInstruments.TimeTagger.Histogram
int CVIFUNC Swab_TimeTag_Histogram__Create(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Histogram__Create_1(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Histogram__Create_2(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Histogram__Create_3(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Histogram_getData(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_getIndex(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_Dispose(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_start(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_startFor(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_startFor_1(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_waitUntilFinished(
	Swab_TimeTag_Histogram __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Histogram_waitUntilFinished_1(
	Swab_TimeTag_Histogram __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Histogram_stop(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_clear(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_isRunning(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_getCaptureDuration(
	Swab_TimeTag_Histogram __instance,
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

int CVIFUNC Swab_TimeTag_Histogram_getConfiguration(
	Swab_TimeTag_Histogram __instance,
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
		"SwabianInstruments.TimeTagger.Histogram", 
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


// Type: SwabianInstruments.TimeTagger.Histogram2D
int CVIFUNC Swab_TimeTag_Histogram2D__Create(
	Swab_TimeTag_Histogram2D * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getData(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getIndex(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getIndex_1(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getIndex_2(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_Dispose(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_start(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_startFor(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_startFor_1(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_waitUntilFinished(
	Swab_TimeTag_Histogram2D __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Histogram2D", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Histogram2D_waitUntilFinished_1(
	Swab_TimeTag_Histogram2D __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Histogram2D_stop(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_clear(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_isRunning(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getCaptureDuration(
	Swab_TimeTag_Histogram2D __instance,
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

int CVIFUNC Swab_TimeTag_Histogram2D_getConfiguration(
	Swab_TimeTag_Histogram2D __instance,
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
		"SwabianInstruments.TimeTagger.Histogram2D", 
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


// Type: SwabianInstruments.TimeTagger.HistogramLogBins
int CVIFUNC Swab_TimeTag_HistogramLogBins__Create(
	Swab_TimeTag_HistogramLogBins * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getData(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getDataNormalizedCountsPerPs(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getDataNormalizedG2(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getBinEdges(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_Dispose(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_start(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_startFor(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_startFor_1(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_waitUntilFinished(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_waitUntilFinished_1(
	Swab_TimeTag_HistogramLogBins __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_stop(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_clear(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_isRunning(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getCaptureDuration(
	Swab_TimeTag_HistogramLogBins __instance,
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

int CVIFUNC Swab_TimeTag_HistogramLogBins_getConfiguration(
	Swab_TimeTag_HistogramLogBins __instance,
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
		"SwabianInstruments.TimeTagger.HistogramLogBins", 
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


// Type: SwabianInstruments.TimeTagger.HistogramND
int CVIFUNC Swab_TimeTag_HistogramND__Create(
	Swab_TimeTag_HistogramND * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int * stop_channels,
	ssize_t __stop_channelsLength,
	__int64 * binwidths,
	ssize_t __binwidthsLength,
	int * n_bins,
	ssize_t __n_binsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle stop_channels__ = 0;
	CDotNetHandle binwidths__ = 0;
	CDotNetHandle n_bins__ = 0;

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

	// Pre-process parameter: stop_channels
	if (stop_channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__stop_channelsLength, 
			stop_channels, 
			&stop_channels__));
	__parameterTypeNames[2] = "System.Int32[]";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[2] = &stop_channels__;

	// Pre-process parameter: binwidths
	if (binwidths)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__binwidthsLength, 
			binwidths, 
			&binwidths__));
	__parameterTypeNames[3] = "System.Int64[]";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[3] = &binwidths__;

	// Pre-process parameter: n_bins
	if (n_bins)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__n_binsLength, 
			n_bins, 
			&n_bins__));
	__parameterTypeNames[4] = "System.Int32[]";
	__parameterTypes[4] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[4] = &n_bins__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
		0, 
		0, 
		__instance, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (stop_channels__)
		CDotNetDiscardHandle(stop_channels__);
	if (binwidths__)
		CDotNetDiscardHandle(binwidths__);
	if (n_bins__)
		CDotNetDiscardHandle(n_bins__);
	return __error;
}

int CVIFUNC Swab_TimeTag_HistogramND_getData(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_getIndex(
	Swab_TimeTag_HistogramND __instance,
	int dim,
	__int64 ** __returnValue,
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


	// Pre-process parameter: dim
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &dim;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getIndex", 
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

int CVIFUNC Swab_TimeTag_HistogramND_getIndex_1(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_Dispose(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_start(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_startFor(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_startFor_1(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_waitUntilFinished(
	Swab_TimeTag_HistogramND __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_HistogramND_waitUntilFinished_1(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_HistogramND_stop(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_clear(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_isRunning(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_getCaptureDuration(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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

int CVIFUNC Swab_TimeTag_HistogramND_getConfiguration(
	Swab_TimeTag_HistogramND __instance,
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
		"SwabianInstruments.TimeTagger.HistogramND", 
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


// Type: SwabianInstruments.TimeTagger.Iterator
int CVIFUNC Swab_TimeTag_Iterator__Create(
	Swab_TimeTag_Iterator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Iterator_next(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_size(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_Dispose(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_start(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_startFor(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_startFor_1(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_waitUntilFinished(
	Swab_TimeTag_Iterator __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Iterator", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Iterator_waitUntilFinished_1(
	Swab_TimeTag_Iterator __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Iterator_stop(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_clear(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_isRunning(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_getCaptureDuration(
	Swab_TimeTag_Iterator __instance,
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

int CVIFUNC Swab_TimeTag_Iterator_getConfiguration(
	Swab_TimeTag_Iterator __instance,
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
		"SwabianInstruments.TimeTagger.Iterator", 
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


// Type: SwabianInstruments.TimeTagger.IteratorBase
int CVIFUNC Swab_TimeTag_IteratorBase_Dispose(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_start(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_startFor(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_startFor_1(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_waitUntilFinished(
	Swab_TimeTag_IteratorBase __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.IteratorBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_IteratorBase_waitUntilFinished_1(
	Swab_TimeTag_IteratorBase __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_IteratorBase_stop(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_clear(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_isRunning(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_getCaptureDuration(
	Swab_TimeTag_IteratorBase __instance,
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

int CVIFUNC Swab_TimeTag_IteratorBase_getConfiguration(
	Swab_TimeTag_IteratorBase __instance,
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
		"SwabianInstruments.TimeTagger.IteratorBase", 
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


// Type: SwabianInstruments.TimeTagger.Sampler
int CVIFUNC Swab_TimeTag_Sampler__Create(
	Swab_TimeTag_Sampler * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int trigger,
	int * channels,
	ssize_t __channelsLength,
	unsigned int max_triggers,
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

	// Pre-process parameter: trigger
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &trigger;

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

	// Pre-process parameter: max_triggers
	__parameterTypeNames[3] = "System.UInt32";
	__parameterTypes[3] = (CDOTNET_UINT32);
	__parameters[3] = &max_triggers;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_getData(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_getDataAsMask(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDataAsMask", 
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

int CVIFUNC Swab_TimeTag_Sampler_Dispose(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_start(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_startFor(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_startFor_1(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_waitUntilFinished(
	Swab_TimeTag_Sampler __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Sampler_waitUntilFinished_1(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Sampler_stop(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_clear(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_isRunning(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_getCaptureDuration(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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

int CVIFUNC Swab_TimeTag_Sampler_getConfiguration(
	Swab_TimeTag_Sampler __instance,
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
		"SwabianInstruments.TimeTagger.Sampler", 
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


// Type: SwabianInstruments.TimeTagger.Scope
int CVIFUNC Swab_TimeTag_Scope__Create(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Scope__Create_1(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Scope__Create_2(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Scope__Create_3(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_Scope_ready(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_triggered(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_getData(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_getWindowSize(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_Dispose(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_start(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_startFor(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_startFor_1(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_waitUntilFinished(
	Swab_TimeTag_Scope __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.Scope", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Scope_waitUntilFinished_1(
	Swab_TimeTag_Scope __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_Scope_stop(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_clear(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_isRunning(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_getCaptureDuration(
	Swab_TimeTag_Scope __instance,
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

int CVIFUNC Swab_TimeTag_Scope_getConfiguration(
	Swab_TimeTag_Scope __instance,
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
		"SwabianInstruments.TimeTagger.Scope", 
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


// Type: SwabianInstruments.TimeTagger.SoftwareClockState
int CVIFUNC Swab_TimeTag_SoftwareClockState__Create(
	Swab_TimeTag_SoftwareClockState * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_clock_period(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"clock_period", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_clock_period(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"clock_period", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_input_channel(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"input_channel", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_input_channel(
	Swab_TimeTag_SoftwareClockState __instance,
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
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"input_channel", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_ideal_clock_channel(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ideal_clock_channel", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_ideal_clock_channel(
	Swab_TimeTag_SoftwareClockState __instance,
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
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ideal_clock_channel", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_averaging_periods(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"averaging_periods", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_averaging_periods(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"averaging_periods", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_enabled(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"enabled", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_enabled(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"enabled", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_is_locked(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"is_locked", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_is_locked(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"is_locked", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_error_counter(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"error_counter", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_error_counter(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"error_counter", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_last_ideal_clock_event(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"last_ideal_clock_event", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_last_ideal_clock_event(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"last_ideal_clock_event", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_period_error(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"period_error", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_period_error(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"period_error", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_phase_error_estimation(
	Swab_TimeTag_SoftwareClockState __instance,
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
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"phase_error_estimation", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_phase_error_estimation(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"phase_error_estimation", 
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

int CVIFUNC Swab_TimeTag_SoftwareClockState_Dispose(
	Swab_TimeTag_SoftwareClockState __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SoftwareClockState", 
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


// Type: SwabianInstruments.TimeTagger.StartStop
int CVIFUNC Swab_TimeTag_StartStop__Create(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_StartStop__Create_1(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_StartStop__Create_2(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_StartStop_getData(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_Dispose(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_start(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_startFor(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_startFor_1(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_waitUntilFinished(
	Swab_TimeTag_StartStop __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.StartStop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_StartStop_waitUntilFinished_1(
	Swab_TimeTag_StartStop __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_StartStop_stop(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_clear(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_isRunning(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_getCaptureDuration(
	Swab_TimeTag_StartStop __instance,
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

int CVIFUNC Swab_TimeTag_StartStop_getConfiguration(
	Swab_TimeTag_StartStop __instance,
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
		"SwabianInstruments.TimeTagger.StartStop", 
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


// Type: SwabianInstruments.TimeTagger.SynchronizedMeasurements
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements__Create(
	Swab_TimeTag_SynchronizedMeasurements * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_Dispose(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_registerMeasurement(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_IteratorBase measurement,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_unregisterMeasurement(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_IteratorBase measurement,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_clear(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_start(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_stop(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_startFor(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_startFor_1(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_waitUntilFinished(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SynchronizedMeasurements", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_waitUntilFinished_1(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_isRunning(
	Swab_TimeTag_SynchronizedMeasurements __instance,
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

int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_getTagger(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_TimeTaggerBase * __returnValue,
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


// Type: SwabianInstruments.TimeTagger.SyntheticSingleTag
int CVIFUNC Swab_TimeTag_SyntheticSingleTag__Create(
	Swab_TimeTag_SyntheticSingleTag * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int base_channel,
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

	// Pre-process parameter: base_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &base_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag__Create_1(
	Swab_TimeTag_SyntheticSingleTag * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_trigger(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"trigger", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getChannel(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_Dispose(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_start(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_startFor(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_startFor_1(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_waitUntilFinished(
	Swab_TimeTag_SyntheticSingleTag __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_waitUntilFinished_1(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_stop(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_clear(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_isRunning(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getCaptureDuration(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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

int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getConfiguration(
	Swab_TimeTag_SyntheticSingleTag __instance,
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
		"SwabianInstruments.TimeTagger.SyntheticSingleTag", 
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


// Type: SwabianInstruments.TimeTagger.TT
int CVIFUNC Swab_TimeTag_TT__Create(
	Swab_TimeTag_TT * __instance,
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

int CVIFUNC Swab_TimeTag_TT_Get_CHANNEL_UNUSED(
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
		CDOTNET_GET_PROPERTY, 
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

int CVIFUNC Swab_TimeTag_TT_Get_CHANNEL_UNUSED_OLD(
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
		CDOTNET_GET_PROPERTY, 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_AUTO(
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
		CDOTNET_GET_PROPERTY, 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_ZERO(
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
		CDOTNET_GET_PROPERTY, 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_ONE(
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
		CDOTNET_GET_PROPERTY, 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_RISING_AND_FALLING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_PROPERTY, 
		"TT_CHANNEL_RISING_AND_FALLING_EDGES", 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_RISING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_PROPERTY, 
		"TT_CHANNEL_RISING_EDGES", 
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

int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_FALLING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_GET_PROPERTY, 
		"TT_CHANNEL_FALLING_EDGES", 
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

int CVIFUNC Swab_TimeTag_TT_add_logEvent(
	Swab_TimeTag_TT_TimeTaggerLogger value,
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

int CVIFUNC Swab_TimeTag_TT_remove_logEvent(
	Swab_TimeTag_TT_TimeTaggerLogger value,
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

int CVIFUNC Swab_TimeTag_TT_addLogger(
	Swab_TimeTag_TT_TimeTaggerLogger handler,
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

int CVIFUNC Swab_TimeTag_TT_setLogger(
	Swab_TimeTag_TT_TimeTaggerLogger handler,
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

int CVIFUNC Swab_TimeTag_TT_removeAllLogger(
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

int CVIFUNC Swab_TimeTag_TT_hasLogger(
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

int CVIFUNC Swab_TimeTag_TT_freeTimeTagger(
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TT_getVersion(
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

int CVIFUNC Swab_TimeTag_TT_createTimeTagger(
	char * serial,
	Swab_TimeTag_Resolution resolution,
	Swab_TimeTag_TimeTagger * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle resolution__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &serial;

	// Pre-process parameter: resolution
	__errChk(SwabianInstruments_TimeTagger_Resolution__Create(
		&resolution, 
		&resolution__, 
		__exception));
	__parameterTypeNames[1] = "SwabianInstruments.TimeTagger.Resolution";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &resolution__;

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
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (resolution__)
		CDotNetDiscardHandle(resolution__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_TT_createTimeTagger_1(
	char * serial,
	Swab_TimeTag_TimeTagger * __returnValue,
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

int CVIFUNC Swab_TimeTag_TT_createTimeTagger_2(
	Swab_TimeTag_TimeTagger * __returnValue,
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

int CVIFUNC Swab_TimeTag_TT_createTimeTaggerVirtual(
	Swab_TimeTag_TimeTaggerVirtual * __returnValue,
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

int CVIFUNC Swab_TimeTag_TT_createTimeTaggerNetwork(
	char * address,
	Swab_TimeTag_TimeTaggerNetwork * __returnValue,
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


	// Pre-process parameter: address
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &address;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"createTimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TT_createTimeTaggerNetwork_1(
	Swab_TimeTag_TimeTaggerNetwork * __returnValue,
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
		"createTimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TT_setCustomBitFileName(
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

int CVIFUNC Swab_TimeTag_TT_scanTimeTagger(
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

int CVIFUNC Swab_TimeTag_TT_getTimeTaggerServerInfo(
	char * address,
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


	// Pre-process parameter: address
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &address;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"getTimeTaggerServerInfo", 
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

int CVIFUNC Swab_TimeTag_TT_getTimeTaggerServerInfo_1(
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
		"getTimeTaggerServerInfo", 
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

int CVIFUNC Swab_TimeTag_TT_scanTimeTaggerServers(
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
		"scanTimeTaggerServers", 
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

int CVIFUNC Swab_TimeTag_TT_getTimeTaggerModel(
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

int CVIFUNC Swab_TimeTag_TT_setTimeTaggerChannelNumberScheme(
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

int CVIFUNC Swab_TimeTag_TT_getTimeTaggerChannelNumberScheme(
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

int CVIFUNC Swab_TimeTag_TT_hasTimeTaggerVirtualLicense(
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

int CVIFUNC Swab_TimeTag_TT_flashLicense(
	char * serial,
	char * license,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &serial;

	// Pre-process parameter: license
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &license;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"flashLicense", 
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

int CVIFUNC Swab_TimeTag_TT_extractDeviceLicense(
	char * license,
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


	// Pre-process parameter: license
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &license;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"extractDeviceLicense", 
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

int CVIFUNC Swab_TimeTag_TT_setLanguageInfo(
	unsigned int pw,
	Swab_TimeTag_LanguageUsed language,
	char * version,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle language__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pw
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &pw;

	// Pre-process parameter: language
	__errChk(SwabianInstruments_TimeTagger_LanguageUsed__Create(
		&language, 
		&language__, 
		__exception));
	__parameterTypeNames[1] = "SwabianInstruments.TimeTagger.LanguageUsed";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &language__;

	// Pre-process parameter: version
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &version;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setLanguageInfo", 
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
	if (language__)
		CDotNetDiscardHandle(language__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TT_setFrontend(
	Swab_TimeTag_FrontendType frontend,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle frontend__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: frontend
	__errChk(SwabianInstruments_TimeTagger_FrontendType__Create(
		&frontend, 
		&frontend__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.FrontendType";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &frontend__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setFrontend", 
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
	if (frontend__)
		CDotNetDiscardHandle(frontend__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TT_setUsageStatisticsStatus(
	Swab_TimeTag_UsageStatisticsStatus new_status,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle new_status__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: new_status
	__errChk(SwabianInstruments_TimeTagger_UsageStatisticsStatus__Create(
		&new_status, 
		&new_status__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.UsageStatisticsStatus";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &new_status__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"setUsageStatisticsStatus", 
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
	if (new_status__)
		CDotNetDiscardHandle(new_status__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TT_getUsageStatisticsStatus(
	Swab_TimeTag_UsageStatisticsStatus * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"getUsageStatisticsStatus", 
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

int CVIFUNC Swab_TimeTag_TT_getUsageStatisticsReport(
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
		"getUsageStatisticsReport", 
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

int CVIFUNC Swab_TimeTag_TT_mergeStreamFiles(
	char * output_filename,
	char ** input_filenames,
	ssize_t __input_filenamesLength,
	int * channel_offsets,
	ssize_t __channel_offsetsLength,
	__int64 * time_offsets,
	ssize_t __time_offsetsLength,
	int overlap_only,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle input_filenames__ = 0;
	CDotNetHandle channel_offsets__ = 0;
	CDotNetHandle time_offsets__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: output_filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &output_filename;

	// Pre-process parameter: input_filenames
	if (input_filenames)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__input_filenamesLength, 
			input_filenames, 
			&input_filenames__));
	__parameterTypeNames[1] = "System.String[]";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[1] = &input_filenames__;

	// Pre-process parameter: channel_offsets
	if (channel_offsets)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channel_offsetsLength, 
			channel_offsets, 
			&channel_offsets__));
	__parameterTypeNames[2] = "System.Int32[]";
	__parameterTypes[2] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[2] = &channel_offsets__;

	// Pre-process parameter: time_offsets
	if (time_offsets)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__time_offsetsLength, 
			time_offsets, 
			&time_offsets__));
	__parameterTypeNames[3] = "System.Int64[]";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[3] = &time_offsets__;

	// Pre-process parameter: overlap_only
	__parameterTypeNames[4] = "System.Boolean";
	__parameterTypes[4] = (CDOTNET_BOOLEAN);
	__parameters[4] = &overlap_only;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"mergeStreamFiles", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (input_filenames__)
		CDotNetDiscardHandle(input_filenames__);
	if (channel_offsets__)
		CDotNetDiscardHandle(channel_offsets__);
	if (time_offsets__)
		CDotNetDiscardHandle(time_offsets__);
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger__Create(
	Swab_TimeTag_TT_TimeTaggerLogger * __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Get_Method(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Get_Target(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Invoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_BeginInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_EndInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetObjectData(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Equals(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetInvocationList(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetHashCode(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_DynamicInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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

int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Clone(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
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
int CVIFUNC Swab_TimeTag_TimeDifferences__Create(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_1(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_2(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_3(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_4(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_5(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences__Create_6(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getData(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getIndex(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_setMaxCounts(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getCounts(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getHistogramIndex(
	Swab_TimeTag_TimeDifferences __instance,
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
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getHistogramIndex", 
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

int CVIFUNC Swab_TimeTag_TimeDifferences_ready(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_Dispose(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_start(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_startFor(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_startFor_1(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_waitUntilFinished(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferences", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeDifferences_waitUntilFinished_1(
	Swab_TimeTag_TimeDifferences __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeDifferences_stop(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_clear(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_isRunning(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getCaptureDuration(
	Swab_TimeTag_TimeDifferences __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferences_getConfiguration(
	Swab_TimeTag_TimeDifferences __instance,
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
		"SwabianInstruments.TimeTagger.TimeDifferences", 
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


// Type: SwabianInstruments.TimeTagger.TimeDifferencesND
int CVIFUNC Swab_TimeTag_TimeDifferencesND__Create(
	Swab_TimeTag_TimeDifferencesND * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int * next_channels,
	ssize_t __next_channelsLength,
	int * sync_channels,
	ssize_t __sync_channelsLength,
	int * n_histograms,
	ssize_t __n_histogramsLength,
	__int64 binwidth,
	int n_bins,
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
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_getData(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_getIndex(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_Dispose(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_start(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_startFor(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_startFor_1(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_waitUntilFinished(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_waitUntilFinished_1(
	Swab_TimeTag_TimeDifferencesND __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_stop(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_clear(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_isRunning(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_getCaptureDuration(
	Swab_TimeTag_TimeDifferencesND __instance,
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

int CVIFUNC Swab_TimeTag_TimeDifferencesND_getConfiguration(
	Swab_TimeTag_TimeDifferencesND __instance,
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
		"SwabianInstruments.TimeTagger.TimeDifferencesND", 
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


// Type: SwabianInstruments.TimeTagger.TimeTagStream
int CVIFUNC Swab_TimeTag_TimeTagStream__Create(
	Swab_TimeTag_TimeTagStream * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	unsigned __int64 n_max_events,
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
	__parameterTypeNames[1] = "System.UInt64";
	__parameterTypes[1] = (CDOTNET_UINT64);
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

int CVIFUNC Swab_TimeTag_TimeTagStream_getCounts(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_getData(
	Swab_TimeTag_TimeTagStream __instance,
	Swab_TimeTag_TimeTagStreamBuffer * __returnValue,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_Dispose(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_start(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_startFor(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_startFor_1(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_waitUntilFinished(
	Swab_TimeTag_TimeTagStream __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagStream", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeTagStream_waitUntilFinished_1(
	Swab_TimeTag_TimeTagStream __instance,
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
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TimeTagStream_stop(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_clear(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_isRunning(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_getCaptureDuration(
	Swab_TimeTag_TimeTagStream __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStream_getConfiguration(
	Swab_TimeTag_TimeTagStream __instance,
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
		"SwabianInstruments.TimeTagger.TimeTagStream", 
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


// Type: SwabianInstruments.TimeTagger.TimeTagStreamBuffer
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_size(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_size(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned __int64 value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.UInt64";
	__parameterTypes[0] = (CDOTNET_UINT64);
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_hasOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_hasOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_tStart(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_tStart(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_tGetData(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_tGetData(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Dispose(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getChannels(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getTimestamps(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getMissedEvents(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getEventTypes(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
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
int CVIFUNC Swab_TimeTag_TimeTagger_reset(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_isChannelRegistered(
	Swab_TimeTag_TimeTagger __instance,
	int chan,
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


	// Pre-process parameter: chan
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &chan;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isChannelRegistered", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getTestSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOutSignal(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int divider,
	double duty_cycle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channel;

	// Pre-process parameter: divider
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &divider;

	// Pre-process parameter: duty_cycle
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &duty_cycle;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setAuxOutSignal", 
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
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOutSignal_1(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int divider,
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
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &divider;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setAuxOutSignal", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOutSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_getAuxOutSignalDivider", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOutSignalDutyCycle(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_getAuxOutSignalDutyCycle", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOut(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_setAuxOut", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOut(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_getAuxOut", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setFanSpeed(
	Swab_TimeTag_TimeTagger __instance,
	double percentage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: percentage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &percentage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setFanSpeed", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setFanSpeed_1(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_setFanSpeed", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_measureTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_measureTriggerLevel", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getHardwareDelayCompensation(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setInputMux(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getInputMux(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setConditionalFilter(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setConditionalFilter_1(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_clearConditionalFilter(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setNormalization(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channels__;

	// Pre-process parameter: state
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setNormalization", 
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
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_getNormalization(
	Swab_TimeTag_TimeTagger __instance,
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
		"getNormalization", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setHardwareBufferSize(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getHardwareBufferSize(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setStreamBlockSize(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getStreamBlockSizeEvents(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getStreamBlockSizeLatency(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setEventDivider(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getEventDivider(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_autoCalibration(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getSerial(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getModel(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getChannelNumberScheme(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDACRange(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDistributionCount(
	Swab_TimeTag_TimeTagger __instance,
	unsigned __int64 ** __returnValue,
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
	__returnValueTypeId = CDOTNET_UINT64 | CDOTNET_ARRAY;

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
				CDOTNET_UINT64, 
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
			CDOTNET_UINT64, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_getDistributionPSecs(
	Swab_TimeTag_TimeTagger __instance,
	double ** __returnValue,
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
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

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
				CDOTNET_DOUBLE, 
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
			CDOTNET_DOUBLE, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_getChannelList(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_ChannelEdge type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle type__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: type
	__errChk(SwabianInstruments_TimeTagger_ChannelEdge__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.ChannelEdge";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

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
	if (type__)
		CDotNetDiscardHandle(type__);
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

int CVIFUNC Swab_TimeTag_TimeTagger_getChannelList_1(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getPsPerClock(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getPcbVersion(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getFirmwareVersion(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockSource(
	Swab_TimeTag_TimeTagger __instance,
	int source,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: source
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &source;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setClockSource", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getClockSource(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_getClockSource", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockAutoSelect(
	Swab_TimeTag_TimeTagger __instance,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: enabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setClockAutoSelect", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getClockAutoSelect(
	Swab_TimeTag_TimeTagger __instance,
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
		"xtra_getClockAutoSelect", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockOut(
	Swab_TimeTag_TimeTagger __instance,
	int enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: enabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"xtra_setClockOut", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getSensorData(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setLED(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_disableLEDs(
	Swab_TimeTag_TimeTagger __instance,
	int disabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: disabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &disabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"disableLEDs", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDeviceLicense(
	Swab_TimeTag_TimeTagger __instance,
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
		"getDeviceLicense", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_factoryAccess(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int pw,
	unsigned int addr,
	unsigned int data,
	unsigned int mask,
	int use_wb,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
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

	// Pre-process parameter: use_wb
	__parameterTypeNames[4] = "System.Boolean";
	__parameterTypes[4] = (CDOTNET_BOOLEAN);
	__parameters[4] = &use_wb;

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
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_factoryAccess_1(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setSoundFrequency(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int freq_hz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: freq_hz
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &freq_hz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoundFrequency", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_enableFpgaLink(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	char * destination_mac,
	Swab_TimeTag_FpgaLinkInterface interface_,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle channels__ = 0;
	CDotNetHandle interface___ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channels__;

	// Pre-process parameter: destination_mac
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &destination_mac;

	// Pre-process parameter: interface_
	__errChk(SwabianInstruments_TimeTagger_FpgaLinkInterface__Create(
		&interface_, 
		&interface___, 
		__exception));
	__parameterTypeNames[2] = "SwabianInstruments.TimeTagger.FpgaLinkInterface";
	__parameterTypes[2] = (CDOTNET_ENUM);
	__parameters[2] = &interface___;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"enableFpgaLink", 
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
	if (channels__)
		CDotNetDiscardHandle(channels__);
	if (interface___)
		CDotNetDiscardHandle(interface___);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_enableFpgaLink_1(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	char * destination_mac,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channels__;

	// Pre-process parameter: destination_mac
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &destination_mac;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"enableFpgaLink", 
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
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_disableFpgaLink(
	Swab_TimeTag_TimeTagger __instance,
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
		"disableFpgaLink", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_startServer(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	int * channels,
	ssize_t __channelsLength,
	unsigned int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle access_mode__ = 0;
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: access_mode
	__errChk(SwabianInstruments_TimeTagger_AccessMode__Create(
		&access_mode, 
		&access_mode__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.AccessMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &access_mode__;

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

	// Pre-process parameter: port
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startServer", 
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
	if (access_mode__)
		CDotNetDiscardHandle(access_mode__);
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_startServer_1(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle access_mode__ = 0;
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: access_mode
	__errChk(SwabianInstruments_TimeTagger_AccessMode__Create(
		&access_mode, 
		&access_mode__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.AccessMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &access_mode__;

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

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startServer", 
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
	if (access_mode__)
		CDotNetDiscardHandle(access_mode__);
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_startServer_2(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle access_mode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: access_mode
	__errChk(SwabianInstruments_TimeTagger_AccessMode__Create(
		&access_mode, 
		&access_mode__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.AccessMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &access_mode__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"startServer", 
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
	if (access_mode__)
		CDotNetDiscardHandle(access_mode__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_isServerRunning(
	Swab_TimeTag_TimeTagger __instance,
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
		"isServerRunning", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_stopServer(
	Swab_TimeTag_TimeTagger __instance,
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
		"stopServer", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setTimeTaggerNetworkStreamCompression(
	Swab_TimeTag_TimeTagger __instance,
	int active,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: active
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &active;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTimeTaggerNetworkStreamCompression", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setInputImpedanceHigh(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int high_impedance,
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

	// Pre-process parameter: high_impedance
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &high_impedance;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputImpedanceHigh", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getInputImpedanceHigh(
	Swab_TimeTag_TimeTagger __instance,
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
		"getInputImpedanceHigh", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setInputHysteresis(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int value,
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

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputHysteresis", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getInputHysteresis(
	Swab_TimeTag_TimeTagger __instance,
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
		"getInputHysteresis", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_Dispose(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getFence(
	Swab_TimeTag_TimeTagger __instance,
	int alloc_fence,
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


	// Pre-process parameter: alloc_fence
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &alloc_fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getFence_1(
	Swab_TimeTag_TimeTagger __instance,
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
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_waitForFence(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int fence,
	__int64 timeout,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process parameter: timeout
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_waitForFence_1(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int fence,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_sync(
	Swab_TimeTag_TimeTagger __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_sync_1(
	Swab_TimeTag_TimeTagger __instance,
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
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getInvertedChannel(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_isUnusedChannel(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getConfiguration(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setInputDelay(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setDelayHardware(
	Swab_TimeTag_TimeTagger __instance,
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
		"setDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setDelaySoftware(
	Swab_TimeTag_TimeTagger __instance,
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
		"setDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getInputDelay(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDelaySoftware(
	Swab_TimeTag_TimeTagger __instance,
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
		"getDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDelayHardware(
	Swab_TimeTag_TimeTagger __instance,
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
		"getDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setDeadtime(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getDeadtime(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignal(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignal_1(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getTestSignal(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Pre-process parameter: wait_until_locked
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &wait_until_locked;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_1(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_2(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_3(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_disableSoftwareClock(
	Swab_TimeTag_TimeTagger __instance,
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
		"disableSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getSoftwareClockState(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
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
		"SwabianInstruments.TimeTagger.TimeTagger", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSoftwareClockState", 
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

int CVIFUNC Swab_TimeTag_TimeTagger_getOverflows(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_clearOverflows(
	Swab_TimeTag_TimeTagger __instance,
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

int CVIFUNC Swab_TimeTag_TimeTagger_getOverflowsAndClear(
	Swab_TimeTag_TimeTagger __instance,
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


// Type: SwabianInstruments.TimeTagger.TimeTaggerBase
int CVIFUNC Swab_TimeTag_TimeTaggerBase_Dispose(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getFence(
	Swab_TimeTag_TimeTaggerBase __instance,
	int alloc_fence,
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


	// Pre-process parameter: alloc_fence
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &alloc_fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getFence_1(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_waitForFence(
	Swab_TimeTag_TimeTaggerBase __instance,
	unsigned int fence,
	__int64 timeout,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process parameter: timeout
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_waitForFence_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	unsigned int fence,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_sync(
	Swab_TimeTag_TimeTaggerBase __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_sync_1(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getInvertedChannel(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_isUnusedChannel(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getConfiguration(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setInputDelay(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDelayHardware(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"setDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDelaySoftware(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"setDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getInputDelay(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDelaySoftware(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"getDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDelayHardware(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"getDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDeadtime(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDeadtime(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setTestSignal(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setTestSignal_1(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getTestSignal(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Pre-process parameter: wait_until_locked
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &wait_until_locked;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerBase __instance,
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
		"disableSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerBase __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
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
		"SwabianInstruments.TimeTagger.TimeTaggerBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSoftwareClockState", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getOverflows(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_clearOverflows(
	Swab_TimeTag_TimeTaggerBase __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerBase_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerBase __instance,
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


// Type: SwabianInstruments.TimeTagger.TimeTaggerNetwork
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_isConnected(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isConnected", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTriggerLevel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTriggerLevel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setConditionalFilter(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setConditionalFilter_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearConditionalFilter(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignalDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTestSignalDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTestSignal(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelayClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 time,
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

	// Pre-process parameter: time
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &time;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDelayClient", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelayClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDelayClient", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getHardwareDelayCompensation(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setNormalization(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * channels,
	ssize_t __channelsLength,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle channels__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channels
	if (channels)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT32, 
			1, 
			0, 
			&__channelsLength, 
			channels, 
			&channels__));
	__parameterTypeNames[0] = "System.Int32[]";
	__parameterTypes[0] = (CDOTNET_INT32 | CDOTNET_ARRAY);
	__parameters[0] = &channels__;

	// Pre-process parameter: state
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setNormalization", 
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
	if (channels__)
		CDotNetDiscardHandle(channels__);
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getNormalization(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getNormalization", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setHardwareBufferSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getHardwareBufferSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setStreamBlockSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getStreamBlockSizeEvents(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getStreamBlockSizeLatency(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setEventDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getEventDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSerial(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getModel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelNumberScheme(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDACRange(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelList(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	Swab_TimeTag_ChannelEdge type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle type__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: type
	__errChk(SwabianInstruments_TimeTagger_ChannelEdge__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.ChannelEdge";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32 | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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
	if (type__)
		CDotNetDiscardHandle(type__);
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelList_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getPsPerClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getPcbVersion(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFirmwareVersion(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSensorData(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setLED(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDeviceLicense(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDeviceLicense", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoundFrequency(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int freq_hz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: freq_hz
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &freq_hz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoundFrequency", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTimeTaggerNetworkStreamCompression(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int active,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: active
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &active;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setTimeTaggerNetworkStreamCompression", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowsClient", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearOverflowsClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"clearOverflowsClient", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsAndClearClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getOverflowsAndClearClient", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputImpedanceHigh(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int high_impedance,
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

	// Pre-process parameter: high_impedance
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &high_impedance;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputImpedanceHigh", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputImpedanceHigh(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputImpedanceHigh", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputHysteresis(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int value,
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

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setInputHysteresis", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputHysteresis(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getInputHysteresis", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_Dispose(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFence(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int alloc_fence,
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


	// Pre-process parameter: alloc_fence
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &alloc_fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFence_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_waitForFence(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int fence,
	__int64 timeout,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process parameter: timeout
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_waitForFence_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int fence,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_sync(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_sync_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInvertedChannel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_isUnusedChannel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConfiguration(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputDelay(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelayHardware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelaySoftware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputDelay(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelaySoftware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelayHardware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDeadtime(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDeadtime(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignal(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignal_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Pre-process parameter: wait_until_locked
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &wait_until_locked;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"disableSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSoftwareClockState", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflows(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearOverflows(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerNetwork __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerNetwork", 
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


// Type: SwabianInstruments.TimeTagger.TimeTaggerVirtual
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_3(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_stop(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_reset(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	__int64 timeout,
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
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setReplaySpeed(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getReplaySpeed(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setConditionalFilter(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_clearConditionalFilter(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getChannelList(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_Dispose(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getFence(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int alloc_fence,
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


	// Pre-process parameter: alloc_fence
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &alloc_fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getFence_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForFence(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned int fence,
	__int64 timeout,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process parameter: timeout
	__parameterTypeNames[1] = "System.Int64";
	__parameterTypes[1] = (CDOTNET_INT64);
	__parameters[1] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForFence_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned int fence,
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


	// Pre-process parameter: fence
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &fence;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitForFence", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_sync(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_sync_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"sync", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getInvertedChannel(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_isUnusedChannel(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConfiguration(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setInputDelay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDelayHardware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"setDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDelaySoftware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"setDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getInputDelay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDelaySoftware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"getDelaySoftware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDelayHardware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"getDelayHardware", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDeadtime(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDeadtime(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setTestSignal(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setTestSignal_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getTestSignal(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Pre-process parameter: wait_until_locked
	__parameterTypeNames[3] = "System.Boolean";
	__parameterTypes[3] = (CDOTNET_BOOLEAN);
	__parameters[3] = &wait_until_locked;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Pre-process parameter: averaging_periods
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &averaging_periods;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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
	return __error;
}

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Pre-process parameter: input_frequency
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &input_frequency;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: input_channel
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &input_channel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"setSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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
		"disableSoftwareClock", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
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
		"SwabianInstruments.TimeTagger.TimeTaggerVirtual", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getSoftwareClockState", 
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getOverflows(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_clearOverflows(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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

int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerVirtual __instance,
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


// Type: SwabianInstruments.TimeTagger.TriggerOnCountrate
int CVIFUNC Swab_TimeTag_TriggerOnCountrate__Create(
	Swab_TimeTag_TriggerOnCountrate * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double reference_countrate,
	double hysteresis,
	__int64 time_window,
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

	// Pre-process parameter: input_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &input_channel;

	// Pre-process parameter: reference_countrate
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &reference_countrate;

	// Pre-process parameter: hysteresis
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &hysteresis;

	// Pre-process parameter: time_window
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &time_window;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannelAbove(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannelAbove", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannelBelow(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getChannelBelow", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannels(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isAbove(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isAbove", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isBelow(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isBelow", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getCurrentCountrate(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"getCurrentCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_injectCurrentState(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"injectCurrentState", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_Dispose(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_start(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_startFor(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_startFor_1(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_waitUntilFinished(
	Swab_TimeTag_TriggerOnCountrate __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_waitUntilFinished_1(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_stop(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_clear(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isRunning(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getCaptureDuration(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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

int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getConfiguration(
	Swab_TimeTag_TriggerOnCountrate __instance,
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
		"SwabianInstruments.TimeTagger.TriggerOnCountrate", 
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


// Type: SwabianInstruments.TimeTagger.CoincidencesFactory
int CVIFUNC Swab_TimeTag_CoincidencesFactory__Create(
	Swab_TimeTag_CoincidencesFactory * __instance,
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

int CVIFUNC Swab_TimeTag_CoincidencesFactory_addCoincidenceGroup(
	Swab_TimeTag_CoincidencesFactory __instance,
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

int CVIFUNC Swab_TimeTag_CoincidencesFactory_getChannels(
	Swab_TimeTag_CoincidencesFactory __instance,
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

int CVIFUNC Swab_TimeTag_CoincidencesFactory_addCoincidenceGroups(
	Swab_TimeTag_CoincidencesFactory __instance,
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

int CVIFUNC Swab_TimeTag_CoincidencesFactory_createCoincidences(
	Swab_TimeTag_CoincidencesFactory __instance,
	Swab_TimeTag_TimeTagger tagger,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp coincidenceType,
	Swab_TimeTag_Coincidences * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle coincidenceType__ = 0;
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

	// Pre-process parameter: coincidenceType
	__errChk(SwabianInstruments_TimeTagger_CoincidenceTimestamp__Create(
		&coincidenceType, 
		&coincidenceType__, 
		__exception));
	__parameterTypeNames[2] = "SwabianInstruments.TimeTagger.CoincidenceTimestamp";
	__parameterTypes[2] = (CDOTNET_ENUM);
	__parameters[2] = &coincidenceType__;

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
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (coincidenceType__)
		CDotNetDiscardHandle(coincidenceType__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_CoincidencesFactory_createCoincidences_1(
	Swab_TimeTag_CoincidencesFactory __instance,
	Swab_TimeTag_TimeTagger tagger,
	__int64 coincidenceWindow,
	Swab_TimeTag_Coincidences * __returnValue,
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


// Type: SwabianInstruments.TimeTagger.CustomMeasurement
int CVIFUNC Swab_TimeTag_CustomMeasurement__Create(
	Swab_TimeTag_CustomMeasurement * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_register_channel(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_unregister_channel(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_finalize_init(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_is_running(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement__lock(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement__unlock(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_Dispose(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_start(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_startFor(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_startFor_1(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_waitUntilFinished(
	Swab_TimeTag_CustomMeasurement __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_waitUntilFinished_1(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_stop(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_clear(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_isRunning(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_getCaptureDuration(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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

int CVIFUNC Swab_TimeTag_CustomMeasurement_getConfiguration(
	Swab_TimeTag_CustomMeasurement __instance,
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
		"SwabianInstruments.TimeTagger.CustomMeasurement", 
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


// Type: SwabianInstruments.TimeTagger.FlimBase
int CVIFUNC Swab_TimeTag_FlimBase__Create(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	int pre_initialize,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Pre-process parameter: pre_initialize
	__parameterTypeNames[11] = "System.Boolean";
	__parameterTypes[11] = (CDOTNET_BOOLEAN);
	__parameters[11] = &pre_initialize;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		0, 
		0, 
		__instance, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase__Create_1(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	unsigned int n_frame_average,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[11] = {0};
	unsigned int __parameterTypes[11];
	void * __parameters[11];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Pre-process parameter: n_frame_average
	__parameterTypeNames[10] = "System.UInt32";
	__parameterTypes[10] = (CDOTNET_UINT32);
	__parameters[10] = &n_frame_average;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		0, 
		0, 
		__instance, 
		11, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase__Create_2(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	unsigned int finish_after_outputframe,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Pre-process parameter: finish_after_outputframe
	__parameterTypeNames[9] = "System.UInt32";
	__parameterTypes[9] = (CDOTNET_UINT32);
	__parameters[9] = &finish_after_outputframe;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		0, 
		0, 
		__instance, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase__Create_3(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];

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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Pre-process parameter: frame_begin_channel
	__parameterTypeNames[8] = "System.Int32";
	__parameterTypes[8] = (CDOTNET_INT32);
	__parameters[8] = &frame_begin_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		0, 
		0, 
		__instance, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase__Create_4(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
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

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Pre-process parameter: pixel_end_channel
	__parameterTypeNames[7] = "System.Int32";
	__parameterTypes[7] = (CDOTNET_INT32);
	__parameters[7] = &pixel_end_channel;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase__Create_5(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
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

	// Pre-process parameter: start_channel
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &start_channel;

	// Pre-process parameter: click_channel
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &click_channel;

	// Pre-process parameter: pixel_begin_channel
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &pixel_begin_channel;

	// Pre-process parameter: n_pixels
	__parameterTypeNames[4] = "System.UInt32";
	__parameterTypes[4] = (CDOTNET_UINT32);
	__parameters[4] = &n_pixels;

	// Pre-process parameter: n_bins
	__parameterTypeNames[5] = "System.UInt32";
	__parameterTypes[5] = (CDOTNET_UINT32);
	__parameters[5] = &n_bins;

	// Pre-process parameter: binwidth
	__parameterTypeNames[6] = "System.UInt32";
	__parameterTypes[6] = (CDOTNET_UINT32);
	__parameters[6] = &binwidth;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_add_FrameReadyEvent(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"add_FrameReadyEvent", 
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

int CVIFUNC Swab_TimeTag_FlimBase_remove_FrameReadyEvent(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"remove_FrameReadyEvent", 
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

int CVIFUNC Swab_TimeTag_FlimBase_registerOnFrameReadyCallback(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback callback,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: callback
	__parameterTypeNames[0] = "SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &callback;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"registerOnFrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_initialize(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"initialize", 
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

int CVIFUNC Swab_TimeTag_FlimBase_isAcquiring(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"isAcquiring", 
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

int CVIFUNC Swab_TimeTag_FlimBase_Dispose(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_start(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_startFor(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_startFor_1(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_waitUntilFinished(
	Swab_TimeTag_FlimBase __instance,
	__int64 timeout,
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


	// Pre-process parameter: timeout
	__parameterTypeNames[0] = "System.Int64";
	__parameterTypes[0] = (CDOTNET_INT64);
	__parameters[0] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimBase_waitUntilFinished_1(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"waitUntilFinished", 
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

int CVIFUNC Swab_TimeTag_FlimBase_stop(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_clear(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_isRunning(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_getCaptureDuration(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
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

int CVIFUNC Swab_TimeTag_FlimBase_getConfiguration(
	Swab_TimeTag_FlimBase __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase", 
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


// Type: SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback
static int CVICALLBACK SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback(
	void * delegate, void * parameters[], size_t numParameters,
	void * returnValue, void * callbackData, void * reserved)
{
	int __error = 0;
	CDotNetHandle data__ = 0;
	unsigned int * __data = 0;
	ssize_t __dataLengths[1] = {0};
	CDotNetHandle pixel_begin_times__ = 0;
	__int64 * __pixel_begin_times = 0;
	ssize_t __pixel_begin_timesLengths[1] = {0};
	CDotNetHandle pixel_end_times__ = 0;
	__int64 * __pixel_end_times = 0;
	ssize_t __pixel_end_timesLengths[1] = {0};



	// Pre-process parameter: data
	data__ = *(CDotNetHandle*) parameters[1];
	if (data__) {
		__errChk(CDotNetGetArrayLength(
			data__, 
			0, 
			&__dataLengths[0]));
		__errChk(CDotNetGetArrayElements(
			data__, 
			CDOTNET_UINT32, 
			0, 
			&__data));
	}

	// Pre-process parameter: pixel_begin_times
	pixel_begin_times__ = *(CDotNetHandle*) parameters[2];
	if (pixel_begin_times__) {
		__errChk(CDotNetGetArrayLength(
			pixel_begin_times__, 
			0, 
			&__pixel_begin_timesLengths[0]));
		__errChk(CDotNetGetArrayElements(
			pixel_begin_times__, 
			CDOTNET_INT64, 
			0, 
			&__pixel_begin_times));
	}

	// Pre-process parameter: pixel_end_times
	pixel_end_times__ = *(CDotNetHandle*) parameters[3];
	if (pixel_end_times__) {
		__errChk(CDotNetGetArrayLength(
			pixel_end_times__, 
			0, 
			&__pixel_end_timesLengths[0]));
		__errChk(CDotNetGetArrayElements(
			pixel_end_times__, 
			CDOTNET_INT64, 
			0, 
			&__pixel_end_times));
	}

	__errChk(((SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback_t)reserved)(
		callbackData,
		*(unsigned int*) parameters[0],
		__data,
		__dataLengths[0],
		__pixel_begin_times,
		__pixel_begin_timesLengths[0],
		__pixel_end_times,
		__pixel_end_timesLengths[0],
		*(__int64*) parameters[4],
		*(__int64*) parameters[5]));

__Error:
	_CDotNetGenDisposeArray(
		&__data, 
		CDOTNET_UINT32, 
		1, 
		&__dataLengths[0]);
	_CDotNetGenDisposeArray(
		&__pixel_begin_times, 
		CDOTNET_INT64, 
		1, 
		&__pixel_begin_timesLengths[0]);
	_CDotNetGenDisposeArray(
		&__pixel_end_times, 
		CDOTNET_INT64, 
		1, 
		&__pixel_end_timesLengths[0]);
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback__Create(
	Swab_TimeTag_FlimBase_FrameReadyCallback * __instance,
	SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	__errChk(CDotNetCreateDelegate(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
		0, 
		0, 
		SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback, 
		__userCallbackData, 
		__userCallback, 
		__instance, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Get_Method(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Get_Target(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Invoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	unsigned int frame_number,
	unsigned int * data,
	ssize_t __dataLength,
	__int64 * pixel_begin_times,
	ssize_t __pixel_begin_timesLength,
	__int64 * pixel_end_times,
	ssize_t __pixel_end_timesLength,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];
	CDotNetHandle data__ = 0;
	CDotNetHandle pixel_begin_times__ = 0;
	CDotNetHandle pixel_end_times__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	if (data)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT32, 
			1, 
			0, 
			&__dataLength, 
			data, 
			&data__));
	__parameterTypeNames[1] = "System.UInt32[]";
	__parameterTypes[1] = (CDOTNET_UINT32 | CDOTNET_ARRAY);
	__parameters[1] = &data__;

	// Pre-process parameter: pixel_begin_times
	if (pixel_begin_times)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__pixel_begin_timesLength, 
			pixel_begin_times, 
			&pixel_begin_times__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pixel_begin_times__;

	// Pre-process parameter: pixel_end_times
	if (pixel_end_times)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__pixel_end_timesLength, 
			pixel_end_times, 
			&pixel_end_times__));
	__parameterTypeNames[3] = "System.Int64[]";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[3] = &pixel_end_times__;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Invoke", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (data__)
		CDotNetDiscardHandle(data__);
	if (pixel_begin_times__)
		CDotNetDiscardHandle(pixel_begin_times__);
	if (pixel_end_times__)
		CDotNetDiscardHandle(pixel_end_times__);
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_BeginInvoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	unsigned int frame_number,
	unsigned int * data,
	ssize_t __dataLength,
	__int64 * pixel_begin_times,
	ssize_t __pixel_begin_timesLength,
	__int64 * pixel_end_times,
	ssize_t __pixel_end_timesLength,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle data__ = 0;
	CDotNetHandle pixel_begin_times__ = 0;
	CDotNetHandle pixel_end_times__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: frame_number
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &frame_number;

	// Pre-process parameter: data
	if (data)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT32, 
			1, 
			0, 
			&__dataLength, 
			data, 
			&data__));
	__parameterTypeNames[1] = "System.UInt32[]";
	__parameterTypes[1] = (CDOTNET_UINT32 | CDOTNET_ARRAY);
	__parameters[1] = &data__;

	// Pre-process parameter: pixel_begin_times
	if (pixel_begin_times)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__pixel_begin_timesLength, 
			pixel_begin_times, 
			&pixel_begin_times__));
	__parameterTypeNames[2] = "System.Int64[]";
	__parameterTypes[2] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[2] = &pixel_begin_times__;

	// Pre-process parameter: pixel_end_times
	if (pixel_end_times)
		__errChk(CDotNetCreateArray(
			CDOTNET_INT64, 
			1, 
			0, 
			&__pixel_end_timesLength, 
			pixel_end_times, 
			&pixel_end_times__));
	__parameterTypeNames[3] = "System.Int64[]";
	__parameterTypes[3] = (CDOTNET_INT64 | CDOTNET_ARRAY);
	__parameters[3] = &pixel_end_times__;

	// Pre-process parameter: frame_begin_time
	__parameterTypeNames[4] = "System.Int64";
	__parameterTypes[4] = (CDOTNET_INT64);
	__parameters[4] = &frame_begin_time;

	// Pre-process parameter: frame_end_time
	__parameterTypeNames[5] = "System.Int64";
	__parameterTypes[5] = (CDOTNET_INT64);
	__parameters[5] = &frame_end_time;

	// Pre-process parameter: callback
	__parameterTypeNames[6] = "System.AsyncCallback";
	__parameterTypes[6] = (CDOTNET_OBJECT);
	__parameters[6] = &callback;

	// Pre-process parameter: object
	__parameterTypeNames[7] = "System.Object";
	__parameterTypes[7] = (CDOTNET_OBJECT);
	__parameters[7] = &object;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BeginInvoke", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (data__)
		CDotNetDiscardHandle(data__);
	if (pixel_begin_times__)
		CDotNetDiscardHandle(pixel_begin_times__);
	if (pixel_end_times__)
		CDotNetDiscardHandle(pixel_end_times__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_EndInvoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetObjectData(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Equals(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetInvocationList(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetHashCode(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_DynamicInvoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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

int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Clone(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
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
		"SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback", 
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


{



