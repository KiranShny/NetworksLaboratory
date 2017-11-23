#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int n,wfo,cfo,cf;
	char buff[1000],buff1[100];
	mknod("w",S_IFIFO|0666,0);
	mknod("c",S_IFIFO|0666,0);
	printf("Server is waiting\n");
	while(1)
	{
	  wfo=open("w",O_RDONLY);
	  cfo=open("c",O_WRONLY);
	  n=read(wfo,buff,1000);
	  buff[n]='\0';
          cf=open(buff,0,O_RDONLY);
	  read(cf,buff1,100);
	  write(cfo,buff1,strlen(buff1));
	  close(wfo);
	  close(cfo);
	  close(cf);
	}
}
