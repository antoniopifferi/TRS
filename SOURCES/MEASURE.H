/* ########################   CONSTANTS   ################################# */

// CONDITIONAL COMPILE
//#define _NIRS	// Enable NIRS compilation, load also NIRS_DLL_v2.lib
//#define _LUCA	// Enable LUCA compilation, load also LUCA_TRS.lib

// INCLUDE
#include "SwabNet.h"	// needed for type definitions in SWAB Structure
#include "preSOLUS_BCD.h"  // needed for type definitions in BCD functions
#include "dmd/hidapi/hidapi.h" // needed for communicating with DMD_TX
#include "windows_temp.h"

// VERSION
#define MESSAGE_ABOUT   "Copyright: POLITECNICO DI MILANO\nVersion: 18.0\nDate: November 2020"

// TYPE OF DATA
// USE long for TimeHarp, Varro, Silena, USE short for all others SPC boards.
#define T_DATA unsigned long
#define T_HEAD struct sHeader2
#define T_SUB struct sSubHeader1

/* TOOLS */
#define SIGNUM(x)	 ((x>=0) ? 1:-1)
#define REMINDER(a,b)  	(a-b*(int)(a/b))
#define MAX(a,b)	(a>b?a:b)
#define MIN(a,b)	(a<b?a:b)
#define CEIL(a,b)	(REMINDER(a,b)==0?a/b:a/b+1)
														  
/* GENERAL CONSTANTS */
#define STRLEN 		  128
#define PATHLEN		  128
#define PACKLENGTH 	  6
#define SLI           sizeof(long)
#define SCH           sizeof(char)
#define ns2ps         1000
#define STRLEN_LONG	  1024


/* PROTOCOL CONSTANTS */
#define STRLEN_PROT	 		128
#define STRLEN_FIBER		64
#define MAX_ROW_PROT		16
#define COL_PROT_SOURCE		1
#define COL_PROT_FIBERS		2
#define COL_PROT_ACQSTART	3
#define COL_PROT_ACQSTOP	4
#define MAX_SUB		 		105
#define MAX_ROI_SUB			4
#define MAX_ROW_FIBER		16
#define MAX_FIBER			64
#define MAX_SOURCE		    16 //ALE
#define COL_FIBER_BOARD		1
#define COL_FIBER_DET		2
#define COL_FIBER_FIBERS	3
#define COL_SOURCE_SOURCE	1
#define COL_SOURCE_SWITCH	2
#define COL_SOURCE_CHANN	3
#define COL_MHARP_INPUT_OFFSET		2 // note: first is the label
#define COL_MHARP_INPUT_LEVEL		3
#define COL_MHARP_INPUT_EDGE		4
#define COL_MHARP_INPUT_DEADTIME	5
#define MAX_ROW_SOURCE		16
#define MAX_TWITCH		2
#define MAX_CHANN_SWITCH	2
#define GEOM_COORD_CART		1
#define LAYOUT_PARALL		0
#define LAYOUT_SERIAL		1

/* PRESENTATION CONSTANTS */
#define MAX_ROW_PRES_BLOCK			18
#define MAX_ROW_PRES_LOOP			MAX_LOOP 		
#define COL_BLOCK_DEF_BLOCK			1
#define COL_BLOCK_DEF_TYPE			2
#define COL_BLOCK_DEF_START_FRAME	3
#define COL_BLOCK_DEF_STOP_FRAME	4
#define COL_BLOCK_DEF_PARAM1		5
#define COL_BLOCK_DEF_PARAM2		6
#define COL_BLOCK_DEF_PARAM3		7
#define COL_BLOCK_SEQUENCE_BLOCK	1
#define COL_BLOCK_SEQUENCE_REPEAT	2
#define ROW_LOOP_PARTITION_LOOP3	1
#define ROW_LOOP_PARTITION_LOOP2	2
#define ROW_LOOP_PARTITION_LOOP1	3
#define END_TYPE_POINTER			3
#define END_LENGTH_POINTER			0
#define END_PARAM1_POINTER			']'
#define END_PARAM2_POINTER			']'
#define END_PARAM3_POINTER			']'
#define BASELINE_CONST				0
#define TASK_CONST					1
#define RECOVERY_CONST				2

/* TABLE CONSTANTS */  
#define MAX_TABLE		1375
#define STRLEN_TABLE	20
#define TCHAR			0
#define TINT			1
#define TDOUBLE			2
#define	TSTRING			3
#define CE				0
#define CT				1
#define MAX_TTABLE		13
#define STRLEN_TTABLE	20
#define MAX_PANEL		18

/* FILE CONSTANTS AND ENVIRONMENT SETTINGS */  
#define EXTASCII      ".TXT"
#define NUMZERO 	  4
#define FILESET		"SET\\TRS.TRS"
#define DIRPROG		""
#define DIRSETTINGS   "SET"
#define DIR_INI      "INI"
#define EXTSETTINGS   "*.TRS" 
#define EXTFILEPOS	  ".POS"
#define DIRFILEPOS	  "POS"
#define EXTFILETRIM	  ".TRM"
#define DIRFILETRIM	  "TRM"
#define EXTFILEBREAK  ".BRE"
#define DIRFILEBREAK  "BREAK"

/* LOOP CONSTANTS */
#define MAX_LOOP		5
#define LOOP_NONE	   -1
#define LOOP1			0
#define LOOP2			1
#define LOOP3			2
#define LOOP4			3
#define LOOP5			4
#define MAXBREAK		1000	 // Maximum number of lines in file break

/* TIME BASE CONSTANTS */
#define TIME_WIN		0
#define TIME_TIOMAMM	1

/* STEPPER CONSTANTS */
#define STEP_SIGN_POS	0
#define STEP_SIGN_NEG	1
#define WAIT_FALSE		0
#define WAIT_TRUE		1
#define NEWP_VEL_CORR	(1.000/1.005) // Empirical correction factor for nominal velocity
#define NEWP_FAST_RV	400		// Ramp Velocity (um/s) #400
#define NEWP_SLOW_RV	100		// Ramp Velocity (um/s) #100
#define NEWP_CONT_RV	5000	// Ramp Velocity (um/s) #5000
#define NEWP_FAST_XV	65000	// Max  Velocity (um/s) #65000
#define NEWP_SLOW_XV	1000	// Max  Velocity (um/s) #1000
#define NEWP_CONT_XV	100000	// Max  Velocity (um/s) #100000
#define NEWP_FAST_RW	1000	// Ramp Width (ms)      #1000
#define NEWP_SLOW_RW	500		// Ramp Width (ms)		#500
#define NEWP_CONT_RW	500		// Ramp Width (ms)	    #500
#define NEWP_FAST_SV	4000	// Set Velocity (um/s)  #40000
#define NEWP_SLOW_SV	200		// Set Velocity (um/s)  #200
#define STEP_EQUAL_POS	11		// Maximum number of unchanged pos
#define FACTOR_MONO	   1
#define FACTOR_TUNE    100
#define FACTOR_NEWP    1		// Loop Step (um)	#1000
#define FACTOR_TIO     2	   //Loop Step factor with TIO board
#define MAXITERNEWP	   10    // Maximum number of iterations in MoveNewp to reach Goal
#define MAX_STEP	   11

#define LPT1 		   888	 // PARALLEL PORT ADDRESS (PIN 11,17-25 -> GND)
#define STEP_LPT_ON_1  0x01	 // LSB 	-> PIN 2	(Axis1)	
#define STEP_LPT_ON_2  0x08  // LSB + 3	-> PIN 5	(Axis2)
#define STEP_LPT_CW_1  0x02  // LSB + 1	-> PIN 3	(Axis1)
#define STEP_LPT_CW_2  0x10	 // LSB + 4	-> PIN 6	(Axis2)
#define STEP_LPT_AWO_1 ~0x04 // LSB + 2	-> PIN 4	(Axis1)
#define STEP_LPT_AWO_2 ~0x20 // LSB + 5	-> PIN 7	(Axis2)

#define SLEEP_MONO 	   0.002	 // 0.025 Sleep Time for MONO (s)
#define SLEEP_TUNE 	   0.008	 // Sleep Time for TUNE	(s)
#define SLEEP_NEWP     5
#define STEPS_MONO	   1      // Number of Steps Moto for 1 nm  (nanometer)
#define STEPS_TUNE	   8       // Number of Steps Tune for 0.01 mm  (millimeter)	
#define STEPS_NEWP	   "000"   // Number of Steps Newp for 1 mm ("0" = *10 steps)	
#define MAXPOS	   	   10000	 // Maximum number of step or switch positions
#define EXP_STEP	   1.0
#define SLEEP_MIN_MVIS 0.005 //0.010
#define SLEEP_MAX_MVIS 0.020 //0.040
//**#define SLEEP_MIN_MNIR 0.002 //0.010
//**#define SLEEP_MAX_MNIR 0.008 //0.040
/**/#define SLEEP_MIN_MNIR 0.0025 //0.010
/**/#define SLEEP_MAX_MNIR 0.0025 //0.040
#define SLEEP_MIN_TUNE 0.002 //0.002
#define SLEEP_MAX_TUNE 0.002 //0.002
#define SPEED          30  // Newport velocity (mm/s)

// TIO SPECIFIC CONSTANTS
#define STEP_TIO_BOARD1			1		// First Tio Board
#define STEP_TIO_BOARD2			2		// Second Tio Board
#define STEP_TIO_PORT0			"0"		// First Port on Tio
#define STEP_TIO_PORT1			"1"		// Second Port on Tio
#define STEP_TIO_LINE_DIR		 0		// Digital Line Direction
#define STEP_TIO_LINE_ENABLE	 1		// Digital Line Enable
#define STEP_TIO_LINE_HALF		 2		// Digital Line HalfStep
#define STEP_TIO_COUNT_GATE		 1		// Counter Gate
#define STEP_TIO_COUNT_CLOCK	 2		// Counter Clock
#define STEP_TIO_COUNT_COUNT	 3		// Counter Counter
#define HIGH_LEVEL		 		 1		// Digital Level High
#define LOW_LEVEL		 		 0		// Digital Level Low
#define STEP_TIO_NUM_LINE	 	 2		// Number of Lines used for each Tio Stepper
#define STEP_TIO_NUM_COUNT		 3		// Number of Counters used for each Tio Stepper
#define STEP_TIO_MAX_LINE		 8		// Max lines per Tio Board

// MIO SPECIFIC CONSTANTS
#define STEP_MIO_MV_V			 1000   // Factor to change mV to V
//#define STEP_MIO_BOARD1			 3   // MIO device number  

// ADC SPECIFIC CONSTANTS
#define POWER_ADC_BOARD			 4   // ADC device number (same as MIO Board: PCI6024E) 
#define ADC_FACTOR				 1000000 // conversion factor from Volt to microVolt

// DELAYER_GATE SPECIFIC CONSTANTS
//#define FILEPATH_CALIB      'C:\\Documents and Settings\\Laboratorio\\Desktop\\Copia di Copy (2) of devTrs\\POS'			 // Folder of the calibration file
#define N_BIT_DELAYER_GATE       8       // Number of bits in imput to delayer
#define N_BIT_DELAYER_GATE_COMMAND    8
#define STEP_DELAYER_GATE        25
#define SLEEP_DELAYER_GATE       0.5
//#define DELAYER_GATE_COM         5

// DELAYER SPECIFIC CONSTANTS
#define DELAYER_BAUDRATE 	19200
#define DELAYER_PARITY 		0
#define DELAYER_DATABITS	8
#define DELAYER_STOPBITS	1
#define DELAYER_DELTA		25 		// stepsize of delayer in ps
#define DELAYER_JUMP		10		// number of steps to jump to avoid 'if(Actual=Goal) return' for the home
#define DELAYER_WAIT		3		// wait time (s) to let GatedModule stabilize after delay change


// MICRO SPECIFIC CONSTANTS
#define MICRO_LCD		'W'
#define MICRO_HOLD		'H'
#define MICRO_FMIN		'M'
#define MICRO_FDELTA	'A'
#define MICRO_HOME		'I'
#define MICRO_VEL		'V'
#define MICRO_GOTO		'G'
#define MICRO_TELL		'T'
#define MICRO_STOP		'F'
#define MICRO_END		'E'
#define MICRO_TERM		';'
#define MICRO_GETLENGTH	16
#define MICRO_HOLD_OFF	0
#define MICRO_HOLD_MEAS	1
#define MICRO_HOLD_ON	2
#define MICRO_LCD_OFF	0	
#define MICRO_LCD_ALL	1	
#define MICRO_LCD_END	2	
#define MICRO_BAUDRATE 	115200
#define MICRO2_BAUDRATE 2000000 // new micro
#define MICRO_PARITY 	0
#define MICRO_DATABITS	8
#define MICRO_STOPBITS	1

// ARDUINO SPECIFIC CONSTANTS
#define ARD_LCD		'W'
#define ARD_HOLD	'H'
#define ARD_FMIN	'M'
#define ARD_FDELTA	'A'
#define ARD_HOME	'I'
#define ARD_VEL		'V'
#define ARD_GOTO	'G'
#define ARD_TELL	'T'
#define ARD_STOP	'F'
#define ARD_END		'E'
#define ARD_TERM	';'
#define ARD_GETLENGTH	16
#define ARD_HOLD_OFF	0
#define ARD_HOLD_MEAS	1
#define ARD_HOLD_ON		2
#define ARD_LCD_OFF		0	
#define ARD_LCD_ALL		1	
#define ARD_LCD_END		2	
#define ARD_BAUDRATE 	115200
#define ARD_PARITY 		0
#define ARD_DATABITS	8
#define ARD_STOPBITS	1

