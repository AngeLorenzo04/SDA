#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	
	if (argc != 3) {
		fprintf(stderr,"Il numero di parametri non è corretto. Sintassi del programma: \"occorrenze <s> < c>\"");
		return 1;
	}


	char* endptr;
	int a = strtol(argv[1], &endptr, 10);
	int b = strtol(argv[2], &endptr, 10);
	

	fprintf(stdout, "%d", a * b);

	return 0;
}