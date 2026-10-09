#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if(pid == 0)
    {
        // Child process
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        sleep(5);   // by this time, parent will have exited

        printf("Child (after parent exit): PID = %d, New Parent PID = %d\n", getpid(), getppid());
        printf("(Child has become an orphan and was adopted by init/systemd)\n");
    }
    else
    {
        // Parent process exits immediately without waiting
        printf("Parent: PID = %d, exiting now...\n", getpid());
    }

    return 0;
}