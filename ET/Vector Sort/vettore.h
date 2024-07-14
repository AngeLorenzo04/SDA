#pragma once
#include "elemtype.h"
#include <stdlib.h>



typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

extern void VectorSort(Vector* v);