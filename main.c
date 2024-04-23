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
    char s[] = " Hi123  dd";
    char s1[] = " ";
    char s2[] = "   ";
    char s3[] = "fffj   jfoetrtt";
    char s4[] = "     fffj   jfoetrtt";
    removeExtraSpaces(s);
    removeExtraSpaces(s1);
    removeExtraSpaces(s2);
    removeExtraSpaces(s3);
    removeExtraSpaces(s4);
    ASSERT_STRING("Hi123 dd", s);
    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
    ASSERT_STRING("fffj jfoetrtt", s3);
    ASSERT_STRING("fffj jfoetrtt", s3);
}
void test_moveLettersInBeginDigitsInEnd() {
    char s[] = " Hi123  dd";
    char s1[] = "";
    char s2[] = "  123jf ";
    char s3[] = "ff12   j1234rtt";
    moveLettersInBeginDigitsInEnd(s);
    moveLettersInBeginDigitsInEnd(s1);
    moveLettersInBeginDigitsInEnd(s2);
    moveLettersInBeginDigitsInEnd(s3);
    ASSERT_STRING(" Hi123  dd", s);
    ASSERT_STRING("", s1);
    ASSERT_STRING("  jf123 ", s2);
    ASSERT_STRING("ff12   jrtt1234", s3);
}

void test_reverseDigitForSpaces(){
    char s[20] = " Hi2  dd";
    char s1[20] = "2";
    char s2[20] = "  3jf ";
    char s3[20] = "ff1   j4rtt";
    replaceDigitSpace(s);
    replaceDigitSpace(s1);
    replaceDigitSpace(s2);
    replaceDigitSpace(s3);
    ASSERT_STRING(" Hi    dd", s);
    ASSERT_STRING("  ", s1);
    ASSERT_STRING("     jf ", s2);
    ASSERT_STRING("ff    j    rtt", s3);
}
void test_replace() {
    char s[100] = "jdjv try";
    char s1[100] = "2345 gjtk";
    char s2[100] = " include iostrim ";
    char s3[100] = "ff1   j4rtt";
    replace(s,"try","false");
    replace(s1,"2345","567");
    replace(s2,"include","iostrim");
    replace(s3,"ff1","gss");
    ASSERT_STRING("jdjv false", s);
    ASSERT_STRING("567 gjtk", s1);
    ASSERT_STRING("iostrim iostrim", s2);
    ASSERT_STRING("gss j4rtt", s3);
}

void test_areABCOrderedWords(){
    char s1[] = "adfgf cdedd efjff";
    char s2[] = " cdfbdfv efjdf awdv";
    char s3[] = "";
    char s4[] = "escf cdddfe aweubc";
    assert(areABCOrderedWords(s1));
    assert(!areABCOrderedWords(s2));
    assert(areABCOrderedWords(s3));
    assert(areABCOrderedWords(s4));
}
void test_printWordsInReverse() {
    char s[100] = "jdjv try";
    char s1[100] = " ";
    char s2[100] = " include f iostrim ";
    char s3[100] = "ff1  d j4rtt";
    printWordsInReverse(s);
    printWordsInReverse(s1);
    printWordsInReverse(s2);
    printWordsInReverse(s3);
    ASSERT_STRING("try jdjv", s);
    ASSERT_STRING(" ", s1);
    ASSERT_STRING("iostrim f include", s2);
    ASSERT_STRING("j4rtt d ff1", s3);
}
void test_all(){
    test_digitToStartTransform_oneWord();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_moveLettersInBeginDigitsInEnd();
    test_reverseDigitForSpaces();
    test_replace();
    test_areABCOrderedWords();
    test_printWordsInReverse();
}

int main(){
    test_all();
    return 0;
}