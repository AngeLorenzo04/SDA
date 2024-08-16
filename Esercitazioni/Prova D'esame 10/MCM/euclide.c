int MCD(int m, int n) {
	
	//caso base
	if (n == 0) {
		return m;
	}

	return MCD(n, m % n);
	
}


