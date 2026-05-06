//write a program that creates three child processes using fork()
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    const int NUM_CHILDREN = 3;

    std::cout << "Parent process (PID: " << getpid() << ") starting...\n" << std::endl;

    for (int i = 0; i < NUM_CHILDREN; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            // Error handling
            std::cerr << "Fork failed!" << std::endl;
            return 1;
        } 
        else if (pid == 0) {
            // Child process logic
            std::cout << "Child " << i + 1 << " created (PID: " << getpid() 
                      << ", Parent PID: " << getppid() << ")" << std::endl;
            
            // Critical: Child must exit the loop so it doesn't fork its own children
            return 0; 
        }
        // Parent continues the loop to create the next child
    }

    // Parent waits for all children to finish
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        wait(NULL);
    }

    std::cout << "\nAll children have finished. Parent exiting." << std::endl;

    return 0;
}
