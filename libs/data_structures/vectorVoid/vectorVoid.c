//
// Created by Иван on 08.03.2024.
//

#include "vectorVoid.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

vectorVoid createVectorV(size_t capacity, size_t baseTypeSize){
    vectorVoid result;
    result.size = 0;
    result.capacity = capacity;
    result.baseTypeSize = baseTypeSize;
    if(capacity == 0)
        result.data = NULL;
    else {
        result.data = (void *) malloc(capacity * baseTypeSize);
        if (result.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    return result;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if(newCapacity < v->size)
        v->size = newCapacity;
    if(newCapacity == 0) {
        free(v->data);
        v->data = NULL;

    }else{
        int *data = (void *)realloc(v->data,v->baseTypeSize *newCapacity);
        if(data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        if(v->data != data){
            memcpy(data,v->data,v->size * v->baseTypeSize);
            free(v->data);
            v->data =data;
        }
    }
    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v,v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->data =NULL;
    v->baseTypeSize = 0;
}


