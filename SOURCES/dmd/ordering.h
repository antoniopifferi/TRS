#ifndef ORDERING_H
#define ORDERING_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//FOR THE RECONSTRUCTION OF THE MEASURE, REMEMBER TO USE THE SAME ALGORITHM USED IN GETBASIS!
//BETTER IF YOU USE SAME FUNCTION!

// QUESTE DUE FUNZIONI NON CI SONO !
//void cake_cutting(const int nBasis, int **matrix);
//int numberOfCakes(int ** matrix,const int rows,const int cols);

/** builds in matrix the Hadamard matrix of order nBasis
note: matrix must be preallocated and nBasis must be power of 2 (it is not verified!) */
void DmdTx_hadamard(short int **matrix, const int nBasis);

/** function to do DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices */
void DmdTx_DFS(short int **M, int row, int col, bool **visited, int ROW, int COL);

/** function that returns count of islands in a given boolean 2D matrix */
int DmdTx_countIslands(short int **M,int ROW, int COL);

/** returns 1 if:
row number is in range, column number is in range and site [row, col] is not yet visited */
int DmdTx_isSafe(short int **M, int row, int col, bool **visited, int ROW, int COL);

/** math function: calculate b^(exp) */
int DmdTx_pow_i_GB(const int b,const int exp);

/** math function: calculate 2^(exp) */
int DmdTx_pow2_i_GB(const int exp);

/** math function: returns the minimum between a and b */
int DmdTx_minimum(const int a, const int b);

#endif
