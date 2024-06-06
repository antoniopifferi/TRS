#include "windows_temp.h"

int win_WriteFile(HANDLE * hSerial, char *command, int str_len, DWORD *bytesWritten)
    {
    return WriteFile(*hSerial, command, str_len, bytesWritten, NULL);
    }
int win_ReadFile(HANDLE * hSerial, char * buffer, int s_buffer,DWORD *bytesRead)
    {
    return ReadFile(*hSerial, buffer, s_buffer, bytesRead, NULL);
    }
