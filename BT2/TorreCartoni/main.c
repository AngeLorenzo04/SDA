#include "torrecartoni.h"

int main(void) {

	Cartone c[2] = {{.p = 10,.a = 20,.l = 40}, {.p = 10,.a = 10,.l = 8}};
	TorreCartoni(c, 2);

	return 0;
}