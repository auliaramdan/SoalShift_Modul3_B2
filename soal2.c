#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char player[2][100];
int lubang[2][16];

void isilubang(int index_lubang, int player) {
	lubang[player][index_lubang] = 1;
}

int main() {
	system("clear");
	int i;
	for (i = 0; i < 2; i++) {
		printf("Masukkan nama player %d: ", i+1);
		scanf("%s", player[i]);
		memset(lubang[i], 0, sizeof(int));
	}

	return 0;
}