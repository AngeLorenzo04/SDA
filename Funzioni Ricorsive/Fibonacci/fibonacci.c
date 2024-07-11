
static int F(int n) {
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	return F(n - 1) + F(n - 2);
}

int Fibonacci(int n) {
	if (n < 0) {
		return -1;
	}
	return F(n);
}