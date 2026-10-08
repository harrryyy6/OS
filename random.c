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


//
