#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// Global variables to track process hierarchy
static int fork_level = 0;
static pid_t original_pid;

void print_process_info(const char* context) {
    printf("[Level %d] %s - PID: %d, PPID: %d\n", 
           fork_level, context, getpid(), getppid());
}

int main() 
{ 
    pid_t pid1, pid2, pid3;
    int status;
    
    original_pid = getpid();
    
    printf("=== Enhanced Multiple Fork Analysis ===\n");
    printf("Original process - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("\n");
    
    // First fork
    printf("--- FORK 1 ---\n");
    fork_level = 0;
    print_process_info("Before fork 1");
    
    pid1 = fork();
    fork_level++;
    
    if (pid1 < 0) {
        perror("Fork 1 failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        print_process_info("Child from fork 1");
    } else {
        print_process_info("Parent after fork 1");
    }
    printf("\n");
    
    // Second fork
    printf("--- FORK 2 ---\n");
    print_process_info("Before fork 2");
    
    pid2 = fork();
    fork_level++;
    
    if (pid2 < 0) {
        perror("Fork 2 failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        print_process_info("Child from fork 2");
    } else {
        print_process_info("Parent after fork 2");
    }
    printf("\n");
    
    // Third fork
    printf("--- FORK 3 ---\n");
    print_process_info("Before fork 3");
    
    pid3 = fork();
    fork_level++;
    
    if (pid3 < 0) {
        perror("Fork 3 failed");
        exit(1);
    }
    
    if (pid3 == 0) {
        print_process_info("Child from fork 3");
    } else {
        print_process_info("Parent after fork 3");
    }
    printf("\n");
    
    // Only the original parent process should wait for children
    if (getpid() == original_pid) {
        printf("=== ORIGINAL PARENT WAITING ===\n");
        printf("Original parent (PID: %d) waiting for all children...\n", getpid());
        
        int child_count = 0;
        while (wait(&status) > 0) {
            child_count++;
            if (WIFEXITED(status)) {
                printf("Child %d exited with status: %d\n", child_count, WEXITSTATUS(status));
            }
        }
        
        printf("\n=== FINAL ANALYSIS ===\n");
        printf("Original parent PID: %d\n", original_pid);
        printf("Total children waited for: %d\n", child_count);
        printf("Total processes created: %d (1 original + %d children)\n", 
               child_count + 1, child_count);
        printf("\nProcess Tree Structure:\n");
        printf("Each fork() call doubles the number of processes:\n");
        printf("  Start: 1 process\n");
        printf("  After fork 1: 2 processes (1 parent + 1 child)\n");
        printf("  After fork 2: 4 processes (2 parents + 2 children)\n");
        printf("  After fork 3: 8 processes (4 parents + 4 children)\n");
        printf("\nFormula: 2^n processes after n fork() calls\n");
        printf("In this case: 2^3 = 8 processes\n");
    }
    
    return 0; 
}

