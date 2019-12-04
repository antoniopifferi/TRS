/*
#######################################

Copyright 2019 Micro-Photon-Devices s.r.l.

SOFTWARE PRODUCT: SOLUS_SDK

Micro-Photon-Devices (MPD) expressly disclaims any warranty for the SOFTWARE PRODUCT.
The SOFTWARE PRODUCT is provided 'As Is' without any express or implied warranty of any kind,
including but not limited to any warranties of merchantability, noninfringement, or
fitness of a particular purpose. MPD does not warrant or assume responsibility for the
accuracy or completeness of any information, text, graphics, links or other items contained
within the SOFTWARE PRODUCT. MPD further expressly disclaims any warranty or representation
to Authorized Users or to any third party.
In no event shall MPD be liable for any damages (including, without limitation, lost profits,
business interruption, or lost information) rising out of 'Authorized Users' use of or inability
to use the SOFTWARE PRODUCT, even if MPD has been advised of the possibility of such damages.
In no event will MPD be liable for loss of data or for indirect, special, incidental,
consequential (including lost profit), or other damages based in contract, tort
or otherwise. MPD shall have no liability with respect to the content of the
SOFTWARE PRODUCT or any part thereof, including but not limited to errors or omissions contained
therein, libel, infringements of rights of publicity, privacy, trademark rights, business
interruption, personal injury, loss of privacy, moral rights or the disclosure of confidential
information.

#######################################
*/

/** @file */

#ifndef __SOLUS_SDK_h__
#define __SOLUS_SDK_h__

