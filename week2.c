#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int ar[20],n,sum = 0,status;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements in the array : ");
    // ar = {1,2,3,4,5,6};
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    pid = fork();
    wait(&status);
    if(pid == 0){
        for(int i=0;i<n;i++){
            if(ar[i]%2 == 0){
                sum+=ar[i];
            }
        }
        printf("Sum of even no is : %d",sum);
        exit(0);
    }else{
        for(int i=0;i<n;i++){
            if(ar[i]%2 != 0){
                sum+=ar[i];
            }
        }
        printf("Sum of odd no is : %d",sum);
    }
    return 0;
}
