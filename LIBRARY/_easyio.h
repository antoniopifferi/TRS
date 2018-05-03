


/*============================================================================*/
/*                        L a b W i n d o w s / C V I                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 1987-1998.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       easyio.h                                                      */
/* Purpose:     Include file for LabWindows/CVI Easy I/O for DAQ Library      */
/* Version:     5,10,4,0                                                       */
/*                                                                            */
/*              The first number is the major CVI version number,             */
/*              the second number is the minor version number multiplied by   */
/*              1000 (e.g., .01 * 1000)                                       */
/*              the third number means:                                       */
/*              1 for alpha                                                   */
/*              2 for beta                                                    */
/*              3 for preview                                                 */
/*              4 for release                                                 */
/*              and the fourth number is the patch version (0 if the main     */
/*              release)                                                      */
/*                                                                            */
/*============================================================================*/


#ifndef _EASYIO_H_
#define _EASYIO_H_

#include "cvidef.h"

// This check determines if we are compiling for external WIN16 compiler
#if (!defined(_NI_mswin16_)) &&  \
     !(defined(_NI_mswin32_)||defined(__WIN32__)||defined(__NT__)||defined( _WIN32)||defined(WIN32))
   #define _FOR_EXTERNAL_WIN16_
   #define EASYIOFUNC __far __pascal
   #define EZ_FAR __far 
#else
   #define EASYIOFUNC CVIFUNC
   #define EZ_FAR
#endif

#define ANALOG_INPUT   0
#define ANALOG_OUTPUT  1
#define DIGITAL_INPUT  2
#define DIGITAL_OUTPUT 3
#define DEMUXED_MODE 0           /* obsolete, replaced by GROUP_BY_CHANNEL */
#define INTERLEAVED_MODE 1       /* obsolete, replaced by GROUP_BY_SCAN */
#define GROUP_BY_CHANNEL 0
#define GROUP_BY_SCAN 1
#define CONSECUTIVE_MODE 1
#define LATEST_MODE 3
#define RELATIVE_TO_TRIGGER_MODE 4
#define MAX_DEVICES 16
#define NO_TRIGGER 0
#define SW_ANALOG_TRIGGER 99
#define HW_ANALOG_TRIGGER 1
#define DIGITAL_TRIGGER_A 2
#define DIGITAL_TRIGGER_AB 3
#define SCAN_CLOCK_GATING 4
#define ETS_TRIGGER 6
#define POSITIVE_SLOPE 1
#define NEGATIVE_SLOPE 2
#define MULTITASKING_AWARE   1
#define MULTITASKING_UNAWARE 0

#define MAX_CHANNEL_NAME_LENGTH 30
#define ONE_COUNTER  0
#define TWO_COUNTERS 1
#define COUNT_UNTIL_TC 2
#define COUNT_CONTINUOUSLY 3
#define USE_COUNTER_SOURCE 0
#define USE_INTERNAL_TIMEBASE 1
#define COUNT_ON_RISING_EDGE 1
#define COUNT_ON_FALLING_EDGE 2
#define UNGATED_SOFTWARE_START 1
#define COUNT_WHILE_GATE_HIGH  2
#define COUNT_WHILE_GATE_LOW   3
#define START_COUNTING_ON_RISING_EDGE 4
#define START_COUNTING_ON_FALLING_EDGE 5
#define RESTART_ON_EACH_RISING_EDGE 6
#define RESTART_ON_EACH_FALLING_EDGE 7
#define HIGH_PULSE 0
#define LOW_PULSE 1
#define HIGH_TOGGLE 2
#define LOW_TOGGLE 3
#define MEASURE_HIGH_PULSE_WIDTH 2
#define MEASURE_LOW_PULSE_WIDTH 3
#define MEASURE_PERIOD_BTW_RISING_EDGES 4
#define MEASURE_PERIOD_BTW_FALLING_EDGES 5
#define I_TOGGLE_ON_TC 0
#define I_PROGRAMMABLE_ONE_SHOT 1
#define I_RATE_GENERATOR 2
#define I_SQUARE_WAVE_RATE_GENERATOR 3
#define I_SOFTWARE_TRIGGERED_STROBE 4
#define I_HARDWARE_TRIGGERED_STROBE 5
#define I_READ 6
#define I_RESET 7
#define I_LOW_STATE 0
#define I_HIGH_STATE 1
#define I_BCD 0
#define I_BINARY 1


