#include<stdio.h>
struct nodes
{
unsigned dist[20];
unsigned from[20];
}rt[10];
int main()
{
int costmat[20][20];
int nodes,i,j,k,count=0;
printf("\n Enter the number of nodes");
scanf("%d",&nodes);
printf("\n Enter the cost matrix");
for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
scanf("%d",&costmat[i][j]);
costmat[i][i]=0;
rt[i].dist[j]=costmat[i][j];
rt[i].from[j]=j;
}
}
for(i=0;i<nodes;i++)
for(j=0;j<nodes;j++)
for(k=0;k<nodes;k++)
if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
rt[i].from[j]=k;
}

for(i=0;i<nodes;i++)
{
printf("\nFor router %d\n",i+1);
for(j=0;j<nodes;j++)
{
printf("\n\t Node %d via %d distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
}
}
printf("\n\n");
}
