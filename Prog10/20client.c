#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int n,wfo,cfo;
	char buff[1000],fname[100];
	mknod("w",S_IFIFO|0666,0);
	mknod("c",S_IFIFO|0666,0);
	wfo=open("w",O_WRONLY);
	cfo=open("c",O_RDONLY);
	printf("Enter filename\n");
	gets(fname);
	write(wfo,fname,strlen(fname));
	n=read(cfo,buff,100);
	buff[n]='\0';
	printf("\n%s",buff);
	close(wfo);
	close(cfo);
}