// ESP300 SPECIFIC CONSTANTS
#define ESP300_TERM		13 // Terminator = Carriage Return
#define ESP300_BAUDRATE 19200
#define ESP300_PARITY 	0
#define ESP300_DATABITS	8
#define ESP300_STOPBITS	1
#define ESP300_VEL		"VA"
#define ESP300_MAXVEL	"VU"
#define ESP300_GOTO		"PA"
#define ESP300_WAIT		"WS"
#define ESP300_TELL		"TP"
#define ESP300_STOP		"ST"
#define ESP300_VER		"VE"
#define ESP300_STATUS	"TS"
#define ESP300_STAGE	"ID"
#define ESP300_QUITPROG	"QP" // Quit Program mode (just in case)
//#define ESP300_CHECKGROUP	"HB" // 
#define ESP300_TRAJTRAP	"TJ1" // Define Trapezoidal velocity profile (trajectory)
#define ESP300_TRAJS	"TJ2" // Define S-Shape velocity profile (trajectory)


// LT900 SPECIFIC CONSTANTS
#define LT900_TERM		13 // Terminator = Carriage Return
#define LT900_BAUDRATE  9600
#define LT900_PARITY 	0
#define LT900_DATABITS	8
#define LT900_STOPBITS	1
#define LT900_RESET		"*RST"
#define LT900_GO0		"SWITCH:0"
#define LT900_ANS_RESET		"0,OK"
#define LT900_ANS_GO0		"00,OK"


// CHAM SPECIFIC CONSTANTS
#define CHAM_TERM		13 // Terminator = Carriage Return
#define CHAM_BAUDRATE 19200
#define CHAM_PARITY 	0
#define CHAM_DATABITS	8
#define CHAM_STOPBITS	1
#define CHAM_VEL		"VA"
#define CHAM_GOTO		"PA"
#define CHAM_WAIT		"WS"
#define CHAM_TELL		"TP"
#define CHAM_STOP		"ST"


// PI SPECIFIC CONSTANTS

#define PI_HOME		"DH"
#define PI_VEL		"SV"
#define PI_GOTO		"MA"
#define PI_TELL		"TP"
#define PI_STOP		"AB"

#define PI_TERM		';'

#define PI_GETLENGTH	16
	
#define PI_BAUDRATE 	9600

#define PI_DEVICE	1
//#define PI_PARITY 	0
//#define PI_DATABITS	8
//#define PI_STOPBITS	1


// AOTF CONSTANTS
#define AOTF_FREQ_FACTOR 1000000 //1E9->HZ, 1E6->KHz, 1E3->MHz
#define AOTF_VOLT_FACTOR 1000   //1->Volt, 1000->mV


// NKT COMMUNICATIONS CONSTANTS

#define NKT_BAUDRATE	115200
#define NKT_PARITY		0
#define NKT_DATABITS	8
#define NKT_STOPBITS	1
#define NKT_SOT 		0x0D
#define NKT_EOT 		0x0A
#define NKT_SOE 		0x5E
#define NKT_ECC 		0x40
#define NKT_TXBUFFERSIZE 240
#define NKT_SOURCE		66
#define NKT_NONE		0
#define NKT_U8			1
#define NKT_U16			2
#define NKT_U32			3

#define NKT_DESTINATION 6
#define NKT_READ_REG	0x04
#define NKT_WRITE_REG	0x05
#define NKT_LAMBDA_REG	0x90
#define NKT_POW_REG		0xB0
#define NKT_LAMBDA_MIN	0x34
#define NKT_LAMBDA_MAX	0x35




// STANDA SPECIFIC CONSTANTS
#define STANDA_MaxTemp 70.0f
#define STANDA_AccelT 200.0f
#define STANDA_DecelT 200.0f
#define STANDA_BTimeout1 500.0f
#define STANDA_BTimeout2 500.0f
#define STANDA_BTimeout3 500.0f
#define STANDA_BTimeout4 500.0f
#define STANDA_BTO1P 100.0f
#define STANDA_BTO2P 200.0f
#define STANDA_BTO3P 300.0f
#define STANDA_BTO4P 600.0f
#define STANDA_MinP 500.0f
#define STANDA_BTimeoutR 500.0f
#define STANDA_LoftPeriod 500.0f
#define STANDA_RTDelta 200
#define STANDA_RTMinError 15
#define STANDA_EncMult 2.5f
#define STANDA_MaxLoft 32
#define STANDA_PTimeout 100.0f
#define STANDA_SynOUTP 1
#define STANDA_TICSxSTEP 8



// MONO SPECIFIC CONSTANTS
#define MONO_HOME		12  
#define MONO_VEL		13
#define MONO_GOTO		12
#define MONO_READPOS    29 
#define MONO_BAUDRATE 	9600
#define MONO_PARITY 	0
#define MONO_DATABITS	8
#define MONO_STOPBITS	1
#define MONO_MASKL		255
#define MONO_MASKH      65280
#define MONO_SEC_TO_MIN	60
#define MONO_NM_TO_AMG	10
#define	MONO_TIMEOUT	1
#define MONO_TIMEOUT_OFFSET	0.5 


// MONO_TCP SPECIFIC CONSTANTS
#define MONO_TCP_STRLEN		256
#define MONO_TCP_WAIT_TIME	1000
#define MONO_TCP_PORT		1   
#define	MONO_IP_ADDRESS_FILE		"M:\\Programs\\ControlloDigikrom\\DigikIp.txt" 
#define MONO_TCP_INIT_COMMAND		'i'
#define MONO_TCP_CLOSE_COMMAND		'c'
#define MONO_TCP_HOME_COMMAND		'h'
#define MONO_TCP_MOVE_COMMAND		'm'
#define MONO_TCP_VEL_COMMAND		'v'
#define MONO_TCP_TELL_COMMAND		't'
#define MONO_TCP_WAIT_COMMAND		'w'   



/* PWM SPECIFIC CONSTANTS */
/* pwm commands */
#define PWM_ABS_GOTO	'A'
#define PWM_REL_GOTO	'R'
#define PWM_STOP        'K'
#define PWM_SETHOME     'H'
#define PWM_SETSPEED    'S'
#define PWM_TELL		'G'
#define PWM_RESET		'H'
#define PWM_STRLEN		 7
/* pwm replies  */
#define PWM_READY       "R00000;"
#define PWM_ERROR       "E00000;"
#define PWM_CURPOS      "P+"
/* pwm COMport parameters */
#define PWM_BAUDRATE 	38400
#define PWM_PARITY		0
#define PWM_DATABITS	8
#define PWM_STOPBITS	1
/* pwm limits and resolution */
#define PWM_STEP_MAX		5000
#define PWM_STEP_MIN		0
#define PWM_FREQ_MAX		1000
#define PWM_FREQ_MIN		0

/* FPM SPECIFIC CONSTANTS */
/* Calibration factor --> power[uW] = FPM_value / FPM_CALIB_FACT   */
#define FPM_CALIB_FACT 2.2665
/* fpm COMport parameters */
#define FPM_BAUDRATE 	9600
#define FPM_PARITY	0
#define FPM_DATABITS	8
#define FPM_STOPBITS	1
#define FPM_STRLEN	10
/* fpm commands... */
#define FPM_STOPMEAS	"GN"
#define FPM_GETSINGLE	"GS0"
#define FPM_GETCONT	"GC0"
#define FPM_SETSAMPFREQ	"SF"
/* fpm replies... */
#define FPM_OK		"OK"
#define FPM_ERROR	"ER"
#define FPM_EINVALCOM	1	/* Invalid command */
#define FPM_ELENEXC	2	/* String too long */
#define FPM_EINVALFREQ	3	/* Invlaid frequency */


// SWITCH CONSTANTS
#define MAX_SWITCH	 10
#define FIBER_OFF    0
#define FIBER_1      1
#define FIBER_2      2
#define FIBER_3      3
#define FIBER_4      4
#define FIBER_5      5
#define FIBER_6      6
#define FIBER_7      7
#define FIBER_8      8
#define FIBER_9      9
#define FIBER_II     0
#define FIBER_X      1

#define SWITCH_LEONI_BAUDRATE	57600	
#define SWITCH_LEONI_PARITY		0		
#define SWITCH_LEONI_DATABITS	8
#define SWITCH_LEONI_STOPBITS	1

#define SWITCH_THORWHEEL_BAUDRATE	115200	


// SYNC CONSTANT
#define SYNC_INPUT   1
#define SYNC_OUTPUT  2
#define SYNC_ONE	 1
#define SYNC_TWO	 2
#define SYNC_CONT	 3
#define SYNC_LPT	 2
#define SYNC_USB	 3
//#define SYNC_USB_BAUD 110



/* IEEE488 CONSTANTS */
#define GPIBVARRO	   1	// Varro Address
#define GPIBNEWP       2    // Newport Address
#define IEEETIMEOUT    60      // Timeout for IEEE (s)
#define GPIB0          0
#define DELAYVARRO     1       // Delay before getting data from Varro

/* USER INTERFACE CONSTANTS */
#define PATH_UIR	".\\Sources\\TRS.UIR"
#define NEG			 -1
#define MEASURING	 0
#define PROCESSING   1
#define SETTING		 2
#define FAST		 0
#define SLOW	 	 1
#define CONT		 0
#define LIGTH		 1
#define EXACT		 2
#define ONLY_FIRST	 3
#define ONLY_SEC	 4
#define REF   		 0
#define SIG   		 1
#define OFF			 0
#define ON           1			 
#define SINGLE       0
#define OSCILL       1  
#define GENERAL      0
#define MAMMOT       1
#define OXYM 	     2
#define SPECTRA		 3
#define MEAS		 0
#define SYST		 1
#define REFL		 0
#define TRANSM		 1
#define STEP_SINGLE	 0
#define STEP_MULTI	 1
#define STEP_CONT	 2
#define SWITCH_SINGLE	 0
#define SWITCH_MULTI	 1
#define SWITCH_CONT  	 2
#define AXIS1 	     0
#define AXIS2 		 1 
#define AXIS3		 2
#define NONE		 0
#define SWITCH2X2	 1
#define SWITCH1X4	 2
#define SWITCH1X9	 3
#define SHUTTER 	 4
#define SWITCH_EOL2x2 5
#define SWITCH_LUCA  6
#define SWITCH_LEONI 7
#define SWITCH_THORWHEEL 8

#define LPT			 1
#define NEWP	 	 2
#define TIO			 3
#define MIO			 4
#define MM4005		 5
#define MICRO		 6
#define MONO		 7
#define MONO_TCP     8
#define PI1   		 9
#define FPM			10
#define PWM 		11
#define DELAYER		12
#define ADC	        13
#define AOTF_FREQ	14
#define AOTF_POW	15
#define DELAYER_GATE 16
#define STANDA		 17
#define NKT_LAMBDA	18
#define NKT_POW		19
#define ESP300		20
#define LT900		21
#define CHAMALEON	22
#define MICRO2		23
#define STEP_STANDA2	24
#define ATT_LUCA		25
#define BCD_SYNC	26
#define BCD_PIX		27
#define DMD_TX		28
#define ARD_FLOW	29
#define ARD_STEP	30

#define VARRO		 1
#define NI_6602	     5
#define COM          6
#define NIDAQmx      7
#define SILENA		 2
#define SPC300		 3
#define HYDRA	     4
#define SPC630       5
#define SPC130       6
#define TEST		 7
#define TH260		 8
#define DEMO		 9
#define SPC_SC1000		 10
#define SPC_SPADLAB		 11
#define SPC_NIRS		 12
#define SPC_LUCA		 13
#define SPC_SWAB		 14
#define SPC_BCD			 15
#define SPC_MHARP		 16

#define WAIT_DELAY	 0
#define WAIT_TIME	 1
#define WAIT_COUNT	 2
#define WAIT_POS     3
#define WAIT_SPC     4
#define WAIT_MARKER	 5
#define BYN		     1
#define ASC			 0
#define MEASURE 	 0
#define RETRIEVE 	 1
#define ORIGIN		 0
#define PEAK		 1
#define SPECTRUM	 1
#define NUMAXIS		 3
#define NUMGATES	 3
#define HEADLEN		 256
#define SHOWROW		 0
#define COL_TRIS_STEP	 1
#define COL_TRIS_SWITCH	 2
#define COL_TRIS_TRIM	 3
#define COL_ROI_PAGE	 1
#define COL_ROI_FIRST	 2
#define COL_ROI_LAST	 3
#define COL_ROI_AREA	 4
#define COL_ROI_MAX		 5
#define COL_ROI_PEAK	 6
#define COL_ROI_WIDTH	 7
#define COL_VALUE_ROI	 1
#define COL_VALUE_AREA	 2
#define COL_VALUE_WIDTH	 3
#define COL_OSCILL_FIRST 1
#define COL_OSCILL_LAST  2
#define COL_OSCILL_FRACT 3
#define CONT_NONE	0
#define CONT_STEP	1
#define CONT_RANGE	2
#define ROW_BANK_NUM	1
#define ROW_BANK_ACTUAL	2
#define ROW_BANK_TIMEB	3
#define ROW_BANK_TIMET	4
#define ROW_BANK_TIMEA	5


/* CONTEST CONSTANTS */
#define CONTEST_MEAS 0
#define CONTEST_OSC	 1
#define CONTEST_TRIM 2
#define APPL_GEN	0
#define APPL_MAMM	1
#define APPL_MOXY	2
#define APPL_SPECTRA 3

/* SPC CONSTANTS */ 
#define MAX_BOARD	4
//#define MAX_DET	64 /* per continuos flow è poco */
#define MAX_DET		256
#define MAX_PAGE	256*32
#define MAX_FRAME	1024
#define MAX_ACQ		1024
#define MAX_ROW_ROI	32
#define MAX_PLOT	16
#define SPC_SHORT	0
#define SPC_LONG	1
#define SPC_ALL		-1
#define SPC_BANK_DIM	128*1024
#define SPC_NUM_BANK	2
#define SPC130_TIMEOUT	2.5
#define SPC_TIMEDELAY	1 //60	//secondi

