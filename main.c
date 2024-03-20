
#include "data_structures/matrix/matrix.h"
#include <assert.h>

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
int main(){
//    test_swapMinMaxstring();
//    test_swapsortRowsByMinElement();
//    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    return 0;
}
