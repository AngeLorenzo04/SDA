#include <stdlib.h>
int* Monete(const int* tagli, size_t tagli_size, int budget) {

	if (tagli == NULL || budget <= 0) {
		return NULL;
	}

	int* ris = calloc(tagli_size , sizeof(int));

	
	for (size_t i = 0; i < tagli_size; i++) {
		while (budget >= tagli[i]) {
			ris[i]++;
			budget -= tagli[i];
		}
	}
	

	return ris;
}