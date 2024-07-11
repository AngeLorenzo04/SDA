static int DivisioneRec(int a, int b, int tmp, int i) {

	if (b > a) {
		return i;
	}

	i++;
	b += tmp;
	return DivisioneRec(a, b, tmp, i);


}

int Divisione(int a, int b) {

	

	if (a < 0 || b <= 0) {
		return -1;
	}

	return DivisioneRec(a,b,b, 0);
}