#define LABEL_CFD_LIMIT_LOW	  "cfd_limit_low"
#define LABEL_CFD_ZC_LEVEL      "cfd_zc_level"
#define LABEL_SYNC_ZC_LEVEL     "sync_zc_level"
#define LABEL_TAC_GAIN          "tac_gain"
#define LABEL_TAC_OFFSET        "tac_offset"
#define LABEL_TAC_LIMIT_LOW     "tac_limit_low"
#define LABEL_TAC_LIMIT_HIGH    "tac_limit_high"


#define INFINITY	 60000
#define MBADR	     0x280  // i/o port address on which the card is mapped 
#define MAX_CHANN_SILENA	     8192   //
#define GROUP_SILENA    0	    //
#define EXTAMPL_SILENA	1	//
#define REALTIME	 0	    //  
#define LIVETIME	 1	    // 
#define TIMESCALE    0	    // seconds ->0       0.01 seconds ->1
#define MAXTIME	     3000   //
#define MBC_TO_PC    0	    // from mca to pc->0   from pc to mca->1 
#define SILENA_TIMESTOP     3	    //
#define COUNTSTOP    4	    //
#define CALIB_VARRO  3.02   // TAC Lab.Elettronica 6/7/98
#define CALIB_SILENA  2.78
#define CALIB_SPC300 (97.7/(4*4*2))
#define CALIB_SPC630 (50/1.024)
#define CALIB_SPC130 (50/1.024)
#define SPC_MIN_TIME 0.1	// minimum acquisition time for count control (s)
#define SPC300_INI_FILE "SPC300.INI"
#define SPC630_INI_FILE "SPC630.INI"
#define SPC130_1_INI_FILE "SPC131.INI"
#define SPC130_2_INI_FILE "SPC132.INI"
#define SPC130_3_INI_FILE "SPC133.INI"
#define SPC130_4_INI_FILE "SPC134.INI"
#define THARP_INI_FILE "TIMEHARP.INI"
#define SPC_NORM_FALSE		0
#define SPC_NORM_TRUE		1
#define MAX_COUNTS			1000000000

/* HYDRA CONSTANTS */
#define HYDRA_BINNING 	0 //you can change this
#define HYDRA_SYNC_OFFSET	0 
#define HYDRA_INPUT_OFFSET	-8000 
#define HYDRA_OFFSET	0 
#define HYDRA_TACQ		1000 //Measurement time in millisec, you can change this
#define HYDRA_SYNC_DIVIDER	4 //Note: you must reduce SYNC rate to <12.5 MHz 
#define HYDRA_SYNC_CFDZEROCROSS	10 //you can change this
#define HYDRA_SYNC_CFDLEVEL		200 //you can change this
#define HYDRA_INPUT_CFDZEROCROSS		10 //you can change this
#define HYDRA_INPUT_CFDLEVEL			100 //you can change this
#define HYDRA_LENCODE			4 //  Note: HistLen=1024*(2^HYDRA_LENCODE)
#define HYDRA_DEV0		0 // Use just 1 Device, the software can control more than 1 device (i.e. many HydraHarp) (Board = Channel, not Device)
#define SEC_2_MILLISEC	1000 // conversion factor for second to millisecond

/* MHARP CONSTANTS */
#define MHARP_DEV0		0 // Use just 1 Device, the software can control more than 1 device (i.e. many HydraHarp) (Board = Channel, not Device)
#define T3HISTBINS 32768 //=2^15, dtime in T3 mode has 15 bits (w/o binning???)
#define MH_SLEEPFORSYNCRATE 300 // After Init allow 150 ms for valid  count rate readings
#define MH_FILEEXT		"mhbin" // file extension for MultiHarp Time Tags
#define MHARP_SLEEP_THREAD 0.001 // number of seconds to sleep if FIFO or Buffer not ready
#define	MHARP_MAX_DET	16 // Max number of det in input
#define	MHARP_MAX_BIN	16384 // Max number of bins
#define MHARP_BUFFER_MULT 4 // Expand the buffer
#define MHARP_SIZE_RING_M MHARP_BUFFER_MULT*TTREADMAX // Size of Ring Buffer for Acquisition
#define MHARP_SIZE_RING_A MHARP_BUFFER_MULT*MHARP_MAX_DET*MHARP_MAX_BIN // Size of Ring Buffer for Analysis


/* TH260 CONSTANTS */
#define TH260_BINNING 	0 //you can change this
#define TH260_SYNC_OFFSET	8600 
#define TH260_INPUT_OFFSET	0 
#define TH260_OFFSET	0 
#define TH260_TACQ		1000 //Measurement time in millisec, you can change this
#define TH260_SYNC_DIVIDER	4 //Note: you must reduce SYNC rate to <12.5 MHz 
#define TH260_SYNC_CFDZEROCROSS	-10 //you can change this
#define TH260_SYNC_CFDLEVEL		-400 //you can change this
#define TH260_INPUT_CFDZEROCROSS		-10 //you can change this
#define TH260_INPUT_CFDLEVEL			-50 //you can change this
#define TH260_LENCODE			4 //  Note: HistLen=1024*(2^TH260_LENCODE)
#define TH260_DEV0		0 // Use just 1 Device, the software can control more than 1 device (i.e. many HydraHarp) (Board = Channel, not Device)
#define SEC_2_MILLISEC	1000 // conversion factor for second to millisecond
#define MILLISEC_2_SEC	1/1000 // conversion factor for millisecond to second

/* SC1000 CONSTANTS */
#define SC1000_TYPE unsigned long			// data type of hystogram SC1000 data (non-lin)
#define SC1000_TIME_INFINITY 1000000       // sec
#define SC1000_BINDEPTH BS32					// max size of the bin (BS32=unsigned int)
#define SC1000_LINEARISE  1					// 1 = use background file to linearise time scale, 0 = do not linearise
#define SC1000_HARDREFOLD  5					// hardware refolding using SC and Modulo
#define SC1000_NODATAOPERATION -1
#define SC1000_MAXBIN	40800		// max number of channels (bin) in SC1000 // 10 mhz
#define SC1000_REBIN 32
#define SC1000_MAX_COUNT_RATE 30000000
#define SC1000_MIN_COUNT_RATE 7000

/* SPADLAB CONSTANTS */
#define SPADLAB_TDC_WRITE  "\\\\localhost\\MyProcess\\tdc-write"
#define SPADLAB_TRS_WRITE  "\\\\localhost\\myprocess\\trs-write"
#define SPADLAB_DATAIN  1
#define SPADLAB_MAXTIME  5000 // max wait time to be sent in transmit the DataIn command

/* NIRS CONSTANTS */
#define NIRS_HISTLEN  8192	   // number of channels per lambda (fixed)
#define NIRS_DT	(10000.0/1024) // (ps) Time Bin
#define NIRS_REGLEN ((int32_t) 128)
#define NIRS_STATLEN ((uint32_t) 3)
#define NIRS_DETNUM	2
#define NIRS_LAMBDA1  1
#define NIRS_LAMBDA2  2
#define NIRS_LAMBDA12 3

/* LUCA CONSTANTS */
#define LUCA_HISTLEN  8192	   // number of channels per detector (fixed)
#define LUCA_DT	(10000.0/1024) // (ps) Time Bin
#define LUCA_REGLEN ((int32_t) 128)
#define LUCA_NUMDET	2
#define LUCA_STATLEN ((uint32_t) 3)
#define LUCA_DETNUM	2
#define LUCA_STOP	0
#define LUCA_AUTO	1
#define LUCA_MANUAL	2
#define LUCA_SHOT	3
#define LUCA_ATT_ABS	0
#define LUCA_ATT_INC	1
#define LUCA_ATT_DEC	2
#define LUCA_ATT_DB		3
#define LUCA_ATT_IDLE	0
#define LUCA_ATT_DONE	1
#define LUCA_ATT_RUNNING 2
#define LUCA_ATT_ERROR	3
#define LUCA_FILE_HANDLE "LucaHandle.log"

/* SWAB CONSTANTS */
#define SWAB_MAX_DET		18		// max number of detectors in SwabianBoard
#define SWAB_NONE			0		// no detector
#define SWAB_SIGN			1		// sign detector
#define SWAB_SYNC			2		// sync detector
#define SWAB_REPLAY_SPEED	1.0		// replay at SWAB_REPLAY_SPEED*real speed
#define SWAB_S2PS			1E12	// seconds to ps conversion
#define SWAB_FILEEXT		"ttbin" // file extension for Time Tags
#define SWAB_HIST			1		// corresponds to classical TPSF histogram
#define SWAB_CORR			2		// corresponds to correlation among 2 channels
#define SWAB_REAL			1		// Real Time Tagger
#define SWAB_VIRTUAL		2		// Virtual Time Tagger
#define COL_SWAB_DETTYPE	1		// Column in UIR SWAB Panel Table corressponding to DetType
#define COL_SWAB_LEVEL		2		// Column in UIR SWAB Panel Table corressponding to DetType
#define COL_SWAB_DELAY		3		// Column in UIR SWAB Panel Table corressponding to DetType

/* BCD CONSTANTS */
#define BCD_MAXBIN			256		// LEN of the TDC Array
#define BCD_MAXPIX			2048	// Maximum size of the Pixel Matrix
#define BCD_QUADRANTS		0b00001111
#define BCD_STEPCOARSE		1280	// (ps) Coarse Step of the Gate/delay
#define BCD_STEPFINE		100		// (ps) Fine Step of the Gate/delay


/* TEST CONSTANTS */
#define TEST_MUS	10.0
#define TEST_MUA	0.10
#define TEST_RHO	2.0
#define TEST_V		0.03/1.5
#define TEST_AREA	1000000
#define TEST_NOISE	0.1
#define TEST_CALIB	3.0


/* TRIMMER CONSTANTS */
#define MAX_TRIM			10
#define TARGET_AREA		0
#define TARGET_STDEV	1
#define TARGET_WIDTH	2
#define TARGET_AREAWIDTH 3
#define TARGET_MAX_BOARD_AREA 4
#define TRIM_DIR_NEG	-1
#define TRIM_DIR_POS	1
#define TRIM_SCAN_MIDDLE	0
#define TRIM_SCAN_UP		1
#define TRIM_SCAN_DOWN		2
#define TRIM_SCAN_RANGE		3
#define TRIM_WAIT_POS	 0
#define TRIM_WAIT_TIME	 1
#define TRIM_WAIT_SPC	 2
#define INIT_HIGHER		0
#define INIT_LOWER		1E20
#define FNAME_TRIM		"POS\\TRIM"
#define FEXT_TRIM		".POS"
#define SAVETRIM_TITLE_1	"DO YOU WANT TO SAVE CHANGES TO FILE "
#define SAVETRIM_MESSAGE_1	"You can SAVE CHANGES, SAVE & COPY previous version,\nSAVE CHANGES in a new file specified in the input box"
#define SAVETRIM_TITLE_2	"SET HOME TO ZERO"
#define SAVETRIM_MESSAGE_2	"Do you want to set HOME position to ZERO?"

/* ########################  MAMMOT CONSTANTS  ################################# */

#define	MAMM_VIS			0	
#define	MAMM_NIR			1	
#define	MAMM_NIR_IDX_MIN_BORDER	400	
#define	MAMM_NIR_IDX_MAX_BORDER	360	
#define MAMM_NIR_STEP_MAX   400
#define	MAMM_NUM_BOARD		2
#define MAMM_NUM_DET		8 //EDO
#define	MAMM_NUM_ROW		240
#define D2				(char) 2
#define X				(char) 0
#define Y				(char) 1
#define MAMM_DIR_POS	(char) 1
#define MAMM_DIR_NEG	(char) -1
#define MAMM_NONE			0
#define MAMM_ONLY_VIS		1
#define MAMM_ONLY_NIR		2
#define MAMM_VIS_AND_NIR	3
#define MAMM_VIS_OR_NIR		4
#define MAMM_NUM_LAMBDA		7
#define MAMM_NORTHWEST_DET	0
#define MAMM_WEST_DET		1
#define MAMM_SOUTHWEST_DET	2
#define MAMM_SOUTH_DET		3
#define MAMM_SOUTHEAST_DET	4
#define MAMM_EAST_DET		5
#define MAMM_NORTHEAST_DET	6
#define MAMM_NORTH_DET		7




/* OMA CONSTANTS  */
/***/
#define OMA_NONE					-1
#define OMA_IP_ADDRESS_FILE			"c:\\Programs\\ControlloOMA\\ipAddress.txt"    
										/* file contenente l'indirizzo IP del PC su cui ï¿½ lanciato il programma dell'OMA */
#define OMA_PORT					10000				   /* porta del programma dell'OMA */
#define OMA_ADDRESS_LENGHT			20					   /* lunghezza dell'array contenetne l'indirizzo IP */
#define OMA_BUFFER_LENGHT			256					   /* lunghezza buffer */
#define OMA_WAIT_TIME				1000				   /* tempo d'attesa prima di restituire errore durante una chiamta TCP */
#define OMA_NO_CONNECTION			-12					   /* codice d'errore */
#define OMA_READY_STRING_LENGHT		6					   /* lunghezza della stringa di "Ready?" */

/* OPHIR SPECIFIC CONSTANTS */
#define OPHIR_NONE		-1
#define OPHIR_BAUDRATE 	9600
#define OPHIR_PARITY	       0
#define OPHIR_DATABITS	   8
#define OPHIR_STOPBITS	   1
#define OPHIR_STRLEN	      10

/* LABEL CONSTANTS */
#define LABEL_MAX		16
#define LABEL_NAMELEN	12
#define LABEL_CONTENTLEN 22

