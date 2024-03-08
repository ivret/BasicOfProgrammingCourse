//
// Created by Иван on 01.03.2024.
//

#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

vector createVectorFromArray(int* a, size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void deleteVector(vector *v);

void shrinkToFit(vector *v);

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);


int* back(vector *v);

int* atVector(vector *v, size_t index);

int* front(vector *v);

#endif //LAB14_VECTOR_H
