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
void lab20_06(const char* input_str, char* output_str);
void test_06();

typedef struct IntNode{
    int value;
    struct IntNode* left;
    struct IntNode* right;
} IntNode;

void deleteTreeRec(IntNode *tree);
IntNode *createTree(int *nums, int n);
void test_07();
void lab20_08(const char* input_str, const int* array, char *output_str);
void test_08();

void lab20_09(const char* read_filename,
              const char *write_filename,
              int n);
void test_09();

void handler(int signal);

bool printNextNLines(FILE *f, int n, char *buffer, int buf_size);

void lab20_10(const char* filename, int n);

void test_10();


void task_11(char **dict, char **requests, int *num_in_req, int n, int q);

void test_for_task_11();
#endif //BASICSOFPROGRAMMINGCOURSE_LAB20_H
