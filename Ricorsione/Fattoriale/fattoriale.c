unsigned long long FattorialeRec(int n) {
	if (n == 1) {
		return 1;
	}
	return FattorialeRec(n - 1) * n;
	
}

unsigned long long Fattoriale(int n) {
	if (n < 0) {
		return 0;
	}
	else if (n == 0) {
		return 1;
	}

	return FattorialeRec(n);
}
