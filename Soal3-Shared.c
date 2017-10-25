#include <stdio.h> 
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h>
#include <stdbool.h>
#include <sys/ipc.h>
#include <sys/shm.h>

pthread_t tid[3];

int *pet;

bool full(int type){
    if(pet[type] > 100) return true;
    else return false;
}

bool starve(int type){
    if(pet[type] <= 0) return true;
    else return false;
}

void feed(){
    int choice;
    printf("\nPilih peliharaan yang akan diberi makan:\n1. Kepiting\n2. Lohan\nEnter: ");
    scanf("%d", &choice);
    choice--;
    if(choice == 0 || choice == 1) pet[choice] += 10;
    else printf("Piihan tidak valid");
}

void *crabstat(void *arg){
    while(1){
        sleep(20);
        pet[0] -= 10;
        if(full(0) == true || starve(0) == true) exit(EXIT_FAILURE);
    }
}

void *fishstat(void *arg){
    while(1){
        sleep(15);
        pet[1] -= 15;
        if(full(1) == true || starve(1) == true) exit(EXIT_FAILURE);
    }
}

void menu(){
    int command;
    printf("Masukkan perintah:\n1. Beri makan\n2. Lihat status\nEnter: ");
    scanf("%d", &command);
    switch(command){
        case 1:
        feed();
        break;
        case 2:
        printf("\n--------------------");
        printf("\nStatus kepiting: %d\n", pet[0]);
        printf("Status lohan:    %d\n", pet[1]);
        printf("--------------------\n\n");
        break;
        default:
        printf("Perintah tidak valid");
        break;
    }
}


int main(){

    key_t key = 1111;
    int shmid = shmget(key, sizeof(int)*3, IPC_CREAT | 0666);
    pet = shmat(shmid, NULL, 0);
    pet[0] = 100;
    pet[1] = 100;
    pthread_t crab_t, fish_t;
    pthread_create(&fish_t,NULL,&fishstat,NULL);
    pthread_create(&crab_t,NULL,&crabstat,NULL);
    
    while(1){
        if(full(0) == true || full(1) == true || starve(0) == true || starve(1) == true){
            printf("\n--------------------------");
            printf("\nStatus akhir kepiting: %d\n", pet[0]);
            printf("Status akhir lohan:    %d\n", pet[1]);
            printf("--------------------------\n");
            exit(EXIT_FAILURE);
        }
        else{
            menu();
        }
    }
    
}