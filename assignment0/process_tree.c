#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void print_tree_level(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

int main() 
{ 
    printf("=== Process Tree Visualization ===\n\n");
    
    pid_t original_pid = getpid();
    printf("Original process: PID %d\n", original_pid);
    
    // First fork
    printf("\n--- Fork 1 ---\n");
    pid_t pid1 = fork();
    
    if (pid1 < 0) {
        perror("Fork 1 failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        // Child 1
        print_tree_level(1);
        printf("Child 1: PID %d (parent: %d)\n", getpid(), getppid());
    } else {
        // Parent
        print_tree_level(0);
        printf("Parent: PID %d\n", getpid());
        print_tree_level(1);
        printf("Child 1: PID %d\n", pid1);
    }
    
    // Second fork
    printf("\n--- Fork 2 ---\n");
    pid_t pid2 = fork();
    
    if (pid2 < 0) {
        perror("Fork 2 failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        // Child from fork 2
        if (getpid() != original_pid) {
            print_tree_level(2);
            printf("Grandchild: PID %d (parent: %d)\n", getpid(), getppid());
        }
    } else {
        // Parent
        if (getpid() == original_pid) {
            print_tree_level(0);
            printf("Parent: PID %d\n", getpid());
            print_tree_level(1);
            printf("Child 1: PID %d\n", pid1);
            print_tree_level(2);
            printf("Grandchild: PID %d\n", pid2);
        } else {
            print_tree_level(1);
            printf("Child 1: PID %d\n", getpid());
            print_tree_level(2);
            printf("Grandchild: PID %d\n", pid2);
        }
    }
    
    // Third fork
    printf("\n--- Fork 3 ---\n");
    pid_t pid3 = fork();
    
    if (pid3 < 0) {
        perror("Fork 3 failed");
        exit(1);
    }
    
    if (pid3 == 0) {
        // Child from fork 3
        print_tree_level(3);
        printf("Great-grandchild: PID %d (parent: %d)\n", getpid(), getppid());
    } else {
        // Parent
        if (getpid() == original_pid) {
            print_tree_level(0);
            printf("Parent: PID %d\n", getpid());
            print_tree_level(1);
            printf("Child 1: PID %d\n", pid1);
            print_tree_level(2);
            printf("Grandchild: PID %d\n", pid2);
            print_tree_level(3);
            printf("Great-grandchild: PID %d\n", pid3);
        } else {
            print_tree_level(2);
            printf("Grandchild: PID %d\n", getpid());
            print_tree_level(3);
            printf("Great-grandchild: PID %d\n", pid3);
        }
    }
    
    // Only original parent waits
    if (getpid() == original_pid) {
        int status;
        int child_count = 0;
        
        while (wait(&status) > 0) {
            child_count++;
        }
        
        printf("\n=== Summary ===\n");
        printf("Original parent PID: %d\n", original_pid);
        printf("Total children waited for: %d\n", child_count);
        printf("Total processes created: %d\n", child_count + 1);
        printf("\nProcess Tree Structure:\n");
        printf("Each fork() creates a binary tree:\n");
        printf("  Level 0: 1 process (original)\n");
        printf("  Level 1: 2 processes (1 parent + 1 child)\n");
        printf("  Level 2: 4 processes (2 parents + 2 children)\n");
        printf("  Level 3: 8 processes (4 parents + 4 children)\n");
        printf("\nFormula: 2^n processes after n fork() calls\n");
    }
    
    return 0; 
}

