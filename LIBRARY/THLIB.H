/* Functions exported by the TimeHarp Driver-DLL   v.3.0   23.2.01 

   Note the following differences from the previous version 2.1:

   - TH_FPGAinit and TH_RegisterInit are now combined in TH_Initialize() 
     which takes no parameters. The I/O address is obtained from
     the Windows Registry. (Device Manager)
   - The library now also supports Windows NT/2000 which requires the
     driver THNTDIO.SYS to be installed and running and the device be
	 configured in the Windows Registry.
   - The Acquisition Time can now be up to 10h

   See the manual for further details
*/

extern int _stdcall TH_GetLibraryVersion(char* vers);
extern int _stdcall TH_Initialize();
extern int _stdcall TH_GetHardwareVersion(char* vers);
extern int _stdcall TH_GetBaseResolution();
extern int _stdcall TH_Calibrate();

extern int _stdcall TH_SetCFDDiscrMin(int value);
extern int _stdcall TH_SetCFDZeroCross(int value);
extern int _stdcall TH_SetSyncLevel(int value);
extern int _stdcall TH_SetRange(int range);
extern int _stdcall TH_SetOffset(int offset);
extern int _stdcall TH_NextOffset(int direction);
extern int _stdcall TH_SetStopOverflow(int stop_ovfl);

extern int _stdcall TH_ClearHistMem();
extern int _stdcall TH_SetMMode(int mmode, int tacq);
extern int _stdcall TH_StartMeas();
extern int _stdcall TH_StopMeas();
extern int _stdcall TH_CTCStatus();
extern int _stdcall TH_SetSyncMode();

extern long int _stdcall TH_GetBlock(unsigned long *chcount);
extern float _stdcall TH_GetResolution();
extern long int _stdcall TH_GetCountRate();
extern int _stdcall TH_GetFlags();

//these are for continuous mode
extern int _stdcall TH_GetBank(unsigned short *buffer, int chanfrom, int chanto);
extern int _stdcall TH_GetLostBlocks();
