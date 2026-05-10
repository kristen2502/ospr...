//fibonacci 
#include <stdio.h>
#include <unistd.h>   // for fork()
#include <sys/types.h>
#include <sys/wait.h> // for wait()

int main() {
    int n, i;
    pid_t pid;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        int t1 = 0, t2 = 1, next;

        printf("\nChild process generating Fibonacci sequence:\n");

        for (i = 0; i < n; i++) {
            printf("%d ", t1);
            next = t1 + t2;
            t1 = t2;
            t2 = next;
        }

        printf("\n");
    }
    else {
        // Parent process
        wait(NULL);  // wait for child to finish
        printf("\nParent process: Child completed execution.\n");
    }

    return 0;
}
