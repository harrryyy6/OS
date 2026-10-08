//Optimal Page Replacement

#include <stdio.h>

int main()
{
int n,m;
int page[100],frame[20];
int i,j,k;
int pageFaults=0;
int found,pos,farthest,future;

printf("Enter number of frames: ");
scanf("%d",&n);

printf("Enter number of pages in reference string: ");
scanf("%d",&m);

printf("Enter reference string:\n");

for(i=0;i<m;i++)
scanf("%d",&page[i]);

for(i=0;i<n;i++)
frame[i]=-1;

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<m;i++)
{
found=0;

for(j=0;j<n;j++)
{
if(frame[j]==page[i])
{
found=1;
break;
}
}

if(found==0)
{
pageFaults++;
pos=-1;

for(j=0;j<n;j++)
{
if(frame[j]==-1)
{
pos=j;
break;
}
}

if(pos==-1)
{
farthest=-1;
pos=0;

for(j=0;j<n;j++)
{
future=0;

for(k=i+1;k<m;k++)
{
if(frame[j]==page[k])
{
future=k;
break;
}
}

if(future==0)
{
pos=j;
break;
}

if(future>farthest)
{
farthest=future;
pos=j;
}
}
}

frame[pos]=page[i];
}

printf("%d\t",page[i]);

for(j=0;j<n;j++)
{
if(frame[j]==-1)
printf("- ");
else
printf("%d ",frame[j]);
}

if(found==0)
printf("\tYes");
else
printf("\tNO");

printf("\n");
}

printf("\nTotal pages = %d",m);
printf("\nTotal page faults = %d\n",pageFaults);

return 0;
}

//--------------------------------------------------------------------------------------------------------


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
