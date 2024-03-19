#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "data_structures/array/array.h"

//размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

//Возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols){
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

// освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m){
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
    free(m->values);
    m->nRows = 0;
    m->values = NULL;
    m->nCols = 0;
}

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }
}

//ввод матрицы m.Row и nCols даны по условию
void inputMatrix(matrix *m){
    for (int row_index = 0; row_index < m->nRows; ++row_index) {
        for (int col_index = 0; col_index < m->nCols; ++col_index) {
            scanf("%d",&m->values[row_index][col_index]);
        }
    }
}

// ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(&ms[i]);
    }
}

//вывод матрицы m
void outputMatrix(matrix m){
    for (int rowindex = 0; rowindex < m.nRows; ++rowindex) {
        for (int colindex = 0; colindex < m.nCols; ++colindex) {
            printf("%d ",m.values[rowindex][colindex]);
        }
        printf("\n");
    }
}

//– вывод массива из
//nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

//обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2){
    assert(i1 < m.nRows && i2 < m.nRows);
    swap_pointers((void **) &m.values[i1], (void **) &m.values[i2]);
}

void swapColumns(matrix m, int j1, int j2){
    assert(j1 < m.nCols && j2 < m.nCols);
    for (int row_index = 0; row_index < m.nRows; ++row_index) {
        swap_int(&m.values[row_index][j1],&m.values[row_index][j2]);
    }
}

//выполняет сортировку вставками строк
//матрицы m по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int*, int)){
    int criteria_array[m.nRows];
    for (int index_row = 0; index_row < m.nRows; ++index_row) {
        criteria_array[index_row] = criteria(m.values[index_row], m.nCols);
    }
    int newElement, location;

    for (int i = 1; i < m.nRows; i++)
    {
        newElement = criteria_array[i];
        int* prow = m.values[i];
        location = i - 1;
        while(location >= 0 && criteria_array[location] > newElement)
        {
            criteria_array[location+1] = criteria_array[location];
            swapRows(m,location+1,location);
            location = location - 1;
        }
        criteria_array[location+1] = newElement;
        m.values[i] = prow;
    }
}
//выполняет сортировку выбором столбцов
//матрицы m по неубыванию значения функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int)){
    int criteria_array[m.nCols];
    for (int index_cols = 0; index_cols < m.nCols; ++index_cols) {
        criteria_array[index_cols] = criteria(m.values[index_cols], m.nRows);
    }
    int minPosition, tmp;
    for (int i = 0; i < m.nCols; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteria_array[minPosition] > criteria_array[j]){
                minPosition = j;
            }
        tmp = criteria_array[minPosition];
        criteria_array[minPosition] = criteria_array[i];
        criteria_array[i] = tmp;
        swapColumns(m,minPosition,i);
    }
}
//если квадратная
bool isSquareMatrix(matrix *m){
    return (m->nRows == m->nCols);
}

//возвращает значение ’истина’, если матрицы m1 и m2 равны
bool areTwoMatricesEqual(matrix *m1, matrix *m2){
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return false;

    for (int i = 0; i < m1->nRows; ++i) {
        if(memcmp(m1->values[i], m2->values[i], m1->nCols * sizeof(int)))
            return false;
    }

    return true;
}

// если матрица m является единичной, ложь – в противном случае.
bool isEMatrix(matrix *m){
    if  (!isSquareMatrix(m))
        return false;
    for (int index_row = 0; index_row < m->nRows; ++index_row) {
        for (int index_cols = 0; index_cols < m->nCols; ++index_cols) {
            if((m->values[index_row][index_cols] != 1 && index_row == index_cols)||
            (index_row != index_cols && m->values[index_row][index_cols] !=0))
                return false;
            }
        }
    return true;
}
//возвращает значение ’истина’, еcли матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix *m){
    if  (isSquareMatrix(m)){
        for (int index_col = 1; index_col < m->nCols; ++index_col) {
            for (int index = 0; index < index_col; index++) {
                if (m->values[index_col][index] != m->values[index][index_col]
                && m->values[index_col] != m->values[index])
                    return false;
                return true;
            }
        }
    }
    return false;
}

//транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix *m) {
    if (isSquareMatrix(m)) {
        for (int index_row = 1; index_row < m->nCols; ++index_row) {
            for (int index_col = 0; index_col < index_row; index_col++) {
                if (index_row != index_col)
                    swap_int(&m->values[index_row][index_col],
                             &m->values[index_col][index_row]);
            }
        }
    }
}

// транспортирует матрицу
void transposeMatrix(matrix *m){
    if (isEMatrix(m))
        transposeSquareMatrix(m);
    else{
        matrix new_matrix = getMemMatrix(m->nCols,m->nRows);
        for (int row_index = 0; row_index < m->nRows; ++row_index) {
            for (int col_index = 0; col_index < m->nCols; ++col_index) {
                new_matrix.values[col_index][row_index] = m->values[row_index][col_index];
            }
        }
        freeMemMatrix(m);
        *m = new_matrix;
    }
}

//возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m){
    position mini = {0, 0};
    int min_value = m.values[mini.rowIndex][mini.colIndex];
    for (int row_index = 0; row_index < m.nRows; ++row_index) {
        for (int col_index = 0; col_index < m.nCols; ++col_index) {
            if(m.values[row_index][col_index] < min_value){
                min_value = m.values[row_index][col_index] ;
                mini.rowIndex = row_index;
                mini.colIndex = col_index;
            }
        }
    }

    return mini;
}

// возращает позицию  максимального элемента матрицы m.
position getMaxValuePos(matrix m){
    position max_v = {0,0};
    int max_value = m.values[max_v.rowIndex][max_v.colIndex];
    for (int row_index = 0; row_index < m.nRows; ++row_index) {
        for (int col_index = 0; col_index < m.nCols; ++col_index) {
            if(max_value < m.values[row_index][col_index]){
                max_value = m.values[row_index][col_index];
                max_v.rowIndex = row_index;
                max_v.colIndex = col_index;
            }
        }
    }
    return max_v;
}

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;

}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows,size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

int countZeroRows(matrix m){
    int zero_rows_amount = 0;
    for (int row_index = 0; row_index < m.nRows; ++row_index)
        zero_rows_amount += isZero(m.values[row_index], m.nCols);

    return zero_rows_amount;
}

//lab 16
void swapMinMaxstring(matrix m){
    position min_v_p = getMinValuePos(m);
    position max_v_p = getMaxValuePos(m);
    swapRows(m,min_v_p.rowIndex,max_v_p.rowIndex);
}

void sortRowsByMinElement(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int row_index = 0; row_index < m.nRows - 1; ++row_index) {
            if (getMax(m.values[row_index], m.nCols) >
                getMax(m.values[row_index + 1], m.nCols))
                swapRows(m, row_index, row_index + 1);
        }

    }
}