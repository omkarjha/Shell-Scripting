// 5. ZOMBIE PROCESS
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        sleep(50);  // Parent sleeps, doesn't wait for child
    }
    else if (pid == 0) {
        printf("Child process\n");
        printf("Child PID: %d\n", getpid());
        exit(0);  // Child terminates
    }
    
    return 0;
}
