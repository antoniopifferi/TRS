// *****************************************************************************
// * wlmData.h                                                                 *
// *   (header file for wlmData.dll)                                           *
// *                                                                2023-08-11 *
// *****************************************************************************

// Copyright (C) 2023 HighFinesse Laser and Electronic Systems GmbH
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef WLMDATA_H_
	// Avoid reentrance
	#define WLMDATA_H_


	// WLMDATA_EXPORTS must not be defined for any project using this dll.
	#ifdef _WIN32
		#ifdef WLMDATA_EXPORTS
			#define DLL_IM_EXPORT __declspec(dllexport)
		#else
			#define DLL_IM_EXPORT __declspec(dllimport)
		#endif
		#define DLL_CALL_CONVENTION __stdcall
	#else
		#ifdef WLMDATA_EXPORTS
			#define DLL_IM_EXPORT __attribute__((visibility("default")))
		#else
			#define DLL_IM_EXPORT
		#endif
		#define DLL_CALL_CONVENTION
	#endif

	#ifdef __cplusplus
		#define NOT_MANGLED extern "C"
	#else
		#define NOT_MANGLED
	#endif

	#define Data_API(ret) NOT_MANGLED DLL_IM_EXPORT ret DLL_CALL_CONVENTION


//	define WLMDATA_OLD_COMPAT if your code requires compatibility to the formerly used variables types
//	#define WLMDATA_OLD_COMPAT 

	#ifdef WLMDATA_OLD_COMPAT 
		typedef short             t_i16val;
		typedef unsigned short    t_u16val;
		typedef long              t_i32val;
		typedef unsigned long     t_u32val;
		typedef __int64           t_i64val;
		typedef unsigned __int64  t_u64val;
		typedef double            t_dblval;
		#ifdef _WIN64
			typedef t_i64val      t_i__ptr;
			typedef t_u64val      t_u__ptr;
		#else
		    typedef t_i32val      t_i__ptr;
			typedef t_u32val      t_u__ptr;
		#endif
	#else
		#include <stdint.h>

		typedef int16_t           t_i16val;
		typedef uint16_t          t_u16val;
		typedef int32_t           t_i32val;
		typedef uint32_t          t_u32val;
		typedef int64_t           t_i64val;
		typedef double            t_dblval;
		typedef intptr_t          t_i__ptr;
		typedef uintptr_t         t_u__ptr;
	#endif

	#ifdef __cplusplus
		typedef t_i32val &        t_i32ref;
		typedef t_i64val &        t_i64ref;
		typedef t_dblval &        t_dblref;
		typedef char &            t_strref;
	#else
		typedef t_i32val *        t_i32ref;
		typedef t_i64val *        t_i64ref;
		typedef t_dblval *        t_dblref;
		typedef char *            t_strref;
	#endif

	#ifndef __cplusplus
		#ifndef bool
			typedef unsigned char bool;
		#endif
		#ifndef true 
			#define true  1
		#endif
		#ifndef false 
			#define false 0
		#endif
	#endif


// ***********  Functions for general usage  ****************************
	Data_API(t_i__ptr)        Instantiate(t_i32val RFC,   t_i32val Mode,   t_i__ptr P1,   t_i32val P2) ;

//	void __stdcall            CallbackProc(t_i32val Mode,   t_i32val IntVal,   t_dblval DblVal) ;
//	void __stdcall            CallbackProcEx(t_i32val Ver,   t_i32val Mode,   t_i32val IntVal,   t_dblval DblVal,   t_i32val Res1) ;
	Data_API(t_i32val)        WaitForWLMEvent(t_i32ref Mode,   t_i32ref IntVal,   t_dblref DblVal) ;
	Data_API(t_i32val)        WaitForWLMEventEx(t_i32ref Ver,   t_i32ref Mode,   t_i32ref IntVal,   t_dblref DblVal,   t_i32ref Res1) ;
	Data_API(t_i32val)        WaitForNextWLMEvent(t_i32ref Mode,   t_i32ref IntVal,   t_dblref DblVal) ;
	Data_API(t_i32val)        WaitForNextWLMEventEx(t_i32ref Ver,   t_i32ref Mode,   t_i32ref IntVal,   t_dblref DblVal,   t_i32ref Res1) ;
	Data_API(void)            ClearWLMEvents(void) ;

	Data_API(t_i32val)        ControlWLM(t_i32val Action,   t_i__ptr App,   t_i32val Ver) ;
	Data_API(t_i32val)        ControlWLMEx(t_i32val Action,   t_i__ptr App,   t_i32val Ver,   t_i32val Delay,   t_i32val Res) ;
	Data_API(t_i64val)        SynchroniseWLM(t_i32val Mode,   t_i64val TS) ;
	Data_API(t_i32val)        SetMeasurementDelayMethod(t_i32val Mode,   t_i32val Delay) ;
	Data_API(t_i32val)        SetWLMPriority(t_i32val PPC,   t_i32val Res1,   t_i32val Res2) ;
	Data_API(t_i32val)        PresetWLMIndex(t_i32val Ver) ;

	Data_API(t_i32val)        GetWLMVersion(t_i32val Ver) ;
	Data_API(t_i32val)        GetWLMIndex(t_i32val Ver) ;
	Data_API(t_i32val)        GetWLMCount(t_i32val V) ;


