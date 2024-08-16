#include <stdlib.h>
#include <string.h>


static void AToIRec(char* str, size_t i, int* ris, int pow) {
	
	int val = atoi(str + i); //conversione
	
	if (i == 0) { //caso base

		if (str[i] == '-') { 
			*ris *= -1;
		}
		else {
			*ris += val * pow; //aggiorno risultato
			str[i] = 0;
		}

		return;
	}
	

	if (val == 0 && str[i] != '0') { // caso in cui il carattere non e valido
		AToIRec(str,i - 1, ris, pow);
	}

	*ris += val * pow; //aggiorno risultato
	str[i] = 0;//aggiorno la fine della stringa

	AToIRec(str, i - 1, ris, pow * 10);//chiamata ricorsiva
}

int AToI(const char* str) {
	
	if (str == NULL) {
		return 0;
	}

	int ris = 0;

	//calcolo la lunghezza di str
	size_t size = 0;
	while( str[size] != 0) {
		size++;
	}
	
	// creo una copia della stringa modificabile
	char* strtmp = malloc(size);
	memcpy(strtmp, str, size);

	//chiamata ricorsiva
	AToIRec(strtmp, size - 1, &ris, 1);

	free(strtmp);

	return ris;
}