#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
struct Matrix {
    size_t size;
    bool* data;
};
#define E(m,r,c) m->data[r * m->size + c]
extern int MappaColori(const struct Matrix* m, const char* c, size_t c_size);