//Premptive priority

#include <stdio.h>

int main()
{
int n,i,time=0,completed=0;
int at[20],bt[20],rt[20],pr[20];
int ct[20],tat[20],wt[20];
int current,prev=-1;
int totalWT=0,totalTAT=0;

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter AT, BT and Priority for P%d: ",i+1);
scanf("%d %d %d",&at[i],&bt[i],&pr[i]);

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
if(current==-1||pr[i]<pr[current])
current=i;
}
}

if(current==-1)
{
if(prev!=-1)
printf("| ");

printf("Idle ");
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

totalTAT+=tat[i];
totalWT+=wt[i];
}

printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
i+1,at[i],bt[i],pr[i],
ct[i],tat[i],wt[i]);
}

printf("\nAverage Waiting Time = %.2f",(float)totalWT/n);

printf("\nAverage Turnaround Time = %.2f\n",(float)totalTAT/n);

return 0;
}
//--------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------


#include <stdio.h>

int main()
{
int pages[20]={3,4,5,6,3,4,7,3,4,5,6,7,2,4,6};
int frames[10];
int n=15,f,i,j;
int pageFaults=0,pointer=0,found;

printf("Enter number of frames: ");
scanf("%d",&f);

for(i=0;i<f;i++)
frames[i]=-1;

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<n;i++)
{
found=0;

for(j=0;j<f;j++)
{
if(frames[j]==pages[i])
{
found=1;
break;
}
}

if(found==0)
{
frames[pointer]=pages[i];
pointer=(pointer+1)%f;
pageFaults++;
}

printf("%d\t",pages[i]);

for(j=0;j<f;j++)
{
if(frames[j]==-1)
printf("- ");
else
printf("%d ",frames[j]);
}

if(found==0)
printf("\tYES");
else
printf("\tNO");

printf("\n");
}

printf("\nTotal Page Faults = %d\n",pageFaults);

return 0;
}
