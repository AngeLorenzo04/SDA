#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int ContaOccorrenze(const char* filename, const char* str) {
	FILE* f = fopen(filename, "r");
	if (f == NULL || str == NULL) {
		return 0;
	}

	int occorrenze = 0;
	char parolaLetta[100];

	while (fscanf(f, "%s", parolaLetta) > 0) {
		if (strcmp(parolaLetta,str) == 0) {
			occorrenze++;
		}
		
	}

	fclose(f);

	return occorrenze;
}