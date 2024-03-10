#include <stdlib.h>

int MinimoRec(const int* v, int v_size,int Min) {

	if (Min >= v[v_size]) {
		Min = v[v_size];
	}

	if (v_size == 0) {

		return Min;

	}
	else {
		v_size--;
		return MinimoRec(v, v_size, Min);
	}

}


int Minimo(const int* v, int v_size) {
	v_size--;
	int ris = v[v_size];
	return MinimoRec(v, v_size, ris);
}




	/*for (int i = 0; i < v_size; i++) {
		if (v[v_size - 1] <= v[i]) {
			ris = v[v_size - 1];
		}
		else {
			v_size--;
			return Minimo(v, v_size);
		}
	}*/


