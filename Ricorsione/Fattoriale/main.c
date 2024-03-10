extern unsigned long long Fattoriale(int n);


int main(void) {
	int s;
	s = Fattoriale(4); //24
	s = Fattoriale(1); //1
	s = Fattoriale(2); //2
	s = Fattoriale(3); //6
	s = Fattoriale(-1); //6
	s = Fattoriale(0); //6

	return 0;
}