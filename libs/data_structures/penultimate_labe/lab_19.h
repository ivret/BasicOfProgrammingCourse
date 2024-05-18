//
// Created by Иван on 10.05.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_LAB_19_H
#define BASICSOFPROGRAMMINGCOURSE_LAB_19_H
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


void fileModifiesAnEntryRowOnCol(const char file[]);

void write(const char* filename, const char* data);

long getFileSize(const char* filename);

bool cmpStrFile(const char *s, const char *filename);

void test_lab19_01();

void lab19_task02(const char *filename);

void testTransformFloat();

int calculateExpression(int x, int y, char op);

int isOperation(char c);

void lab19_task03(const char *filename);

void test_calculate_the_value_end();

void saves_str_Word(const char *filename, const char *seq);

void test_saves_str_Word();

int wordLen(WordDescriptor wd);

void ConvertsStrLongWord(const char *filename);

void test_ConvertsStrLongWord();

void lab19_task06_deletePolinomXRoot(const char *filename);

void lab19_deletePolinomXRoot(const char *filename, double x);

void test_deletePolinomXRoot();

void separatePositiveNegativeInFile(const char *fileName);

void generateFileTask7(const char *fileName);

void task_separatePositiveNegativeInFile();

void lab19_task08_generate_file(const char *filename);

void lab19_replaceMatrixSymmetricTheTransposed(const char *filename);

void test_replaceMatrixSymmetricTheTransposed();
typedef struct sportsMan{
    char *firstname;
    char *lastname;
    char *surname;
    int best_result;
} sportsMan;

char* loadStrBin(FILE* f);

char *createCopyStr(const char *s);

sportsMan createSportsMan(
        const char *firstname,
        const char *lastname,
        const char *surname,
        int best_result);

sportsMan createSportsManF(FILE *f);

void saveStrBin(const char *s, FILE* f);

void saveSportsMan(sportsMan sm, FILE *f);

void freeSportsMan(sportsMan *sm);

void freeSportsManV(void *sm);

void lab19_generate_file(const char *filename);

int sportsmanCmp(const void * val1, const void * val2);

void test_lab19_team();
#endif //BASICSOFPROGRAMMINGCOURSE_LAB_19_H
