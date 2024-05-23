//
// Created by Иван on 22.05.2024.
//

#include "lab20-.h"
#include <assert.h>
#include <string.h>
#include <signal.h>


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
    outputMatrixSquareFile(m, f);
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
    write(read_file, lab20_task01_str);
    lab20_task01(read_file, write_file);

    assert(cmpStrFile(lab20_task01_out_str, write_file));
}

int countNeighbours(matrix m, int row_index, int col_index){
    int amount = 0;
    int row_border = m.nRows - 1;
    int col_border = m.nCols - 1;
    amount += row_index > 0 && m.values[row_index - 1][col_index] != 0;
    amount += row_index < row_border && m.values[row_index + 1][col_index] != 0;
    amount += col_index > 0 && m.values[row_index][col_index - 1] != 0;
    amount += col_index < col_border && m.values[row_index][col_index + 1] != 0;
    amount += col_index > 0 && row_index > 0 &&
              m.values[row_index - 1][col_index - 1] != 0;
    amount += col_index > 0 && row_index < row_border &&
              m.values[row_index + 1][col_index - 1] != 0;
    amount += col_index < col_border && row_index > 0 &&
              m.values[row_index - 1][col_index + 1] != 0;
    amount += col_index < col_border && row_index < row_border &&
              m.values[row_index + 1][col_index + 1] != 0;

    return amount;
}

void lab20_task02(const char* read_file, const char* write_file){
    FILE *f = fopen(read_file, "r");
    matrix source_matrix = createMatrixFile(f);
    fclose(f);

    matrix new_matrix = {NULL, 0, 0};
    new_matrix = copyFromMatrix(new_matrix, source_matrix);

    for (int row_index = 0; row_index < source_matrix.nRows; ++row_index) {
        for (int col_index = 0; col_index < source_matrix.nCols; ++col_index) {
            int neighbours = countNeighbours(source_matrix, row_index, col_index);
            int old_value = source_matrix.values[row_index][col_index];
            int new_value;

            if (old_value == 1)
                new_value = neighbours == 2 || neighbours == 3;
            else
                new_value = neighbours == 3;

            new_matrix.values[row_index][col_index] = new_value;
        }
    }

    f = fopen(write_file, "w");
    outputMatrixF(new_matrix, f);
    fclose(f);

    freeMemMatrix(&new_matrix);
    freeMemMatrix(&source_matrix);
}

void test_lab20_02(){
    char lab20_task02_str[] = "4 3\n"
                              "0 1 0\n"
                              "0 0 1\n"
                              "1 1 1\n"
                              "0 0 0";

    char lab20_task02_out_str[] = "4 3\n"
                                  "0 0 0\n"
                                  "1 0 1\n"
                                  "0 1 1\n"
                                  "0 1 0\n";

    const char read_file[] = "20_2_r.txt";
    const char write_file[] = "20_2_w.txt";
    write(read_file, lab20_task02_str);
    lab20_task02(read_file, write_file);

    assert(cmpStrFile(lab20_task02_out_str, write_file));
}