// ***********  General Get... & Set...-functions  **********************
	Data_API(t_dblval)        GetWavelength(t_dblval WL) ;
	Data_API(t_dblval)        GetWavelength2(t_dblval WL2) ;
	Data_API(t_dblval)        GetWavelengthNum(t_i32val num,   t_dblval WL) ;
	Data_API(t_dblval)        GetCalWavelength(t_i32val ba,   t_dblval WL) ;
	Data_API(t_dblval)        GetCalibrationEffect(t_dblval CE) ;
	Data_API(t_dblval)        GetFrequency(t_dblval F) ;
	Data_API(t_dblval)        GetFrequency2(t_dblval F2) ;
	Data_API(t_dblval)        GetFrequencyNum(t_i32val num,   t_dblval F) ;
	Data_API(t_dblval)        GetLinewidth(t_i32val Index,   t_dblval LW) ;
	Data_API(t_dblval)        GetLinewidthNum(t_i32val num,   t_dblval LW) ;
	Data_API(t_dblval)        GetDistance(t_dblval D) ;
	Data_API(t_dblval)        GetAnalogIn(t_dblval AI) ;
	Data_API(t_dblval)        GetMultimodeInfo(t_i32val num,   t_i32val type,   t_i32val mode,   t_dblref Val) ;
	Data_API(t_i32val)        GetResultInfo(t_i32val num,   t_i32val info) ;
	Data_API(t_dblval)        GetMeasurementUncertainty(t_i32val Index,   t_i32val num,   t_dblval MU);
	Data_API(t_dblval)        GetTemperature(t_dblval T) ;
	Data_API(t_i32val)        SetTemperature(t_dblval T) ;
	Data_API(t_dblval)        GetPressure(t_dblval P) ;
	Data_API(t_i32val)        SetPressure(t_i32val Mode,   t_dblval P) ;
	Data_API(t_i32val)        GetAirParameters(t_i32val Mode,   t_i32ref State,   t_dblref Val) ;
	Data_API(t_i32val)        SetAirParameters(t_i32val Mode,   t_i32val State,   t_dblval Val) ;
	Data_API(t_dblval)        GetExternalInput(t_i32val Index,   t_dblval I) ;
	Data_API(t_i32val)        SetExternalInput(t_i32val Index,   t_dblval I) ;
	Data_API(t_i32val)        GetExtraSetting(t_i32val Index,   t_i32ref lGet,   t_dblref dGet,   t_strref sGet) ;
	Data_API(t_i32val)        SetExtraSetting(t_i32val Index,   t_i32val lSet,   t_dblval dSet,   t_strref sSet) ;

	Data_API(t_u16val)        GetExposure(t_u16val E) ;
	Data_API(t_i32val)        SetExposure(t_u16val E) ;
	Data_API(t_u16val)        GetExposure2(t_u16val E2) ;
	Data_API(t_i32val)        SetExposure2(t_u16val E2) ;
	Data_API(t_i32val)        GetExposureNum(t_i32val num,   t_i32val arr,   t_i32val E) ;
	Data_API(t_i32val)        SetExposureNum(t_i32val num,   t_i32val arr,   t_i32val E) ;
	Data_API(t_dblval)        GetExposureNumEx(t_i32val num,   t_i32val arr,   t_dblval E) ;
	Data_API(t_i32val)        SetExposureNumEx(t_i32val num,   t_i32val arr,   t_dblval E) ;
	Data_API(bool)            GetExposureMode(bool EM) ;
	Data_API(t_i32val)        SetExposureMode(bool EM) ;
	Data_API(t_i32val)        GetExposureModeNum(t_i32val num, bool EM) ;
	Data_API(t_i32val)        SetExposureModeNum(t_i32val num, bool EM) ;
	Data_API(t_i32val)        GetExposureRange(t_i32val ER) ;
	Data_API(t_dblval)        GetExposureRangeEx(t_i32val ER) ;
	Data_API(t_i32val)        GetAutoExposureSetting(t_i32val num,   t_i32val AES,   t_i32ref iVal,   t_dblref dVal) ;
	Data_API(t_i32val)        SetAutoExposureSetting(t_i32val num,   t_i32val AES,   t_i32val iVal,   t_dblval dVal) ;

	Data_API(t_u16val)        GetResultMode(t_u16val RM) ;
	Data_API(t_i32val)        SetResultMode(t_u16val RM) ;
	Data_API(t_u16val)        GetRange(t_u16val R) ;
	Data_API(t_i32val)        SetRange(t_u16val R) ;
	Data_API(t_u16val)        GetPulseMode(t_u16val PM) ;
	Data_API(t_i32val)        SetPulseMode(t_u16val PM) ;
	Data_API(t_i32val)        GetPulseDelay(t_i32val PD) ;
	Data_API(t_i32val)        SetPulseDelay(t_i32val PD) ;
	Data_API(t_i32val)        GetPulseIntegration(t_i32val PI) ;
	Data_API(t_i32val)        SetPulseIntegration(t_i32val PI) ;
	Data_API(t_u16val)        GetWideMode(t_u16val WM) ;
	Data_API(t_i32val)        SetWideMode(t_u16val WM) ;

	Data_API(t_i32val)        GetDisplayMode(t_i32val DM) ;
	Data_API(t_i32val)        SetDisplayMode(t_i32val DM) ;
	Data_API(bool)            GetFastMode(bool FM) ;
	Data_API(t_i32val)        SetFastMode(bool FM) ;

	Data_API(bool)            GetLinewidthMode(bool LM) ;
	Data_API(t_i32val)        SetLinewidthMode(bool LM) ;

	Data_API(bool)            GetDistanceMode(bool DM) ;
	Data_API(t_i32val)        SetDistanceMode(bool DM) ;

	Data_API(t_i32val)        GetSwitcherMode(t_i32val SM) ;
	Data_API(t_i32val)        SetSwitcherMode(t_i32val SM) ;
	Data_API(t_i32val)        GetSwitcherChannel(t_i32val CH) ;
	Data_API(t_i32val)        SetSwitcherChannel(t_i32val CH) ;
	Data_API(t_i32val)        GetSwitcherSignalStates(t_i32val Signal,   t_i32ref Use,   t_i32ref Show) ;
	Data_API(t_i32val)        SetSwitcherSignalStates(t_i32val Signal,   t_i32val Use,   t_i32val Show) ;
	Data_API(t_i32val)        SetSwitcherSignal(t_i32val Signal,   t_i32val Use,   t_i32val Show) ;

	Data_API(t_i32val)        GetAutoCalMode(t_i32val ACM) ;
	Data_API(t_i32val)        SetAutoCalMode(t_i32val ACM) ;
	Data_API(t_i32val)        GetAutoCalSetting(t_i32val ACS,   t_i32ref val,   t_i32val Res1,   t_i32ref Res2) ;
	Data_API(t_i32val)        SetAutoCalSetting(t_i32val ACS,   t_i32val val,   t_i32val Res1,   t_i32val Res2) ;

	Data_API(t_i32val)        GetActiveChannel(t_i32val Mode,   t_i32ref Port,   t_i32val Res1) ;
	Data_API(t_i32val)        SetActiveChannel(t_i32val Mode,   t_i32val Port,   t_i32val CH,   t_i32val Res1) ;
	Data_API(t_i32val)        GetChannelsCount(t_i32val C) ;

	Data_API(t_u16val)        GetOperationState(t_u16val OS) ;
	Data_API(t_i32val)        Operation(t_u16val Op) ;
	Data_API(t_i32val)        SetOperationFile(t_strref lpFile) ;
	Data_API(t_i32val)        Calibration(t_i32val Type,   t_i32val Unit,   t_dblval Value,   t_i32val Channel) ;
	Data_API(t_i32val)        PowerCalibration(t_i32val Unit,   t_dblval Value,   t_i32val Channel,   t_i32val Options,   t_i32val Res) ;
	Data_API(t_i32val)        RaiseMeasurementEvent(t_i32val Mode) ;
	Data_API(t_i32val)        TriggerMeasurement(t_i32val Action) ;
	Data_API(t_i32val)        GetTriggerState(t_i32val TS) ;
	Data_API(t_i32val)        GetInterval(t_i32val I) ;
	Data_API(t_i32val)        SetInterval(t_i32val I) ;
	Data_API(bool)            GetIntervalMode(bool IM) ;
	Data_API(t_i32val)        SetIntervalMode(bool IM) ;
	Data_API(t_dblval)        GetInternalTriggerRate(t_dblval TR) ;
	Data_API(t_i32val)        SetInternalTriggerRate(t_dblval TR) ;
	Data_API(t_i32val)        GetBackground(t_i32val BG) ;
	Data_API(t_i32val)        SetBackground(t_i32val BG) ;
	Data_API(t_i32val)        GetAveragingSettingNum(t_i32val num,   t_i32val AS,   t_i32val Value) ;
	Data_API(t_i32val)        SetAveragingSettingNum(t_i32val num,   t_i32val AS,   t_i32val Value) ;

	Data_API(bool)            GetLinkState(bool LS) ;
	Data_API(t_i32val)        SetLinkState(bool LS) ;
	Data_API(void)            LinkSettingsDlg(void) ;

	Data_API(t_i32val)        GetPatternItemSize(t_i32val Index) ;
	Data_API(t_i32val)        GetPatternItemCount(t_i32val Index) ;
	Data_API(t_u__ptr)        GetPattern(t_i32val Index) ;
	Data_API(t_u__ptr)        GetPatternNum(t_i32val Chn,   t_i32val Index) ;
	Data_API(t_i32val)        GetPatternData(t_i32val Index,   t_u__ptr PArray) ;
	Data_API(t_i32val)        GetPatternDataNum(t_i32val Chn,   t_i32val Index,   t_u__ptr PArray) ;
	Data_API(t_i32val)        SetPattern(t_i32val Index,   t_i32val iEnable) ;
	Data_API(t_i32val)        SetPatternData(t_i32val Index,   t_u__ptr PArray) ;

	Data_API(bool)            GetAnalysisMode(bool AM) ;
	Data_API(t_i32val)        SetAnalysisMode(bool AM) ;
	Data_API(t_i32val)        GetAnalysisItemSize(t_i32val Index) ;
	Data_API(t_i32val)        GetAnalysisItemCount(t_i32val Index) ;
	Data_API(t_u__ptr)        GetAnalysis(t_i32val Index) ;
	Data_API(t_i32val)        GetAnalysisData(t_i32val Index,   t_u__ptr PArray) ;
	Data_API(t_i32val)        SetAnalysis(t_i32val Index,   t_i32val iEnable) ;

	Data_API(t_i32val)        GetMinPeak(t_i32val M1) ;
	Data_API(t_i32val)        GetMinPeak2(t_i32val M2) ;
	Data_API(t_i32val)        GetMaxPeak(t_i32val X1) ;
	Data_API(t_i32val)        GetMaxPeak2(t_i32val X2) ;
	Data_API(t_i32val)        GetAvgPeak(t_i32val A1) ;
	Data_API(t_i32val)        GetAvgPeak2(t_i32val A2) ;
	Data_API(t_i32val)        SetAvgPeak(t_i32val PA) ;

	Data_API(t_i32val)        GetAmplitudeNum(t_i32val num,   t_i32val Index,   t_i32val A) ;
	Data_API(t_dblval)        GetIntensityNum(t_i32val num,   t_dblval I) ;
	Data_API(t_dblval)        GetPowerNum(t_i32val num,   t_dblval P) ;

	Data_API(t_u16val)        GetDelay(t_u16val D) ;
	Data_API(t_i32val)        SetDelay(t_u16val D) ;
	Data_API(t_u16val)        GetShift(t_u16val S) ;
	Data_API(t_i32val)        SetShift(t_u16val S) ;
	Data_API(t_u16val)        GetShift2(t_u16val S2) ;
	Data_API(t_i32val)        SetShift2(t_u16val S2) ;
	Data_API(t_dblval)        GetGain(t_i32val num,   t_i32val index,   t_i32val mode,   t_dblref Gain) ;
	Data_API(t_i32val)        SetGain(t_i32val num,   t_i32val index,   t_i32val mode,   t_dblval Gain) ;


