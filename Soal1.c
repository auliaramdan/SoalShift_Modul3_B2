#include <stdio.h> 
#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
//#include<stdlib.h> 
#include<unistd.h> 
//#include<stdlib.h>

pthread_t tid;

int main(){
	int senjata[4];
	int command;
	printf ("Menu:\n1. Lihat Stock\n2. Tambah Stock");
	scanf("%d", &command);
	switch(command){
	case 1:
	printf("Stock senjata:");
	break;
	case 2:
	printf("Tambah senjata:");
	break;
	default:
	break;
	}

return 0;
}

