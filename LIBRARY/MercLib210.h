//------------------------------------------
// File     : MercLib210.h 
// Date     : 2001-12-02
//  
//------------------------------------------

// add this include when using CVI
#include <cvidef.h>  

#ifdef __cplusplus
    extern "C" {
#endif

// This is the header to use the Mercury DLL functions with CVI
// To use the DLL, include the static import
// library MercLib200_cvi.lib into the project

// The same header also can be used with VC++


//-----------------------------------
// types
//-----------------------------------
typedef unsigned char BYTE;
//XYZ CONFLICT typedef unsigned int WORD;

//-----------------------------------
// terminator characters
//-----------------------------------
#define LF 0x10;
#define CR 0x13;

//-----------------------------------
// Error Base Codes
//-----------------------------------
#define EBC_init         16;
#define EBC_setBuffer    32;
#define EBC_EOF          48;
#define EBC_getChar      64;
#define EBC_getstring    80;
#define EBC_sendChar     96;
#define EBC_sendstring  112;
#define EBC_sendstringE 128;

//-----------------------------------
// Error offset codes
//-----------------------------------
#define ERR_readfile     1;
#define ERR_writefile    2;
#define ERR_timeout      3;
#define ERR_length       4;
#define ERR_content      5;
#define ERR_GetCommState 6;
#define ERR_SetCommState 7;
#define ERR_PurgeComm    8;
#define ERR_PortNumber   9;
#define ERR_handle      10;

//-----------------------------------
// Functions 
//-----------------------------------
int __stdcall MCRS_open(BYTE PortNumber, int baudrate);
int __stdcall MCRS_close(void);
int __stdcall MCRS_setBuffer(void);
WORD __stdcall MCRS_EOF(void);
int __stdcall MCRS_clear_input(void);
int __stdcall MCRS_sendChar(char *character);
int __stdcall MCRS_sendString(char *command_string);
int __stdcall MCRS_moveA(int axis, int position);
int __stdcall MCRS_moveR(int axis, int shift);
int __stdcall MCRS_getChar(char *character);
int __stdcall MCRS_getString(char *report, WORD count);
int __stdcall MCRS_getStringCR(char *report);
int __stdcall MCRS_getMacro(int macno,char *report);
int __stdcall MCRS_getPos(void);
int __stdcall MCRS_getPosErr(void);
int __stdcall MCRS_getVal(int query);
int __stdcall MCRS_getQuery(char *command, char *report);
int __stdcall MCRS_moving(void);
int __stdcall MCRS_waitStop(void);
int __stdcall MCRS_getSTB(int bytenumber);
int __stdcall MCRS_getDLLversion(void);
int __stdcall MCRS_initNetwork(int maxAxis);
int __stdcall MCRS_select(int newAxis);
int __stdcall MCRS_set_device(int newAxis);

#ifdef __cplusplus 
}
#endif



