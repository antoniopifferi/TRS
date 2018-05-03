//#include "extcode.h"		// MODIFIED TO AVOID extcode.h  
#pragma pack(push)
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * NIRS_OPEN
 */
uint32_t __cdecl NIRS_OPEN(uint32_t *Handle, uint32_t Registers_Out[], 
	int32_t Registers_Out_Length);
/*!
 * NIRS_CLOSE
 */
uint32_t __cdecl NIRS_CLOSE(uint32_t *Handle);
/*!
 * NIRS_ON
 */
uint32_t __cdecl NIRS_ON(uint32_t *Handle, uint32_t Registers_In[], 
	uint32_t Registers_Out[], int32_t Registers_In_Length, 
	int32_t Registers_Out_Length, uint32_t ON_nOFF);
/*!
 * NIRS_SET
 */
uint32_t __cdecl NIRS_SET(uint32_t *Handle, uint32_t Registers_In[], 
	uint32_t Registers_Out[], int32_t Registers_In_Length, 
	int32_t Registers_Out_Length, uint32_t Frequency, uint32_t Time, 
	uint32_t Wavelength);
/*!
 * NIRS_ACQ
 */
uint32_t __cdecl NIRS_ACQ(uint32_t *Handle, uint32_t Histogram[], 
	uint32_t Stats[], int32_t Histogram_Length, int32_t Stats_Length, 
	uint32_t *Bank);
/*!
 * NIRS_LASER
 */
uint32_t __cdecl NIRS_LASER(uint32_t *Handle, uint32_t Registers_In[], 
	uint32_t Registers_Out[], int32_t Registers_In_Length, 
	int32_t Registers_Out_Length, uint32_t ON_nOFF);
/*!
 * NIRS_MEASURE
 */
uint32_t __cdecl NIRS_MEASURE(uint32_t *Handle, uint32_t Registers_In[], 
	uint32_t Registers_Out[], int32_t Registers_In_Length, 
	int32_t Registers_Out_Length, uint32_t ON_nOFF);

//MgErr __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);
int32_t __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module); // MODIFIED TO AVOID extcode.h

#ifdef __cplusplus
} // extern "C"
#endif

#pragma pack(pop)

