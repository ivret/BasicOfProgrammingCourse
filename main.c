
#include "data_structures/matrix/matrix.h"
#include "data_structures/array/array.h"

#include <assert.h>
#include <stdio.h>


void test_swapMinMaxstring() {
    matrix m = createMatrixFromArray(
            (int[])
                    {
                            1, 2, 3,
                            4, 5, 6,
                            7, 8, 9
                    }, 3, 3);

    swapMinMaxstring(m);
    outputMatrix(m);
}

void test_swapsortRowsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[])
                    {
                            1, 1, 9,
                            10, 2, 2,
                            6, 8, 6
                    }, 3, 3);

    sortRowsByMinElement(m);
    outputMatrix(m);
}
void test_sortColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[])
                    {
                            0, 1, 9,
                            10, 2, 2,
                            6, 8, 6
                    }, 3, 3);

    sortColsByMinElement(m);
    outputMatrix(m);
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix m = createMatrixFromArray(
            (int[])
                    {
                                9, 1, 7,
                                10, 2, 2,
                                5, 8, 6
                    }, 3, 3);
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            9, 1, 7,
                            1, 2, 2,
                            7, 2, 6
                    }, 3, 3);
    matrix res = createMatrixFromArray(
            (int[])
                    {
                            131, 25, 107,
                            25, 9, 23,
                            107, 23, 89
                    }, 3, 3);

    getSquareOfMatrixIfSymmetric(&m1);
    assert( areTwoMatricesEqual( &m1,  &res));
    outputMatrix(m1);
    freeMemMatrix(&m);
    freeMemMatrix(&m1);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[])
                    {
                            9, 1, 7,
                            10, 2, 2,
                            5, 8, 6
                    }, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    outputMatrix(m);
}
void test_isMutuallyInverseMatrices(){
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            1,0,
                            0,1
                    }, 2, 2);
    matrix m2 = createMatrixFromArray(
            (int[])
                    {
                            1,0,
                            0,1
                    }, 2, 2);
    assert(isMutuallyInverseMatrices(m1,m2));
}
void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            3, 2,5,4,
                            1, 3,6,3,
                            3,2,1,2
                    }, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);
}
void test_getMinInArea(){
    matrix m = createMatrixFromArray(
    (int [])
    {
        10,7,5,6,
        3,11,8,9,
        4,1,14,2,
        12,18,13,15
    },4,4);
    assert(getMinInArea(m) == 1);
}


void  test_sortByDistances() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            10, 7, 5, 6,
                            3, 11, 8, 9,
                            4, 1, 14, 2,
                            12, 18, 13, 15
                    }, 4, 4);
    matrix m2 = createMatrixFromArray(
            (int[])
                    {
                            10, 7, 5, 6,
                            4, 1, 14, 2,
                            3, 11, 8, 9,
                            12, 18, 13, 15
                    }, 4, 4);
    sortByDistances(m1);
    assert(areTwoMatricesEqual(&m1,&m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_countEqClassesByRowsSum(){
    matrix m = createMatrixFromArray(
            (int [])
                    {7,1,//8
                     2,7,//9
                     5,4,//9
                     4,3,//7
                     1,0,//1
                     8,10//18
                    },6,2);
    //1,7,8,9,9,18
    assert(countEqClassesByRowsSum(m) == 5);
}

void test_getNSpecialElement(){
    matrix m = createMatrixFromArray(
            (int [])
                    {
                            3,5,5,4,
                            2,3,6,7,
                            12,2,1
                    },4,4);
    assert(getNSpecialElement(m) == 2);
}void test_swapPenultimateRow(){
    matrix m = createMatrixFromArray(
            (int [])
                    {
                            1,2,3,
                            4,5,6,
                            7,8,1
                    },3,3);
    matrix m1 = createMatrixFromArray(
            (int [])
                    {
                            1,2,3,
                            1,4,7,
                            7,8,1
                    },3,3);
    swapPenultimateRow(m);
    outputMatrix(m);
    assert(areTwoMatricesEqual(&m,&m1));
}
int main(){
//    test_swapMinMaxstring();
//    test_swapsortRowsByMinElement();
//    test_sortColsByMinElement();
//    test_getSquareOfMatrixIfSymmetric();
//    test_transposeIfMatrixHasNotEqualSumOfRows();
//    test_isMutuallyInverseMatrices();
//    test_findSumOfMaxesOfPseudoDiagonal();
//    test_getMinInArea();
//    test_sortByDistances();
//    test_countEqClassesByRowsSum();
//    test_getNSpecialElement();
    test_swapPenultimateRow();
    return 0;
}
