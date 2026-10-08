//Banker Algorithm simple accept,diaplay and need matrix

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int alloc[5][3], max[5][3], need[5][3];
int avail[3];

void accept()
{
int i,j;
printf("\nEnter Allocation Matrix:\n");
for(i=0;i<5;i++)
{
printf("P%d: ",i);
    for(j=0;j<3;j++)
        scanf("%d",&alloc[i][j]);
}

printf("\nEnter Max Matrix:\n");
for(i=0;i<5;i++)
{
printf("P%d: ",i);
    for(j=0;j<3;j++)
        scanf("%d",&max[i][j]);
}

printf("\nEnter Available (A B C): ");
scanf("%d%d%d",&avail[0],&avail[1],&avail[2]);
    for(i=0;i<5;i++)
        for(j=0;j<3;j++)
            need[i][j]=max[i][j]-alloc[i][j];
printf("\nData accepted successfully.");
}

void displayAllocMax()
{
int i;
printf("\nProcess\tAllocation\tMax\n");
printf("\tA B C\t\tA B C\n");
for(i=0;i<5;i++)
    printf("P%d\t%d %d %d\t\t%d %d %d\n",i,alloc[i][0],alloc[i][1],alloc[i][2],max[i][0],max[i][1],max[i][2]);
}

void displayNeed()
{
int i;
printf("\nNeed Matrix\n");
printf("Process\tA\tB\tC\n");
    for(i=0;i<5;i++)
printf("P%d\t%d\t%d\t%d\n",
i,need[i][0],need[i][1],need[i][2]);
}

void displayAvailable()
{
printf("\nAvailable Resources\n");
printf("A\tB\tC\n");
printf("%d\t%d\t%d\n",
avail[0],avail[1],avail[2]);
}

int main()
{
int ch;
do
{
printf("\n\n--- BANKER'S ALGORITHM ---");
printf("\n1. Accept Allocation, Max and Available");
printf("\n2. Display Allocation, Max");
printf("\n3. Find and Display Need");
printf("\n4. Display Available");
printf("\n5. Exit");
printf("\n\nEnter choice: ");
scanf("%d",&ch);

switch(ch)
{
case 1:
    accept();
break;
case 2:
    displayAllocMax();
break;
case 3:
    displayNeed();
break;
case 4:
    displayAvailable();
break;
case 5:
    exit(0);
default:
    printf("\nInvalid choice!");
}
}while(1);
return 0;
}


//--------------------------------------------------------------------------------------------------------


//SCAN Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,m,i,j;
int request[100];
int head;
int totalMovement=0;
int temp;

printf("Enter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
scanf("%d",&m);

printf("Enter disk request string:\n");
for(i=0;i<m;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

for(i=0;i<m-1;i++)
{
for(j=i+1;j<m;j++)
{
if(request[i]>request[j])
{
temp=request[i];
request[i]=request[j];
request[j]=temp;
}
}
}

printf("\nOrder of service:\n");

for(i=m-1;i>=0;i--)
{
if(request[i]<=head)
{
printf("%d -> ",request[i]);
totalMovement+=abs(head-request[i]);
head=request[i];
}
}

totalMovement+=head;
head=0;

printf("0 -> ");

for(i=0;i<m;i++)
{
if(request[i]>head)
{
printf("%d",request[i]);
totalMovement+=abs(head-request[i]);
head=request[i];

if(i!=m-1)
printf(" -> ");
}
}

printf("\n\nTotal head movements = %d\n",totalMovement);

return 0;
}