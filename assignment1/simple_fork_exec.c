#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    pid_t pid;
    int status;
    
    printf("=== Assignment 1: Simple Fork and Exec ===\n");
    printf("Parent process - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Creating child process...\n\n");
    
    // Create child process
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) {
        // Child process
        printf("Child process - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("Child: About to execute 'ls' command...\n\n");
        
        // Use execl to run ls command
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        
        // If execl returns, it means it failed
        perror("execl failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("Parent: Created child with PID %d\n", pid);
        printf("Parent: Waiting for child to complete...\n\n");
        
        // Wait for child process to complete
        wait(&status);
        
        if (WIFEXITED(status)) {
            printf("Parent: Child process exited with status: %d\n", WEXITSTATUS(status));
        }
        
        printf("Parent process done\n");
    }
    
    return 0;
}
