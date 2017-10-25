#include <stdio.h> 
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h>

pthread_t tid[2];

int pet[2] = {100, 100};

bool full(int type){
    if(pet[type] > 100) return true;
    else return false;
}

bool starve(int type){
    if(pet[type] <= 0) return true;
    else return false;
}

void *crabstat(void *arg){
    while(1){
        sleep(20);
        pet[0] -= 10;
    }
}

void *fishstat(void *arg){
    while(1){
        sleep(15);
        pet[1] -= 15;
    }
}