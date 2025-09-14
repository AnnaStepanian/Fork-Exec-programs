#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        execl("/usr/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        perror("execl failed");
        exit(1);
    }
    else {
        wait(NULL);
        printf("Parent process completed\n");
    }
    
    return 0;
}
