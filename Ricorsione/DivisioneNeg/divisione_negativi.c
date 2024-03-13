#include <limits.h>
#include <math.h>
int DivisioneNegativiRec(int a, int b , int i, int tmp) {

	if (b > a) {
		return i;
	}
	else {
		i++;
		b += tmp;
		return DivisioneNegativiRec(a, b, i, tmp);
	}

	return 0;
}
int DivisioneNegativi(int a, int b) {


	if (b == 0) {
		return INT_MAX;
	}

	if ((a < 0 && b >0) || (a > 0 && b < 0)) {
		return -DivisioneNegativiRec(abs(a),abs(b),0,abs(b));
	}
	else {
		return  DivisioneNegativiRec(abs(a), abs(b),0,abs(b));
	}

	return 0;
}