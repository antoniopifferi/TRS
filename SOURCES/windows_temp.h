#include<windows.h>

//wrapper functin for writeFile and readFIle of windows.h
int win_WriteFile(HANDLE * hSerial, char *command,int str_len, DWORD *bytesWritten);
int win_ReadFile(HANDLE *hSerial, char * buffer, int s_buffer, DWORD *bytesRead);
 
