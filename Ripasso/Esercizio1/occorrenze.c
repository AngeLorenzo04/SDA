#include <stdlib.h>
#include<stdio.h>

int main(int argc, char** argv) {

	if (argc != 3) {
		printf(stderr, "%s", "Il numero di parametri non e' corretto.Sintassi del programma : \"occorrenze <s> < c>\"");
		return 1;
	}

	int count = 0;
	int i = 0;
	while (argv[1][i] != 0) {
		if (argv[1][i] == *argv[2]) {
			count++;
		}
		i++;
	}
	printf("%i", count);
	return 0;
}