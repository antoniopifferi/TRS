//#include "extcode.h"		// MODIFIED TO AVOID extcode.h  
#pragma pack(push)
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * TRS_CLOSE
 */
uint32_t __cdecl TRS_CLOSE(uint64_t *Handle_In, 
	uint32_t Total_Registers_In[], int32_t Total_Registers_In_Length);
/*!
 * TRS_INIT
 */
uint32_t __cdecl TRS_INIT(uint64_t *Handle_Out, 
	uint32_t Total_Registers_Out[], int32_t Total_Registers_Out_Length);
/*!
 * TRS_LASER
 */
uint32_t __cdecl TRS_LASER(uint64_t *Handle_In, 
	uint32_t Total_Registers_In[], uint32_t Total_Registers_Out[], 
	int32_t Total_Registers_In_Length, int32_t Total_Registers_Out_Length, 
	uint32_t ON_nOFF);
/*!
 * TRS_CTRS
 */
uint32_t __cdecl TRS_CTRS(uint64_t *Handle_In, uint32_t Counts[], 
	int32_t Counts_Length);
/*!
 * TRS_ACQ
 */
uint32_t __cdecl TRS_ACQ(uint64_t *Handle_In, uint32_t Histogram_1[], 
	uint32_t Histogram_2[], int32_t Histogram_1_Length, 
	int32_t Histogram_2_Length, uint32_t Stats_1[], uint32_t Stats_2[], 
	int32_t Stats_1_Length, int32_t Stats_2_Length, uint32_t *Mem_Bank, 
	uint32_t *Laser_Ch, uint32_t *Meas_Index);
/*!
 * TRS_WATTEN
 */
uint32_t __cdecl TRS_WATTEN(uint64_t *Handle_In, 
	uint32_t Total_Registers_In[], uint32_t Total_Registers_Out[], 
	int32_t Total_Registers_In_Length, int32_t Total_Registers_Out_Length, 
	uint32_t Attenuator_Index, uint32_t Motor_Command, uint32_t Value);
/*!
 * TRS_RATTEN
 */
uint32_t __cdecl TRS_RATTEN(uint64_t *Handle_In, uint32_t Attenuator_Index, 
	uint32_t *Attenuator_Status);
/*!
 * TRS_MAP
 */
uint32_t __cdecl TRS_MAP(uint64_t *Handle_In, uint32_t Total_Registers_In[], 
	uint32_t Total_Registers_Out[], int32_t Total_Registers_In_Length, 
	int32_t Total_Registers_Out_Length, uint32_t Auto_Cmd[], 
	int32_t Auto_Cmd_Length, uint32_t Auto_ITime[], int32_t Auto_ITime_Length);
/*!
 * TRS_MEAS
 */
uint32_t __cdecl TRS_MEAS(uint64_t *Handle_In, uint32_t Total_Registers_In[], 
	uint32_t Total_Registers_Out[], int32_t Total_Registers_In_Length, 
	int32_t Total_Registers_Out_Length, uint32_t Meas_Cmd);
/*!
 * TRS_SET
 */
uint32_t __cdecl TRS_SET(uint64_t *Handle_In, uint32_t Total_Registers_In[], 
	uint32_t Total_Registers_Out[], int32_t Total_Registers_In_Length, 
	int32_t Total_Registers_Out_Length, uint32_t Ctrs_ITime, 
	uint32_t Man_Wavelength, uint32_t Man_ITime, uint32_t Sync_Rate);

//MgErr __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);
int32_t __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module); // MODIFIED TO AVOID extcode.h    

#ifdef __cplusplus
} // extern "C"
#endif

#pragma pack(pop)

