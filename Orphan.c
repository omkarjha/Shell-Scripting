#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        // Parent terminates early
        sleep(1);
    }
    else if (pid == 0) {
        sleep(2);  // Ensure parent terminates first
        printf("Child process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        sleep(3);
    }
    
    return 0;
}
