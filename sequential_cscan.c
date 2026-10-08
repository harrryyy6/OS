// Sequential File Allocation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct File
{
char name[20];
int start;
int length;
};

int main()
{
int n,i,choice;
int bit[MAX];
struct File files[20];
int fileCount=0;

srand(time(NULL));

printf("Enter number of blocks: ");
scanf("%d",&n);

for(i=0;i<n;i++)
bit[i]=rand()%2;

while(1)
{
printf("\n--- SEQUENTIAL FILE ALLOCATION ---\n");
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
int blocks,j,k,found;

if(fileCount>=20)
{
printf("\nDirectory is full!\n");
break;
}

printf("\nEnter file name: ");
scanf("%s",files[fileCount].name);

printf("Enter number of blocks required: ");
scanf("%d",&blocks);

found=-1;

for(i=0;i<=n-blocks;i++)
{
int free=1;

for(j=i;j<i+blocks;j++)
{
if(bit[j]==1)
{
free=0;
break;
}
}

if(free)
{
found=i;
break;
}
}

if(found==-1)
{
printf("\nContiguous free blocks not available!\n");
break;
}

files[fileCount].start=found;
files[fileCount].length=blocks;

for(k=found;k<found+blocks;k++)
bit[k]=1;

printf("\nFile created successfully.\n");
printf("Allocated blocks: ");

for(k=found;k<found+blocks;k++)
{
printf("%d",k);

if(k<found+blocks-1)
printf(" -> ");
}

printf("\n");

fileCount++;
break;
}

case 3:
printf("\n--- DIRECTORY ---\n");

if(fileCount==0)
{
printf("No files created.\n");
}
else
{
printf("File Name\tStart Block\tLength\n");

for(i=0;i<fileCount;i++)
{
printf("%s\t\t%d\t\t%d\n",
files[i].name,
files[i].start,
files[i].length);
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


//---------------------------------------------------------------------------


//C-Scan Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int main()
{
int request[100];
int n,i,j,temp;
int head,totalMovement=0;

printf("Enter number of disk requests: ");
scanf("%d",&n);

printf("Enter disk request string:\n");
for(i=0;i<n;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
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

for(i=0;i<n;i++)
{
if(request[i]>=head)
{
printf("%d",request[i]);
totalMovement+=abs(head-request[i]);
head=request[i];
printf(" -> ");
}
}

totalMovement+=199-head;
head=199;

totalMovement+=199;
head=0;

printf("0 -> ");

for(i=0;i<n;i++)
{
if(request[i]<100)
{
printf("%d",request[i]);

totalMovement+=abs(head-request[i]);
head=request[i];

if(i!=n-1)
printf(" -> ");
}
}

printf("\n\nTotal head movements = %d\n",totalMovement);

return 0;
}

