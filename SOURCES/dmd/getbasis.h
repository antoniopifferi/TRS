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
void getBasis(const int hadamard_raster, const int dim, const int *idx, const int szIdx, int compressImage, int zoom, int xCenter, int yCenter, unsigned char ***output);

/** generates and puts in basis the Hadamard bases of size nBasis */
void getBasisHadamard(const int nBasis, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** implementation of cake-cutting for ordering Hadamard bases */
void ordering(short int **H, const int nBasis, const int *idx, const int szIdx);

/** reads a .txt file containing Hadamard matrices
note: the file must be under \basis directory and calles nBasis.txt (e.g. 32.txt)
come deve essere il file ? */
void getBasisHadamardFromTxt(short int **H, const int nBasis, const int *idx, const int szIdx);

/** generates a pattern for raster scan
dim is the width in pixels of the opened line */
void getBasisRaster(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates a pattern of all ones (all mirrors oriented to detector) */
void getBasisOnes(const int sz, unsigned char ***basis);

/** generates a pattern of all zeros (all mirrors closed) */
void getBasisZeros(const int sz, unsigned char ***basis);

/** generates a pattern for notch filter
dim is the width of the closed line (opposite to raster) */
void getBasisNotchFilter(const int *idx, const int dim, unsigned char ***basis);

/** generates Hadamard pattern (Horizontal) */
void getBasisHadamardHorizontal(const int nBasis, const int *idx, const int szIdx, int compressImage, unsigned char ***basis);

/** generates pattern for Raster scan (Horizontal) */
void getBasisRasterHorizontal(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates a pattern adding at each measurement a line of "dim" pixels (Horizontal) */
void getBasisAddOneLineHorizontal(const int dim, const int *idx, const int szIdx, int compressImage, unsigned char ***basis);

/** generates a pattern for a band pass filter
all opened until dim, other closed */
void getBasisBandPass(const int *idx, const int dim, unsigned char ***basis);

/** generates a pattern adding a line of n="dim" pixels at each measurement */
void getBasisAddOneLineObli(const int dim, const int *idx, const int szIdx,int compressImage, unsigned char ***basis);

/** generates 2D pattern with Hadamard basis for image reconstruction */
void getBasisHadamard2D(const int nBasis, const int *idx, const int szIdx, const int zoom, const int xc, const int yc, unsigned char ***basis );

/* some support functions */
/** returns how many digits the number n has */
int nDigit(int n);
/** converts the number n into a string */
char *intToString(int n);
/** concatenates strings a, b and c (a+b+c) */
char *concatenate(char *a, char *b, char *c);

#endif
