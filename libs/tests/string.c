
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"

size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* findNonSpace(char *begin){
    while (begin != 0 && isspace(*begin)) {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin){
    while (*begin && !isspace(*begin))
        begin++;

    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend){
    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

int strcmp2(char *a1, char *a2){
    while (*a1 && *a1 == *a2) {
       a1++;
       a2++;
    }
    return *a1 - *a2;
}

char* copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    while (beginSource != endSource){
        *beginDestination = *beginSource;
        beginSource++;
        beginDestination++;
    }
    return beginDestination;
}

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)){
    while (beginSource != endSource){
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource){
        if (f(*rbeginSource)){
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource++;
    }
    return beginDestination;
}
