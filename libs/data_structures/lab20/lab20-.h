//
// Created by Иван on 22.05.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_LAB20_H
#define BASICSOFPROGRAMMINGCOURSE_LAB20_H
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "data_structures/array/array.h"
#include "data_structures/matrix/matrix.h"
#include "data_structures/array/array.h"
#include "data_structures/vector/vector.h"
#include "data_structures/vectorVoid/vectorVoid.h"
#include "data_structures/str/string.h"
#include "data_structures/polynom/polynominals.h"
#include "data_structures/data/data.h"
#include "data_structures/penultimate_labe/lab_19.h"

void lab20_task01(const char* read_file, const char* write_file);

void test_lab20_01();

void lab20_task02(const char* read_file, const char* write_file);

void test_lab20_02();
void shellSortInt(int a[], int n);
int getMedian(matrix *m, int row_index, int col_index, int *buffer);
void processFilterWindow(matrix m, position start, position end, int *buffer);
void lab20_task03(matrix m, int filter);
void test_lab20_03();

int minInt(int a, int b);

void addDomainParseStrToVec(vectorVoid *vec,
                            char *write_ptr,
                            char *buffer);
vectorVoid parseDomainStr(const char *s);
void lab20_04(const char* read_file, const char* write_file);
void test_04();

int lab20_05(matrix m);

void test_l05();
#endif //BASICSOFPROGRAMMINGCOURSE_LAB20_H
