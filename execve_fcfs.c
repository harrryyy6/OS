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
