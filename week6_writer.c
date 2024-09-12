#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd,nbw;
	char str[100];
	mknod("myfifo",S_IFIFO|0666,0);
	printf("Writing for reader process :\n\t");
	fd = open("myfifo",O_WRONLY);
	while(gets(str)){
		nbw = write(fd,str,strlen(str));
		printf("Writer process write %d bytes: %s\n",nbw,str);
	}
	return 0;
}

// Note - to run the code make both the files 
// and run them simultaneously and in the two 
// terminals test the code type something in 
// the writer terminal and it will gets read 
// in the reader terminal 
