#include<stdio.h>

int allocation[10][10], maxm[10][10], need[10][10], available[10];
int n_process, n_resource;

void calculate_need()
{
    int i, j;
    for(i = 0; i < n_process; i++)
        for(j = 0; j < n_resource; j++)
            need[i][j] = maxm[i][j] - allocation[i][j];
}

int check_safe_state(int safe_seq[])
{
    int work[10], finish[10] = {0};
    int i, j, count = 0, found;

    for(j = 0; j < n_resource; j++)
        work[j] = available[j];

    while(count < n_process)
    {
        found = 0;
        for(i = 0; i < n_process; i++)
        {
            if(!finish[i])
            {
                int can_allocate = 1;
                for(j = 0; j < n_resource; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        can_allocate = 0;
                        break;
                    }
                }
                if(can_allocate)
                {
                    for(j = 0; j < n_resource; j++)
                        work[j] += allocation[i][j];
                    finish[i] = 1;
                    safe_seq[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if(!found)
            break;
    }

    return (count == n_process);
}

int request_resources(int process_id, int request[])
{
    int j;

    // Step 1: request must not exceed need
    for(j = 0; j < n_resource; j++)
    {
        if(request[j] > need[process_id][j])
        {
            printf("Error: Request exceeds process's stated Need.\n");
            return 0;
        }
    }

    // Step 2: request must not exceed available
    for(j = 0; j < n_resource; j++)
    {
        if(request[j] > available[j])
        {
            printf("Process must wait, resources not available.\n");
            return 0;
        }
    }

    // Step 3: pretend to allocate
    for(j = 0; j < n_resource; j++)
    {
        available[j] -= request[j];
        allocation[process_id][j] += request[j];
        need[process_id][j] -= request[j];
    }

    return 1;
}

int main()
{
    int i, j, process_id, request[10], safe_seq[10];

    printf("Enter number of processes: ");
    scanf("%d", &n_process);
    printf("Enter number of resource types: ");
    scanf("%d", &n_resource);

    printf("Enter Allocation matrix:\n");
    for(i = 0; i < n_process; i++)
        for(j = 0; j < n_resource; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max matrix:\n");
    for(i = 0; i < n_process; i++)
        for(j = 0; j < n_resource; j++)
            scanf("%d", &maxm[i][j]);

    printf("Enter Available resources: ");
    for(j = 0; j < n_resource; j++)
        scanf("%d", &available[j]);

    calculate_need();

    printf("Enter process number requesting resources: ");
    scanf("%d", &process_id);

    printf("Enter request vector: ");
    for(j = 0; j < n_resource; j++)
        scanf("%d", &request[j]);

    if(request_resources(process_id, request))
    {
        if(check_safe_state(safe_seq))
        {
            printf("Request can be granted immediately.\n");
            printf("Safe Sequence: ");
            for(i = 0; i < n_process; i++)
                printf("P%d ", safe_seq[i]);
            printf("\n");
        }
        else
        {
            printf("Request cannot be granted (leads to unsafe state).\n");
        }
    }

    return 0;
}