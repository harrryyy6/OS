//Round Robin Scheduling Algorithm

#include <stdio.h>

struct Process
{
int pid;
int at;
int bt;
int rt;
int ct;
int tat;
int wt;
};

int main()
{
struct Process p[20];
int n,tq;
int i,time=0,completed=0;
int found;
float avgWT=0,avgTAT=0;

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
p[i].pid=i+1;

printf("\nEnter Arrival Time of P%d: ",i+1);
scanf("%d",&p[i].at);

printf("Enter CPU Burst of P%d: ",i+1);
scanf("%d",&p[i].bt);

p[i].rt=p[i].bt;
}

printf("\nEnter Time Quantum: ");
scanf("%d",&tq);

printf("\nGantt Chart:\n");

while(completed<n)
{
found=0;

for(i=0;i<n;i++)
{
if(p[i].rt>0&&p[i].at<=time)
{
found=1;

printf("| P%d ",p[i].pid);

if(p[i].rt>tq)
{
time=time+tq;
p[i].rt=p[i].rt-tq;
}
else
{
time=time+p[i].rt;
p[i].rt=0;

p[i].ct=time;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;

avgWT=avgWT+p[i].wt;
avgTAT=avgTAT+p[i].tat;

completed++;
}
}
}

if(found==0)
{
time++;
}
}

printf("|\n");

printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
p[i].pid,
p[i].at,
p[i].bt,
p[i].ct,
p[i].tat,
p[i].wt);
}

printf("\nAverage Waiting Time = %.2f",avgWT/n);
printf("\nAverage Turnaround Time = %.2f\n",avgTAT/n);

return 0;
}


//----------------------––--––----------------------------––--––----------------------------––--––------

//Look Disk Algorithm

#include <stdio.h>
#include <stdlib.h>

int main()
{
int request[20],n,head;
int i,j,temp;
int totalMovement=0;

printf("Enter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
int r;
scanf("%d",&r);

printf("Enter disk request string:\n");
for(i=0;i<r;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

for(i=0;i<r-1;i++)
{
for(j=i+1;j<r;j++)
{
if(request[i]>request[j])
{
temp=request[i];
request[i]=request[j];
request[j]=temp;
}
}
}

printf("\nOrder of requests served:\n");

for(i=r-1;i>=0;i--)
{
if(request[i]<head)
{
printf("%d ",request[i]);
totalMovement+=abs(head-request[i]);
head=request[i];
}
}

for(i=0;i<r;i++)
{
if(request[i]>head)
{
printf("%d ",request[i]);
totalMovement+=abs(head-request[i]);
head=request[i];
}
}

printf("\n\nTotal head movements = %d\n",totalMovement);

return 0;
}
