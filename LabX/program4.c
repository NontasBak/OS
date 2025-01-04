#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork error");
    } else if (pid == 0) {
        fprintf(fp, "Child PID: %d\n", getpid());
        printf("Data written to output.txt successfully from child.\n");
    } else {
        fprintf(fp, "Parent PID: %d\n", getpid());
        printf("Data written to output.txt successfully from parent.\n");
    }

    if (fclose(fp) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}