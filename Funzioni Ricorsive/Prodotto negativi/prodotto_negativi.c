#include <math.h>

static int ProdottoNegativiRec(int a, int b) {

	if (a == 0 || b == 0) {
		return 0;
	}

	if (b == 1) {
		return a;
	}
	b--;
	return a + ProdottoNegativiRec(a, b);

}

int ProdottoNegativi(int a, int b) {
		

	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		return -ProdottoNegativiRec(abs(a), abs(b));
	}
	return ProdottoNegativiRec(abs(a), abs(b));

}




