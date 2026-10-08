#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int alloc[5][3], max[5][3], need[5][3];
int avail[3];

void accept()
{
int i,j;
printf("\nEnter Allocation Matrix:\n");
for(i=0;i<5;i++)
{
printf("P%d: ",i);
    for(j=0;j<3;j++)
        scanf("%d",&alloc[i][j]);
}

printf("\nEnter Max Matrix:\n");
for(i=0;i<5;i++)
{
printf("P%d: ",i);
    for(j=0;j<3;j++)
        scanf("%d",&max[i][j]);
}

printf("\nEnter Available (A B C): ");
scanf("%d%d%d",&avail[0],&avail[1],&avail[2]);
    for(i=0;i<5;i++)
        for(j=0;j<3;j++)
            need[i][j]=max[i][j]-alloc[i][j];
printf("\nData accepted successfully.");
}

void displayAllocMax()
{
int i;
printf("\nProcess\tAllocation\tMax\n");
printf("\tA B C\t\tA B C\n");
for(i=0;i<5;i++)
    printf("P%d\t%d %d %d\t\t%d %d %d\n",i,alloc[i][0],alloc[i][1],alloc[i][2],max[i][0],max[i][1],max[i][2]);
}

void displayNeed()
{
int i;
printf("\nNeed Matrix\n");
printf("Process\tA\tB\tC\n");
    for(i=0;i<5;i++)
printf("P%d\t%d\t%d\t%d\n",
i,need[i][0],need[i][1],need[i][2]);
}

void displayAvailable()
{
printf("\nAvailable Resources\n");
printf("A\tB\tC\n");
printf("%d\t%d\t%d\n",
avail[0],avail[1],avail[2]);
}

int main()
{
int ch;
do
{
printf("\n\n--- BANKER'S ALGORITHM ---");
printf("\n1. Accept Allocation, Max and Available");
printf("\n2. Display Allocation, Max");
printf("\n3. Find and Display Need");
printf("\n4. Display Available");
printf("\n5. Exit");
printf("\n\nEnter choice: ");
scanf("%d",&ch);

switch(ch)
{
case 1:
    accept();
break;
case 2:
    displayAllocMax();
break;
case 3:
    displayNeed();
break;
case 4:
    displayAvailable();
break;
case 5:
    exit(0);
default:
    printf("\nInvalid choice!");
}
}while(1);
return 0;
}


//----------------------------------------------------------------------------------------------------


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