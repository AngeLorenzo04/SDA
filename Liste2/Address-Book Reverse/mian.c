#include "list.h"

extern Item* Reverse(const Item* i);

int main(void) {
	
	ElemType inidrizzi[4] = { 

		{"Angelo","Via Moneta",23,"Laterza","TA","74014"},
		{"Francesco","Via Montenero",3,"Matera","MA","39232"},
		{"Michele","Via Montenero",3,"Matera","MA","39232"},
		{"Antonio","via G.B. Vico",9,"Ginosa","TA","23439"}
	};
	
	
	
	const Item* i = ListCreateEmpty();

	for (size_t j = 0; j < 4; j++) {

		i = ListInsertBack(i, inidrizzi + j);

	}
	
	ListWriteStdout(i);
	
	i = Reverse(i);

	printf("\n");
	ListWriteStdout(i);
	
	
	return 0;

}