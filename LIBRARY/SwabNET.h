// CVI wrapper header file for .NET assembly: SwabianInstruments.TimeTagger, Version=2.16.2.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7
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
// CVI name: System_Collections_Generic_IEnumerator_T1, .NET name: System.Collections.Generic.IEnumerator`1[[SwabianInstruments.TimeTagger.Tag, SwabianInstruments.TimeTagger, Version=2.16.2.0, Culture=neutral, PublicKeyToken=b205e4d8392117f7]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Runtime_Serialization_SerializationInfo, .NET name: System.Runtime.Serialization.SerializationInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Delegate, .NET name: System.Delegate, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Reflection_MethodInfo, .NET name: System.Reflection.MethodInfo, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Runtime_Serialization_StreamingContext, .NET name: System.Runtime.Serialization.StreamingContext, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_IAsyncResult, .NET name: System.IAsyncResult, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_AsyncCallback, .NET name: System.AsyncCallback, Assembly: mscorlib, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __Swab_TimeTag_Coincidence * Swab_TimeTag_Coincidence;
typedef struct __Swab_TimeTag_Coincidences * Swab_TimeTag_Coincidences;
typedef struct __Swab_TimeTag_Combiner * Swab_TimeTag_Combiner;
typedef struct __Swab_TimeTag_ConstantFractionDiscriminator * Swab_TimeTag_ConstantFractionDiscriminator;
typedef struct __Swab_TimeTag_Correlation * Swab_TimeTag_Correlation;
typedef struct __Swab_TimeTag_CountBetweenMarkers * Swab_TimeTag_CountBetweenMarkers;
typedef struct __Swab_TimeTag_Counter * Swab_TimeTag_Counter;
typedef struct __Swab_TimeTag_CounterData * Swab_TimeTag_CounterData;
typedef struct __Swab_TimeTag_Countrate * Swab_TimeTag_Countrate;
typedef struct __Swab_TimeTag_CustomMeasBase * Swab_TimeTag_CustomMeasBase;
typedef struct __Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 * Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0;
typedef struct __System_Reflection_MethodInfo * System_Reflection_MethodInfo;
typedef struct __System_AsyncCallback * System_AsyncCallback;
typedef struct __System_IAsyncResult * System_IAsyncResult;
typedef struct __System_Runtime_Serialization_SerializationInfo * System_Runtime_Serialization_SerializationInfo;
typedef struct __System_Runtime_Serialization_StreamingContext * System_Runtime_Serialization_StreamingContext;
typedef struct __System_Delegate * System_Delegate;
typedef struct __Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 * Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1;
typedef struct __Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 * Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2;
typedef struct __Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 * Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3;
typedef struct __Swab_TimeTag_DelayedChannel * Swab_TimeTag_DelayedChannel;
typedef struct __Swab_TimeTag_Dump * Swab_TimeTag_Dump;
typedef struct __Swab_TimeTag_Event * Swab_TimeTag_Event;
typedef struct __Swab_TimeTag_EventGenerator * Swab_TimeTag_EventGenerator;
typedef struct __Swab_TimeTag_FileReader * Swab_TimeTag_FileReader;
typedef struct __Swab_TimeTag_FileWriter * Swab_TimeTag_FileWriter;
typedef struct __Swab_TimeTag_FlimAbstract_internal * Swab_TimeTag_FlimAbstract_internal;
typedef struct __Swab_TimeTag_FlimBase_internal * Swab_TimeTag_FlimBase_internal;
typedef struct __Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 * Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0;
typedef struct __Swab_TimeTag_FlimFrameInfo * Swab_TimeTag_FlimFrameInfo;
typedef struct __Swab_TimeTag_Flim_internal * Swab_TimeTag_Flim_internal;
typedef struct __Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 * Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0;
typedef struct __Swab_TimeTag_FrequencyMultiplier * Swab_TimeTag_FrequencyMultiplier;
typedef struct __Swab_TimeTag_FrequencyStability * Swab_TimeTag_FrequencyStability;
typedef struct __Swab_TimeTag_FrequencyStabilityData * Swab_TimeTag_FrequencyStabilityData;
typedef struct __Swab_TimeTag_GatedChannel * Swab_TimeTag_GatedChannel;
typedef struct __Swab_TimeTag_Histogram * Swab_TimeTag_Histogram;
typedef struct __Swab_TimeTag_Histogram2D * Swab_TimeTag_Histogram2D;
typedef struct __Swab_TimeTag_HistogramLogBins * Swab_TimeTag_HistogramLogBins;
typedef struct __Swab_TimeTag_HistogramND * Swab_TimeTag_HistogramND;
typedef struct __Swab_TimeTag_Iterator * Swab_TimeTag_Iterator;
typedef struct __Swab_TimeTag_IteratorBase * Swab_TimeTag_IteratorBase;
typedef struct __Swab_TimeTag_Sampler * Swab_TimeTag_Sampler;
typedef struct __Swab_TimeTag_Scope * Swab_TimeTag_Scope;
typedef struct __Swab_TimeTag_SoftwareClockState * Swab_TimeTag_SoftwareClockState;
typedef struct __Swab_TimeTag_StartStop * Swab_TimeTag_StartStop;
typedef struct __Swab_TimeTag_SynchronizedMeasurements * Swab_TimeTag_SynchronizedMeasurements;
typedef struct __Swab_TimeTag_SyntheticSingleTag * Swab_TimeTag_SyntheticSingleTag;
typedef struct __Swab_TimeTag_TT * Swab_TimeTag_TT;
typedef struct __Swab_TimeTag_TT_TimeTaggerLogger * Swab_TimeTag_TT_TimeTaggerLogger;
typedef struct __Swab_TimeTag_TimeDifferences * Swab_TimeTag_TimeDifferences;
typedef struct __Swab_TimeTag_TimeDifferencesND * Swab_TimeTag_TimeDifferencesND;
typedef struct __Swab_TimeTag_TimeTagStream * Swab_TimeTag_TimeTagStream;
typedef struct __Swab_TimeTag_TimeTagStreamBuffer * Swab_TimeTag_TimeTagStreamBuffer;
typedef struct __Swab_TimeTag_TimeTagger * Swab_TimeTag_TimeTagger;
typedef struct __Swab_TimeTag_TimeTaggerBase * Swab_TimeTag_TimeTaggerBase;
typedef struct __Swab_TimeTag_TimeTaggerNetwork * Swab_TimeTag_TimeTaggerNetwork;
typedef struct __Swab_TimeTag_TimeTaggerVirtual * Swab_TimeTag_TimeTaggerVirtual;
typedef struct __Swab_TimeTag_TriggerOnCountrate * Swab_TimeTag_TriggerOnCountrate;
typedef struct __Swab_TimeTag_CoincidencesFactory * Swab_TimeTag_CoincidencesFactory;
typedef struct __Swab_TimeTag_CustomMeasurement * Swab_TimeTag_CustomMeasurement;
typedef struct __Swab_TimeTag_FlimBase * Swab_TimeTag_FlimBase;
typedef struct __Swab_TimeTag_FlimBase_FrameReadyCallback * Swab_TimeTag_FlimBase_FrameReadyCallback;
typedef struct __Swab_TimeTag_Flim * Swab_TimeTag_Flim;
typedef struct __Swab_TimeTag_Flim_FrameReadyCallback * Swab_TimeTag_Flim_FrameReadyCallback;
typedef struct __Swab_TimeTag_Tag * Swab_TimeTag_Tag;
typedef struct __Swab_TimeTag_TagBlock * Swab_TimeTag_TagBlock;
typedef struct __System_Collections_Generic_IEnumerator_T1 * System_Collections_Generic_IEnumerator_T1;
typedef struct __Swab_TimeTag_Exp_ExponentialSignalGenerator * Swab_TimeTag_Exp_ExponentialSignalGenerator;
typedef struct __Swab_TimeTag_Exp_GammaSignalGenerator * Swab_TimeTag_Exp_GammaSignalGenerator;
typedef struct __Swab_TimeTag_Exp_GaussianSignalGenerator * Swab_TimeTag_Exp_GaussianSignalGenerator;
typedef struct __Swab_TimeTag_Exp_MarkovProcessGenerator * Swab_TimeTag_Exp_MarkovProcessGenerator;
typedef struct __Swab_TimeTag_Exp_PatternSignalGenerator * Swab_TimeTag_Exp_PatternSignalGenerator;
typedef struct __Swab_TimeTag_Exp_PoissonSignalGenerator * Swab_TimeTag_Exp_PoissonSignalGenerator;
typedef struct __Swab_TimeTag_Exp_SignalGeneratorBase * Swab_TimeTag_Exp_SignalGeneratorBase;
typedef struct __Swab_TimeTag_Exp_SimDetector * Swab_TimeTag_Exp_SimDetector;
typedef struct __Swab_TimeTag_Exp_SimLifetime * Swab_TimeTag_Exp_SimLifetime;
typedef struct __Swab_TimeTag_Exp_SimSignalSplitter * Swab_TimeTag_Exp_SimSignalSplitter;
typedef struct __Swab_TimeTag_Exp_TransformCrosstalk * Swab_TimeTag_Exp_TransformCrosstalk;
typedef struct __Swab_TimeTag_Exp_TransformDeadtime * Swab_TimeTag_Exp_TransformDeadtime;
typedef struct __Swab_TimeTag_Exp_TransformEfficiency * Swab_TimeTag_Exp_TransformEfficiency;
typedef struct __Swab_TimeTag_Exp_TransformGaussianBroadening * Swab_TimeTag_Exp_TransformGaussianBroadening;
typedef struct __Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator * Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator;
typedef struct __Swab_TimeTag_Exp_UniformSignalGenerator * Swab_TimeTag_Exp_UniformSignalGenerator;

