// Write a C++ program to demonstrate process creation using fork()

#include <iostream>
#include <unistd.h>   // fork(), getpid(), getppid()
#include <sys/types.h>

using namespace std;

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        cout << "Fork failed!" << endl;
        return 1;
    }
    else if (pid == 0) {
        // Child process
        cout << "This is the child process." << endl;
        cout << "Child PID: " << getpid() << endl;
        cout << "Parent PID: " << getppid() << endl;
    }
    else {
        // Parent process
        cout << "This is the parent process." << endl;
        cout << "Parent PID: " << getpid() << endl;
        cout << "Child PID: " << pid << endl;
    }

    return 0;
}
