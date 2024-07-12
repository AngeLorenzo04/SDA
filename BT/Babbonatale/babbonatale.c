#include <stdlib.h> 
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h>

static bool IsBest(bool* vcurr,bool* vbest, int cnt, int* max, size_t pacchi_size) {
	if (cnt > *max) {
		*max = cnt;
		memcpy(vbest, vcurr, pacchi_size);
	}
	return(cnt > *max);
}

static void Print(bool*vcurr, size_t pacchi_size) {
	for (size_t i = 0; i < pacchi_size; i++) {
		printf("%d ", vcurr[i]);
	}
	printf("\n");
}

static bool checkValid(const int* pacchi, size_t i,int sum, int p) {
	return((pacchi[i] + sum) < p);
}

static void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, bool* vcurr, bool * vbest, size_t i, int sum, int* max, int cnt) {
	
	if (i == pacchi_size) {
		IsBest(vcurr, vbest,cnt, max, pacchi_size);
		return;
	}

	vcurr[i] = 1;
	if (i == 0 || checkValid(pacchi, i, sum, p)) {
		BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, i + 1, sum + pacchi[i], max , cnt + 1);
	}
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, i + 1, sum, max, cnt);

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	
	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));

	int max = 0;

	BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, 0, 0,&max,0);
	Print(vbest, pacchi_size);

	free(vbest);
	free(vcurr);
	return;
}