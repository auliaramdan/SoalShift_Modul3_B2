#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char player[2][100];
int lubang[2][16];

int isilubang(int index_lubang, int player) {
	if (index_lubang < 0 || index_lubang > 15) {
		return 0;
	} else {
		lubang[player][index_lubang] = 1;
		return 1;
	}
}

int tebaklubang(int index_lubang, int player) {
	if (index_lubang < 0 || index_lubang > 15) {
		return 0;
	} else if (lubang[player][index_lubang]) {
		return 1;
	}

	return 0;
}

void *player1 (void *arg) {

}

void *player2 (void *arg) {

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