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
    assert(findNonSpace("ufhe") == 'u');
    assert(findNonSpace("try") == 't');
    assert(findNonSpace("") == 0);
    assert(findNonSpace("ufhe") == 'u');
}
void test_findSpace(){
    assert(findNonSpace("u\n fhe") == '\n');
    assert(findNonSpace("tr y") == ' ');
    assert(findNonSpace("\n\n\n") == '\n');
    assert(findNonSpace("ufhe") == 0);
}


int main() {
    test_strlen_();
    test_findSpace();
    return 0;
}