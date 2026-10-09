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
    int i, head, direction;
    int lo, hi, current, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    if(n < 1 || n > 50)
    {
        printf("Number of requests must be 1 to 50\n");
        return 1;
    }

    printf("Enter disk requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0=Left, 1=Right): ");
    scanf("%d", &direction);

    sort_requests();

    lo = 0;                                  /* first index with req >= head */
    while(lo < n && req[lo] < head) lo++;
    hi = lo;                                 /* first index with req > head */
    while(hi < n && req[hi] == head) hi++;

    current = head;
    printf("\nOrder of servicing: %d", head);

    for(i = lo; i < hi; i++)                 /* requests at head position */
        printf(" -> %d", req[i]);

    if(direction == 1)
    {
        for(i = hi; i < n; i++)
        {
            printf(" -> %d", req[i]);
            total += abs(current - req[i]);
            current = req[i];
        }
        for(i = lo - 1; i >= 0; i--)
        {
            printf(" -> %d", req[i]);
            total += abs(current - req[i]);
            current = req[i];
        }
    }
    else
    {
        for(i = lo - 1; i >= 0; i--)
        {
            printf(" -> %d", req[i]);
            total += abs(current - req[i]);
            current = req[i];
        }
        for(i = hi; i < n; i++)
        {
            printf(" -> %d", req[i]);
            total += abs(current - req[i]);
            current = req[i];
        }
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}

