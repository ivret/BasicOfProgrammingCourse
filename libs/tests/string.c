
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"

char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
BagOfWords _bag2;

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
    //char* findNonSpace(char *begin) – возвращает указатель на первый
    //символ, отличный от пробельных46, расположенный на ленте памяти,
    // начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
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

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}
char* copyWord(char *dest,WordDescriptor word){
    return copy(word.begin,word.end,dest);
}

void wordDescriptorToString(WordDescriptor word, char *destination){
    *copyWord(destination,word) = '\0';
}

void moveLettersInBeginDigitsInEndWord(WordDescriptor word){
    wordDescriptorToString(word,_stringBuffer);
    char *ptrWrite = word.begin;
    char *ptrRead = _stringBuffer;
    while (*ptrRead != 0){
        if (isalpha(*ptrRead)){
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead++;
    }
    ptrRead = _stringBuffer;
    while (*ptrRead != 0){
        if (isdigit(*ptrRead)){
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead++;
    }
}

void moveLettersInBeginDigitsInEnd(char *s){
    WordDescriptor word = {s,s};
    while (getWord(word.end,&word)){
        moveLettersInBeginDigitsInEndWord(word);
    }
}

//Преобразовать строку, заменяя каждую цифру соответствующим ей числ
//пробелов. Имеются такие задачи, при которых размер строки может увеличиться.
// Мы пока что будем исходить из предположения, что размер итоговой
//строки не превысит некоторого MAX_STRING_SIZE определенного в string_.h
char* writeSpaces(char digitCods,char *s){
    int digit = digitCods - '0';
    for (int i = 0; i < digit; ++i) {
        *s = ' ';
        s++;
    }
    return s;
}

void replaceDigitSpace(char  *s){
    strcpy_(_stringBuffer,s);
    char *ptrWrite = s;
    char *ptrRead = _stringBuffer;
    while (*ptrRead != 0){
        if (isdigit(*ptrRead)){
            ptrWrite = writeSpaces(*ptrRead,ptrWrite);
        }
        else{
            *ptrWrite = *ptrRead;
            ptrWrite++;
        }
        ptrRead++;
    }
    *ptrWrite = '\0';
}

int compareWord(WordDescriptor word1, WordDescriptor word2 ){
    while (word1.begin != word1.end &&
           word2.begin != word2.end &&
           *word1.begin == *word1.end){
        word1.begin++;
        word2.begin++;
    }
    if(word1.begin == word1.end &&
       word2.begin == word2.end)
        return 0;
    else
        return *word1.begin - *word2.begin;

}
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
    WordDescriptor word;
    while (getWord(readPtr,&word)){
        if(!compareWord(word, word1))
            recPtr = copyWord(recPtr,word2);
        else{
            recPtr = copyWord(recPtr,word);

        }
        *recPtr = ' ';
        recPtr ++;
        readPtr = word.end;
    }
    recPtr--;
    *recPtr = '\0';
}
int getWord1(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}



bool areABCOrderedWords(char *s){
    WordDescriptor word;
    getWord(s, &word);

    WordDescriptor wordCurrent;
    int order;
    while(getWord(word.end, &wordCurrent)){
        if((order = compareWord(word, wordCurrent)) != 0) {
            word = wordCurrent;
            break;
        }
        word = wordCurrent;
    }

    while (getWord(word.end, &wordCurrent)){
        int res = compareWord(word, wordCurrent);
        if (res != order)
            return false;
        word = wordCurrent;
    }

    return true;
}



void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word1 = {s, s};
    bag->size = 0;

    while (getWord(word1.end, &word1)) {
        bag->words[bag->size++] = word1;
    }
}

//void printWordsInReverse(BagOfWords *bag) {
//    for (int i = bag->size - 1; i >= 0; i--) {
//        WordDescriptor2 word = bag->words[i];
//        printf("%.*s\n", word.length, word.word);
//    }
//
//}

bool isPalindromis(char  *s,char start,char finish){
    while (start < finish){
        if(s[start] != s[finish])
            return false;
        start++;
        finish--;
    }
    return true;
}
int countWordsPalindromes(char *s) {
    int counter = 0;
    WordDescriptor word = {s, s};
    while (*word.end != 0) {
        while (*word.end != ',' && *word.end != 0) {
            word.end++;
        }

        s = word.end--;
        while (word.begin < word.end &&*word.begin == *word.end) {
            word.begin++;
            word.end--;
        }

        if (word.begin >= word.end)
            counter++;

        if (*s != 0)
            word.begin = word.end = ++s;
        else
            word.end = s;
    }
    return counter;
}


void movingString_2(char* s1, char* s2, char* out) {
    char* rec_ptr = out;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            beginSearch1 = word1.end;
            rec_ptr = copyWord(rec_ptr, word1);
            *rec_ptr = ' ';
            rec_ptr++;
        }
        if (isW2Found) {
            beginSearch2 = word2.end;
            rec_ptr = copyWord(rec_ptr, word2);
            *rec_ptr = ' ';
            rec_ptr++;
        }
    }
    if (rec_ptr != out)
        rec_ptr--;

    *rec_ptr = 0;
}





