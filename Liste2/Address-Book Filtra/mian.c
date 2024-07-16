#include "list.h"
extern Item* Filtra(const Item* i, const char* city);

int main(void) {
	
	ElemType inidrizzi[5] = { 

		{"Angelo","Via Moneta",23,"Laterza","TA","74014"},
		{"Antonio","Via Montenero",3,"Matera","MA","39232"},
		{"Marco","Via Montenero",3,"Matera","MA","39232"},
		{"Francesco","Via Montenero",3,"Matera","MA","39232"},
		{"Antonio","via G.B. Vico",9,"Ginosa","TA","23439"}
	};
	
	
	
	const Item* i = ListCreateEmpty();

	for (size_t j = 0; j < 4; j++) {

		i = ListInsertBack(i, inidrizzi + j);

	}
	
	ListWriteStdout(i);
	
	i = Filtra(i, "Matera");

	printf("\n");
	ListWriteStdout(i);
	
	
	return 0;

}