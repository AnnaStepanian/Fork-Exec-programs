#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{ 
    pid_t pid1, pid2, pid3;
    int status;
    
    printf("=== Multiple Fork Calls ===\n");
    printf("Initial process - PID: %d, PPID: %d\n", getpid(), getppid());
    
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        printf("Child 1 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        printf("Parent - PID: %d, Child: %d\n", getpid(), pid1);
    }
    
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        printf("Child 2 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        printf("Parent - PID: %d, Child: %d\n", getpid(), pid2);
    }
    
    pid3 = fork();
    
    if (pid3 < 0) {
        perror("Third fork failed");
        exit(1);
    }
    
    if (pid3 == 0) {
        printf("Child 3 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        printf("Parent - PID: %d, Child: %d\n", getpid(), pid3);
    }
    
    if (pid1 > 0 && pid2 > 0 && pid3 > 0) {
        // Original parent waits for all children
        while (wait(&status) > 0) {
            // Wait for children to complete
        }
        
        printf("\n--- Analysis ---\n");
        printf("Total processes created: 8 (2^3 = 8)\n");
        printf("Each fork() doubles the number of processes.\n");
    }
    
    return 0; 
}
