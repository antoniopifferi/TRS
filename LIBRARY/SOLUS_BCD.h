//#include "extcode.h"
#pragma pack(push)
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
	int32_t dimSizes[2];
	LVBoolean elt[1];
} LVBooleanArrayBase;
typedef LVBooleanArrayBase **LVBooleanArray;

/*!
 * Gating_config
 */
void __cdecl Gating_config(uint8_t STOP, uint8_t CLOSE_fine, uint8_t CLOSE, 
	uint8_t OPENFine, uint8_t STOP_fine, uint8_t OPEN, uint8_t Quadrants, 
	uint8_t RSTDuration, LVBoolean LOWPower, uint32_t HandleIN, 
	LVBoolean *STATUS, uint32_t *HandleOUT);
/*!
 * Get_Histogram
 */
 // Histogram should be an array of 256 elements
 // "len" should be 256
void __cdecl Get_Histogram(uint32_t HandleIN, LVBoolean *STATUS, 
	uint32_t *HandleOUT, uint32_t *COUNTS, uint32_t Histogram[], int32_t len);
/*!
 * SetPixels
 */
 //"Path" should point to the file where the pixel priorities are listed
void __cdecl SetPixels(uint32_t HandleIN, uint32_t Threshold, 
	Path *PixelsOrder, LVBooleanArray *SETMap, uint32_t *HandleOUT, 
	LVBoolean *STATUS);
/*!
 * Shutdown_DLL
 */
void __cdecl Shutdown_DLL(uint32_t HandleIN);
/*!
 * Startup
 */
 //typ values:
 // VDD_CORE = 1.85
 // VDDD_CORE = 5
 // VDD_CK = 1.85
 // VHIGH = 30.4
void __cdecl Startup(double VDD_CORE, double VDDD_CORE, double VDD_CK, 
	double VHIGH, LVBoolean *Status, uint32_t *Handle);
/*!
 * Basic_test
 */
 //Simple debug function
 //Returns an array of 256 elements
 //where the elements of position 0 to "Input" contain increasing numbers
 //"Output" should be equal to "Input"
void __cdecl Basic_test(uint32_t Input, uint32_t *Output, 
	uint32_t OUT_ARRAY[], int32_t len);

MgErr __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);

/*
* Memory Allocation/Resize/Deallocation APIs for type 'LVBooleanArray'
*/
LVBooleanArray __cdecl AllocateLVBooleanArray (int32 *dimSizeArr);
MgErr __cdecl ResizeLVBooleanArray (LVBooleanArray *hdlPtr, int32 *dimSizeArr);
MgErr __cdecl DeAllocateLVBooleanArray (LVBooleanArray *hdlPtr);

void __cdecl SetExecuteVIsInPrivateExecutionSystem(Bool32 value);

#ifdef __cplusplus
} // extern "C"
#endif

#pragma pack(pop)

