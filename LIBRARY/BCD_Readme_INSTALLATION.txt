POCEDURE TO INSTALL A NEW DLL VERSION:
- Copy New SOLUS_BCD.zip -> PROGRAMS\SOLUS_BCD
- Unpack .zip and copy files  -> PROGRAMS\SOLUS_BCD\SOURCE
- Open directory PROGRAMS\SOLUS_BCD\SOURCE
- Copy SOLUS_BCD.dll -> TRS
- Copy SOLUS_BCD.lib -> TRS\LIBRARY
- Copy SOLUS_BCD.h   -> TRS\LIBRARY
- Copy SOLUS_BCD.ini -> TRS\INI
- Copy README.txt -> TRS\DOC and rename in SOLUS_BCD_README.txt
- Comment first line in SOLUS_BCD.h: //#include "extcode.h"
- Unload and Reload SOLUS_BCD.lib from LabWindows TRS
- Recompile and debug

 