#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }
    
    return 0;
}
