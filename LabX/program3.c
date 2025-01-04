#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child received SIGUSR1: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
            perror("Signal error");
            exit(EXIT_FAILURE);
        }

        printf("Child process ID:%d. Waiting for SIGUSR1\n", getpid());
        
        while (1) {
            pause();  // Wait for signal
        }
    } else {
        printf("Parent process ID:%d. Child PID: %d\n", getpid(), pid);

        sleep(3);  // Sleep before sending SIGUSR1

        if (kill(pid, SIGUSR1) == -1) {
            perror("Kill error");
            exit(EXIT_FAILURE);
        }

        sleep(1);
        
        printf("Parent sent signal\n");
    }

    return 0;
}