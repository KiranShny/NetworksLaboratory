#include<stdio.h>
#include<stdlib.h>
int bkt;
void bktinput(int a,int b)
{
if(a>bkt)
printf("\nbucket overflow");
else
{
sleep(1);
while(a>b)
{
printf("\n %d bytes output",b);
a-=b;
sleep(1);
}
if(a>0)
printf("\nlast %d bytes sent ",a);
printf("\nbucket output successful\n");
}
}
int main()
{
int op,pktsize,i;
printf("\nEnter bucket size ");
scanf("%d",&bkt);
printf("\nEnter output rate:");
scanf("%d",&op);
for(i=1;i<=5;i++)
{
sleep(1);
pktsize=rand()%100;
printf("\nPacket no %d packet size %d ",i,pktsize);
bktinput(pktsize,op);
}
}
