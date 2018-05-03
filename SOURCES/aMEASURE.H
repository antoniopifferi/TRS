/* ########################   CONSTANTS   ################################# */

// VERSION
#define MESSAGE_ABOUT   "Copyright: POLITECNICO DI MILANO\nVersion: 8.0\nDate: July 2008"

// TYPE OF DATA
// USE long for TimeHarp, Varro, Silena, USE short for all others SPC boards.
#define T_DATA unsigned short
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
#define PATHLEN		  30
#define PACKLENGTH 	  6
#define SLI           sizeof(long)
#define SCH           sizeof(char)

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
#define MAX_TABLE		1051
#define STRLEN_TABLE	20
#define TCHAR			0
#define TINT			1
#define TDOUBLE			2
#define	TSTRING			3
#define CE				0
#define CT				1
#define MAX_TTABLE		13
#define STRLEN_TTABLE	20
#define MAX_PANEL		13


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
#define EXTFILEBREAK  ".BRE"
#define DIRFILEBREAK  "BREAK"

/* LOOP CONSTANTS */
#define MAX_LOOP			3
#define LOOP_NONE	   -1
#define LOOP1			0
#define LOOP2			1
#define LOOP3			2

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
#define STEP_MIO_BOARD1			 3   // MIO device number  

// ADC SPECIFIC CONSTANTS
#define POWER_ADC_BOARD			 4   // ADC device number (same as MIO Board: PCI6024E) 
#define ADC_FACTOR				 1000000 // conversion factor from Volt to microVolt

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
#define MICRO_PARITY 	0
#define MICRO_DATABITS	8
#define MICRO_STOPBITS	1

// DELAYER SPECIFIC CONSTANTS
#define DELAYER_BAUDRATE 	19200
#define DELAYER_PARITY 		0
#define DELAYER_DATABITS	8
#define DELAYER_STOPBITS	1


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
#define AOTF_FREQ_FACTOR 1000000; //1E9->HZ, 1E6->KHz, 1E3->MHz
#define AOTF_VOLT_FACTOR 1000;   //1->Volt, 1000->mV

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

// SYNC CONSTANT
#define SYNC_INPUT   1
#define SYNC_OUTPUT  2
#define SYNC_ONE	 1
#define SYNC_TWO	 2
#define SYNC_CONT	 3



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

#define LPT			 1
#define NEWP	 	 2
#define TIO			 3
#define MIO			 4
#define MM4005		 5
#define MICRO		 6
#define MONO		 7
#define MONO_TCP     8
#define PI			 9
#define FPM			10
#define PWM 		11
#define DELAYER		12
#define ADC	        13
#define AOTF_FREQ	14
#define AOTF_POW	15
#define NKT_LAMBDA	16
#define NKT_POW		17
#define VARRO		 1
#define NI_6602	     5
#define COM          6
#define NIDAQmx      7
#define SILENA		 2
#define SPC300		 3
#define THARP	     4
#define SPC630       5
#define SPC130       6
#define HYDRA		 7
#define TEST		 8
#define WAIT_DELAY	 0
#define WAIT_TIME	 1
#define WAIT_COUNT	 2
#define WAIT_POS     3
#define WAIT_SPC     4
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
#define MAX_DET		64
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
#define TARGET_WIDTH	1
#define TARGET_AREAWIDTH 2
#define LOWER			0
#define HIGHER			1
#define TRIM_DIR_MIDDLE	0
#define TRIM_DIR_UP		1
#define TRIM_DIR_DOWN	2
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

/* OMA CONSTANTS  */
/***/
#define OMA_NONE					-1
#define OMA_IP_ADDRESS_FILE			"c:\\Programs\\ControlloOMA\\ipAddress.txt"    
										/* file contenente l'indirizzo IP del PC su cui è lanciato il programma dell'OMA */
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
#define ERR_HYDRA	2


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

