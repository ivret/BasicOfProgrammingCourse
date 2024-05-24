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

void shellSortInt(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            //сортировка подсписков, созданных с помощью gap
            int temp = a[i];

            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

int getMedian(matrix *m, int row_index, int col_index, int *buffer){
    row_index++;
    col_index++;
    int k = 0;
    for (int i = row_index - 2; i <= row_index; ++i) {
        for (int j = col_index - 2; j <= col_index; ++j) {
            buffer[k++] = m->values[i][j];
        }
    }

    shellSortInt(buffer, 9);

    return buffer[4];
}

void processFilterWindow(matrix m, position start, position end, int *buffer){
    for (int row_index = start.rowIndex + 1;
         row_index < end.rowIndex;
         ++row_index) {
        for (int col_index = start.colIndex + 1;
             col_index < end.colIndex;
             ++col_index) {
            m.values[row_index][col_index] =
                    getMedian(&m, row_index, col_index, buffer);
        }
    }
}

void lab20_task03(matrix m, int filter){
    int buffer[9];
    int k = filter - 1;
    for (int row_index = 0; row_index < m.nRows; row_index += filter) {
        for (int col_index = 0; col_index < m.nCols; col_index += filter) {
            processFilterWindow(
                    m,
                    (position) {row_index, col_index},
                    (position) {row_index + k, col_index + k},
                    buffer);
        }
    }
}

void test_lab20_03(){
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            10, 20, 30,
                            25, 35, 45,
                            15, 25, 35
                    }, 3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[])
                    {
                            10, 20, 30,
                            25, 25, 45,
                            15, 25, 35
                    }, 3, 3
    );

    lab20_task03(m1, 3);
    assert(areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void addDomainParseStrToVec(vectorVoid *vec,
                            char *write_ptr,
                            char *buffer){
    long str_len = write_ptr - buffer + 1;
    char *add_str = malloc(str_len);
    memcpy(add_str, buffer, str_len);
    pushBackV(vec, &add_str);
}

vectorVoid parseDomainStr(const char *s){
    char buffer[256];
    char *write_ptr = buffer;
    vectorVoid vec = createVectorV(2, sizeof (char*));

    while (*s){
        if (*s == '.' || *s == '\n'){
            *write_ptr = 0;
            addDomainParseStrToVec(&vec, write_ptr, buffer);
            write_ptr = buffer;
        } else {
            *write_ptr = *s;
            write_ptr++;
        }

        s++;
    }

    return vec;
}

void lab20_04(const char* read_file, const char* write_file){
    FILE *f = fopen(read_file, "r");

    int n;
    fscanf(f, "%d", &n);

    vectorVoid domains[n];
    int visits_amounts[n];
    int visits_amounts_c[n];

    const int buffer_size = 1024;
    char buffer[buffer_size];
    for (int i = 0; i < n; ++i) {
        fscanf(f, "%d ", visits_amounts + i);
        fgets(buffer, buffer_size, f);

        domains[i] = parseDomainStr(buffer);
    }

    fclose(f);

    f = fopen(write_file, "w");

    char *unique_str[n];
    int unique_visits_amounts[n];
    char *p_str[n];
    while(n) {
        for (int vec_index = 0; vec_index < n;) {
            if (!isEmptyV(&domains[vec_index])) {
                getVectorValueV(&domains[vec_index],
                                domains[vec_index].size - 1,
                                p_str + vec_index);

                if (domains[vec_index].size > 1){
                    char *undo_str;
                    getVectorValueV(&domains[vec_index],
                                    domains[vec_index].size - 2,
                                    &undo_str);

                    strcpy(buffer, undo_str);
                    int undo_len = strlen(undo_str);
                    buffer[undo_len++] = '.';
                    strcpy(buffer + undo_len, p_str[vec_index]);
                    undo_len += strlen(p_str[vec_index]) + 1;
                    free(undo_str);
                    undo_str = malloc(undo_len);
                    memcpy(undo_str, buffer, undo_len);

                    setVectorValueV(&domains[vec_index],
                                    domains[vec_index].size - 2,
                                    &undo_str);
                }
                popBackV(domains + vec_index);
                ++vec_index;
            } else {
                deleteVectorV(domains + vec_index);
                domains[vec_index] = domains[--n];
                visits_amounts[vec_index] = visits_amounts[n];
            }
        }
        if (n == 0)
            break;
        int k = n;
        unique_str[0] = p_str[0];
        int unique_amount = 1;
        unique_visits_amounts[0] = visits_amounts[0];
        int vec_index = 1;
        memcpy(visits_amounts_c, visits_amounts, n * sizeof (int));

        while (vec_index < k) {
            int i;
            for (i = 0; i < unique_amount; ++i) {
                if (!strcmp(p_str[vec_index], unique_str[i])) {
                    break;
                }
            }

            if (i == unique_amount) {
                unique_visits_amounts[unique_amount] = visits_amounts_c[vec_index];
                unique_str[unique_amount++] = p_str[vec_index++];
            } else {
                unique_visits_amounts[i] += visits_amounts_c[vec_index];
                k--;
                free(p_str[vec_index]);
                p_str[vec_index] = p_str[k];
                visits_amounts_c[vec_index] = visits_amounts_c[k];
            }
        }

        for (int i = 0; i < unique_amount; ++i) {
            fprintf(f, "%d %s\n", unique_visits_amounts[i], unique_str[i]);
            free(unique_str[i]);
        }
    }

    fclose(f);
}

void test_04(){
    char lab20_task04_str[] = "4\n"
                              "900 google.mail.com\n"
                              "50 yahoo.com\n"
                              "1 intel.mail.com\n"
                              "5 wiki.org\n";

    char lab20_task04_out_str[] = "901 mail.com\n"
                                  "50 yahoo.com\n"
                                  "900 google.mail.com\n"
                                  "5 wiki.org\n"
                                  "5 org\n"
                                  "1 intel.mail.com\n"
                                  "951 com\n";

    const char read_file[] = "20_4_r.txt";
    const char write_file[] = "20_4_w.txt";
    write(read_file, lab20_task04_str);
    lab20_04(read_file, write_file);

    assert(cmpStrFile(lab20_task04_out_str, write_file));
}

int minInt(int a, int b){
    return a <= b ? a : b;
}

int lab20_05(matrix m){
    int counter = 0;
    matrix inc_m = getMemMatrix(m.nRows, m.nCols);
    for (int row_index = 0; row_index < m.nRows; ++row_index) {
        inc_m.values[row_index][0] = m.values[row_index][0];
        for (int col_index = 0; col_index < m.nCols; ++col_index) {
            if(m.values[row_index][col_index])
                inc_m.values[row_index][col_index] =
                        inc_m.values[row_index][col_index - 1] + 1;
            else
                inc_m.values[row_index][col_index] = 0;

            int min = inc_m.values[row_index][col_index];
            for (int k = row_index; k >= 0; --k) {
                min = minInt(min, inc_m.values[k][col_index]);
                counter += min;
            }
        }
    }

    freeMemMatrix(&inc_m);

    return counter;
}

void test_l05(){
    matrix m1 = createMatrixFromArray(
            (int[])
                    {
                            1, 0, 1,
                            1, 1, 0,
                            1, 1, 0
                    }, 3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[])
                    {
                            1, 1, 0, 1,
                            1, 1, 1, 1,
                            1, 1, 1, 1,
                            1, 1, 1, 1
                    }, 4, 4
    );

    assert(lab20_05(m1) == 13);
    assert(lab20_05(m2) == 76);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void lab20_06(const char* input_str, char* output_str){
    char digit = '1';

    if (*input_str == 'I'){
        *output_str = digit++;
        output_str++;
    }
    else{
        const char *end_ptr = input_str + 1;
        while (*end_ptr == 'D')
            end_ptr++;

        output_str = output_str + (end_ptr - input_str);
        char *write_ptr = output_str;
        for (const char* cur_ptr = end_ptr + 1; cur_ptr != input_str; cur_ptr--){
            *write_ptr = digit++;
            write_ptr--;
        }

        input_str = end_ptr;
        output_str++;
    }

    while (*input_str) {
        while (*input_str == 'I') {
            input_str++;
            *output_str = digit++;
            output_str++;
        }

        if (*input_str) {
            const char *end_ptr = input_str;

            output_str--;
            digit--;

            while (*end_ptr == 'D')
                end_ptr++;

            long dif = end_ptr - input_str;
            char *write_ptr = output_str + dif;
            for (const char *cur_ptr = end_ptr; cur_ptr >= input_str; cur_ptr--) {
                *write_ptr = digit++;
                write_ptr--;
            }

            input_str = end_ptr;
            output_str += dif + 1;
        }
    }

    *output_str = 0;

}

void test_06(){
    char str1[] = "IIIDIDDD";
    char str2[] = "DDD";
    char str3[] = "IIDIDDII";
    char out_str1[] = "123549876";
    char out_str2[] = "4321";
    char out_str3[] = "124376589";
    char processed_str1[10];
    char processed_str2[10];
    char processed_str3[10];

    lab20_06(str1, processed_str1);
    lab20_06(str2, processed_str2);
    lab20_06(str3, processed_str3);

    assert(!strcmp(processed_str1, out_str1));
    assert(!strcmp(processed_str2, out_str2));
    assert(!strcmp(processed_str3, out_str3));
}