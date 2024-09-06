#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#define max 20

// single fork
// int main(){
//     fork();
//     printf("Hii there\n");
//     return 0;
// }

// multi fork
int main(){
    fork();
    printf("hello 1\n");
    fork();
    printf("hello 2\n");
    fork();
    printf("hello 3\n");
    return 0;
}
