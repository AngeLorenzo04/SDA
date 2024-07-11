extern int Minimo(const int* v, int v_size);

int main(void) {

	int v[4] = { 1,3,2,4 };
	int v_size = sizeof(v) / sizeof(int);
	Minimo(v, v_size);

	return 0;
}

