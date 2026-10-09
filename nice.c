#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void show_priority(char name[])
{
    printf("%s nice value: %d\n", name, nice(0));
}

int main()
{
    int pid;

    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed!\n");
    }
    else if(pid == 0)
    {
        printf("\nChild PID: %d\n", getpid());

        show_priority("Child before");

        nice(5);

        show_priority("Child after");
    }
    else
    {
        wait(NULL);

        printf("\nParent process completed.\n");
    }

    return 0;
}