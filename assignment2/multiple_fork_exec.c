#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    pid_t pid1, pid2;
    
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        perror("execl ls failed");
        exit(1);
    }
    
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }
    
    if (pid2 == 0) {
        execl("/bin/date", "date", (char *)NULL);
        perror("execl date failed");
        exit(1);
    }
    
    while (wait(NULL) > 0) {
    }
    
    printf("Parent process done\n");
    
    return 0;
}
