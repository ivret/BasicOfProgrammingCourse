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
#endif //BASICSOFPROGRAMMINGCOURSE_LAB_19_H
