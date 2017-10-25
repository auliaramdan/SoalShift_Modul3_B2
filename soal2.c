#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char player[2][100];
int lubang[2][16], score[2];
int giliran = 0, winner = -1;

int isilubang(int index_lubang, int player) {
	if (index_lubang < 0 || index_lubang > 15) {
		return 0;
	} else if (!lubang[player][index_lubang]){
		lubang[player][index_lubang] = 1;
		return 1;
	}

	return 0;
}

int tebaklubang(int index_lubang, int player) {
	if (!lubang[player][index_lubang]) {
		return 1;
	} else {
		return 0;
	}
}

void *player1 (void *arg) {
	while (1) {
		while(giliran) {

		}

		system("clear");

		int i, jumlah_ranjau, nomor_lubang;

		printf("\n-= Giliran %s mengisi ranjau. =-\n", player[0]);
		printf("\nLubang yg sudah diisi ranjau: ");
		for (i = 0; i < 16; i++) {
			if (lubang[0][i]) printf("%d ", i+1);
		}
		
		int tmp = 0;
		for (i = 0; i < 16; i++) {
			tmp += lubang[0][i];
		}

		do {
			printf("\nBerapa jumlah lubang yg akan diisi ranjau? (Maksimal 4) ");
			scanf("%d", &jumlah_ranjau);
			if ((jumlah_ranjau >= 0 && jumlah_ranjau <= 4) && jumlah_ranjau <= 16-tmp ) {
				for (i = 0; i < jumlah_ranjau; i++) {
					printf("\nMasukkan nomor lubang yg akan diisi lubang (1-16): ");
					scanf("%d", &nomor_lubang);
					if (!isilubang(nomor_lubang-1, 0)) {
						printf("Input invalid!\n");
						i--;
					}
				}

				break;
			} else {
				printf("Input invalid!\n");
			}
		} while (1);

		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();
		getchar();

		system("clear");
		printf("\n-= Giliran %s menebak lubang yg tidak berisi ranjau. =-\n", player[1]);
		for (i = 0; i < 4; i++) {
			printf("Tebakan ke-%d. Masukkan nomor lubang yg ditebak (1-16): ", i+1);
			scanf("%d", &nomor_lubang);
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

		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();
		getchar();

		int tmp1 = 0;
		for (i = 0; i < 16; i++) {
			tmp1 += lubang[0][i];
		}

		int tmp2 = 0;
		for (i = 0; i < 16; i++) {
			tmp2 += lubang[1][i];
		}

		if (score[0] >= 10) {
			winner = 1;
			break;
		} else if (score[1] >= 10) {
			winner = 2;
			break;
		} else if (tmp1 == 16 && tmp2 == 16) {
			winner = 3;
			break;
		}

		system("clear");
		printf("-= SCORE =-\n");
		printf("\n%s: %d\n", player[0], score[0]);
		printf("%s: %d\n", player[1], score[1]);
		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();

		giliran = 1;
	}
}

void *player2 (void *arg) {
	while (1) {
		while(!giliran) {

		}

		system("clear");

		int i, jumlah_ranjau, nomor_lubang;

		printf("\n-= Giliran %s mengisi ranjau. =-\n", player[1]);
		printf("\nLubang yg sudah diisi ranjau: ");
		for (i = 0; i < 16; i++) {
			if (lubang[1][i]) printf("%d ", i+1);
		}

		int tmp = 0;
		for (i = 0; i < 16; i++) {
			tmp += lubang[0][i];
		}

		do {
			printf("\nBerapa jumlah lubang yg akan diisi ranjau? (Maksimal 4) ");
			scanf("%d", &jumlah_ranjau);
			if ((jumlah_ranjau >= 0 && jumlah_ranjau <= 4) && jumlah_ranjau <= 16-tmp ) {
				for (i = 0; i < jumlah_ranjau; i++) {
					printf("\nMasukkan nomor lubang yg akan diisi lubang (1-16): ");
					scanf("%d", &nomor_lubang);
					if (!isilubang(nomor_lubang-1, 1)) {
						printf("Input invalid!\n");
						i--;
					}
				}

				break;
			} else {
				printf("Input invalid!\n");
			}
		} while(1);

		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();
		getchar();

		system("clear");
		printf("\n\n-= Giliran %s menebak lubang yg tidak berisi ranjau. =-\n", player[0]);
		for (i = 0; i < 4; i++) {
			printf("Tebakan ke-%d. Masukkan nomor lubang yg ditebak (1-16): ", i+1);
			scanf("%d", &nomor_lubang);
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

		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();
		getchar();

		int tmp1 = 0;
		for (i = 0; i < 16; i++) {
			tmp1 += lubang[0][i];
		}

		int tmp2 = 0;
		for (i = 0; i < 16; i++) {
			tmp2 += lubang[1][i];
		}

		if (score[0] >= 10) {
			winner = 1;
			break;
		} else if (score[1] >= 10) {
			winner = 2;
			break;
		} else if (tmp1 == 16 && tmp2 == 16) {
			winner = 3;
			break;
		}

		system("clear");
		printf("-= SCORE =-\n");
		printf("\n%s: %d\n", player[0], score[0]);
		printf("%s: %d\n", player[1], score[1]);
		printf("\nTekan enter untuk melanjutkan.\n");
		getchar();

		giliran = 0;
	}
}

int main() {
	system("clear");
	int i;
	for (i = 0; i < 2; i++) {
		printf("Masukkan nama player %d: ", i+1);
		scanf("%s", player[i]);
		memset(lubang[i], 0, sizeof(int));
	}

	pthread_t tid[2];

	pthread_create(&(tid[0]), NULL, &player1, NULL);
	pthread_create(&(tid[1]), NULL, &player2, NULL);

	while (1) {
		if (winner == 1) {
			system("clear");
			printf("-= GAME OVER =-\n");
			printf("Player 1 win.\n");
			printf("\n* SCORE *\n");
			printf("%s: %d\n", player[0], score[0]);
			printf("%s: %d\n", player[1], score[1]);
			getchar();

			return 0;
		} else if (winner == 2) {
			system("clear");
			printf("-= GAME OVER =-\n");
			printf("Player 2 win.\n");
			printf("\n* SCORE *\n");
			printf("\n%s: %d\n", player[0], score[0]);
			printf("%s: %d\n", player[1], score[1]);
			getchar();

			return 0;
		} else if (winner == 3) {
			system("clear");
			printf("-= GAME OVER =-\n");
			printf("DRAW!.\n");
			printf("\n* SCORE *\n");
			printf("%s: %d\n", player[0], score[0]);
			printf("%s: %d\n", player[1], score[1]);
			getchar();

			return 0;
		}
	}
}