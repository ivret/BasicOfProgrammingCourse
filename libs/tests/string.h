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

char* copy(const char *beginSource, const char *endSource,
           char *beginDestination);

int compares_2_memory_location(char *a1,char *a2);
#endif //BASICSOFPROGRAMMINGCOURSE_STRING_H
