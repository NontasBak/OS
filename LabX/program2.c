#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];
    char message[] = "Hello from the parent process!";

    // Create a pipe
    if(pipe(fd) == -1) {
        perror("Pipe error");
        return 1;
    }

    // Fork to create a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork error");
        return 1;
    }

    if (pid == 0) { 
        // Child process
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {  
        // Parent process
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    
    return 0;
}