// ***********  Deviation (Laser Control) and PID-functions  ************
	Data_API(bool)            GetDeviationMode(bool DM) ;
	Data_API(t_i32val)        SetDeviationMode(bool DM) ;
	Data_API(t_dblval)        GetDeviationReference(t_dblval DR) ;
	Data_API(t_i32val)        SetDeviationReference(t_dblval DR) ;
	Data_API(t_i32val)        GetDeviationSensitivity(t_i32val DS) ;
	Data_API(t_i32val)        SetDeviationSensitivity(t_i32val DS) ;
	Data_API(t_dblval)        GetDeviationSignal(t_dblval DS) ;
	Data_API(t_dblval)        GetDeviationSignalNum(t_i32val Port,   t_dblval DS) ;
	Data_API(t_i32val)        SetDeviationSignal(t_dblval DS) ;
	Data_API(t_i32val)        SetDeviationSignalNum(t_i32val Port,   t_dblval DS) ;
	Data_API(t_dblval)        RaiseDeviationSignal(t_i32val iType,   t_dblval dSignal) ;

	Data_API(t_i32val)        GetPIDCourse(t_strref PIDC) ;
	Data_API(t_i32val)        SetPIDCourse(t_strref PIDC) ;
	Data_API(t_i32val)        GetPIDCourseNum(t_i32val Port,   t_strref PIDC) ;
	Data_API(t_i32val)        SetPIDCourseNum(t_i32val Port,   t_strref PIDC) ;
	Data_API(t_i32val)        GetPIDSetting(t_i32val PS,   t_i32val Port,   t_i32ref iSet,   t_dblref dSet) ;
	Data_API(t_i32val)        SetPIDSetting(t_i32val PS,   t_i32val Port,   t_i32val iSet,   t_dblval dSet) ;
	Data_API(t_i32val)        GetLaserControlSetting(t_i32val PS,   t_i32val Port,   t_i32ref iSet,   t_dblref dSet,   t_strref sSet) ;
	Data_API(t_i32val)        SetLaserControlSetting(t_i32val PS,   t_i32val Port,   t_i32val iSet,   t_dblval dSet,   t_strref sSet) ;
	Data_API(t_i32val)        ClearPIDHistory(t_i32val Port) ;


// ***********  Other...-functions  *************************************
	Data_API(t_dblval)        ConvertUnit(t_dblval Val,   t_i32val uFrom,   t_i32val uTo) ;
	Data_API(t_dblval)        ConvertDeltaUnit(t_dblval Base,   t_dblval Delta,   t_i32val uBase,   t_i32val uFrom,   t_i32val uTo) ;


