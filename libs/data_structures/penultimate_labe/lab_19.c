#include "lab_19.h"

void fileModifiesAnEntryRowOnCol(const char file[]){
    FILE *f = fopen(file,"r");
    int n;
    matrix  *ms = createMatrixFromArrayFile(f,&n);
    fclose(f);
    for (int i = 0; i < n; ++i) {
        transposeSquareMatrix(&ms[i]);
    }
    f = fopen(file,"w");

    ou
}