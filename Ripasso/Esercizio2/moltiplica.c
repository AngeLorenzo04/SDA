#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "%s", "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> < b>\"");
		return 1;
	}

	char* endptr;
	int a = strtol(argv[1], &endptr, 10);
	//if (*endptr != 0) {
	//	return 1;
	//}
	int b = strtol(argv[2], &endptr, 10);

	int ris = a * b;

	fprintf(stdout, "%d", ris);

	return 0;

}