// ***********  Obsolete...-functions  **********************************
	Data_API(bool)            GetReduced(bool R) ;
	Data_API(t_i32val)        SetReduced(bool R) ;
	Data_API(t_u16val)        GetScale(t_u16val S) ;
	Data_API(t_i32val)        SetScale(t_u16val S) ;


// ***********  Constants  **********************************************

// Instantiating Constants for 'RFC' parameter
	const t_i32val	cInstCheckForWLM = -1;
	const t_i32val	cInstResetCalc = 0;
	const t_i32val	cInstReturnMode = cInstResetCalc;
	const t_i32val	cInstNotification = 1;
	const t_i32val	cInstCopyPattern = 2;
	const t_i32val	cInstCopyAnalysis = cInstCopyPattern;
	const t_i32val	cInstControlWLM = 3;
	const t_i32val	cInstControlDelay = 4;
	const t_i32val	cInstControlPriority = 5;
	const t_i32val	cInstNetworkControl = 6;

// Notification Constants for 'Mode' parameter
	const t_i32val	cNotifyInstallCallback = 0;
	const t_i32val	cNotifyRemoveCallback = 1;
	const t_i32val	cNotifyInstallWaitEvent = 2;
	const t_i32val	cNotifyRemoveWaitEvent = 3;
	const t_i32val	cNotifyInstallCallbackEx = 4;
	const t_i32val	cNotifyInstallWaitEventEx = 5;

// ResultError Constants of Set...-functions
	const t_i32val	ResERR_NoErr = 0;
	const t_i32val	ResERR_WlmMissing = -1;
	const t_i32val	ResERR_CouldNotSet = -2;
	const t_i32val	ResERR_ParmOutOfRange = -3;
	const t_i32val	ResERR_WlmOutOfResources = -4;
	const t_i32val	ResERR_WlmInternalError = -5;
	const t_i32val	ResERR_NotAvailable = -6;
	const t_i32val	ResERR_WlmBusy = -7;
	const t_i32val	ResERR_NotInMeasurementMode = -8;
	const t_i32val	ResERR_OnlyInMeasurementMode = -9;
	const t_i32val	ResERR_ChannelNotAvailable = -10;
	const t_i32val	ResERR_ChannelTemporarilyNotAvailable = -11;
	const t_i32val	ResERR_CalOptionNotAvailable = -12;
	const t_i32val	ResERR_CalWavelengthOutOfRange = -13;
	const t_i32val	ResERR_BadCalibrationSignal = -14;
	const t_i32val	ResERR_UnitNotAvailable = -15;
	const t_i32val	ResERR_FileNotFound = -16;
	const t_i32val	ResERR_FileCreation = -17;
	const t_i32val	ResERR_TriggerPending = -18;
	const t_i32val	ResERR_TriggerWaiting = -19;
	const t_i32val	ResERR_NoLegitimation = -20;
	const t_i32val	ResERR_NoTCPLegitimation = -21;
	const t_i32val	ResERR_NotInPulseMode = -22;
	const t_i32val	ResERR_OnlyInPulseMode = -23;
	const t_i32val	ResERR_NotInSwitchMode = -24;
	const t_i32val	ResERR_OnlyInSwitchMode = -25;
	const t_i32val	ResERR_TCPErr = -26;
	const t_i32val	ResERR_StringTooLong = -29;
	const t_i32val	ResERR_InterruptedByUser = -30;

