#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    for(int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            printf("Child process: PID = %d\n", getpid());
            return 0; // Prevent child processes from forking
        } else {
            printf("Parent process: PID = %d\n", getpid());
        }
    }

    // Wait for child processes to finish
    for (int i = 0; i < 3; i++) {
        int status;
        wait(&status);
    }

    return 0;  
}