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


int main() {
    test_strlen_();
    return 0;
}