struct FileS {
	char Type;
	char Dir   [PATHLEN];
	char Name  [PATHLEN];
	char Ext   [PATHLEN];
	char Prefix[PATHLEN];
	char Path  [STRLEN];
	int Tag;
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
struct CommentS {
	char Date[STRLEN];
	char Time[STRLEN];  
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

struct AdcS {
	char sPath[STRLEN];							// Channel Path as defined in the daq  syntax
	char sChann[2];							// Channel within same Board
	long Board;							// NIDAQ Board Number
	long Chann;							// NIDAQ Channel Number
	unsigned long Task;							// NIDAQ Task ID
	double Data[10000];					// Buffered Data
	};

struct MonoTcpS {
	unsigned int Handle;  
	long ServerValue;
	int ServerReady;
	char IpAddress[MONO_TCP_STRLEN]; 
	};
	
struct StepS {
	int Control;
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
	long Delta;
	long Home;
	double Factor;
	struct TioS Tio;
	struct MioS Mio;
	double FreqMax;
	double FreqMin;
	double FreqActual;
	double FreqDelta;
	double Freq;
	long Start[MAXPOS];
	long Stop[MAXPOS];
	char  FName[STRLEN];
	char  FPath[STRLEN];
	};


struct SwitchS {
	char  Switch;
	int Control;
	char  Device;
	char  Type;
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
	double Width;
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
	struct ChannS Roi;
	struct ChannS Range;
	int Control;
	char Type;
	char Dir;
	char Region;
	char Step;
	char Trim;
	char Loop;
	double Fract;
	char Target;
	double Goal;
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
	long   Count;
	char   Scale;
	double Calib;
	double Factor;
	int    RoutingBits;
	int	   MaxPage[MAX_BOARD];
	char   Settings[MAX_BOARD][260];
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
	long LoopHome[MAX_LOOP];
	long LoopFirst[MAX_LOOP];
	long LoopLast[MAX_LOOP];
	long LoopDelta[MAX_LOOP];
	long LoopNum[MAX_LOOP];
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
	long Loop[MAX_LOOP];
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
	struct CommentS Comment;
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
	};

// Data Structures
struct DataS {
	T_HEAD Head;		// D.Head
	T_SUB **Sub;		// D.Sub[P.Frame.Num][P.Num.Page]
	T_DATA ***Data;		// D.Data[P.Frame.Num][P.Num.Page][P.Num.Chann] 
	T_DATA **Osc;		// D.Osc[P.Num.Board*P.Num.Det][P.Num.Chann] 
	T_DATA **Buffer;	// D.Buffer[P.Num.Board][P.Num.Det*P.Num.Chann] 
	T_DATA **Bank;		// D.Bank[P.Num.Board][SPC_BANK_DIM] 
	T_DATA *Curve;		// D.Curve[P.Num.Chann] 
	T_DATA *Last;		// D.Last[P.Num.Chann] 
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
int hMamm;
int hSave;
int hLabel;
int hDoStep;
int hDisplay;
int hPlot[MAX_PLOT];
int hMarkerF, hMarkerL;
int hPanel[MAX_PANEL];
int is_panel_mamm, is_panel_label;

/* GEOMETRY GLOBAL VARIABLES */								//ALE
int hGeom;													//ALE
int pa,lattice_type,clatticetype;							//ALE
int ip,ir,ic,jr,jc,lattice_type;							//ALE
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

/* #####################    MEASUREMENT FUNCTIONS   ########################### */
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
void CalcLoopIndex(long Steps,long *Loop1,long *Loop2,long *Loop3);

/* ########################   DISPLAY PROCEDURES   ########################### */
void TextOut(void);
void UpdateTag(void);
void InitDisplay(void);
void DisplayStatus(void);
void DisplayPlot(void);
void GraphRoi(void);
void GraphPlot(void);
void DisplayRoi(void);
long CalcArea(long First, long Last);
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

/* ########################   SPC300 SPC FUNCTIONS   ####################### */
void InitSpc300(void);
void GetDataSpc300(void);
void InitSpcm(int Board);
void GetDataSpcm(void);
void CloseSpcm(void);
void ClearSpcm(void);

/* ########################   HYDRA HARP FUNCTIONS   ####################### */
void InitHydra(int Board);
void CloseHydra(void);
void GetDataHydra(void);
void ClearHydra(void);


/* ########################   THARP SPC FUNCTIONS   ####################### */
void InitTimeharp(void);
void GetDataTimeharp(void);

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
void CheckTrimGoal(int Step);
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



/* ########################   SYNC PROCEDURES   ######################## */
void InitSync(void);
void StartSync(void);
void StopSync(void);

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
void CloseMio(void);

// #### NATIONAL INSTRUMENTS ADC ####
void InitAdc(void);
void StartAdc(void);
void StopAdc(void);
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
void TalkMicro(int Com, char Command, long Value, long *Answer);
void GetMicro(int Com, long *Answer);

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


// #### NATIONAL INSTRUMENTS USB-6229
void SetFreqNI_USB6229(char Step,long Goal);
void SetVoltNI_USB6229(char Step,long Goal);

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
void Passed(void);
char *NewItoa(int num, char *numstring, int length);
int StringToNum(char *sNum);
void CompLRC(char *pointer, int size);
void SetNow(clock_t *ptimeorigin);
void CheckTime(clock_t timeorigin);
void PrintTime(clock_t timeorigin, char *Title);
void CalibrateTime(double TimeDelay);
void ErrHandler(int Device, int Code, char* Function);

/* ########################   MEMORY FUNCTIONS   ########################### */
T_DATA *DAlloc1D(int Num1);
T_DATA **DAlloc2D(int Num1, int Num2);
T_DATA ***DAlloc3D(int Num1, int Num2, int Num3);
T_SUB **SAlloc2D(int Num1, int Num2);
void DFree1D(T_DATA *D);
void DFree2D(T_DATA **D, int Num1);
void DFree3D(T_DATA ***D, int Num1, int Num2);
void SFree2D(T_SUB **D, int Num1);


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
