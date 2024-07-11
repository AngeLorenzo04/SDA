extern unsigned long long Fattoriale(int n);
int main(void) {
	Fattoriale(-1);
	Fattoriale(0);
	Fattoriale(1); //1
	Fattoriale(2); //2
	Fattoriale(3); //6
	Fattoriale(4); //24
	Fattoriale(5); //120
	return 0;
}



/*	
	
	n=0   0
	n=1	  1

	n>1	  f(n-1)*n

*/