//linked 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct File
{
char name[20];
int blocks[MAX];
int count;
};

int main()
{
int n,i,choice;
int bit[MAX];
struct File files[20];
int fileCount=0;

srand(time(NULL));

printf("\nEnter number of blocks: ");
scanf("%d",&n);

for(i=0;i<n;i++)
bit[i]=rand()%2;

while(1)
{
printf("\n--- LINKED FILE ALLOCATION ---\n");
printf("1. Show Bit Vector\n");
printf("2. Create New File\n");
printf("3. Show Directory\n");
printf("4. Exit\n");
printf("\nEnter your choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("\nBit Vector:\n");
for(i=0;i<n;i++)
printf("%d ",bit[i]);
printf("\n");
break;

case 2:
{
int blocks,j,found,k;

if(fileCount>=20)
{
printf("\nDirectory is full!\n");
break;
}

printf("\nEnter file name: ");
scanf("%s",files[fileCount].name);

printf("Enter number of blocks required: ");
scanf("%d",&blocks);

files[fileCount].count=0;

for(j=0;j<blocks;j++)
{
found=-1;

for(k=0;k<n;k++)
{
if(bit[k]==0)
{
found=k;
break;
}
}

if(found==-1)
{
printf("\nNot enough free blocks!\n");
break;
}

files[fileCount].blocks[files[fileCount].count]=found;
files[fileCount].count++;
bit[found]=1;
}

if(files[fileCount].count==blocks)
{
printf("\nFile created successfully.\n");
printf("Linked blocks: ");

for(j=0;j<files[fileCount].count;j++)
{
printf("%d",files[fileCount].blocks[j]);

if(j!=files[fileCount].count-1)
printf(" -> ");
}

printf("\n");
fileCount++;
}
break;
}

case 3:
printf("\n--- DIRECTORY ---\n");

if(fileCount==0)
{
printf("\nNo files created.\n");
}
else
{
printf("File Name\tLinked Blocks\n");

for(i=0;i<fileCount;i++)
{
int j;

printf("%s\t\t",files[i].name);

for(j=0;j<files[i].count;j++)
{
printf("%d",files[i].blocks[j]);

if(j!=files[i].count-1)
printf(" -> ");
}

printf("\n");
}
}
break;

case 4:
printf("\nExiting...\n");
exit(0);

default:
printf("\nInvalid choice!\n");
}
}

return 0;
}


//--------------------------------------------------------------------------------------------------------

//FCFS Disk Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
int n,i,head,total=0;
int req[100];
printf("\nEnter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
scanf("%d",&n);

printf("Enter disk request string:\n");
for(i=0;i<n;i++)
  scanf("%d",&req[i]);

printf("\nEnter current head position: ");
scanf("%d",&head);

printf("\n\nFCFS Disk Scheduling\n");
printf("\nRequest order:\n");
printf("%d",head);
for(i=0;i<n;i++)
{
total=total+abs(head-req[i]);
head=req[i];
printf(" -> %d",req[i]);
}

printf("\n\nTotal head movements = %d\n",total);
return 0;
}