#ifdef __cplusplus
extern "C" {
#endif

	/**
	\mainpage SOLUS Software Development Kit (SOLUS-SDK)
	Software Development Kit (SDK) for the SOLUS probe.
	This software allows the communication between a Windows PC and the SOLUS probe. It must be included in the user software as a DLL, which provides all the functions
	to properly configurate and operate the probe.
	In order to execute a program which links to the SDK library, the following files are required:
	\verbatim
	SOLUS_SDK.dll		Software development kit library
	\endverbatim
	*/

	/**\file SOLUS_SDK.h
	SOLUS probe software development kit.
	This C header contains all the functions and custom types needed to operate the SOLUS probe in user defined applications.
	*/

#ifndef DllSDKExport
#if defined(_WIN32)
#define DllSDKExport __declspec(dllexport)
#include <Windows.h>
#else
#define DllSDKExport __attribute__ ((visibility("default")))
#endif
#endif

	/**
	* \defgroup Define SOLUS-SDK macros
	Macro definitions for SOLUS-SDK. DO NOT CHANGE.
	*/
	/*@{*/

#define MAX_SEQUENCE 384						/**<Max Sequence Lenght.*/
#define MAX_FRAMES 384*8						/**<Max frames.*/
#define HISTOGRAM_BINS 128						/**<Number of histogram bins.*/
#define FRAME_SIZE_INT_HIST (2 + 4 + 192 + 2)	/**<Frame size histogram mode.*/
#define FRAME_SIZE_INT (2 + 4 + 2)				/**<Frame size intensity mode.*/
#define N_LD 4									/**<Number of laser driver chip per optode.*/
#define N_OPTODE 8								/**<Number of optode. */
#define N_PIXEL 1728							/**<Number of GSIPM pixels.*/
#define EEPROM_SIZE 4096						/**<EEPROM size.*/

	/*@}*/

	/**
	* \defgroup Flags Measurement flags
	Measurement flags definitions for SOLUS-SDK. DO NOT CHANGE.
	*/
	/*@{*/

#define FORCE_LASER_OFF 1					/**<If 1 force all laser off during the sequence*/
#define AUTOCAL 2							/**<Specify if autocalibration of attenuation should be performed before each line of the sequence. If 0, the value of attenuation specified in the sequence will be used.*/
#define OVERRIDE_MAP 4						/**<If 1, the attwnuation field of the sequence specify the sungle SPAD to be switched on instead of the area.*/
#define	GSIPM_GATE_OFF_AFTER_MEAS 8			/**<If 1, switch the GSIPM gate off after a sequence*/
#define	laser_OFF_AFTER_MEAS 16				/**<If 1, switch all laser off after a sequence.*/
#define	TURNOFF_UNUSED_LD 32				/**<If 1, put unused LD in low power mode.*/
#define	TRIM_METHOD_BITL 64					/**<Set the trim algorith to be used (LSB).*/
#define	TRIM_METHOD_BITh 128				/**<Set the trim algorith to be used (MSB).*/
#define	DISABLE_INTERLOCK 256				/**<If 1, bypass contact sensor interlock.*/


	/*@}*/

	/**
	* \defgroup Enum SOLUS-SDK custom Types and structures
	Custom types used by the SDK. Must be used by the user to properly set/get data. Do not use raw data.
	*/
	/*@{*/

	/**Enum type for the optode/control address.	*/
	typedef enum
	{
		OPTODE1 = 0,	/**<Optode 1 address*/
		OPTODE2 = 1,	/**<Optode 2 address*/
		OPTODE3 = 2,	/**<Optode 3 address*/
		OPTODE4 = 3,	/**<Optode 4 address*/
		OPTODE5 = 4,	/**<Optode 5 address*/
		OPTODE6 = 5,	/**<Optode 6 address*/
		OPTODE7 = 6,	/**<Optode 7 address*/
		OPTODE8 = 7,	/**<Optode 8 address*/
		CONTROL = 8		/**<Control address*/
	} ADDRESS;

	/**Error codes returned by the SOLUS functions.	*/
	typedef enum {
		OK = 0,                                 /**<The function returned successfully.*/
		COMM_ERROR = -1,						/**<Communication error. Check connections.*/
		OUT_OF_MEMORY = -2,						/**<Not enough memory to allocate the structure.*/
		INVALID_POINTER = -3,					/**<An invalid pointer was passed as parameter.*/
		COMM_TIMEOUT = -4,						/**<Timeout during communication.*/
		OUT_OF_RANGE = -5,						/**<Parameters out of range.*/
		INVALID_OP = -6,                        /**<The required function can not be executed. */
		PROBE_ERROR = -7,						/**<Probe returned an error code.*/
		FIRMWARE_NOT_COMPATIBLE = -8,           /**<Firmware not compatible.*/
		OPTODE_NOT_PRESENT = -9,				/**<Optode not present or not working.*/
		FIRMWARE_UPDATE_ERROR = -10,			/**<Error during firmware update.*/
		SEQUENCE_ALREADY_RUNNING = -11,			/**<A sequence is already running.*/
		NO_SEQUENCE_RUNNING = -12				/**<A sequence has not been started yet.*/
	} SOLUS_Return;

	/**Types of acquisition data.	*/
	typedef enum
	{
		Intensity = 0,		/**<Only intensity is acquired*/
		Int_Hist = 1		/**<Intensity and full histogram are acquired*/
	} DataType;

#pragma pack(push,1)

	/**Laser Driver register structure containing all registers for one LD chip (two laser drivers). Note that only few on them needs to be changed during normal use.
	They will be saved into the internal optode EEPROM and loaded on startup. If it is needed to change some of them, the user must load
	the actual values from the probe, save them into a local structure, modify only the required fields, and program the structure back to the optode
	(optionally saving it in the EEPROM).	*/
	struct _LD_reg
	{
		// channel 1
		UINT16 CH1_DELAY_F1 : 10;		/**<Channel 1 Delay Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT8 CH1_DELAYC1 : 4;			/**<Channel 1 Delay Coarse.*/
		UINT8 : 4;						/**<Zero bits.*/
		UINT16 CH1_WIDTH_F1 : 10;		/**<Channel 1 Width Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT16 CH1_WIDTH_C1 : 5;		/**<Channel 1 Width Coarse.*/
		UINT16 : 11;					/**<Zero bits.*/
		UINT16 CH1_IFINE1 : 10;			/**<Channel 1 Current Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT8 CH1_ICOARSE1 : 3;			/**<Channel 1 Current Coarse.*/
		UINT8 : 5;						/**<Zero bits.*/
		// channel 2
		UINT16 CH2_DELAY_F2 : 10;		/**<Channel 2 Delay Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT8 CH2_DELAYC2 : 4;			/**<Channel 2 Delay Coarse.*/
		UINT8 : 4;						/**<Zero bits.*/
		UINT16 CH2_WIDTH_F2 : 10;		/**<Channel 2 Width Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT16 CH2_WIDTH_C2 : 5;		/**<Channel 2 Width Coarse.*/
		UINT16 : 11;					/**<Zero bits.*/
		UINT16 CH2_IFINE2 : 10;			/**<Channel 2 Current Fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT8 CH2_ICOARSE2 : 3;			/**<Channel 2 Current Coarse.*/
		UINT8 : 5;						/**<Zero bits.*/
		// LVDS Input interface
		UINT8 NETTLI : 1;				/**<Not TTL input mode.*/
		UINT8 : 3;						/**<Zero bits.*/
		UINT8 CLKDIV : 2;				/**<Reference frequency divider.*/
		UINT8 : 2;						/**<Zero bits.*/
		// Pulse Generator
		UINT8 DIVH : 3;					/**<Frequency divider for PLL hi.*/
		UINT8 ENLP : 1;					/**<Enable Long Pulses.*/
		UINT8 DIVL : 3;					/**<Frequency divider for PLL low.*/
		UINT8 NEPLL : 1;				/**<Disable PLL.*/
		// Sync Output
		UINT16 SYNCDF : 10;				/**<Sync delay fine.*/
		UINT16 : 6;						/**<Zero bits.*/
		UINT8 SYNCDC : 4;				/**<Sync delay coarse.*/
		UINT8 ESYNC : 1;				/**<Enable sync output.*/
		UINT8 ETTLO : 1;				/**<Enable TTL output mode.*/
		UINT8 : 2;						/**<Zero bits.*/
		// ADC/DAC
		UINT8 SELAD : 3;				/**<Select ADC/DAC source.*/
		UINT8 ENADC : 1;				/**<Enable AD/DA converter.*/
		UINT8 : 2;						/**<Zero bits.*/
		UINT8 ILIM_LSB : 2;				/**<Current limit LSB.*/
		UINT8 ILIM_MSB : 8;				/**<Current limit MSB.*/
		// iCHAUS Internal Configuration
		UINT8 CPONH : 1;				/**<Reference for charge pump block P.*/
		UINT8 CPONL : 1;				/**<Reference for charge pump block P.*/
		UINT8 : 2;						/**<Zero bits.*/
		UINT8 SDAREF : 2;				/**<Choose DA ref block I (hi or lo).*/
		UINT8 : 2;						/**<Zero bits.*/
		UINT8 SYNCTR : 3;				/**<Sync trim in block S.*/
		UINT8 : 1;						/**<Zero bit.*/
		UINT8 ETIMON : 1;				/**<Enable test current monitor block S.*/
		UINT8 : 3;						/**<Zero bits.*/
		UINT8 CITR : 3;					/**<Trim output current in LDK (block O).*/
		UINT8 : 1;						/**<Zero bit.*/
		UINT8 NCIEX : 1;				/**<Not CI voltage external (block O).*/
		UINT8 NCIDIS : 1;				/**<Not CI disable, emergency shutdown (block O).*/
		UINT8 : 1;						/**<Zero bit.*/
		UINT8 LBYP : 1;					/**<Bypass error check at startup.*/
		// iCHAUS Internal Test
		UINT8 TSEL : 4;					/**<Test block selection 3bit.*/
		UINT8 TM : 2;					/**<Testmode.*/
		UINT8 : 1;						/**<Zero bit.*/
		UINT8 ENTAP : 1;				/**<Enable Test Access Port.*/
		// CRC Checksum
		UINT8 CRC_CFG;					/**<CRC Checksum.*/
	};

	/**Laser Driver registers union containing registers of all LD chip (4 LD chips, 8 laser drivers in total). It is 32 x 4 bytes long.	*/
	typedef union {
		struct _LD_reg LD_reg[N_LD];				/**<Array of Laser Driver registers*/
		UINT8 bytes[sizeof(struct _LD_reg)*N_LD];   /**<Array of 32 x 4 bytes*/
	} LDs_registers;

	/**Struct containing the most common laser parameters*/
	typedef struct
	{
		// laser param
		UINT16 DELAY_F[8];		/**<Laser Delay Fine array. Valid range 0..1023.*/	
		UINT8 DELAY_C[8];		/**<Laser Delay Coarse array. Valid range 0..15.*/
		UINT16 WIDTH_F[8];		/**<Laser Width Fine array. Valid range 0..1023.*/
		UINT8 WIDTH_C[8];		/**<Laser Width Coarse array. Valid range 0..31.*/
		UINT16 I_FINE[8];		/**<Current Fine array. Valid range 0..1023.*/
		UINT8 I_COARSE[8];		/**<Current Coarse array. Valid range 0..7.*/
		UINT8 CITR[4];			/**<Current boost setting, one parameter for each driver. Driver 0 -> lasers 0 and 1, etc. Valid range 0..7.*/
		// Sync Output
		UINT16 SYNCD_F;			/**<Sync delay fine. Valid range 0..1023.*/
		UINT8 SYNCD_C;			/**<Sync delay coarse. Valid range 0..15.*/
	} LD_parameters;

	/**GSIPM register structure containing all registers for the GSIPM chip. Note that only few on them needs to be changed during normal use.
	They will be saved into the internal optode EEPROM and loaded on startup. If it is needed to change some of them, the user must load
	the actual values from the probe, save them into a local structure, modify the required fields, and program the structure back to the optode
	(optionally saving it in the EEPROM).	*/
	struct _GSIPM_reg {
		UINT8 VC2 : 2;						/**<VC2 voltage*/
		UINT8 VC1 : 2;						/**<VC1 voltage*/
		UINT8 VC1_ns : 2;					/**<VC1_ns voltage*/
		UINT8 GATE_GEN_FORCE_EN : 1;		/**<Force gate generation on all cycle*/
		UINT8 GATE_GEN_MONO_BYPASS : 1;		/**<Bypass gate generator monostable*/
		UINT8 EN_QUADRANT_1 : 1;			/**<Enable Quadrant 1*/
		UINT8 EN_QUADRANT_2 : 1;			/**<Enable Quadrant 2*/
		UINT8 EN_QUADRANT_3 : 1;			/**<Enable Quadrant 3*/
		UINT8 EN_QUADRANT_4 : 1;			/**<Enable Quadrant 4*/
		UINT8 TDC_DITHER_CODE : 3;			/**<TDC dithering code*/
		UINT8 TDC_DITHER_DISABLE : 1;		/**<Disable TDC dithering*/
		UINT8 STOP;							/**<TDC stop position. Valid range 0..23.*/
		UINT8 GATE_CLOSE;					/**<Gate closing position. Valid range 0..23.*/
		UINT8 GATE_OPEN;					/**<Gate opening position. Valid range 0..23.*/
	};

	/**GSIPM registers union containing all registers for the GSIPM chip. It is 5 bytes long.	*/
	typedef union {
		struct _GSIPM_reg GSIPM_ref;				/**<GSIPM registers*/
		UINT8 bytes[sizeof(struct _GSIPM_reg)];		/**<5 bytes*/
	} GSIPM_config_reg;

	/**Struct containing the most common GSIPM parameters*/
	typedef struct {
		BOOLEAN EN_QUADRANT_1;			/**<Enable Quadrant 1*/
		BOOLEAN EN_QUADRANT_2;			/**<Enable Quadrant 2*/
		BOOLEAN EN_QUADRANT_3;			/**<Enable Quadrant 3*/
		BOOLEAN EN_QUADRANT_4;			/**<Enable Quadrant 4*/
		UINT8 STOP;						/**<TDC stop position in ns. Valid range: 0..23*/
		UINT8 GATE_CLOSE;				/**<Gate closing position in ns. Valid range: 0..23*/
		UINT8 GATE_OPEN;				/**<Gate opening position in ns. Valid range: 0..23*/
	} GSIPM_parameters;

	/**Struct containing control PCb parameters*/
	typedef struct
	{
		UINT16 LD_Voltage;				/**<Laser driver supply voltage presets. Valid range 0..3. Default value: 0*/
		UINT16 SPAD_Voltage;			/**<SPAD supply voltage in mV. Valid range 25000..29500*/
		UINT16 GSIPM3v3_Voltage;		/**<GSIPM 3.3V supply voltage presets. Valid range 0..3. Default value: 0*/
	} Control_params;

	/**Struct containing autocalibration parameters*/
	typedef struct
	{
		UINT32 goal;					/**<Intensity goal for the calibration procedure. Valid range 1..16000000*/
		UINT16 meas_time;				/**<Measurement time for each step of the calibration procedure with a 100us time bin. Valid range 1..32767*/
		UINT16 steps;					/**<Number of steps of the calibration procedure. Valid range 1..11.*/
		UINT16 start_pos;				/**<Starting position for the binary search. Valid range 1..1728*/
	} Autocal_params;

	/**Low level Sequence line structure containing one line of the measurement sequence. It is 6 bytes long.	*/
	struct _Sequence_Line_LL
	{
		UINT16 meas_time;				/**<Measurement time. If bit 16 is 0, bits 0-15 encode time with a 100us time bin, otherwise with a 10ms time bin.*/
		UINT16 attenuation : 12;		/**<Attenuation, i.e. number of disabled SPADs.*/
		UINT16 gate_dly_c : 4;			/**<Gate delay coarse*/
		UINT16 gate_dly_f : 10;			/**<Gate delay fine*/
		UINT16 laser_num : 6;			/**<Laser to fire*/
	};

	/**High level Sequence line structure containing one line of the measurement sequence.*/
	struct _Sequence_Line
	{
		float meas_time;					/**<Measurement time in seconds. Valid range is 100us..327s. Actual value is rounded with 100us precision up to 3s, then with 10ms precision up to 327s.*/
		UINT16 attenuation[N_OPTODE];		/**<Attenuation, i.e. number of disabled SPADs for each optode. Valid range: 0..1727.*/
		UINT8 gate_delay_coarse[N_OPTODE];	/**<Gate delay coarse for each optode. Valid range: 0..15.*/
		UINT16 gate_delay_fine[N_OPTODE];	/**<Gate delay fine for each optode. Valid range: 0..1023.*/
		UINT8 laser_num;					/**<Laser to fire. Valid range: 0..63.*/
	};

	/**Low level Sequence union containing all lines of the measurement sequence.	*/
	typedef union
	{
		struct _Sequence_Line_LL Lines[MAX_SEQUENCE];					/**<Array of Sequence Lines*/
		UINT8 bytes[sizeof(struct _Sequence_Line_LL)*MAX_SEQUENCE];		/**<6 x MAX_SEQUENCE bytes*/
	} Sequence_LL;

	/**High level array containing all lines of the measurement sequence.	*/
	typedef struct _Sequence_Line Sequence[MAX_SEQUENCE];

	/**Structure containing the status for a LD chip. It is 4 bytes long.	*/
	struct _LD_status {
		UINT16 ERR_VDD5 : 1;	/**<5V supply voltage error*/
		UINT16 ERR_VBG : 1;		/**<Bandgap reference error*/
		UINT16 ERR_STUP : 1;	/**<Error during startup procedure*/
		UINT16 ERR_ID : 1;		/**<Wrong ID (serial comm)*/
		UINT16 ERR_IDRED : 1;	/**<ID redundancy error (RAM)*/
		UINT16 ERR_OP : 1;		/**<Wrong opcode (serial comm)*/
		UINT16 ERR_ADR : 1;		/**<Wrong address (serial comm)*/
		UINT16 ERR_CRC : 1;		/**<CRC checksum error (RAM)*/
		UINT16 ERR_LCKL : 1;	/**<Error PLL low not locked*/
		UINT16 ERR_LCKH : 1;	/**<Error PLL high not locked*/
		UINT16 ERR_OVC : 1;		/**<Over current error*/
		UINT16 ERR_OVT : 1;		/**<Over temperature error*/
		UINT16 ERR_PULSE : 1;	/**<Pulse width error*/
		UINT16 ERR_CLKI : 1;	/**<Internal 10M clock error*/
		UINT16 ERR_FFBIH : 1;	/**<Internal PLL timing error hi*/
		UINT16 ERR_FFBIL : 1;	/**<Internal PLL timing error low*/
		UINT16 ERR_CI : 1;		/**<Output current error*/
		UINT16 ERR_CHANN : 1;	/**<No channel selected*/
	};

	/**Array of union with status of all Laser Driver chips. It is 4 x 4 bytes long.	*/
	typedef union {
		struct _LD_status status[N_LD];		/**<LD status structure*/
		UINT32 u32[N_LD];					/**<4 x 4 bytes*/
	} LDs_status;

	/**Structure containing the analog acquisitions for an optode.	*/
	typedef struct {
		INT16 gsipmSPADcurrent;		/**<GSIPM SPAD current in tens of uA*/
		INT16 gsipmCoreCurrent;		/**<GSIPM core current in hundreds of uA*/
		INT16 laserCurrent;			/**<Laser current in tens of uA*/
		UINT16 gsipmSPADvoltage;	/**<GSIPM SPAD voltage in mV*/
		UINT16 gsipmCoreVoltage;	/**<GSIPM core voltage in mV*/
		UINT16 laserVoltage;		/**<Laser voltage in mV*/
		INT16 picTemperature;		/**<PIC Temperature in 0.01 C*/
		UINT16 gsipmTemperature;	/**<GSIPM Temperature (in code for now)*/
		UINT16 bandgap;				/**<Bandgap readout (code)*/
	} Optode_analog_acq;

	/**Structure containing the analog acquisitions for the control board.	*/
	typedef struct {
		INT16 spadCurrent;		/**<SPAD current in tens of uA*/
		INT16 inputCurrent;		/**<Input current in hundreds of uA*/
		UINT16 spadVoltage;		/**<SPAD voltage in mV*/
		UINT16 inputVoltage;	/**<Input voltage in mV*/
		UINT16 p5Volt;			/**<5V supply voltage in mV*/
	} Control_analog_acq;

	/**Structure containing the analog acquisitions for a LD chip	*/
	struct _LD_Analog {
		UINT16 ILDK;		/**<Laser driver current at LDK*/
		UINT16 VCI;			/**<Voltage at the driver stage*/
		UINT16 V18;			/**<Generated 1.8V supply*/
		UINT16 VDD;			/**<Supply voltage*/
		UINT16 Temp;		/**<Chip Temperature*/
	};

	/**Array of structures containing the analog acquisitions for all the laser drivers of an optode.	*/
	typedef struct _LD_Analog LDs_analog[N_LD];

	/**Structure containing one acquisition frame.	*/
	typedef struct {
		UINT32 intensity_data;						/**<Total number of detection during an acquision frame*/
		UINT16 histogram_data[HISTOGRAM_BINS];		/**<Complete histogram of the acquisition frame*/
		UINT16 Area_ON;								/**<Number of enabled SPAD during the acquisition*/
		ADDRESS Optode;								/**<Optode to which the frame refers*/
		UINT16 Status;								/**<Status of the probe during acquisition*/
	} Frame;

	/**Bidimensional array containing the DCR of the detectors.*/
	typedef UINT32 DCRmap[N_OPTODE][N_PIXEL];

	/**Array containing a full measurement. Each member of the array is an acquisition frame, according to the programmed sequence.	Each line of the sequence corresponds to N frames, where N is the
	number of installed optodes (typically 8).*/
	typedef Frame Acquired_data[MAX_FRAMES];

	/**Array containing the activation list for calibration. The array entry is the address of the SPAD and the array index is the activation order.*/
	typedef UINT16 CalMap[N_PIXEL];

	/**Array of boolean showing which optode are actually installed and working in the probe.*/
	typedef BOOLEAN Opt_Present[N_OPTODE];

#pragma pack(pop)

	/**Handle to the SOLUS structure.*/
	typedef struct _SOLUS_H * SOLUS_H;

	/**Handle to the SOLUS data structure.*/
	typedef  Acquired_data * Data_H;

	/*@}*/
	//------------ Constructor -----------------------------------------
	/**
	* \defgroup ConDes Constructror, destructor, error handling
	Functions to construct and destruct SOLUS objects and for error handling
	*/
	/*@{*/

	/**SOLUS Constructor.
	Allocates a memory block to contain data for a SOLUS probe and opens the communication.
	\param SOLUS Pointer to SOLUS handle.
	\param OptList Pointer to the array in which the constructor will save which optode is present and working.
	\return OK The structure was successfully created and communication opened.
	\return INVALID_POINTER A not empty pointer was passed.
	\return OUT_OF_MEMORY Not enough memory to allocate the structure.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_Constr(SOLUS_H* SOLUS, Opt_Present* OptList);

	/**SOLUS Destructor.
	Deallocates the memory and closes the communication.
	\param SOLUS SOLUS handle
	\return OK The structure was successfully deallocated and communication closed.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_Destr(SOLUS_H SOLUS);

	/**Print an error message.
	All the SDK functions return an error code to inform the user whether the issued command was successfully executed or not. This function prints out the description of the error code on the standard output.
	\param FunName Additional text to define the warning/error. Usually the name of the calling function is provided.
	\param retcode Error code returned by a SDK command
	*/
	DllSDKExport void PrintErrorCode(const char* FunName, SOLUS_Return retcode);

	/*@}*/
	//------------ Set methods -----------------------------------------
	/**
	* \defgroup Set Set methods
	Functions to set parameters of the SOLUS probe.
	*/
	/*@{*/

	/**Set optode registers.
	Sets the registers for a specific optode. The function requires pointers to user space structures containing laser drivers and GSIPM registers. When changing optode parameters, a Read-Modify-Write sequence must be followed.
	This means that \ref SOLUS_ReadOptodeRegs() and \ref SOLUS_GetOptodeRegs() must be called before this function in order to receive in a user space variable the current settings. After that, the desired settings can be changed,
	and finally sent to the optode with this function.
	\param solus SOLUS handle
	\param optode Address of the optode
	\param LD_Registers Pointer to a structure containing laser driver registers.
	\param GSIPM_Registers Pointer to a structure containing GSIPM registers.
	\return OK Registers setting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return INVALID_POINTER An empty SOLUS handle or pointer to setting structures was passed.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetOptodeRegs(SOLUS_H solus, ADDRESS optode, LDs_registers* LD_Registers, GSIPM_config_reg* GSIPM_Registers);

	/**Set optode parameters.
	Sets the parameter for a specific optode. The function requires pointers to user space structures containing laser drivers and GSIPM parameters. When changing optode parameters, a Read-Modify-Write sequence must be followed.
	This means that \ref SOLUS_GetOptodeParams() must be called before this function in order to receive in a user space variable the current settings. After that, the desired settings can be changed,
	and finally sent to the optode with this function.
	\param solus SOLUS handle
	\param optode Address of the optode
	\param LD_Parameters Pointer to a structure containing laser driver parameters.
	\param GSIPM_parameters Pointer to a structure containing GSIPM parameters.
	\return OK Parameters setting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return INVALID_POINTER An empty SOLUS handle or pointer to setting structures was passed.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetOptodeParams(SOLUS_H solus, ADDRESS optode, LD_parameters LD_Parameters, GSIPM_parameters GSIPM_parameters);

	/**Set calibration map.
	Sets the calibration map for a specific optode. The calibration is an array of N_PIXEL UINT16 values, containing the desired pixel activation order to be used by the internal calibration procedure.
	\param solus SOLUS handle
	\param optode Address of the optode
	\param data Pointer to the array containing the calibration map.
	\param MaxArea Maximum number of pixel to be activated. Valid range: 1..1728
	\return OK Calibration map setting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return INVALID_POINTER An empty SOLUS handle or pointer to data was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetCalibrationMap(SOLUS_H solus, ADDRESS optode, CalMap* data, UINT16 MaxArea);

	/**Set autocalibration parameters.
	\param solus SOLUS handle
	\param Params Structure containing the parameters to be set
	\return OK Calibration map setting was successful.
	\return OUT_OF_RANGE An invalid parameter was passed to the function.
	\return INVALID_POINTER An empty SOLUS handle or pointer to data was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetAutocalParams(SOLUS_H solus, Autocal_params Params);

	/**Set measurement sequence, low level.
	Sets the measurement sequence for an optode at low level. If the effective sequence lenght is less than MAX_SEQUENCE, all fields of unused sequence entries must be set to 0.
	\param solus SOLUS handle
	\param sequence Pointer to a user space structure containing the measurement sequence. 
	\param optode Address of the optode
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetSequenceLL(SOLUS_H solus, Sequence_LL* sequence, ADDRESS optode);

	/**Set measurement sequence, high level.
	Sets the measurement sequence at high level. If the effective sequence lenght is less than MAX_SEQUENCE, all fields of unused sequence entries must be set to 0.
	\param solus SOLUS handle
	\param sequence Pointer to a user space structure containing the measurement sequence.
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetSequence(SOLUS_H solus, Sequence* sequence);

	/**Set measurement flags. See defines for flags meaning. Flags are set or reset according the mask word.
	\param solus SOLUS handle
	\param flags Flag word
	\param mask Mask word
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetFlags(SOLUS_H solus, UINT16 flags, UINT16 mask);

	/**Setlaser frequency.
	Sets the laser frequency.
	\param solus SOLUS handle
	\param Frequency New laser frequecny in Hz.
	\return OK Laser frequency setting was successful.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_SetLaserFrequency(SOLUS_H solus, UINT32 Frequency);

	/*@}*/
	//------------ Get methods -----------------------------------------
	/**
	* \defgroup Get Get methods
	Functions to get parameters from the SOLUS probe. Functions of the "Read" type are used to obtain the actual value for the probe and save it into the local
	probe structure. Functions of the "Get" type returns the locally stored value. This means that a sequence Read->Get must be followed to obtain the actual value for
	quantities still unknons or that can be changed by the probe itself, whereas a simple Get is enough (and recommended, to avoid useless communications), if the value
	can only be changed by the user.
	*/
	/*@{*/

	/**Read registers from Optode.
	Reads all config registers for an optode an save them into the SOLUS object.
	\param solus SOLUS handle
	\param optode Address of the optode
	\return OK Parameters reading was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadOptodeRegs(SOLUS_H solus, ADDRESS optode);

	/**Get registers for an Optode.
	Gets the locally cached registers for an Optode. Must be proceeded by \ref SOLUS_ReadOptodeRegs() if the actual and not cached values are desided (for instance to obtain the map loaded on startup from EEPROM,
	or when parameters have been changed by the optode itself during operation).
	\param solus SOLUS handle
	\param optode Address of the optode
	\param LD_Registers Pointer to a structure to contain laser driver registers.
	\param GSIPM_Registers Pointer to a structure to contain GSIPM registers.
	\return OK Registers getting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return INVALID_POINTER An empty SOLUS handle or pointer to setting structures was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetOptodeRegs(SOLUS_H solus, ADDRESS optode, LDs_registers* LD_Registers, GSIPM_config_reg* GSIPM_Registers);

	/**Get parameters for an Optode.
	Gets the currently applied parameters for an Optode.
	\param solus SOLUS handle
	\param optode Address of the optode
	\param LD_Parameters Pointer to a structure to contain laser driver parameters.
	\param GSIPM_parameters Pointer to a structure to contain GSIPM parameters.
	\return OK Parameters getting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return INVALID_POINTER An empty SOLUS handle or pointer to setting structures was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetOptodeParams(SOLUS_H solus, ADDRESS optode, LD_parameters* LD_Parameters, GSIPM_parameters* GSIPM_parameters);

	/**Read calibration map from Optode.
	Read the calibration map for an optode an save it into the SOLUS object.
	\param solus SOLUS handle
	\param optode Address of the optode
	\return OK Calibration map reading was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadCalibrationMap(SOLUS_H solus, ADDRESS optode);

	/**Set calibration map.
	Gets the locally stored calibration map for a specific optode. The calibration is an array of N_PIXEL UINT16 values, containing the desired pixel activation order to be used by the internal calibration procedure.
	Must be proceeded by \ref SOLUS_ReadCalibrationMap() if the actual and not cached values are desided (for instance to obtain the map loaded on startup from EEPROM).
	\param solus SOLUS handle
	\param optode Address of the optode
	\param data Pointer to the array containing the calibration map.
	\param MaxArea Pointer to the variable for MaxArea
	\return OK Calibration map getting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return INVALID_POINTER An empty SOLUS handle or pointer to data was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetCalibrationMap(SOLUS_H solus, ADDRESS optode, CalMap* data, UINT16* MaxArea);

	/**Get measurement Sequence, low level.
	Gets the locally stored measurement Sequence for the optode.
	\param solus SOLUS handle
	\param sequence Pointer to a user space structure for storing the measurement sequence.
	\param optode Address of the optode
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetSequenceLL(SOLUS_H solus, Sequence_LL* sequence, ADDRESS optode);

	/**Get measurement Sequence, high level.
	Gets the locally stored measurement Sequence.
	\param solus SOLUS handle
	\param sequence Pointer to a user space structure for storing the measurement sequence.
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetSequence(SOLUS_H solus, Sequence* sequence);

	/**Get measurement flags. See defines for flags meaning.
	\param solus SOLUS handle
	\param flags Flag word
	\return OK Measurement sequence setting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to sequence structure was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetFlags(SOLUS_H solus, UINT16* flags);

	/**Read the status for an Optode.
	Reads the status for an optode an save it into the SOLUS object.
	\param solus SOLUS handle
	\param optode Address of the optode
	\return OK Status reading was successful.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadStatusOptode(SOLUS_H solus, ADDRESS optode);

	/**Get the status for an Optode.
	Gets the locally stored status for an optode.
	\param solus SOLUS handle
	\param optode Address of the optode
	\param status Pointer to an UINT16 variable to hold the optode global status.
	\param LD_Status Pointer to the structure to hold the laser driver status.
	\return OK Status getting was successful.
	\return OUT_OF_RANGE An invalid optode Address was passed to the function.
	\return OPTODE_NOT_PRESENT Optode not present or not working.
	\return INVALID_POINTER An empty SOLUS handle or pointer to structures was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetStatusOptode(SOLUS_H solus, ADDRESS optode, UINT16* status, LDs_status* LD_Status);

	/**Read the status for control MCU.
	Reads the status for the control MCU an save it into the SOLUS object.
	\param solus SOLUS handle
	\return OK Status reading was successful.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadStatusControl(SOLUS_H solus);

	/**Get the status for control MCU.
	Gets the locally stored status for control MCU.
	\param solus SOLUS handle
	\param status Pointer to an UINT16 variable to hold the status.
	\return OK Status getting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to structures was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetStatusControl(SOLUS_H solus, UINT16* status);

	/**Read the actual laser frequency.
	Read actual value for laser frequency from probe MCU.
	\param solus SOLUS handle
	\return OK Laser frequency reading was successful.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadLaserFrequency(SOLUS_H solus);

	/**Get the laser frequency.
	Gets the locally stored value for laser frequency.
	\param solus SOLUS handle
	\param Frequency Pointer to an UINT32 variable to hold the frequency.
	\return OK Laser frequency getting was successful.
	\return INVALID_POINTER An empty SOLUS handle or pointer to structures was passed.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetLaserFrequency(SOLUS_H solus, UINT32* Frequency);

	/*@}*/
	//------------ Acquisition methods -----------------------------------------
	/**
	* \defgroup Acquire Acquisition methods
	Functions for acquiring data from the SOLUS probe.
	*/
	/*@{*/

	/**Start measurement sequence.
	Starts the measurement according to the programmed sequence and data type. Once the acquisition started data must be downloaded calling repeatedly the function
	\ref SOLUS_GetMeasurement().
	\param solus SOLUS handle
	\param type Specify the datatype of the measurement (only intensity or complete histogram and intensity)
	\return OK Measurement started successfully.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return INVALID_OP Acquisition already running.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_StartSequence(SOLUS_H solus, DataType type);

	/**Stop measurement sequence.
	Stops the running measurement. It must be called in any case before starting a new one. Optionally, status and analog acquisitions of the system can be acquired and stored in an external XML file.
	\param solus SOLUS handle
	\param enable_dump enable saving XML file
	\return OK Measurement stopped successfully.
	\return INVALID_POINTER An empty SOLUS handle was passed.
	\return INVALID_OP Acquisition not running.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_StopSequence(SOLUS_H solus, BOOLEAN enable_dump);

	/**Query Available Lines
	Gets the number of acquired sequence lines. Call this function before \ref SOLUS_GetMeasurement() to know if all the desired lines has been measured.
	\param solus SOLUS handle
	\param NLines Pointer to the number of acquired lines
	\return OK Number of acquired lines succesfully read.
	\return INVALID_POINTER An empty SOLUS of data handle was passed.
	\return INVALID_OP Acquisition not running.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_QueryNLinesAvailable(SOLUS_H solus, UINT16 *NLines);

	/**Get Measurement.
	Gets the desired number of sequence lines from a running measurement and provide to the user the address of the internal data structure. Each line of the sequence is composed by N frames, where N is the
	number of installed optodes (typically 8). Each frame rappresents an intensity or histogram measurement according to the programmed sequence. Data from the complete sequence may be acquired either with
	a single or multiple calls of this function, however the user must take care not to request in total more lines than the length of the currently programmed sequence. In order to avoid data corruption,
	it must be preceeded by \ref SOLUS_QueryNLinesAvailable(), unless the user is sure that the measurement time is elapsed.
	\param solus SOLUS handle
	\param data Pointer to the data structure handle
	\param NLines Number of sequence lines to be acquired. Accepted values: 1..384
	\return OK Frames acquired successfully.
	\return INVALID_POINTER An empty SOLUS of data handle was passed.
	\return OUT_OF_RANGE NLines out of range.
	\return INVALID_OP Acquisition not running.
	\return COMM_ERROR Communication error.
	\return COMM_TIMEOUT Communication timeout.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetMeasurement(SOLUS_H solus, Data_H* data, UINT16 NLines);

	/*@}*/
	//------------ Service methods -----------------------------------------
	/**
	* \defgroup Service Service methods
	Service functions for the SOLUS probe.
	*/
	/*@{*/

	/**Trigger calibration.
	\param solus SOLUS handle
	*/
	DllSDKExport SOLUS_Return SOLUS_TriggerCalibration(SOLUS_H solus);

	/**Save to EEPROM.
	\param solus SOLUS handle
	\param address Address of the optode/control
	*/
	DllSDKExport SOLUS_Return SOLUS_SaveEEPROM(SOLUS_H solus, ADDRESS address);

	/**Read from EEPROM.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param data Data read from EEPROM
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadEEPROM(SOLUS_H solus, ADDRESS address, UINT8* data);

	/**Read optode diagnothic.
	\param solus SOLUS handle
	\param Optode Address of the optode
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadDiagOptode(SOLUS_H solus, ADDRESS Optode);

	/**Get optode diagnostic.
	\param solus SOLUS handle
	\param Optode Address of the optode
	\param LD_Analog Analog readings from LDs
	\param Optode_Analog Analog readings from optode MCU
	*/
	DllSDKExport SOLUS_Return SOLUS_GetDiagOptode(SOLUS_H solus, ADDRESS Optode, LDs_analog* LD_Analog, Optode_analog_acq* Optode_Analog);

	/**Read control MCU diagnostic.
	\param solus SOLUS handle
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadDiagControl(SOLUS_H solus);

	/**Get control MCU diagnostic
	\param solus SOLUS handle
	\param Control_Analog Analog readings from control MCU
	*/
	DllSDKExport SOLUS_Return SOLUS_GetDiagControl(SOLUS_H solus, Control_analog_acq* Control_Analog);

	/**Reset MCU
	\param solus SOLUS handle
	\param address Address of the optode/control
	*/
	DllSDKExport SOLUS_Return SOLUS_ResetMCU(SOLUS_H solus, ADDRESS address);

	/**Trigger bootloader programming.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param path Path of the file (in bl2 format, generated by mplabx)
	*/
	DllSDKExport SOLUS_Return SOLUS_TriggerBootLoader(SOLUS_H solus, ADDRESS address, char* path);

	/**Get firmware version.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param FW_ver Version of the current firmware
	*/
	DllSDKExport SOLUS_Return SOLUS_GetFWVersion(SOLUS_H solus, ADDRESS address, UINT16* FW_ver);

	/**Read MCU ID.
	\param solus SOLUS handle
	\param address Address of the optode/control
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadMCU_ID(SOLUS_H solus, ADDRESS address);

	/**Get MCU ID.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param id Pointer to the ID of MCU at the selected address
	*/
	DllSDKExport SOLUS_Return SOLUS_GetMCU_ID(SOLUS_H solus, ADDRESS address, UINT16 *id);

	/**Turn ON power supplies.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param config Configuration word
	*/
	DllSDKExport SOLUS_Return SOLUS_PowerSupplyON(SOLUS_H solus, ADDRESS address, UINT16 config);

	/**Turn OFF power supplies.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param config Configuration word
	*/
	DllSDKExport SOLUS_Return SOLUS_PowerSupplyOFF(SOLUS_H solus, ADDRESS address, UINT16 config);

	/**Turn OFF all laser diodes.
	\param solus SOLUS handle
	*/
	DllSDKExport SOLUS_Return SOLUS_LaserOFF(SOLUS_H solus);

	/**Turn ON one laser diode.
	\param solus SOLUS handle
	\param address Address of the optode/control
	\param laser Number of the laser to be switched on
	*/
	DllSDKExport SOLUS_Return SOLUS_LaserON(SOLUS_H solus, ADDRESS address, UINT8 laser);

	/**Set control PCB parameters.
	\param solus SOLUS handle
	\param Params Structure containing the parameters to be set
	*/
	DllSDKExport SOLUS_Return SOLUS_SetControlParams(SOLUS_H solus, Control_params Params);

	/**Get control PCB parameters.
	\param solus SOLUS handle
	\param Params Pointer to the structure that will contain the parameters got from the probe.
	*/
	DllSDKExport SOLUS_Return SOLUS_GetControlParams(SOLUS_H solus, Control_params* Params);

	/**Compensate temperature.
	\param solus SOLUS handle
	\param temperature Calibration temperature.
	*/
	DllSDKExport SOLUS_Return SOLUS_CompensateTemperature(SOLUS_H solus, float temperature);

	/**Trim CTMU.
	\param solus SOLUS handle
	\param address Optode to be calibrated
	\param ctmu_en enable/disable the calibration state
	\param ctmu_trim value used to trim the CTMU (between -31 and 31 - 2% nominal steps)
	*/
	DllSDKExport SOLUS_Return SOLUS_TrimCTMU(SOLUS_H solus, ADDRESS address, BOOLEAN ctmu_en, INT16 ctmu_trim);

	/**Program STUSB4500.
	Program USB-PD sink controller with proper settings for The SOLUS Probe. 
	\param solus SOLUS handle
	*/
	DllSDKExport SOLUS_Return SOLUS_ProgramSTUSB4500(SOLUS_H solus);

	/**Read Analog Logs.
	Get last acquired analog acquisitions from control and optodes
	\param solus SOLUS handle
	*/
	DllSDKExport SOLUS_Return SOLUS_ReadAnalogLogs(SOLUS_H solus);

	/*@}*/

	/**@example SOLUS_Example.c*/

#ifdef __cplusplus
}
#endif

#endif //__SOLUS_SDK_h__
