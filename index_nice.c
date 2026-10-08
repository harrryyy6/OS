//Index file allocation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct File
{
char name[20];
int indexBlock;
int blocks[MAX];
int count;
};

int main()
{
int n,i,choice;
int bit[MAX];
struct File file[20];
int fileCount=0;

printf("Enter number of disk blocks: ");
scanf("%d",&n);

srand(time(NULL));

for(i=0;i<n;i++)
bit[i]=rand()%2;

do
{
printf("\n--- INDEX FILE ALLOCATION ---\n");
printf("1. Show Bit Vector\n");
printf("2. Create New File\n");
printf("3. Show Directory\n");
printf("4. Exit\n");

printf("Enter your choice: ");
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
int index,blocks,count=0;

printf("\nEnter file name: ");
scanf("%s",file[fileCount].name);

index=-1;

for(i=0;i<n;i++)
{
if(bit[i]==0)
{
index=i;
break;
}
}

if(index==-1)
{
printf("No free block available for index block.\n");
break;
}

printf("Enter number of blocks required: ");
scanf("%d",&blocks);

for(i=0;i<n&&count<blocks;i++)
{
if(bit[i]==0&&i!=index)
{
file[fileCount].blocks[count]=i;
bit[i]=1;
count++;
}
}

if(count<blocks)
{
printf("Not enough free blocks available.\n");

for(i=0;i<count;i++)
bit[file[fileCount].blocks[i]]=0;

break;
}

bit[index]=1;

file[fileCount].indexBlock=index;
file[fileCount].count=count;

printf("\nFile created successfully.\n");
printf("Index Block: %d\n",index);
printf("Allocated Blocks: ");

for(i=0;i<count;i++)
printf("%d ",file[fileCount].blocks[i]);

printf("\n");

fileCount++;
break;
}

case 3:
printf("\nDirectory:\n");

if(fileCount==0)
{
printf("No files created.\n");
}
else
{
for(i=0;i<fileCount;i++)
{
int j;

printf("\nFile Name: %s",file[i].name);
printf("\nIndex Block: %d",file[i].indexBlock);
printf("\nBlocks: ");

for(j=0;j<file[i].count;j++)
printf("%d ",file[i].blocks[j]);

printf("\n");
}
}
break;

case 4:
printf("\nExiting...\n");
break;

default:
printf("\nInvalid choice!\n");
}

}while(choice!=4);

return 0;
}

//--------------------------------------------------------------------------------------------------

//Nice() Fork()

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;
int retnice;

retnice=nice(2);

pid=fork();

if(pid==0)
{
retnice=nice(-20);
printf("Child gets higher CPU priority: %d\n",retnice);
printf("Child Process ID: %d\n",getpid());
}
else if(pid>0)
{
retnice=nice(20);
printf("Parent gets lower CPU priority: %d\n",retnice);
printf("Parent Process ID: %d\n",getpid());
}
else
{
printf("Fork failed\n");
}
return 0;
}
