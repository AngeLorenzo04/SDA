#include "vettore.h"

void Push(struct vettore* v, int d) {


    size_t nmem = v->size + 1;
    v->data = realloc(v->data, nmem * sizeof(int));
    v->data[nmem - 1] = d;
    v->size = nmem;

}

int Pop(struct vettore* v) {

    int ris = v->data[0];

    size_t nmem = v->size - 1;
    memmove(v->data, v->data + 1, nmem * sizeof(int));
    v->data = realloc(v->data, nmem *sizeof(int));

    v->size = nmem;

    
    
	return ris;
}