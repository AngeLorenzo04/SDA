#include <time.h>
#include <stdio.h>
extern int Ombrelloni(int k, int n);

int main(void) {

	Ombrelloni(4, 7);
	Ombrelloni(2, 4);
	int tik = clock();
	Ombrelloni(4, 100);
	int tak = clock();
	int time = tak - tik/CLOCKS_PER_SEC;
	printf("la tua funzione ci ha messo: %d secondi", time);
	Ombrelloni(5, 7);
	return 0;
}