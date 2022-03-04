\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
DLLs for the SOLUS BCD test board
Alpha version
Author: Enrico Conca
Politecnico di Milano - SPADlab

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Basic_test
This function can be used to check if the DLL is compiled correctly.
You should pass an empty array of uint32_t of size 256 (or greater).
The content of that array will be overwritten by an increasing sequence of numbers up until the value "Input".
"len" needs to be always 256.
"Output" will be set equal to "Input".

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Startup
This function:
- enables communication to the FPGA board
- initializes all voltages
- turns on the detector IC
- configures the TDC and the various internal registers.
It expects to find a file named "TDC_calibration.dat" in the main program folder. This file contains the configuration of the TDC.
After this function returns, the array is set with one pixel active and it is possible to call the Get_Histogram function.
It provides the handle necessary for the other functions.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Get_Histogram
This function acquires a histogram from the detector.
You should pass an empty array of uint32_t of size 256 (or greater).
The content of that array will be overwritten by the acquired histogram.
"len" needs to be always 256.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Get_Histogram_set_integration
This function triggers an acquisition of duration equal to "IntegrationUs" microseconds
and returns the corresponding histogram. This function is locking for the duration of the acquisition.
Maximum integration time = 100 ms
You should pass an empty array of uint32_t of size 256 (or greater).
The content of that array will be overwritten by the acquired histogram.
"len" needs to be always 256.


\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Gating config
This function sets the position of:
- the gate window rising edge according to "OPEN" and "OPEN_fine"
- the gate window falling edge according to "CLOSE" and "CLOSE_fine"
- the delay of the TDC STOP signal according to "STOP" and "STOP_fine"

  according to the following formula: position (ns) = "VALUE" * 1.28 + "VALUE_fine" * 0.1

- the quadrants enabled according to the following configuration:
	0b0000ABCD
	      A -> enables South-East quadrant
	       B -> enables North-East quadrant
	        C -> enables North-West quadrant
	         D -> enables South-West quadrant
  It is suggested to leave all quadrants enabled at all time ( 0b00001111 or decimal 15 value).

- the strength of the SPAD reset transistors according to the value of RSTDuration (1 slowest, 2 medium, 3 fastest)

- the inhibition of the gate signal generation during TDC conversion according to the value of LOWPower
  (false = gate signal generated all the time)

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
SetPixels
This function enables the pixels according to the ranking present in the file at path "PixelsOrder"
and the value of the parameter Threshold.
Pixel "i" is enabled if in the file "PixelsOrder" the i-th row contains a number lower than "threshold".

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Load_pixel_order
This function reads the pixel sequence file and returns an array size len=2048 to be used in the function "SetPixels_fast"

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
SetPixels_fast
This function enables the pixels according to the ranking present in the array populated by Load_pixel_order
and the value of the parameter Threshold.
Pixel "i" is enabled if in the file "PixelsOrder" the i-th row contains a number lower than "threshold".


\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Shutdown_DLL
This function turns off the detector and closes the communication to the FPGA board.