#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    pid_t pid1, pid2;
    int status;
    
    printf("=== Assignment 2: Multiple Forks and Execs ===\n");
    printf("Parent process - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Creating two child processes...\n\n");
    
    // Create first child process
    printf("--- Creating First Child (ls command) ---\n");
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        // First child process - run ls command
        printf("First child - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("First child: About to execute 'ls -l' command...\n\n");
        
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        
        // If execl returns, it means it failed
        perror("execl ls failed");
        exit(1);
    }
    
    // Create second child process
    printf("--- Creating Second Child (date command) ---\n");
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        // Second child process - run date command
        printf("Second child - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("Second child: About to execute 'date' command...\n\n");
        
        execl("/bin/date", "date", (char *)NULL);
        
        // If execl returns, it means it failed
        perror("execl date failed");
        exit(1);
    }
    
    // Parent process
    printf("Parent process - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Parent: Created children with PIDs %d and %d\n", pid1, pid2);
    printf("Parent: Waiting for both children to complete...\n\n");
    
    // Wait for both child processes to complete
    int child_count = 0;
    while (wait(&status) > 0) {
        child_count++;
        if (WIFEXITED(status)) {
            printf("Parent: Child %d exited with status: %d\n", child_count, WEXITSTATUS(status));
        }
    }
    
    printf("\nParent: Both children have completed\n");
    printf("Parent process done\n");
    
    return 0;
}
