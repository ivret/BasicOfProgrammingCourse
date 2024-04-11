////lab17
//#include <malloc.h>
//#include <stdio.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <memory.h>
//#include <ctype.h>
//#include "libs/tests/string.h"
//void test_strlen_(){
//    assert(strlen_("ertyui") == 6);
//    assert(strlen_("try yes") == 7);
//    assert(strlen_("g") == 1);
//    assert(strlen_("") == 0);
//}
//
//void test_finderNonSpace(){
//    assert(*findNonSpace("ufhe") == 'u');
//    assert(*findNonSpace("try") == 't');
//    assert(*findNonSpace("") == 0);
//    assert(*findNonSpace("ufhe") == 'u');
//}
//void test_findSpace(){
//    assert(*findSpace("\t\n\n\n") == '\t');
//    assert(*findSpace("tr y") == ' ');
//    assert(*findSpace("u\n fhe") == '\n');
//    assert(*findSpace("ufhe") == 0);
//}
//
//
//void test_findNonSpaceReverse(){
//    char rend0[] = "forp";
//    assert(findNonSpaceReverse(rend0 + 3, rend0 - 1) == rend0 + 3);
//    char rend[] = "tiodfv " ;
//    assert(findNonSpaceReverse(rend + 6,rend - 1) == rend + 5);
//    char rend1[] = "  fg  \n";
//    assert(findNonSpaceReverse(rend1 + 6,rend1 - 1) == rend1 + 3);
//    char rend2[] = "";
//    assert(findNonSpaceReverse(rend2 - 1, rend2 - 1) == rend2 - 1);
//}
//
//void test_findSpaceReverse(){
//    char rend0[] = "forp\n";
//    assert(findSpaceReverse(rend0 + 4, rend0 - 1) == rend0 + 4);
//    char rend[] = "tiodfv " ;
//    assert(findSpaceReverse(rend + 6,rend - 1) == rend + 6);
//    char rend1[] = "  fg \n ";
//    assert(findSpaceReverse(rend1 + 6,rend1 - 1) == rend1 + 6);
//    char rend2[] = "";
//    assert(findSpaceReverse(rend2 - 1, rend2 - 1) == rend2 - 1);
//}
//
//void test_strcmp(){
//    char a[] = "bdfgj";
//    char a1[] = "aghff";
//    assert(strcmp2(a, a1) == 1);
//    char a2[] = "afgj";
//    char a3[] = "fghff";
//    assert(strcmp2(a2, a3) == -5);
//    char a4[] = "Chernikov";
//    char a5[] = "Chernikov";
//    assert(strcmp2(a4, a5) == 0);
//}
//
//
//void test_copy(){
//    char *a = "be";
//    char d[17];
//    copy(a,a + 3,d);
//    assert(!strcmp2(a,d));
//    char *a1 = "begin";
//    char d1[17];
//    copy(a1,a1 + 6,d1);
//    assert(!strcmp2(a1,d1));
//    char *a12 = "hello world";
//    char d12[17];
//    copy(a12,a12 + 12,d12);
//    assert(!strcmp2(a12,d12) );
//}
//
//int isNotSpace(int c){
//    return !isspace(c);
//}
//
//void test_copyIf(){
//    char src[] = "Init0 1Local2 3Machine4";
//    char dest[20];
//
//    char s1[] = "Init01Local";
//    copyIf(src, src + 14, dest, isNotSpace);
//    assert(!memcmp(dest, s1, 11));
//
//    char s2[] = "  ";
//    copyIf(src, src + 19, dest, isspace);
//    assert(!memcmp(dest, s2, 2));
//
//    char s3[] = "nitocal";
//    copyIf(src, src + 14, dest, islower);
//    assert(!memcmp(dest, s3, 7));
//}
//
//void test_copyIfReverse() {
//    char a[] = "copy 123 false23";
//    char d[30];
//    char s1[] = "  ";
//    copyIfReverse(a + 16,a - 1,d,isspace);
//    assert(!memcmp(d,s1,2));
//
//    char s2[] = "32eslaf321ypoc";
//    copyIfReverse(a + 16,a - 1,d,isNotSpace);
//    assert(!memcmp(d,s2,2));
//
//
//}
//
//int main() {
//    test_strlen_();
//    test_finderNonSpace();
//    test_findSpace();
//    test_findNonSpaceReverse();
//    test_findSpaceReverse();
//    test_strcmp();
//    test_copy();
//    test_copyIf();
//    test_copyIfReverse();
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
