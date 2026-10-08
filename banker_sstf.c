//bankers Algorithm with safe sequence

#include <stdio.h>
int main()
{
int n,m;
int allocation[20][20],max[20][20],need[20][20];
int available[20];
int finish[20]={0};
int safe[20];
int i,j,k;
int count=0,canRun;

printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter number of resources: ");
scanf("%d",&m);

printf("\nEnter Allocation Matrix:\n");
for(i=0;i<n;i++)
{
printf("P%d: ",i);
for(j=0;j<m;j++)
scanf("%d",&allocation[i][j]);
}

printf("\nEnter Max Matrix:\n");
for(i=0;i<n;i++)
{
printf("P%d: ",i);
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
}

printf("\nEnter Available Resources:\n");
for(j=0;j<m;j++)
scanf("%d",&available[j]);

for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j]=max[i][j]-allocation[i][j];

printf("\nNeed Matrix:\n");
for(i=0;i<n;i++)
{
printf("P%d: ",i);
for(j=0;j<m;j++)
printf("%d ",need[i][j]);
printf("\n");
}

while(count<n)
{
int found=0;
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
canRun=1;
for(j=0;j<m;j++)
{
if(need[i][j]>available[j])
{
canRun=0;
break;
}
}
if(canRun)
{
for(k=0;k<m;k++)
available[k]+=allocation[i][k];
safe[count]=i;
count++;
finish[i]=1;
found=1;
}
}
}
if(found==0)
break;
}

if(count==n)
{
printf("\nSystem is in SAFE state.\n");
printf("Safe Sequence: ");
for(i=0;i<n;i++)
{
printf("P%d",safe[i]);
if(i!=n-1)
printf(" -> ");
}
printf("\n");
}
else
printf("\nSystem is NOT in a safe state.\n");

return 0;
}


//--------------------------------------------------------------------------------------------------------

//SSTF Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,j;
int request[100],visited[100]={0};
int head;
int totalMovement=0;
int min,index;

printf("Enter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
int m;
scanf("%d",&m);

printf("Enter disk request string:\n");
for(i=0;i<m;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

printf("\n\nOrder of service:\n");

for(i=0;i<m;i++)
{
min=9999;
index=-1;

for(j=0;j<m;j++)
{
if(visited[j]==0)
{
if(abs(request[j]-head)<min)
{
min=abs(request[j]-head);
index=j;
}
}
}

visited[index]=1;
totalMovement+=min;
head=request[index];

printf("%d",head);

if(i!=m-1)
printf(" -> ");
}

printf("\n\nTotal head movements = %d\n",totalMovement);

return 0;
}