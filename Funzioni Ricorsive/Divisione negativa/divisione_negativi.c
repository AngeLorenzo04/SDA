#include <stdlib.h>
#include <limits.h>
static int DivisioneRec(int a, int b, int tmp, int i) {

	if (b > a) {
		return i;
	}

	i++;
	b += tmp;
	return DivisioneRec(a, b, tmp, i);


}

int DivisioneNegativi(int a, int b) {

	if (b == 0) {
		return INT_MAX;
	}

	if ((a * b) > 0) {
		return DivisioneRec(abs(a), abs(b), abs(b), 0);
	}
	return -DivisioneRec(abs(a), abs(b), abs(b), 0);
	
}

