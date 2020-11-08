// CVI wrapper header file for .NET assembly: SwabianInstruments.TimeTagger, Version=2.6.8.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name:+ mscorlib, Location: C:\Windows\Microsoft.NET\Framework\v4.0.30319\mscorlib.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: System_Runtime_Serialization_StreamingContext, .NET name: System.Runtime.Serialization.StreamingContext, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Runtime_Serialization_SerializationInfo, .NET name: System.Runtime.Serialization.SerializationInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Delegate, .NET name: System.Delegate, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_IAsyncResult, .NET name: System.IAsyncResult, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Reflection_MethodInfo, .NET name: System.Reflection.MethodInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_AsyncCallback, .NET name: System.AsyncCallback, Assembly: mscorlib, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __SwabianInstruments_TimeTagger_AverageChannel * SwabianInstruments_TimeTagger_AverageChannel;
typedef struct __SwabianInstruments_TimeTagger_Coincidence * SwabianInstruments_TimeTagger_Coincidence;
typedef struct __SwabianInstruments_TimeTagger_Coincidences * SwabianInstruments_TimeTagger_Coincidences;
typedef struct __SwabianInstruments_TimeTagger_Combiner * SwabianInstruments_TimeTagger_Combiner;
typedef struct __SwabianInstruments_TimeTagger_ConstantFractionDiscriminator * SwabianInstruments_TimeTagger_ConstantFractionDiscriminator;
typedef struct __SwabianInstruments_TimeTagger_Correlation * SwabianInstruments_TimeTagger_Correlation;
typedef struct __SwabianInstruments_TimeTagger_CountBetweenMarkers * SwabianInstruments_TimeTagger_CountBetweenMarkers;
typedef struct __SwabianInstruments_TimeTagger_Counter * SwabianInstruments_TimeTagger_Counter;
typedef struct __SwabianInstruments_TimeTagger_Countrate * SwabianInstruments_TimeTagger_Countrate;
typedef struct __SwabianInstruments_TimeTagger_CustomMeasurementBase * SwabianInstruments_TimeTagger_CustomMeasurementBase;
typedef struct __SwabianInstruments_TimeTagger_DelayedChannel * SwabianInstruments_TimeTagger_DelayedChannel;
typedef struct __SwabianInstruments_TimeTagger_Dump * SwabianInstruments_TimeTagger_Dump;
typedef struct __SwabianInstruments_TimeTagger_Event * SwabianInstruments_TimeTagger_Event;
typedef struct __SwabianInstruments_TimeTagger_EventGenerator * SwabianInstruments_TimeTagger_EventGenerator;
typedef struct __SwabianInstruments_TimeTagger_FileReader * SwabianInstruments_TimeTagger_FileReader;
typedef struct __SwabianInstruments_TimeTagger_FileWriter * SwabianInstruments_TimeTagger_FileWriter;
typedef struct __SwabianInstruments_TimeTagger_Flim * SwabianInstruments_TimeTagger_Flim;
typedef struct __SwabianInstruments_TimeTagger_FrequencyMultiplier * SwabianInstruments_TimeTagger_FrequencyMultiplier;
typedef struct __SwabianInstruments_TimeTagger_GatedChannel * SwabianInstruments_TimeTagger_GatedChannel;
typedef struct __SwabianInstruments_TimeTagger_Histogram * SwabianInstruments_TimeTagger_Histogram;
typedef struct __SwabianInstruments_TimeTagger_Histogram2D * SwabianInstruments_TimeTagger_Histogram2D;
typedef struct __SwabianInstruments_TimeTagger_HistogramLogBins * SwabianInstruments_TimeTagger_HistogramLogBins;
typedef struct __SwabianInstruments_TimeTagger_Iterator * SwabianInstruments_TimeTagger_Iterator;
typedef struct __SwabianInstruments_TimeTagger_IteratorBase * SwabianInstruments_TimeTagger_IteratorBase;
typedef struct __SwabianInstruments_TimeTagger_Scope * SwabianInstruments_TimeTagger_Scope;
typedef struct __SwabianInstruments_TimeTagger_StartStop * SwabianInstruments_TimeTagger_StartStop;
typedef struct __SwabianInstruments_TimeTagger_SynchronizedMeasurements * SwabianInstruments_TimeTagger_SynchronizedMeasurements;
typedef struct __SwabianInstruments_TimeTagger_TT * SwabianInstruments_TimeTagger_TT;
typedef struct __SwabianInstruments_TimeTagger_TT_TimeTaggerLogger * SwabianInstruments_TimeTagger_TT_TimeTaggerLogger;
typedef struct __System_Reflection_MethodInfo * System_Reflection_MethodInfo;
typedef struct __System_AsyncCallback * System_AsyncCallback;
typedef struct __System_IAsyncResult * System_IAsyncResult;
typedef struct __System_Runtime_Serialization_SerializationInfo * System_Runtime_Serialization_SerializationInfo;
typedef struct __System_Runtime_Serialization_StreamingContext * System_Runtime_Serialization_StreamingContext;
typedef struct __System_Delegate * System_Delegate;
typedef struct __SwabianInstruments_TimeTagger_TimeDifferences * SwabianInstruments_TimeTagger_TimeDifferences;
typedef struct __SwabianInstruments_TimeTagger_TimeDifferencesND * SwabianInstruments_TimeTagger_TimeDifferencesND;
typedef struct __SwabianInstruments_TimeTagger_TimeTagStream * SwabianInstruments_TimeTagger_TimeTagStream;
typedef struct __SwabianInstruments_TimeTagger_TimeTagStreamBuffer * SwabianInstruments_TimeTagger_TimeTagStreamBuffer;
typedef struct __SwabianInstruments_TimeTagger_TimeTagger * SwabianInstruments_TimeTagger_TimeTagger;
typedef struct __SwabianInstruments_TimeTagger_TimeTaggerBase * SwabianInstruments_TimeTagger_TimeTaggerBase;
typedef struct __SwabianInstruments_TimeTagger_TimeTaggerVirtual * SwabianInstruments_TimeTagger_TimeTaggerVirtual;
typedef struct __SwabianInstruments_TimeTagger_CoincidencesFactory * SwabianInstruments_TimeTagger_CoincidencesFactory;

