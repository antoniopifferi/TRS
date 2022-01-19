// Patch file needed to overcome definitions of types
// YOU NEED to comment/remove #include "extcode.h" from SOLUS_BCD.h

#ifndef SOLUS_BCD_MOD	// MOD
#define SOLUS_BCD_MOD	// MOD
#define int32		int32_t		 
#define MgErr		int32_t		 
#define LVBoolean	uint8_t
#define Bool32		int32_t		 
#define Path		char* // dubious

#include "SOLUS_BCD.h"

#undef int32	 
#undef MgErr	 
//#undef LVBoolean // NEEDED to keep this type for use in Measure.c
#undef Bool32	 
#undef Path
//#undef SOLUS_BCD_MOD
#endif // MOD end of #define
