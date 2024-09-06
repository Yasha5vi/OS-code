#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    pid_t pid;
    char ar[100], str[100];
    int fd[2],nbr,nbw;
    pipe(fd);
    pid = fork();
    if(pid == 0){
        printf("\nEnter a string : ");
        gets(str);
        nbw = write(fd[1],str,strlen(str));
        printf("Child wrote %d bytes \n",nbw);
    }else{
        nbr = read(fd[0],ar,sizeof(ar));
        ar[nbr] = '\0';
        printf("Parent read %d bytes : %s\n",nbr,ar);
    }
    return 0;
}