// Mode Constants for Callback-Export and WaitForWLMEvent-function
	const t_i32val	cmiResultMode = 1;
	const t_i32val	cmiRange = 2;
	const t_i32val	cmiPulse = 3;
	const t_i32val	cmiPulseMode = cmiPulse;
	const t_i32val	cmiWideLine = 4;
	const t_i32val	cmiWideMode = cmiWideLine;
	const t_i32val	cmiFast = 5;
	const t_i32val	cmiFastMode = cmiFast;
	const t_i32val	cmiExposureMode = 6;
	const t_i32val	cmiExposureValue1 = 7;
	const t_i32val	cmiExposureValue2 = 8;
	const t_i32val	cmiDelay = 9;
	const t_i32val	cmiShift = 10;
	const t_i32val	cmiShift2 = 11;
	const t_i32val	cmiReduce = 12;
	const t_i32val	cmiReduced = cmiReduce;
	const t_i32val	cmiScale = 13;
	const t_i32val	cmiTemperature = 14;
	const t_i32val	cmiLink = 15;
	const t_i32val	cmiOperation = 16;
	const t_i32val	cmiDisplayMode = 17;
	const t_i32val	cmiPattern1a = 18;
	const t_i32val	cmiPattern1b = 19;
	const t_i32val	cmiPattern2a = 20;
	const t_i32val	cmiPattern2b = 21;
	const t_i32val	cmiMin1 = 22;
	const t_i32val	cmiMax1 = 23;
	const t_i32val	cmiMin2 = 24;
	const t_i32val	cmiMax2 = 25;
	const t_i32val	cmiNowTick = 26;
	const t_i32val	cmiCallback = 27;
	const t_i32val	cmiFrequency1 = 28;
	const t_i32val	cmiFrequency2 = 29;
	const t_i32val	cmiDLLDetach = 30;
	const t_i32val	cmiVersion = 31;
	const t_i32val	cmiAnalysisMode = 32;
	const t_i32val	cmiDeviationMode = 33;
	const t_i32val	cmiDeviationReference = 34;
	const t_i32val	cmiDeviationSensitivity = 35;
	const t_i32val	cmiAppearance = 36;
	const t_i32val	cmiAutoCalMode = 37;
	const t_i32val	cmiWavelength1 = 42;
	const t_i32val	cmiWavelength2 = 43;
	const t_i32val	cmiLinewidth = 44;
	const t_i32val	cmiLinewidthMode = 45;
	const t_i32val	cmiLinkDlg = 56;
	const t_i32val	cmiAnalysis = 57;
	const t_i32val	cmiAnalogIn = 66;
	const t_i32val	cmiAnalogOut = 67;
	const t_i32val	cmiDistance = 69;
	const t_i32val	cmiWavelength3 = 90;
	const t_i32val	cmiWavelength4 = 91;
	const t_i32val	cmiWavelength5 = 92;
	const t_i32val	cmiWavelength6 = 93;
	const t_i32val	cmiWavelength7 = 94;
	const t_i32val	cmiWavelength8 = 95;
	const t_i32val	cmiVersion0 = cmiVersion;
	const t_i32val	cmiVersion1 = 96;
	const t_i32val	cmiPulseDelay = 99;
	const t_i32val   cmiPulseIntegration = cmiPulseDelay;
	const t_i32val	cmiDLLAttach = 121;
	const t_i32val	cmiSwitcherSignal = 123;
	const t_i32val	cmiSwitcherMode = 124;
	const t_i32val	cmiExposureValue11 = cmiExposureValue1;
	const t_i32val	cmiExposureValue12 = 125;
	const t_i32val	cmiExposureValue13 = 126;
	const t_i32val	cmiExposureValue14 = 127;
	const t_i32val	cmiExposureValue15 = 128;
	const t_i32val	cmiExposureValue16 = 129;
	const t_i32val	cmiExposureValue17 = 130;
	const t_i32val	cmiExposureValue18 = 131;
	const t_i32val	cmiExposureValue21 = cmiExposureValue2;
	const t_i32val	cmiExposureValue22 = 132;
	const t_i32val	cmiExposureValue23 = 133;
	const t_i32val	cmiExposureValue24 = 134;
	const t_i32val	cmiExposureValue25 = 135;
	const t_i32val	cmiExposureValue26 = 136;
	const t_i32val	cmiExposureValue27 = 137;
	const t_i32val	cmiExposureValue28 = 138;
	const t_i32val	cmiPatternAverage = 139;
	const t_i32val	cmiPatternAvg1 = 140;
	const t_i32val	cmiPatternAvg2 = 141;
	const t_i32val	cmiAnalogOut1 = cmiAnalogOut;
	const t_i32val	cmiAnalogOut2 = 142;
	const t_i32val	cmiMin11 = cmiMin1;
	const t_i32val	cmiMin12 = 146;
	const t_i32val	cmiMin13 = 147;
	const t_i32val	cmiMin14 = 148;
	const t_i32val	cmiMin15 = 149;
	const t_i32val	cmiMin16 = 150;
	const t_i32val	cmiMin17 = 151;
	const t_i32val	cmiMin18 = 152;
	const t_i32val	cmiMin21 = cmiMin2;
	const t_i32val	cmiMin22 = 153;
	const t_i32val	cmiMin23 = 154;
	const t_i32val	cmiMin24 = 155;
	const t_i32val	cmiMin25 = 156;
	const t_i32val	cmiMin26 = 157;
	const t_i32val	cmiMin27 = 158;
	const t_i32val	cmiMin28 = 159;
	const t_i32val	cmiMax11 = cmiMax1;
	const t_i32val	cmiMax12 = 160;
	const t_i32val	cmiMax13 = 161;
	const t_i32val	cmiMax14 = 162;
	const t_i32val	cmiMax15 = 163;
	const t_i32val	cmiMax16 = 164;
	const t_i32val	cmiMax17 = 165;
	const t_i32val	cmiMax18 = 166;
	const t_i32val	cmiMax21 = cmiMax2;
	const t_i32val	cmiMax22 = 167;
	const t_i32val	cmiMax23 = 168;
	const t_i32val	cmiMax24 = 169;
	const t_i32val	cmiMax25 = 170;
	const t_i32val	cmiMax26 = 171;
	const t_i32val	cmiMax27 = 172;
	const t_i32val	cmiMax28 = 173;
	const t_i32val	cmiAvg11 = cmiPatternAvg1;
	const t_i32val	cmiAvg12 = 174;
	const t_i32val	cmiAvg13 = 175;
	const t_i32val	cmiAvg14 = 176;
	const t_i32val	cmiAvg15 = 177;
	const t_i32val	cmiAvg16 = 178;
	const t_i32val	cmiAvg17 = 179;
	const t_i32val	cmiAvg18 = 180;
	const t_i32val	cmiAvg21 = cmiPatternAvg2;
	const t_i32val	cmiAvg22 = 181;
	const t_i32val	cmiAvg23 = 182;
	const t_i32val	cmiAvg24 = 183;
	const t_i32val	cmiAvg25 = 184;
	const t_i32val	cmiAvg26 = 185;
	const t_i32val	cmiAvg27 = 186;
	const t_i32val	cmiAvg28 = 187;
	const t_i32val	cmiPatternAnalysisWritten = 202;
	const t_i32val	cmiSwitcherChannel = 203;
	const t_i32val	cmiStartCalibration = 235;
	const t_i32val	cmiEndCalibration = 236;
	const t_i32val	cmiAnalogOut3 = 237;
	const t_i32val	cmiAnalogOut4 = 238;
	const t_i32val	cmiAnalogOut5 = 239;
	const t_i32val	cmiAnalogOut6 = 240;
	const t_i32val	cmiAnalogOut7 = 241;
	const t_i32val	cmiAnalogOut8 = 242;
	const t_i32val	cmiIntensity = 251;
	const t_i32val	cmiPower = 267;
	const t_i32val	cmiActiveChannel = 300;
	const t_i32val	cmiPIDCourse = 1030;
	const t_i32val	cmiPIDUseTa = 1031;
	const t_i32val	cmiPIDUseT = cmiPIDUseTa;
	const t_i32val	cmiPID_T = 1033;
	const t_i32val	cmiPID_P = 1034;
	const t_i32val	cmiPID_I = 1035;
	const t_i32val	cmiPID_D = 1036;
	const t_i32val	cmiDeviationSensitivityDim = 1040;
	const t_i32val	cmiDeviationSensitivityFactor = 1037;
	const t_i32val	cmiDeviationPolarity = 1038;
	const t_i32val	cmiDeviationSensitivityEx = 1039;
	const t_i32val	cmiDeviationUnit = 1041;
	const t_i32val	cmiDeviationBoundsMin = 1042;
	const t_i32val	cmiDeviationBoundsMax = 1043;
	const t_i32val	cmiDeviationRefMid = 1044;
	const t_i32val	cmiDeviationRefAt = 1045;
	const t_i32val	cmiPIDConstdt = 1059;
	const t_i32val	cmiPID_dt = 1060;
	const t_i32val	cmiPID_AutoClearHistory = 1061;
	const t_i32val	cmiDeviationChannel = 1063;
	const t_i32val	cmiPID_ClearHistoryOnRangeExceed = 1069;
	const t_i32val	cmiAutoCalPeriod = 1120;
	const t_i32val	cmiAutoCalUnit = 1121;
	const t_i32val	cmiAutoCalChannel = 1122;
	const t_i32val	cmiServerInitialized = 1124;
	const t_i32val	cmiWavelength9 = 1130;
	const t_i32val	cmiExposureValue19 = 1155;
	const t_i32val	cmiExposureValue29 = 1180;
	const t_i32val	cmiMin19 = 1205;
	const t_i32val	cmiMin29 = 1230;
	const t_i32val	cmiMax19 = 1255;
	const t_i32val	cmiMax29 = 1280;
	const t_i32val	cmiAvg19 = 1305;
	const t_i32val	cmiAvg29 = 1330;
	const t_i32val	cmiWavelength10 = 1355;
	const t_i32val	cmiWavelength11 = 1356;
	const t_i32val	cmiWavelength12 = 1357;
	const t_i32val	cmiWavelength13 = 1358;
	const t_i32val	cmiWavelength14 = 1359;
	const t_i32val	cmiWavelength15 = 1360;
	const t_i32val	cmiWavelength16 = 1361;
	const t_i32val	cmiWavelength17 = 1362;
	const t_i32val	cmiExternalInput = 1400;
	const t_i32val	cmiPressure = 1465;
	const t_i32val	cmiBackground = 1475;
	const t_i32val	cmiDistanceMode = 1476;
	const t_i32val	cmiInterval = 1477;
	const t_i32val	cmiIntervalMode = 1478;
	const t_i32val	cmiCalibrationEffect = 1480;
	const t_i32val	cmiLinewidth1 = cmiLinewidth;
	const t_i32val	cmiLinewidth2 = 1481;
	const t_i32val	cmiLinewidth3 = 1482;
	const t_i32val	cmiLinewidth4 = 1483;
	const t_i32val	cmiLinewidth5 = 1484;
	const t_i32val	cmiLinewidth6 = 1485;
	const t_i32val	cmiLinewidth7 = 1486;
	const t_i32val	cmiLinewidth8 = 1487;
	const t_i32val	cmiLinewidth9 = 1488;
	const t_i32val	cmiLinewidth10 = 1489;
	const t_i32val	cmiLinewidth11 = 1490;
	const t_i32val	cmiLinewidth12 = 1491;
	const t_i32val	cmiLinewidth13 = 1492;
	const t_i32val	cmiLinewidth14 = 1493;
	const t_i32val	cmiLinewidth15 = 1494;
	const t_i32val	cmiLinewidth16 = 1495;
	const t_i32val	cmiLinewidth17 = 1496;
	const t_i32val	cmiTriggerState = 1497;
	const t_i32val	cmiDeviceAttach = 1501;
	const t_i32val	cmiDeviceDetach = 1502;
	const t_i32val	cmiTimePerMeasurement = 1514;
	const t_i32val	cmiAutoExpoMin = 1517;
	const t_i32val	cmiAutoExpoMax = 1518;
	const t_i32val	cmiAutoExpoStepUp = 1519;
	const t_i32val	cmiAutoExpoStepDown = 1520;
	const t_i32val	cmiAutoExpoAtSaturation = 1521;
	const t_i32val	cmiAutoExpoAtLowSignal = 1522;
	const t_i32val	cmiAutoExpoFeedback = 1523;
	const t_i32val	cmiAveragingCount = 1524;
	const t_i32val	cmiAveragingMode = 1525;
	const t_i32val	cmiAveragingType = 1526;
	const t_i32val	cmiAirMode = 1532;
	const t_i32val	cmiAirTemperature = 1534;
	const t_i32val	cmiAirPressure = 1535;
	const t_i32val	cmiAirHumidity = 1536;
	const t_i32val	cmiAirCO2 = 1651;
	const t_i32val	cmiSubSnapshotID = 1539;
	const t_i32val	cmiInternalTriggerRate = 1540;
	const t_i32val	cmiGain11 = 1541;
	const t_i32val	cmiGain12 = 1542;
	const t_i32val	cmiGain13 = 1543;
	const t_i32val	cmiGain14 = 1544;
	const t_i32val	cmiGain15 = 1545;
	const t_i32val	cmiGain16 = 1546;
	const t_i32val	cmiGain17 = 1547;
	const t_i32val	cmiGain18 = 1548;
	const t_i32val	cmiGain19 = 1549;
	const t_i32val	cmiGain21 = 1558;
	const t_i32val	cmiGain22 = 1559;
	const t_i32val	cmiGain23 = 1560;
	const t_i32val	cmiGain24 = 1561;
	const t_i32val	cmiGain25 = 1562;
	const t_i32val	cmiGain26 = 1563;
	const t_i32val	cmiGain27 = 1564;
	const t_i32val	cmiGain28 = 1565;
	const t_i32val	cmiGain29 = 1566;
	const t_i32val	cmiMultimodeLevel1 = 1609;
	const t_i32val	cmiMultimodeLevel2 = 1610;
	const t_i32val	cmiMultimodeLevel3 = 1611;
	const t_i32val	cmiMultimodeLevel4 = 1612;
	const t_i32val	cmiMultimodeLevel5 = 1613;
	const t_i32val	cmiMultimodeLevel6 = 1614;
	const t_i32val	cmiMultimodeLevel7 = 1615;
	const t_i32val	cmiMultimodeLevel8 = 1616;
	const t_i32val	cmiMultimodeLevel9 = 1617;
	const t_i32val	cmiFastBasedLinewidthAnalysis = 1630;
	const t_i32val	cmiMultimodeCount1 = 1633;
	const t_i32val	cmiMultimodeCount2 = 1634;
	const t_i32val	cmiMultimodeCount3 = 1635;
	const t_i32val	cmiMultimodeCount4 = 1636;
	const t_i32val	cmiMultimodeCount5 = 1637;
	const t_i32val	cmiMultimodeCount6 = 1638;
	const t_i32val	cmiMultimodeCount7 = 1639;
	const t_i32val	cmiMultimodeCount8 = 1640;
	const t_i32val	cmiMultimodeCount9 = 1641;
	const t_i32val	cmiPowerCalibration = 1652;
	const t_i32val	cmiStartPowerCalibration = 1653;
	const t_i32val	cmiEndPowerCalibration = 1654;

