//2. SJF

#include <stdio.h>

int main() {

    int n = 5;

    int process[] = {0,1,2,3,4};
    int arrival[] = {0,1,2,3,4};
    int burst[] = {4,3,1,5,2};

    int waiting[5] = {0};
    int completed[5] = {0};

    int time = 0, done = 0;
    float totalWaiting = 0;

    while(done < n) {

        int shortest = -1;

        for(int i = 0; i < n; i++) {

            if(arrival[i] <= time && completed[i] == 0) {

                if(shortest == -1 || burst[i] < burst[shortest]) {
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
        }
        else {

            waiting[shortest] = time - arrival[shortest];

            if(waiting[shortest] < 0)
                waiting[shortest] = 0;

            time += burst[shortest];

            completed[shortest] = 1;

            done++;

            totalWaiting += waiting[shortest];
        }
    }

    printf("Process\tWaiting Time\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\n", i, waiting[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           totalWaiting / n);

    return 0;
}
