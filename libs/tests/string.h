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


int getWord(char *beginSearch, WordDescriptor *word);

void ReverseWordstartAndGigitEnd();

char* copyWord(char *dest,WordDescriptor word);

void wordDescriptorToString(WordDescriptor word, char *destination);

void moveLettersInBeginDigitsInEndWord(WordDescriptor word);

void moveLettersInBeginDigitsInEnd(char *s);

char countSpase(char digit);

void replaceDigitSpace(char  *s);


#endif //BASICSOFPROGRAMMINGCOURSE_STRING_H
