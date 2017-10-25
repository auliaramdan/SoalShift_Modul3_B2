#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *faktorial(void *arg) {
	int num = *((int *) arg);

	int i;
	long double res = 1;
	for (i = 2; i <= num; i++) {
		res *= i;
	}

	printf("Hasil %d! = %.0Lf\n", num, res);
}

int main(int argc, char *argv[]) {
	pthread_t tid[argc-1];
	int i;

	for (i = 0; i < argc-1; i++) {
		int *nmr = (int*) malloc(sizeof(*nmr));
		*nmr = atoi(argv[i+1]);
		pthread_create(&(tid[i]), NULL, &faktorial, (void*) nmr);
	}

	for (i = 0; i < argc-1; i++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}