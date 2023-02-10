#pragma once

#ifdef GETBASISDLL_EXPORTS
#define GETBASIS_DLL_API __declspec(dllexport)
#else 
#define GETBASIS_DLL_API __declspec(dllimport)
#endif

#ifndef GETBASIS_H
#define GETBASIS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "ordering.h"

#define WIDTH 1920
#define HEIGHT 1080
#define SIZE_BUFFER 2049

/** readdress to other getbasis functions according to hadamard_raster parameter
 dim: in hadamard mode is the dimension of the hadamard basis, in raster scan mode is the dimension of the line
 idx: is the index of basis or raster to be calculated */
GETBASIS_DLL_API void DmdTx_getBasis(const int hadamard_raster, const int dim, const int *idx, const int szIdx, int compressImage, int zoom, int xCenter, int yCenter, int csMode, unsigned char ***output);

/** generates and puts in basis the Hadamard bases of size nBasis */
GETBASIS_DLL_API void DmdTx_getBasisHadamard(const int nBasis, const int *idx, const int szIdx,int compressImage, int csMode, unsigned char ***basis);

/** implementation of cake-cutting for ordering Hadamard bases */
GETBASIS_DLL_API void DmdTx_ordering(short int **H, const int nBasis, const int *idx, int rows, int cols, const int szIdx);

/** reads a .txt file containing Hadamard matrices
note: the file must be under \basis directory and calles nBasis.txt (e.g. 32.txt)
come deve essere il file ? */
GETBASIS_DLL_API void DmdTx_getBasisHadamardFromTxt(short int **H, const int nBasis, const int *idx, const int szIdx);

/** generates a pattern for raster scan
dim is the width in pixels of the opened line */
GETBASIS_DLL_API void DmdTx_getBasisRaster(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates a pattern of all ones (all mirrors oriented to detector) */
GETBASIS_DLL_API void DmdTx_getBasisOnes(const int sz, unsigned char ***basis);

/** generates a pattern of all zeros (all mirrors closed) */
GETBASIS_DLL_API void DmdTx_getBasisZeros(const int sz, unsigned char ***basis);

/** generates a pattern for notch filter
dim is the width of the closed line (opposite to raster) */
GETBASIS_DLL_API void DmdTx_getBasisNotchFilter(const int *idx, const int dim, unsigned char ***basis);

/** generates Hadamard pattern (Horizontal) */
GETBASIS_DLL_API void DmdTx_getBasisHadamardHorizontal(const int nBasis, const int *idx, const int szIdx, int compressImage, int csMode, unsigned char ***basis);

/** generates pattern for Raster scan (Horizontal) */
GETBASIS_DLL_API void DmdTx_getBasisRasterHorizontal(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates a pattern adding at each measurement a line of "dim" pixels (Horizontal) */
GETBASIS_DLL_API void DmdTx_getBasisAddOneLineHorizontal(const int dim, const int *idx, const int szIdx, int compressImage, unsigned char ***basis);

/** generates a pattern for a band pass filter
all opened until dim, other closed */
GETBASIS_DLL_API void DmdTx_getBasisBandPass(const int *idx, const int dim, unsigned char ***basis);

/** generates a pattern adding a line of n="dim" pixels at each measurement */
GETBASIS_DLL_API void DmdTx_getBasisAddOneLineObli(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates 2D pattern with Hadamard basis for image reconstruction */
GETBASIS_DLL_API void DmdTx_getBasisHadamard2D(const int nBasis, const int *idx, const int szIdx, const int zoom, const int xc, const int yc, int csMode, unsigned char ***basis );

/* some support functions */
/** returns how many digits the number n has */
GETBASIS_DLL_API int DmdTx_nDigit(int n);
/** converts the number n into a string */
GETBASIS_DLL_API char * DmdTx_intToString(int n);
/** concatenates strings a, b and c (a+b+c) */
GETBASIS_DLL_API char * DmdTx_concatenate(char *a, char *b, char *c);

#endif
