# include <stdio.h>
# include <assert.h>
# include <stdint.h>
# include "array.h"
#include <stdbool.h>


void inputArray_ (int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        scanf ("%d", & a [ i ]) ;
    }

void outputArray_ ( const int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        printf ("%d ", a [ i ]) ;
    printf ("\n") ;
    }

void outputArrayF ( const float * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        printf ("%f ", a [ i ]) ;
    printf ("\n") ;
}
void append_ (int * const a , size_t * const n , const int value ) {
    a [* n ] = value ;
    (* n ) ++;
    }

void insert_ (int * const a , size_t * const n , const size_t pos ,
const int value ) {
    assert ( pos < * n ) ;
    if (* n != 0) {
        size_t lowBound = ( pos == 0) ? SIZE_MAX : pos ;
        (* n ) ++;
        for ( size_t i = * n ; i != lowBound ; i --)
            a [ i ] = a [ i - 1];
        a [ pos ] = value ;
    } else {
        (* n ) ++;
        a [ pos ] = value ;
    }
}

void deleteByPosSaveOrder_ (int *a , size_t *n , const size_t pos ) {
    for ( size_t i = pos ; i < * n - 1; i ++)
        a [ i ] = a [ i + 1];
    (* n ) --;
    }

void deleteByPosUnsaveOrder_ (int *a , size_t *n , size_t pos ) {
    a [ pos ] = a [* n - 1];
    (* n ) --;
    }

size_t linearSearch_ ( const int *a , const size_t n , int x ) {
    for ( size_t i = 0; i < n ; i ++)
        if ( a [ i ] == x )
        return i ;
    return n ;
    }

int any_ ( const int *a , size_t n , int (* predicate ) (int) ) {
    for ( size_t i = 0; i < n ; i ++)
        if ( predicate ( a [ i ]) )
        return 1;
    return 0;
}

int all_ ( const int *a , size_t n , int (* predicate ) (int) ) {
    for ( size_t i = 0; i < n ; i ++)
        if (! predicate ( a [ i ]) )
        return 0;
    return 1;
}

int countIf_ ( const int * const a , const size_t n , int (* predicate ) (int) ){
    int count = 0;
    for ( size_t i = 0; i < n ; i ++)
        count += predicate ( a [ i ]) ;
    return count ;
}

void deleteIf_ (int * const a , size_t * const n , int (* deletePredicate ) (int) ) {
    size_t iRead = 0;
    while ( iRead < * n && ! deletePredicate ( a [ iRead ]) )
        iRead ++;
    size_t iWrite = iRead ;
    while ( iRead < * n ) {
        if (! deletePredicate ( a [ iRead ]) ) {
            a [ iWrite ] = a [ iRead ];
            iWrite ++;
            }
        iRead ++;
        }
    * n = iWrite ;
}

void forEach_ ( const int * source , int * dest , const size_t n , const int (*predicate ) ( int) ) {
    for ( size_t i = 0; i < n ; i ++)
        dest [ i ] = predicate ( source [ i ]) ;
}

size_t binarySearch_ ( const int *a , size_t n , int x ) {
    size_t left = 0;
    size_t right = n - 1;
    while ( left <= right ) {
        size_t middle = left + ( right - left ) / 2;
        if ( a [ middle ] < x )
            left = middle + 1;
        else if ( a [ middle ] > x )
            right = middle - 1;
        else
        return middle ;
    }
    return SIZE_MAX ;
}

size_t binarySearchMoreOrEqual_ ( const int *a , size_t n , int x ) {
    if ( a [0] >= x )
        return 0;
    size_t left = 0;
    size_t right = n ;
    while ( right - left > 1) {
        size_t middle = left + ( right - left ) / 2;
        if ( a [ middle ] < x )
            left = middle ;
        else
        right = middle ;
    }
    return right ;
}
void swap_int(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void swap_pointers(void** a, void** b){
    void* t = *a;
    *a = *b;
    *b = t;
}

bool isZero(const int a[], const size_t size) {
    for (int i = 0; i < size; ++i)
        if (a[i])
            return false;

    return true;
}

bool isZeroF(const int a[], const size_t size) {
    for (int i = 0; i < size; ++i)
        if (a[i])
            return false;

    return true;
}
void InsertionSort(int n, int mass[])
{
    int newElement, location;

    for (int i = 1; i < n; i++)
    {
        newElement = mass[i];
        location = i - 1;
        while(location >= 0 && mass[location] > newElement)
        {
            mass[location+1] = mass[location];
            location = location - 1;
        }
        mass[location+1] = newElement;
    }
}
int getMax(int *a, int n){
    int max_values = a[0];
    for (int i = 1; i < n; ++i) {
        if (max_values > a[i])
            max_values;
        else
            max_values = a[i];
    }
    return max_values;
}

long long getSumL(int *a,int n){
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += a[i];
    }
    return result;
}
bool isUnique(long long *a, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n ; ++j) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

int getSum(int *a, int n){
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += a[i];
    }
    return result;
}











