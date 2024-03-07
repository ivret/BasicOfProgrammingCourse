//
// Created by Иван on 01.03.2024.
//

#include "vector.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
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
void reserve(vector *v, size_t newCapacity){
    if(newCapacity < v->size)
        v->size = newCapacity;
    if(newCapacity == 0) {
        free(v->data);
        v->data = NULL;

    }else{
        int *data = (int *)realloc(v->data,sizeof (int) *newCapacity);
        if(v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        if(v->data != data){
            memcpy(data,v->data,v->size * sizeof (int));
            free(v->data);
            v->data =data;
        }
    }



}