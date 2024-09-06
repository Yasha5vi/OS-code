#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    pid_t pid;
    pid = fork();
    int status;
    if(pid == 0){
        printf("I'm Child\n");
        exit(0);
    }else{
        wait(&status);
        printf("I'm Parent\n");
        printf("The Child PID = %d\n",pid);
    }
    return 0;
}
