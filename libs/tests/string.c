
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

int strcmp_(char *a1, char *a2){
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

char* getEndOfString(char *s){
    while (*s != '\0')
        s++;
    return s;
}

void strcpy_(char *dest,char *source){
    copy(source, getEndOfString(source) + 1,dest);
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void digitToStartTransform(char *s){
    char s1[100];
    strcpy_(s1,s);
    char*  ptrWrite = s;
    char* ptrRead = getEndOfString(s1 ) - 1;
    char* rend = s1 - 1;
    while (ptrRead != rend) {
        if (isdigit(*ptrRead)) {
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead--;
    }
    ptrRead = s1;
    while (*ptrRead != 0) {
        if (!isdigit(*ptrRead)) {
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead++;
    }
    *ptrWrite = '\0';
}

void removeAdjacentEqualLetters(char *s){
    char* ptrRead = s + 1;
    char* ptrWrite = s + 1;
    while (*ptrRead != 0){
        if (*ptrRead != *(ptrRead - 1)){
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead++;
    }
    *ptrWrite = '\0';
}

void removeExtraSpaces(char *s){
    char* ptrRead = findNonSpace(s);
    char* ptrWrite = s;
    while (*ptrRead != 0){
        *ptrWrite = *ptrRead;
        ptrWrite++;
        if (isspace(*ptrRead)) {
            ptrRead = findNonSpace(ptrRead);
        } else {
            ptrRead++;
        }
    }
    *ptrWrite = '\0';
}








