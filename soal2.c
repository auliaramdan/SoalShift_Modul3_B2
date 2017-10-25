#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char player[2][100];
int lubang[2][16], score[2];
int giliran = 0;

int isilubang(int index_lubang, int player) {
	if (index_lubang < 0 || index_lubang > 15) {
		return 0;
	} else {
		lubang[player][index_lubang] = 1;
		return 1;
	}
}

int tebaklubang(int index_lubang, int player) {
	if (!lubang[player][index_lubang]) {
		return 1;
	} else {
		return 0;
	}
}

void *player1 (void *arg) {
	while(giliran) {

	}

	system("clear");

	int i, jumlah_ranjau, nomor_lubang;

	printf("\nGiliran %s mengisi ranjau.\n", player[0]);
	printf("\nBerapa jumlah lubang yg akan diisi ranjau? (Maksimal 4) ");
	scanf("%d", &jumlah_ranjau);
	if (jumlah_ranjau >= 0 && jumlah_ranjau <= 4) {
		printf("Lubang yg sudah diisi ranjau: ");
		for (i = 0; i < 16; i++) {
			if (lubang[0][i]) printf("%d ", i);
		}

		for (i = 0; i < jumlah_ranjau; i++) {
			printf("Masukkan nomor lubang yg akan diisi lubang (1-16): ");
			scanf("%d", &nomor_lubang);
			if (!isilubang(nomor_lubang-1, 0)) {
				printf("Input invalid!\n");
				i--;
			}
		}
	} else {
		printf("Input invalid!\n");
	}

	system("clear");
	printf("\nGiliran %s menebak lubang yg tidak berisi ranjau.\n", player[1]);
	for (i = 0; i < 4; i++) {
		printf("Tebakan ke-%d. Masukkan nomor lubang yg ditebak (1-16): ", i+1);
		scanf("%d", nomor_lubang);
		if (nomor_lubang > 0 && nomor_lubang <= 16) {
			if (tebaklubang(nomor_lubang-1, 0)) {
				printf("Benar!\n");
				score[1]++;
			} else {
				printf("Salah!\n");
				score[0]++;
			}
		} else {
			printf("Input invalid!\n");
			i--;
		}
	}

	giliran = 1;
}

void *player2 (void *arg) {
	while(!giliran) {

	}

	system("clear");

	int i, jumlah_ranjau, nomor_lubang;

	printf("\nGiliran %s mengisi ranjau.\n", player[1]);
	printf("\nBerapa jumlah lubang yg akan diisi ranjau? (Maksimal 4) ");
	scanf("%d", &jumlah_ranjau);
	if (jumlah_ranjau >= 0 && jumlah_ranjau <= 4) {
		printf("Lubang yg sudah diisi ranjau: ");
		for (i = 0; i < 16; i++) {
			if (lubang[1][i]) printf("%d ", i);
		}

		for (i = 0; i < jumlah_ranjau; i++) {
			printf("Masukkan nomor lubang yg akan diisi lubang (1-16): ");
			scanf("%d", &nomor_lubang);
			if (!isilubang(nomor_lubang-1, 1)) {
				printf("Input invalid!\n");
				i--;
			}
		}
	} else {
		printf("Input invalid!\n");
	}

	system("clear");
	printf("\nGiliran %s menebak lubang yg tidak berisi ranjau.\n", player[0]);
	for (i = 0; i < 4; i++) {
		printf("Tebakan ke-%d. Masukkan nomor lubang yg ditebak (1-16): ", i+1);
		scanf("%d", nomor_lubang);
		if (nomor_lubang > 0 && nomor_lubang <= 16) {
			if (tebaklubang(nomor_lubang-1, 1)) {
				printf("Benar!\n");
				score[0]++;
			} else {
				printf("Salah!\n");
				score[1]++;
			}
		} else {
			printf("Input invalid!\n");
			i--;
		}
	}

	giliran = 0;
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