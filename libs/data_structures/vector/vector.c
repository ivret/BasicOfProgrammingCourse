//
// Created by Иван on 01.03.2024.
//

#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>
vector createVector(size_t n){
    vector result;
    result.size = 0;
    result.capacity = n;
    if(n == 0)
        result.data = NULL;
    else {
        result.data = (int *) malloc(n * sizeof(int));
        if (result.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    return result;
}

vector createVectorFromArray(int* a, size_t n){
    vector v = createVector(n);
    memcpy(v.data, a, n * sizeof (int));
    v.size = n;
    return v;
}

void reserve(vector *v, size_t newCapacity){
    if(newCapacity < v->size)
        v->size = newCapacity;
    if(newCapacity == 0) {
        free(v->data);
        v->data = NULL;

    }else{
        int *data = (int *)realloc(v->data,sizeof (int) *newCapacity);
        if(data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        if(v->data != data){
            memcpy(data,v->data,v->size * sizeof (int));
            free(v->data);
            v->data =data;
        }
    }
    v->capacity = newCapacity;
}
void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v,v->size);
}

void deleteVector(vector *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->data =NULL;
}

bool isEmpty(vector *v){
    return v->size == 0;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if(isFull(v)) {
        if (v->capacity == 0) {
            reserve(v, 1);
        } else
            reserve(v, 2 * v->capacity);
    }
    v->data[v->size++] = x;
}


void popBack(vector *v){
    if(v->size == 0) {
        fprintf(stderr, "1");
        exit(1);
    }else{
        --v->size;
    }
}

int* atVector(vector *v, size_t index){
    if(v->size <= index){
        fprintf(stderr, "IndexError: a[%zu] is not exists",index);
        exit(1);
    }
    return &v->data[index];
}
//– возвращает указатель на последний элемент вектора
int* back(vector *v){
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty.\n");
        exit(1);
    }
    return &v->data[v->size - 1];
}

//возвращает указатель на нулевой элемент вектора.
int* front(vector *v){
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty.\n");
        exit(1);
    }
    return &v->data[0];
}








