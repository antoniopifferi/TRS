----------------------------------------------------
-- SOLUS-SDK	0.3.0		July 2019
----------------------------------------------------

In order to use the SOLUS-SDK:
- install on your PC launching setup.exe. This will create a folder with the following structure and a desktop link to it:
	driver		-->	device driver
	examples	-->	compiled bin, source code and Visual Studio 2015 project for test application
	lib		-->	required shared libs 
	include		-->	required header file
- if on your PC there are no FTDI drivers, install them using the installer in the driver folder

If you are developing software with no SOLUS probe connected, you can use the libraries provided in the folder "Libraries for no Hardware", which bypass any connection check and does not perform any actual communication.

System requirements:
Windows 10
It may work on previous version but it was not tested.

Special note:
This a pre-release version of the SOLUS-SDK. Its purpose is to let users familiarise with the SDK functions.
The final release will be as similar as possible to this one, but some minor modifications to function parameters and behaviour may be introduced. If not strictly necessary, backward compatibility will be preserved but it is not guaranteed. In case of breaking changes, they will be reported in the release note.

