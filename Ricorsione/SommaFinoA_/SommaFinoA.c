#include "SommaFinoA.h"
static int SommaFinoARec(int n) { //funzione ricorsiva
	if (n == 1) {
		return 1;
	}
	return SommaFinoARec(n - 1) + n;
}
int SommaFinoA(int n) {  //check delle regole
	
	if (n <= 0) {
		return -1;
	}

	return SommaFinoARec(n);

}