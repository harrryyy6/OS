//SSTF Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,j;
int request[100],visited[100]={0};
int head;
int totalMovement=0;
int min,index;

printf("Enter total number of disk blocks: ");
scanf("%d",&n);

printf("Enter number of disk requests: ");
int m;
scanf("%d",&m);

printf("Enter disk request string:\n");
for(i=0;i<m;i++)
scanf("%d",&request[i]);

printf("Enter current head position: ");
scanf("%d",&head);

printf("\n\nOrder of service:\n");

for(i=0;i<m;i++)
{
min=9999;
index=-1;

for(j=0;j<m;j++)
{
if(visited[j]==0)
{
if(abs(request[j]-head)<min)
{
min=abs(request[j]-head);
index=j;
}
}
}

visited[index]=1;
totalMovement+=min;
head=request[index];

printf("%d",head);

if(i!=m-1)
printf(" -> ");
}

printf("\n\nTotal head movements = %d\n",totalMovement);

return 0;
}

//--------------------------------------------------------------------------------------------------------

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