// C wrapper for enumeration type SwabianInstruments.TimeTagger.CoincidenceTimestamp
#ifndef SwabianInstruments_TimeTagger_CoincidenceTimestamp_DEFINED
#define SwabianInstruments_TimeTagger_CoincidenceTimestamp_DEFINED
typedef enum SwabianInstruments_TimeTagger_CoincidenceTimestamp
{
	SwabianInstruments_TimeTagger_CoincidenceTimestamp_Last = 0x0,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp_Average = 0x1,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp_First = 0x2,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp_ListedFirst = 0x3,
} SwabianInstruments_TimeTagger_CoincidenceTimestamp;
#endif // SwabianInstruments_TimeTagger_CoincidenceTimestamp_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.State
#ifndef SwabianInstruments_TimeTagger_State_DEFINED
#define SwabianInstruments_TimeTagger_State_DEFINED
typedef enum SwabianInstruments_TimeTagger_State
{
	SwabianInstruments_TimeTagger_State_UNKNOWN = 0x0,
	SwabianInstruments_TimeTagger_State_HIGH = 0x1,
	SwabianInstruments_TimeTagger_State_LOW = 0x2,
} SwabianInstruments_TimeTagger_State;
#endif // SwabianInstruments_TimeTagger_State_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.LogLevel
#ifndef SwabianInstruments_TimeTagger_LogLevel_DEFINED
#define SwabianInstruments_TimeTagger_LogLevel_DEFINED
typedef enum SwabianInstruments_TimeTagger_LogLevel
{
	SwabianInstruments_TimeTagger_LogLevel_LOGGER_INFO = 0xa,
	SwabianInstruments_TimeTagger_LogLevel_LOGGER_WARNING = 0x1e,
	SwabianInstruments_TimeTagger_LogLevel_LOGGER_ERROR = 0x28,
} SwabianInstruments_TimeTagger_LogLevel;
#endif // SwabianInstruments_TimeTagger_LogLevel_DEFINED


typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t)(void * callbackData,
		int level,
		char * message);


// Global Functions
int CVIFUNC Initialize_SwabianInstruments_TimeTagger(void);
int CVIFUNC Close_SwabianInstruments_TimeTagger(void);

