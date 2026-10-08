//random preemptive sjf

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], ct[20];
    int tat[20], wt[20];
    int current, prev = -1;
    int totalWT = 0, totalTAT = 0;

    srand(time(NULL));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and first CPU burst for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (completed < n)
    {
        current = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (current == -1 || rt[i] < rt[current])
                    current = i;
            }
        }

        if (current == -1)
        {
            if (prev != -1)
                printf("| ");

            printf("Idle(%d-%d) ", time, time + 1);
            time++;
            prev = -1;
            continue;
        }

        if (current != prev)
            printf("| P%d ", current + 1);

        rt[current]--;
        time++;

        if (rt[current] == 0)
        {
            ct[current] = time;
            completed++;

            /*
             * Generate the next CPU burst randomly.
             * This value is displayed but is not used
             * for scheduling because no I/O burst or
             * further process activity is specified.
             */
        }

        prev = current;
    }

    printf("|\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nProcess\tAT\tFirst BT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)totalWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)totalTAT / n);

    return 0;
}


//----------------------------------------------------------------------

//preemptive priority

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n,i,time=0,completed=0;
int at[20],bt[20],rt[20],pr[20],ct[20],tat[20],wt[20];
int current,prev=-1;
int totalWT=0,totalTAT=0;

srand(time(NULL));

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter Arrival Time, First CPU Burst and Priority for P%d: ",i+1);
scanf("%d %d %d",&at[i],&bt[i],&pr[i]);

rt[i]=bt[i];
}

printf("\nNext CPU Bursts generated randomly:\n");

for(i=0;i<n;i++)
printf("P%d: %d\n",i+1,rand()%10+1);

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
printf("| Idle ");
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
i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
}

printf("\nAverage Waiting Time = %.2f",
(float)totalWT/n);

printf("\nAverage Turnaround Time = %.2f\n",
(float)totalTAT/n);

return 0;
}



//----------------------------------------------------------------------

//fcfs

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n,i,time=0;
int at[20],bt[20],ct[20],tat[20],wt[20];
int totalWT=0,totalTAT=0;

srand(time(NULL));

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter Arrival Time and First CPU Burst for P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);
}

printf("\nNext CPU Bursts generated randomly:\n");

for(i=0;i<n;i++)
printf("P%d: %d\n",i+1,rand()%10+1);

printf("\nGantt Chart:\n");

for(i=0;i<n;i++)
{
if(time<at[i])
{
printf("| Idle ");
time=at[i];
}

printf("| P%d ",i+1);

time=time+bt[i];
ct[i]=time;

tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];

totalTAT=totalTAT+tat[i];
totalWT=totalWT+wt[i];
}

printf("|\n");

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



//----------------------------------------------------------------------

//round robin scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n,tq;
int at[20],bt[20],rem[20];
int ct[20],tat[20],wt[20];
int io[20]={0};
int completed=0;
int time=0;
int i;
int totalWT=0,totalTAT=0;

srand(time(NULL));

printf("Enter number of processes: ");
scanf("%d",&n);

printf("Enter Arrival Time and First CPU Burst:\n");

for(i=0;i<n;i++)
{
printf("P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);

rem[i]=bt[i];
ct[i]=0;
}

printf("Enter Time Quantum: ");
scanf("%d",&tq);

printf("\nNext CPU Bursts generated randomly:\n");

for(i=0;i<n;i++)
printf("P%d: %d\n",i+1,rand()%10+1);

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

totalTAT=totalTAT+tat[i];
totalWT=totalWT+wt[i];
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


//----------------------------------------------------------------------

//non-preemptive sjf scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int n,i,time=0,completed=0;
int at[20],bt[20],ct[20],tat[20],wt[20],done[20];
int min,index;
int totalWT=0,totalTAT=0;

srand(time(NULL));

printf("Enter number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("Enter Arrival Time and First CPU Burst for P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);
done[i]=0;
}

printf("\nNext CPU Bursts generated randomly:\n");

for(i=0;i<n;i++)
printf("P%d: %d\n",i+1,rand()%10+1);

printf("\nGantt Chart:\n");

while(completed<n)
{
min=9999;
index=-1;

for(i=0;i<n;i++)
{
if(at[i]<=time&&done[i]==0)
{
if(bt[i]<min)
{
min=bt[i];
index=i;
}
}
}

if(index==-1)
{
printf("| Idle ");
time++;
continue;
}

printf("| P%d ",index+1);

time=time+bt[index];

ct[index]=time;
tat[index]=ct[index]-at[index];
wt[index]=tat[index]-bt[index];

done[index]=1;
completed++;

totalTAT=totalTAT+tat[index];
totalWT=totalWT+wt[index];
}

printf("|\n");

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

