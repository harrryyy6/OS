#include<stdio.h>

int allocation[10][10], maxm[10][10], available[10];
int n_process, n_resource;

void accept_available()
{
    int j;
    printf("Enter Available resources: ");
    for(j = 0; j < n_resource; j++)
        scanf("%d", &available[j]);
}

void display_alloc_max()
{
    int i, j;
    printf("\nProcess\tAllocation\t\tMax\n");
    printf("----------------------------------------------\n");
    for(i = 0; i < n_process; i++)
    {
        printf("P%d\t", i);
        for(j = 0; j < n_resource; j++)
            printf("%d ", allocation[i][j]);
        printf("\t\t");
        for(j = 0; j < n_resource; j++)
            printf("%d ", maxm[i][j]);
        printf("\n");
    }
}

void display_need()
{
    int i, j;
    printf("\nProcess\tNeed\n");
    printf("----------------------------\n");
    for(i = 0; i < n_process; i++)
    {
        printf("P%d\t", i);
        for(j = 0; j < n_resource; j++)
            printf("%d ", maxm[i][j] - allocation[i][j]);
        printf("\n");
    }
}

void display_available()
{
    int j;
    printf("\nAvailable: ");
    for(j = 0; j < n_resource; j++)
        printf("%d ", available[j]);
    printf("\n");
}

int main()
{
    int i, j, choice;

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

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation & Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: accept_available(); break;
            case 2: display_alloc_max(); break;
            case 3: display_need(); break;
            case 4: display_available(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}