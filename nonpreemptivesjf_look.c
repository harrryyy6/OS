//Non-preemptive SJF

#include <stdio.h>

struct Process
{
int pid;
int at;
int bt;
int ct;
int tat;
int wt;
int done;
};

int main()
{
struct Process p[20];
int n,i;
int time=0,completed=0;
int min,index;
float avgWT=0,avgTAT=0;

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
p[i].pid=i+1;

printf("Enter Arrival Time of P%d: ",i+1);
scanf("%d",&p[i].at);

printf("Enter CPU Burst of P%d: ",i+1);
scanf("%d",&p[i].bt);

p[i].done=0;
}

printf("\nGantt Chart:\n");

while(completed<n)
{
min=9999;
index=-1;

for(i=0;i<n;i++)
{
if(p[i].done==0&&p[i].at<=time)
{
if(p[i].bt<min)
{
min=p[i].bt;
index=i;
}
}
}

if(index==-1)
{
time++;
continue;
}

printf("| P%d ",p[index].pid);

time=time+p[index].bt;

p[index].ct=time;
p[index].tat=p[index].ct-p[index].at;
p[index].wt=p[index].tat-p[index].bt;

p[index].done=1;
completed++;

avgWT+=p[index].wt;
avgTAT+=p[index].tat;
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


//--------------------------------------------------------------------------------------------------------


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
