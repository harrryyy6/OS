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

//------------------------------------------------------------------------------------------------------------


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
