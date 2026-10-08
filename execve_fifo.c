//Parent Process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int a[20],n,i,j,temp,key;
pid_t pid;
char *args[25];
char num[20];

printf("Enter number of elements: ");
scanf("%d",&n);

printf("Enter array elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}

printf("Sorted array:\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);

printf("\nEnter element to search: ");
scanf("%d",&key);

pid=fork();

if(pid==0)
{
sprintf(num,"%d",n);
args[0]="child";
args[1]=num;

for(i=0;i<n;i++)
{
args[i+2]=malloc(20);
sprintf(args[i+2],"%d",a[i]);
}

args[n+2]=malloc(20);
sprintf(args[n+2],"%d",key);
args[n+3]=NULL;

execve("./child",args,NULL);

perror("execve failed");
exit(1);
}
else if(pid>0)
{
wait(NULL);
}
else
{
perror("fork failed");
return 1;
}

return 0;
}



//child process

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
int a[20],n,key;
int i,low,high,mid;

n=atoi(argv[1]);

for(i=0;i<n;i++)
a[i]=atoi(argv[i+2]);

key=atoi(argv[n+2]);

printf("\nArray received by child:\n");
for(i=0;i<n;i++)
printf("%d ",a[i]);

low=0;
high=n-1;

while(low<=high)
{
mid=(low+high)/2;

if(a[mid]==key)
{
printf("\nElement found at position %d\n",mid+1);
return 0;
}
else if(a[mid]<key)
low=mid+1;
else
high=mid-1;
}

printf("\nElement not found\n");

return 0;
}

//Both in same directory


//------------------------------------------------------------------------------------------


#include <stdio.h>

int main()
{
int pages[20]={3,4,5,6,3,4,7,3,4,5,6,7,2,4,6};
int frames[10];
int n=15,f,i,j;
int pageFaults=0,pointer=0,found;

printf("Enter number of frames: ");
scanf("%d",&f);

for(i=0;i<f;i++)
frames[i]=-1;

printf("\nPage\tFrames\t\tStatus\n");

for(i=0;i<n;i++)
{
found=0;

for(j=0;j<f;j++)
{
if(frames[j]==pages[i])
{
found=1;
break;
}
}

if(found==0)
{
frames[pointer]=pages[i];
pointer=(pointer+1)%f;
pageFaults++;
}

printf("%d\t",pages[i]);

for(j=0;j<f;j++)
{
if(frames[j]==-1)
printf("- ");
else
printf("%d ",frames[j]);
}

if(found==0)
printf("\tYES");
else
printf("\tNO");

printf("\n");
}

printf("\nTotal Page Faults = %d\n",pageFaults);

return 0;
}
