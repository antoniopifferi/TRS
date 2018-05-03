/*---------------------------------------------------------------------------*/
/*                              SPC                                          */
/*---------------------------------------------------------------------------*/
/*    Copyright (c) Becker & Hickl GmbH  1997,1998  All Rights Reserved.     */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Title   : SPC_DEF.H                                                       */
/* Purpose : Include file for programs using SPC 32-bit DLL under            */
/*              Windows95/NT.                                                   */
/* Note    :                                                                 */
/*                                                                           */
/*   Functions listed here are exported in   spcdll32.dll                    */
/*                                                                           */
/*   Use proper Import Library File spcdll32.lib depending on used compiler  */
/*    ( Borland C++ v.4 , Watcom C , Microsoft Visual C and  Symantec C      */
/*        compilers are supported )                                          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*- Defines -----------------------------------------------------------------*/

#include <cvirte.h>     /* needed if linking DLL in external compiler; harmless otherwise */



#ifdef __cplusplus
  extern "C" {
#endif

#pragma pack(1)


/*- Error codes  ------------------------------------------------------------*/

#ifndef SPC_DEFINITIONS
#define SPC_DEFINITIONS

#define OK                0    /* no error */

#define  SPCDLL_ERROR_KEYWORDS \
{ \
  keyword (SPC_NONE), \
  keyword (SPC_OPEN_FILE), \
  keyword (SPC_FILE_NVALID), \
  keyword (SPC_MEM_ALLOC), \
  keyword (SPC_READ_STR), \
  keyword (SPC_WRONG_ID), \
  keyword (SPC_EEPROM_CHKSUM), \
  keyword (SPC_EEPROM_READ), \
  keyword (SPC_EEPROM_WRITE), \
  keyword (SPC_EEP_WR_DIS), \
  keyword (SPC_BAD_PAR_ID), \
  keyword (SPC_BAD_PAR_VAL), \
  keyword (SPC_HARD_TEST), \
  keyword (SPC_BAD_PARA1), \
  keyword (SPC_BAD_PARA2), \
  keyword (SPC_BAD_PARA3), \
  keyword (SPC_BAD_PARA4), \
  keyword (SPC_BAD_PARA5), \
  keyword (SPC_BAD_PARA6), \
  keyword (SPC_BAD_PARA7), \
  keyword (SPC_CANT_ARM),\
  keyword (SPC_CANT_STOP),\
  keyword (SPC_INV_REPT),\
  keyword (SPC_NO_SEQ),\
  keyword (SPC_SEQ_RUN),\
  keyword (SPC_FILL_TOUT),\
  keyword (SPC_BAD_FUNC),\
  keyword (SPC_WINDRV_ERR),\
  keyword (SPC_NOT_INIT),\
  keyword (SPC_ERR_ID),\
  keyword (SPC_RATES_NOT_RDY),\
};
                   
/*
   use function SPCI_get_error_string to get error string programmatically
   
   SPC_NONE            0       no error
   SPC_OPEN_FILE      -1       can't open configuration file
   SPC_FILE_NVALID    -2       not valid configuration file
   SPC_MEM_ALLOC      -3       memory allocation error
   SPC_READ_STR       -4       can't read string from file
   SPC_WRONG_ID       -5       wrong module id read from SPC
   SPC_EEP_CHKSUM     -6       wrong EEPROM checksum
   SPC_EEPROM_READ    -7       error during reading EEPROM
   SPC_EEPROM_WRITE   -8       error during writing to EEPROM
   SPC_EEP_WR_DIS     -9       write access to EEPROM denied
   SPC_BAD_PAR_ID     -10      unknown SPC parameter id 
   SPC_BAD_PAR_VAL    -11      wrong SPC parameter value  
   SPC_HARD_TEST      -12      SPC hardware test error 
   SPC_BAD_PARA1      -13      wrong value of 1st function parameter 
   SPC_BAD_PARA2      -14      wrong value of 2nd function parameter 
   SPC_BAD_PARA3      -15      wrong value of 3rd function parameter 
   SPC_BAD_PARA4      -16      wrong value of 4th function parameter 
   SPC_BAD_PARA5      -17      wrong value of 5th function parameter 
   SPC_BAD_PARA6      -18      wrong value of 6th function parameter 
   SPC_BAD_PARA7      -19      wrong value of 7th function parameter 
   SPC_CANT_ARM       -20      cannot arm SPC module 
   SPC_CANT_STOP      -21      cannot stop SPC module  
   SPC_INV_REPT       -22      invalid contents of repeat timer 
   SPC_NO_SEQ         -23      sequencer does not exist on the module
   SPC_SEQ_RUN        -24      cannot execute function when sequencer is running
   SPC_FILL_TOUT      -25      timeout during filling SPC memory
   SPC_BAD_FUNC       -26      function not available for the module or current mode
   SPC_WINDRV_ERR     -27      Error in WinDriver
   SPC_NOT_INIT       -28      SPC is not yet initialized or unknown module type
   SPC_ERR_ID         -29      Error ID is out of range
   SPC_RATES_NOT_RDY  -30      Rates values not ready yet
*/



/*- SPC parameters IDs ------------------------------------------------------*/

#define  SPC_PARAMETERS_KEYWORDS \
{ \
  keyword (CFD_LIMIT_LOW), \
  keyword (CFD_LIMIT_HIGH), \
  keyword (CFD_ZC_LEVEL), \
  keyword (CFD_HOLDOFF), \
  keyword (SYNC_ZC_LEVEL), \
  keyword (SYNC_FREQ_DIV), \
  keyword (SYNC_HOLDOFF), \
  keyword (SYNC_THRESHOLD), \
  keyword (TAC_RANGE), \
  keyword (TAC_GAIN), \
  keyword (TAC_OFFSET), \
  keyword (TAC_LIMIT_LOW), \
  keyword (TAC_LIMIT_HIGH), \
  keyword (ADC_RESOLUTION), \
  keyword (EXT_LATCH_DELAY), \
  keyword (COLLECT_TIME), \
  keyword (DISPLAY_TIME), \
  keyword (REPEAT_TIME), \
  keyword (STOP_ON_TIME), \
  keyword (STOP_ON_OVFL), \
  keyword (DITHER_RANGE), \
  keyword (COUNT_INCR), \
  keyword (MEM_BANK), \
  keyword (DEAD_TIME_COMP), \
  keyword (SCAN_CONTROL), \
  keyword (ROUTING_MODE), \
  keyword (TAC_ENABLE_HOLD), \
  keyword (MODE), \
  keyword (SCAN_SIZE_X), \
  keyword (SCAN_SIZE_Y), \
  keyword (SCAN_ROUT_X), \
  keyword (SCAN_ROUT_Y), \
  keyword (SCAN_POLARITY), \
  keyword (SCAN_FLYBACK), \
  keyword (SCAN_BORDERS), \
  keyword (PIXEL_TIME), \
  keyword (PIXEL_CLOCK), \
  keyword (LINE_COMPRESSION), \
  keyword (TRIGGER), \
  keyword (EXT_PIXCLK_DIV), \
  keyword (RATE_COUNT_TIME), \
  keyword (MACRO_TIME_CLK), \
  keyword (ADD_SELECT), \
};                                   




#ifdef keyword
#undef keyword  /* prevents redefinition warning */
#endif

#define keyword(key) key

enum spcdll_error_enum     SPCDLL_ERROR_KEYWORDS
enum spc_parameters_enum   SPC_PARAMETERS_KEYWORDS

    /* rate values structure */
typedef struct _rate_values
{
  float sync_rate;
  float cfd_rate;
  float tac_rate;
  float adc_rate;

} rate_values;


#endif     // SPC_DEFINITIONS

/*---------------------------------------------------------------------------*/

      /* correct SPC modules id values - tested in SPC_test_id */
#define SPC300_ID               0x1
#define SPC400_ID               0x8

      /* possible modes of DLL operation - returned from SPC_set(get)_mode */
#define SPC_HARD             0      /* hardware mode */
#define SPC_SIMUL300_10      3010   /* simulation mode of SPC300 10 bits ADC */
#define SPC_SIMUL300_12      3012   /* simulation mode of SPC300 12 bits ADC */
#define SPC_SIMUL330_10      3310   /* simulation mode of SPC330 10 bits ADC */
#define SPC_SIMUL330_12      3312   /* simulation mode of SPC330 12 bits ADC */
#define SPC_SIMUL400         40     /* simulation mode of SPC400 module */
#define SPC_SIMUL430         43     /* simulation mode of SPC430 module */
#define SPC_SIMUL401         401    /* simulation mode of SPC401 module */
#define SPC_SIMUL431         431    /* simulation mode of SPC431 module */
#define SPC_SIMUL402         402    /* simulation mode of SPC402 module */
#define SPC_SIMUL432         432    /* simulation mode of SPC432 module */
#define SPC_SIMUL500         50     /* simulation mode of SPC500 module */
#define SPC_SIMUL530         53     /* simulation mode of SPC530 module */
#define SPC_SIMUL230         23     /* simulation mode of SPC230 module */
#define SPC_SIMUL505         505    /* simulation mode of SPC505 module */
#define SPC_SIMUL535         535    /* simulation mode of SPC535 module */
#define SPC_SIMUL506         506    /* simulation mode of SPC506 module */
#define SPC_SIMUL536         536    /* simulation mode of SPC536 module */
#define SPC_SIMUL600         600    /* simulation mode of SPC600 module */
#define SPC_SIMUL630         630    /* simulation mode of SPC630 module */
#define SPC_SIMUL700         700    /* simulation mode of SPC700 module */
#define SPC_SIMUL730         730    /* simulation mode of SPC730 module */
#define SPC_SIMUL130         130    /* simulation mode of SPC130 module */

    /* supported module types  - returned value from SPC_test_id */
#define M_WRONG_TYPE  -1
#define M_SPC300    1
#define M_SPC330    2
#define M_SPC400    3
#define M_SPC430    4
#define M_SPC401    5     /* SPC FIFO with 48 bit data format */
#define M_SPC431    6     /* SPC FIFO with 48 bit data format */
#define M_SPC402    7     /* SPC FIFO with 32 bit data format */
#define M_SPC432    8     /* SPC FIFO with 32 bit data format */
#define M_SPC230    23    /* 430 special version */
#define M_SPC500    50    /* 400 with 8MB memory in one bank, no sequencer */
#define M_SPC530    53    /* 430 with 8MB memory in one bank, no sequencer */  
#define M_SPC505    505   /* 500 with scan control */
#define M_SPC535    535   /* 530 with scan control */
#define M_SPC506    506   /* 500 with TV routing control */  
#define M_SPC536    536   /* 530 with TV routing control */  
#define M_SPC600    600   /* PCI version of 400 + 401 + 402 */  
#define M_SPC630    630   /* PCI version of 430 + 431 + 432 */  
#define M_SPC700    700   /* PCI version of 500 + 505 + 506 */  
#define M_SPC730    730   /* PCI version of 530 + 535 + 536 */  
#define M_SPC130    130   /* 130  */

         /* masks for SPC module state  - function SPC_test_state */
#define SPC_OVERFL       0x1     /* stopped on overflow */
#define SPC_OVERFLOW     0x2     /* overflow occured */
#define SPC_TIME_OVER    0x4     /* stopped on expiration of collection timer */
#define SPC_COLTIM_OVER  0x8     /* collection timer expired */
#define SPC_CMD_STOP     0x10    /* stopped on user command */
#define SPC_ARMED        0x80    /* measurement in progress (current bank) */
         /* masks valid only for all modules from SPC400(430)*/
#define SPC_REPTIM_OVER  0x20    /* repeat timer expired */
#define SPC_COLTIM_2OVER 0x100   /* second overflow of collection timer */
#define SPC_REPTIM_2OVER 0x200   /* second overflow of repeat timer */
         /* masks valid only for modules SPC4x0, SPC6x0 */
#define SPC_SEQ_GAP      0x40    /* Sequencer is waiting for other bank to be armed */
         /* masks valid only for SPC4x1(4x2),SPC6x0 modules */
#define SPC_FOVFL        0x400   /* Fifo overflow,data lost */
#define SPC_FEMPTY       0x800   /* Fifo empty */

         /* masks valid only for SPC5x5, SPC7x0 modules */
#define SPC_FBRDY        0x800   /* Flow back of scan finished */
#define SPC_SCRDY        0x400   /* Scan ready (data can be read ) */

         /* masks valid only for SPC6x0 and SPC7x0 modules */
#define SPC_WAIT_TRG     0x1000   /* wait for trigger */

  /* sequencer state bits - returned from function SPC_get_sequencer_state  */
#define SPC_SEQ_ENABLE   0x1  /* sequencer is enabled */
#define SPC_SEQ_RUNNING  0x2  /* sequencer is running */
#define SPC_SEQ_GAP_BANK 0x4  /* sequencer is waiting for other bank to be armed */


    /*  initialization error codes -
           - possible return values of function SPC_get_init_status */
#define INIT_OK                    0
#define INIT_NOT_DONE             -1 /* init not done */
#define INIT_WRONG_EEP_CHKSUM     -2 /* wrong EEPROM checksum */
#define INIT_WRONG_MOD_ID         -3 /* wrong module identification code */
#define INIT_HARD_TEST_ERR        -4 /* hardware test failed */
#define INIT_CANT_OPEN_PCI_CARD   -5 /* cannot open PCI card */


         /* Scanning control word - scan_control parameter */
         /* masks valid only for SPC505(535) modules */
#define SPC_SCOE         0x8000  /* scan signal output enabled */
#define SPC_SCPPOL       0x4000  /* Polarity of SCAN PIXEL CLK */
#define SPC_SCXPOL       0x2000  /* Polarity of SCAN FLY BACK X */
#define SPC_SCYPOL       0x1000  /* Polarity of SCAN FLY BACK Y */
#define SPC_SCF          0xf00   /* SCF[3:0] log2(Scan fly-back) number of 
                                              pixels, max.=12 */
#define SPC_SCY          0xf0    /* SCY[3:0] log2(Scan Y) length of frame,
                                           min.= length of line, max.=14 */
#define SPC_SCX          0xf     /* SCX[3:0] log2(Scan X) length of frame,
                                           <= SCY , max.=14 */



         /* Routing control word - scan_control parameter */
         /* masks valid only for SPC506(536) modules */
#define SPC_TVFPOL       0x4000  /* Polarity of TV Frame Sync */
#define SPC_TVLPOL       0x2000  /* Polarity of TV Line Sync */
#define SPC_TVPIX        0x0300  /* TVPIX[1:0] pixel time[ns] 00 = 200, 01 = 400,
                                                              10 = 800, 11 = 1600 */
#define SPC_TVY          0x30    /* TVY[1:0] no. of lines per image:
                                     00 = 64, 01 = 128, 10 = 256, 11 = 512 */
#define SPC_TVLDIV       0xc     /* TVLDIV[1:0] line predivider
                                     00 = 1, 01 = 2 10 = 4, 11 = 8 */
#define SPC_TVX          0x3     /* TVX[1:0] no. of pixels per line
                                     00 = 32, 01 = 64 10 = 128, 11 = 256 */

         /* mode values for SPC7xx */
         
#define ROUT_IN   0           
#define ROUT_OUT  1           
#define SCAN_IN   2           
#define SCAN_OUT  3           
         
         /* mode values for SPC6xx */
         
#define NORMAL    0           
#define WIDE      1    // not implemented
#define FIFO_48   2           
#define FIFO_32   3           

         /* mode values for SPC130 */
         
#define NORMAL    0           
#define WIDE      1    // not implemented
#define FIFO130   2           

#define FIFO_130  4   // fifo type of 130

/*---------------------------------------------------------------------------*/


              /* structure for memory configuration parameters */
typedef struct _SPCIMemConfig{   
  long   max_block_no;    /* total number of blocks per memory bank */
  short  block_length;    /* no of 16-bits words per one block */
  long   blocks_per_frame; /* no of blocks per frame */
  long   frames_per_page;  /* no of frames per page */
  long   maxpage;         /* max number of pages to use in a measurement */
  }SPCIMemConfig;

typedef struct _SPCIMemConfig *SPCIMemConfigType;   

typedef struct _SPCIdata{     /* structure for library data  */
  unsigned short base_adr;
  short          init;       /* set to initialization result code */
  short test_eep;        /* test EEPROM checksum or not  */
  float cfd_limit_low;   /* for SPCx3x -500 .. -20mV ,for SPCx0x 5 .. 80mV */
  float cfd_limit_high;  /* 5 ..80 mV, default 80 mV , not for SPC130 */
  float cfd_zc_level;    /* SPCx3x -96 .. 96mV, SPCx0x -10 .. 10mV */
  float cfd_holdoff;     /* SPCx0x: 5 .. 20 ns, other modules: no influence */
  float sync_zc_level;   /* SPCx3x: -96 .. 96mV, SPCx0x: -10..10mV */
  short sync_freq_div;   /* 1,2,4,8,16 ( SPC130/230: 1,2,4) */
  float sync_holdoff;    /* 4 .. 16 ns ( SPC130/230: no influence) */
  float sync_threshold;  /* SPCx3x: -500 .. -20mV, SPCx0x: no influence */
  float tac_range;       /* 50 .. 2000 ns */
  short tac_gain;        /* 1 .. 15  */
  float tac_offset;      /* 0 .. 100% */
  float tac_limit_low;   /* 0 .. 100% */
  float tac_limit_high;  /* 0 .. 100% */
  short adc_resolution;  /* SPC300(330) fixed to 10 or 12  depending on
                               the module type  ,
                            SPC401(431) fixed to 12, SPC402(432) fixed to 8, 
                            other SPC modules: 6,8,10,12 bits */
  short ext_latch_delay; /* 0 ..255, SPC130/230: no influence */
  float collect_time;    /* SPC300/330: 0.01s .. 100000s
                            other SPC modules: 0.0001s .. 100000s */
  float display_time;    /* SPC300/330: 0.01   .. 100000s
                            other SPC modules: no influence */
  float repeat_time;     /* SPC300/330: 0.01   .. 100000s
                            other SPC modules: 0.0001s .. 100000s */
  short stop_on_time;    /* 0 (stop) or 1 (no stop) */
  short stop_on_ovfl;    /* 0 (stop) or 1 (no stop) */
  short dither_range;    /* SPC300/330: 0,32,64,128,256
                   other SPC modules: 0=0, 32=1/64, 64=1/32, 128=1/16, 256=1/8*/
  short count_incr;      /* 1 .. 255 */
  short mem_bank;        /* SPC400(130,230,430,600,630): 0 or 1 ,
                            other SPC modules: always 0*/
  short dead_time_comp;  /* SPC300(330) always 1 (on)  
                            other SPC modules: 0 (off) or 1 (on) */
  unsigned short scan_control; /* SPC505(535,506,536) scanning(routing) control word,
                                  other SPC modules always 0 */
  short routing_mode;     /* SPC230 0 (off) or 1 (on) 
                             other SPC modules always 0 */
  float tac_enable_hold;  /* SPC230 10.0 .. 265.0 ns - duration of
                             TAC enable pulse ,other SPC modules always 0 */
  short pci_card_no;      /* module no for PCI module(0-7) or -1 for ISA module */
  unsigned short mode;    /* SPC6(7)XX,other SPC modules not used */
                          /* for SPC7xx      , default 0       
                                0 - normal operation (routing in), 
                                1 - block address out, 2 -  Scan In, 3 - Scan Out 
                             for SPC6xx      , default 0       
                                0 - normal operation (routing in)   
                                2 - FIFO mode 48 bits, 3 - FIFO mode 32 bits  
                             for SPC130      , default 0       
                                0 - normal operation (routing in)   
                                2 - FIFO mode */
  unsigned long scan_size_x;  /* for SPC7xx modules in scanning modes 1 .. 65536, default 1 */
  unsigned long scan_size_y;  /* for SPC7xx modules in scanning modes 1 .. 65536, default 1 */
  unsigned long scan_rout_x;  /* for SPC7xx modules in scanning modes 1 .. 128, default 1 */
  unsigned long scan_rout_y;  /* for SPC7xx modules in scanning modes 1 .. 128, default 1 */
     /* INT(log2(scan_size_x)) + INT(log2(scan_size_y)) + 
        INT(log2(scan_rout_x)) + INT(log2(scan_rout_y)) <= max number of scanning bits
                        max number of scanning bits depends on current adc_resolution:
                                10                       -              12
                                12                       -              10
                                14                       -               8
                                16                       -               6  */
  unsigned short scan_polarity;    /* for SPC7xx modules in scanning modes, default 0 */
                     /* bit 0 - polarity of HSYNC, bit 1 - polarity of VSYNC,
                        bit 2 - pixel clock polarity
                        bit = 0 - falling edge(active low)
                        bit = 1 - rising  edge(active high) */
  unsigned short scan_flyback;   /* for SPC7xx modules in Scan Out or Rout Out mode, default 0 */
                                 /* bits 7-0  Flyback X in number of pixels
                                      bits 15-8 Flyback Y in number of lines */
  unsigned short scan_borders;   /* for SPC7xx modules in Scan In mode, default 0 */
                                 /* bits 7-0  Upper boarder, bits 15-8 Left boarder */
  float pixel_time;    /* pixel time in sec for SPC7xx modules in Scan In mode,
                              50e-9 .. 1.0 , default 200e-9 */
  unsigned short pixel_clock;   /* for SPC7xx modules in Scan In mode, 
                 pixel clock source, 0 - internal,1 - external, default 0 */
  unsigned short line_compression;   /* line compression factor for SPC7xx modules 
                                   in Scan In mode,   1,2,4,8,16,32,64,128, default 1*/
  unsigned short trigger;    /* external trigger condition for SPC6xx,7xx,130 modules - 
                                     none(0),active low(1),active high(2) */
  unsigned long ext_pixclk_div;  /* divider of external pixel clock for SPC7xx modules
                                in Scan In mode, 1 .. 0x3fe, default 1*/
  float rate_count_time;    /* rate counting time in sec  default 1.0 sec
                              for SPC130 can be : 1.0, 250ms, 100ms, 50ms */
  short macro_time_clk;     /*  macro time clock definition for SPC130 in FIFO mode     
                              0 - 50ns (default), 1 - SYNC freq., 2 - 1/2 SYNC freq.,
                              3 - 1/4 SYNC freq., 4 - 1/8 SYNC freq. */
  short add_select;     /* selects ADD signal source: 0 - internal (ADD only), 
                                                      1 - external */
  }SPCIdata;


     /* structure containing SPC adjust parameters stored in EEPROM */
typedef struct _SPCI_Adjust_Para{
  short vrt1;
  short vrt2;
  short vrt3;
  short dith_g;
  float gain_1;
  float gain_2;
  float gain_4;
  float gain_8;
  float tac_r0;
  float tac_r1;
  float tac_r2;
  float tac_r4;
  float tac_r8;
  short sync_div;
  }SPCI_Adjust_Para;


   /* EEPROM data structure */

typedef struct _SPCI_EEP_Data{  /* structure for SPC module EEPROM data  */
  char module_type[16];        /* SPC module type */
  char serial_no[16];          /* SPC module serial number */
  char date[16];               /* SPC module production date */
  SPCI_Adjust_Para adj_para;       /* structure with adjust parameters */
  }SPCI_EEP_Data;


/*- General functions -------------------------------------------------------*/

short   CVICDECL   SPCI_init (char *ini_file);
short   CVICDECL   SPCI_close (void);
short   CVICDECL   SPCI_get_init_status(void);
short   CVICDECL   SPCI_get_parameters(SPCIdata * data);
short   CVICDECL   SPCI_set_parameters(SPCIdata *data);
short   CVICDECL   SPCI_get_parameter(short par_id , float * value);
short   CVICDECL   SPCI_set_parameter(short par_id , float value);
short   CVICDECL   SPCI_configure_memory(short adc_resolution,
                        short no_of_routing_bits, SPCIMemConfig  * mem_info);
short   CVICDECL   SPCI_fill_memory(long block,long page,
                                   unsigned short fill_value);
short   CVICDECL   SPCI_read_data_block(long block,long page,
                             short reduction_factor,short from, short to,
                             unsigned short *data);
short   CVICDECL   SPCI_write_data_block(long block, long page,
                             short from, short to, unsigned short *data);
short   CVICDECL   SPCI_read_data_frame(long frame,long page,
                                    unsigned short *data);
short   CVICDECL   SPCI_read_data_page(long first_page,long last_page,
                                    unsigned short *data);
short   CVICDECL   SPCI_set_page(long page);
short   CVICDECL   SPCI_get_sync_state(short *sync_state);
short   CVICDECL   SPCI_clear_rates(void);
short   CVICDECL   SPCI_read_rates(rate_values *rates);
short   CVICDECL   SPCI_get_time_from_start(float *time);
short   CVICDECL   SPCI_get_break_time(float *time);
short   CVICDECL   SPCI_get_actual_coltime(float *time);
short   CVICDECL   SPCI_test_state(short *state);
short   CVICDECL   SPCI_start_measurement(void);
short   CVICDECL   SPCI_pause_measurement(void);
short   CVICDECL   SPCI_restart_measurement(void);
short   CVICDECL   SPCI_stop_measurement(void);
short   CVICDECL   SPCI_enable_sequencer(short enable);
short   CVICDECL   SPCI_get_sequencer_state(short *state);
short   CVICDECL   SPCI_read_gap_time(float *time);
short   CVICDECL   SPCI_get_eeprom_data(SPCI_EEP_Data *eep_data);
short   CVICDECL   SPCI_write_eeprom_data(unsigned short write_enable,
                                         SPCI_EEP_Data *eep_data);
short   CVICDECL   SPCI_get_adjust_parameters (SPCI_Adjust_Para * adjpara);
short   CVICDECL   SPCI_set_adjust_parameters (SPCI_Adjust_Para * adjpara);
                   // for SPC401,SPC431, SPC6x0, SPC130 modules 
short   CVICDECL   SPCI_read_fifo(unsigned long * count,unsigned short *data);

/*- Low level functions -----------------------------------------------------*/
short   CVICDECL   SPCI_test_id (void);


/*- Miscellaneous -----------------------------------------------------------*/

short   CVICDECL   SPCI_set_mode(short mode);
short   CVICDECL   SPCI_get_mode (void);
short   CVICDECL   SPCI_get_error_string(short error_id, 
                                       char * dest_string, short max_length);
short   CVICDECL   SPCI_close (void);

/*- Functions for using in LabView         -----------------------------------*/
/*-           not needed in C environment  -----------------------------------*/

short   CVICDECL   SPCI_LV_get_eeprom_data(char *module_type,
                     char *serial_no,char *date, SPCI_Adjust_Para * adjpara);

#ifdef __cplusplus
  }
#endif

/*- The End -----------------------------------------------------------------*/
