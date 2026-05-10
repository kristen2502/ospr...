//3. PSP

#include <stdio.h>

int main() {

    int n = 5;

    int process[] = {0,1,2,3,4};
    int arrival[] = {0,1,2,3,4};
    int burst[] = {4,3,1,5,2};
    int priority[] = {2,3,4,5,5};

    int waiting[5] = {0};
    int completed[5] = {0};

    int time = 0, done = 0;
    float totalWaiting = 0;

    while(done < n) {

        int highest = -1;

        for(int i = 0; i < n; i++) {

            if(arrival[i] <= time && completed[i] == 0) {

                if(highest == -1 ||
                   priority[i] < priority[highest]) {

                    highest = i;
                }
            }
        }

        if(highest == -1) {
            time++;
        }
        else {

            waiting[highest] = time - arrival[highest];

            if(waiting[highest] < 0)
                waiting[highest] = 0;

            time += burst[highest];

            completed[highest] = 1;

            done++;

            totalWaiting += waiting[highest];
        }
    }

    printf("Process\tPriority\tWaiting Time\n");

    for(int i = 0; i < n; i++) {

        printf("P%d\t%d\t\t%d\n",
               i, priority[i], waiting[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           totalWaiting / n);

    return 0;
}
