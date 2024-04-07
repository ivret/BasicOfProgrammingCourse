//lab17
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include "libs/tests/string.h"
void test_strlen_(){
    assert(strlen_("ertyui") == 6);
    assert(strlen_("try yes") == 7);
    assert(strlen_("g") == 1);
    assert(strlen_("") == 0);
}

void test_finderNonSpace(){
    assert(*findNonSpace("ufhe") == 'u');
    assert(*findNonSpace("try") == 't');
    assert(*findNonSpace("") == 0);
    assert(*findNonSpace("ufhe") == 'u');
}
void test_findSpace(){
    assert(*findSpace("\t\n\n\n") == '\t');
    assert(*findSpace("tr y") == ' ');
    assert(*findSpace("u\n fhe") == '\n');
    assert(*findSpace("ufhe") == 0);
}


void test_findNonSpaceReverse(){
    char rend0[] = "forp";
    assert(findNonSpaceReverse(rend0 + 3, rend0 - 1) == rend0 + 3);
    char rend[] = "tiodfv " ;
    assert(findNonSpaceReverse(rend + 6,rend - 1) == rend + 5);
    char rend1[] = "  fg  \n";
    assert(findNonSpaceReverse(rend1 + 6,rend1 - 1) == rend1 + 3);
    char rend2[] = "";
    assert(findNonSpaceReverse(rend2 - 1, rend2 - 1) == rend2 - 1);
}

void test_findSpaceReverse(){
    char rend0[] = "forp\n";
    assert(findSpaceReverse(rend0 + 4, rend0 - 1) == rend0 + 4);
    char rend[] = "tiodfv " ;
    assert(findSpaceReverse(rend + 6,rend - 1) == rend + 6);
    char rend1[] = "  fg \n ";
    assert(findSpaceReverse(rend1 + 6,rend1 - 1) == rend1 + 6);
    char rend2[] = "";
    assert(findSpaceReverse(rend2 - 1, rend2 - 1) == rend2 - 1);
}

void test_compares_memory_location(){
    char a[] = "bdfgj";
    char a1[] = "aghff";
    assert(compares_memory_location(a,a1) == 1);
    char a2[] = "afgj";
    char a3[] = "fghff";
    assert(compares_memory_location(a2,a3) == -5);
    char a4[] = "Chernikov";
    char a5[] = "Chernikov";
    assert(compares_memory_location(a4,a5) == 0);
}

void test_copy(){
    char *a = "beginDistination";
    char d[17];
    assert(copy(a,a + 16,d) == memcpy(d,a,sizeof (char )*16));
    char *a1 = "begin";
    char d1[17];
    assert(copy(a1,a1 + 5,d1) == memcpy(d1,a1,sizeof (char )*5));
    char *a12 = "hello world";
    char d12[17];
    assert(copy(a12,a12 + 11,d12) == memcpy(d12,a12,sizeof (char )*11));
}

int main() {
    test_strlen_();
    test_finderNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_compares_memory_location();
    return 0;
}