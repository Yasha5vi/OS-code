#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        sleep(5);
        printf("\n I'm child. My PID = %d And PPID = %d",getpid(),getppid());
    }else{
        printf("I'm Parent. My Child PID = %d and my PID = %d",pid,getpid());
    }printf("\nTerminating PID = %d\n",getpid());
    return 0;
}
