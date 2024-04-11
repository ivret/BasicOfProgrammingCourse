//
// Created by Иван on 04.04.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_STRING_H
#define BASICSOFPROGRAMMINGCOURSE_STRING_H

size_t strlen_(const char *begin);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(char *a1, char *a2);

char* copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char* getEndOfString(char *s);

void removeNonLetters(char *s);

void digitToStartTransform(char *s);

void strcpy_(char *dest,char *source);

void removeAdjacentEqualLetters(char *s);

void removeExtraSpaces(char *s);
#endif //BASICSOFPROGRAMMINGCOURSE_STRING_H
