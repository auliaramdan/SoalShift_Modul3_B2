#include <stdio.h>
#include <thread.h>
#include <stdlib.h>

void *search(void *arg) {
	int res = 0;
	char *kata = (char *) arg;
	char word[1024];

	while (fscanf(file,"%s", word) != EOF) {
		if (strcmp(word, kata) == 0) res++;
		printf("%s\n", word);
	}

	printf("%s : %d\n", kata, res);
}

int main(int argc, char *argv[]) {


	return 0;
}