/* DOSTEP CONSTANTS */
#define DOSTEP_MAX		3
#define DOSTEP_NONE		-1     

/* DISPLAY CONSTANTS */
#define MAX_PLOT		16
#define COLOR_FULL		256
#define COLOR_FRACT		0.5
#define WINDOW_MANUAL	0
#define WINDOW_REF		1
#define WINDOW_SIG		2
#define WINDOW_REFs_SIGs	3
#define WINDOW_REFSIG_	4
#define GRAPH_PLOT		0
#define GRAPH_ROI		1
#define GRAPH_LIN		0
#define GRAPH_LOG		1
#define MAX_ROW_OSCILL	2

/* MOXY CONSTANTS */
#define MOXY_NUM_SWITCH		2
#define MOXY_END_SWITCH		"N"
#define MOXY_END_COMMAND	"F"
#define MOXY_SET			"S"
#define MOXY_START			"M"
#define MOXY_ABORT			"A"
#define MOXY_GOTO			"P"
#define MOXY_END			'O'
#define MOXY_NO_SWITCH		"1"
#define MOXY_SWITCH			"0"
#define MOXY_COMPORT 		1
#define MOXY_BAUDRATE 		9600
#define MOXY_PARITY 		0
#define MOXY_DATABITS 		8
#define MOXY_STOPBITS 		1
#define MOXY_OVERHEAD 		0.02
#define SEC_TO_MICROSEC		1000000
#define MOXY_CHANN_REST		8
#define MOXY_SWITCH_DELAY	0.005

/* GENERAL CONSTANTS */
#define FALSE   	 0	   	 
#define TRUE    	 1
//#define TNONE		 0
//#define TCHAR		 1
//#define TSHORT		 2
//#define TDOUBLE      3
#define VER_UNO		 1
#define VER_DUE		 2
#define VER_GEN		 0
#define VER_MAMM	 1
#define VER_MAMM_HEADER 1

/* PROFILING CONSTANTS */
#define IS_PROFILING 0
#define PROF_MAX_STRLEN	20
#define PROF_MAX_ID		10000
#define PROF_FILE_NAME	"PROFILING.TXT"

/* ERROR HANDLER CONSTANTS */
#define ERR_SPC		0
#define ERR_MEM		1
#define ERR_HYDRA		2
#define ERR_TH260		3
#define ERR_SC1000	4
#define ERR_GENERIC	5
#define ERR_SWAB	6
#define ERR_BCD 	7
#define ERR_MHARP	8


/* GEOMETRY CONSTANTS */													//ALE
#define ASCII 48			  // USED FOR NAMING THE PAD					//ALE

#define MAX_PAD 16			  // MAX NUMBER OF PADS. EQUAL TO MAX_SOURCE	//ALE
#define MAX_PAD_ROW 9		  // MAX NUMBER OF ROWS IN THE PAD LAYOUT		//ALE
#define MAX_PAD_COL 9		  // MAX NUMBER OF COLS IN THE PAD LAYOUT		//ALE
#define STEP_ROW 40			  // USED FOR DRAWING THE PAD					//ALE
#define STEP_COL 40			  // USED FOR DRAWING THE PAD					//ALE
#define RECT_FACT_ROW 1.25    // USED FOR DRAWING THE PAD					//ALE
#define RECT_FACT_COL 0.75    // USED FOR DRAWING THE PAD					//ALE
#define TOP 40				  // USED FOR DRAWING THE PAD					//ALE
#define LEFT 10				  // USED FOR DRAWING THE PAD					//ALE
#define WIDTH 10			  // USED FOR DRAWING THE PAD					//ALE
#define PAD_WIDTH 400		  // USED FOR DRAWING THE PAD					//ALE
#define PAD_HEIGHT 475		  // USED FOR DRAWING THE PAD					//ALE
#define PAD_TOP 20			  // USED FOR DRAWING THE PAD					//ALE
#define PAD_LEFT 2			  // USED FOR DRAWING THE PAD					//ALE

#define SQUARE 1			  // LATTICE TYPE SQUARE						//ALE
#define RECTANGULAR 2   	  // LATTICE TYPE RECTANGULAR					//ALE
#define HESAGONAL 3			  // LATTICE TYPE HESAGONAL						//ALE
#define MAX_NEIGH 8			  // MAX NUMBER OF NEIGHBORS FOR EACH SOURCE	//ALE
#define NEAR_NEIGH 4		  // MAX ORDER OF NEIGHBORS						//ALE
#define DIST_TOLL 0.1		  // 0.1 cm										//ALE
#define MAXDIST 1E+9    	  // UNITS cm									//ALE
#define STEP_CTRL 0			  // LATTICE CTRL STEP							//ALE
#define DIAG_CTRL 1			  // LATTICE CTRL DIAG							//ALE

#define FIBER 1				  // CELL TYPE IS FIBER							//ALE
#define SOURCE 2			  // CELL TYPE IS SOURCE						//ALE
#define NOT_USED 0			  // CELL TYPE IS NOT_USED						//ALE
#define NOT_AVAILABLE -1 	  // CELL TYPE IS USED BY ANOTHER PAD			//ALE

#define GEO_FDIR "GEO\\"      // DIRECTORY FOR GEOMETRY FILES				//ALE
#define GEO_FNAME "GEOMETRY"  // DEFAULT FILENAME FOR GEOMETRY INFO			//ALE
#define GEO_FEXT ".GEO"		  // DEFAULT EXTENSION FOR GEOMETRY FILE		//ALE


/* END GEOMETRY CONSTANTS */												//ALE

/* ########################   TYPE DEFINITION  ############################ */

// DMD_TX Structures

struct DmdTx_Node{
	unsigned char data;
	struct DmdTx_Node *next;
};
struct DmdTx_List{
	int *data;
	struct DmdTx_List *next;
};

/** This structure contains all the data about the patterns to be sent to the dmd */
struct DmdTx_Patterns{
	unsigned char (*defPatterns)[12]; // pattern settings (exposure time, bit-depth, triggers, pattern index...)
	unsigned char configureLut[6]; // configuration of Look up table (LUT)
	unsigned char (*setBmp)[6]; // image settings (index, size)
	unsigned char ***bmpLoad; // compressed BMP image to load
	int nB;
	int *packNum; // number of data packets (max 504 bytes) to be loaded
	int nEl;
	int **bitsPackNum; // size of each packet
	int *exposure;
	int numOfBatches;
};

/** This structure contains data of the patterns for the dmd */
struct Dmd{
	hid_device *handle; // pointer to the hid device
	struct DmdTx_Patterns *pattern; // structure containing the pattern for the DMD (see in dmd.h)
	int szPattern;
	int repeat;
	char ReconsPy;
};

/** This structure contains the parameters to set the measurements (type of pattern and duration) */
struct InfoDmd{
	int RasterOrHadamard; // selected mode for the measure
	int nBasis;
	int nMeas;
	int startPosition;
	int previousPos;
	int exp;
	int dark_time;
	int repeat;
	int compress;
	int sizeBatch;
	int zoom;
	int xC;
	int yC;
	int csMode;
	int startPx;
	int endPx;
};

struct FileS {
	char Type;
	char Dir   [PATHLEN];
	char Name  [PATHLEN];
	char Ext   [PATHLEN];
	char Prefix[PATHLEN];
	char Path  [PATHLEN];
	int Tag;
	char Save;
	FILE *File;
	};
	
struct NumS {
	long Page;
	long Board;
	long Prot;
	long Det;
	long Fiber;
	long Source; //ALE
	long LoopxFrame;
	};

struct FiberS {
	char Board;
	char Fiber;
	char Det;
	char Coord;
	char Pad;
	double Xf;
	double Yf;
	double Zf;
	double Rf;
	double Nf;											//ALE
	int row;										    //ALE
	int col;										    //ALE
	};

struct SourceS {
	char Coord;
	char Pad;
	char Switch;
	char Chann;
	double Xs;
	double Ys;
	double Zs;
	double Rs;
	double Ns;											//ALE
	int Neigh[NEAR_NEIGH][MAX_NEIGH];					//ALE
	int row;										    //ALE
	int col;										    //ALE
	};

struct TwitchS {
	char Chann[MAX_ACQ][MOXY_NUM_SWITCH];
	int NoSwitch;
	};

struct TFiberS {
	char Board[MAX_ROW_FIBER];
	char Fibers[MAX_ROW_FIBER][STRLEN_FIBER];
	char Det[MAX_ROW_FIBER];
	};

struct TSourceS {
	char Source[MAX_ROW_SOURCE];
	char Switch[MAX_ROW_SOURCE];
	char Chann[MAX_ROW_SOURCE];
	};

struct ChannS {
	long First;
	long Last;
	long Num;
	double Fract;
	};

struct GpibS {
	int hGpib;
	char sGpib[3];
	};

struct MeasS {
	unsigned long Plot;
	unsigned long Roi;
	unsigned long Status;
	unsigned long Ram;
	char Clear;
	char Stop;
	char Autorun;
	char SkipOscill;
	};

struct WaitS {
	char Type;
	long Pos;
	char Step;
	};

struct JumpS {
	char Jump;
	char Loop;
	char Board;
	int Break;
	unsigned long Max;
	unsigned long Area;
	};

struct RamS {
	unsigned long Loop;
	unsigned long LoopU;
	unsigned long Actual;
	unsigned long Num;
	};

struct MammIdxS {
	int Home;
	int Top[MAMM_NUM_BOARD];
	int Border[MAMM_NUM_BOARD];
	int Actual;
	int First;
	int Last;
	int Num;
	};

struct MammRateS {
	double High[MAMM_NUM_BOARD];
	double Mid[MAMM_NUM_BOARD];
	double Low[MAMM_NUM_BOARD];
	double Actual[MAMM_NUM_BOARD];
	};

struct MammAttS{
	char Step;
	char Wait;
//	int Idx[MAMM_NUM_ROW];
	int IdxMin;
	int IdxMin2;
	int IdxMax;
	int IdxMax2;
	int IdxGoal;
	double FreqOpen;
	};

struct MammRefMeaS{	   //EDO
	double Width;
	double BaricentrePos;
	long MaxPos;
	long MaxVal;
	long Area;
	long First;
	long Last;
	double Treshold;
};
struct ScReinitS{  //EDO
	int Measure;
	int TrimmerPreBreak;
	int TrimmerPostBreak;
	int Oscilloscope;
	int InitMammot;
	int AnyOper;
};
struct NumAcqS{		  //EDO
	int Actual;
	float Tot;
	char Active;
};
struct ExtraFrameS{
	int Num;
	int IsActiveOnLoopYNum;
};
struct MammS {
	char Mamm;
	char AutoLabel;
	char FindTop;		
	int IterBord;
	int IdxBorderNIR;
	double BackTopNIR;
	double Lambda[MAMM_NUM_LAMBDA];
	char Step[D2];
	char Loop[D2];
	char Shrink[D2];
	struct MammIdxS Idx[D2];
	struct MammRateS Count;
	struct MammRateS Rate;
	struct MammAttS Att[MAMM_NUM_BOARD];
	char OverTreshold;   //EDO
	char IsTop;					//EDO
	int ShiftBack;				//EDO
	int TopLim;					//EDO
	int CorrShift;				//EDO
	char Roi;					//EDO
	double Fract;				//EDO
	char IgnoreTrash;			//EDO
	char Status;
	char   IniFile[MAMM_NUM_BOARD][260];		//EDO
	struct MammRefMeaS RefMeas;				    //EDO
	struct NumAcqS NumAcq;		  //EDO
	struct ExtraFrameS ExtraFrame;             //EDO
	int IsRefMeas;
	double NegativeTreshold;
	};

struct ActionS{
	char Status;
	char CheckJump;
	char DoJump;
	char MoveSwitch[MAX_SWITCH];
	char MoveStep[MAX_STEP];
	char WaitStep[MAX_STEP];
	char StartCont[MAX_STEP];
	char WaitCont[MAX_STEP];
	char Trim[MAX_TRIM];
	char Break[MAX_LOOP];
	char StartSync;
	char StopSync;
	char SpcReset;
	char SpcStop;
	char SpcOut;
	char WaitEnd;
	char WaitChrono;
	char DisplayStatus;
	char DisplayRoi;
	char DisplayPlot;
	char DataSave;
	//char NewFrame;
	char StartOma;
	char StopOma;
	char Ophir;
	char StopAdc;
	char StartAdc;
	char WaitAdc;
	char ReadUIR;
	char SpcFlow;
	char StartFlow;
	char StopFlow;
	char ReconsPy;
	char SpcTime;			//EDO
	char InitMamm;         //EDO
	char StartMamm;			 //EDO
	char CheckMamm;         //EDO
	char StopMamm;		    //EDO
	char DoJumpMamm;		//EDO
	struct ScReinitS ScReInit;			//EDO
	};

struct LoopS {
	int Control;
	long Home;
	long First;
	long Last;
	long Delta;
	long Num;
	long Idx;
	long Actual;
	char Break;
	char Invert;
	char Cont;
	char FName[STRLEN];
	char FPath[STRLEN];
	long ExceptNum;
	int ExceptValue[MAXBREAK];
	long ExceptLabel[MAXBREAK];
	};

struct TimeS {
	char Time;
	unsigned long Counter;	// Tasks
	char sCount[3];			// Strings Counters
	long Board;			// Tio Board Number
	double Start;
	double Stop;
	};

struct TioS {
	long lDir, lEnable, lHalf, lSwitch0, lSwitch1, lSwitch2, lSwitch3;				// Lines used
	unsigned long tGate, tClock, tCount;	// Tasks
	char sGate[3], sClock[3], sCount[3];	// Strings Counters
	char sPort[2];							// Port Number within same Board
	long Board;							// Tio Board Number
	};

