// -----------------------------------------------------------------------------------------------------------------------------
//    From quora.com
//    How do I iterate efficiently through an array of ints of unknown size in C (where each element must be nonzero)?
//    
//    ====
//    Dima Korolev
//    With a pointer.
//    
//    void iterate(const int* p) {
//      while (*p) {
//        // const int v = *p;
//        // do_something(*p);
//        ++p;
//      }
//    }
//    
//    Much like with null-terminated strings that are const char* pointers.
//    Further reading: strcpy() -- How and Why Does It "Just Work"?
//    
//    ====
//    Satyanarayana Shanmugam
//    Aren't you assuming that the integer array is null terminated in your code?
//    I thought that was implicitly true for only char*?
//    Shouldn't we first calculate the ptr for the end of the array, and then continue while p != ptr?
//    
//    ====
//    Dima Korolev
//    No.
//    There is no such thing as the length of an array in C, when it is passed by the pointer.
//    Also, the question explicitly says "where each element must be nonzero".
//    I read it as "the zero element indicates the end of the array".
//    
//    ====
//    Satyanarayana Shanmugam
//    Doesn't the sizeof(p)/sizeof(p[0]) technique work on pointers?
//    
//    ====
//    Dima Korolev
//    No.
//    Compile & run this and be surprised :-)
// -----------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
int foo(int p[5]) {
    printf("%d\n", (int)(sizeof(p) / sizeof(p[0])));
}
int main() {
    int p[10];
    foo(p);
}

