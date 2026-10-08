//SJF

#include <stdio.h>

int main()
{
int n,i,time=0,completed=0;
int at[20],bt[20],rt[20],ct[20];
int tat[20],wt[20];
int current,prev=-1;
int totalWT=0,totalTAT=0;

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter arrival time and burst time for P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);

rt[i]=bt[i];
}

printf("\nGantt Chart:\n");

while(completed<n)
{
current=-1;

for(i=0;i<n;i++)
{
if(at[i]<=time&&rt[i]>0)
{
if(current==-1||rt[i]<rt[current])
current=i;
}
}

if(current==-1)
{
if(prev!=-1)
printf("| ");

printf("Idle(%d-%d) ",time,time+1);
time++;
prev=-1;
continue;
}

if(current!=prev)
printf("| P%d ",current+1);

rt[current]--;
time++;

if(rt[current]==0)
{
ct[current]=time;
completed++;
}

prev=current;
}

printf("|\n");

for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];

totalWT+=wt[i];
totalTAT+=tat[i];
}

printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}

printf("\nAverage Waiting Time = %.2f",
(float)totalWT/n);

printf("\nAverage Turnaround Time = %.2f\n",
(float)totalTAT/n);

return 0;

}


//--------------------------------------------------------------------------------------------------------------

//Orphan process
 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;

pid=fork();

if(pid==0)
{
sleep(5);

printf("Child Process\n");
printf("Child PID: %d\n",getpid());
printf("Parent PID: %d\n",getppid());
printf("Child becomes orphan process\n");
}
else if(pid>0)
{
printf("Parent Process\n");
printf("Parent PID: %d\n",getpid());
printf("Parent is terminating...\n");
}
else
{
printf("Fork failed\n");
}

return 0;
}
