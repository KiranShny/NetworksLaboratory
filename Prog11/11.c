#include<stdio.h>
#include<math.h>
#include<string.h>

int mult(unsigned int x,unsigned int y,unsigned int n)
{
	unsigned long int k=1;
	int j;
	for(j=1;j<=y;j++)
	k=(k*x)%n;
	return(unsigned int)k;
}
int main()
{
char msg[100];
unsigned int pt[100],ct[100],d,e,p,q,n,z,temp,et,i;
printf("Enter prime numbers p,q\n");
scanf("%d %d",&p,&q);
n=p*q;
z=(p-1)*(q-1);
printf("Select e value:");
scanf("%d",&e);
printf("\nEnter message:");
scanf("%s",msg);
for(i=0;i<strlen(msg);i++)
	pt[i]=msg[i];
for(d=1;d<z;++d)
	if(((e*d)%z)==1)
	break;
printf("\np=%d,q=%d,n=%d,z=%d,e=%d,d=%d",p,q,n,z,e,d);
printf("\nCT=");
for(i=0;i<strlen(msg);i++)
ct[i]=mult(pt[i],e,n);
for(i=0;i<strlen(msg);i++)
printf("%d",ct[i]);
printf("\nPT=");
for(i=0;i<strlen(msg);i++)
pt[i]=mult(ct[i],d,n);
for(i=0;i<strlen(msg);i++)
printf("%c",pt[i]);

}
