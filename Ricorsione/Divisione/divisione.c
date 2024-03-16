int DivisioneRec(int a, int b, int i, int tmp) {

	if (b > a) {
		return i;
	}
	else {
		i++;
		b += tmp;
		return DivisioneRec(a, b, i, tmp);
	}
}
int Divisione(int a, int b) {

	if (b == 0) {
		return -1;
	}

	if (a < 0 || b < 0) {
		return -1;
	}

	int i = 0;

	return DivisioneRec(a, b, i, b);


	return 0;
}

/*
	4/2 
	2 + 2 = 4

	6 / 2 = 3
	2 + 2 + 2 = 6 
	
	7 / 2
	2 + 2 + 2 = 

*/