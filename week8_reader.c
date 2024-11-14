// reader.c of shared memeory
// opent the terminal 
// run the file and enter the data
// then execute the another file

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main(){
    key_t key;
    int shmid;
    void* ptr;
    key = ftok("shmfile",'A');
    shmid = shmget(key,1024,0666|IPC_CREAT);
    ptr=shmat(shmid,(void *)0,0);
    printf("Input Data : ");
    gets(ptr);
    shmdt(ptr);
    return 0;
}
