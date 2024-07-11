#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	
	if (argc != 3) {
		fprintf(stderr,"Il numero di parametri non è corretto.Sintassi del programma : occorrenze <s> <c>");
		return 1;
	}

	int occorrenze = 0;
	int i = 0;
	char* str = calloc(1, sizeof(argv[1]));
	char e = *argv[2];
	strcpy(str, argv[1]);

	while (str[i] != 0) {
		if (str[i] == e) {
			occorrenze++;
		}
		i++;
	}

	fprintf(stdout,"%d", occorrenze);


	return 0;
}