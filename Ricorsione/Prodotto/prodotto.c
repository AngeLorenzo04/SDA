int ProdottoRec(int a, int b) {

	if (a == 1) {
		return b;
	}
	else {
		a--;
		return b + ProdottoRec(a, b);
	}

	return 0;
}


int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;

	}

	if (a == 0 || b == 0) {
		return 0;
	}

	return ProdottoRec(a,b);
}




/*

		caso base -> 1 * b ret b
		caso ricorsivo -> n + prodotto(n)
*/