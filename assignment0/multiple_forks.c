#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{ 
    pid_t pid1, pid2, pid3;
    int status;
    
    printf("=== Assignment 0: Multiple Fork Calls ===\n");
    printf("Initial process - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Process tree before any forks:\n");
    printf("  %d (initial process)\n", getpid());
    printf("\n");
    
    printf("--- First fork() call ---\n");
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        // Child process from first fork
        printf("Child 1 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent after first fork - PID: %d, PPID: %d, Child PID: %d\n", 
               getpid(), getppid(), pid1);
    }
    
    printf("--- Second fork() call ---\n");
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        // Child process from second fork
        printf("Child 2 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent after second fork - PID: %d, PPID: %d, Child PID: %d\n", 
               getpid(), getppid(), pid2);
    }
    
    printf("--- Third fork() call ---\n");
    pid3 = fork();
    
    if (pid3 < 0) {
        perror("Third fork failed");
        exit(1);
    }
    
    if (pid3 == 0) {
        // Child process from third fork
        printf("Child 3 - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent after third fork - PID: %d, PPID: %d, Child PID: %d\n", 
               getpid(), getppid(), pid3);
    }
    
    // Wait for all child processes to complete
    printf("\n--- Process Summary ---\n");
    printf("Current process - PID: %d, PPID: %d\n", getpid(), getppid());
    
    // Only the original parent process should wait for children
    if (pid1 > 0 && pid2 > 0 && pid3 > 0) {
        printf("Original parent waiting for all children to complete...\n");
        
        // Wait for all children
        while (wait(&status) > 0) {
            if (WIFEXITED(status)) {
                printf("Child process exited with status: %d\n", WEXITSTATUS(status));
            }
        }
        
        printf("\n--- Final Process Tree Analysis ---\n");
        printf("Total processes created: 8 (1 original + 7 children)\n");
        printf("Process hierarchy structure:\n");
        printf("  %d (original parent)\n", getpid());
        printf("    ├── %d (child from fork 1)\n", pid1);
        printf("    │   ├── [grandchild from fork 2]\n");
        printf("    │   └── [grandchild from fork 3]\n");
        printf("    ├── %d (child from fork 2)\n", pid2);
        printf("    │   └── [grandchild from fork 3]\n");
        printf("    └── %d (child from fork 3)\n", pid3);
        printf("\nNote: Each fork() creates a binary tree structure.\n");
        printf("With 3 sequential forks, we get 2^3 = 8 total processes.\n");
        printf("The actual PIDs of grandchildren vary due to process scheduling.\n");
    }
    
    return 0; 
}