struct NidaqS {
	long lDir, lEnable, lHalf, lSwitch0, lSwitch1, lSwitch2, lSwitch3;
	unsigned long tGate, tClock, tCount;
	char sGate[3], sClock[3], sCount[3];
	char sPort[2];
	long Board;
	};
	
struct MioS {
	char sChann[2];							// Channel within same Board
	long Board;							// NIDAQ Board Number
	};


struct StandaS {
	long Home;							// Home position in TICS (Steps=Tics x STANDA_TICSxSTEP)
	};


struct AdcS {
	unsigned long taskmodpower_diode;
	char sPath[STRLEN];							// Channel Path as defined in the daq  syntax
	char sChann[2];							// Channel within same Board
	long Board;							// NIDAQ Board Number
	long Chann;							// NIDAQ Channel Number
	unsigned long Task;							// NIDAQ Task ID
	double Data[100000];					// Buffered Data
	};

struct MonoTcpS {
	unsigned int Handle;  
	long ServerValue;
	int ServerReady;
	char IpAddress[MONO_TCP_STRLEN]; 
	};

struct Delay_GateS{
	char Str [N_BIT_DELAYER_GATE];
	float Value;
	char pChar[N_BIT_DELAYER_GATE_COMMAND];
	float Calib_Factor[N_BIT_DELAYER_GATE];
	float Calib_Calib[N_BIT_DELAYER_GATE];
    };
	
struct Standa2S {
	int Device;
	long DeltaHome;
	};

struct StepS {
	int Control;
	char  Com;
	char  Axis;
	char  Type;
	char  Step;
	char  Loop;
	char  Dir;
	char Sign;
	char Speed;
	char Mode;
	char Sort;
	char Moving;
	char Started;
	char DiffHome;
	char Lcd;
	char Hold;
	long Actual;
	long Actual_mean_pow;
	long Actual_std;
	long Delta;
	long Home;
	long Min;
	long Max;
	double Factor;
	struct TioS Tio;
	struct MioS Mio;
	struct StandaS Standa;
	double FreqMax;
	double FreqMin;
	double FreqActual;
	double FreqDelta;
	double Freq;
	long Start[MAXPOS];
	long Stop[MAXPOS];
	char  FName[STRLEN];
	char  FPath[STRLEN];
	struct Delay_GateS Delay_Gate;
	struct Standa2S Standa2;
	long StopGoal; // EDO
	HANDLE hSerial; 
	};

struct SwitchS {
	char  Switch;
	int Control;
	char  Device;
	char  Type;
	int Com;
	char  Line0;  
	char Port[2];
	int Board;
	char  Loop;
	char Mode;
	long Home;
	long Pos[MAXPOS];
	long Actual;
	char  FName[STRLEN];
	char  FPath[STRLEN];
	struct TioS Tio;
	struct MioS Mio;
	struct NidaqS Nidaq;
	};
	

struct SyncS {
	char  Sync;
	char  Type;
	char  Loop;
	char  Pattern;
	char  Dir;
	char   Com;
	double Width;
	int	   Baud;
	};
	

struct OmaS {
	int Oma;
	int Ready;
	int FileYes;
	int FileDirOk;
	int FileNameOk;
	char Loop;
	float Baric;
	float Peak;
	FILE *File;
	int DataStored;
	unsigned int g_hconv;
	};
	
struct OphirS {
	int Ophir;
	char Loop;
	FILE *File;
	};

struct PowerS {
	int Power;
	char Step;
	int Loop;
	struct AdcS Adc;
	};

struct TrimS {
//	struct ChannS Roi;
	struct ChannS Range;
	int Control;
	char Type;
	char Wait;
	char Scan;
	char Dir;
	char Region;
	char Step;
	char Trim;
	char Loop;
	char FileTrim;
	double Fract;
	char Target;
	double Goal;
	double Low;
	double High;
	double Best;
	double BestW;
	double BestA;
	double Value;
	char Sign;
	char Success;
	char Improved;
	char ImprovedW;
	char ImprovedA;
	char Stop;
	char Boundary;
	char Increase;
	double Time;
	double DeltaU;
	long Delta;
	int Num;
	int Trial;
	int Set;
	int SetW;
	int SetA;
	char Display;
	char Status;
	char Break;
	char Prompt;
	long PosBest;
	long PosAct;
	long PosW;
	long PosA;					 
	long Label[MAXPOS];
	double Pos[MAXPOS];
	int RegionFile[MAXPOS];
	char  FName[STRLEN];
	char  FPath[STRLEN];
	char RegionActual;
	};

struct SpadS{
	CNVWriter					WriterTRS;
	CNVBufferedSubscriber	SubscriberTDC;
	CNVData						DataTRS;
	CNVData						DataTDC;
	double						Time;
	unsigned int				*Buffer;
	};

struct NirsS{
	uint32_t Handle;
	uint32_t IntTime; // ms
	int		 UirTime; // ms
	int		 Freq;	  //MHz
	int		 Lambda; // 1 -> Laser1 always active, 2 -> Laser2 always active, 3 -> toggling Laser1/Laser2
	uint32_t *Hist;
	uint32_t RegOut[NIRS_REGLEN];
	int	InitializedBox;
	int InitializedLaser;
	};

struct LucaSpcS{
	uint64_t Handle;
	uint32_t IntTime; // ms
	uint32_t CtrTime; // ms
	int		 Freq;	  //MHz
	uint32_t Lambda; // 0 -> END, 1->635nm,2->670nm,3->730nm,4->830nm,5->852nm,6->915nm,7->980nm,8->1040nm
	uint32_t *Hist;
	uint32_t RegOut[LUCA_REGLEN];
	int	InitializedBox;
	int InitializedLaser;
	};

struct BcdS{
	uint64_t Handle;
	int IsInitialized;
	float Time;
	char Calibration[STRLEN_LONG];

	
	// general settings
	double VDD_CORE;
	double VDDD_CORE;
	double VDD_CK;
	double VHIGH;
	
	// Gate
	uint8_t RSTDuration;
	LVBoolean LOWPower;
	//char RSTDuration;
	//char LOWPower;
	long int Open0;	// Open of the HW gate (ps)
	long int Width0;	// Width of the HW gate (ps)
	long int Sync0; // Delay of the TDC Stop Sync (ps)
	//unsigned short Open0;	// Open of the HW gate (ps)
	//unsigned short Width0;	// Width of the HW gate (ps)
	//unsigned short Sync0; // Delay of the TDC Stop Sync (ps)
	
	// Pixels
	int PixelDefault;
	char PixelSingle;
	char PixelsOrder[STRLEN_LONG];
	LVBooleanArray *SETMap;
	int32_t NumPixels;
	int64_t Pixel_sequence[BCD_MAXPIX];
	};

struct SurfaceConceptS{
	int	 Refolding; //EDO
	int	 ScBoard[MAX_BOARD];	 //EDO
	int  ScBoardInitialized[MAX_BOARD];   //EDO
	int  ScInitializedForMammot[MAX_BOARD];   //EDO
	double ScTimeElapsed;//EDO
	float  ScAcqTime;		//EDO          
	int    ScAutoTrim; //EDO
	int ScPipeClose;			//EDO
	int SelRepNum;			//EDO
	int StartDivider;		//EDO
	int ScFirstBin;			//EDO
	int ScLastBin;			//EDO
	int ScDeinit;		   //EDO
	char ScWait;
	int	 Pipe[MAX_BOARD][MAX_DET];
	unsigned int ScNumBin; //EDO
	char DCR_files[MAX_BOARD][MAX_DET][STRLEN];
	double *LinArray;
	FILE *FID;
	SC1000_TYPE *NonLinArray;
	SC1000_TYPE *DCR_raw_count;
	double *DCR_raw_time;
	double *Buffer;
	double *Buffer2;
	SC1000_TYPE *IRF_raw_count;
	double *IRF_raw_time;
	int Modulo; // perform Refolding operation via SC hardware. It corresponds to the Modulo length, i.e. Period=Number of Bins to refold (NOT SURE, VERIFY)
	double ***NonLinDt;     // corrections coefficients
	double Binsize;								// temporal width of the mean bin
	double Period;									// period between two IRF peaks (used in rebinning)
	double Rebin;
};

struct SwabS{
	__int64 Binwidth; // channel (bin) width in ps (ps/ch)
	int DetSync; // code identifying Sync Detector (1-based from UIR)
	int DetSyncFreqMult; // code identifying Sync Detector after FreqMult (=DetSync if FreqMult=1)
	int DetSign[SWAB_MAX_DET]; // code identifying Sign Detectors (1-based from UIR) 
	int DetType[SWAB_MAX_DET]; // code identifying type of detector (SWAB_NONE, SWAB_SYNC, SWAB_SIGN)
	double Level[SWAB_MAX_DET]; // threshold (mV)
	int Hysteresis[SWAB_MAX_DET]; // Hysteresis (mV) - accepted values: 1mV, 20mV, 70mV
	int Delay[SWAB_MAX_DET]; // (ps) delay
	int Deadtime[SWAB_MAX_DET]; // (ps) delay
	Swab_TimeTag_TimeTagger Ttr; // handle to a Real Tagger object
	Swab_TimeTag_TimeTaggerVirtual Ttv; // handle to Virtual Tagger object
	Swab_TimeTag_FrequencyMultiplier Fm; // handle to Frequency Multiplier object
	Swab_TimeTag_TimeTaggerBase Ttb; // handle to Base Tagger object
	Swab_TimeTag_HistogramLogBins Corr[SWAB_MAX_DET]; // handle to Correlation object
	//Swab_TimeTag_Correlation Corr[SWAB_MAX_DET]; // handle to Correlation object
	Swab_TimeTag_Histogram Hist[SWAB_MAX_DET]; // handle to Correlation object
	Swab_TimeTag_FileWriter Fw; // handle to File Write object
	CDotNetHandle Except; // handle to Exception raised by the .NET function in the Swab library
	char* FNameVirt[STRLEN]; // file name for reading the TimeTags
	char* FPathVirt[STRLEN]; // complete file path for reading the TimeTags
	char* FPathOut[STRLEN]; // complete file path for writing the TimeTags 
	__int64 TimeSW; // duration in ps of acquisition
	int Meas; // type of measurement, as defined in #define
	int isFwRunning; 
	int SaveTags; // activate saving of TimeTags on File
	int Type;
	int FreqMult; // multiplication factor for refolding after frequency divider
	int FreqDiv; // divider factor for reducing Sync
	};


// Ring buffer structure
typedef struct RingBufferS {
    unsigned int *data;
    unsigned int front;
    unsigned int rear;
    unsigned int count;
    CRITICAL_SECTION mutex;
    CONDITION_VARIABLE notEmpty;
	int stop;
};

typedef struct RingBufferMA{
    struct RingBufferS* bufferM; // Measurement data buffer
    struct RingBufferS* bufferA; // Analyzed data buffer
};



struct MharpS{
	int Mode; // MHARP_MODE_HIST=standard histogramming, MHARP_MODE_T3=continuous flow using T3 (time-tags)  
	//int oflcorrection; // overflow correction. remember number of occured overflow in sync time
	int SyncRate; // sync rate needed to control Tacq (expressed in terms of sync counts)
	//int Sync0; // initial sync value (number of elapsed syncs)
	uint64_t SyncGoal; // sync counts that delimit the next Tacq (already corrected for overflow)
	//int PassedTacq; // number of acquisitions up to now since board was started
	int NextAcq; // reached Tacq
	int NumRecords; // number of records in FIFO
	int ActualRecord; // position of the actual record in the processed FifoBuffer
	int Binning; // binning of the acquisition bins (i.e. channels in old TRS)
	int SyncDivider; // to be used to reduce sync rate to max 75MHz, otherwise use 1
	int LenCode; // Power of 2 of the HystLen (=P.Chann.Num)
	int Offset; // shift of the histogram (ns) (maybe useful in few cases to discard part of the histogram)
	int SyncOffset; // offset of the sync (ps)
	int SyncLevel; // threshold for the sync (mV)
	int SyncEdge; // 0=falling, 1=rising
	int SyncDeadtime; // delay before a new sync is taken (ps)
	int InputOffset[MHARP_MAX_DET]; // offset of the signal (ps)
	int InputLevel[MHARP_MAX_DET]; // threshold for the signal (mV)
	int InputEdge[MHARP_MAX_DET]; // 0=falling, 1=rising
	int InputDeadtime[MHARP_MAX_DET]; // delay before a new input is taken (ps)	
	int SaveTags; // save file with time-tags. Format=Flow of TimeTags as retrieved with ReadFifo
	char PathTags[PATHLEN]; // pathlength of the TAGS file
	FILE *FileTags; // pointer to the TAGS FILE
	struct RingBufferS RingBufferM; // ring buffer for Measurement 
	struct RingBufferS RingBufferA; // ring buffer for Analysis 
	struct RingBufferMA RingBufferMA; // ring buffer for Analysis 
	HANDLE AcquireThread; // handle for Multithread functions
	HANDLE AnalyzeThread; // handle for Multithread functions
	};

