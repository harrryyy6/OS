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

//------------------------------------------------------------------------------------------

//Shell Program with count command

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char comm[100], *args[10];
int tot;

void getcomm()
{
int len;
fgets(comm,80,stdin);
len=strlen(comm);
comm[len-1]='\0';
}

void sep_args()
{
char *token;
tot=0;
token=strtok(comm," ");
while(token!=NULL)
{
args[tot]=malloc(20);
strcpy(args[tot++],token);
token=strtok(NULL," ");
}
args[tot]=NULL;
}

void count(char option[], char fname[])
{
FILE *fp;
int ch, characters=0, words=0, lines=0, inword=0;
fp=fopen(fname,"r");
if(fp==NULL)
{
printf("Unable to open file\n");
return;
}
while((ch=fgetc(fp))!=EOF)
{
characters++;
if(ch=='\n')
lines++;
if(ch==' ' || ch=='\t' || ch=='\n')
inword=0;
else if(inword==0)
{
words++;
inword=1;
}
}
fclose(fp);
if(strcmp(option,"c")==0)
printf("Total characters = %d\n",characters);
else if(strcmp(option,"w")==0)
printf("Total words = %d\n",words);
else if(strcmp(option,"l")==0)
printf("Total lines = %d\n",lines+1);
else
printf("Invalid option\n");
}

int main()
{
pid_t pid;
int status;
char str[100];
while(1)
{
printf("$ ");
getcomm();
sep_args();
if(args[0]==NULL)
continue;

if(strcmp(args[0],"count")==0)
{
if(tot!=3)
{
printf("Usage: count c|w|l filename\n");
continue;
}
count(args[1],args[2]);
}
else
{
pid=fork();
if(pid<0)
{
printf("Fork Failed\n");
continue;
}
if(pid==0)
{
execvp(args[0],args);
strcpy(str,"./");
strcat(str,args[0]);
execvp(str,args);
printf("%s : Command not found\n",args[0]);
exit(0);
}
else
waitpid(pid,&status,0);
}
}
return 0;
}
