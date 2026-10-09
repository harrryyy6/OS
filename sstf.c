#include<stdio.h>
#include<stdlib.h>

struct diskreq
{
    int block;
}req[50];

int n;

void display_order(int head)
{
    int i, j, min, index, distance;
    int visited[50] = {0};

    printf("Order of servicing: %d", head);

    for(i = 0; i < n; i++)
    {
        min = 9999;
        index = -1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                distance = abs(head - req[j].block);

                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        head = req[index].block;

        printf(" -> %d", head);
    }

    printf("\n");
}

int total_head_movement(int head)
{
    int i, j, min, index, distance;
    int total = 0;
    int visited[50] = {0};

    for(i = 0; i < n; i++)
    {
        min = 9999;
        index = -1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                distance = abs(head - req[j].block);

                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total = total + min;
        head = req[index].block;
    }

    return total;
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


/*  98, 183, 37, 122, 14, 124, 65 
   Start Head Position: 53 */