// Index constants for Get- and SetExtraSetting
	const t_i32val	cesCalculateLive = 4501;
	const t_i32val	cesTryCalcOnAllErrors = 4530;
	const t_i32val	cesTryCalcOnUnderexposure = 4531;
	const t_i32val	cesCalcUnderexposureMinLevel = 4561;
	const t_i32val	cesTrancheAverage = 4600;
	const t_i32val	cesTTLBatchCount  = 4601;

// WLM Control Mode Constants
	const t_i32val	cCtrlWLMShow = 1;
	const t_i32val	cCtrlWLMHide = 2;
	const t_i32val	cCtrlWLMExit = 3;
	const t_i32val	cCtrlWLMStore = 4;
	const t_i32val	cCtrlWLMCompare = 5;
	const t_i32val	cCtrlWLMWait        = 0x0010;
	const t_i32val	cCtrlWLMStartSilent = 0x0020;
	const t_i32val	cCtrlWLMSilent      = 0x0040;
	const t_i32val	cCtrlWLMStartDelay  = 0x0080;

// Operation Mode Constants (for "Operation" and "GetOperationState" functions)
	const t_i32val	cStop = 0;
	const t_i32val	cAdjustment = 1;
	const t_i32val	cMeasurement = 2;

// Base Operation Constants (To be used exclusively, only one of this list at a time,
// but still can be combined with "Measurement Action Addition Constants". See below.)
	const t_i32val	cCtrlStopAll = cStop;
	const t_i32val	cCtrlStartAdjustment = cAdjustment;
	const t_i32val	cCtrlStartMeasurement = cMeasurement;
	const t_i32val	cCtrlStartRecord = 0x0004;
	const t_i32val	cCtrlStartReplay = 0x0008;
	const t_i32val	cCtrlStoreArray  = 0x0010;
	const t_i32val	cCtrlLoadArray   = 0x0020;

