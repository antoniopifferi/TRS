#ifndef DMD_H
#define DMD_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 65
#define SIZE_SEND 65
#define WIDTH 1920
#define HEIGHT 1080
#define SIZE_PATTERN 24
#define SIZE_BUFFER 2049

#define DEBUG false                 // if true, the program works when the device is disconnected. The bytes are written on .txt files
#define DMD_SIMULATOR false         // if true, create a series of .txt files with the patterns for the dmd
#define PRINT_BYTES false           // if DEBUG = true and PRINT_BYTES = true, print bytes on command window
#define REMEMBER_PREVIUS_POS true
#define BATCHES false               // if false, only 1 batch is created (sizeBatch = nMeas)
                                    /*  the program allows the division of a single measure in separate batches
                                     *  the DMD can get up to 256 bases it is needed to separate in two batches if you want to use more than 256 bases
                                     *  it is no needed if you use max 256 bases
                                     */

#include "hidapi/hidapi.h"

/* STRUTTURE DICHIARATE IN MEASURE

struct DmdTx_Node{
	unsigned char data;
	struct DmdTx_Node *next;
};
struct DmdTx_List{
	int *data;
	struct DmdTx_List *next;
};

// This structure contains all the data about the patterns to be sent to the dmd 
struct DmdTx_Patterns{
	unsigned char (*defPatterns)[12]; // pattern settings (exposure time, bit-depth, triggers, pattern index...)
	unsigned char configureLut[6]; // configuration of Look up table (LUT)
	unsigned char (*setBmp)[6]; // image settings (index, size)
	unsigned char ***bmpLoad; // compressed BMP image to load
	int nB;
	int *packNum; // number of data packets (max 504 bytes) to be loaded
	int nEl;
	int **bitsPackNum; // size of each packet
	int *exposure;
	int numOfBatches;
};
*/


/* unused (all at the end of .c file) */
//int command(hid_device *handle, const char mode, const char sequencebyte, const char com2, const char com1, const int *data, const int sizeData);
//int newEncodeDMDScopeFoundary(int ***image, struct Node **bitString);
//void commandPattern(hid_device *handle, struct Patterns * pattern, const int szPattern);
//void checkForErrors(hid_device *handle);

/** write on .txt file (for debug when DMD is not connected) */
void DmdTx_writeOnFile(char *fileName, unsigned char *data, int size);

/** same of writeOnFile but with (int) data variable (used only in defSequence) */
void DmdTx_writeOnFile_int(char *fileName, int data [], int size);

/** This function converts a number "a" into a bit string of  length "l"
note: should be a < 2^l (it is not verified) */
char * DmdTx_convlen(int a, int l);

/** convert a string of bits in an array of char "a" in bytes (number 0 - 255)
returns the reference to the last byte converted
note: size is assumed to be multiple of 8, no controls are done
remember to free bytes after calling the function */
int * DmdTx_bitsToBytes(const char *a, const int size);

/** function to write data in the DMD buffer
for more informations look at the ti DLPC900 Programmer's Guide */
int DmdTx_talkDMD_char(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const unsigned char *data, const int sizeData);

/** same to talkDMD_char but data are in int format
a conversion to char is performed and (char)data are passed to talkDMD_char */
int DmdTx_talkDMD_int(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const int *data, const int sizeData);

/** changes the internal image processing function of the DMD
see DMD Programmer's Guide pag. 58 */
void DmdTx_changeMode(hid_device *handle, int mode);

/** function tells the DMD to stop the pattern display sequence (next start command restart from the beginning)
see DMD Programmer's Guide pag. 69 */
void DmdTx_stopSequence(hid_device *handle);

/** function tells the DMD to start reproducing the pattern sequence stored in memory
see DMD Programmer's Guide pag. 69 */
void DmdTx_startSequence(hid_device *handle);

/** performs a software reset of the DMD, USB connection must be reestablished before sending new file
see DMD Programmer's Guide pag. 32-33 */
void DmdTx_reset(hid_device *handle);

/** retrieve the error number code from the DMD
see DMD Programmer's Guide pag. 23 */
void DmdTx_checkForErrors(hid_device *handle);

/** retrieve the error message string from the DMD
see DMD Programmer's Guide pag. 23 */
void DmdTx_checkErrorMessage(hid_device *handle);

/* function to send data to the DMD (same to talk_DMD) UNUSED*/
//int DmdTx_command(hid_device *handle, const char mode, const char sequencebyte, const char com1, const char com2, const char *data, const int sizeData);

/** configure the LUT for setting the sequence of patterns
p. 71 DLPC900 Programmer's guide (LUT configuration) */
void DmdTx_configureLut(struct DmdTx_Patterns *pattern, int size, int rep);

/** to process the image we need to compress it to a 3D 8bit array such that we can encode in each bit a pixel of an image,
we can store here 24 images.
It is the reason why I go on a step of 24 for uploading the images */
void DmdTx_mergeImages(unsigned char ***images, unsigned char ***res);

/** It defines the characteristic of a single pattern. (exposure time, bit-depth, triggers, pattern index...)
p.74 DLPC900 Programmer's guide */
void DmdTx_definePatterns(struct DmdTx_Patterns *pattern,const int index,const int exposure,const int bitdepth, const char *color,const int triggerIn,const int darkTime,const int triggerout,const int patInd,const int bitpos);

/** all the information useful for showing the patterns is produced here.
it requires only what pattern, the exposure and if triggers need to be presents */
void DmdTx_defSequence(struct DmdTx_Patterns *pattern, unsigned char ***matrixes, int *exposure, int *trigger_in, int dark_time, int *trigger_out, int repetition, const int size);

/** function to push data in LIFO structure */
void DmdTx_push(struct DmdTx_Node **head, unsigned char data);

/** given a number of elements "nEl" in a batch,
the function allocates memory for storing the pattern and save its addresses in struct Patterns*/
void DmdTx_allocatePattern(struct DmdTx_Patterns *p, int nEl);

/** function for eRLE to verify if planes of mergedImages are equal
return 0 if they are not equal
return 1 if they are equal */
int DmdTx_isRowEqual(const unsigned char *a, const unsigned char *b);

/** sets parameters (index and number of bytes) for image (group of patterns)
p. 75 DLPC900 Programmer's guide (initialize BMP Load) */
void DmdTx_setBmp(struct DmdTx_Patterns *pattern, const int  index, const int size);

/** load (or load to Patterns) the encoded image to the DMD
p. 75-76 DLPC900 Programmer's guide */
void DmdTx_bmpLoad(struct DmdTx_Patterns *pattern, const int index, const unsigned char *image, const int size);

/** This function encodes the images into something the dmd is able to read.
This function is the translation into C of the function "encode" present in https://github.com/csi-dcsc/Pycrafter6500
It uses a method called enhanced run lenght encoding described in the programming manual of the DMD6500/DMD9000
p.62 DLPC900 Programmer's Guide */
int DmdTx_newEncode2(unsigned char ***image, struct DmdTx_Node **n);

/** take data of the pattern from txt file */
int DmdTx_takeFromTxt(struct DmdTx_Node **bitString);

/** function to create a pattern from a 24-bit bmp image (note: only one color channel is read) */
void DmdTx_readBMP(char *filename, int *** image);

/* basic mathematical functions */
int DmdTx_pow2_i(const int exp);
int DmdTx_pow_i(const int b, const int exp);    // these are in ordering.c
int DmdTx_celing(const int a, const int b);

#endif

