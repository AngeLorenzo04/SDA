#include <stdlib.h>
extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);
int main(void) {

	int pacchi[8] = { 10, 15, 13, 100, 23, 49, 30, 5 };

	BabboNatale(pacchi, 8, 100);

	return 0;
}
