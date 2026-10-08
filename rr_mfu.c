//Round Robin Scheduling Algorithm

#include <stdio.h>

int main()
{
int n,tq;
int at[20],bt[20],rem[20];
int ct[20],tat[20],wt[20];
int io[20]={0};
int completed=0;
int time=0;
int i,j;
float avgwt=0,avgtat=0;

printf("Enter number of processes: ");
scanf("%d",&n);

printf("Enter Arrival Time and CPU Burst Time:\n");

for(i=0;i<n;i++)
{
printf("P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);

rem[i]=bt[i];
ct[i]=0;
tat[i]=0;
wt[i]=0;
}

printf("Enter Time Quantum: ");
scanf("%d",&tq);

printf("\nGantt Chart:\n");

while(completed<n)
{
int found=0;

for(i=0;i<n;i++)
{
if(at[i]<=time&&rem[i]>0&&io[i]<=time)
{
found=1;

printf("| P%d ",i+1);

if(rem[i]<=tq)
{
time=time+rem[i];
rem[i]=0;

ct[i]=time;
completed++;
}
else
{
time=time+tq;
rem[i]=rem[i]-tq;
io[i]=time+2;
}

break;
}
}

if(found==0)
{
printf("| Idle ");
time++;
}
}

printf("|\n");

for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];

avgwt=avgwt+wt[i];
avgtat=avgtat+tat[i];
}

printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}

printf("\nAverage Waiting Time = %.2f",avgwt/n);
printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);

return 0;
}


//--------------------------------------------------------------------------------------------------------------


//MFU

#include <stdio.h>

int main()
{
int pages[]={2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8};
int frames[20],freq[20];
int n=16,f,i,j;
int faults=0,hits=0;
int found,pos,max;

printf("Enter number of frames: ");
scanf("%d",&f);

if(f<1||f>20)
{
printf("Invalid number of frames.\n");
return 1;
}

for(i=0;i<f;i++)
{
frames[i]=-1;
freq[i]=0;
}

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<n;i++)
{
found=0;

for(j=0;j<f;j++)
{
if(frames[j]==pages[i])
{
freq[j]++;
found=1;
hits++;
break;
}
}

if(found==0)
{
pos=-1;

for(j=0;j<f;j++)
{
if(frames[j]==-1)
{
pos=j;
break;
}
}

if(pos==-1)
{
max=freq[0];
pos=0;

for(j=1;j<f;j++)
{
if(freq[j]>max)
{
max=freq[j];
pos=j;
}
}
}

frames[pos]=pages[i];
freq[pos]=1;
faults++;
}

printf("%d\t",pages[i]);

for(j=0;j<f;j++)
{
if(frames[j]==-1)
printf("- ");
else
printf("%d ",frames[j]);
}

if(found)
printf("\tNO\n");
else
printf("\tYES\n");
}

printf("\nTotal Page Faults = %d\n",faults);

return 0;
}
