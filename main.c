
#include "data_structures/matrix/matrix.h"

//void test_swapMinMaxstring() {
//    matrix m = createMatrixFromArray(
//            (int[])
//                    {
//                            1, 2, 3,
//                            4, 5, 6,
//                            7, 8, 9
//                    }, 3, 3);
//
//    swapMinMaxstring(m);
//    outputMatrix(m);
//}

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
int main(){
//    test_swapMinMaxstring();
    test_swapsortRowsByMinElement();
    return 0;
}
