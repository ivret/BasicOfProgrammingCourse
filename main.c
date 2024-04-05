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
    char s3[] = "asdf";
    assert(findNonSpaceReverse(s3 + 3, s3 - 1) == s3 + 3);
    char rend[] = "tiodfv " ;
    assert(*findNonSpaceReverse(rend + 7,rend - 1) == rend + 2);
    char rend1[] = "fg\n\n\n";
    assert(*findNonSpaceReverse(rend1 + 8,rend1 - 1) == rend1 + 6);
    char rend2[] = "sd      fr  ";
    assert(findNonSpaceReverse(rend2 + 11, rend2 - 1) == rend2 + 9);
}


int main() {
    test_strlen_();
    test_finderNonSpace();
    test_findSpace();

    return 0;
}