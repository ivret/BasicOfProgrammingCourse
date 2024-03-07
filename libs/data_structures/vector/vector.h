//
// Created by Иван on 01.03.2024.
//

#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H
#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);
#endif //LAB14_VECTOR_H