// C wrapper for enumeration type SwabianInstruments.TimeTagger.AccessMode
#ifndef Swab_TimeTag_AccessMode_DEFINED
#define Swab_TimeTag_AccessMode_DEFINED
typedef enum Swab_TimeTag_AccessMode
{
	Swab_TimeTag_AccessMode_Listen = 0x0,
	Swab_TimeTag_AccessMode_Control = 0x2,
	Swab_TimeTag_AccessMode_SynchronousControl = 0x3,
} Swab_TimeTag_AccessMode;
#endif // Swab_TimeTag_AccessMode_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.ChannelEdge
#ifndef Swab_TimeTag_ChannelEdge_DEFINED
#define Swab_TimeTag_ChannelEdge_DEFINED
typedef enum Swab_TimeTag_ChannelEdge
{
	Swab_TimeTag_ChannelEdge_All = 0x0,
	Swab_TimeTag_ChannelEdge_Rising = 0x1,
	Swab_TimeTag_ChannelEdge_Falling = 0x2,
	Swab_TimeTag_ChannelEdge_HighResAll = 0x4,
	Swab_TimeTag_ChannelEdge_HighResRising = 0x5,
	Swab_TimeTag_ChannelEdge_HighResFalling = 0x6,
	Swab_TimeTag_ChannelEdge_StandardAll = 0x8,
	Swab_TimeTag_ChannelEdge_StandardRising = 0x9,
	Swab_TimeTag_ChannelEdge_StandardFalling = 0xa,
} Swab_TimeTag_ChannelEdge;
#endif // Swab_TimeTag_ChannelEdge_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.CoincidenceTimestamp
#ifndef Swab_TimeTag_CoincidenceTimestamp_DEFINED
#define Swab_TimeTag_CoincidenceTimestamp_DEFINED
typedef enum Swab_TimeTag_CoincidenceTimestamp
{
	Swab_TimeTag_CoincidenceTimestamp_Last = 0x0,
	Swab_TimeTag_CoincidenceTimestamp_Average = 0x1,
	Swab_TimeTag_CoincidenceTimestamp_First = 0x2,
	Swab_TimeTag_CoincidenceTimestamp_ListedFirst = 0x3,
} Swab_TimeTag_CoincidenceTimestamp;
#endif // Swab_TimeTag_CoincidenceTimestamp_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.State
#ifndef Swab_TimeTag_State_DEFINED
#define Swab_TimeTag_State_DEFINED
typedef enum Swab_TimeTag_State
{
	Swab_TimeTag_State_UNKNOWN = 0x0,
	Swab_TimeTag_State_HIGH = 0x1,
	Swab_TimeTag_State_LOW = 0x2,
} Swab_TimeTag_State;
#endif // Swab_TimeTag_State_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.FpgaLinkInterface
#ifndef Swab_TimeTag_FpgaLinkInterface_DEFINED
#define Swab_TimeTag_FpgaLinkInterface_DEFINED
typedef enum Swab_TimeTag_FpgaLinkInterface
{
	Swab_TimeTag_FpgaLinkInterface_SFPP_10GE = 0x0,
} Swab_TimeTag_FpgaLinkInterface;
#endif // Swab_TimeTag_FpgaLinkInterface_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.FrontendType
#ifndef Swab_TimeTag_FrontendType_DEFINED
#define Swab_TimeTag_FrontendType_DEFINED
typedef enum Swab_TimeTag_FrontendType
{
	Swab_TimeTag_FrontendType_Undefined = 0x0,
	Swab_TimeTag_FrontendType_WebApp = 0x1,
	Swab_TimeTag_FrontendType_Firefly = 0x2,
	Swab_TimeTag_FrontendType_Pyro5RPC = 0x3,
	Swab_TimeTag_FrontendType_UserFrontend = 0x4,
} Swab_TimeTag_FrontendType;
#endif // Swab_TimeTag_FrontendType_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.GatedChannelInitial
#ifndef Swab_TimeTag_GatedChannelInitial_DEFINED
#define Swab_TimeTag_GatedChannelInitial_DEFINED
typedef enum Swab_TimeTag_GatedChannelInitial
{
	Swab_TimeTag_GatedChannelInitial_Closed = 0x0,
	Swab_TimeTag_GatedChannelInitial_Open = 0x1,
} Swab_TimeTag_GatedChannelInitial;
#endif // Swab_TimeTag_GatedChannelInitial_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.LanguageUsed
#ifndef Swab_TimeTag_LanguageUsed_DEFINED
#define Swab_TimeTag_LanguageUsed_DEFINED
typedef enum Swab_TimeTag_LanguageUsed
{
	Swab_TimeTag_LanguageUsed_Cpp = 0x0,
	Swab_TimeTag_LanguageUsed_Python = 0x1,
	Swab_TimeTag_LanguageUsed_Csharp = 0x2,
	Swab_TimeTag_LanguageUsed_Matlab = 0x3,
	Swab_TimeTag_LanguageUsed_Labview = 0x4,
	Swab_TimeTag_LanguageUsed_Mathematica = 0x5,
	Swab_TimeTag_LanguageUsed_Unknown = 0xff,
} Swab_TimeTag_LanguageUsed;
#endif // Swab_TimeTag_LanguageUsed_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.LogLevel
#ifndef Swab_TimeTag_LogLevel_DEFINED
#define Swab_TimeTag_LogLevel_DEFINED
typedef enum Swab_TimeTag_LogLevel
{
	Swab_TimeTag_LogLevel_LOGGER_INFO = 0xa,
	Swab_TimeTag_LogLevel_LOGGER_WARNING = 0x1e,
	Swab_TimeTag_LogLevel_LOGGER_ERROR = 0x28,
} Swab_TimeTag_LogLevel;
#endif // Swab_TimeTag_LogLevel_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.Resolution
#ifndef Swab_TimeTag_Resolution_DEFINED
#define Swab_TimeTag_Resolution_DEFINED
typedef enum Swab_TimeTag_Resolution
{
	Swab_TimeTag_Resolution_Standard = 0x0,
	Swab_TimeTag_Resolution_HighResA = 0x1,
	Swab_TimeTag_Resolution_HighResB = 0x2,
	Swab_TimeTag_Resolution_HighResC = 0x3,
} Swab_TimeTag_Resolution;
#endif // Swab_TimeTag_Resolution_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.UsageStatisticsStatus
#ifndef Swab_TimeTag_UsageStatisticsStatus_DEFINED
#define Swab_TimeTag_UsageStatisticsStatus_DEFINED
typedef enum Swab_TimeTag_UsageStatisticsStatus
{
	Swab_TimeTag_UsageStatisticsStatus_Disabled = 0x0,
	Swab_TimeTag_UsageStatisticsStatus_Collecting = 0x1,
	Swab_TimeTag_UsageStatisticsStatus_CollectingAndUploading = 0x2,
} Swab_TimeTag_UsageStatisticsStatus;
#endif // Swab_TimeTag_UsageStatisticsStatus_DEFINED

// C wrapper for enumeration type SwabianInstruments.TimeTagger.TagType
#ifndef Swab_TimeTag_TagType_DEFINED
#define Swab_TimeTag_TagType_DEFINED
typedef enum Swab_TimeTag_TagType
{
	Swab_TimeTag_TagType_TimeTag = 0x0,
	Swab_TimeTag_TagType_Error = 0x1,
	Swab_TimeTag_TagType_OverflowBegin = 0x2,
	Swab_TimeTag_TagType_OverflowEnd = 0x3,
	Swab_TimeTag_TagType_MissedEvents = 0x4,
} Swab_TimeTag_TagType;
#endif // Swab_TimeTag_TagType_DEFINED


typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback_t)(void * callbackData);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback_t)(void * callbackData);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback_t)(void * callbackData);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback_t)(void * callbackData,
		void * tags_ptr,
		unsigned __int64 num_tags,
		__int64 begin_time,
		__int64 end_time);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback_t)(void * callbackData,
		unsigned int frame_number,
		void * data,
		void * pixel_begin_times,
		void * pixel_end_times,
		__int64 frame_begin_time,
		__int64 frame_end_time);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback_t)(void * callbackData,
		unsigned int frame_number,
		void * data,
		void * pixel_begin_times,
		void * pixel_end_times,
		__int64 frame_begin_time,
		__int64 frame_end_time);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t)(void * callbackData,
		int level,
		char * message);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback_t)(void * callbackData,
		unsigned int frame_number,
		unsigned int * data,
		ssize_t __dataLength,
		__int64 * pixel_begin_times,
		ssize_t __pixel_begin_timesLength,
		__int64 * pixel_end_times,
		ssize_t __pixel_end_timesLength,
		__int64 frame_begin_time,
		__int64 frame_end_time);
typedef int (CVICALLBACK * SwabianInstruments_TimeTagger_Flim_FrameReadyCallback__Callback_t)(void * callbackData,
		unsigned int frame_number,
		unsigned int * data,
		ssize_t __dataLength,
		__int64 * pixel_begin_times,
		ssize_t __pixel_begin_timesLength,
		__int64 * pixel_end_times,
		ssize_t __pixel_end_timesLength,
		__int64 frame_begin_time,
		__int64 frame_end_time);


// Global Functions
int CVIFUNC Initialize_SwabianInstruments_TimeTagger(void);
int CVIFUNC Close_SwabianInstruments_TimeTagger(void);

