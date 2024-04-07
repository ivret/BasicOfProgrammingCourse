
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

//возвращает указатель на первый
//символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и
// заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char *begin){
    while (begin != 0 && isspace(*begin)) {
        begin++;
    }
    return begin;
}

//возвращает указатель на первый пробельный символ, расположенный на ленте памяти
// начиная с адреса begin или на первый ноль-символ.
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

int compares_memory_location(char *lhs,char *rhs){
    int result = 0;
    while (*lhs && *lhs == *rhs) {
       lhs++;
       rhs++;
    }
    return *lhs - *rhs;
}
char* copy(const char *beginSource, const char *endSource,
           char *beginDestination) {

}