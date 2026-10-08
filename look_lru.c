#include <stdio.h>
#include <stdlib.h>

int main()
{
int request[20],n,r,head;
int i,j,temp;
int totalMovement=0;

printf("Enter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
scanf("%d",&r);

printf("Enter disk request string:\n");
for(i=0;i<r;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

for(i=0;i<r-1;i++)
{
for(j=0;j<r-i-1;j++)
{
if(request[j]>request[j+1])
{
temp=request[j];
request[j]=request[j+1];
request[j+1]=temp;
}
}
}

printf("\nDirection: Right");
printf("\nRequest servicing order:\n");

for(i=0;i<r;i++)
{
if(request[i]>=head)
{
printf("%d ",request[i]);
totalMovement+=abs(request[i]-head);
head=request[i];
}
}

for(i=r-1;i>=0;i--)
{
if(request[i]<head)
{
printf("%d ",request[i]);
totalMovement+=abs(request[i]-head);
head=request[i];
}
}

printf("\nTotal head movement = %d\n",totalMovement);

return 0;
}


//---------------------------------------------------------------------------------------------


//LRU Page Replacement 

#include <stdio.h>

int main()
{
int pages[]={3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};
int n=15,frames[20],counter[20];
int f,i,j,faults=0,hits=0;
int time=0,found,min,pos;

printf("Enter number of frames: ");
scanf("%d",&f);

for(i=0;i<f;i++)
{
frames[i]=-1;
counter[i]=0;
}

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<n;i++)
{
found=0;
time++;

for(j=0;j<f;j++)
{
if(frames[j]==pages[i])
{
found=1;
counter[j]=time;
hits++;
break;
}
}

if(found==0)
{
pos=-1;

for(j=0;j<f;j++)
{
if(frames[j]==-1)
{
pos=j;
break;
}
}

if(pos==-1)
{
min=counter[0];
pos=0;

for(j=1;j<f;j++)
{
if(counter[j]<min)
{
min=counter[j];
pos=j;
}
}
}

frames[pos]=pages[i];
counter[pos]=time;
faults++;
}

printf("%d\t",pages[i]);

for(j=0;j<f;j++)
{
if(frames[j]==-1)
printf("- ");
else
printf("%d ",frames[j]);
}

if(found==1)
printf("\tHit\n");
else
printf("\tPage Fault\n");
}

printf("\nTotal Page Faults = %d\n",faults);
printf("Total Page Hits = %d\n",hits);

return 0;
}
