#include "vettore.h"
int main(void) {
	int *data = malloc(10 * sizeof(int));

	for (size_t i = 0; i < 10; i++) {
		data[i] = i + 1;
	}
	
	struct vettore vet1 = {data , 10};
	struct vettore vet2 = {data , 10};

	Push(&vet1, 0);
	Pop(&vet2);
}