//Orphan process
 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;

pid=fork();

if(pid==0)
{
sleep(5);

printf("Child Process\n");
printf("Child PID: %d\n",getpid());
printf("Parent PID: %d\n",getppid());
printf("Child becomes orphan process\n");
}
else if(pid>0)
{
printf("Parent Process\n");
printf("Parent PID: %d\n",getpid());
printf("Parent is terminating...\n");
}
else
{
printf("Fork failed\n");
}

return 0;
}


//------------------------------------------------------------------------------------------------------------------------------



//Shell search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void search(char option,char *file,char *pattern)
{
FILE *fp;
char str[1000];
char *p;
int count=0;
int line=0;
int index;

fp=fopen(file,"r");

if(fp==NULL)
{
printf("File not found\n");
return;
}

while(fgets(str,sizeof(str),fp))
{
line++;
p=str;

while((p=strstr(p,pattern))!=NULL)
{
count++;
index=p-str;

if(option=='f')
{
printf("First occurrence found at line %d, index %d\n",line,index+1);
fclose(fp);
return;
}

if(option=='a')
{
printf("Occurrence %d found at line %d, index %d\n",count,line,index+1);
}

p++;
}
}

fclose(fp);

if(option=='a')
printf("Total occurrences = %d\n",count);

if(option=='c')
printf("Number of occurrences = %d\n",count);

if(option!='f'&&option!='a'&&option!='c')
printf("Invalid option\n");

if(count==0)
printf("Pattern not found\n");
}

int main()
{
char command[200];
char *args[20];
char *token;
int n;
pid_t pid;

while(1)
{
printf("$ ");
fflush(stdout);

if(fgets(command,sizeof(command),stdin)==NULL)
break;

command[strcspn(command,"\n")]='\0';

if(strlen(command)==0)
continue;

n=0;
token=strtok(command," ");

while(token!=NULL&&n<19)
{
args[n++]=token;
token=strtok(NULL," ");
}

args[n]=NULL;

if(strcmp(args[0],"exit")==0)
break;

if(strcmp(args[0],"search")==0)
{
if(n!=4)
{
printf("Usage: search f/a/c filename pattern\n");
continue;
}

search(args[1][0],args[2],args[3]);
continue;
}

pid=fork();

if(pid<0)
{
printf("Fork Failed\n");
}
else if(pid==0)
{
execvp(args[0],args);
printf("Command not found\n");
exit(1);
}
else
{
wait(NULL);
}
}

return 0;
}
