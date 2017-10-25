#include <stdio.h> 
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdbool.h>

int *total;
const char *weapon[6] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};
//key_t key = 1111;

void modifyStock(char weap[7], int amount){
	if(strcmp(weap, "MP4A1") == 0){
        if(amount <= total[0]) {
			total[0] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
	else if(strcmp(weap, "PM2-V1") ==0){
        if(amount <= total[1]) {
			total[1] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
    else if(strcmp(weap, "SPR-3") ==0){
        if(amount <= total[2]) {
			total[2] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
    else if(strcmp(weap, "SS2-V5") ==0){
        if(amount <= total[3]) {
			total[3] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
    else if(strcmp(weap, "SPG1-V3") ==0){
        if(amount <= total[4]) {
			total[4] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
    else if(strcmp(weap, "MINE") ==0){
        if(amount <= total[5]) {
			total[5] -= amount;
			printf("Nota: %s %d\n\n", weap, amount);
		}
        else printf("barang di stock tidak cukup\n");
    }
}
void menu(){
	bool exit = false;
	char stock[7];
	int senjata[4];
	int command, amount;
	while(!exit){
		printf ("Menu:\n1. Lihat Stock\n2. Beli Stock\n3. Exit\nEnter: ");
		scanf("%d", &command);
		switch(command){
		case 1:
		printf("\nStock senjata:\n");
		for(int i=0; i<6; i++){
		printf("%s %d\n", weapon[i], total[i]);
		}
		printf("\n");
		break;
		case 2:
		printf("\nBeli senjata:\n");
		scanf("%s %d", &stock, &amount);
		modifyStock(stock, amount);
		break;
		case 3:
		exit = true;
		break;
		default:
		break;
		}
	}
}

int main(){
	key_t key = 123;
	int shmid = shmget(key, sizeof(int)*3, IPC_CREAT | 0666);
	total = shmat(shmid, NULL, 0);
	menu();
	shmdt(total);
	shmctl(shmid, IPC_RMID, NULL);
return 0;
}

