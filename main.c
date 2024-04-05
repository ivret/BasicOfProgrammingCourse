//lab17
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
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
    assert(findNonSpaceReverse(rend0 + 4, rend0 - 1) == rend0 + 4);
    char rend[] = "tiodfv " ;
    assert(findNonSpaceReverse(rend + 6,rend - 1) == rend + 6);
    char rend1[] = "  fg \n ";
    assert(findNonSpaceReverse(rend1 + 6,rend1 - 1) == rend1 + 6);
    char rend2[] = "";
    assert(findNonSpaceReverse(rend2 - 1, rend2 - 1) == rend2 - 1);
}

int main() {
    test_strlen_();
    test_finderNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    return 0;
}