
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


//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ
//строки, за которым следует ноль-символ) и заканчивая rend (адрес символа
// перед началом строки). Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend) {
}