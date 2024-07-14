#include <stdlib.h>
extern int* Monete(const int* tagli, size_t tagli_size, int budget);

int main(void) {

	int tagli[6] = {50, 20, 10, 5, 2, 1};

	Monete(&tagli, 6, 126);

	return 0;
}