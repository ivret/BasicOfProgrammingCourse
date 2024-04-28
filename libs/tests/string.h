//
// Created by Иван on 04.04.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_STRING_H
#define BASICSOFPROGRAMMINGCOURSE_STRING_H
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20


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
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

int compareWords(WordDescriptor word1, WordDescriptor word2 );

int getWord(char *beginSearch, WordDescriptor *word);

void ReverseWordstartAndGigitEnd();

char* copyWord(char *dest,WordDescriptor word);

void wordDescriptorToString(WordDescriptor word, char *destination);

void moveLettersInBeginDigitsInEndWord(WordDescriptor word);

void moveLettersInBeginDigitsInEnd(char *s);

char countSpase(char digit);

void replaceDigitSpace(char  *s);

void replace(char *source, char *w1, char *w2);

bool areABCOrderedWord(char *s);

bool areABCOrderedWords(char *s);

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef struct WordDescriptor2 {
    char *word;
    int length;
} WordDescriptor2;

extern char _stringBuffer[MAX_STRING_SIZE+1];
extern BagOfWords _bag;
extern BagOfWords _bag2;

void getBagOfWords(BagOfWords *bag, char *s);

void printWordsInReverse(BagOfWords *bag);

int countWordsPalindromes(char *s);

int palindrome(char  *s,char start,char finish);

void movingString_2(char* s1, char* s2, char* out);

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

void getWordReverseOrder(char *s);

void printWordBeforeFirstWordWithA(char *s);

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, WordDescriptor *w);

void wordDescriptorToString1(WordDescriptor word, char *destination);

WordDescriptor lastWordInFirstStringInSecondString(char* s1, char* s2);

bool haveEqualWords(char  *s);

bool haveSetsEqualABC(char *s);

void printStrNoEqualLastWord(char *s);

WordDescriptor getPreviousFirstEqualWord(char  *s1, char  *s2);
#endif //BASICSOFPROGRAMMINGCOURSE_STRING_H
