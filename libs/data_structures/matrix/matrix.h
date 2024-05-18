//
// Created by Иван on 08.03.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_MATRIX_H
#define BASICSOFPROGRAMMINGCOURSE_MATRIX_H
#include <stdbool.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix *m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int*, int));

void selectionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int));

bool isSquareMatrix(matrix *m);

bool areTwoMatricesEqual(matrix *m1, matrix *m2);

bool isEMatrix(matrix *m);

bool isSymmetricMatrix(matrix *m);

void transposeSquareMatrix(matrix *m);

void transposeMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols);

int countZeroRows(matrix m);

void swapMinMaxstring(matrix m);

int getMax(int *a, int n);

void sortRowsByMinElement(matrix m);

void inputMatrixF(matrix *m, FILE*  f);

matrix createMatrixFile(FILE *f);

matrix  *createMatrixFromArrayFile(FILE *f,int *n);

void outputArrayF(int a[], const size_t n, const char* sep, FILE* f);

void outputMatrixSquareFile(matrix m, FILE* f);

void outputMatricesSquareFiles(matrix *ms, int nMatrices, FILE* f);

void outputMatrixSquareFBin(matrix m, FILE* f);

void outputMatricesSquareFBin(matrix *ms, int nMatrices, FILE* f);

void inputMatrixFBin(matrix *m, FILE* f);

matrix createMatrixSquareFBin(FILE* f);

matrix* createArrayOfMatricesSquareFBin(FILE* f, int *n);
#endif //BASICSOFPROGRAMMINGCOURSE_MATRIX_H