struct SpcS {
	char   Type;
	char   Control;
	char   Trash;
	char   Started;
	char   SkipZero;
	char   Overflow;
	char   Subtract;
	char   Format;
	int	   Init;
	double TimeInit;
	double Zero;
	double EffTime[MAX_BOARD];
	double TimeO;
	double TimeM;
	int	   TimeHydra;
	int	   TimeMharp;
	int	   TimeTH260;
	int	   TH260HistLen;
	int	   TimeSC1000;
	long   Count;
	char   TdcDcrFileRoot[260];
	char   Scale;
	double Calib;
	double Factor;
	int    RoutingBits;
	double RepRate;
	int	   MaxPage[MAX_BOARD];
	char   Settings[MAX_BOARD][260];
	char   IniFile[MAX_BOARD][260];
	int	 Refolding; //EDO
	int	 ScBoard[MAX_BOARD];	 //EDO
	int  ScBoardInitialized[MAX_BOARD];   //EDO
	int  ScInitializedForMammot[MAX_BOARD];   //EDO
	double ScTimeElapsed;//EDO
	float  ScAcqTime;		//EDO          
	int    ScAutoTrim; //EDO
	int ScPipeClose;			//EDO
	int SelRepNum;			//EDO
	int StartDivider;		//EDO
	int ScFirstBin;			//EDO
	int ScLastBin;			//EDO
	int ScDeinit;		   //EDO
	char ScWait;			//EDO
	int	 Pipe[MAX_BOARD][MAX_DET];//EDO
	unsigned int ScNumBin; //EDO
	struct SurfaceConceptS SC;   //EDO
	struct SpadS Spad[MAX_BOARD];
	struct NirsS Nirs[MAX_BOARD];
	struct LucaSpcS Luca[MAX_BOARD];
	struct SwabS Swab[MAX_BOARD];
	struct BcdS Bcd[MAX_BOARD];
	struct MharpS Mharp[MAX_BOARD];
	};

struct AcqS{
	long Bank;
	long Frame;
	long Counter;
	long Actual;
	long Tot;
	};

struct PageS{
	char Source;
	char Fiber;
	char Board;
	long Acq;
	double TimeNom;
	double TimeEff;
	};

struct FrameS{
	long Num;
	long Actual;
	int Min;
	int Max;
	int First;		 //EDO
	int Half;		 //EDO
	int Dir;		 //EDO
	int Last;		 //EDO
	};

struct FilterS{
	long Actual;
	long Page[MAX_ACQ][MAX_BOARD][MAX_DET];
	};

struct RoiS{
	char Window;
	char RoiM[MAX_ROW_ROI];
	char RoiO[MAX_ROW_ROI];
	long First[MAX_ROW_ROI];
	long Last[MAX_ROW_ROI];
	double Fract[MAX_ROW_ROI];
	long Page[MAX_ROW_ROI];
	long Area[MAX_ROW_ROI];
	double Width[MAX_ROW_ROI];
	double Lambda[MAX_ROW_ROI];
	double Rho[MAX_ROW_ROI];
	};

struct PlotS{
	long NumO;
	long NumM;
	int Plot[MAX_PLOT];
	int PageU[MAX_PLOT];
	};
	
struct GraphS{
	char Type;
	char Scale;
	};

struct TProtS{
	long AcqStart[MAX_ROW_PROT];
	long AcqStop[MAX_ROW_PROT];
	char Fibers[MAX_ROW_PROT][STRLEN_PROT];
	long Source[MAX_ROW_PROT];
	};

struct TBlockS{
	int Num[MAX_ROW_PRES_BLOCK];
	int Type[MAX_ROW_PRES_BLOCK];
	int StartFrame[MAX_ROW_PRES_BLOCK];
	int StopFrame[MAX_ROW_PRES_BLOCK];
	char Param1[MAX_ROW_PRES_BLOCK][2];
	int Param2[MAX_ROW_PRES_BLOCK];
	int Param3[MAX_ROW_PRES_BLOCK];
	};
	
struct TSequenceS{
	int BlockUsed[MAX_ROW_PRES_BLOCK];
	int Repeat[MAX_ROW_PRES_BLOCK];
	int Shuffle;
	int FrameTot;
	};

struct TPartitionS{
	int LoopFactor[MAX_ROW_PRES_LOOP];
	int Align;
	};

struct BlockObjS{
	int Num;
	int Length;
	int ActualRepetition;
	int LengthPart[MAX_ROW_PRES_BLOCK];
	int TypePart[MAX_ROW_PRES_BLOCK];
	char Param1[MAX_ROW_PRES_BLOCK][2];
	int Param2[MAX_ROW_PRES_BLOCK];
	int Param3[MAX_ROW_PRES_BLOCK];
	};

struct ValueS{
	char Roi;
	};

struct OscillS {
	double Time;
	long First[MAX_ROW_OSCILL];
	long Last[MAX_ROW_OSCILL];
	long Num[MAX_ROW_OSCILL];
	double Fract[MAX_ROW_OSCILL];
	struct ChannS Zoom;
	};
	
struct CommandS{
	int Abort;
	int Continue;
	char ReadUIR;
	};

struct ContestS{
	char Run;
	char Function;
	};

struct ChronoS {
	char Chrono;
	double Now;
	double Delta;
	};

struct LabelS {
	char Name[LABEL_NAMELEN];
	char Content[LABEL_CONTENTLEN];
	int Auto;
	};

struct DoStepS {
	char Step;
	long Home;
	long Goal;
	char Oscill;
	char Break;
	char Return;
	};

struct ConstS {
	double Rho;
	double Thick;
	double N;
	};

/*  GEOMETRY TYPE DEFINITION */							//ALE
struct sFS {											//ALE
	double x;											//ALE
	double y;											//ALE
	double z;											//ALE
	double r;											//ALE
	char Label[STRLEN];									//ALE
	int Neigh[NEAR_NEIGH][MAX_NEIGH];					//ALE
	int Name;											//ALE
	int status;										    //ALE
	int row;										    //ALE
	int col;										    //ALE
	};													//ALE

struct sPad{											//ALE
	char hPad;											//ALE
	char Pad;											//ALE
	char Name[STRLEN];									//ALE
	char Label[STRLEN];									//ALE
	int LatticeType;									//ALE
	int LatticeCtrl;									//ALE
	double LatticeStepX;								//ALE
	double LatticeStepY;								//ALE
	double LatticeDiagonal;								//ALE
	struct sFS Cell[MAX_PAD_ROW][MAX_PAD_COL];			//ALE
	struct sFS Fiber[MAX_FIBER];						//ALE
	struct sFS Source[MAX_SOURCE];						//ALE
	int numfiber;										//ALE
	int numsource;										//ALE
	int NearNeigh[NEAR_NEIGH];							//ALE
	double Dist[NEAR_NEIGH];							//ALE
	double Rs;											//ALE
	double Rf;											//ALE
	double Nn;											//ALE
	};													//ALE



/* Note Per Lorenzo
campo SubHeader
campo size Header
campo size SubHeader
int->long
VER_MAMM_HEADER (qualenumero?)
togliere commenti su INIT_SPC (per me)
*/

#pragma pack(push,1)
T_HEAD{
	short Ver[2];
	long SubHeader;
	long SubHeadVer;
	long SizeHeader;
	long SizeSubHeader;
	long SizeData;
	long Kind;
	long Appl;
	long Oma;
	char Date[10+1];
	char Time[8+1];
	long LoopHome[MAX_LOOP-2];	  // for compatibility with FIT, use only LOOP3,LOOP4,LOOP5
	long LoopFirst[MAX_LOOP-2];
	long LoopLast[MAX_LOOP-2];
	long LoopDelta[MAX_LOOP-2];
	long LoopNum[MAX_LOOP-2];
	long McaChannNum;
	long PageNum;
	long FrameNum;
	long RamNum;
	double McaTime;
	double McaFactor;
	long MeasNorm;
	char LabelName[LABEL_MAX][LABEL_NAMELEN];
	char LabelContent[LABEL_MAX][LABEL_CONTENTLEN];
	double Constn;
	double ConstRho;
	double ConstThick;
	long MammHeader;
	long MammIdxFirst[D2];
	long MammIdxLast[D2];
	long MammIdxTop[D2];
	long MammRateMid[D2];
	long MammRateHigh[D2];
	};

T_SUB{
	char Geom;
	char Source;
	char Fiber;
	char Det;
	char Board;
	char Coord;
	char Pad;
	double Xf;
	double Yf;
	double Zf;
	double Rf;
	double Xs;
	double Ys;
	double Zs;
	double Rs;
	double Rho;
	double TimeNom;
	double TimeEff;
	double n;
	long Loop[MAX_LOOP-2];		  // for compatibility with FIT, use only LOOP3,LOOP4,LOOP5
	long Acq;
	long Page;
	char RoiNum;
	short RoiFirst[MAX_ROI_SUB];
	short RoiLast[MAX_ROI_SUB];
	double RoiLambda[MAX_ROI_SUB];
	double RoiPower[MAX_ROI_SUB];
	};
#pragma pack(pop)

struct InfoS {
	char Kind;
	char Appl;
	char Geom;
	char SubHeader;
	char Monitor;
	};

struct MoxyS {
	int Moxy;
	char Command[STRLEN];
	long TimeMic;
	float TimeSpc;
	int DisplayDivisor;
	int PresentationRise;
	int ExternalTrigger;
	};
	
struct LayoutS {
	int Layout;
	char Order;
	char FGeometry[STRLEN];
	};

struct PresentationS {
	int Flag;
	char FInitPresentationName[STRLEN];
	char FInitPresentationDir[STRLEN]; 
	char FStimuliName[STRLEN];
	char FStimuliDir[STRLEN];
	};

struct FlowS {
	char Flow;
	int Slot0;
	int NumSlot;
	int Page0;
	int EmptyBank;
	int FilledFrame;
	int Bank;
	int Spcm;
	int Mharp;
	volatile int StopMultiThread;
	int MultiThreadFunctionId;
	int NumRecords;
	CmtThreadLockHandle Lock;
	};

struct ParmS {
	struct OscillS Oscill;
	struct CommandS Command;
	struct ContestS Contest;
	struct FileS File;
	struct GpibS Gpib[3];
	struct SpcS Spc;
	struct ChannS Chann;
	struct AcqS Acq;
	struct PageS Page[MAX_PAGE];
	struct FrameS Frame;
	struct NumS Num;
	struct FilterS Filter;
	struct RoiS Roi;
	struct PlotS Plot;
	struct GraphS Graph;
	struct ValueS Value;
	struct TProtS TProt;
	struct TFiberS TFiber;
	struct TSourceS TSource;
	struct FiberS Fiber[MAX_FIBER];
	//struct SourceS Source[MAX_ROW_SOURCE];  //ALE
	struct SourceS Source[MAX_SOURCE]; 		  //ALE
	struct TwitchS Twitch;
	struct MeasS Meas;
	struct RamS Ram;
	struct ActionS Action;
	struct JumpS Jump;
	struct ChronoS Chrono;
	struct LoopS Loop[MAX_LOOP];
	struct StepS Step[MAX_STEP];
	struct SwitchS Switch[MAX_SWITCH];
	struct SyncS Sync;
	struct OmaS Oma;
	struct OphirS Ophir;
	struct PowerS Power;
	struct TrimS Trim[MAX_TRIM];
	struct MammS Mamm;
	struct LabelS Label[LABEL_MAX];
	struct DoStepS DoStep[DOSTEP_MAX];
	struct ConstS Const;
	struct TimeS Time;
	struct WaitS Wait;
	struct InfoS Info;
	struct MoxyS Moxy;
	struct LayoutS Layout;
	struct PresentationS Presentation;
	struct TBlockS TBlock;
	struct TSequenceS TSequence;
	struct TPartitionS TPartition;
	struct BlockObjS BlockObj[MAX_ROW_PRES_BLOCK];
	struct FlowS Flow;
	};

// Data Structures
struct DataS {
	T_HEAD Head;		// D.Head
	T_SUB **Sub;		// D.Sub[P.Frame.Num][P.Num.Page]
	T_DATA ***Data;		// D.Data[P.Frame.Num][P.Num.Page][P.Num.Chann] 
	T_DATA **Osc;		// D.Osc[P.Num.Board*P.Num.Det][P.Num.Chann] 
	T_DATA **Buffer;	// D.Buffer[P.Num.Board][P.Num.Det*P.Num.Chann] 
	T_DATA **Bank;		// D.Bank[P.Num.Board][SPC_BANK_DIM] or D.Bank[P.Num.Board][MAX FIFO MHARP] // not a problem: there is a calloc later
	T_DATA *Curve;		// D.Curve[P.Num.Chann] 
	T_DATA *Last;		// D.Last[P.Num.Chann]
	uint32_t **MharpBuffer;		// D.MharpBuffer[P.Num.Board][TTREADMAX*MHARP_BUFFER_MULT] 
	uint32_t *MharpBufferThread;	// D.MharpBufferThread[P.Num.Board][TTREADMAX*MHARP_BUFFER_MULT]
	SC1000_TYPE ***BufferTDC;
	};

struct TableS {
	int   Class[MAX_TABLE]; 
	int   Ctrl[MAX_TABLE]; 
	int   Type[MAX_TABLE]; 
	int   Row[MAX_TABLE];
	int   Col[MAX_TABLE];
	void* Addr[MAX_TABLE];
	int   Panel[MAX_TABLE];
	char  Dimmed[MAX_TABLE];
	char  Label[MAX_TABLE][STRLEN_TABLE];
	int   Num;   
	};
   
   

struct sPad Pad[MAX_PAD];								//ALE
/* END GEOMETRY TYPE DEFINITION */						//ALE
   
/* #####################   GLOBAL VARIABLES   ########################### */


/**/double tAnalMCrit, tAnalAProc, tAnalACrit, tAcqCrit, tAcqMeas;
/**/int TempLoop;
/**/double tRand;
/**/int MHAfter;

// DELETE THIS BELOW
/**/int NumPhotons;
/**/int NumCall;
/**/int NumValidCall;
/**/int FinalSync;

struct ParmS P;
struct DataS D;
struct TableS T;

struct MonoTcpS MonoTcp; 

unsigned long *DataRam, *DataRam0;//TODO: Suppress

int is_auto_on; //1 if MIO board channel 1 is on.

