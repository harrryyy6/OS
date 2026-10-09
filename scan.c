#include<stdio.h>
#include<stdlib.h>

int req[50], n;

void sort_requests()
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-1-i; j++)
            if(req[j] > req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
}

int main()
{
    int i, head, disk_size, direction, split, total = 0, current;

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0=Left, 1=Right): ");
    scanf("%d", &direction);

    sort_requests();

    split = 0;
    while(split < n && req[split] < head)
        split++;
    current = head;
    printf("Order of servicing: %d", head);

    
    if(direction == 0)   // moving left first
    {
        for(i = split-1; i >= 0; i--)
        {
            printf(" -> %d", req[i]);
            total += abs(req[i] - current);
            current = req[i];
        }
        printf(" -> 0");
        total += abs(0 - current);
        current = 0;
        for(i = split; i < n; i++)
        {
            printf(" -> %d", req[i]);
            total += abs(req[i] - current);
            current = req[i];
        }
    }
    else   // moving right first
    {
        for(i = split; i < n; i++)
        {
            printf(" -> %d", req[i]);
            total += abs(req[i] - current);
            current = req[i];
        }
        printf(" -> %d", disk_size - 1);
        total += abs((disk_size - 1) - current);
        current = disk_size - 1;
        for(i = split-1; i >= 0; i--)
        {
            printf(" -> %d", req[i]);
            total += abs(req[i] - current);
            current = req[i];
        }
    }

    printf("\nTotal Head Movements = %d\n", total);

    return 0;
}


