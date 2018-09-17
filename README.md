TRS


_LUCA and _NIRS_BOX instance
1) modify in measure.h the #define _LUCA or #define _NIRS
2) load the LUCA_TRS.lib and NIRS_DLL_v2.lib libraries in the LabWindows Project

SPCM Board by b&h
1) Check environment: 32=both Windows and TRS at 32bit, 32x64=Windows @64 TRS@32 bit,  64=both Windows and TRS at 64bit
2) load the corresponding library in the LabWindows Project (e.g. SPCM32.lib, SPCM32x64.lib, SPCM64.lib) and verify date or versione
3) check or copy the corresponding .DLL file in the TRS forlder, with same name and version of the library (For TR17.1 version is 4.0 dated 2015)