int hTrs;
int hParm;
int hLayout;
int hPresent;
int hMoxy;
int hTrim;
int hStep;
int hSwitch;
int hNirs;
int hLuca;
int hSwab;
int hBcd;
int hMharp;
int hMamm;
int hSave;
int hLabel;
int hDoStep;
int hDisplay;
int hPlot[MAX_PLOT];
int hMarkerF, hMarkerL;
int hPanel[MAX_PANEL];
int is_panel_mamm, is_panel_label;
int num_read;
//TaskHandle	taskmodpower=0;


/* GEOMETRY GLOBAL VARIABLES */								//ALE
int hGeom;													//ALE
int pa,lattice_type,clatticetype;							//ALE
//int ip,ir,ic,jr,jc,lattice_type;							//ALE
int cid[MAX_PAD][MAX_PAD_ROW][MAX_PAD_COL];					//ALE
int step_row,step_col;										//ALE
char padname[STRLEN],fname[STRLEN];							//ALE
int colctrl,valctrl,totfiber,totsource,totpad;				//ALE
int numfiber[MAX_PAD],numsource[MAX_PAD];					//ALE
int bs_pad[MAX_PAD],ring_pad[MAX_PAD],bs_pad_name[MAX_PAD]; //ALE
int sourcex,fiberx;											//ALE
int matrice[MAX_PAD_ROW][MAX_PAD_COL];						//ALE
char strtemp[STRLEN_PROT];									//ALE
/* END GEOMETRY GLOBAL VARIABLES */							//ALE

// PROFILING
//#ifdef IS_PROFILING
int ProfId;
char ProfS[PROF_MAX_ID][PROF_MAX_STRLEN];
double ProfT[PROF_MAX_ID];
char tempString[PROF_MAX_ID];
//#endif

/* SC1000 GLOBAL VARIABLES */ 
// move to std code when finished debugging
char DCR_files[MAX_BOARD][MAX_DET][STRLEN];
double *LinArray;
FILE *FID;
SC1000_TYPE *NonLinArray;
SC1000_TYPE *DCR_raw_count;
double *DCR_raw_time;
SC1000_TYPE *IRF_raw_count;
double *IRF_raw_time;
int Modulo; // perform Refolding operation via SC hardware. It corresponds to the Modulo length, i.e. Period=Number of Bins to refold (NOT SURE, VERIFY)
double ***NonLinDt;     // corrections coefficients
double Binsize;								// temporal width of the mean bin
double Period;									// period between two IRF peaks (used in rebinning)
double *BufferTDC;
double *BufferTDC2;

/* DMD_TX GLOBAL VARIABLES */
struct Dmd DmdTx;
struct InfoDmd DmdTxInfo;
struct DmdTx_Patterns DmdTxPatt;


/* #####################    MEASUREMENT FUNCTIONS   ########################### */
void InitVariable(void);
void CVICALLBACK Measure(int menuBar,int menuItem,void *callbackData,int panel);
void CVICALLBACK RunOscilloscope (int menuBar, int menuItem, void *callbackData,int panel);
void KernelGen(void);   
int CVICALLBACK RunDoStep(int panel,int control,int event,void *callbackData,int eventData1,int eventData2);
void DoStep(char Issue, int Homecontrol);
void Oscilloscope(void);
void SetLoopActual(void);
void DecideAction(void);
void CloseMeasure(void);
void InitMem(void);
void CloseMem(void);
void CompleteParmS(void); 
void MakePath(void);   
void CheckJump(void);

/* ########################   DISPLAY PROCEDURES   ########################### */
void InitFiber(void);
void InitGeom(void);
void InitSource(void);
void InitFilter(void);
void InitTwitch(void);
void CompileSub(long Ram, long Frame, long Page);
double CalcPower(long Frame, long Page, int Roi);
double CalcStdev(long Frame, long Page, int Roi);
double InsertMicroPos(long Frame, long Page, int Roi);
void CalcLoopIndex(long Steps,long *Loop1,long *Loop2,long *Loop3,long *Loop4,long *Loop5);

