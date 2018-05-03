/*============================================================================*/
/*                        L a b W i n d o w s / C V I                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 1987-1998.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       dataacq.h                                                     */
/* Purpose:     Include file for NI-DAQ library support.                      */
/*                                                                            */
/*============================================================================*/

#ifndef __DATAACQ_HEADER
#define __DATAACQ_HEADER

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#include "cvidef.h"

#ifdef __cplusplus
extern "C" {
#endif


/************************************************************************/
/* Include files containing named constants.                            */
/************************************************************************/
#define ___olderror_h___ /* prevent nidaqerr.h from defining the old error codes */
                         /* to the new error values;  this file can be used with */
                         /* version 4.8.5, which returns the old error codes;    */
                         /* also, dataacq.h never included the defined constants */
                         /* for the error codes before.                          */
#ifdef CVIDAQ_GLUE_GENERATION
#include "niderror.h"
#else
#include "nidaqerr.h"    /* include error codes for version 4.9.0 and later      */
#endif
#include "nidaqcns.h"
#include "regdefs.h"

/************************************************************************/
/* CVI-specific typedefs and macros.                                    */
/************************************************************************/

#define CVIDAQFUNC  CVIFUNC

#ifdef _NI_mswin16_ 

 typedef short           DAQEventHandle;
 typedef short           DAQEventMsg;
 typedef unsigned short  DAQEventWParam;
 typedef unsigned long   DAQEventLParam;

#else

 typedef int             DAQEventHandle;
 typedef int             DAQEventMsg;
 typedef unsigned int    DAQEventWParam;
 typedef unsigned long   DAQEventLParam;

#endif

typedef void (CVICALLBACK *DAQEventCallbackPtr) (DAQEventHandle handle, 
                                                 DAQEventMsg    msg,
                                                 DAQEventWParam wParam,
                                                 DAQEventLParam lParam);

/************************************************************************/
/* Special function to convert from the old to the new error codes      */
/* introduced in NI-DAQ 4.9.0.                                          */
/************************************************************************/

short CVIDAQFUNC ConvertToNewNIDAQErrorCode (short errorCode);

/************************************************************************/
/* Function to return a pointer to an error message string.             */
/* Requires a "new-style" error code.                                   */
/************************************************************************/

char * CVIFUNC GetNIDAQErrorString (short newErrorCode);

/************************************************************************/
/* NI-DAQ function prototypes.                                          */
/************************************************************************/

short CVIDAQFUNC AI_Change_Parameter (short device,
	                                   short channel,
	                                   unsigned long paramID,
		                                unsigned long paramValue);
short CVIDAQFUNC AI_Check (short device, 
                           short *readingAvailable, 
                           short *value);
short CVIDAQFUNC AI_Clear (short device);
short CVIDAQFUNC AI_Configure (short device, 
                               short channel, 
                               short inputMode,
                               short inputVoltageRange, 
                               short polarity, 
                               short driveAISENSE); 
short CVIDAQFUNC AI_Get_Overloaded_Channels (short device, 
                                             short *numChannels, 
                                             short channelList[]);
short CVIDAQFUNC AI_Mux_Config (short device, 
                                short AMUX64devices);
short CVIDAQFUNC AI_Read (short device, 
                          short channel, 
                          short gain, 
                          short *reading);
short CVIDAQFUNC AI_Read_Scan (short device, 
                               short binaryreading[]);
short CVIDAQFUNC AI_Setup (short device, 
                           short channel, 
                           short gain);
short CVIDAQFUNC AI_VRead (short device, 
                           short channel, 
                           short gain, 
                           double *voltage);
short CVIDAQFUNC AI_VRead_Scan (short device, 
                                double voltages[]);
short CVIDAQFUNC AI_VScale (short device, 
                            short channel, 
                            short gain, 
                            double gainAdjustFactor,
                            double binaryZeroOffset, 
                            short binaryValue, 
                            double *voltage);

short CVIDAQFUNC Align_DMA_Buffer (short device, 
                                   short resource, 
                                   short buffer[],
                                   unsigned long numberofPoints, 
                                   unsigned long bufferSize,
                                   unsigned long *alignIndex);

short CVIDAQFUNC AO_Calibrate (short device, 
                               short destination, 
                               short EEPROMLocation);
short CVIDAQFUNC AO_Change_Parameter (short device, 
                                      short outputChannel,
                                      unsigned long parameterID, 
                                      unsigned long parameterValue);
short CVIDAQFUNC AO_Configure (short device, 
                               short outputChannel, 
                               short polarity,
                               short referenceSelection, 
                               double referenceVoltage,
                               short updateMode);
short CVIDAQFUNC AO_Update (short device);
short CVIDAQFUNC AO_VScale (short device, 
                            short outputChannel, 
                            double voltage,
                            short *binaryValue);
short CVIDAQFUNC AO_VWrite (short device, 
                            short outputChannel, 
                            double voltage);
short CVIDAQFUNC AO_Write (short device, 
                           short outputChannel, 
                           short value);

short CVIDAQFUNC Calibrate_1200 (short device, 
                                 short calibrateOperation,
                                 short saveNewValues, 
                                 short EEPROMLocation,
                                 short referenceChannel, 
                                 short groundChannel,
                                 short DAC0Channel, 
                                 short DAC1Channel,
                                 double DCReferenceVoltage, 
                                 double gain);
short CVIDAQFUNC Calibrate_DSA(short device,
							          unsigned long operation,
							          double refVoltage);
short CVIDAQFUNC Calibrate_E_Series (short device, 
                                     unsigned long calibrateOperation,
                                     unsigned long calConstants, 
                                     double calRefVoltage);
short CVIDAQFUNC Calibrate_TIO (short device,
                                unsigned long operation,
                                unsigned long setOfCalConst,
                                double referenceFreq);
short CVIDAQFUNC Config_Alarm_Deadband (short device, 
                                        short mode, 
                                        char channelString[],
                                        double triggerLevel, 
                                        double deadbandWidth,
                                        DAQEventHandle handle, 
                                        DAQEventMsg alarmOnMessage,
                                        DAQEventMsg alarmOffMessage,
                                        DAQEventCallbackPtr eventFunction);
short CVIDAQFUNC Config_ATrig_Event_Message (short device, 
                                             short mode, 
                                             char channelString[],
                                             double triggerLevel, 
                                             double windowSize,
                                             short triggerSlope, 
                                             long triggerSkipCount,
                                             unsigned long preTriggerScans,
                                             unsigned long postTriggerScans,
                                             DAQEventHandle handle,
                                             DAQEventMsg message, 
                                             DAQEventCallbackPtr eventFunction);
short CVIDAQFUNC Config_DAQ_Event_Message (short device, 
                                           short mode, 
                                           char channelString[],
                                           short DAQEvent, 
                                           long triggerValue0,
                                           long triggerValue1, 
                                           long triggerSkipCount,
                                           unsigned long preTriggerScans,
                                           unsigned long postTriggerScans, 
                                           DAQEventHandle handle,
                                           DAQEventMsg message, 
                                           DAQEventCallbackPtr eventFunction);
short CVIDAQFUNC Configure_HW_Analog_Trigger (short device, 
                                              unsigned long onorOff,
                                              long lowValue, 
                                              long highValue,
                                              unsigned long triggerMode,
                                              unsigned long triggerSource);

short CVIDAQFUNC CTR_Config (short device, 
                             short counter, 
                             short edgeCountType, 
                             short gateMode,
                             short outputType, 
                             short outputPolarity);
short CVIDAQFUNC CTR_EvCount (short device, 
                              short counter, 
                              short timebase, 
                              short countMode);
short CVIDAQFUNC CTR_EvRead (short device, 
                             short counter, 
                             short *overflow,
                             unsigned short *count);
short CVIDAQFUNC CTR_FOUT_Config (short device, 
                                  short freqOUTPort, 
                                  short freqOUTsignal,
                                  short timebase, 
                                  short divideFactor);
short CVIDAQFUNC CTR_Period (short device, 
                             short counter, 
                             short timebase);
short CVIDAQFUNC CTR_Pulse (short device, 
                            short counter, 
                            short timebase, 
                            unsigned short delay,
                            unsigned short pulseWidth);
short CVIDAQFUNC CTR_Rate (double frequencyHz, 
                           double dutyFraction, 
                           short *timebase,
                           unsigned short *period1, 
                           unsigned short *period2);
short CVIDAQFUNC CTR_Reset (short device, 
                            short counter, 
                            short outputState);
short CVIDAQFUNC CTR_Restart (short device, 
                              short counter);
short CVIDAQFUNC CTR_Simul_Op (short device, 
                               short numberofCounters, 
                               short counterList[],
                               short operation);
short CVIDAQFUNC CTR_Square (short device, 
                             short counter, 
                             short timebase,
                             unsigned short period1, 
                             unsigned short period2);
short CVIDAQFUNC CTR_State (short device, 
                            short counter, 
                            short *outputState);
short CVIDAQFUNC CTR_Stop (short device, 
                           short counter);

short CVIDAQFUNC DAQ_Check (short device, 
                            short *DAQStopped, 
                            unsigned long *pointsAcquired);
short CVIDAQFUNC DAQ_Clear (short device);
short CVIDAQFUNC DAQ_Config (short device, 
                             short startTrigger, 
                             short timing);
short CVIDAQFUNC DAQ_DB_Config (short device, 
                                short mode);
short CVIDAQFUNC DAQ_DB_HalfReady (short device, 
                                   short *halfReadyIndicator, 
                                   short *DAQStopped);
short CVIDAQFUNC DAQ_DB_Transfer (short device, 
                                  short halfBuffer[],
                                  unsigned long *pointsTransferred, 
                                  short *DAQStopped);
short CVIDAQFUNC DAQ_Monitor (short device, 
                              short channel, 
                              short monitorMode,
                              unsigned long numberofPoints, 
                              short monitorBuffer[],
                              unsigned long *newestPointIndex, 
                              short *DAQStopped);
short CVIDAQFUNC DAQ_Op (short device, 
                         short channel, 
                         short gain, 
                         short dataBuffer[],
                         unsigned long numberofPoints, 
                         double sampleRate);
short CVIDAQFUNC DAQ_Rate (double acquisitionRate, 
                           short units, 
                           short *timebase,
                           unsigned short *sampleInterval);
short CVIDAQFUNC DAQ_Set_Clock(short device,
                               unsigned long whichClock,
                               double desiredRate,
                               unsigned long units,
                               double *actualRate);
short CVIDAQFUNC DAQ_Start (short device, 
                            short channel, 
                            short gain, 
                            short buffer[],
                            unsigned long numberofPoints, 
                            short sampleTimebase,
                            unsigned short sampleInterval);
short CVIDAQFUNC DAQ_StopTrigger_Config (short device, 
                                         short pretriggerMode,
                                         unsigned long pointsAfterTrigger);
short CVIDAQFUNC DAQ_to_Disk (short device, 
                              short channel, 
                              short gain, 
                              char fileName[],
                              unsigned long numberofPoints, 
                              double sampleRate, 
                              short fileMode);
short CVIDAQFUNC DAQ_VScale (short device, 
                             short channel, 
                             short gain, 
                             double gainAdjust,
                             double binaryZeroOffset, 
                             unsigned long numberofPoints,
                             short binaryArray[], 
                             double voltageArray[]);

short CVIDAQFUNC DIG_Block_Check (short device, 
                                  short groupNumber, 
                                  unsigned long *remaining);
short CVIDAQFUNC DIG_Block_Clear (short device, 
                                  short groupNumber);
short CVIDAQFUNC DIG_Block_In (short device, 
                               short groupNumber, 
                               short buffer[],
                               unsigned long numberofPoints);
short CVIDAQFUNC DIG_Block_Out (short device, 
                                short groupNumber, 
                                short buffer[],
                                unsigned long numberofPoints);
short CVIDAQFUNC DIG_Block_PG_Config (short device, 
                                      short groupNumber, 
                                      short PGMode,
                                      short clockSource, 
                                      short timebase,
                                      unsigned short patternInterval, 
                                      short externalGate);
short CVIDAQFUNC DIG_Change_Message_Config (short device,
                                            short operation,
                                            char  riseChanStr[],
                                            char  fallChanStr[],
                                            DAQEventHandle handle,
                                            DAQEventMsg message,
                                            DAQEventCallbackPtr callbackAddr);
short CVIDAQFUNC DIG_Change_Message_Control (short device,
                                                short controlCode);
short CVIDAQFUNC DIG_DB_Config (short device, 
                                short groupNumber, 
                                short mode,
                                short stoponOldData, 
                                short partialTransfers);
short CVIDAQFUNC DIG_DB_HalfReady (short device, 
                                   short groupNumber, 
                                   short *halfReadyIndicator);
short CVIDAQFUNC DIG_DB_Transfer (short device, 
                                  short groupNumber, 
                                  short halfBuffer[],
                                  unsigned long pointsTransferred);
short CVIDAQFUNC DIG_Filter_Config (short device,
                                    short mode,
                                    char chanStr[],
                                    double interval);
short CVIDAQFUNC DIG_Grp_Config (short device, 
                                 short groupNumber, 
                                 short groupSize, 
                                 short port,
                                 short direction);
short CVIDAQFUNC DIG_Grp_Mode (short device, 
                               short groupNumber, 
                               short signalType,
                               short edgeMode, 
                               short requestMode, 
                               short acknowledgeMode,
                               short settlingTime);
short CVIDAQFUNC DIG_Grp_Status (short device, 
                                 short groupNumber, 
                                 short *groupReady);
short CVIDAQFUNC DIG_In_Grp (short device, 
                             short groupNumber, 
                             short *pattern);
short CVIDAQFUNC DIG_In_Line (short device, 
                              short port, 
                              short line, 
                              short *lineState);
short CVIDAQFUNC DIG_In_Port (short device, 
                              short port, 
                              short *pattern);
short CVIDAQFUNC DIG_In_Prt (short device, 
                             short port, 
                             long *pattern);
short CVIDAQFUNC DIG_Line_Config (short device, 
                                  short port, 
                                  short line, 
                                  short direction);
short CVIDAQFUNC DIG_Out_Grp (short device, 
                              short groupNumber, 
                              short pattern);
short CVIDAQFUNC DIG_Out_Line (short device, 
                               short port, 
                               short line, 
                               short lineState);
short CVIDAQFUNC DIG_Out_Port (short device, 
                               short port, 
                               short pattern);
short CVIDAQFUNC DIG_Out_Prt (short device, 
                              short port, 
                              long pattern);
short CVIDAQFUNC DIG_Prt_Config (short device, 
                                 short port, 
                                 short handshaking, 
                                 short direction);
short CVIDAQFUNC DIG_Prt_Status (short device, 
                                 short port, 
                                 short *portReady);
short CVIDAQFUNC DIG_SCAN_Setup (short device, 
                                 short groupNumber, 
                                 short groupSize,
                                 short portList[], 
                                 short direction);
short CVIDAQFUNC DIG_Trigger_Config (short device, 
									 short group,
									 short startTrigger,
									 short startPol,
									 short stopTrig,
									 short stopPol,
									 unsigned long ptsAfterStoptrig,
									 unsigned long pattern,
									 unsigned long patternMask);

short CVIDAQFUNC Get_DAQ_Device_Info (short device, 
                                      unsigned long typeofInformation,
                                      unsigned long *informationValue);
short CVIDAQFUNC Get_NI_DAQ_Version (unsigned long *DAQLibraryVersion);

short CVIDAQFUNC GPCTR_Change_Parameter (short device, 
                                         unsigned long counterNumber,
                                         unsigned long parameterType,
                                         unsigned long parameterValue);
short CVIDAQFUNC GPCTR_Config_Buffer (short device, 
                                      unsigned long counterNumber,
                                      unsigned long reserved, 
                                      unsigned long bufferSize,
                                      unsigned long bufferName[]);
short CVIDAQFUNC GPCTR_Control (short device, 
                                unsigned long counterNumber,
                                unsigned long controlAction);

short CVIDAQFUNC GPCTR_Read_Buffer (short deviceNumber,
                                    unsigned long gpCounterNumber,
                                    unsigned long readMode,
                                    long readOffset,
                                    unsigned long numPointsToRead,
                                    double timeOut,
                                    unsigned long *numPointsRead,
                                    unsigned long  buffer[]);
short CVIDAQFUNC GPCTR_Set_Application (short device, 
                                        unsigned long counterNumber,
                                        unsigned long application);
short CVIDAQFUNC GPCTR_Watch (short device, 
                              unsigned long counterNumber,
                              unsigned long watchedProperty, 
                              unsigned long *watchedValue);

short CVIDAQFUNC ICTR_Read (short device, 
                            short counter, 
                            unsigned short *count);
short CVIDAQFUNC ICTR_Reset (short device, 
                             short counter, 
                             short state);
short CVIDAQFUNC ICTR_Setup (short device, 
                             short counter, 
                             short mode, 
                             unsigned short count,
                             short binaryorBCD);

short CVIDAQFUNC Init_DA_Brds (short device, 
                               short *deviceCode);

short CVIDAQFUNC Lab_ISCAN_Check (short device, 
                                  short *DAQStopped,
                                  unsigned long *pointsAcquired, 
                                  short finalScanOrder[]);
short CVIDAQFUNC Lab_ISCAN_Op (short device, 
                               short numberofChannels, 
                               short gain, 
                               short buffer[],
                               unsigned long numberofPoints, 
                               double sampleRate,
                               double scanRate, 
                               short finalScanOrder[]);
short CVIDAQFUNC Lab_ISCAN_Start (short device, 
                                  short numberofChannels, 
                                  short gain,
                                  short buffer[], 
                                  unsigned long numberofPoints, 
                                  short timebase,
                                  unsigned short sampleInterval, 
                                  unsigned short scanInterval);
short CVIDAQFUNC Lab_ISCAN_to_Disk (short device, 
                                    short numberofChannels, 
                                    short gain,
                                    char fileName[], 
                                    unsigned long numberofPoints,
                                    double sampleRate, 
                                    double scanRate, 
                                    short fileMode);

short CVIDAQFUNC Line_Change_Attribute (short device,
                                        unsigned long lineNumber,
                                        unsigned long attribID,
                                        unsigned long attribValue);

short CVIDAQFUNC LPM16_Calibrate (short device);

short CVIDAQFUNC MIO_Config (short device, 
                             short dither, 
                             short inputChanSelection);
short CVIDAQFUNC Mux_SCAN_Setup (short chassisID,
                                  short numModules,
                                  short *modules,
                                  short *numChans,
                                  short **chanLists,
                                  short **wireModes,
                                  short DAQboard,
                                  short modeFlag);

short CVIDAQFUNC RTSI_Clear (short device);
short CVIDAQFUNC RTSI_Clock (short device, 
                             short action, 
                             short direction);
short CVIDAQFUNC RTSI_Conn (short device, 
                            short signalCode, 
                            short RTSITriggerLine, 
                            short direction);
short CVIDAQFUNC RTSI_DisConn (short device, 
                               short signalCode, 
                               short RTSITriggerLine);

short CVIDAQFUNC SC_2040_Config (short device, 
                                 short channel, 
                                 short gain);

short CVIDAQFUNC SCAN_Demux (short dataBuffer[], 
                             unsigned long numberofPoints, 
                             short numberofChannels, 
                             short AMUX64devices);
short CVIDAQFUNC SCAN_Op (short device, 
                          short numberofChannels, 
                          short channelList[],
                          short gainList[], 
                          short buffer[], 
                          unsigned long numberofPoints,
                          double sampleRate, 
                          double scanRate);
short CVIDAQFUNC SCAN_Sequence_Demux (short numberofChannels, 
                                      short channelList[],
                                      unsigned long numberofPoints, 
                                      short dataBuffer[],
                                      short samplesperSequence, 
                                      short scanSequenceList[],
                                      unsigned long sampsperChansList[]);
short CVIDAQFUNC SCAN_Sequence_Retrieve (short device, 
                                         short samplesperSequence,
                                         short scanSequenceList[]);
short CVIDAQFUNC SCAN_Sequence_Setup (short device, 
                                      short numberofChannels, 
                                      short channelList[],
                                      short gainList[], 
                                      short scanRateDivisors[],
                                      short *scansperSequence, 
                                      short *samplesperSequence);
short CVIDAQFUNC SCAN_Setup (short device, 
                             short numberofChannels, 
                             short channelList[],
                             short gainList[]);
short CVIDAQFUNC SCAN_Start (short device, 
                             short buffer[], 
                             unsigned long numberofPoints,
                             short sampleTimebase, 
                             unsigned short sampleInterval,
                             short scanTimebase, 
                             unsigned short scanInterval);
short CVIDAQFUNC SCAN_to_Disk (short device, 
                               short numberofChannels, 
                               short channelList[],
                               short gainList[], 
                               char fileName[], 
                               unsigned long numberofPoints,
                               double sampleRate, 
                               double scanRate, 
                               short fileMode);

short CVIDAQFUNC SCXI_AO_Write (short SCXIChassisID, 
                                short moduleSlotNumber,
                                short moduleChannel, 
                                short operation, 
                                short range,
                                double voltCurrentData, 
                                short binaryData,
                                short *binaryDataWritten);
short CVIDAQFUNC SCXI_Cal_Constants (short SCXIChassisID, 
                                     short moduleSlotNumber,
                                     short moduleChannel, 
                                     short operation, 
                                     short calArea,
                                     short range, 
                                     double moduleGain, 
                                     short DAQDevice,
                                     short DAQChannel, 
                                     short DAQGain, 
                                     double terminalBlockGain,
                                     double voltage1, 
                                     double binary1, 
                                     double voltage2, 
                                     double binary2, 
                                     double *constant1, 
                                     double *constant2);
short CVIDAQFUNC SCXI_Calibrate (short SCXIchassisID,
                                 short moduleSlot,
                                 short moduleChan,
                                 short operation,
                                 short calArea,
                                 double SCXIgain,
                                 double inputRefVoltage,
                                 short DAQdevice,
                                 short DAQchan);
short CVIDAQFUNC SCXI_Strain_Null (short chassisID,
                                   short slot,
                                   short moduleChan,
                                   short device,
                                   short DAQchan,
                                   float *imbalance);
short CVIDAQFUNC SCXI_Calibrate_Setup (short SCXIChassisID, 
                                       short moduleSlotNumber, 
                                       short calibrateOperation);
short CVIDAQFUNC SCXI_Change_Chan (short SCXIChassisID, 
                                   short moduleSlotNumber,
                                   short moduleChannel);
short CVIDAQFUNC SCXI_Configure_Filter (short SCXIChassisID, 
                                        short moduleSlotNumber, 
                                        short moduleChannel, 
                                        short filterMode, 
                                        double cutoffFrequencyHz, 
                                        unsigned short freqDivider, 
                                        unsigned short OUTCLKDivider, 
                                        double *actualCutoffFrequency);
short CVIDAQFUNC SCXI_Get_Chassis_Info (short SCXIChassisID, 
                                        short *chassisType,
                                        short *chassisAddress, 
                                        short *communicationMode,
                                        short *communicatorDevice, 
                                        short *numberofSlots);
short CVIDAQFUNC SCXI_Get_Module_Info (short SCXIChassisID, 
                                       short moduleSlotNumber,
                                       long *modulePresent, 
                                       short *operatingMode,
                                       short *DAQdeviceConnected);
short CVIDAQFUNC SCXI_Get_State (short SCXIChassisID, 
                                 short moduleSlotNumber, 
                                 short port,
                                 short moduleChannel, 
                                 unsigned long *data);
short CVIDAQFUNC SCXI_Get_Status (short SCXIChassisID, 
                                  short moduleSlotNumber, 
                                  short waitMode,
                                  unsigned long *statusRegister);
short CVIDAQFUNC SCXI_Load_Config (short SCXIChassisID);
short CVIDAQFUNC SCXI_ModuleID_Read (short scxiID, short module, long *id);
short CVIDAQFUNC SCXI_MuxCtr_Setup (short device, 
                                    short enable, 
                                    short scanDivide,
                                    unsigned short muxCounterValue);
short CVIDAQFUNC SCXI_Reset (short SCXIChassisID, 
                             short resetSlotNumber);
short CVIDAQFUNC SCXI_Scale (short SCXIChassisID, 
                             short moduleSlotNumber, 
                             short moduleChannel,
                             double moduleGain, 
                             double terminalBlockGain, 
                             short DAQDevice,
                             short DAQChannel, 
                             short DAQGain, 
                             unsigned long numberofSamples,
                             short binaryArray[], 
                             double voltageArray[]);
short CVIDAQFUNC SCXI_SCAN_Setup (short SCXIChassisID, 
                                  short numberofModules,
                                  short moduleList[], 
                                  short ofChannelsList[],
                                  short startChannelList[], 
                                  short inputDAQdevice,
                                  short scanningMode);
short CVIDAQFUNC SCXI_Set_Config (short SCXIChassisID, 
                                  short chassisType, 
                                  short chassisAddress,
                                  short communicationMode, 
                                  short communicatordevice,
                                  short numberofSlots, 
                                  long modulesPresent[],
                                  short operatingModes[], 
                                  short connectionMap[]);
short CVIDAQFUNC SCXI_Set_Gain (short SCXIChassisID, 
                                short moduleSlotNumber,
                                short moduleChannel, 
                                double moduleGain);
short CVIDAQFUNC SCXI_Set_Excitation (short chassisID,
                                      short module,
                                      short channel,
                                      short excitationType,
                                      float excitation,
                                      float *actualExcitation);
short CVIDAQFUNC SCXI_Configure_Connection (short chassisID,
                                            short module,
                                            short channel,
                                            short connectionType);
short CVIDAQFUNC SCXI_Set_Input_Mode (short SCXIChassisID, 
                                      short moduleSlotNumber,
                                      short inputMode);
short CVIDAQFUNC SCXI_Set_State (short SCXIChassisID, 
                                 short moduleSlotNumber, 
                                 short port, 
                                 short moduleChannel, 
                                 long data);
short CVIDAQFUNC SCXI_Set_Threshold (short SCXIChassisID, 
                                     short moduleSlotNumber, 
                                     short moduleChannel, 
									 double threshold,
									 double hysteresis);
short CVIDAQFUNC SCXI_Single_Chan_Setup (short SCXIChassisID, 
                                         short moduleSlotNumber,
                                         short moduleChannel, 
                                         short inputDAQdevice);
short CVIDAQFUNC SCXI_Track_Hold_Control (short SCXIChassisID, 
                                          short moduleSlotNumber,
                                          short state, 
                                          short inputDAQdevice);
short CVIDAQFUNC SCXI_Track_Hold_Setup (short SCXIChassisID, 
                                        short moduleSlotNumber,
                                        short inputMode, 
                                        short controlSource,
                                        short routeControlSignal, 
                                        short holdCount,
                                        short inputDAQdevice);

short CVIDAQFUNC Select_Signal (short device, 
                                unsigned long signalName,
                                unsigned long signalSource, 
                                unsigned long sourceSpecifiation);

short CVIDAQFUNC Set_DAQ_Device_Info (short device, 
                                      unsigned long typeofInformation,
                                      unsigned long informationValue);

short CVIDAQFUNC Timeout_Config (short device, 
                                 long timeout);

short CVIDAQFUNC Tio_Combine_Signals (short device,
                                      unsigned long internalLine,
                                      unsigned long logicalExpression);
short CVIDAQFUNC Tio_Select_Signal (short device,
                                    unsigned long signal,
                                    unsigned long source,
                                    unsigned long sourceSpec);

short CVIDAQFUNC Trigger_Window_Config (short device, 
                                        short mode,
                                        unsigned short triggerWindowSize);

short CVIDAQFUNC WFM_Chan_Control (short device, 
                                   short channel, 
                                   short channelOperation);
short CVIDAQFUNC WFM_Check (short device, 
                            short channel, 
                            short *WFMStopped,
                            unsigned long *iterationsDone, 
                            unsigned long *pointsGenerated);
short CVIDAQFUNC WFM_ClockRate (short device, 
                                short WFMGroupNumber, 
                                short clockSelect,
                                short timebase, 
                                unsigned long updateInterval, 
                                short mode);
short CVIDAQFUNC WFM_DB_Config (short device, 
                                short numberofChannels, 
                                short channelVector[],
                                short doubleBufferMode, 
                                short stoponOldData,
                                short stoponPartialXfer);
short CVIDAQFUNC WFM_DB_HalfReady (short device, 
                                   short numberofChannels, 
                                   short channelVector[],
                                   short *halfBufferDone);
short CVIDAQFUNC WFM_DB_Transfer (short device, 
                                  short numberofChannels, 
                                  short channelVector[],
                                  short arrayBuffer[], 
                                  unsigned long numberofPoints);
short CVIDAQFUNC WFM_from_Disk (short device, 
                                short numberofChannels, 
                                short channelVector[],
                                char fileName[], 
                                unsigned long startPoint,
                                unsigned long endPoint, 
                                unsigned long iterations,
                                double updateRate);
short CVIDAQFUNC WFM_Group_Control (short device, 
                                    short WFMGroupNumber, 
                                    short groupOperation);
short CVIDAQFUNC WFM_Group_Setup (short device, 
                                  short numberofChannels, 
                                  short channelVector[],
                                  short WFMGroupNumber);
short CVIDAQFUNC WFM_Load (short device, 
                           short numberofChannels, 
                           short channelVector[],
                           short waveformBuffer[], 
                           unsigned long numberofPoints,
                           unsigned long iterations, 
                           short mode);
short CVIDAQFUNC WFM_Op (short device, 
                         short numberofChannels, 
                         short channelVector[],
                         short waveformBuffer[], 
                         unsigned long numberofPoints,
                         unsigned long iterations, 
                         double updateRate);
short CVIDAQFUNC WFM_Rate (double updateRate, 
                           short units, 
                           short *timebase,
                           unsigned long *updateInterval);
short CVIDAQFUNC WFM_Scale (short device, 
                            short channel, 
                            unsigned long numberofPoints,
                            double gain, 
                            double voltageArray[], 
                            short binaryArray[]);
short CVIDAQFUNC WFM_Set_Clock(short device,
                               short group,
                               unsigned long whichClock,
                               double desiredRate,
                               unsigned long units,
                               double *actualRate);


/********************************************************************/
/* special low-level functions                                      */
/********************************************************************/
short CVIDAQFUNC getVXIDAQviSession (char *resourceName, unsigned long *viSession);
short CVIDAQFUNC getVXIDAQdeviceNum (unsigned long viSession, short *deviceNum);

/********************************************************************/
/* obsolete functions                                               */
/********************************************************************/

short CVIDAQFUNC  A2000_Calibrate (short device, 
                                   short saveNewValues, 
                                   short calibrationMethod,
                                   short channel, 
                                   double extRefVoltage);
short CVIDAQFUNC  A2000_Config (short device, 
                                short sampClkSource, 
                                short sampClkDrive,
                                short dither);
short CVIDAQFUNC  A2150_Calibrate (short device, 
                                   short ADC0Reference, 
                                   short ADC1Reference);
short CVIDAQFUNC  AI_Scale (short slot, short gain, short value, double *voltage);
short CVIDAQFUNC  AI_Config (short slot, short singOrDiff, short range, short uniOrBi);
short CVIDAQFUNC  AO_Config (short slot, short chan, short outputPolarity,
                             double refVoltage, short updateMode);
short CVIDAQFUNC  DAQ_DB_StrTransfer (short device, 
                                      char halfBuffer[],
                                      unsigned long *pointsTransferred, 
                                      short *DAQStopped);
short CVIDAQFUNC  DAQ_Scale (short slot, short gain, unsigned long cnt,
                             short rawData[], double scaledData[]);
short CVIDAQFUNC  DAQ_Trigger_Config (short slot, short preTrig, unsigned long preTrigCnt);
short CVIDAQFUNC  DIG_DB_StrTransfer (short device, 
                                      short groupNumber, 
                                      char halfBuffer[],
                                      unsigned long pointsTransferred);
short CVIDAQFUNC  DSP2200_Calibrate (short device, 
                                     short calibrateMode, 
                                     short analogInputRefrnce);
short CVIDAQFUNC  DSP2200_Config (short device, 
                                  short inputTranslation, 
                                  short outputTranslation,
                                  short demuxData);
short CVIDAQFUNC  Get_DA_Brds_Info (short slot, short *brdCode, short *baseAddr,
                                    short *irq1Lvl, short *irq2Lvl,
                                    short *irqTrigMode, short *dma1Lvl,
                                    short *dma2Lvl, short *daqMode);
short CVIDAQFUNC  Get_DAQ_Event (unsigned long timeOut, 
                                 DAQEventHandle *handle, 
                                 DAQEventMsg *message,
                                 DAQEventWParam *wParam, 
                                 DAQEventLParam *lParam);
short CVIDAQFUNC  Lab_SCAN_Check (short slot, short *status,
                                  unsigned long *retrieved, short finalScanOrder[]);
short CVIDAQFUNC  Lab_SCAN_Op (short slot, short numChans, short gain, short buffer[],
                               unsigned long cnt, double sampleRate, short finalScanOrder[]);
short CVIDAQFUNC  Lab_SCAN_Start (short slot, short numChans, short gain,
                                  short buffer[], unsigned long cnt, short timebase,
                                  unsigned short sampleInt);
short CVIDAQFUNC  Lab_SCAN_to_Disk (short slot, short numChans, short gain, char fileName[],
                                    unsigned long cnt, double sampleRate, short concat);
short CVIDAQFUNC  MAI_Arm (short device, 
                           short armDisarm);
short CVIDAQFUNC  MAI_Clear (short device);
short CVIDAQFUNC  MAI_Coupling (short device, 
                                short numChannels, 
                                short coupling[]);
short CVIDAQFUNC  MAI_Read (short device, 
                            short reading[]);
short CVIDAQFUNC  MAI_Scale (short device, 
                             unsigned long numScans, 
                             short values[],
                             double volts[]);
short CVIDAQFUNC  MAI_Setup (short device, 
                             short numChannels, 
                             short channelList[],
                             short gainList[], 
                             unsigned short muxInterval, 
                             short timebase,
                             short muxMode);
short CVIDAQFUNC  Master_Slave_Config (short device, 
                                       short numberofSlaves, 
                                       short slaveList[]);
short CVIDAQFUNC  MDAQ_Check (short device, 
                              short fullCheck, 
                              short *acqDone,
                              unsigned long *framesDone, 
                              unsigned long *scansDone);
short CVIDAQFUNC  MDAQ_Clear (short device);
short CVIDAQFUNC  MDAQ_Get (short device, 
                            short orientation, 
                            short retrieval,
                            unsigned long numScansFrames, 
                            unsigned long startFrame,
                            unsigned long startScan, 
                            long timeout, 
                            short buffer[],
                            unsigned long *numRetrieved, 
                            unsigned long *lastFrame,
                            unsigned long *lastScan, 
                            short *acqDone);
short CVIDAQFUNC  MDAQ_ScanRate (short device, 
                                 unsigned short scanInterval, 
                                 short timebase);
short CVIDAQFUNC  MDAQ_Setup (short device, 
                              unsigned long bufferSize, 
                              short orientation,
                              unsigned long preTriggerScans, 
                              unsigned long postTriggerScans,
                              short acqBuffer[]);
short CVIDAQFUNC  MDAQ_Start (short device, 
                              unsigned long numofTriggers);
short CVIDAQFUNC  MDAQ_Stop (short device);
short CVIDAQFUNC  MDAQ_StrGet (short device, 
                               short orientation, 
                               short retrieval,
                               unsigned long numScansFrames, 
                               unsigned long startFrame, 
                               unsigned long startScan, 
                               long timeout, 
                               char buffer[], 
                               unsigned long *numRetrieved, 
                               unsigned long *lastFrame, 
                               unsigned long *lastScan, 
                               short *acqDone);
short CVIDAQFUNC  MDAQ_Trig_Delay (short device, 
                                   unsigned short delayInterval, 
                                   short timebase);
short CVIDAQFUNC  MDAQ_Trig_Select (short device, 
                                    short digitalTrigger, 
                                    short triggerEdge,
                                    short analogTrigger, 
                                    short triggerSlope, 
                                    short triggerLevel,
                                    short ATriggerSource);
short CVIDAQFUNC  MIO_Calibrate (short device, 
                                 short calibrateOperation, 
                                 short saveNewValues,
                                 short EEPROMLocation, 
                                 short calRefChannel, 
                                 short DAC0Channel,
                                 short DAC1Channel, 
                                 double calRefVoltage,
                                 short referenceLocation);
short CVIDAQFUNC  MIO16_F5_Config (short slot, short dither);
short CVIDAQFUNC  MIO16_F5_Calibrate (short slot, short calOP, short saveNewCal,
                                      short EEPROMloc, short CalRefChan,
                                      short DAC0Chan, short DAC1Chan,
                                      double calRefVolts, short refLoc);
short CVIDAQFUNC  Peek_DAQ_Event (unsigned long timeOut, 
                                  DAQEventHandle *handle, 
                                  DAQEventMsg *message, 
                                  DAQEventWParam *wParam,  
                                  DAQEventLParam *lParam);
short CVIDAQFUNC  REG_Level_Read (short device, 
                                  short registerIndex, 
                                  unsigned long *registerValue);
short CVIDAQFUNC  REG_Level_Write (short device, 
                                   short registerIndex, 
                                   unsigned long bitsAffected, 
                                   unsigned long bitSettings, 
                                   unsigned long *registerValue);
/* SCXI_1200_Calibrate is the old name for Calibrate_1200 */
short CVIDAQFUNC  SCXI_1200_Calibrate (short device, 
                                       short calibrateOperation,
                                       short saveNewValues, 
                                       short EEPROMLocation,
                                       short referenceChannel, 
                                       short groundChannel,
                                       short DAC0Channel, 
                                       short DAC1Channel,
                                       double DCReferenceVoltage, 
                                       double gain);
short CVIDAQFUNC  SCXI_Set_Filter (short chassisID, short module, short channel,
                                   short externalDivideDown, double freq, double *actFreq);
short CVIDAQFUNC  SCXI_Set_Module_Gain (short chassisID, short module, short gain);
short CVIDAQFUNC  Set_DAQ_Mode (short slot, short newDaqMode);
short CVIDAQFUNC  USE_E_Series (void);
short CVIDAQFUNC  WF_Check (short slot, short chan, short *status,
                            unsigned long *itersDone, unsigned long *nextPoint);
short CVIDAQFUNC  WF_Clear (short slot);
short CVIDAQFUNC  WF_DB_Config (short slot, short chan, short DBmode, short oldDataStop);
short CVIDAQFUNC  WF_DB_StrTransfer (short slot, short chan, char buffer[],
                                     unsigned long cnt);
short CVIDAQFUNC  WF_DB_Transfer (short slot, short chan, short buffer[],
                                  unsigned long cnt);
short CVIDAQFUNC  WF_from_Disk (short slot, short chan, char fileName[],
                                unsigned long iters, double rate,
                                unsigned long startPt, unsigned long endPt);
short CVIDAQFUNC  WF_Load (short slot, short chan, short buffer[],
                           unsigned long cnt, unsigned long iterations);
short CVIDAQFUNC  WF_Op (short slot, short chan, short buf0[], short buf1[],
                         unsigned long cnt0, unsigned long cnt1, unsigned long iters0,
                         unsigned long iters1, double rate);
short CVIDAQFUNC  WF_Pause (short slot);
short CVIDAQFUNC  WF_Rate (double rate, short units, short *timebase,
                           unsigned short *updateInt);
short CVIDAQFUNC  WF_Resume (short slot);
short CVIDAQFUNC  WF_Scale (short slot, short chan, unsigned long cnt,
                             double gain, double realArray[], short intArray[]);
short CVIDAQFUNC  WF_Start (short slot, short timebase, unsigned short updateInt);
short CVIDAQFUNC  WFM_DB_StrTransfer (short device, 
                                      short numberofChannels,
                                      short channelVector[], 
                                      char stringBuffer[],
                                      unsigned long numberofPoints);
short CVIDAQFUNC  WFM_UpdateRate (short slot, short group, short timebase,
                                  unsigned long updateInterval, short mode);



#ifdef __cplusplus
}
#endif

#endif  /* __DATAACQ_HEADER */