// Type: SwabianInstruments.TimeTagger.Coincidence
int CVIFUNC Swab_TimeTag_Coincidence__Create(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence__Create_1(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence__Create_2(
	Swab_TimeTag_Coincidence * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_getChannel(
	Swab_TimeTag_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_getChannels(
	Swab_TimeTag_Coincidence __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_setCoincidenceWindow(
	Swab_TimeTag_Coincidence __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_Dispose(
	Swab_TimeTag_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_start(
	Swab_TimeTag_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_startFor(
	Swab_TimeTag_Coincidence __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_startFor_1(
	Swab_TimeTag_Coincidence __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_waitUntilFinished(
	Swab_TimeTag_Coincidence __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_waitUntilFinished_1(
	Swab_TimeTag_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_stop(
	Swab_TimeTag_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_clear(
	Swab_TimeTag_Coincidence __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_isRunning(
	Swab_TimeTag_Coincidence __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_getCaptureDuration(
	Swab_TimeTag_Coincidence __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidence_getConfiguration(
	Swab_TimeTag_Coincidence __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Coincidences
int CVIFUNC Swab_TimeTag_Coincidences__Create(
	Swab_TimeTag_Coincidences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp timestamp,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences__Create_1(
	Swab_TimeTag_Coincidences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle coincidenceGroups,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_getChannels(
	Swab_TimeTag_Coincidences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_setCoincidenceWindow(
	Swab_TimeTag_Coincidences __instance,
	__int64 coincidenceWindow,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_Dispose(
	Swab_TimeTag_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_start(
	Swab_TimeTag_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_startFor(
	Swab_TimeTag_Coincidences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_startFor_1(
	Swab_TimeTag_Coincidences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_waitUntilFinished(
	Swab_TimeTag_Coincidences __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_waitUntilFinished_1(
	Swab_TimeTag_Coincidences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_stop(
	Swab_TimeTag_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_clear(
	Swab_TimeTag_Coincidences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_isRunning(
	Swab_TimeTag_Coincidences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_getCaptureDuration(
	Swab_TimeTag_Coincidences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Coincidences_getConfiguration(
	Swab_TimeTag_Coincidences __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Combiner
int CVIFUNC Swab_TimeTag_Combiner__Create(
	Swab_TimeTag_Combiner * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_getChannelCounts(
	Swab_TimeTag_Combiner __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_getData(
	Swab_TimeTag_Combiner __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_getChannel(
	Swab_TimeTag_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_Dispose(
	Swab_TimeTag_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_start(
	Swab_TimeTag_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_startFor(
	Swab_TimeTag_Combiner __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_startFor_1(
	Swab_TimeTag_Combiner __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_waitUntilFinished(
	Swab_TimeTag_Combiner __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_waitUntilFinished_1(
	Swab_TimeTag_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_stop(
	Swab_TimeTag_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_clear(
	Swab_TimeTag_Combiner __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_isRunning(
	Swab_TimeTag_Combiner __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_getCaptureDuration(
	Swab_TimeTag_Combiner __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Combiner_getConfiguration(
	Swab_TimeTag_Combiner __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.ConstantFractionDiscriminator
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator__Create(
	Swab_TimeTag_ConstantFractionDiscriminator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 search_window,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getChannels(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_Dispose(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_start(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_startFor(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_startFor_1(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_waitUntilFinished(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_waitUntilFinished_1(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_stop(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_clear(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_isRunning(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getCaptureDuration(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_ConstantFractionDiscriminator_getConfiguration(
	Swab_TimeTag_ConstantFractionDiscriminator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Correlation
int CVIFUNC Swab_TimeTag_Correlation__Create(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation__Create_1(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation__Create_2(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel_1,
	int channel_2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation__Create_3(
	Swab_TimeTag_Correlation * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel_1,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_getData(
	Swab_TimeTag_Correlation __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_getDataNormalized(
	Swab_TimeTag_Correlation __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_getIndex(
	Swab_TimeTag_Correlation __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_Dispose(
	Swab_TimeTag_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_start(
	Swab_TimeTag_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_startFor(
	Swab_TimeTag_Correlation __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_startFor_1(
	Swab_TimeTag_Correlation __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_waitUntilFinished(
	Swab_TimeTag_Correlation __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_waitUntilFinished_1(
	Swab_TimeTag_Correlation __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_stop(
	Swab_TimeTag_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_clear(
	Swab_TimeTag_Correlation __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_isRunning(
	Swab_TimeTag_Correlation __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_getCaptureDuration(
	Swab_TimeTag_Correlation __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Correlation_getConfiguration(
	Swab_TimeTag_Correlation __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CountBetweenMarkers
int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	int n_values,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create_1(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	int end_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers__Create_2(
	Swab_TimeTag_CountBetweenMarkers * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int begin_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_ready(
	Swab_TimeTag_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getData(
	Swab_TimeTag_CountBetweenMarkers __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getBinWidths(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getIndex(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_Dispose(
	Swab_TimeTag_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_start(
	Swab_TimeTag_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_startFor(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_startFor_1(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_waitUntilFinished(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_waitUntilFinished_1(
	Swab_TimeTag_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_stop(
	Swab_TimeTag_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_clear(
	Swab_TimeTag_CountBetweenMarkers __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_isRunning(
	Swab_TimeTag_CountBetweenMarkers __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getCaptureDuration(
	Swab_TimeTag_CountBetweenMarkers __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CountBetweenMarkers_getConfiguration(
	Swab_TimeTag_CountBetweenMarkers __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Counter
int CVIFUNC Swab_TimeTag_Counter__Create(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	int n_values,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter__Create_1(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter__Create_2(
	Swab_TimeTag_Counter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getData(
	Swab_TimeTag_Counter __instance,
	int rolling,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getData_1(
	Swab_TimeTag_Counter __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getDataNormalized(
	Swab_TimeTag_Counter __instance,
	int rolling,
	double ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getDataNormalized_1(
	Swab_TimeTag_Counter __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getDataTotalCounts(
	Swab_TimeTag_Counter __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getIndex(
	Swab_TimeTag_Counter __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getDataObject(
	Swab_TimeTag_Counter __instance,
	int remove,
	Swab_TimeTag_CounterData * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getDataObject_1(
	Swab_TimeTag_Counter __instance,
	Swab_TimeTag_CounterData * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_Dispose(
	Swab_TimeTag_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_start(
	Swab_TimeTag_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_startFor(
	Swab_TimeTag_Counter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_startFor_1(
	Swab_TimeTag_Counter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_waitUntilFinished(
	Swab_TimeTag_Counter __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_waitUntilFinished_1(
	Swab_TimeTag_Counter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_stop(
	Swab_TimeTag_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_clear(
	Swab_TimeTag_Counter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_isRunning(
	Swab_TimeTag_Counter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getCaptureDuration(
	Swab_TimeTag_Counter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Counter_getConfiguration(
	Swab_TimeTag_Counter __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CounterData
int CVIFUNC Swab_TimeTag_CounterData_Get_size(
	Swab_TimeTag_CounterData __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_Get_dropped_bins(
	Swab_TimeTag_CounterData __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_Get_overflow(
	Swab_TimeTag_CounterData __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_Dispose(
	Swab_TimeTag_CounterData __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getData(
	Swab_TimeTag_CounterData __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getDataNormalized(
	Swab_TimeTag_CounterData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getDataTotalCounts(
	Swab_TimeTag_CounterData __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getIndex(
	Swab_TimeTag_CounterData __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getTime(
	Swab_TimeTag_CounterData __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getOverflowMask(
	Swab_TimeTag_CounterData __instance,
	char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CounterData_getChannels(
	Swab_TimeTag_CounterData __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Countrate
int CVIFUNC Swab_TimeTag_Countrate__Create(
	Swab_TimeTag_Countrate * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_getData(
	Swab_TimeTag_Countrate __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_getCountsTotal(
	Swab_TimeTag_Countrate __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_Dispose(
	Swab_TimeTag_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_start(
	Swab_TimeTag_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_startFor(
	Swab_TimeTag_Countrate __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_startFor_1(
	Swab_TimeTag_Countrate __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_waitUntilFinished(
	Swab_TimeTag_Countrate __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_waitUntilFinished_1(
	Swab_TimeTag_Countrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_stop(
	Swab_TimeTag_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_clear(
	Swab_TimeTag_Countrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_isRunning(
	Swab_TimeTag_Countrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_getCaptureDuration(
	Swab_TimeTag_Countrate __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Countrate_getConfiguration(
	Swab_TimeTag_Countrate __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase
int CVIFUNC Swab_TimeTag_CustomMeasBase_stop_all_custom_measurements(
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_register_channel(
	Swab_TimeTag_CustomMeasBase __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_unregister_channel(
	Swab_TimeTag_CustomMeasBase __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_finalize_init(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_is_running(
	Swab_TimeTag_CustomMeasBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase__lock(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase__unlock(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_Dispose(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_start(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_startFor(
	Swab_TimeTag_CustomMeasBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_startFor_1(
	Swab_TimeTag_CustomMeasBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_waitUntilFinished(
	Swab_TimeTag_CustomMeasBase __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_waitUntilFinished_1(
	Swab_TimeTag_CustomMeasBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_stop(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_clear(
	Swab_TimeTag_CustomMeasBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_isRunning(
	Swab_TimeTag_CustomMeasBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_getCaptureDuration(
	Swab_TimeTag_CustomMeasBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_getConfiguration(
	Swab_TimeTag_CustomMeasBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_0
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasurementBase_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_1
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_1__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_1 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_2
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_2__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_2 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurementBase+SwigDelegateCustomMeasurementBase_3
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3__Create(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 * __instance,
	SwabianInstruments_TimeTagger_CustomMeasurementBase_SwigDelegateCustomMeasurementBase_3__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Get_Method(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Get_Target(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Invoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	void * tags_ptr,
	unsigned __int64 num_tags,
	__int64 begin_time,
	__int64 end_time,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_BeginInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	void * tags_ptr,
	unsigned __int64 num_tags,
	__int64 begin_time,
	__int64 end_time,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_EndInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetObjectData(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Equals(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetInvocationList(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_GetHashCode(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_DynamicInvoke(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3_Clone(
	Swab_TimeTag_CustomMeasBase_SwigDelegateCustomMeasBase_3 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.DelayedChannel
int CVIFUNC Swab_TimeTag_DelayedChannel__Create(
	Swab_TimeTag_DelayedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_getChannel(
	Swab_TimeTag_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_setDelay(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_Dispose(
	Swab_TimeTag_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_start(
	Swab_TimeTag_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_startFor(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_startFor_1(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_waitUntilFinished(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_waitUntilFinished_1(
	Swab_TimeTag_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_stop(
	Swab_TimeTag_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_clear(
	Swab_TimeTag_DelayedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_isRunning(
	Swab_TimeTag_DelayedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_getCaptureDuration(
	Swab_TimeTag_DelayedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_DelayedChannel_getConfiguration(
	Swab_TimeTag_DelayedChannel __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Dump
int CVIFUNC Swab_TimeTag_Dump__Create(
	Swab_TimeTag_Dump * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump__Create_1(
	Swab_TimeTag_Dump * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	char * filename,
	__int64 max_tags,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_Dispose(
	Swab_TimeTag_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_start(
	Swab_TimeTag_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_startFor(
	Swab_TimeTag_Dump __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_startFor_1(
	Swab_TimeTag_Dump __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_waitUntilFinished(
	Swab_TimeTag_Dump __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_waitUntilFinished_1(
	Swab_TimeTag_Dump __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_stop(
	Swab_TimeTag_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_clear(
	Swab_TimeTag_Dump __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_isRunning(
	Swab_TimeTag_Dump __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_getCaptureDuration(
	Swab_TimeTag_Dump __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Dump_getConfiguration(
	Swab_TimeTag_Dump __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Event
int CVIFUNC Swab_TimeTag_Event__Create(
	Swab_TimeTag_Event * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Event_Get_time(
	Swab_TimeTag_Event __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Event_Set_time(
	Swab_TimeTag_Event __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Event_Get_state(
	Swab_TimeTag_Event __instance,
	Swab_TimeTag_State * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Event_Set_state(
	Swab_TimeTag_Event __instance,
	Swab_TimeTag_State value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Event_Dispose(
	Swab_TimeTag_Event __instance,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator__Create_1(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	unsigned __int64 divider_offset,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator__Create_2(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	unsigned __int64 trigger_divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator__Create_3(
	Swab_TimeTag_EventGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int trigger_channel,
	__int64 * pattern,
	ssize_t __patternLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_getChannel(
	Swab_TimeTag_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_Dispose(
	Swab_TimeTag_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_start(
	Swab_TimeTag_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_startFor(
	Swab_TimeTag_EventGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_startFor_1(
	Swab_TimeTag_EventGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_waitUntilFinished(
	Swab_TimeTag_EventGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_waitUntilFinished_1(
	Swab_TimeTag_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_stop(
	Swab_TimeTag_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_clear(
	Swab_TimeTag_EventGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_isRunning(
	Swab_TimeTag_EventGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_getCaptureDuration(
	Swab_TimeTag_EventGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_EventGenerator_getConfiguration(
	Swab_TimeTag_EventGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FileReader
int CVIFUNC Swab_TimeTag_FileReader__Create(
	Swab_TimeTag_FileReader * __instance,
	char ** filenames,
	ssize_t __filenamesLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader__Create_1(
	Swab_TimeTag_FileReader * __instance,
	char * filename,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_Dispose(
	Swab_TimeTag_FileReader __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_hasData(
	Swab_TimeTag_FileReader __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_getData(
	Swab_TimeTag_FileReader __instance,
	unsigned __int64 n_events,
	Swab_TimeTag_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_getConfiguration(
	Swab_TimeTag_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_getChannelList(
	Swab_TimeTag_FileReader __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileReader_getLastMarker(
	Swab_TimeTag_FileReader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FileWriter
int CVIFUNC Swab_TimeTag_FileWriter__Create(
	Swab_TimeTag_FileWriter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	char * filename,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_split(
	Swab_TimeTag_FileWriter __instance,
	char * new_filename,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_split_1(
	Swab_TimeTag_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_setMaxFileSize(
	Swab_TimeTag_FileWriter __instance,
	unsigned __int64 max_file_size,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_getMaxFileSize(
	Swab_TimeTag_FileWriter __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_getTotalEvents(
	Swab_TimeTag_FileWriter __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_getTotalSize(
	Swab_TimeTag_FileWriter __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_setMarker(
	Swab_TimeTag_FileWriter __instance,
	char * marker,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_Dispose(
	Swab_TimeTag_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_start(
	Swab_TimeTag_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_startFor(
	Swab_TimeTag_FileWriter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_startFor_1(
	Swab_TimeTag_FileWriter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_waitUntilFinished(
	Swab_TimeTag_FileWriter __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_waitUntilFinished_1(
	Swab_TimeTag_FileWriter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_stop(
	Swab_TimeTag_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_clear(
	Swab_TimeTag_FileWriter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_isRunning(
	Swab_TimeTag_FileWriter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_getCaptureDuration(
	Swab_TimeTag_FileWriter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FileWriter_getConfiguration(
	Swab_TimeTag_FileWriter __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FlimAbstract_internal
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_isAcquiring(
	Swab_TimeTag_FlimAbstract_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_Dispose(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_start(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_startFor(
	Swab_TimeTag_FlimAbstract_internal __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_startFor_1(
	Swab_TimeTag_FlimAbstract_internal __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_waitUntilFinished(
	Swab_TimeTag_FlimAbstract_internal __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_waitUntilFinished_1(
	Swab_TimeTag_FlimAbstract_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_stop(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_clear(
	Swab_TimeTag_FlimAbstract_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_isRunning(
	Swab_TimeTag_FlimAbstract_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_getCaptureDuration(
	Swab_TimeTag_FlimAbstract_internal __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimAbstract_internal_getConfiguration(
	Swab_TimeTag_FlimAbstract_internal __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal__Create_5(
	Swab_TimeTag_FlimBase_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_initialize(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_isAcquiring(
	Swab_TimeTag_FlimBase_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_Dispose(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_start(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_startFor(
	Swab_TimeTag_FlimBase_internal __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_startFor_1(
	Swab_TimeTag_FlimBase_internal __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_waitUntilFinished(
	Swab_TimeTag_FlimBase_internal __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_waitUntilFinished_1(
	Swab_TimeTag_FlimBase_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_stop(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_clear(
	Swab_TimeTag_FlimBase_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_isRunning(
	Swab_TimeTag_FlimBase_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_getCaptureDuration(
	Swab_TimeTag_FlimBase_internal __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_getConfiguration(
	Swab_TimeTag_FlimBase_internal __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FlimBase_internal+SwigDelegateFlimBase_internal_0
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0__Create(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 * __instance,
	SwabianInstruments_TimeTagger_FlimBase_internal_SwigDelegateFlimBase_internal_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Get_Method(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Get_Target(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Invoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_EndInvoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetObjectData(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Equals(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetInvocationList(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_GetHashCode(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_DynamicInvoke(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0_Clone(
	Swab_TimeTag_FlimBase_internal_SwigDelegateFlimBase_internal_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FlimFrameInfo
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_pixels(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_pixels(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_bins(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_bins(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_frame_number(
	Swab_TimeTag_FlimFrameInfo __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_frame_number(
	Swab_TimeTag_FlimFrameInfo __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_pixel_position(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_pixel_position(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Get_valid(
	Swab_TimeTag_FlimFrameInfo __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Set_valid(
	Swab_TimeTag_FlimFrameInfo __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_Dispose(
	Swab_TimeTag_FlimFrameInfo __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getFrameNumber(
	Swab_TimeTag_FlimFrameInfo __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_isValid(
	Swab_TimeTag_FlimFrameInfo __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelPosition(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getHistograms(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getIntensities(
	Swab_TimeTag_FlimFrameInfo __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getSummedCounts(
	Swab_TimeTag_FlimFrameInfo __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelBegins(
	Swab_TimeTag_FlimFrameInfo __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimFrameInfo_getPixelEnds(
	Swab_TimeTag_FlimFrameInfo __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal__Create_5(
	Swab_TimeTag_Flim_internal * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_initialize(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrame(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrame_1(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameIntensity(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameIntensity_1(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrame(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrameIntensity(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFrames_2(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesIntensity_2(
	Swab_TimeTag_Flim_internal __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameEx(
	Swab_TimeTag_Flim_internal __instance,
	int index,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getReadyFrameEx_1(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getCurrentFrameEx(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	int clear_summed,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx_1(
	Swab_TimeTag_Flim_internal __instance,
	int only_ready_frames,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getSummedFramesEx_2(
	Swab_TimeTag_Flim_internal __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getFramesAcquired(
	Swab_TimeTag_Flim_internal __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getIndex(
	Swab_TimeTag_Flim_internal __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_isAcquiring(
	Swab_TimeTag_Flim_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_Dispose(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_start(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_startFor(
	Swab_TimeTag_Flim_internal __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_startFor_1(
	Swab_TimeTag_Flim_internal __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_waitUntilFinished(
	Swab_TimeTag_Flim_internal __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_waitUntilFinished_1(
	Swab_TimeTag_Flim_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_stop(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_clear(
	Swab_TimeTag_Flim_internal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_isRunning(
	Swab_TimeTag_Flim_internal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getCaptureDuration(
	Swab_TimeTag_Flim_internal __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_getConfiguration(
	Swab_TimeTag_Flim_internal __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Flim_internal+SwigDelegateFlim_internal_0
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0__Create(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 * __instance,
	SwabianInstruments_TimeTagger_Flim_internal_SwigDelegateFlim_internal_0__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Get_Method(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Get_Target(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Invoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	unsigned int frame_number,
	void * data,
	void * pixel_begin_times,
	void * pixel_end_times,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_EndInvoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetObjectData(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Equals(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetInvocationList(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_GetHashCode(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_DynamicInvoke(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0_Clone(
	Swab_TimeTag_Flim_internal_SwigDelegateFlim_internal_0 __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FrequencyMultiplier
int CVIFUNC Swab_TimeTag_FrequencyMultiplier__Create(
	Swab_TimeTag_FrequencyMultiplier * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int multiplier,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getChannel(
	Swab_TimeTag_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getMultiplier(
	Swab_TimeTag_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_Dispose(
	Swab_TimeTag_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_start(
	Swab_TimeTag_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_startFor(
	Swab_TimeTag_FrequencyMultiplier __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_startFor_1(
	Swab_TimeTag_FrequencyMultiplier __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_waitUntilFinished(
	Swab_TimeTag_FrequencyMultiplier __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_waitUntilFinished_1(
	Swab_TimeTag_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_stop(
	Swab_TimeTag_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_clear(
	Swab_TimeTag_FrequencyMultiplier __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_isRunning(
	Swab_TimeTag_FrequencyMultiplier __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getCaptureDuration(
	Swab_TimeTag_FrequencyMultiplier __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyMultiplier_getConfiguration(
	Swab_TimeTag_FrequencyMultiplier __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FrequencyStability
int CVIFUNC Swab_TimeTag_FrequencyStability__Create(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	__int64 average,
	unsigned __int64 trace_len,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability__Create_1(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	__int64 average,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability__Create_2(
	Swab_TimeTag_FrequencyStability * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	unsigned __int64 * steps,
	ssize_t __stepsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_getDataObject(
	Swab_TimeTag_FrequencyStability __instance,
	Swab_TimeTag_FrequencyStabilityData * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_Dispose(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_start(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_startFor(
	Swab_TimeTag_FrequencyStability __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_startFor_1(
	Swab_TimeTag_FrequencyStability __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_waitUntilFinished(
	Swab_TimeTag_FrequencyStability __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_waitUntilFinished_1(
	Swab_TimeTag_FrequencyStability __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_stop(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_clear(
	Swab_TimeTag_FrequencyStability __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_isRunning(
	Swab_TimeTag_FrequencyStability __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_getCaptureDuration(
	Swab_TimeTag_FrequencyStability __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStability_getConfiguration(
	Swab_TimeTag_FrequencyStability __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FrequencyStabilityData
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_Dispose(
	Swab_TimeTag_FrequencyStabilityData __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getSTDD(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getADEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getMDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getHDEV(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getADEVScaled(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getHDEVScaled(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTau(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTracePhase(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequency(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequencyAbsolute(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double input_frequency,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceFrequencyAbsolute_1(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FrequencyStabilityData_getTraceIndex(
	Swab_TimeTag_FrequencyStabilityData __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.GatedChannel
int CVIFUNC Swab_TimeTag_GatedChannel__Create(
	Swab_TimeTag_GatedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int gate_start_channel,
	int gate_stop_channel,
	Swab_TimeTag_GatedChannelInitial initial,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel__Create_1(
	Swab_TimeTag_GatedChannel * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int gate_start_channel,
	int gate_stop_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_getChannel(
	Swab_TimeTag_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_Dispose(
	Swab_TimeTag_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_start(
	Swab_TimeTag_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_startFor(
	Swab_TimeTag_GatedChannel __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_startFor_1(
	Swab_TimeTag_GatedChannel __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_waitUntilFinished(
	Swab_TimeTag_GatedChannel __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_waitUntilFinished_1(
	Swab_TimeTag_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_stop(
	Swab_TimeTag_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_clear(
	Swab_TimeTag_GatedChannel __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_isRunning(
	Swab_TimeTag_GatedChannel __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_getCaptureDuration(
	Swab_TimeTag_GatedChannel __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_GatedChannel_getConfiguration(
	Swab_TimeTag_GatedChannel __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Histogram
int CVIFUNC Swab_TimeTag_Histogram__Create(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram__Create_1(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram__Create_2(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram__Create_3(
	Swab_TimeTag_Histogram * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_getData(
	Swab_TimeTag_Histogram __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_getIndex(
	Swab_TimeTag_Histogram __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_Dispose(
	Swab_TimeTag_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_start(
	Swab_TimeTag_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_startFor(
	Swab_TimeTag_Histogram __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_startFor_1(
	Swab_TimeTag_Histogram __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_waitUntilFinished(
	Swab_TimeTag_Histogram __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_waitUntilFinished_1(
	Swab_TimeTag_Histogram __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_stop(
	Swab_TimeTag_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_clear(
	Swab_TimeTag_Histogram __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_isRunning(
	Swab_TimeTag_Histogram __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_getCaptureDuration(
	Swab_TimeTag_Histogram __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram_getConfiguration(
	Swab_TimeTag_Histogram __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getData(
	Swab_TimeTag_Histogram2D __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getIndex(
	Swab_TimeTag_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	ssize_t * ____returnValueLength3,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getIndex_1(
	Swab_TimeTag_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getIndex_2(
	Swab_TimeTag_Histogram2D __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_Dispose(
	Swab_TimeTag_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_start(
	Swab_TimeTag_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_startFor(
	Swab_TimeTag_Histogram2D __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_startFor_1(
	Swab_TimeTag_Histogram2D __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_waitUntilFinished(
	Swab_TimeTag_Histogram2D __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_waitUntilFinished_1(
	Swab_TimeTag_Histogram2D __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_stop(
	Swab_TimeTag_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_clear(
	Swab_TimeTag_Histogram2D __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_isRunning(
	Swab_TimeTag_Histogram2D __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getCaptureDuration(
	Swab_TimeTag_Histogram2D __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Histogram2D_getConfiguration(
	Swab_TimeTag_Histogram2D __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.HistogramLogBins
int CVIFUNC Swab_TimeTag_HistogramLogBins__Create(
	Swab_TimeTag_HistogramLogBins * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	double exp_start,
	double exp_stop,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getData(
	Swab_TimeTag_HistogramLogBins __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getDataNormalizedCountsPerPs(
	Swab_TimeTag_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getDataNormalizedG2(
	Swab_TimeTag_HistogramLogBins __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getBinEdges(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_Dispose(
	Swab_TimeTag_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_start(
	Swab_TimeTag_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_startFor(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_startFor_1(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_waitUntilFinished(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_waitUntilFinished_1(
	Swab_TimeTag_HistogramLogBins __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_stop(
	Swab_TimeTag_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_clear(
	Swab_TimeTag_HistogramLogBins __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_isRunning(
	Swab_TimeTag_HistogramLogBins __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getCaptureDuration(
	Swab_TimeTag_HistogramLogBins __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramLogBins_getConfiguration(
	Swab_TimeTag_HistogramLogBins __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_getData(
	Swab_TimeTag_HistogramND __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_getIndex(
	Swab_TimeTag_HistogramND __instance,
	int dim,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_getIndex_1(
	Swab_TimeTag_HistogramND __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_Dispose(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_start(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_startFor(
	Swab_TimeTag_HistogramND __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_startFor_1(
	Swab_TimeTag_HistogramND __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_waitUntilFinished(
	Swab_TimeTag_HistogramND __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_waitUntilFinished_1(
	Swab_TimeTag_HistogramND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_stop(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_clear(
	Swab_TimeTag_HistogramND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_isRunning(
	Swab_TimeTag_HistogramND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_getCaptureDuration(
	Swab_TimeTag_HistogramND __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_HistogramND_getConfiguration(
	Swab_TimeTag_HistogramND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Iterator
int CVIFUNC Swab_TimeTag_Iterator__Create(
	Swab_TimeTag_Iterator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_next(
	Swab_TimeTag_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_size(
	Swab_TimeTag_Iterator __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_Dispose(
	Swab_TimeTag_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_start(
	Swab_TimeTag_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_startFor(
	Swab_TimeTag_Iterator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_startFor_1(
	Swab_TimeTag_Iterator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_waitUntilFinished(
	Swab_TimeTag_Iterator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_waitUntilFinished_1(
	Swab_TimeTag_Iterator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_stop(
	Swab_TimeTag_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_clear(
	Swab_TimeTag_Iterator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_isRunning(
	Swab_TimeTag_Iterator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_getCaptureDuration(
	Swab_TimeTag_Iterator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Iterator_getConfiguration(
	Swab_TimeTag_Iterator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.IteratorBase
int CVIFUNC Swab_TimeTag_IteratorBase_Dispose(
	Swab_TimeTag_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_start(
	Swab_TimeTag_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_startFor(
	Swab_TimeTag_IteratorBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_startFor_1(
	Swab_TimeTag_IteratorBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_waitUntilFinished(
	Swab_TimeTag_IteratorBase __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_waitUntilFinished_1(
	Swab_TimeTag_IteratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_stop(
	Swab_TimeTag_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_clear(
	Swab_TimeTag_IteratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_isRunning(
	Swab_TimeTag_IteratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_getCaptureDuration(
	Swab_TimeTag_IteratorBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_IteratorBase_getConfiguration(
	Swab_TimeTag_IteratorBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Sampler
int CVIFUNC Swab_TimeTag_Sampler__Create(
	Swab_TimeTag_Sampler * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int trigger,
	int * channels,
	ssize_t __channelsLength,
	unsigned int max_triggers,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_getData(
	Swab_TimeTag_Sampler __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_getDataAsMask(
	Swab_TimeTag_Sampler __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_Dispose(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_start(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_startFor(
	Swab_TimeTag_Sampler __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_startFor_1(
	Swab_TimeTag_Sampler __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_waitUntilFinished(
	Swab_TimeTag_Sampler __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_waitUntilFinished_1(
	Swab_TimeTag_Sampler __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_stop(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_clear(
	Swab_TimeTag_Sampler __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_isRunning(
	Swab_TimeTag_Sampler __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_getCaptureDuration(
	Swab_TimeTag_Sampler __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Sampler_getConfiguration(
	Swab_TimeTag_Sampler __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope__Create_1(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	int n_traces,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope__Create_2(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	__int64 window_size,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope__Create_3(
	Swab_TimeTag_Scope * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int * event_channels,
	ssize_t __event_channelsLength,
	int trigger_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_ready(
	Swab_TimeTag_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_triggered(
	Swab_TimeTag_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_getData(
	Swab_TimeTag_Scope __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_getWindowSize(
	Swab_TimeTag_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_Dispose(
	Swab_TimeTag_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_start(
	Swab_TimeTag_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_startFor(
	Swab_TimeTag_Scope __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_startFor_1(
	Swab_TimeTag_Scope __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_waitUntilFinished(
	Swab_TimeTag_Scope __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_waitUntilFinished_1(
	Swab_TimeTag_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_stop(
	Swab_TimeTag_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_clear(
	Swab_TimeTag_Scope __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_isRunning(
	Swab_TimeTag_Scope __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_getCaptureDuration(
	Swab_TimeTag_Scope __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Scope_getConfiguration(
	Swab_TimeTag_Scope __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.SoftwareClockState
int CVIFUNC Swab_TimeTag_SoftwareClockState__Create(
	Swab_TimeTag_SoftwareClockState * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_clock_period(
	Swab_TimeTag_SoftwareClockState __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_clock_period(
	Swab_TimeTag_SoftwareClockState __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_input_channel(
	Swab_TimeTag_SoftwareClockState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_input_channel(
	Swab_TimeTag_SoftwareClockState __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_ideal_clock_channel(
	Swab_TimeTag_SoftwareClockState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_ideal_clock_channel(
	Swab_TimeTag_SoftwareClockState __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_averaging_periods(
	Swab_TimeTag_SoftwareClockState __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_averaging_periods(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_enabled(
	Swab_TimeTag_SoftwareClockState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_enabled(
	Swab_TimeTag_SoftwareClockState __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_is_locked(
	Swab_TimeTag_SoftwareClockState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_is_locked(
	Swab_TimeTag_SoftwareClockState __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_error_counter(
	Swab_TimeTag_SoftwareClockState __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_error_counter(
	Swab_TimeTag_SoftwareClockState __instance,
	unsigned int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_last_ideal_clock_event(
	Swab_TimeTag_SoftwareClockState __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_last_ideal_clock_event(
	Swab_TimeTag_SoftwareClockState __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_period_error(
	Swab_TimeTag_SoftwareClockState __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_period_error(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Get_phase_error_estimation(
	Swab_TimeTag_SoftwareClockState __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Set_phase_error_estimation(
	Swab_TimeTag_SoftwareClockState __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SoftwareClockState_Dispose(
	Swab_TimeTag_SoftwareClockState __instance,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.StartStop
int CVIFUNC Swab_TimeTag_StartStop__Create(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop__Create_1(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop__Create_2(
	Swab_TimeTag_StartStop * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_getData(
	Swab_TimeTag_StartStop __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_Dispose(
	Swab_TimeTag_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_start(
	Swab_TimeTag_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_startFor(
	Swab_TimeTag_StartStop __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_startFor_1(
	Swab_TimeTag_StartStop __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_waitUntilFinished(
	Swab_TimeTag_StartStop __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_waitUntilFinished_1(
	Swab_TimeTag_StartStop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_stop(
	Swab_TimeTag_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_clear(
	Swab_TimeTag_StartStop __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_isRunning(
	Swab_TimeTag_StartStop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_getCaptureDuration(
	Swab_TimeTag_StartStop __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_StartStop_getConfiguration(
	Swab_TimeTag_StartStop __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.SynchronizedMeasurements
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements__Create(
	Swab_TimeTag_SynchronizedMeasurements * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_Dispose(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_registerMeasurement(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_IteratorBase measurement,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_unregisterMeasurement(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_IteratorBase measurement,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_clear(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_start(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_stop(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_startFor(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_startFor_1(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_waitUntilFinished(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_waitUntilFinished_1(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_isRunning(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SynchronizedMeasurements_getTagger(
	Swab_TimeTag_SynchronizedMeasurements __instance,
	Swab_TimeTag_TimeTaggerBase * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.SyntheticSingleTag
int CVIFUNC Swab_TimeTag_SyntheticSingleTag__Create(
	Swab_TimeTag_SyntheticSingleTag * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag__Create_1(
	Swab_TimeTag_SyntheticSingleTag * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_trigger(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getChannel(
	Swab_TimeTag_SyntheticSingleTag __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_Dispose(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_start(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_startFor(
	Swab_TimeTag_SyntheticSingleTag __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_startFor_1(
	Swab_TimeTag_SyntheticSingleTag __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_waitUntilFinished(
	Swab_TimeTag_SyntheticSingleTag __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_waitUntilFinished_1(
	Swab_TimeTag_SyntheticSingleTag __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_stop(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_clear(
	Swab_TimeTag_SyntheticSingleTag __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_isRunning(
	Swab_TimeTag_SyntheticSingleTag __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getCaptureDuration(
	Swab_TimeTag_SyntheticSingleTag __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_SyntheticSingleTag_getConfiguration(
	Swab_TimeTag_SyntheticSingleTag __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TT
int CVIFUNC Swab_TimeTag_TT__Create(
	Swab_TimeTag_TT * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_CHANNEL_UNUSED(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_CHANNEL_UNUSED_OLD(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_AUTO(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_ZERO(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_NUMBER_SCHEME_ONE(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_RISING_AND_FALLING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_RISING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_Get_TT_CHANNEL_FALLING_EDGES(
	Swab_TimeTag_ChannelEdge * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_add_logEvent(
	Swab_TimeTag_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_remove_logEvent(
	Swab_TimeTag_TT_TimeTaggerLogger value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_addLogger(
	Swab_TimeTag_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setLogger(
	Swab_TimeTag_TT_TimeTaggerLogger handler,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_removeAllLogger(
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_hasLogger(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_freeTimeTagger(
	Swab_TimeTag_TimeTaggerBase tagger,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getVersion(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTagger(
	char * serial,
	Swab_TimeTag_Resolution resolution,
	Swab_TimeTag_TimeTagger * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTagger_1(
	char * serial,
	Swab_TimeTag_TimeTagger * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTagger_2(
	Swab_TimeTag_TimeTagger * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTaggerVirtual(
	Swab_TimeTag_TimeTaggerVirtual * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTaggerNetwork(
	char * address,
	Swab_TimeTag_TimeTaggerNetwork * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_createTimeTaggerNetwork_1(
	Swab_TimeTag_TimeTaggerNetwork * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setCustomBitFileName(
	char * bitFileName,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_scanTimeTagger(
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getTimeTaggerServerInfo(
	char * address,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getTimeTaggerServerInfo_1(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_scanTimeTaggerServers(
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getTimeTaggerModel(
	char * serial,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setTimeTaggerChannelNumberScheme(
	int scheme,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getTimeTaggerChannelNumberScheme(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_hasTimeTaggerVirtualLicense(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_flashLicense(
	char * serial,
	char * license,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_extractDeviceLicense(
	char * license,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setLanguageInfo(
	unsigned int pw,
	Swab_TimeTag_LanguageUsed language,
	char * version,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setFrontend(
	Swab_TimeTag_FrontendType frontend,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_setUsageStatisticsStatus(
	Swab_TimeTag_UsageStatisticsStatus new_status,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getUsageStatisticsStatus(
	Swab_TimeTag_UsageStatisticsStatus * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_getUsageStatisticsReport(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_mergeStreamFiles(
	char * output_filename,
	char ** input_filenames,
	ssize_t __input_filenamesLength,
	int * channel_offsets,
	ssize_t __channel_offsetsLength,
	__int64 * time_offsets,
	ssize_t __time_offsetsLength,
	int overlap_only,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TT+TimeTaggerLogger
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger__Create(
	Swab_TimeTag_TT_TimeTaggerLogger * __instance,
	SwabianInstruments_TimeTagger_TT_TimeTaggerLogger__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Get_Method(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Get_Target(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Invoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_BeginInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	int level,
	char * message,
	System_AsyncCallback callback,
	CDotNetHandle object,
	System_IAsyncResult * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_EndInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetObjectData(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Equals(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetInvocationList(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_GetHashCode(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_DynamicInvoke(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TT_TimeTaggerLogger_Clone(
	Swab_TimeTag_TT_TimeTaggerLogger __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_1(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	int n_bins,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_2(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	__int64 binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_3(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	int sync_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_4(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	int next_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_5(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	int start_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences__Create_6(
	Swab_TimeTag_TimeDifferences * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int click_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getData(
	Swab_TimeTag_TimeDifferences __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getIndex(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_setMaxCounts(
	Swab_TimeTag_TimeDifferences __instance,
	unsigned __int64 max_counts,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getCounts(
	Swab_TimeTag_TimeDifferences __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getHistogramIndex(
	Swab_TimeTag_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_ready(
	Swab_TimeTag_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_Dispose(
	Swab_TimeTag_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_start(
	Swab_TimeTag_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_startFor(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_startFor_1(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_waitUntilFinished(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_waitUntilFinished_1(
	Swab_TimeTag_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_stop(
	Swab_TimeTag_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_clear(
	Swab_TimeTag_TimeDifferences __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_isRunning(
	Swab_TimeTag_TimeDifferences __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getCaptureDuration(
	Swab_TimeTag_TimeDifferences __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferences_getConfiguration(
	Swab_TimeTag_TimeDifferences __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_getData(
	Swab_TimeTag_TimeDifferencesND __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_getIndex(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_Dispose(
	Swab_TimeTag_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_start(
	Swab_TimeTag_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_startFor(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_startFor_1(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_waitUntilFinished(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_waitUntilFinished_1(
	Swab_TimeTag_TimeDifferencesND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_stop(
	Swab_TimeTag_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_clear(
	Swab_TimeTag_TimeDifferencesND __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_isRunning(
	Swab_TimeTag_TimeDifferencesND __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_getCaptureDuration(
	Swab_TimeTag_TimeDifferencesND __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeDifferencesND_getConfiguration(
	Swab_TimeTag_TimeDifferencesND __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagStream
int CVIFUNC Swab_TimeTag_TimeTagStream__Create(
	Swab_TimeTag_TimeTagStream * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	unsigned __int64 n_max_events,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_getCounts(
	Swab_TimeTag_TimeTagStream __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_getData(
	Swab_TimeTag_TimeTagStream __instance,
	Swab_TimeTag_TimeTagStreamBuffer * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_Dispose(
	Swab_TimeTag_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_start(
	Swab_TimeTag_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_startFor(
	Swab_TimeTag_TimeTagStream __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_startFor_1(
	Swab_TimeTag_TimeTagStream __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_waitUntilFinished(
	Swab_TimeTag_TimeTagStream __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_waitUntilFinished_1(
	Swab_TimeTag_TimeTagStream __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_stop(
	Swab_TimeTag_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_clear(
	Swab_TimeTag_TimeTagStream __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_isRunning(
	Swab_TimeTag_TimeTagStream __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_getCaptureDuration(
	Swab_TimeTag_TimeTagStream __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStream_getConfiguration(
	Swab_TimeTag_TimeTagStream __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagStreamBuffer
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_size(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_size(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned __int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_hasOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_hasOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_tStart(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_tStart(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Get_tGetData(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Set_tGetData(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	__int64 value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_Dispose(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getOverflows(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getChannels(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getTimestamps(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getMissedEvents(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagStreamBuffer_getEventTypes(
	Swab_TimeTag_TimeTagStreamBuffer __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTagger
int CVIFUNC Swab_TimeTag_TimeTagger_reset(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_isChannelRegistered(
	Swab_TimeTag_TimeTagger __instance,
	int chan,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
	int divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getTestSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOutSignal(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int divider,
	double duty_cycle,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOutSignal_1(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOutSignalDivider(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOutSignalDutyCycle(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setAuxOut(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getAuxOut(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setFanSpeed(
	Swab_TimeTag_TimeTagger __instance,
	double percentage,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setFanSpeed_1(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	double voltage,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_measureTriggerLevel(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getHardwareDelayCompensation(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setInputMux(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int mux_mode,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getInputMux(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setConditionalFilter(
	Swab_TimeTag_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	int hardwareDelayCompensation,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setConditionalFilter_1(
	Swab_TimeTag_TimeTagger __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_clearConditionalFilter(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setNormalization(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getNormalization(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setHardwareBufferSize(
	Swab_TimeTag_TimeTagger __instance,
	int size,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getHardwareBufferSize(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setStreamBlockSize(
	Swab_TimeTag_TimeTagger __instance,
	int max_events,
	int max_latency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getStreamBlockSizeEvents(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getStreamBlockSizeLatency(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setEventDivider(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	unsigned int divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getEventDivider(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_autoCalibration(
	Swab_TimeTag_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getSerial(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getModel(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getChannelNumberScheme(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDACRange(
	Swab_TimeTag_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDistributionCount(
	Swab_TimeTag_TimeTagger __instance,
	unsigned __int64 ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDistributionPSecs(
	Swab_TimeTag_TimeTagger __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getChannelList(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_ChannelEdge type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getChannelList_1(
	Swab_TimeTag_TimeTagger __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getPsPerClock(
	Swab_TimeTag_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getPcbVersion(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getFirmwareVersion(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockSource(
	Swab_TimeTag_TimeTagger __instance,
	int source,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getClockSource(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockAutoSelect(
	Swab_TimeTag_TimeTagger __instance,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_getClockAutoSelect(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_xtra_setClockOut(
	Swab_TimeTag_TimeTagger __instance,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getSensorData(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setLED(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int bitmask,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_disableLEDs(
	Swab_TimeTag_TimeTagger __instance,
	int disabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDeviceLicense(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_factoryAccess(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int pw,
	unsigned int addr,
	unsigned int data,
	unsigned int mask,
	int use_wb,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_factoryAccess_1(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int pw,
	unsigned int addr,
	unsigned int data,
	unsigned int mask,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setSoundFrequency(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int freq_hz,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_enableFpgaLink(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	char * destination_mac,
	Swab_TimeTag_FpgaLinkInterface interface_,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_enableFpgaLink_1(
	Swab_TimeTag_TimeTagger __instance,
	int * channels,
	ssize_t __channelsLength,
	char * destination_mac,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_disableFpgaLink(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_startServer(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	int * channels,
	ssize_t __channelsLength,
	unsigned int port,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_startServer_1(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	int * channels,
	ssize_t __channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_startServer_2(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_AccessMode access_mode,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_isServerRunning(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_stopServer(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setTimeTaggerNetworkStreamCompression(
	Swab_TimeTag_TimeTagger __instance,
	int active,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setInputImpedanceHigh(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int high_impedance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getInputImpedanceHigh(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setInputHysteresis(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getInputHysteresis(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_Dispose(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getFence(
	Swab_TimeTag_TimeTagger __instance,
	int alloc_fence,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getFence_1(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_waitForFence(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int fence,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_waitForFence_1(
	Swab_TimeTag_TimeTagger __instance,
	unsigned int fence,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_sync(
	Swab_TimeTag_TimeTagger __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_sync_1(
	Swab_TimeTag_TimeTagger __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getInvertedChannel(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_isUnusedChannel(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getConfiguration(
	Swab_TimeTag_TimeTagger __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setInputDelay(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setDelayHardware(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setDelaySoftware(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getInputDelay(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDelaySoftware(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDelayHardware(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setDeadtime(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getDeadtime(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignal(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setTestSignal_1(
	Swab_TimeTag_TimeTagger __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getTestSignal(
	Swab_TimeTag_TimeTagger __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_1(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_2(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_setSoftwareClock_3(
	Swab_TimeTag_TimeTagger __instance,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_disableSoftwareClock(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getSoftwareClockState(
	Swab_TimeTag_TimeTagger __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getOverflows(
	Swab_TimeTag_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_clearOverflows(
	Swab_TimeTag_TimeTagger __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTagger_getOverflowsAndClear(
	Swab_TimeTag_TimeTagger __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTaggerBase
int CVIFUNC Swab_TimeTag_TimeTaggerBase_Dispose(
	Swab_TimeTag_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getFence(
	Swab_TimeTag_TimeTaggerBase __instance,
	int alloc_fence,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getFence_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_waitForFence(
	Swab_TimeTag_TimeTaggerBase __instance,
	unsigned int fence,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_waitForFence_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	unsigned int fence,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_sync(
	Swab_TimeTag_TimeTaggerBase __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_sync_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getInvertedChannel(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_isUnusedChannel(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getConfiguration(
	Swab_TimeTag_TimeTaggerBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setInputDelay(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDelayHardware(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDelaySoftware(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getInputDelay(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDelaySoftware(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDelayHardware(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setDeadtime(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getDeadtime(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setTestSignal(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setTestSignal_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getTestSignal(
	Swab_TimeTag_TimeTaggerBase __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerBase __instance,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerBase __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getOverflows(
	Swab_TimeTag_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_clearOverflows(
	Swab_TimeTag_TimeTaggerBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerBase_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTaggerNetwork
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_isConnected(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTriggerLevel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	double voltage,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTriggerLevel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setConditionalFilter(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	int hardwareDelayCompensation,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setConditionalFilter_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearConditionalFilter(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignalDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTestSignalDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getTestSignal(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelayClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 time,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelayClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getHardwareDelayCompensation(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setNormalization(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * channels,
	ssize_t __channelsLength,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getNormalization(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setHardwareBufferSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int size,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getHardwareBufferSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setStreamBlockSize(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int max_events,
	int max_latency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getStreamBlockSizeEvents(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getStreamBlockSizeLatency(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setEventDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	unsigned int divider,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getEventDivider(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSerial(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getModel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelNumberScheme(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDACRange(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelList(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	Swab_TimeTag_ChannelEdge type,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getChannelList_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getPsPerClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getPcbVersion(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFirmwareVersion(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSensorData(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setLED(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int bitmask,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDeviceLicense(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoundFrequency(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int freq_hz,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTimeTaggerNetworkStreamCompression(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int active,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearOverflowsClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsAndClearClient(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputImpedanceHigh(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int high_impedance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputImpedanceHigh(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputHysteresis(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputHysteresis(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_Dispose(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFence(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int alloc_fence,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getFence_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_waitForFence(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int fence,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_waitForFence_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	unsigned int fence,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_sync(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_sync_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInvertedChannel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_isUnusedChannel(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getConfiguration(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setInputDelay(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelayHardware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDelaySoftware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getInputDelay(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelaySoftware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDelayHardware(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setDeadtime(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getDeadtime(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignal(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setTestSignal_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflows(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_clearOverflows(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerNetwork_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerNetwork __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TimeTaggerVirtual
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	int queue,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	__int64 duration,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	char * file,
	__int64 begin,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_replay_3(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	char * file,
	unsigned __int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_stop(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_reset(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned __int64 ID,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForCompletion_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setReplaySpeed(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	double speed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getReplaySpeed(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setConditionalFilter(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int * trigger,
	ssize_t __triggerLength,
	int * filtered,
	ssize_t __filteredLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_clearConditionalFilter(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConditionalFilterTrigger(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConditionalFilterFiltered(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getChannelList(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_Dispose(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getFence(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int alloc_fence,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getFence_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForFence(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned int fence,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_waitForFence_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	unsigned int fence,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_sync(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_sync_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getInvertedChannel(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_isUnusedChannel(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getConfiguration(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setInputDelay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDelayHardware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDelaySoftware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getInputDelay(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDelaySoftware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDelayHardware(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setDeadtime(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 deadtime,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getDeadtime(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setTestSignal(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setTestSignal_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int * channel,
	ssize_t __channelLength,
	int enabled,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getTestSignal(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int channel,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	int wait_until_locked,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_1(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	double averaging_periods,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_2(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	double input_frequency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_setSoftwareClock_3(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_disableSoftwareClock(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getSoftwareClockState(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	Swab_TimeTag_SoftwareClockState * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getOverflows(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_clearOverflows(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TimeTaggerVirtual_getOverflowsAndClear(
	Swab_TimeTag_TimeTaggerVirtual __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TriggerOnCountrate
int CVIFUNC Swab_TimeTag_TriggerOnCountrate__Create(
	Swab_TimeTag_TriggerOnCountrate * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double reference_countrate,
	double hysteresis,
	__int64 time_window,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannelAbove(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannelBelow(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getChannels(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isAbove(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isBelow(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getCurrentCountrate(
	Swab_TimeTag_TriggerOnCountrate __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_injectCurrentState(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_Dispose(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_start(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_startFor(
	Swab_TimeTag_TriggerOnCountrate __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_startFor_1(
	Swab_TimeTag_TriggerOnCountrate __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_waitUntilFinished(
	Swab_TimeTag_TriggerOnCountrate __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_waitUntilFinished_1(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_stop(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_clear(
	Swab_TimeTag_TriggerOnCountrate __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_isRunning(
	Swab_TimeTag_TriggerOnCountrate __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getCaptureDuration(
	Swab_TimeTag_TriggerOnCountrate __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TriggerOnCountrate_getConfiguration(
	Swab_TimeTag_TriggerOnCountrate __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CoincidencesFactory
int CVIFUNC Swab_TimeTag_CoincidencesFactory__Create(
	Swab_TimeTag_CoincidencesFactory * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CoincidencesFactory_addCoincidenceGroup(
	Swab_TimeTag_CoincidencesFactory __instance,
	int * array1d,
	ssize_t __array1dLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CoincidencesFactory_getChannels(
	Swab_TimeTag_CoincidencesFactory __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CoincidencesFactory_addCoincidenceGroups(
	Swab_TimeTag_CoincidencesFactory __instance,
	int * array2d,
	ssize_t __array2dLength1,
	ssize_t __array2dLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CoincidencesFactory_createCoincidences(
	Swab_TimeTag_CoincidencesFactory __instance,
	Swab_TimeTag_TimeTagger tagger,
	__int64 coincidenceWindow,
	Swab_TimeTag_CoincidenceTimestamp coincidenceType,
	Swab_TimeTag_Coincidences * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CoincidencesFactory_createCoincidences_1(
	Swab_TimeTag_CoincidencesFactory __instance,
	Swab_TimeTag_TimeTagger tagger,
	__int64 coincidenceWindow,
	Swab_TimeTag_Coincidences * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.CustomMeasurement
int CVIFUNC Swab_TimeTag_CustomMeasurement__Create(
	Swab_TimeTag_CustomMeasurement * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_register_channel(
	Swab_TimeTag_CustomMeasurement __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_unregister_channel(
	Swab_TimeTag_CustomMeasurement __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_finalize_init(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_is_running(
	Swab_TimeTag_CustomMeasurement __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement__lock(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement__unlock(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_Dispose(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_start(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_startFor(
	Swab_TimeTag_CustomMeasurement __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_startFor_1(
	Swab_TimeTag_CustomMeasurement __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_waitUntilFinished(
	Swab_TimeTag_CustomMeasurement __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_waitUntilFinished_1(
	Swab_TimeTag_CustomMeasurement __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_stop(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_clear(
	Swab_TimeTag_CustomMeasurement __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_isRunning(
	Swab_TimeTag_CustomMeasurement __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_getCaptureDuration(
	Swab_TimeTag_CustomMeasurement __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_CustomMeasurement_getConfiguration(
	Swab_TimeTag_CustomMeasurement __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase__Create_5(
	Swab_TimeTag_FlimBase * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_add_FrameReadyEvent(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_remove_FrameReadyEvent(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_registerOnFrameReadyCallback(
	Swab_TimeTag_FlimBase __instance,
	Swab_TimeTag_FlimBase_FrameReadyCallback callback,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_initialize(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_isAcquiring(
	Swab_TimeTag_FlimBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_Dispose(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_start(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_startFor(
	Swab_TimeTag_FlimBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_startFor_1(
	Swab_TimeTag_FlimBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_waitUntilFinished(
	Swab_TimeTag_FlimBase __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_waitUntilFinished_1(
	Swab_TimeTag_FlimBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_stop(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_clear(
	Swab_TimeTag_FlimBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_isRunning(
	Swab_TimeTag_FlimBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_getCaptureDuration(
	Swab_TimeTag_FlimBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_getConfiguration(
	Swab_TimeTag_FlimBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.FlimBase+FrameReadyCallback
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback__Create(
	Swab_TimeTag_FlimBase_FrameReadyCallback * __instance,
	SwabianInstruments_TimeTagger_FlimBase_FrameReadyCallback__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Get_Method(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Get_Target(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_EndInvoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetObjectData(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Equals(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetInvocationList(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_GetHashCode(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_DynamicInvoke(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_FlimBase_FrameReadyCallback_Clone(
	Swab_TimeTag_FlimBase_FrameReadyCallback __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Flim
int CVIFUNC Swab_TimeTag_Flim__Create(
	Swab_TimeTag_Flim * __instance,
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim__Create_1(
	Swab_TimeTag_Flim * __instance,
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim__Create_2(
	Swab_TimeTag_Flim * __instance,
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim__Create_3(
	Swab_TimeTag_Flim * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	int frame_begin_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim__Create_4(
	Swab_TimeTag_Flim * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	int pixel_end_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim__Create_5(
	Swab_TimeTag_Flim * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int start_channel,
	int click_channel,
	int pixel_begin_channel,
	unsigned int n_pixels,
	unsigned int n_bins,
	unsigned int binwidth,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_add_FrameReadyEvent(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_Flim_FrameReadyCallback value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_remove_FrameReadyEvent(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_Flim_FrameReadyCallback value,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_registerOnFrameReadyCallback(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_Flim_FrameReadyCallback callback,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_initialize(
	Swab_TimeTag_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrame(
	Swab_TimeTag_Flim __instance,
	int index,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrame_1(
	Swab_TimeTag_Flim __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrameIntensity(
	Swab_TimeTag_Flim __instance,
	int index,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrameIntensity_1(
	Swab_TimeTag_Flim __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getCurrentFrame(
	Swab_TimeTag_Flim __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getCurrentFrameIntensity(
	Swab_TimeTag_Flim __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFrames(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	int clear_summed,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFrames_1(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFrames_2(
	Swab_TimeTag_Flim __instance,
	unsigned int ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesIntensity(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	int clear_summed,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesIntensity_1(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesIntensity_2(
	Swab_TimeTag_Flim __instance,
	float ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrameEx(
	Swab_TimeTag_Flim __instance,
	int index,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getReadyFrameEx_1(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getCurrentFrameEx(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesEx(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	int clear_summed,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesEx_1(
	Swab_TimeTag_Flim __instance,
	int only_ready_frames,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getSummedFramesEx_2(
	Swab_TimeTag_Flim __instance,
	Swab_TimeTag_FlimFrameInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getFramesAcquired(
	Swab_TimeTag_Flim __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getIndex(
	Swab_TimeTag_Flim __instance,
	__int64 ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_isAcquiring(
	Swab_TimeTag_Flim __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_Dispose(
	Swab_TimeTag_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_start(
	Swab_TimeTag_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_startFor(
	Swab_TimeTag_Flim __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_startFor_1(
	Swab_TimeTag_Flim __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_waitUntilFinished(
	Swab_TimeTag_Flim __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_waitUntilFinished_1(
	Swab_TimeTag_Flim __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_stop(
	Swab_TimeTag_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_clear(
	Swab_TimeTag_Flim __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_isRunning(
	Swab_TimeTag_Flim __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getCaptureDuration(
	Swab_TimeTag_Flim __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_getConfiguration(
	Swab_TimeTag_Flim __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Flim+FrameReadyCallback
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback__Create(
	Swab_TimeTag_Flim_FrameReadyCallback * __instance,
	SwabianInstruments_TimeTagger_Flim_FrameReadyCallback__Callback_t __userCallback,
	void * __userCallbackData,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_Get_Method(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	System_Reflection_MethodInfo * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_Get_Target(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_Invoke(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	unsigned int frame_number,
	unsigned int * data,
	ssize_t __dataLength,
	__int64 * pixel_begin_times,
	ssize_t __pixel_begin_timesLength,
	__int64 * pixel_end_times,
	ssize_t __pixel_end_timesLength,
	__int64 frame_begin_time,
	__int64 frame_end_time,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_BeginInvoke(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
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
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_EndInvoke(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	System_IAsyncResult result,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_GetObjectData(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	System_Runtime_Serialization_SerializationInfo info,
	System_Runtime_Serialization_StreamingContext context,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_Equals(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	CDotNetHandle obj,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_GetInvocationList(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	System_Delegate ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_GetHashCode(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_DynamicInvoke(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	CDotNetHandle * args,
	ssize_t __argsLength,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Flim_FrameReadyCallback_Clone(
	Swab_TimeTag_Flim_FrameReadyCallback __instance,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Tag
int CVIFUNC Swab_TimeTag_Tag__Create(
	Swab_TimeTag_Tag * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Get__type(
	Swab_TimeTag_Tag __instance,
	Swab_TimeTag_TagType * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Set__type(
	Swab_TimeTag_Tag __instance,
	Swab_TimeTag_TagType type,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Get__reserved(
	Swab_TimeTag_Tag __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Set__reserved(
	Swab_TimeTag_Tag __instance,
	unsigned char reserved,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Get__missedEvents(
	Swab_TimeTag_Tag __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Set__missedEvents(
	Swab_TimeTag_Tag __instance,
	unsigned short missedEvents,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Get__channel(
	Swab_TimeTag_Tag __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Set__channel(
	Swab_TimeTag_Tag __instance,
	int channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Get__time(
	Swab_TimeTag_Tag __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Tag__Set__time(
	Swab_TimeTag_Tag __instance,
	__int64 time,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.TagBlock
int CVIFUNC Swab_TimeTag_TagBlock__Create(
	Swab_TimeTag_TagBlock * __instance,
	void * nativeTagPtr,
	unsigned __int64 length,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TagBlock_Get_Length(
	Swab_TimeTag_TagBlock __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TagBlock_Get_Item(
	Swab_TimeTag_TagBlock __instance,
	int index,
	Swab_TimeTag_Tag * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_TagBlock_GetEnumerator(
	Swab_TimeTag_TagBlock __instance,
	System_Collections_Generic_IEnumerator_T1 * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.ExponentialSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator__Create(
	Swab_TimeTag_Exp_ExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator__Create_1(
	Swab_TimeTag_Exp_ExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator__Create_2(
	Swab_TimeTag_Exp_ExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_getChannel(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_Dispose(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_start(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_startFor(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_stop(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_clear(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_isRunning(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_ExponentialSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_ExponentialSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.GammaSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator__Create(
	Swab_TimeTag_Exp_GammaSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double alpha,
	double beta,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator__Create_1(
	Swab_TimeTag_Exp_GammaSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double alpha,
	double beta,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator__Create_2(
	Swab_TimeTag_Exp_GammaSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double alpha,
	double beta,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_getChannel(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_Dispose(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_start(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_startFor(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_stop(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_clear(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_isRunning(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GammaSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_GammaSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.GaussianSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator__Create(
	Swab_TimeTag_Exp_GaussianSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double mean,
	double standard_deviation,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator__Create_1(
	Swab_TimeTag_Exp_GaussianSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double mean,
	double standard_deviation,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator__Create_2(
	Swab_TimeTag_Exp_GaussianSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double mean,
	double standard_deviation,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_getChannel(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_Dispose(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_start(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_startFor(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_stop(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_clear(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_isRunning(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_GaussianSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_GaussianSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.MarkovProcessGenerator
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator__Create(
	Swab_TimeTag_Exp_MarkovProcessGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	unsigned __int64 num_states,
	double * frequencies,
	ssize_t __frequenciesLength,
	int * ref_channels,
	ssize_t __ref_channelsLength,
	int * base_channels,
	ssize_t __base_channelsLength,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator__Create_1(
	Swab_TimeTag_Exp_MarkovProcessGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	unsigned __int64 num_states,
	double * frequencies,
	ssize_t __frequenciesLength,
	int * ref_channels,
	ssize_t __ref_channelsLength,
	int * base_channels,
	ssize_t __base_channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator__Create_2(
	Swab_TimeTag_Exp_MarkovProcessGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	unsigned __int64 num_states,
	double * frequencies,
	ssize_t __frequenciesLength,
	int * ref_channels,
	ssize_t __ref_channelsLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_getChannel(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_getChannels(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_Dispose(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_start(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_startFor(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_startFor_1(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_stop(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_clear(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_isRunning(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_MarkovProcessGenerator_getConfiguration(
	Swab_TimeTag_Exp_MarkovProcessGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.PatternSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator__Create(
	Swab_TimeTag_Exp_PatternSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 * sequence,
	ssize_t __sequenceLength,
	int repeat,
	__int64 start_delay,
	__int64 spacing,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator__Create_1(
	Swab_TimeTag_Exp_PatternSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 * sequence,
	ssize_t __sequenceLength,
	int repeat,
	__int64 start_delay,
	__int64 spacing,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator__Create_2(
	Swab_TimeTag_Exp_PatternSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 * sequence,
	ssize_t __sequenceLength,
	int repeat,
	__int64 start_delay,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator__Create_3(
	Swab_TimeTag_Exp_PatternSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 * sequence,
	ssize_t __sequenceLength,
	int repeat,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator__Create_4(
	Swab_TimeTag_Exp_PatternSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 * sequence,
	ssize_t __sequenceLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_getChannel(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_Dispose(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_start(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_startFor(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_stop(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_clear(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_isRunning(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PatternSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_PatternSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.PoissonSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator__Create(
	Swab_TimeTag_Exp_PoissonSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator__Create_1(
	Swab_TimeTag_Exp_PoissonSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator__Create_2(
	Swab_TimeTag_Exp_PoissonSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double rate,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_getChannel(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_Dispose(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_start(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_startFor(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_stop(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_clear(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_isRunning(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_PoissonSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_PoissonSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.SignalGeneratorBase
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_getChannel(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_Dispose(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_start(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_startFor(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_startFor_1(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_waitUntilFinished(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_waitUntilFinished_1(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_stop(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_clear(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_isRunning(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_getCaptureDuration(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SignalGeneratorBase_getConfiguration(
	Swab_TimeTag_Exp_SignalGeneratorBase __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.SimDetector
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	double darkcount_rate,
	double jitter,
	double deadtime,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create_1(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	double darkcount_rate,
	double jitter,
	double deadtime,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create_2(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	double darkcount_rate,
	double jitter,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create_3(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	double darkcount_rate,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create_4(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector__Create_5(
	Swab_TimeTag_Exp_SimDetector * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector_Dispose(
	Swab_TimeTag_Exp_SimDetector __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimDetector_getChannel(
	Swab_TimeTag_Exp_SimDetector __instance,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.SimLifetime
int CVIFUNC Swab_TimeTag_Exp_SimLifetime__Create(
	Swab_TimeTag_Exp_SimLifetime * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double lifetime,
	double emission_rate,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime__Create_1(
	Swab_TimeTag_Exp_SimLifetime * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double lifetime,
	double emission_rate,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime__Create_2(
	Swab_TimeTag_Exp_SimLifetime * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double lifetime,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_getChannel(
	Swab_TimeTag_Exp_SimLifetime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_registerLifetimeReactor(
	Swab_TimeTag_Exp_SimLifetime __instance,
	int trigger_channel,
	double * lifetimes,
	ssize_t __lifetimesLength,
	int repeat,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_registerEmissionReactor(
	Swab_TimeTag_Exp_SimLifetime __instance,
	int trigger_channel,
	double * emissions,
	ssize_t __emissionsLength,
	int repeat,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_Dispose(
	Swab_TimeTag_Exp_SimLifetime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_start(
	Swab_TimeTag_Exp_SimLifetime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_startFor(
	Swab_TimeTag_Exp_SimLifetime __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_startFor_1(
	Swab_TimeTag_Exp_SimLifetime __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_waitUntilFinished(
	Swab_TimeTag_Exp_SimLifetime __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_waitUntilFinished_1(
	Swab_TimeTag_Exp_SimLifetime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_stop(
	Swab_TimeTag_Exp_SimLifetime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_clear(
	Swab_TimeTag_Exp_SimLifetime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_isRunning(
	Swab_TimeTag_Exp_SimLifetime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_getCaptureDuration(
	Swab_TimeTag_Exp_SimLifetime __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimLifetime_getConfiguration(
	Swab_TimeTag_Exp_SimLifetime __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.SimSignalSplitter
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter__Create(
	Swab_TimeTag_Exp_SimSignalSplitter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double ratio,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter__Create_1(
	Swab_TimeTag_Exp_SimSignalSplitter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double ratio,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter__Create_2(
	Swab_TimeTag_Exp_SimSignalSplitter * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_getChannels(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	int ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_getLeftChannel(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_getRightChannel(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_Dispose(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_start(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_startFor(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_startFor_1(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_waitUntilFinished(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_waitUntilFinished_1(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_stop(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_clear(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_isRunning(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_getCaptureDuration(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_SimSignalSplitter_getConfiguration(
	Swab_TimeTag_Exp_SimSignalSplitter __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.TransformCrosstalk
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk__Create(
	Swab_TimeTag_Exp_TransformCrosstalk * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int relay_input_channel,
	double delay,
	double tau,
	int copy,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk__Create_1(
	Swab_TimeTag_Exp_TransformCrosstalk * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	int relay_input_channel,
	double delay,
	double tau,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_getChannel(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_Dispose(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_start(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_startFor(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_startFor_1(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_waitUntilFinished(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_waitUntilFinished_1(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_stop(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_clear(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_isRunning(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_getCaptureDuration(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformCrosstalk_getConfiguration(
	Swab_TimeTag_Exp_TransformCrosstalk __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.TransformDeadtime
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime__Create(
	Swab_TimeTag_Exp_TransformDeadtime * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double deadtime,
	int copy,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime__Create_1(
	Swab_TimeTag_Exp_TransformDeadtime * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double deadtime,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_getChannel(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_Dispose(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_start(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_startFor(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_startFor_1(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_waitUntilFinished(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_waitUntilFinished_1(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_stop(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_clear(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_isRunning(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_getCaptureDuration(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformDeadtime_getConfiguration(
	Swab_TimeTag_Exp_TransformDeadtime __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.TransformEfficiency
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency__Create(
	Swab_TimeTag_Exp_TransformEfficiency * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	int copy,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency__Create_1(
	Swab_TimeTag_Exp_TransformEfficiency * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	int copy,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency__Create_2(
	Swab_TimeTag_Exp_TransformEfficiency * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double efficiency,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_getChannel(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_Dispose(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_start(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_startFor(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_startFor_1(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_waitUntilFinished(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_waitUntilFinished_1(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_stop(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_clear(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_isRunning(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_getCaptureDuration(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformEfficiency_getConfiguration(
	Swab_TimeTag_Exp_TransformEfficiency __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.TransformGaussianBroadening
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening__Create(
	Swab_TimeTag_Exp_TransformGaussianBroadening * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double standard_deviation,
	int copy,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening__Create_1(
	Swab_TimeTag_Exp_TransformGaussianBroadening * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double standard_deviation,
	int copy,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening__Create_2(
	Swab_TimeTag_Exp_TransformGaussianBroadening * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	int input_channel,
	double standard_deviation,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_getChannel(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_Dispose(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_start(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_startFor(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_startFor_1(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_waitUntilFinished(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_waitUntilFinished_1(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_stop(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_clear(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_isRunning(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_getCaptureDuration(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TransformGaussianBroadening_getConfiguration(
	Swab_TimeTag_Exp_TransformGaussianBroadening __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.TwoStateExponentialSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator__Create(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double excitation_time,
	double life_time,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator__Create_1(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double excitation_time,
	double life_time,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator__Create_2(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	double excitation_time,
	double life_time,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_getChannel(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_Dispose(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_start(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_startFor(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_stop(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_clear(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_isRunning(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_TwoStateExponentialSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: SwabianInstruments.TimeTagger.Experimental.UniformSignalGenerator
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator__Create(
	Swab_TimeTag_Exp_UniformSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 upper_bound,
	__int64 lower_bound,
	int base_channel,
	int seed,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator__Create_1(
	Swab_TimeTag_Exp_UniformSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 upper_bound,
	__int64 lower_bound,
	int base_channel,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator__Create_2(
	Swab_TimeTag_Exp_UniformSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 upper_bound,
	__int64 lower_bound,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator__Create_3(
	Swab_TimeTag_Exp_UniformSignalGenerator * __instance,
	Swab_TimeTag_TimeTaggerBase tagger,
	__int64 upper_bound,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_getChannel(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_Dispose(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_start(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_startFor(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	__int64 capture_duration,
	int clear,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_startFor_1(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	__int64 capture_duration,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_waitUntilFinished(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	__int64 timeout,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_waitUntilFinished_1(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_stop(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_clear(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_isRunning(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_getCaptureDuration(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Swab_TimeTag_Exp_UniformSignalGenerator_getConfiguration(
	Swab_TimeTag_Exp_UniformSignalGenerator __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
