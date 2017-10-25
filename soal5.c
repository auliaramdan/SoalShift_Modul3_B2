#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *search(void *arg) {
	FILE *file = fopen("Novel.txt", "r");
	int res = 0;
	char *kata = (char *) arg;
	char word[1024];

	while (fscanf(file,"%s", word) != EOF) {
		// if (strcmp(word, kata) == 0) res++;
		if (strstr(word, kata) != NULL) {
			res++;
		}
	}

	printf("%s : %d\n", kata, res);

	fclose(file);
}

int main(int argc, char *argv[]) {
	pthread_t tid[argc-1];
	int i;

	for (i = 0; i < argc-1; i++) {
		pthread_create(&(tid[i]), NULL, &search, (void*) argv[i+1]);
	}

	for (i = 0; i < argc-1; i++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}