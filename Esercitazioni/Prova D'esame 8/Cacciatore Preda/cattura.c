#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool PredaCatturata(const char* v, size_t v_size, int u, size_t i, bool* ctrl, int* ris, int* j) {

	
	for (*j = 1; *j <= u; (*j)++) {
		
		if ( (int)i - (int)*j >= 0 && ris[i] == -3 && ris[i - *j] == -3) { //controlla dietro
			if (v[i] != v[i - *j]) {
				return true;
			}
		}else if (i + *j < v_size && ris[i] == -3 && ris[i + *j] == -3) { //controlla avanti
			if (v[i] != v[i + *j]) {
				*ctrl = true;
				return true;
			}
		}
	}

	return false;
}

static void CacciatorePredaRec(const char* v, size_t v_size, int u, size_t i, int* ris, bool* ctrl) {

	int j = -1;

	*ctrl = false;

	if (i == v_size) {
		return;
	}

	if (ris[i] != -3) {
		CacciatorePredaRec(v, v_size, u, i + 1, ris, ctrl);
		return;
	}

	if (PredaCatturata(v, v_size, u, i, ctrl, ris, &j)) { //se è stata catturta una preda
		if ((v[i] == 'C' || v[i] == 'c')) {	//se sono il cacciatore che ha catturato 
			if (*ctrl) {
				ris[i] = (size_t)j + i;
				ris[j + i] = -2;
			}
			else {
				ris[i] = i - j;
				ris[(size_t)i - j] = -2;
			}
			CacciatorePredaRec(v, v_size, u, i + 1, ris, ctrl);
		}else {//se sono la preda catturata
			
			if (*ctrl) {
				ris[i] = -2;
				ris[j + i] = i;
			}else{
				ris[i] = -1;
			}
			CacciatorePredaRec(v, v_size, u, i + 1, ris, ctrl);
		}
	
	}else {

		ris[i] = -1;

		CacciatorePredaRec(v, v_size, u, i + 1, ris, ctrl);
	}
}


int* CacciatorePreda(const char* v, size_t v_size, int u) {

	int* ris = calloc(v_size, sizeof(int));

	for (size_t i = 0; i < v_size; i++) {

		ris[i] = -3;

	}
	
	bool ctrl = false;
	CacciatorePredaRec(v, v_size, u, 0, ris, &ctrl);
	return ris;

}

