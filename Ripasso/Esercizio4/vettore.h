#pragma once
#include <stdlib.h>
#include <string.h>
struct vettore {
    int* data;
    size_t size;
};
extern void Push(struct vettore* v, int d);
extern int Pop(struct vettore* v);