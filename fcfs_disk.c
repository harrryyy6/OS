#include<stdio.h>
#include<stdlib.h>

struct diskreq
{
    int block;
}req[50];

int n;

int total_head_movement(int head)
{
    int i, total = 0, current = head;
    for(i = 0; i < n; i++)
    {
        total += abs(req[i].block - current);
        current = req[i].block;
    }
    return total;
}

void display_order(int head)
{
    int i;
    printf("Order of servicing: %d", head);
    for(i = 0; i < n; i++)
        printf(" -> %d", req[i].block);
    printf("\n");
}

int main()
{
    int i, head, movement;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i].block);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    display_order(head);
    movement = total_head_movement(head);

    printf("Total Head Movements = %d\n", movement);

    return 0;
}