// Type: SwabianInstruments.TimeTagger.AverageChannel
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel__Create(
	SwabianInstruments_TimeTagger_AverageChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTagger tagger,
	int input_channel,
	int * combined_channels,
	ssize_t __combined_channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_getChannel(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_Dispose(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_start(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_startFor(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_startFor_1(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_stop(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_clear(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_isRunning(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_AverageChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_AverageChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Coincidence
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create_1(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence__Create_2(
	SwabianInstruments_TimeTagger_Coincidence * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getChannel(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_setCoincidenceWindow(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getChannels(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_Dispose(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_start(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_startFor(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_startFor_1(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_stop(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_clear(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_isRunning(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidence_getCaptureDuration(
	SwabianInstruments_TimeTagger_Coincidence __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Coincidences
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences__Create(
	SwabianInstruments_TimeTagger_Coincidences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences__Create_1(
	SwabianInstruments_TimeTagger_Coincidences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_setCoincidenceWindow(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_getChannels(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_Dispose(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_start(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_startFor(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_startFor_1(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_stop(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_clear(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_isRunning(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Coincidences_getCaptureDuration(
	SwabianInstruments_TimeTagger_Coincidences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Combiner
int CVIFUNC SwabianInstruments_TimeTagger_Combiner__Create(
	SwabianInstruments_TimeTagger_Combiner * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getChannel(
	SwabianInstruments_TimeTagger_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getData(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_Dispose(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_start(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_startFor(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_startFor_1(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_stop(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_clear(
	SwabianInstruments_TimeTagger_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_isRunning(
	SwabianInstruments_TimeTagger_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Combiner_getCaptureDuration(
	SwabianInstruments_TimeTagger_Combiner __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.ConstantFractionDiscriminator
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator__Create(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 search_window,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_getChannels(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_Dispose(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_start(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_startFor(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_startFor_1(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_stop(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_clear(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_isRunning(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_ConstantFractionDiscriminator_getCaptureDuration(
	SwabianInstruments_TimeTagger_ConstantFractionDiscriminator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Correlation
int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_1(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_2(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation__Create_3(
	SwabianInstruments_TimeTagger_Correlation * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel_1,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getData(
	SwabianInstruments_TimeTagger_Correlation __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getDataNormalized(
	SwabianInstruments_TimeTagger_Correlation __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getIndex(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_Dispose(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_start(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_startFor(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_startFor_1(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_stop(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_clear(
	SwabianInstruments_TimeTagger_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_isRunning(
	SwabianInstruments_TimeTagger_Correlation __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Correlation_getCaptureDuration(
	SwabianInstruments_TimeTagger_Correlation __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CountBetweenMarkers
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	int n_values,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create_1(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers__Create_2(
	SwabianInstruments_TimeTagger_CountBetweenMarkers * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_ready(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getData(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getBinWidths(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getIndex(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_Dispose(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_start(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_startFor(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_startFor_1(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_stop(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_clear(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_isRunning(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CountBetweenMarkers_getCaptureDuration(
	SwabianInstruments_TimeTagger_CountBetweenMarkers __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Counter
int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	int n_values,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create_1(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter__Create_2(
	SwabianInstruments_TimeTagger_Counter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_getData(
	SwabianInstruments_TimeTagger_Counter __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_getIndex(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_Dispose(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_start(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_startFor(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_startFor_1(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_stop(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_clear(
	SwabianInstruments_TimeTagger_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_isRunning(
	SwabianInstruments_TimeTagger_Counter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Counter_getCaptureDuration(
	SwabianInstruments_TimeTagger_Counter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Countrate
int CVIFUNC SwabianInstruments_TimeTagger_Countrate__Create(
	SwabianInstruments_TimeTagger_Countrate * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getData(
	SwabianInstruments_TimeTagger_Countrate __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getCountsTotal(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_Dispose(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_start(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_startFor(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_startFor_1(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_stop(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_clear(
	SwabianInstruments_TimeTagger_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_isRunning(
	SwabianInstruments_TimeTagger_Countrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Countrate_getCaptureDuration(
	SwabianInstruments_TimeTagger_Countrate __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_register_channel(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_unregister_channel(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_finalize_init(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_is_running(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase__lock(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase__unlock(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_Dispose(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_start(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_startFor(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_startFor_1(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_stop(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_clear(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_isRunning(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CustomMeasurementBase_getCaptureDuration(
	SwabianInstruments_TimeTagger_CustomMeasurementBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.DelayedChannel
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel__Create(
	SwabianInstruments_TimeTagger_DelayedChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_getChannel(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_setDelay(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_Dispose(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_start(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_startFor(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_startFor_1(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_stop(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_clear(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_isRunning(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_DelayedChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_DelayedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Dump
int CVIFUNC SwabianInstruments_TimeTagger_Dump__Create(
	SwabianInstruments_TimeTagger_Dump * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump__Create_1(
	SwabianInstruments_TimeTagger_Dump * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_Dispose(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_start(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_startFor(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_startFor_1(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_stop(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_clear(
	SwabianInstruments_TimeTagger_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_isRunning(
	SwabianInstruments_TimeTagger_Dump __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Dump_getCaptureDuration(
	SwabianInstruments_TimeTagger_Dump __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Event
int CVIFUNC SwabianInstruments_TimeTagger_Event__Create(
	SwabianInstruments_TimeTagger_Event * __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Event_Get_time(
	SwabianInstruments_TimeTagger_Event __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Event_Set_time(
	SwabianInstruments_TimeTagger_Event __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Event_Get_state(
	SwabianInstruments_TimeTagger_Event __instance,
	SwabianInstruments_TimeTagger_State * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Event_Set_state(
	SwabianInstruments_TimeTagger_Event __instance,
	SwabianInstruments_TimeTagger_State value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Event_Dispose(
	SwabianInstruments_TimeTagger_Event __instance,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_1(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	unsigned __int64 divider_offset,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_2(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator__Create_3(
	SwabianInstruments_TimeTagger_EventGenerator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_getChannel(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_Dispose(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_start(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_startFor(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_startFor_1(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_stop(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_clear(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_isRunning(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_EventGenerator_getCaptureDuration(
	SwabianInstruments_TimeTagger_EventGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FileReader
int CVIFUNC SwabianInstruments_TimeTagger_FileReader__Create(
	SwabianInstruments_TimeTagger_FileReader * __instance,
	char ** filenames,
	ssize_t __filenamesLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader__Create_1(
	SwabianInstruments_TimeTagger_FileReader * __instance,
	char * filename,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader_Dispose(
	SwabianInstruments_TimeTagger_FileReader __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader_hasData(
	SwabianInstruments_TimeTagger_FileReader __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getData(
	SwabianInstruments_TimeTagger_FileReader __instance,
	unsigned int n_events,
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getConfiguration(
	SwabianInstruments_TimeTagger_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileReader_getLastMarker(
	SwabianInstruments_TimeTagger_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FileWriter
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter__Create(
	SwabianInstruments_TimeTagger_FileWriter * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	char * filename,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_split(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	char * new_filename,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_split_1(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_setMaxFileSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 max_file_size,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getMaxFileSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getTotalEvents(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getTotalSize(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_setMarker(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	char * marker,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_Dispose(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_start(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_startFor(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_startFor_1(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_stop(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_clear(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_isRunning(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FileWriter_getCaptureDuration(
	SwabianInstruments_TimeTagger_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_1(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_2(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim__Create_3(
	SwabianInstruments_TimeTagger_Flim * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_Dispose(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_start(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_startFor(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_startFor_1(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_stop(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_clear(
	SwabianInstruments_TimeTagger_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_getCaptureDuration(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_getData(
	SwabianInstruments_TimeTagger_Flim __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Flim_getIndex(
	SwabianInstruments_TimeTagger_Flim __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FrequencyMultiplier
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier__Create(
	SwabianInstruments_TimeTagger_FrequencyMultiplier * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	int multiplier,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getChannel(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getMultiplier(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_Dispose(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_start(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_startFor(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_startFor_1(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_stop(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_clear(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_isRunning(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_FrequencyMultiplier_getCaptureDuration(
	SwabianInstruments_TimeTagger_FrequencyMultiplier __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.GatedChannel
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel__Create(
	SwabianInstruments_TimeTagger_GatedChannel * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int input_channel,
	int gate_start_channel,
	int gate_stop_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_getChannel(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_Dispose(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_start(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_startFor(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_startFor_1(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_stop(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_clear(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_isRunning(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_GatedChannel_getCaptureDuration(
	SwabianInstruments_TimeTagger_GatedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Histogram
int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_1(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_2(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram__Create_3(
	SwabianInstruments_TimeTagger_Histogram * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_Dispose(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_start(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_startFor(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_startFor_1(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_stop(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_clear(
	SwabianInstruments_TimeTagger_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getCaptureDuration(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_isRunning(
	SwabianInstruments_TimeTagger_Histogram __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getData(
	SwabianInstruments_TimeTagger_Histogram __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram_getIndex(
	SwabianInstruments_TimeTagger_Histogram __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getData(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	ssize_t * ____returnValueLength3,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex_1(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getIndex_2(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_Dispose(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_start(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_startFor(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_startFor_1(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_stop(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_clear(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_isRunning(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Histogram2D_getCaptureDuration(
	SwabianInstruments_TimeTagger_Histogram2D __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.HistogramLogBins
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins__Create(
	SwabianInstruments_TimeTagger_HistogramLogBins * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	double exp_start,
	double exp_stop,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getData(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getDataNormalizedCountsPerPs(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getDataNormalizedG2(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getBinEdges(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_Dispose(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_start(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_startFor(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_startFor_1(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_stop(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_clear(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_isRunning(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_HistogramLogBins_getCaptureDuration(
	SwabianInstruments_TimeTagger_HistogramLogBins __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Iterator
int CVIFUNC SwabianInstruments_TimeTagger_Iterator__Create(
	SwabianInstruments_TimeTagger_Iterator * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_next(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_size(
	SwabianInstruments_TimeTagger_Iterator __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_Dispose(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_start(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_startFor(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_startFor_1(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_stop(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_clear(
	SwabianInstruments_TimeTagger_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_isRunning(
	SwabianInstruments_TimeTagger_Iterator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Iterator_getCaptureDuration(
	SwabianInstruments_TimeTagger_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.IteratorBase
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_Dispose(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_start(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_startFor(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_startFor_1(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_stop(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_clear(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_isRunning(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_IteratorBase_getCaptureDuration(
	SwabianInstruments_TimeTagger_IteratorBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_1(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	int n_traces,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_2(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope__Create_3(
	SwabianInstruments_TimeTagger_Scope * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_ready(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_triggered(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_getWindowSize(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_getData(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_Dispose(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_start(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_startFor(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_startFor_1(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_stop(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_clear(
	SwabianInstruments_TimeTagger_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_isRunning(
	SwabianInstruments_TimeTagger_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_Scope_getCaptureDuration(
	SwabianInstruments_TimeTagger_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.StartStop
int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create_1(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop__Create_2(
	SwabianInstruments_TimeTagger_StartStop * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_getData(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_Dispose(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_start(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_startFor(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_startFor_1(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_stop(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_clear(
	SwabianInstruments_TimeTagger_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_isRunning(
	SwabianInstruments_TimeTagger_StartStop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_StartStop_getCaptureDuration(
	SwabianInstruments_TimeTagger_StartStop __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.SynchronizedMeasurements
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements__Create(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_Dispose(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_registerMeasurement(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_IteratorBase measurement,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_unregisterMeasurement(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_IteratorBase measurement,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_clear(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_start(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_stop(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_startFor(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_startFor_1(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_isRunning(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_SynchronizedMeasurements_getTagger(
	SwabianInstruments_TimeTagger_SynchronizedMeasurements __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TT
int CVIFUNC SwabianInstruments_TimeTagger_TT__Create(
	SwabianInstruments_TimeTagger_TT * __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_add_logEvent(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_remove_logEvent(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_addLogger(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_setLogger(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_removeAllLogger(
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_hasLogger(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_getVersion(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTagger(
	char * serial,
	SwabianInstruments_TimeTagger_TimeTagger * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTagger_1(
	SwabianInstruments_TimeTagger_TimeTagger * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_createTimeTaggerVirtual(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_setCustomBitFileName(
	char * bitFileName,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_freeTimeTagger(
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_freeAllTimeTagger(
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_getTimeTaggerModel(
	char * serial,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_setTimeTaggerChannelNumberScheme(
	int scheme,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_getTimeTaggerChannelNumberScheme(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_hasTimeTaggerVirtualLicense(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_scanTimeTagger(
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TIMETAGGER_VERSION(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__CHANNEL_UNUSED(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__CHANNEL_UNUSED_OLD(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_AUTO(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_ZERO(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_NUMBER_SCHEME_ONE(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_RISING_AND_FALLING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_RISING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT__Get__TT_CHANNEL_FALLING_EDGES(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TT+TimeTaggerLogger
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Create(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger * __instance,
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Get_Method(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Get_Target(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Invoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_BeginInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_EndInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetObjectData(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Equals(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetInvocationList(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_GetHashCode(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_DynamicInvoke(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TT_TimeTaggerLogger_Clone(
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_1(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_2(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_3(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_4(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_5(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences__Create_6(
	SwabianInstruments_TimeTagger_TimeDifferences * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_setMaxCounts(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	unsigned __int64 max_counts,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getCounts(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_ready(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getData(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getIndex(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_Dispose(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_start(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_startFor(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_startFor_1(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_stop(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_clear(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_isRunning(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferences_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeDifferences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getData(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getIndex(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_Dispose(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_start(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_startFor(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_startFor_1(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_stop(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_clear(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_isRunning(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeDifferencesND_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeDifferencesND __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagStream
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream__Create(
	SwabianInstruments_TimeTagger_TimeTagStream * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	unsigned int n_max_events,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream__Create_1(
	SwabianInstruments_TimeTagger_TimeTagStream * __instance,
	SwabianInstruments_TimeTagger_TimeTaggerBase tagger,
	unsigned int n_max_events,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getCounts(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getData(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_Dispose(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_start(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_startFor(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_startFor_1(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_stop(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_clear(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_isRunning(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStream_getCaptureDuration(
	SwabianInstruments_TimeTagger_TimeTagStream __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagStreamBuffer
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer__Create(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer * __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_size(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_size(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned int value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_hasOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_hasOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_tStart(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_tStart(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Get_tGetData(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Set_tGetData(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_Dispose(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getOverflows(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getChannels(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getTimestamps(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getMissedEvents(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagStreamBuffer_getEventTypes(
	SwabianInstruments_TimeTagger_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagger
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_reset(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignalDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int divider,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTestSignalDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTriggerLevel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	double voltage,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTriggerLevel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getHardwareDelayCompensation(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setInputMux(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int mux_mode,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInputMux(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_clearConditionalFilter(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setNormalization(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getNormalization(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setHardwareBufferSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int size,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getHardwareBufferSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setStreamBlockSize(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int max_events,
	int max_latency,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getStreamBlockSizeEvents(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getStreamBlockSizeLatency(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setEventDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	unsigned int divider,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getEventDivider(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getSerial(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getModel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelNumberScheme(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getPsPerClock(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getPcbVersion(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getFirmwareVersion(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getSensorData(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setLED(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	unsigned int bitmask,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_factoryAccess(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	unsigned int pw,
	unsigned int addr,
	unsigned int data,
	unsigned int mask,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setConditionalFilter(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	int hardwareDelayCompensation,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setConditionalFilter_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConditionalFilterTrigger(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConditionalFilterFiltered(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_autoCalibration(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDACRange(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDistributionCount(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDistributionPSecs(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelList(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getChannelList_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_Dispose(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_sync(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getOverflows(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTagger_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTagger __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTaggerBase
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_Dispose(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_sync(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerBase_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTaggerBase __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTaggerVirtual
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	int queue,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_2(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_replay_3(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char * file,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_stop(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	int timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_waitForCompletion_2(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setReplaySpeed(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	double speed,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getReplaySpeed(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_Dispose(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_sync(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getInvertedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_isUnusedChannel(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getConfiguration(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getInputDelay(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getDeadtime(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getTestSignal(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_clearOverflows(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_getOverflowsAndClear(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_TimeTaggerVirtual_setTestSignal_1(
	SwabianInstruments_TimeTagger_TimeTaggerVirtual __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CoincidencesFactory
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory__Create(
	SwabianInstruments_TimeTagger_CoincidencesFactory * __instance,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_addCoincidenceGroup(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	int * array1d,
	ssize_t __array1dLength,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_getChannels(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_addCoincidenceGroups(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	int * array2d,
	ssize_t __array2dLength1,
	ssize_t __array2dLength2,
	CDotNetHandle * __exception);
int CVIFUNC SwabianInstruments_TimeTagger_CoincidencesFactory_createCoincidences(
	SwabianInstruments_TimeTagger_CoincidencesFactory __instance,
	SwabianInstruments_TimeTagger_TimeTagger tagger,
	__int64 coincidenceWindow,
	SwabianInstruments_TimeTagger_Coincidences * __returnValue,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
