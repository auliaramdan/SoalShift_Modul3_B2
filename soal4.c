#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *faktorial(void *arg) {
	int num = (int *) arg;

	int i;
	long double res = 1;
	for (i = 2; i <= num; i++) {
		res *= i;
	}

	printf("Hasil %d! = %.0Lf\n", num, res);
}

int main() {

	return 0;
}