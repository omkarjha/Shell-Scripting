// Write a C program to create a child process and display child PID, parent PID from the child process.

#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1)
    {
        // Fork failed
        perror("fork");
        return 1;
    }

    if (child_pid == 0)
    {
        // Code for the child process
        printf("Child process:\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else
    {
        // Code for the parent process
        printf("Parent process:\n");
        printf("PID: %d\n", getpid());
        printf("Child PID: %d\n", child_pid);
    }

    return 0;
}
