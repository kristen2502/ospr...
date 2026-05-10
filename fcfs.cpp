//fcfs
#include <stdio.h>

int main() {
    int n = 5;

    int arrival[] = {0, 1, 2, 3, 4};
    int burst[] = {4, 3, 1, 5, 2};

    int waiting[5], turnaround[5], completion[5];

    int totalWaiting = 0;

    // First process
    completion[0] = arrival[0] + burst[0];
    waiting[0] = 0;

    // Remaining processes
    for(int i = 1; i < n; i++) {

        // If CPU is idle
        if(completion[i-1] < arrival[i]) {
            completion[i] = arrival[i] + burst[i];
        }
        else {
            completion[i] = completion[i-1] + burst[i];
        }

        waiting[i] = completion[i] - arrival[i] - burst[i];

        totalWaiting += waiting[i];
    }

    printf("Process\tArrival\tBurst\tWaiting\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               i, arrival[i], burst[i], waiting[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)totalWaiting / n);

    return 0;
}
