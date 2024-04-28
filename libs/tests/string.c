
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include "string.h"
#include <memory.h>

char _stringBuffer[MAX_STRING_SIZE+1];
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

int compareWords(WordDescriptor word1, WordDescriptor word2 ){
    while (word1.begin != word1.end &&
           word2.begin != word2.end &&
           *word1.begin == *word2.begin){
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
        if(!compareWords(word, word1))
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

bool areABCOrderedWords(char *s){
    WordDescriptor word;
    getWord(s, &word);

    WordDescriptor wordCurrent;
    int order;
    while(getWord(word.end, &wordCurrent)){
        if((order = compareWords(word, wordCurrent)) != 0) {
            word = wordCurrent;
            break;
        }
        word = wordCurrent;
    }

    while (getWord(word.end, &wordCurrent)){
        int res = compareWords(word, wordCurrent);
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


//void movingString_2(char* s1, char* s2, char* out) {
//    char* rec_ptr = out;
//    WordDescriptor word1, word2;
//    bool isW1Found, isW2Found;
//    char *beginSearch1 = s1, *beginSearch2 = s2;
//    while ((isW1Found = getWord(beginSearch1, &word1)),
//            (isW2Found = getWord(beginSearch2, &word2)),
//            isW1Found || isW2Found) {
//        if (isW1Found) {
//            beginSearch1 = word1.end;
//            rec_ptr = copyWord(rec_ptr, word1);
//            *rec_ptr = ' ';
//            rec_ptr++;
//        }
//        if (isW2Found) {
//            beginSearch2 = word2.end;
//            rec_ptr = copyWord(rec_ptr, word2);
//            *rec_ptr = ' ';
//            rec_ptr++;
//        }
//    }
//    if (rec_ptr != out)
//        rec_ptr--;
//
//    *rec_ptr = 0;
//}
void movingString_2(char *s1,char *s2,char *out) {
    char* res = out;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found){
            beginSearch1 = word1.end;
            res = copyWord(res,word1);
            *res = ' ';
            res++;
        }
        if (isW2Found){
            beginSearch2 = word2.end;
            res = copyWord(res,word2);
            *res = ' ';
            res++;
        }
    }
    if(out != res)
        res--;
    *res = 0;
}

int getWordReverse(char *r_begin, char *r_end, WordDescriptor *word){
    word->end = findNonSpaceReverse(r_begin , r_end);
    if (word->end == r_end)
        return 0;
    word->begin = findSpaceReverse(word->end, r_end) +1 ;
    word->end++;
    return 1;
}

void getWordReverseOrder(char *s) {
    if (*s == 0)
        return;

    strcpy_(_stringBuffer, s);
    WordDescriptor word = {getEndOfString(_stringBuffer), NULL};
    while (getWordReverse(word.begin-1, _stringBuffer-1, &word)) {
        s = copyWord(s, word);
        *s = ' ';
        s++;
    }
    s--;
    *s = 0;
}

bool isAlphaInWord(WordDescriptor *word, char c) {
    char* ptr = word->begin;
    while (ptr != word->end) {
        if (*ptr == c)
            return true;
        ptr++;
    }
    return false;

}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, WordDescriptor *w) {
    WordDescriptor word;
    if (!getWord(s, w))
        return EMPTY_STRING;
    if (isAlphaInWord(w, 'A'))
        return FIRST_WORD_WITH_A;
    while (getWord(w->end, &word)) {
        if (isAlphaInWord(&word, 'A'))
            return WORD_FOUND;
        else
            *w = word;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void wordDescriptorToString1(WordDescriptor word, char *destination) {
    destination = copyWord(destination, word);
    *destination = 0;
}

WordDescriptor lastWordInFirstStringInSecondString(char* s1, char* s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (int bag1_index =((int) _bag.size)-1; bag1_index >= 0; --bag1_index) {
        for (int bag2_index = 0; bag2_index < _bag2.size; ++bag2_index) {
            if (!compareWords(_bag.words[bag1_index], _bag2.words[bag2_index]))
                return _bag.words[bag1_index];
        }
    }
    return (WordDescriptor) {NULL, NULL};
}

bool haveEqualWords(char  *s){
    getBagOfWords(&_bag,s);
    for (int i = 0; i < ((int)_bag.size) - 1; ++i) {
        for (int j = i + 1; j < _bag.size; ++j) {
            if (!compareWords(_bag.words[i],_bag.words[j])){
                return true;
            }
        }
    }
    return false;
}

int compareSymbols(const void* p1,const void *p2){
    char c1 = *(const char *)p1;
    char c2 = *(const char *)p2;
    return c1 - c2;
}

void sortWord(WordDescriptor word){
    qsort(word.begin,word.end - word.begin,1,compareSymbols);
}

bool haveSetsEqualABC(char *s){
    strcpy_(_stringBuffer,s);
    WordDescriptor word = {NULL,_stringBuffer};
    while (getWord(word.end,&word)){
        sortWord(word);
    }
    return haveEqualWords(_stringBuffer);
}

//Получить строку из слов данной строки, которые отличны от последнего слова.

void printStrNoEqualLastWord(char *s){
    WordDescriptor lastWord;

    if(getWordReverse(getEndOfString(s) - 1,s -1,&lastWord) == 0){
        *s = 0;
        return;
    }
    WordDescriptor word = {NULL,s};
    while (getWord(word.end,&word)){
        if (compareWords(lastWord,word)) {
            s = copyWord(s, word);
            *s = ' ';
            s++;
        }
    }
    *(--s) = '\0';


}

WordDescriptor getPreviousFirstEqualWord(char  *s1, char  *s2){
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    for (int index_bag1 = 0; index_bag1 < ((int)_bag.size) - 1; ++index_bag1) {
        for (int index_bag2 = 0; index_bag2 < _bag2.size; ++index_bag2) {
            if (!compareWords(_bag.words[index_bag1],_bag2.words[index_bag2])){
                if (index_bag1 == 0){
                    return (WordDescriptor){NULL,NULL};
                }
                return _bag.words[index_bag1 - 1] ;
            }
        }
    }
    return (WordDescriptor){NULL,NULL};
}

bool isPalindromesWord(WordDescriptor word){
    word.end--;
    while (word.end > word.begin){
        if (*word.begin != *word.end){
            return false;
        }
        word.end--;
        word.begin++;
    }
    return true;
}

void deleteIsPalindromes(char *s){
    WordDescriptor word = {s,s};
    while (getWord(word.end,&word)){
        if(!isPalindromesWord(word)) {
            s = copyWord(s,word);
            *s = ' ';
            s++;
        }
    }
    *(s - 1) = '\0';
}

void complementStrBeforeThe(char* s, BagOfWords bag, size_t start_copy_index) {

        char *ptr = getEndOfString(s);
        if (ptr != s){
            *ptr = ' ';
            ptr++;
        }
        for (size_t i = start_copy_index; i < bag.size; ++i) {
            ptr = copyWord(ptr, bag.words[i]);
            *ptr = ' ';
            ptr++;
        }
        ptr--;
        *ptr = '\0';
    }

    void complementStrBeforeTheUniverse(char* s1, char* s2) {
        getBagOfWords(&_bag, s1);
        getBagOfWords(&_bag2, s2);
        if (_bag.size > _bag2.size){
            complementStrBeforeThe(s2, _bag, _bag2.size);
        }
        if (_bag.size < _bag2.size){
            complementStrBeforeThe(s1, _bag2, _bag.size);
        }
    }

bool isAllWordLettersStr(char* s, WordDescriptor word) {
    const int alphabet_size = 26;
    char buffer[alphabet_size];
    memset(buffer, 0, alphabet_size);
    int size = 0;
    char* ptr = word.begin;
    while (ptr != word.end) {
        if (buffer[*ptr-'a'] == 0) {
            buffer[*ptr - 'a'] = 1;
            size++;
        }
        ptr++;
    }
    ptr = s;
    while (*ptr && size) {
        if (buffer[*ptr -'a']) {
            buffer[*ptr-'a'] = 0;
            size--;
        }
        ptr++;
    }
    return size==0;
}