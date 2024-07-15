#include "list.h"
extern const ElemType* Find(const Item* i, const char* name);

int main(void) {
	
	ElemType inidrizzi[4] = { 

		{"Angelo","Via Moneta",23,"Laterza","TA","74014"},
		{"Francesco","Via Montenero",3,"Matera","MA","39232"},
		{"Antonio","via G.B. Vico",9,"Ginosa","TA","23439"}
	};

	Item* i = ListCreateEmpty();

	for (size_t j = 0; j < 4; j++) {

		i = ListInsertBack(i, inidrizzi + j);

	}

	

	printf("città: %s, nome: %s, indirizzo: %s, numero civico: %i, cap: %s,  provincia: %s",
		Find(i, "Antonio")->city, Find(i, "Antonio")->name, Find(i, "Antonio")->street, Find(i, "Antonio")->number, Find(i, "Antonio")->postal_code, Find(i, "Antonio")->province);

	return 0;

}