// Additional Operation Flag Constants (combine with "Base Operation Constants" above.)
	const t_i32val	cCtrlDontOverwrite = 0x0000;
	const t_i32val	cCtrlOverwrite     = 0x1000; // don't combine with cCtrlFileDialog
	const t_i32val	cCtrlFileGiven     = 0x0000;
	const t_i32val	cCtrlFileDialog    = 0x2000; // don't combine with cCtrlOverwrite and cCtrlFileASCII
	const t_i32val	cCtrlFileBinary    = 0x0000; // *.smr, *.ltr
	const t_i32val	cCtrlFileASCII     = 0x4000; // *.smx, *.ltx, don't combine with cCtrlFileDialog

// Measurement Control Mode Constants
	const t_i32val	cCtrlMeasDelayRemove = 0;
	const t_i32val	cCtrlMeasDelayGenerally = 1;
	const t_i32val	cCtrlMeasDelayOnce = 2;
	const t_i32val	cCtrlMeasDelayDenyUntil = 3;
	const t_i32val	cCtrlMeasDelayIdleOnce = 4;
	const t_i32val	cCtrlMeasDelayIdleEach = 5;
	const t_i32val	cCtrlMeasDelayDefault = 6;

// Measurement Triggering Action Constants
	const t_i32val	cCtrlMeasurementContinue = 0;
	const t_i32val	cCtrlMeasurementInterrupt = 1;
	const t_i32val	cCtrlMeasurementTriggerPoll = 2;
	const t_i32val	cCtrlMeasurementTriggerSuccess = 3;
	const t_i32val	cCtrlMeasurementEx = 0x0100;

// ExposureRange Constants
	const t_i32val	cExpoMin = 0;
	const t_i32val	cExpoMax = 1;
	const t_i32val	cExpo2Min = 2;
	const t_i32val	cExpo2Max = 3;

// Amplitude Constants
	const t_i32val	cMin1 = 0;
	const t_i32val	cMin2 = 1;
	const t_i32val	cMax1 = 2;
	const t_i32val	cMax2 = 3;
	const t_i32val	cAvg1 = 4;
	const t_i32val	cAvg2 = 5;

// Measurement Range Constants
	const t_i32val	cRange_250_410 = 4;
	const t_i32val	cRange_250_425 = 0;
	const t_i32val	cRange_300_410 = 3;
	const t_i32val	cRange_350_500 = 5;
	const t_i32val	cRange_400_725 = 1;
	const t_i32val	cRange_700_1100 = 2;
	const t_i32val	cRange_800_1300 = 6;
	const t_i32val	cRange_900_1500 = cRange_800_1300;
	const t_i32val	cRange_1100_1700 = 7;
	const t_i32val	cRange_1100_1800 = cRange_1100_1700;

// Measurement Range Model Constants
	const t_i32val	cRangeModelOld = 65535;
	const t_i32val	cRangeModelByOrder = 65534;
	const t_i32val	cRangeModelByWavelength = 65533;

// Unit Constants for Get-/SetResultMode, GetLinewidth, Convert... and Calibration
	const t_i32val	cReturnWavelengthVac = 0;
	const t_i32val	cReturnWavelengthAir = 1;
	const t_i32val	cReturnFrequency = 2;
	const t_i32val	cReturnWavenumber = 3;
	const t_i32val	cReturnPhotonEnergy = 4;

// Power Unit Constants
	const t_i32val	cPower_muW = 0;
	const t_i32val	cPower_mW  = 1;
	const t_i32val	cPower_dBm = 2;

// Source Type Constants for Calibration
	const t_i32val	cHeNe633 = 0;
	const t_i32val	cHeNe1152 = 0;
	const t_i32val	cNeL = 1;
	const t_i32val	cOther = 2;
	const t_i32val	cFreeHeNe = 3;
	const t_i32val	cSLR1530 = 5;

// Unit Constants for Autocalibration
	const t_i32val	cACOnceOnStart = 0;
	const t_i32val	cACMeasurements = 1;
	const t_i32val	cACDays = 2;
	const t_i32val	cACHours = 3;
	const t_i32val	cACMinutes = 4;

// Options flags for PowerCalibration
	const t_i32val	cIntSensor1     = 0x00000000;
	const t_i32val	cIntSensor2     = 0x00000001;
	const t_i32val	cTryWOStoreDark = 0x00000010;
	
// ExposureRange Constants
	const t_i32val	cGetSync = 1;
	const t_i32val	cSetSync = 2;

// Pattern- and Analysis Constants
	const t_i32val	cPatternDisable = 0;
	const t_i32val	cPatternEnable = 1;
	const t_i32val	cAnalysisDisable = cPatternDisable;
	const t_i32val	cAnalysisEnable = cPatternEnable;

	const t_i32val	cSignal1Interferometers = 0;
	const t_i32val	cSignal1WideInterferometer = 1;
	const t_i32val	cSignal1Grating = 1;
	const t_i32val	cSignal2Interferometers = 2;
	const t_i32val	cSignal2WideInterferometer = 3;
	const t_i32val	cSignalAnalysis = 4;
	const t_i32val	cSignalAnalysisX = cSignalAnalysis;
	const t_i32val	cSignalAnalysisY = cSignalAnalysis + 1;

// State constants used with AutoExposureSetting functions
	const t_i32val	cJustStepDown = 0;
	const t_i32val	cRestartAtMinimum = 1;
	const t_i32val	cJustStepUp = 0;
	const t_i32val	cDriveToLevel = 1;
	const t_i32val	cConsiderFeedback = 1;
	const t_i32val	cDontConsiderFeedback = 0;

