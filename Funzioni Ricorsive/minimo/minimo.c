static int MinimoRec(const int* v, int v_size, int i) {
	
	if (v_size - 1 == i) {
		return v[i];
	}

	int min = MinimoRec(v, v_size, i + 1);

	if (v[i] < min) {
		return v[i];
	}
	return min;
	

}
int Minimo(const int* v, int v_size) {
	
	return MinimoRec(v,v_size,0);
}