#pragma once
#include "elemtype.h"
#include <stdlib.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

extern Vector* VectorRead(const char* filename);
extern Vector* VectorReadSorted(const char* filename);