// Options identifiers used with GetOptionInfo
	const t_i32val	cInfoSwitch = 1;
	const t_i32val	cInfoSwitchChannelsCount = 2;
	const t_i32val	cInfoIntNeonLamp = 11;
	const t_i32val	cInfo2ndExternalPort = 13;
	const t_i32val	cInfoPID = 21;
	const t_i32val	cInfoPIDPortsCount = 22;
	const t_i32val	cInfoPIDPortType = 23;
	const t_i32val	cInfoPIDPortRes = 24;
	const t_i32val	cInfoPIDPortUMin = 25;
	const t_i32val	cInfoPIDPortUMax = 26;

// PID type constants
	const t_i32val	cInfoPIDPortTypeInt = 1;
	const t_i32val	cInfoPIDPortTypeExt = 2;
	const t_i32val	cInfoPIDPortTypeDigi = 3;

// State constants used with AveragingSetting functions
	const t_i32val	cAvrgFloating = 1;
	const t_i32val	cAvrgSucceeding = 2;
	const t_i32val	cAvrgSimple = 0;
	const t_i32val	cAvrgPattern = 1;

// Return errorvalues of GetFrequency, GetWavelength, GetWLMVersion, GetOptionInfo and GetResultInfo
	const t_i32val	ErrNoError = 2; // only with GetResultInfo, other functions return the measured value in this case
	const t_i32val	ErrNoValue = 0;
	const t_i32val	ErrNoSignal = -1;
	const t_i32val	ErrBadSignal = -2;
	const t_i32val	ErrLowSignal = -3;
	const t_i32val	ErrBigSignal = -4;
	const t_i32val	ErrWlmMissing = -5;
	const t_i32val	ErrNotAvailable = -6;
	const t_i32val	InfNothingChanged = -7;
	const t_i32val	ErrNoPulse = -8;
	const t_i32val	ErrChannelNotAvailable = -10;
	const t_i32val	ErrDiv0 = -13;
	const t_i32val	ErrOutOfRange = -14;
	const t_i32val	ErrUnitNotAvailable = -15;
	const t_i32val	ErrWOCalc = -16;
	const t_i32val	ErrTCPErr = -26;
	const t_i32val	ErrParameterOutOfRange = -28;
	const t_i32val	ErrStringTooLong = -29;
	const t_i32val	ErrInterruptedByUser = -30;
	const t_i32val	ErrInfoAlreadyFetched = -31;
	const t_i32val	ErrNoValueYet = -32;
	const t_i32val	ErrNoNewValueYet = -33;
	const t_i32val	ErrMaxErr = ErrNoNewValueYet;

// Return errorvalues of GetTemperature and GetPressure
	const t_i32val	ErrTemperature = -1000;
	const t_i32val	ErrTempNotMeasured = ErrTemperature + ErrNoValue;
	const t_i32val	ErrTempNotAvailable = ErrTemperature + ErrNotAvailable;
	const t_i32val	ErrTempWlmMissing = ErrTemperature + ErrWlmMissing;

// Return errorvalues of GetGain
	const t_i32val	ErrGain = -1000;
	const t_i32val	ErrGainNotAvailable        = ErrGain + ErrNotAvailable;
	const t_i32val	ErrGainWlmMissing          = ErrGain + ErrWlmMissing;
	const t_i32val	ErrGainChannelNotAvailable = ErrGain + ErrChannelNotAvailable;
	const t_i32val	ErrGainOutOfRange          = ErrGain + ErrOutOfRange;
	const t_i32val	ErrGainParameterOutOfRange = ErrGain + ErrParameterOutOfRange;

// Return errorvalues of GetMultimodeInfo
	const t_i32val	ErrMMI = -1000;
	const t_i32val	ErrMMINotAvailable        = ErrMMI + ErrNotAvailable;
	const t_i32val	ErrMMIWlmMissing          = ErrMMI + ErrWlmMissing;
	const t_i32val	ErrMMIChannelNotAvailable = ErrMMI + ErrChannelNotAvailable;
	const t_i32val	ErrMMIOutOfRange          = ErrMMI + ErrOutOfRange;
	const t_i32val	ErrMMIParameterOutOfRange = ErrMMI + ErrParameterOutOfRange;

// Return errorvalues of GetDistance
	// real errorvalues are ErrDistance combined with those of GetWavelength
	const t_i32val	ErrDistance = -1000000000;
	const t_i32val	ErrDistanceNotAvailable = ErrDistance + ErrNotAvailable;
	const t_i32val	ErrDistanceWlmMissing = ErrDistance + ErrWlmMissing;

// Return flags of ControlWLMEx in combination with Show or Hide, Wait and Res = 1
	const t_i32val	flServerStarted           = 0x00000001;
	const t_i32val	flErrDeviceNotFound       = 0x00000002;
	const t_i32val	flErrDriverError          = 0x00000004;
	const t_i32val	flErrUSBError             = 0x00000008;
	const t_i32val	flErrUnknownDeviceError   = 0x00000010;
	const t_i32val	flErrWrongSN              = 0x00000020;
	const t_i32val	flErrUnknownSN            = 0x00000040;
	const t_i32val	flErrTemperatureError     = 0x00000080;
	const t_i32val	flErrPressureError        = 0x00000100;
	const t_i32val	flErrCancelledManually    = 0x00000200;
	const t_i32val	flErrWLMBusy              = 0x00000400;
	const t_i32val	flErrUnknownError         = 0x00001000;
	const t_i32val	flNoInstalledVersionFound = 0x00002000;
	const t_i32val	flDesiredVersionNotFound  = 0x00004000;
	const t_i32val	flErrFileNotFound         = 0x00008000;
	const t_i32val	flErrParmOutOfRange       = 0x00010000;
	const t_i32val	flErrCouldNotSet          = 0x00020000;
	const t_i32val	flErrEEPROMFailed         = 0x00040000;
	const t_i32val	flErrFileFailed           = 0x00080000;
	const t_i32val	flDeviceDataNewer         = 0x00100000;
	const t_i32val	flFileDataNewer           = 0x00200000;
	const t_i32val	flErrDeviceVersionOld     = 0x00400000;
	const t_i32val	flErrFileVersionOld       = 0x00800000;
	const t_i32val	flDeviceStampNewer        = 0x01000000;
	const t_i32val	flFileStampNewer          = 0x02000000;

// Return file info flags of SetOperationFile
	const t_i32val	flFileInfoDoesntExist = 0x00000000;
	const t_i32val	flFileInfoExists      = 0x00000001;
	const t_i32val	flFileInfoCantWrite   = 0x00000002;
	const t_i32val	flFileInfoCantRead    = 0x00000004;
	const t_i32val	flFileInfoInvalidName = 0x00000008;
	const t_i32val	cFileParameterError = -1;

#endif

// *** end of wlmData.h