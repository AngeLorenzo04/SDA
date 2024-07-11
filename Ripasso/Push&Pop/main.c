#include "vettore.h"
#include <time.h>
#include <stdio.h>

void printv(char* str, struct vettore* v) {

	printf("%s: ",str);
	for (size_t i = 0; i < v->size; i++) {
		printf("%d ", v->data[i]);
	}
	printf("\n");
	printf("\n");

}

int main(void) {

	srand(time(NULL));

	int *data = malloc(3 * sizeof(int));
	size_t size = 3;

	printf("prima della push: ");
	for (size_t i = 0; i < 3; i++) {
		data[i] = rand() % 10; 
		printf("%d ",data[i]);

	}
	printf("\n");
	printf("\n");

	
	struct vettore *v = malloc(sizeof(struct vettore));
	v->size = size;
	v->data = malloc(v->size * sizeof(int));
	v->data = data;	


	Push(v,5);
	printv("dopo della push", v);

	Pop(v);

	return 0;
}