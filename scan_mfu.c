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


//--------------------------------------------------------------------------------------------------------



//MFU

#include <stdio.h>

int main()
{
int pages[]={8,5,7,8,5,7,2,3,7,3,5,9,4,6,2};
int frames[20],freq[20];
int n=15,f,i,j;
int faults=0,hits=0;
int found,pos,max;

printf("Enter number of frames: ");
scanf("%d",&f);

if(f<1||f>20)
{
printf("Invalid number of frames.\n");
return 1;
}

for(i=0;i<f;i++)
{
frames[i]=-1;
freq[i]=0;
}

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<n;i++)
{
found=0;

for(j=0;j<f;j++)
{
if(frames[j]==pages[i])
{
freq[j]++;
found=1;
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
max=freq[0];
pos=0;

for(j=1;j<f;j++)
{
if(freq[j]>max)
{
max=freq[j];
pos=j;
}
}
}

frames[pos]=pages[i];
freq[pos]=1;
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

if(found)
printf("\tHit\n");
else
printf("\tPage Fault\n");
}

printf("\nTotal Page Faults = %d\n",faults);
printf("Total Page Hits = %d\n",hits);

return 0;
}
