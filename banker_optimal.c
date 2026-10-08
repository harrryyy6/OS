//Bankers Algorithm simple accept,diaplay and need matrix

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

//------------------------------------------------------------------------------------------------------------

//Optimal Page Replacement

#include <stdio.h>

int main()
{
int n,m;
int page[100],frame[20];
int i,j,k;
int pageFaults=0;
int found,pos,farthest,future;

printf("Enter number of frames: ");
scanf("%d",&n);

printf("Enter number of pages in reference string: ");
scanf("%d",&m);

printf("Enter reference string:\n");

for(i=0;i<m;i++)
scanf("%d",&page[i]);

for(i=0;i<n;i++)
frame[i]=-1;

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<m;i++)
{
found=0;

for(j=0;j<n;j++)
{
if(frame[j]==page[i])
{
found=1;
break;
}
}

if(found==0)
{
pageFaults++;
pos=-1;

for(j=0;j<n;j++)
{
if(frame[j]==-1)
{
pos=j;
break;
}
}

if(pos==-1)
{
farthest=-1;
pos=0;

for(j=0;j<n;j++)
{
future=0;

for(k=i+1;k<m;k++)
{
if(frame[j]==page[k])
{
future=k;
break;
}
}

if(future==0)
{
pos=j;
break;
}

if(future>farthest)
{
farthest=future;
pos=j;
}
}
}

frame[pos]=page[i];
}

printf("%d\t",page[i]);

for(j=0;j<n;j++)
{
if(frame[j]==-1)
printf("- ");
else
printf("%d ",frame[j]);
}

if(found==0)
printf("\tYes");
else
printf("\tNO");

printf("\n");
}

printf("\nTotal pages = %d",m);
printf("\nTotal page faults = %d\n",pageFaults);

return 0;
}
