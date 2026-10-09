#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct process
{
    int pid;
    int at;
    int bt1;
    int bt2;
    int bt;
    int ct;
    int wt;
    int tat;
} p[50];

int main()
{
    int n, i, j;
    int current = 0;
    float avg_wt = 0, avg_tat = 0;

    srand(time(0));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and First CPU Burst:\n");

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt1);

        /* Generate next CPU burst randomly */
        p[i].bt2 = (rand() % 10) + 1;

        p[i].bt = p[i].bt1 + p[i].bt2;
    }

    /* Sort according to Arrival Time */
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    /* FCFS Scheduling */
    printf("\nGantt Chart:\n");

    for(i = 0; i < n; i++)
    {
        if(current < p[i].at)
            current = p[i].at;

        printf("| P%d ", p[i].pid);

        current = current + p[i].bt;

        p[i].ct = current;

        p[i].tat = p[i].ct - p[i].at;

        p[i].wt = p[i].tat - p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("|\n");

    current = 0;

    printf("0");

    for(i = 0; i < n; i++)
    {
        if(current < p[i].at)
            current = p[i].at;

        current = current + p[i].bt;

        printf("    %d", current);
    }

    printf("\n");

    /* Display table */
    printf("\nProcess\tAT\tBT1\tBT2\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt1,
               p[i].bt2,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
