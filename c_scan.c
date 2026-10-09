#include <stdio.h>
#include <stdlib.h>

int main()
{
    int blocks, n, head;
    int request[100];
    int i, j, temp;
    int total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &blocks);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nOrder of requests served:\n");

    /* Move Right */
    for(i = 0; i < n; i++)
    {
        if(request[i] >= head)
        {
            printf("%d ", request[i]);
            total += abs(head - request[i]);
            head = request[i];
        }
    }

    /* Go to end of disk */
    total += (blocks - 1) - head;
    head = blocks - 1;

    /* Jump to beginning */
    total += blocks - 1;
    head = 0;

    /* Continue Right */
    for(i = 0; i < n; i++)
    {
        if(request[i] < 100)
        {
            printf("%d ", request[i]);
            total += abs(head - request[i]);
            head = request[i];
        }
    }

    printf("\nTotal head movement = %d\n", total);

    return 0;
}

