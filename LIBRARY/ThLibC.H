/* Functions exported by the TimeHarp Driver-DLL */

int TH_GetLibraryVersion(char* vers);
int TH_GetHardwareVersion(char* vers);
int TH_GetBaseResolution(void);

//**int TH_FPGAInit(int IOBase);
//**int TH_RegisterInit(void);
/**/int TH_Initialize(void);
/**/int TH_Calibrate(void);

int TH_SetCFDDiscrMin(int value);
int TH_SetCFDZeroCross(int value);
int TH_SetSyncLevel(int value);
int TH_SetRange(int range);
int TH_SetOffset(int offset);
int TH_NextOffset(int direction);

int TH_ClearHistMem(void);
int TH_SetMMode(int mmode, int tacq);
int TH_StartMeas(void);
int TH_StopMeas(void);
int TH_CTCStatus(void);
int TH_SetSyncMode(void);

long int TH_GetBlock(unsigned long *chcount);
float TH_GetResolution(void);
long int TH_GetCountRate(void);
int TH_GetFlags(void);