#define POSITIVE_POLARITY 1
#define NEGATIVE_POLARITY 2




#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#ifdef __cplusplus
extern "C" {
#endif


char EZ_FAR * EASYIOFUNC GetDAQErrorString (short error);

short EASYIOFUNC GetNumChannels (short device, char EZ_FAR channelString[], short channelType, unsigned long EZ_FAR *numChannels);

short EASYIOFUNC GetChannelIndices (short device, char EZ_FAR channelString[], char EZ_FAR channelSubString[], short channelType,
             long EZ_FAR channelIndices[]);

short EASYIOFUNC GetChannelNameFromIndex (short device, char EZ_FAR channelString[], long index, short channelType, char EZ_FAR channelName[]);

short EASYIOFUNC GetAILimitsOfChannel (short device, char EZ_FAR channelString[], char EZ_FAR singleChannel[], double initialHighLimit,
                double initialLowLimit, double EZ_FAR *p_highLimit, double EZ_FAR *p_lowLimit);


short EASYIOFUNC GroupByChannel (double EZ_FAR array[], long numberofScans, unsigned long groupSize);

short EASYIOFUNC AISampleChannel (short device, char EZ_FAR channelString[], double upperLimit,
                double lowerLimit, double EZ_FAR *voltage);

short EASYIOFUNC AISampleChannels (short device, char EZ_FAR channelString[], double upperLimit,
            double lowerLimit, double EZ_FAR voltages[]);


short EASYIOFUNC AIAcquireWaveforms (short device, char EZ_FAR channelString[],
              long numberOfSamplesPerChannel, double scanRate,
              double upperLimit, double lowerLimit,
              double EZ_FAR *actualScanPeriod, short fillMode,
              double EZ_FAR waveform[]);

short EASYIOFUNC AIAcquireTriggeredWaveforms (short device, char EZ_FAR channelString[],
                  long numberOfScans, double scanRate,
                  double upperLimit, double lowerLimit,
                  double EZ_FAR *p_actualScanFreq, unsigned short triggerType,
                  unsigned short edgeSlope, double level,
                  char EZ_FAR triggerSource[], long preTriggerScans,
                  double timeLimit, short fillMode, double EZ_FAR waveform[]);


short EASYIOFUNC AIStartAcquisition (short device, char EZ_FAR channelString[], long bufferSize,
              double scanRate, double highLimitvolts, double lowLimitvolts,
              double EZ_FAR *actualScanFreq, unsigned long EZ_FAR *taskID);

short EASYIOFUNC AICheckAcquisition (unsigned long taskID, unsigned long EZ_FAR *p_scanBacklog);


short EASYIOFUNC AIReadAcquisition (unsigned long taskID, long scanstoRead, unsigned short readMode,
             unsigned long EZ_FAR *scanBacklog, short fillMode,
             double EZ_FAR waveforms[]);

short EASYIOFUNC AIClearAcquisition (unsigned long taskID);


short EASYIOFUNC PlotLastAIWaveformsPopup (short device, double EZ_FAR voltages[]);

short EASYIOFUNC AOUpdateChannel (short device, char EZ_FAR channelString[], double voltage);

short EASYIOFUNC AOUpdateChannels (short device, char EZ_FAR channelString[], double EZ_FAR voltages[]);

short EASYIOFUNC AOGenerateWaveforms (short device, char EZ_FAR channelString[],
               double updatesSecond, long updatesChannel,
               long iterations, double EZ_FAR waveforms[],
               unsigned long EZ_FAR *taskID);

short EASYIOFUNC AOClearWaveforms (unsigned long taskID);

short EASYIOFUNC WriteToDigitalLine (short device, char EZ_FAR portNumber[], short line,
              short portWidth, long iteration, unsigned long lineState);

short EASYIOFUNC WriteToDigitalPort (short device, char EZ_FAR portNumber[], short portWidth,
              long iteration, unsigned long pattern);

short EASYIOFUNC ReadFromDigitalLine (short device, char EZ_FAR portNumber[], short line,
              short portWidth, long iteration, unsigned long EZ_FAR *lineState);

short EASYIOFUNC ReadFromDigitalPort (short device, char EZ_FAR portNumber[],
               short portWidth, long iteration, unsigned long EZ_FAR *p_pattern);

short EASYIOFUNC CounterMeasureFrequency (short device, char EZ_FAR counter[],
                   unsigned short counterSize,
                   double gateWidthSampleTimeinSec,
                   double maxDelayBeforeGateSec,
                   unsigned short gateMode, double EZ_FAR *actualGateWidth,
                   short EZ_FAR *overflow, short EZ_FAR *valid, short EZ_FAR *timeout,
                   double EZ_FAR *frequency);


short EASYIOFUNC CounterEventOrTimeConfig(short device, char EZ_FAR counter[], unsigned short counterSize,
                   double sourceOrTimebase, unsigned short countLimitAction,
                   short sourceEdge, unsigned short gateMode, unsigned long EZ_FAR *p_taskID);

short EASYIOFUNC ContinuousPulseGenConfig (short device, char EZ_FAR counter[], double frequency,
               double dutyCycle, unsigned short gateMode,
               unsigned short pulsePolarity, double EZ_FAR *actualFrequency,
               double EZ_FAR *actualDutyCycle, unsigned long EZ_FAR *taskID);

short EASYIOFUNC DelayedPulseGenConfig (short device, char EZ_FAR counter[],
                 double pulseDelay, double pulseWidth,
                 unsigned short timebaseSource, unsigned short gateMode,
                 unsigned short pulsePolarity, double EZ_FAR *actualDelay,
                 double EZ_FAR *actualPulseWidth, unsigned long EZ_FAR *taskID);

short EASYIOFUNC FrequencyDividerConfig (short device, char EZ_FAR counter[], double sourceTimebase,
                  double timebaseDivisor, unsigned short gateMode,
                  unsigned short outputBehavior, short sourceEdge,
                  unsigned long EZ_FAR *taskID);

short EASYIOFUNC PulseWidthOrPeriodMeasConfig (short device, char EZ_FAR counter[],
                   unsigned short typeOfMeasurement,
                   double sourceTimebase, unsigned long EZ_FAR *taskID);


short EASYIOFUNC CounterStart (unsigned long taskID);
short EASYIOFUNC CounterRead (unsigned long taskID, long EZ_FAR * count, short EZ_FAR * overflow);
short EASYIOFUNC CounterStop (unsigned long taskID);

short EASYIOFUNC ICounterControl (short device, short counter, short controlCode,
                unsigned short count, short binaryorBCD,
                short outputState, unsigned short EZ_FAR *readValue);

void EASYIOFUNC SetEasyIOMultitaskingMode (int Multitasking_Mode);


enum DAQErrors
{
    cmdSyntaxErr                 = -9000,
    cmdLimitSyntaxErr            = -9001,
    cmdInterChannelRateSyntaxErr = -9002,

    syntaxErr                    = -10001,
    semanticsErr                 = -10002,
    invalidValueErr              = -10003,
    valueConflictErr             = -10004,
    badDeviceErr                 = -10005,
    badLineErr                   = -10006,
    badChanErr                   = -10007,
    badGroupErr                  = -10008,
    badCounterErr                = -10009,
    badCountErr                  = -10010,
    badIntervalErr               = -10011,
    badRangeErr                  = -10012,
    badRangeWarn                 =  10012,
    badErrorCodeErr              = -10013,
    groupTooLargeErr             = -10014,
    badTimeLimitErr              = -10015,
    badReadCountErr              = -10016,
    badReadModeErr               = -10017,
    badReadOffsetErr             = -10018,
    badClkFrequencyErr           = -10019,
    badTimebaseErr               = -10020,
    badLimitsErr                 = -10021,
    badWriteCountErr             = -10022,
    badWriteModeErr              = -10023,
    badWriteOffsetErr            = -10024,
    limitsOutOfRangeWarn         =  10025,
    limitsOutOfRangeErr          = -10025,
    badInputBufferSpecification  = -10026,
    badDAQEventErr               = -10027,
    badFilterCutoffErr           = -10028,
    obsoleteFunctionErr          = -10029,
    badBaudRateErr               = -10030,
    badChassisIDErr              = -10031,
    badModuleSlotErr             = -10032,
    invalidWinHandleErr          = -10033,
    noSuchMessageErr             = -10034,

    badGainErr                   = -10080,
    badPretrigCountErr           = -10081,
    badPosttrigCountErr          = -10082,
    badTrigModeErr               = -10083,
    badTrigCountErr              = -10084,
    badTrigRangeErr              = -10085,
    badExtRefErr                 = -10086,
    badTrigTypeErr               = -10087,
    badTrigLevelErr              = -10088,
    badTotalCountErr             = -10089,
    badRPGErr                    = -10090,
    badIterationsErr             = -10091,
    lowScanIntervalErr           = -10092,
    fifoModeErr                  = -10093,

    badPortWidthErr              = -10100,

    gpctrBadApplicationErr       = -10120,
    gpctrBadCounterNumberErr     = -10121,
    gpctrBadParamValueErr        = -10122,
    gpctrBadParamIdErr           = -10123,
    gpctrBadEntityIdErr          = -10124,
    gpctrBadActionErr            = -10125,

    EEPROMreadErr                = -10200,
    EEPROMwriteErr               = -10201,

    noDriverErr                  = -10240,
    oldDriverErr                 = -10241,
    functionNotFoundErr          = -10242,
    configFileErr                = -10243,
    deviceInitErr                = -10244,
    osInitErr                    = -10245,
    communicationsErr            = -10246,
    cmosConfigErr                = -10247,
    dupAddressErr                = -10248,
    intConfigErr                 = -10249,
    dupIntErr                    = -10250,
    dmaConfigErr                 = -10251,
    dupDMAErr                    = -10252,
    switchlessBoardErr           = -10253,
    DAQCardConfigErr             = -10254,
    remoteChassisDriverInitErr   = -10255,
    comPortOpenErr               = -10256,
    baseAddressErr               = -10257,
    dmaChannel1Err               = -10258,
    dmaChannel2Err               = -10259,

    noConnectErr                 = -10340,
    badConnectErr                = -10341,
    multConnectErr               = -10342,
    SCXIConfigErr                = -10343,
    chassisNotSynchedErr         = -10344,
    chassisMemAllocErr           = -10345,
    badPacketErr                 = -10346,
    chassisCommunicationErr      = -10347,
    waitingForReprogErr          = -10348,
    SCXIModuleTypeConflictErr    = -10349,

    DSPInitErr                   = -10360,
    badScanListErr               = -10370,
    userOwnedRsrcErr             = -10400,
    unknownDeviceErr             = -10401,
    unknownDeviceErrOld        = -60,
    deviceNotFoundErr            = -10402,
    deviceSupportErr             = -10403,
    noLineAvailErr               = -10404,
    noChanAvailErr               = -10405,
    noGroupAvailErr              = -10406,
    lineBusyErr                  = -10407,
    chanBusyErr                  = -10408,
    groupBusyErr                 = -10409,
    relatedLCGBusyErr            = -10410,
    counterBusyErr               = -10411,
    noGroupAssignErr             = -10412,
    groupAssignErr               = -10413,
    reservedPinErr               = -10414,
    externalMuxSupportErr        = -10415,
    DSPDataPathBusyErr           = -10416,
    SCXIModuleNotSupportedErr    = -10417,

    sysOwnedRsrcErr              = -10440,
    memConfigErr                 = -10441,
    memDisabledErr               = -10442,
    memAlignmentErr              = -10443,
    memFullErr                   = -10444,
    memLockErr                   = -10445,
    memPageErr                   = -10446,
    memPageLockErr               = -10447,
    stackMemErr                  = -10448,
    cacheMemErr                  = -10449,
    physicalMemErr               = -10450,
    virtualMemErr                = -10451,
    noIntAvailErr                = -10452,
    intInUseErr                  = -10453,
    noDMACErr                    = -10454,
    noDMAAvailErr                = -10455,
    DMAInUseErr                  = -10456,
    badDMAGroupErr               = -10457,
    diskFullErr                  = -10458,
    DLLInterfaceErr              = -10459,
    interfaceInteractionErr      = -10460,

    muxMemFullErr                = -10480,
    bufferNotInterleavedErr      = -10481,

    invalidDSPhandleErr          = -10560,
    noSetupErr                   = -10600,
    multSetupErr                 = -10601,
    noWriteErr                   = -10602,
    groupWriteErr                = -10603,
    activeWriteErr               = -10604,
    endWriteErr                  = -10605,
    notArmedErr                  = -10606,
    armedErr                     = -10607,
    noTransferInProgWarn         =  10608,
    noTransferInProgErr          = -10608,
    transferInProgErr            = -10609,
    transferPauseErr             = -10610,
    badDirOnSomeLinesErr         = -10611,
    badLineDirErr                = -10612,
    badChanDirErr                = -10613,
    badGroupDirErr               = -10614,
    masterClkErr                 = -10615,
    slaveClkErr                  = -10616,
    noClkSrcErr                  = -10617,
    badClkSrcErr                 = -10618,
    multClkSrcErr                = -10619,
    noTrigErr                    = -10620,
    badTrigErr                   = -10621,
    preTrigErr                   = -10622,
    postTrigErr                  = -10623,
    delayTrigErr                 = -10624,
    masterTrigErr                = -10625,
    slaveTrigErr                 = -10626,
    noTrigDrvErr                 = -10627,
    multTrigDrvErr               = -10628,
    invalidOpModeErr             = -10629,
    invalidReadErr               = -10630,
    noInfiniteModeErr            = -10631,
    someInputsIgnoredErr         = -10632,
    invalidRegenModeErr          = -10633,
    noContTransferInProgErr      = -10634,
    invalidSCXIOpModeErr         = -10635,
    noContWithSynchErr           = -10636,
    bufferAlreadyConfigErr       = -10637,
    badChanGainErr               = -10680,
    badChanRangeErr              = -10681,
    badChanPolarityErr           = -10682,
    badChanCouplingErr           = -10683,
    badChanInputModeErr          = -10684,
    clkExceedsBrdsMaxConvRate    = -10685,
    scanListInvalidErr           = -10686,
    bufferInvalidErr             = -10687,
    noTrigEnabledErr             = -10688,
    digitalTrigBErr              = -10689,
    digitalTrigAandBErr          = -10690,
    extConvRestrictionErr        = -10691,
    chanClockDisabledErr         = -10692,
    extScanClockErr              = -10693,
    unsafeSamplingFreqErr        = -10694,
    DMAnotAllowedErr             = -10695,
    multiRateModeErr             = -10696,
    rateNotSupportedErr          = -10697,
    timebaseConflictErr          = -10698,
    polarityConflictErr          = -10699,
    signalConflictErr            = -10700,
    noLaterUpdateErr             = -10701,
    prePostTriggerErr            = -10702,

    noHandshakeModeErr           = -10710,

    noEventCtrErr                = -10720,

    SCXITrackHoldErr             = -10740,

    sc2040InputModeErr           = -10780,
    outputTypeMustBeVoltageErr   = -10781,
    sc2040HoldModeErr            = -10782,
    calConstPolarityConflictErr  = -10783,

    timeOutErr                   = -10800,
    timeOutWarn                  =  10800,
    calibrationErr               = -10801,
    dataNotAvailErr              = -10802,
    transferStoppedErr           = -10803,
    earlyStopErr                 = -10804,
    overRunErr                   = -10805,
    noTrigFoundErr               = -10806,
    earlyTrigErr                 = -10807,
    LPTCommunicationErr          = -10808,
    gateSignalErr                = -10809,
    internalDriverErr            = -10810,
    internalKernelErr            = -10811,

    softwareErr                  = -10840,
    firmwareErr                  = -10841,
    hardwareErr                  = -10842,
    underFlowErr                 = -10843,
    underWriteErr                = -10844,
    overFlowErr                  = -10845,
    overWriteErr                 = -10846,
    dmaChainingErr               = -10847,
    noDMACountAvailErr           = -10848,
    openFileErr                  = -10849,
    closeFileErr                 = -10850,
    fileSeekErr                  = -10851,
    readFileErr                  = -10852,
    writeFileErr                 = -10853,
    miscFileErr                  = -10854,
    osUnsupportedErr             = -10855,
    osErr                        = -10856,

    updateRateChangeErr          = -10880,
    partialTransferCompleteErr   = -10881,
    daqPollDataLossErr           = -10882,
    wfmPollDataLossErr           = -10883,
    pretrigReorderErr            = -10884,

    gpctrDataLossErr             = -10920,

    chassisResponseTimeoutErr    = -10940,
    reprogrammingFailedErr       = -10941,
    invalidResetSignatureErr     = -10942,
};

/********            Low Level Functions          ********/

short EASYIOFUNC DIOPortConfig (short device, char EZ_FAR portNumber[],
             short portWidth, long lineDirMap,
             unsigned long EZ_FAR *taskID);

short EASYIOFUNC DIOPortRead (unsigned long taskID, long lineMask,
           unsigned long EZ_FAR *pattern);

short EASYIOFUNC DIOPortWrite (unsigned long taskID, unsigned long pattern,
           long lineMask);

/*********************************************************/


/********        Instrument Driver Functions      ********/

/*******************************************************************/
/*                       Utility functions                         */
/*******************************************************************/
short EASYIOFUNC ID_ChannelToIndex (
      unsigned long taskID,
      char EZ_FAR *channelString,
      short EZ_FAR *numChans,
      long EZ_FAR *indices);

short EASYIOFUNC ID_FOUT_Control(
      unsigned long taskID,
      short control_code,
      double frequency,
      short divisor);

short EASYIOFUNC ID_GetKernelModeDeviceAccess(
      short deviceNum);

short EASYIOFUNC ID_GetVXIDAQ_DeviceNumber(
      char EZ_FAR *resourceName,
      short EZ_FAR *deviceNum);

short EASYIOFUNC ID_Reset(
      unsigned long taskID,
      short device);

short EASYIOFUNC ID_Route_Signal(
      unsigned long taskID,
      short signal,
      short source);

/*******************************************************************/
/*                      DMM class functions                        */
/*******************************************************************/
short EASYIOFUNC ID_Get_AI_FilterNotch(
      unsigned long taskID,
      double EZ_FAR *frequency);

short EASYIOFUNC ID_Get_AI_Measurement_Mode(
      unsigned long taskID,
      short EZ_FAR *measMode);

short EASYIOFUNC ID_Set_AI_FilterNotch(
      unsigned long taskID,
      double frequency);

short EASYIOFUNC ID_Set_AI_Measurement_Mode(
      unsigned long taskID,
      short measMode);

/*****************************************************************************/
/*                      Scope class Functions                                */
/*****************************************************************************/
short EASYIOFUNC ID_Get_RIS_Parameters(
      unsigned long taskID,
      short parameter,
      double EZ_FAR *floatOut);

short EASYIOFUNC ID_Set_AI_Impedence(
      unsigned long taskID,
      double impedence,
      char EZ_FAR *channelString);

/*******************************************************************/
/*                     Analog Input functions                      */
/*******************************************************************/
short EASYIOFUNC ID_AI_Group_Config(
      short device,
      short group,
      char EZ_FAR *channels,
      unsigned long EZ_FAR *taskID);

short EASYIOFUNC ID_AI_Group_Config_Adv(
      short device,
      short group,
      short numStrings,
      char EZ_FAR *channels,
      unsigned long EZ_FAR *taskID);

short EASYIOFUNC ID_AI_FIFO_Read_Status(
      unsigned long taskID,
      short EZ_FAR *acqStatus,
      short EZ_FAR *dataRemaining);

short EASYIOFUNC ID_AI_FIFO_Read_Binary(
      unsigned long taskID,
      short mode,
      double timeLimit,
      short EZ_FAR *binaryData);

short EASYIOFUNC ID_AI_FIFO_Read_Volts(
      unsigned long taskID,
      short mode,
      double timeLimit,
      double EZ_FAR *voltageData);

short EASYIOFUNC ID_AI_Read_Binary(
      unsigned long taskID,
      long numberToRead,
      double timeLimit,
      short EZ_FAR *binaryBuffer);

short EASYIOFUNC ID_AI_Read_Status(
      unsigned long taskID,
      long EZ_FAR *scanBacklog,
      short EZ_FAR *acqDone);

short EASYIOFUNC ID_AI_Read_Volts(
      unsigned long taskID,
      long numberToRead,
      double timeLimit,
      double EZ_FAR *voltageBuffer);

short EASYIOFUNC ID_AI_Read_Volts_Adv(
      unsigned long taskID,
      long numberToRead,
      short mode,
      long offset,
      double timeLimit,
      double EZ_FAR *voltageBuffer);

short EASYIOFUNC ID_AI_Single_Scan(
      unsigned long taskID,
      double timeLimit,
      double EZ_FAR *voltageData);

short EASYIOFUNC ID_Get_AI_ChannelString(
      unsigned long taskID,
      char EZ_FAR *channelString);

short EASYIOFUNC ID_Get_AI_Conditional_Retrieval(
      short EZ_FAR *condMode,
      long EZ_FAR *condIndex,
      short EZ_FAR *condSlope,
      double EZ_FAR *condLevel,
      double EZ_FAR *condHysteresis,
      long EZ_FAR *condSkipCount,
      long EZ_FAR *condOffset);

short EASYIOFUNC ID_Get_AI_Group_Size(
      unsigned long taskID,
      long EZ_FAR *size);

short EASYIOFUNC ID_Get_AI_Limits(
      unsigned long taskID,
      double EZ_FAR upperLimits[],
      double EZ_FAR lowerLimits[]);

short EASYIOFUNC ID_Get_AI_Mode(
      unsigned long taskID,
      short EZ_FAR modeArray[]);

short EASYIOFUNC ID_Get_AI_Trigger_Config(
      unsigned long taskID,
      double EZ_FAR *trigLevel,
      double EZ_FAR *hysteresis,
      double EZ_FAR *delay);

short EASYIOFUNC ID_Set_AI_Allocation_Mode(
      unsigned long taskID,
      short allocMode);

short EASYIOFUNC ID_Set_AI_Buffer_Size(
      unsigned long taskID,
      long bufferSize);

short EASYIOFUNC ID_Set_AI_ChannelString(
      unsigned long taskID,
      long numberOfChannels,
      char EZ_FAR *channelString);

short EASYIOFUNC ID_Set_AI_ChannelString_Adv(
      unsigned long taskID,
      long numberOfChannels,
      short channelSets,
      char EZ_FAR *channelString);

short EASYIOFUNC ID_Set_AI_Clock_Config(
      unsigned long taskID,
      short clock,
      short sourceCode,
      char EZ_FAR *sourceString,
      double clockFrequency);

short EASYIOFUNC ID_Set_AI_Conditional_Retrieval(
      short condMode,
      long condIndex,
      short condSlope,
      double condLevel,
      double condHysteresis,
      long condSkipCount,
      long condOffset);

short EASYIOFUNC ID_Set_AI_Control(
      unsigned long taskID,
      short controlCode,
      long totalScans);

short EASYIOFUNC ID_Set_AI_Control_Adv(
      unsigned long taskID,
      short controlCode,
      long totalScans,
      long preTriggerScans);

short EASYIOFUNC ID_Set_AI_Coupling(
      unsigned long taskID,
      short numberOfChannels,
      short EZ_FAR couplingArray[]);

short EASYIOFUNC ID_Set_AI_Limits(
      unsigned long taskID,
      long numberOfChannels,
      double EZ_FAR upperLimits[],
      double EZ_FAR lowerLimits[]);

short EASYIOFUNC ID_Set_AI_Mode(
      unsigned long taskID,
      long numberOfChannels,
      short EZ_FAR modeArray[]);

short EASYIOFUNC ID_Set_AI_Trigger_Conditions(
      unsigned long taskID,
      short edgeSlope,
      double trigLevel,
      double hysteresis,
      double delay,
      double timeLimit);

short EASYIOFUNC ID_Set_AI_Trigger_Coupling(
      unsigned long taskID,
      short coupling);

short EASYIOFUNC ID_Set_AI_Trigger_Type(
      unsigned long taskID,
      short type,
      short onOff,
      char EZ_FAR *sourceStr);

/*******************************************************************/
/*                     Analog Output functions                     */
/*******************************************************************/
short EASYIOFUNC ID_AO_Group_Config(
     short device,
     short group,
     char EZ_FAR *channels,
     unsigned long EZ_FAR *taskID);

short EASYIOFUNC ID_AO_Group_Config_Adv(
     short device,
     short group,
     char EZ_FAR *channels,
     unsigned long EZ_FAR *taskID);

short EASYIOFUNC ID_AO_Trigger(
      unsigned long taskID);

short EASYIOFUNC ID_AO_Write(
      unsigned long taskID,
      short numOfChannels,
      double EZ_FAR *voltageArray);

short EASYIOFUNC ID_AO_Write_Volts(
      unsigned long taskID,
      long numToWrite,
      double EZ_FAR voltageBuffer[],
      double timeLimit);

short EASYIOFUNC ID_Get_AO_ChannelString(
      unsigned long taskID,
      char EZ_FAR *channelString);

short EASYIOFUNC ID_Get_AO_ChannelType(
      unsigned long taskID,
      short EZ_FAR *channelTypes);

short EASYIOFUNC ID_Get_AO_Clock_Freq(
      unsigned long taskID,
      double EZ_FAR *clockFrequency);

short EASYIOFUNC ID_Get_AO_Group_Size(
      unsigned long taskID,
      short EZ_FAR *groupSize);

short EASYIOFUNC ID_Get_AO_Limits(
      unsigned long taskID,
      double EZ_FAR *upperLimits,
      double EZ_FAR *lowerLimits);

short EASYIOFUNC ID_Get_AO_Status(
      unsigned long taskID,
      long EZ_FAR *outputMark,
      long EZ_FAR *iterationsDone,
      short EZ_FAR *bufferState);

short EASYIOFUNC ID_Set_AO_Allocation_Mode(
      unsigned long taskID,
      short allocMode);

short EASYIOFUNC ID_Set_AO_Buffer_Size(
      unsigned long taskID,
      long numUpdates);

short EASYIOFUNC ID_Set_AO_ChannelType(
      unsigned long taskID,
      short numberOfChannels,
      char EZ_FAR *channelString,
      short EZ_FAR *channelTypes);

short EASYIOFUNC ID_Set_AO_Clock_Config(
      unsigned long taskID,
      short clock,
      short sourceCode,
      char EZ_FAR *sourceString,
      double clockFrequency);

short EASYIOFUNC ID_Set_AO_Control(
      unsigned long taskID,
      short controlCode,
      long iterations);

short EASYIOFUNC ID_Set_AO_Defaults(
      unsigned long taskID);

short EASYIOFUNC ID_Set_AO_Limits(
      unsigned long taskID,
      short numberOfChannels,
      char EZ_FAR *channelString,
      double EZ_FAR *upperLimits,
      double EZ_FAR *lowerLimits);

short EASYIOFUNC ID_Set_AO_Regeneration(
      unsigned long taskID,
      short regenMode);

short EASYIOFUNC ID_Set_AO_Trigger_Conditions(
      unsigned long taskID,
      short edgeSlope);

short EASYIOFUNC ID_Set_AO_Trigger_Type(
      unsigned long taskID,
      short triggerSource,
      char EZ_FAR *sourceStr);



#ifdef __cplusplus
}
#endif

#endif /* _H */
