//
// Created by Иван on 08.03.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_MATRIX_H
#define BASICSOFPROGRAMMINGCOURSE_MATRIX_H
#include <stdbool.h>
#include <limits.h>
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

int getMin(int *a, int n);

void sortColsByMinElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

void fillRowCriteriaArray(matrix  m, int *criteria_array, int (*criteria)(int*, int));

void fillRowCriteriaArrayL(matrix  m, long long *criteria_array, long long (*criteria)(int*, int));

void transposeIfMatrixHasNotEqualSumOfRows(matrix *m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

float getDistance(int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                             float (*criteria)(int *, int));

void sortByDistances(matrix m);

int cmp_long_long(const void *pa, const void *pb);

int countNUnique(int *a, int n);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

position getLeftMin(matrix m);

void swapPenultimateRow(matrix m);

bool isNonDescendingSorted(int *a, int n);

bool hasAllNonDescendingRows(matrix m);

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);


#endif //BASICSOFPROGRAMMINGCOURSE_MATRIX_H
