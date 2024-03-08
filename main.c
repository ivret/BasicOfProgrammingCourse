#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>
void test_pushBack_emptyVector(){
    vector v1 = createVector(0);
    pushBack(&v1,7);
    assert(v1.size == 1);
    assert(v1.capacity == 1);
    assert(v1.data[0] == 7);

    vector v2 = createVector(5);
    pushBack(&v2,9);
    assert(v2.size == 1);
    assert(v2.capacity == 5);
    assert(v2.data[0] == 9);
}

void test_pushBack_fullVector(){

    vector v2 = createVector(4);
    v2.size = v2.capacity;
    pushBack(&v2,8);
    assert(v2.size == 5);
    assert(v2.capacity == 8);
    assert(v2.data[4] == 8);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_vector_all() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main(){
    test_vector_all();

    return 0;
}

