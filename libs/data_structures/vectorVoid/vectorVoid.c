
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

bool isEmptyV(vectorVoid *v){
    return v->size == 0;
}

bool isFullV(vectorVoid *v){
    return v->size == v->capacity;
}

void* atVectorV(vectorVoid *v, size_t index){
    if(v->size <= index){
        fprintf(stderr, "IndexError: a[%zu] is not exists",index);
        exit(1);
    }
    return (char *) v->data + index * v->baseTypeSize;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    memcpy(destination, atVectorV(v, index), v->baseTypeSize);
}
//записывает на index-ый элемент вектора v значение, расположенное по
//адресу source;
void setVectorValueV(vectorVoid *v, size_t index, void *source){
    memcpy(atVectorV(v,index),source,v->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if(v->size == 0) {
        fprintf(stderr, "1");
        exit(1);
    }else{
        --v->size;
    }
}

void pushBackV(vectorVoid *v, void *source){
    if(isFullV(v)) {
        if (v->capacity == 0) {
            reserveV(v, 1);
        } else
            reserveV(v, 2 * v->capacity);
    }
    setVectorValueV(v,v->size++,source);
}
