//**************************************************************************
//* FILE     : W32NII3E.H
//* FUNCTION : Include file to build W32NII3E.DLL
//**************************************************************************
#define FRANCAIS                1
#define ENGLISH                 2

#define LF_TERMIN               1
#define CR_TERMIN               2
#define LFCR_TERMIN             3
#define CRLF_TERMIN             4

#define  MAXSIZE                255    // Buffer's size

//----------------------------------------------------------------------------------
// Error codes definition.
//----------------------------------------------------------------------------------

#define USER_ERROR_CODE   0x20000000
#define COMM_OK           0                     // Function OK.
#define COMM_NOT_OK       USER_ERROR_CODE + 1   // Communication error.
#define COMM_NOT_OPEN     USER_ERROR_CODE + 2   // Port not open.
#define COMM_TIME_OUT     USER_ERROR_CODE + 3   // Time Out expired.  
#define COMM_NOT_DLL      USER_ERROR_CODE + 4   // DLL not find.
#define COMM_OPEN         USER_ERROR_CODE + 5   // Port already open.
#define ERR_AXIS_NUMBER   USER_ERROR_CODE + 6

// Error Messages Returned in Global Variable iberr

#define NI_I3E_EDVR  100   //* DOS error.
#define NI_I3E_ECIC  101   //* Function requires GPIB board to be CIC.
#define NI_I3E_ENOL  102   //* Write function detected no Listeners.
#define NI_I3E_EADR  103   //* Interface board not addressed correctly.
#define NI_I3E_EARG  104   //* Invalid argument to function call.
#define NI_I3E_ESAC  105   //* Function requires GPIB board to be SAC.
#define NI_I3E_EABO  106   //* I/O operation aborted.
#define NI_I3E_ENEB  107   //* Non-existent interface board.
#define NI_I3E_EDMA  108   //* DMA error
#define NI_I3E_EOIP  110   //* I/O operation started before previous.
#define NI_I3E_ECAP  111   //* No capability for intended operation.
#define NI_I3E_EFSO  112   //* File system operation error.
#define NI_I3E_EBUS  114   //* Command error during device call.
#define NI_I3E_ESTB  115   //* Serial poll status byte lost.
#define NI_I3E_ESRQ  116   //* SRQ remains asserted.
#define NI_I3E_ETAB  120   //* The return buffer is full.
#define NI_I3E_BADR  130   //* Bad device address.
#define NI_I3E_EOS   131   //* Bad string terminator.

#ifndef DLL
#define DLL _declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
 {
#endif
    int __stdcall  NI_PortOpen  	      (int Terminator, int Device, int Srq);
    int __stdcall  NI_PortClose           (void);
    int __stdcall  NI_SendCommand         (char *SendMessage);
    int __stdcall  NI_SendAndWaitResponse (char *SendMessage, char *Response, int *Length);
    int __stdcall  NI_ReadMessage         (char *Response, int *Length);
    int __stdcall  NI_SetTimeOut          (double TimeOutInSeconds);
    int __stdcall  NI_GetExtendedError    (int ErrorCode, char *Response);
    int __stdcall  NI_TellDLLVersion      (char *Response);
#ifdef __cplusplus
 }
#endif
