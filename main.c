#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <ctype.h>
#include "libs/tests/string.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_digitToStartTransform_oneWord() {
    char s[] = "Hi123";
    digitToStartTransform(s);
    ASSERT_STRING("321Hi", s);
}

void test_removeAdjacentEqualLetters(){
    char s[] = "Hi12333 hgfddd";
    char s1[] = " ";
    char s2[] = "   ";
    char s3[] = "fffj jfoetrtt";
    removeAdjacentEqualLetters(s);
    removeAdjacentEqualLetters(s1);
    removeAdjacentEqualLetters(s2);
    removeAdjacentEqualLetters(s3);
    ASSERT_STRING("Hi123 hgfd", s);
    ASSERT_STRING(" ", s1);
    ASSERT_STRING(" ", s2);
    ASSERT_STRING("fj jfoetrt", s3);
}

void test_removeExtraSpaces(){
    char s[] = "Hi12333   hgfddd";
    char s1[] = " ";
    char s2[] = "   ";
    char s3[] = "fffj   jfoetrtt";
    removeExtraSpaces(s);
    removeExtraSpaces(s1);
    removeExtraSpaces(s2);
    removeExtraSpaces(s3);
    ASSERT_STRING("Hi12333 hgfddd", s);
    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
    ASSERT_STRING("fffj jfoetrtt", s3);
}
void test_all(){
    test_digitToStartTransform_oneWord();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
}

int main(){
    test_all();
    return 0;
}