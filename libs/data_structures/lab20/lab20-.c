//
// Created by Иван on 22.05.2024.
//

#include "lab20-.h"
#include <matrix/matrix.h>
#include "array/array.h"
#include <file/file.h>
#include <assert.h>
#include <vector_void/vector_void.h>
#include <string.h>
#include <signal.h>
#include <ncurses.h>


void lab20_task01(const char* read_file, const char* write_file){
    FILE *f = fopen(read_file, "r");

    int n, query_amount;
    fscanf(f, "%d%d", &n, &query_amount);

    matrix m = getMemMatrix(n, n);
    zeroMatrix(m);

    for (int i = 0; i < query_amount; ++i) {
        int row1, col1, row2, col2;
        fscanf(f, "%d%d%d%d", &row1, &col1, &row2, &col2);

        for (int row_index = row1; row_index <= row2; ++row_index) {
            for (int col_index = col1; col_index <= col2; ++col_index) {
                m.values[row_index][col_index]++;
            }
        }
    }

    fclose(f);

    f = fopen(write_file, "w");
    outputMatrixSquareF(m, f);
    fclose(f);

    freeMemMatrix(&m);
}

void test_lab20_01(){
    char lab20_task01_str[] = "3\n"
                              "2\n"
                              "1 1 2 2\n"
                              "0 0 1 1";

    char lab20_task01_out_str[] = "3\n"
                                  "1 1 0\n"
                                  "1 2 1\n"
                                  "0 1 1\n";

    const char read_file[] = "20_1_r.txt";
    const char write_file[] = "20_1_w.txt";
    writeAnyway(read_file, lab20_task01_str);
    lab20_task01(read_file, write_file);

    assert(cmpStrF(lab20_task01_out_str, write_file));
}