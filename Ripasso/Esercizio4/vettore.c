#include "vettore.h"
void Push(struct vettore* v, int d) {
	
	size_t a = v->size + 1;
	
	v->data = realloc(v->data, a * sizeof(int));
	v->data[v->size] = d;


}
int Pop(struct vettore* v) {

	int ris = v->data[0];

	int tmp = v->data[v->size];

	v->size--;
	memmove(v->data, v->data + 1, v->size * sizeof(int));
	v->data = realloc(v->data, v->size * sizeof(int));


	return ris;
}
/*

 s
 


*/
