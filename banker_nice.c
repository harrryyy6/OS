// Banker's Algorithm

#include <stdio.h>

int main()
{
int n,m;
int allocation[20][20],max[20][20],need[20][20];
int available[20],work[20];
int finish[20]={0};
int safe[20];
int i,j,k;
int count=0;
int canRun;

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
{
for(j=0;j<m;j++)
need[i][j]=max[i][j]-allocation[i][j];
}

printf("\nNeed Matrix:\n");
for(i=0;i<n;i++)
{
printf("P%d: ",i);
for(j=0;j<m;j++)
printf("%d ",need[i][j]);
printf("\n");
}

for(j=0;j<m;j++)
work[j]=available[j];

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
if(need[i][j]>work[j])
{
canRun=0;
break;
}
}

if(canRun)
{
for(k=0;k<m;k++)
work[k]+=allocation[i][k];

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
{
printf("\nSystem is NOT in SAFE state.\n");
}

return 0;
}


//------------------------------------------------------------------------------------------------

//Nice() Fork()

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;
int retnice;

retnice=nice(2);

pid=fork();

if(pid==0)
{
retnice=nice(-20);
printf("Child gets higher CPU priority: %d\n",retnice);
printf("Child Process ID: %d\n",getpid());
}
else if(pid>0)
{
retnice=nice(20);
printf("Parent gets lower CPU priority: %d\n",retnice);
printf("Parent Process ID: %d\n",getpid());
}
else
{
printf("Fork failed\n");
}
return 0;
}
