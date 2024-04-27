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
//void test_printWordsInReverse() {
//    char s[100] = "jdjv try";
//    char s1[100] = " ";
//    char s2[100] = " include f iostrim ";
//    char s3[100] = "ff1  d j4rtt";
//    printWordsInReverse(s);
//    printWordsInReverse(s1);
//    printWordsInReverse(s2);
//    printWordsInReverse(s3);
//    ASSERT_STRING("try jdjv", s);
//    ASSERT_STRING(" ", s1);
//    ASSERT_STRING("iostrim f include", s2);
//    ASSERT_STRING("j4rtt d ff1", s3);
//}

void test_countWordsPalindromes(){
    char s1[] = "adfgf d efjff";
    char s2[] = " cdfbdfv esse f awdv";
    char s3[] = " ";
    char s4[] = "escf cdddfe aweubc";
    assert(countWordsPalindromes(s1) == 1);
    assert(countWordsPalindromes(s2) == 0);
    assert(countWordsPalindromes(s3) == 1);
    assert(countWordsPalindromes(s4) == 0);
}

void test_movingString_2() {
    char s[] = "jd try";
    char s_0[] = "jd try";
    char s1[] = "2345 df tk";
    char s1_1[] = "5 d k";
    char s2[] = " inc io";
    char s2_2[] = " ";
    char s3[] = " ";
    char s3_3[] = " ";
    char buff[10000];
    movingString_2(s3,s3_3,buff);
    ASSERT_STRING("", buff);
    movingString_2(s,s_0,buff);
    ASSERT_STRING( "jd jd try try",buff);
    movingString_2(s1,s1_1,buff);
    ASSERT_STRING("2345 5 df d tk k", buff);
    movingString_2(s2,s2_2,buff);
    ASSERT_STRING("inc io", buff);
}

void test_getWordReverseOrder() {
    char s[] = "jdjv try";
    char s1[] = "2345 gj";
    char s2[] = " ";
    char s3[] = "ff1   j4rtt";
    getWordReverseOrder(s);
    getWordReverseOrder(s1);
    getWordReverseOrder(s2);
    getWordReverseOrder(s3);
    ASSERT_STRING("try jdjv", s);
    ASSERT_STRING("gj 2345", s1);
    ASSERT_STRING(" ", s2);
    ASSERT_STRING("j4rtt ff1", s3);
}

void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(
            getWordBeforeFirstWordWithA(s1, &word)
            == EMPTY_STRING
    );
    char s2[] = "ABC";
    assert(
            getWordBeforeFirstWordWithA(s2, &word)
            == FIRST_WORD_WITH_A
    );
    char s3[] = "BC A";
    assert(
            getWordBeforeFirstWordWithA(s3, &word)
            == WORD_FOUND
    );
    char got[MAX_WORD_SIZE];
    copyWord(got, word);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) ==
           NOT_FOUND_A_WORD_WITH_A);
}

void testAll_lastWordInFirstStringInSecondString() {
    WordDescriptor word;
    char s1[] = "word1 word2 word3";
    char s2[] = "word4 word5 word6";
    assert(
            lastWordInFirstStringInSecondString(s1, s2).begin == NULL);
    char s3[] = "";
    assert(
            lastWordInFirstStringInSecondString(s3, s3).begin == NULL
    );
    char s4[] = "word4 word2 word5";
    word = lastWordInFirstStringInSecondString(s1, s4);
    char got[MAX_STRING_SIZE];
    wordDescriptorToString(word, got);
    ASSERT_STRING("word2", got);

}

void test_haveEqualWords(){
    char s1[] = "rg tr rg";
    char s2[] = " ffff ffffff ";
    char s3[] = " ";
    char s4[] = "v";
    assert(haveEqualWords(s1) == 1);
    assert(haveEqualWords(s2) == 0);
    assert(haveEqualWords(s3) == 0);
    assert(haveEqualWords(s4) == 0);
}
void test_all(){
    test_digitToStartTransform_oneWord();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_moveLettersInBeginDigitsInEnd();
    test_reverseDigitForSpaces();
    test_replace();
    test_areABCOrderedWords();
//    test_printWordsInReverse();
//    test_countWordsPalindromes();
    test_movingString_2();
    test_getWordReverseOrder();
    testAll_getWordBeforeFirstWordWithA();
    testAll_lastWordInFirstStringInSecondString();
    test_haveEqualWords();
}

int main(){
    test_all();
    return 0;
}