/* ########################   DISPLAY PROCEDURES   ########################### */
void TextDisplay(void);
void UpdateTag(void);
void InitDisplay(void);
void DisplayStatus(void);
void DisplayPlot(void);
void GraphRoi(void);
void GraphPlot(void);
void DisplayRoi(void);
long CalcArea(long First, long Last);
double CalcBaricentre(long First, long Last);
double CalcWidth(long First,long Last,double Treshold);
void GetRange(long RoiFirst,long RoiLast,double Fract,long *Max, long *Peak, long *pRangeFirst, long *pRangeLast,double *Treshold);
int CVICALLBACK GetMarker(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK GetPlot(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int CVICALLBACK GetCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);

/* ########################   WAIT FUNCTIONS   ######### */
void WaitEnd(double Time,long Pos,char Type,char Step);
void WaitCount(void);
void WaitChrono(void);

/* ########################   SPC FUNCTIONS   ######### */
void SpcInit(void);
void SpcClose(void);
void SpcPause(void);
void SpcClear(void);
void SpcIn();
void SpcRestart(void);  // TODO: check
void SpcReset(char Status, char Clear, char Stop);
void SpcTime(float Time); 
void SpcStop(char Status);
void SpcWait(void);
void SpcGet(void);
void SpcOut(char Status);
void DataSubtract(void);
void DataReverse(void);
void CalcTime(void);
void DataCopy(void);
void NewAcq(void);
void GetDataTest(void);
void InitTest(void);
void InitDemo(void);
void CloseDemo(void);
void GetDataDemo(void);

/* ########################   FLOW FUNCTIONS   ######### */
void SpcFlow(char Status);
void StartFlow(void);
void StopFlow(void);


/* ########################   SPC300 SPC FUNCTIONS   ####################### */
void InitSpc300(void);
void GetDataSpc300(void);
void InitSpcm(int Board);
void GetDataSpcm(void);
void CloseSpcm(void);
void ClearSpcm(void);

void test_sequencer_state(void);
void WaitFlowSpcm(void);
void CheckTriggerFlowSpcm(void);
void GetFlowSpcm(void);
void CopyFlowSpcm(void);
void StartFlowSpcm(void);
void StopFlowSpcm(void);
void InitFlowSpcm(void);


/* ########################   HYDRA HARP FUNCTIONS   ####################### */
void InitHydra(int Board);
void CloseHydra(void);
void GetDataHydra(void);
void ClearHydra(void);

/* ########################   MULTI HARP FUNCTIONS   ####################### */
void InitMharp(int Board);
void CloseMharp(void);
void StopMharp(int Board);
void GetDataMharp(void);
void ClearMharp(void);
void StartMharp(int Board);
void WaitMharp(int Board);
void StartFlowMharp(void);
void StopFlowMharp(void);
void CopyFlowMharp(void);
int InitFileMharpTags(void);
void MharpReadFifoSingle(unsigned int* Buffer, int* pNumRecords);
void MharpReadFifoMulti(unsigned int* Buffer, int* pNumRecords);
DWORD WINAPI AnalyzeDataMharp(LPVOID pBufferMA);
DWORD WINAPI AcquireDataMharp(LPVOID Buffer);


/* ########################   TH260 HARP FUNCTIONS   ####################### */
void InitTH260(int Board);
void CloseTH260(void);
void GetDataTH260(void);
void ClearTH260(void);


/* ########################   THARP SPC FUNCTIONS   ####################### */
void InitTimeharp(void);
void GetDataTimeharp(void);

/* ########################   SC1000 FUNCTIONS   ####################### */
void InitSC1000(int Board);
float StartSC1000(int Board,float AcqTime);
void CloseSC1000(void);
void GetDataSC1000(void);
void ClearSC1000(void);
void CompleteClosureSC1000(int Board);
void ReInitSC1000(char Operation);
void CalcNonlinSC1000(void);
void LinRefoldSC1000(int Refold,int Board,int Det,SC1000_TYPE *NonLinArray, double *LinArray, int NumChannLin);
void FlushSC1000(int Board);
int PipeRead(int Board,int Det,int Timeout);


/* ########################   SPADLAB FUNCTIONS   ####################### */
void InitSpad(int Board);
void CloseSpad(void);
void TimeSpad(int Board, double Time);
void GetDataSpad(void);
void ClearSpad(void);
void PauseSpad(int Board);
void StartSpad(int Board);
void StopSpad(int Board);
void WaitSpad(int Board);

/* ########################    NIRS TDC FUNCTIONS (NIRS)  ####################### */

int NirsBox(int Start);
int NirsLasers(int Start);
void InitNirs(int Board);
void TimeNirs(int Board, double Time);
void TrashNirs(void);
void CloseNirs(void);
void StartNirs(int Board);
void StopNirs(int Board);
void GetDataNirs(void);
void WaitNirs(int Board);


/* ########################    LUCA TDC FUNCTIONS (LUCA)  ####################### */

int LucaBox(int Start);
int LucaLasers(int Start);
void InitLuca(int Board);
void TimeLuca(int Board, double Time);
void TrashLuca(void);
void CloseLuca(void);
void StartLuca(int Board);
void StopLuca(int Board);
void GetDataLuca(void);
void WaitLuca(int Board);


/* ########################    SWAB TDC FUNCTIONS  ####################### */

void InitSwab(int Board);
void CloseSwab(void);
void GetDataSwab(void);
void ClearSwab(void);
void PauseSwab(int Board);
void StartSwab(int Board);
void TimeSwab(int Board,double Time);
void StopSwab(int Board);
void WaitSwab(int Board);
void GetSwabElapsedTime(double *Elapsed_Time);
void StartFileSwab(void);

/* ########################   BCD SPC & STEP FUNCTIONS   ####################### */
void InitBcd(int Board);
void CloseBcd(void);
void GetDataBcd(void);
void ClearBcd(void);
void MoveBcdSync(char Step,long Goal,char Wait);
void CalcCoarseFineBcd(long Goal, uint8_t *Coarse, uint8_t *Fine);
void MoveBcdPix(char Step,long Goal,char Wait);
void TimeBcd(float Time);
void WaitBcd(void);

/* ########################   VARRO SPC FUNCTIONS   ####################### */
void InitVarro(void);
char CheckAcqVarro(void);
void GetDataVarro(void);
void StringCommVarro(char *comstring);
void CharCommVarro(char comchar);
void NewComm(void);
void SendAck(void);
void GetAck(void);

/* ########################   SILENA SPC FUNCTIONS   ####################### */
void InitSilena(void);
void SetSilenaTime(void);
void SetSilenaRoi(void);
void ClearSilena(void);
void DataInSilena(void);
char CheckAcqSilena(void);
void DataStopSilena(void);
void WaitEndSilena(unsigned char tcstop);
void GetDataSilena(void);

/* ########################   TRIMMER PROCEDURES   ######################## */
void InitTrim(char Trim);
void AutoTrim(int Trim);
void CheckTrimGoal(int Trim);
void SaveTrim(char Trim);

/* ########################   SWITCH PROCEDURES   ######################## */
void InitSwitch(char Switch);
void CloseSwitch(char Switch);
void MoveSwitch(long Goal, char Switch);
long CalcGoalSwitch(char Switch);
void InitPosSwitch(char Switch);
void InitSwitch2X2(char Switch);
void MoveSwitch2X2(long Goal,char Switch);
void InitSwitch1X4(char Switch);
void InitSwitch1X9(char Switch) ;
void MoveSwitch1X9(long Goal,char Switch);
void MoveSwitch1X4_old(long Goal,char Switch);
void MoveSwitch1X4(long Goal,char Switch);
void InitSwitch2X2EOL(char Switch);
void MoveSwitch2X2EOL(long Goal,char Switch);
void InitSwitchLuca(char Switch);
void MoveSwitchLuca(long Goal,char Switch);
void InitSwitchLeoni(char Switch);
void MoveSwitchLeoni(long Goal,char Switch);
void InitSwitchThorWheel(char Switch);
void CloseSwitchThorWheel(char Switch);
void MoveSwitchThorWheel(long Goal,char Switch);

/* ########################   SYNC PROCEDURES   ######################## */
void InitSync(void);
void StartSync(void);
void StopSync(void);
void InitSyncUsb(void);
void StartSyncUsb(void);
void StopSyncUsb(void);
void InitSyncLpt(void);
void StartSyncLpt(void);
void StopSyncLpt(void);

/* ########################   OMA PROCEDURES   ######################## */
void InitOma(void);
void CloseOma(void);
void StartOma(void);
void StopOma(void);
int CVICALLBACK ClientTCPCB (unsigned handle, int event, int error,void *callbackData);

/* ########################   OPHIR PROCEDURES   ######################## */
void InitOphir(void);
void CloseOphir(void);
void GetOphir(void);

/* ########################   STEPPER PROCEDURES   ######################## */
void StartCont(char Step, char Status);
void WaitCont(char Step, char Status);
void InitStep(char Step);
void CloseStep(char Step);
void SetVel(char Step, double Freq);
void InitPos(char Step);
void InitBreak(char Break);
void DefineHome(char Step);
long CalcGoal(char Step);
void MoveStep(long *Actual,long Goal,char Issue,char Wait,char Status);
void StopStep(char Step);
void TellPos(char Step,long *Position);
void WaitPos(char Step,long Goal);
void WaitStep(long *Actual,long Goal,char Step,char Status);

// ### STEPPER WITH PARALELL PORT ###
void InitLpt(void) ;
void MoveLpt(char Step,long Inc,char Dir);
double CalcSleepStep(long it, long StepMax, double FreqMax, double FreqMin);

// ### STEPPER WITH NEWPORT ###
void InitNewp(double speed, char Axis, char Step);
void SetVelNewp(double Freq);
void DefineHomeNewp(char Step);
void MoveNewp(char Step, long Goal, long Delta, char Axis, char Speed, char Wait);
void TellPosNewp(char Step,long *Position);

// ### STEPPER WITH NEWPORT MM4005 ###
void InitNewp4005(double speed, char Axis, char Step);
void SetVelNewp4005(char Step,double Freq);
void DefineHomeNewp4005(char Step);
void MoveNewp4005(char Step, long Goal, long Delta, char Axis, char Speed, char Wait);
void TellPosNewp4005(char Step,long *Position);

// #### NATIONAL INSTRUMENTS MIO DAQ ####
void InitMio(char Axis, char Step);
void MoveMio(char Step,long Goal);
void CloseMio(char Step);

// #### NATIONAL INSTRUMENTS ADC ####
void InitAdc(void);
void StartAdc(void);
void StopAdc(void);
void WaitAdc(void);
void CloseAdc(void);

// #### NATIONAL INSTRUMENTS TIO10 STEPPER ####
void InitTio(char Axis, char Step);
void CloseTio(char Axis, char Step);
void SetVelTio(char Step, double Freq);
void MoveTio(char Step,long Delta, char Dir, char Wait);
void WaitTio(char Step,long Delta,char Dir);
void TellPosTio(char Step,long *Position);
void StopTio(char Step);

// #### MICROCHIP STEPPER ####
void InitMicro(char Step);
void CloseMicro(char Step);
void SetVelMicro(char Step, double Freq);
void MoveMicro(char Step,long Goal,char Wait);
void WaitMicro(char Step,long Goal);
void TellPosMicro(char Step,long *Actual);
void StopMicro(char Step);
void DefineHomeMicro(char Step);
void TalkMicro(char Step, char Command, long Value, long *Answer);
void GetMicro(int Com, long *Answer);

// #### ARDUINO STEPPER ####
void InitArd(char Step);
void CloseArd(char Step);
void SetVelArd(char Step, double Freq);
void MoveArd(char Step,long Goal,char Wait);
void WaitArd(char Step,long Goal);
void TellPosArd(char Step,long *Actual);
void StopArd(char Step);
void DefineHomeArd(char Step);
void TalkArd(char Step, char Command, long Value, long *Answer);
void GetArd(int Com,long *Answer);


// #### DMD TEXAS STEPPER ####
//void allocatePatternTest123(struct Patterns *p, int nEl);
void SetupDmdTx(struct InfoDmd* info);
void InitDmdTx(char Step);
void CloseDmdTx(char Step);
void MoveDmdTx(char Step,long Goal,char Wait);
void WaitDmdTx(char Step,long Goal);
void TellPosDmdTx(char Step,long *Actual);
void StopDmdTx(char Step);
void DefineHomeDmdTx(char Step);


// #### ESP300 STEPPER ####
void InitEsp300(char Step);
void CloseEsp300(char Step);
void SetVelEsp300(char Step, double Freq);
void MoveEsp300(char Step,long Goal,char Wait);
void WaitEsp300(char Step,long Goal);
void TellPosEsp300(char Step,long *Actual);
void StopEsp300(char Step);
void DefineHomeEsp300(char Step);
void TalkEsp300a(int Com, int Axis, char *Command, long Value);
void TalkEsp300b(int Com, int Axis, char *Command);
void GetEsp300(int Com,char *Answer);

// #### LT900 STEPPER ####
void InitLt900(char Step);
void CloseLt900(char Step);
void SetVelLt900(char Step, double Freq);
void MoveLt900(char Step,long Goal);
void DefineHomeLt900(char Step);
void TalkLt900(int Com, char *Command, char *Answer);
void GetLt900(int Com,char *Answer);

// #### CHAMALEON STEPPER ####
void InitCham(char Step);
void CloseCham(char Step);
void SetVelCham(char Step, double Freq);
void MoveCham(char Step,long Goal,char Wait);
void WaitCham(char Step,long Goal);
void TellPosCham(char Step,long *Actual);
void StopCham(char Step);
void DefineHomeCham(char Step);
void TalkChama(int Com, int Axis, char Command[2], long Value);
void TalkChamb(int Com, int Axis, char Command[2]);
void GetCham(int Com,float *Answer);

// #### PI STEPPER ####
void InitPi(char Step);
void ClosePi(void);
void SetVelPi(double Freq);
void MovePi(char Step,long Goal,char Wait);
void WaitPi(char Step,long Goal);
void TellPosPi(char Step,long *Actual);
void StopPi(void);
void DefineHomePi(char Step);
void TalkPi(int Com, char Command, long Value, long *Answer);
void GetPi(int Com, long *Answer);

// #### STANDA STEPPER ####
void InitStanda(char Step);
void CloseStanda(char Step);
void SetVelStanda(char Step,double Freq);
void MoveStanda(char Step,long Goal,char Wait);
void WaitStanda(char Step,long Goal);
void TellPosStanda(char Step,long *Actual);
void StopStanda(char Step);
void DefineHomeStanda(char Step);

// #### STANDA2 STEPPER ####
void InitStanda2(char Step);
void CloseStanda2(char Step);
void SetVelStanda2(char Step, double Freq);
void MoveStanda2(char Step,long Goal,char Wait);
void WaitStanda2(char Step,long Goal);
void TellPosStanda2(char Step,long *Actual);
void StopStanda2(char Step);
void DefineHomeStanda2(char Step);

// #### ATT_LUCA STEPPER ####
void InitAttLuca(char Step);
void CloseAttLuca(char Step);
void SetVelAttLuca(char Step, double Freq);
void MoveAttLuca(char Step,long Goal,char Wait);
void WaitAttLuca(char Step,long Goal);
void TellPosAttLuca(char Step,long *Actual);
void StopAttLuca(char Step);
void DefineHomeAttLuca(char Step);

// #### NATIONAL INSTRUMENTS USB-6229
void SetFreqNI_USB6229(char Step,long Goal);
void SetVoltNI_USB6229(char Step,long Goal);
void SetVoltNI_USB6221(char Step,long Goal);

// #### NKT COMMUNICATION
void InitNKTLambda(char Step);
void InitNKTPow(char Step);
void CloseNKTLambda(char Step);
void CloseNKTPow(char Step);
unsigned short calcCRC16(unsigned char data, unsigned short crc); 
void addToTxMsgData(unsigned char *txBuffer,int *txBufferSize,unsigned short *txCRC,unsigned char data, unsigned int escParse, unsigned int updCRC);
void NKTSendMessage(char Step,void *Value, unsigned char Dest, unsigned char Source, unsigned char Type,unsigned char Register, unsigned int DataType);
void rx(char Step, unsigned char *rxBuffer);
void SetNKTLambda(char Step,long Goal);
void SetNKTPow(char Step,long Goal);
void ReadNKTLimits(char Step, long *WaveShort, long *WaveLong);

// #### MONOCROMATOR STEPPER  VIA SERIAL PORT ####
void InitMono(char Step);
void CloseMono(char Step);
void SetVelMono(char Step, double Freq);
void MoveMono(char Step,long Goal,char Wait);
void WaitMono(char Step,long Goal);
void TellPosMono(char Step,long *Actual);
//void StopMono(char Step);
void DefineHomeMono(char Step);
void TalkMono(int Com, int Command, long Value, long *Answer);
void GetMono(int Com, long *Answer);

// #### MONOCROMATOR STEPPER  VIA TCPIP PORT ####
void InitMonoTcp(char Step);
void CloseMonoTcp(char Step);
void SetVelMonoTcp(char Step, double Freq);
void MoveMonoTcp(char Step,long Goal,char Wait);
void WaitMonoTcp(char Step,long Goal);
void TellPosMonoTcp(char Step,long *Actual);
void DefineHomeMonoTcp(char Step);
void TalkMonoTcp(char *Command);
void GetMonoTcp(int Com, long *Answer);
int CVICALLBACK Client_MonoTCPCB (unsigned handle, int event, int error,void *callbackData);

// #### FIBER ATTENUATOR PWM ####
void InitPwm(char Step);
void ClosePwm(char Step);
void SetVelPwm(char Step, double Freq);
void MovePwm(char Step,long Goal,char Wait);
void TellPosPwm(char Step,long *Actual);
void StopPwm(char Step);
void DefineHomePwm(unsigned int Step);
void TalkPwm(int Com, char Command, long Value, long *Answer);
void GetPwm(int Com, long *Answer);


// #### FIBER POWER MONITOR (FPM) ####
void InitFpm(char Step);
void CloseFpm(char Step);
void TalkFpm(int Com, char *Command, long Value, long *Answer);
void GetFpm(int Com, long *Answer);
void MoveFpm(char Step,long Goal);
//void TellPosFpm(char Step,long *Actual);
void StopFpm(char Step);

// #### DELAYER_STEP ####
void InitDelayerGate(char Step);
void MoveDelayerGate(char Step,long Goal);
void CalcStr (float Goal,char Step,int n);
void TalkDelayerStep(char Step);


// #### DELAYER (DELAYER) ####
void InitDelayer(char Step);
void MoveDelayer(char Step,long Goal);
void CloseDelayer(char Step);



/* ########################   SAVE PROCEDURES   ########################### */
void InitDataFile(void);
void CloseDataFile(void);
void EnterName(void);
void DataSave(void); 
void CompileHeader(void);

/* ########################   MISCELLANEOUS PROCEDURES   ################## */
void InitIeee(void);
void InitTime(void);
void CloseTime(void);
double TimerN(void);
	
/* ########################   PROFILING FUNCTIONS   ########################### */
//#ifdef IS_PROFILING
void InitProf(void);
void RecProf(char *Label);
void CloseProf(void);
//#endif

/* ########################   TOOLS FUNCTIONS   ########################### */
void GpibWrite(int Address,char *Command);
void GpibRead(int Address, char *Buffer, int MaxByte);
void Failure(char *Error);
void PrintValue(double value, char* Text);
void Passed(void);
char *NewItoa(int num, char *numstring, int length);
int StringToNum(char *sNum);
void CompLRC(char *pointer, int size);
void SetNow(clock_t *ptimeorigin);
void CheckTime(clock_t timeorigin);
void PrintTime(clock_t timeorigin, char *Title);
void CalibrateTime(double TimeDelay);
void ErrHandler(int Device, int Code, char* Function);
void pyErrHandler(char* Function, char* serror);

/* ########################   MEMORY FUNCTIONS   ########################### */
T_DATA *DAlloc1D(int Num1);
T_DATA **DAlloc2D(int Num1, int Num2);
uint32_t **DAlloc2D_uint32(int Num1, int Num2);
T_DATA ***DAlloc3D(int Num1, int Num2, int Num3);
SC1000_TYPE ***DAlloc3D_SC1000(int Num1, int Num2, int Num3);
T_SUB **SAlloc2D(int Num1, int Num2);
SC1000_TYPE *SC1000Alloc1D(int Num1);
double *doubleAlloc1D(int Num1);
double ***doubleAlloc3D(int Num1, int Num2, int Num3);
void DFree1D(T_DATA *D);
void DFree2D(T_DATA **D, int Num1);
void DFree2D_uint32(uint32_t **D, int Num1);
void DFree3D(T_DATA ***D, int Num1, int Num2);
void DFree3D_SC1000(SC1000_TYPE ***D, int Num1, int Num2);
void SFree2D(T_SUB **D, int Num1);
void SC1000Free1D(SC1000_TYPE *D);
void doubleFree1D(double *D);
void doubleFree3D(double ***D, int Num1, int Num2);



/* ########################   MAMM PROCEDURES   ########################### */
void KernelMamm(void);
void InitMamm(void);
void InitRam(void);
void DoMamm(void);
void FindTop(void);
int FindBorderVIS(int *iActual, char Axis, double Count,char Dir);
void DataSaveMamm(void);
void AnalysisMamm(void);
char IsBorderVIS(char);
char IsBorderNIR(char, char);
void InitLegend(void);
void AddLabel(int IdName);
void AddThick(int ID);
void InitMammot(void);			//EDO
void StartMammot(void);			//EDO
void StopMammot(void);			//EDO
void CheckMammot(void);			//EDO
void AnalysisMamm_new(void);	//EDO
void ShiftCorrection(void);		//EDO
void BackShift(void);			//EDO


/* ########################   MOXY PROCEDURES   ########################### */
void InitMoxy(void);
void CloseMoxy(void);
void StartMoxy(void);
void AbortMoxy(void);
void GotoMoxy(int Switch,int Chann);
void WaitMoxy(void);
void KernelMoxy(void);
short test_fill_state(void);
void InitBank(void);
short ClearBank(void);
void WaitBank(void);
void EnableBank(void);
void GetBank(void);
void StatusBank(int ActBank, int TotBank);
void CopySaveBank(void);

/* ########################   PRESENTATION PROCEDURES   ########################### */ 
void InitPres(void);

/* ########################   UIR PROCEDURES   ########################### */
void CVICALLBACK SaveSetting (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK LoadSetting (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK Print(int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK Quit (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK ShowPanel (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK SetImage (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK SetRefle (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK SetFluo (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK SetFree (int menuBar, int menuItem, void *callbackData,int panel);
void CVICALLBACK About (int menuBar, int menuItem, void *callbackData,int panel);
void InitPanel(void);
void *AddrCtrl(int Control,int hPanel);
int CVICALLBACK Setting (int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int handlePanel(int PanelID);
void UpdatePanel(void);

/* ########################   GEOMETRY PROCEDURES   ########################### */ 							      //ALE
/* GEOMETRY FUNCTIONS DEFINITION */																			      //ALE
int CVICALLBACK CreatePad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2); //ALE
int CVICALLBACK PropPad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);   //ALE
int CVICALLBACK ShowPad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);   //ALE
int CVICALLBACK SetType (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);   //ALE
int CVICALLBACK SaveGeom (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);   //ALE
int CVICALLBACK LoadGeom (int panel, int control, int event,void *callbackData, int eventData1, int eventData2);   //ALE
void ReadGeom(void);
void InitPad (void);																						      //ALE
void ReCreatePad (void);																						  //ALE
/* END GEOMETRY FUNCTIONS DEFINITION */								   										      //ALE
