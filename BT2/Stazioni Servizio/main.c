#include <stdlib.h>
extern void StazioniServizio(double m, const double* d, const double* p, size_t n);

int main(void) {
	double d[5] = { 260, 284,308,332,356 };
	double p[5] = { 35,35,33,29,23 };

	StazioniServizio(2500, d, p, 5);
	StazioniServizio(1000, d, p, 5);
	return 0;
}


/*		d[i]			p[i]

0: km 260.000000, prezzo 35.000000
1: km 284.000000, prezzo 35.000000
2: km 308.000000, prezzo 33.000000
3: km 332.000000, prezzo 29.000000
4: km 356.000000, prezzo 23.000000

|inizio|--------260------------|stazione 1|-------284-----------|stazione 2|-------308-----------|stazione 3|----------600-------|max percorribile|
 


 percorsi  + d[i] < maxKm 

 

*/