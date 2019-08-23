//
// Created by CodeFace on 2019-08-23.
//

#include "size_offset.h"
#include <stddef.h>
#include <stdio.h>

struct Foo{
    char flag;
    int i;
    int j;
};

void size_offset_test() {
    Foo foo;

    // 内存对齐
    printf("sizeof flag: %ld\n", sizeof(foo.flag));
    printf("sizeof i: %ld\n", sizeof(foo.i));
    printf("sizeof j: %ld\n", sizeof(foo.j));
    printf("sizeof foo: %ld\n", sizeof(foo)); // not 9

    // 指针运算
    printf("offsetof i:%ld\n", offsetof(Foo, i));
    printf("offsetof j:%ld\n", offsetof(Foo, j));
    printf("offset between %ld\n", &foo.j - &foo.i); // wrong
    printf("offset between %ld\n", (char *)&foo.j - (char *)&foo.i); // correct
}
