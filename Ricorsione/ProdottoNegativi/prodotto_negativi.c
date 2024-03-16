#include <math.h>
int ProdottoNegativiRec(int a, int b) {
	if (a == 1) {
		return b;
	}
	else {
		a--;
		return b + ProdottoNegativiRec(a, b);
	}

	return 0;
}

int ProdottoNegativi(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}

	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		return - ProdottoNegativiRec(abs(a), abs(b)) ;
	}
	else {
		return ProdottoNegativiRec(abs(a), abs(b));
	}

	return 0;
}