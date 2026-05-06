//write a c++ program to simulate the following non preemptive cpu scheduling algo to find average waiting time.
#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int bt;   // Burst Time
    int pr;   // Priority
    int wt;   // Waiting Time
};

// -------- FCFS --------
void fcfs(Process p[], int n) {
    int total_wt = 0;
    p[0].wt = 0;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    cout << "\nFCFS Scheduling:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << " WT=" << p[i].wt << endl;
        total_wt += p[i].wt;
    }

    cout << "Average Waiting Time = " << (float)total_wt / n << endl;
}

// -------- SJF (Non-preemptive) --------
bool compareBT(Process a, Process b) {
    return a.bt < b.bt;
}

void sjf(Process p[], int n) {
    sort(p, p + n, compareBT);

    int total_wt = 0;
    p[0].wt = 0;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    cout << "\nSJF Scheduling:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << " WT=" << p[i].wt << endl;
        total_wt += p[i].wt;
    }

    cout << "Average Waiting Time = " << (float)total_wt / n << endl;
}

// -------- Priority (Non-preemptive) --------
bool comparePR(Process a, Process b) {
    return a.pr < b.pr;  // lower value = higher priority
}

void priorityScheduling(Process p[], int n) {
    sort(p, p + n, comparePR);

    int total_wt = 0;
    p[0].wt = 0;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    cout << "\nPriority Scheduling:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << " WT=" << p[i].wt << endl;
        total_wt += p[i].wt;
    }

    cout << "Average Waiting Time = " << (float)total_wt / n << endl;
}

// -------- Main Function --------
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n], temp[n];

    cout << "Enter Burst Time and Priority:\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << i + 1 << " BT: ";
        cin >> p[i].bt;
        cout << "P" << i + 1 << " Priority: ";
        cin >> p[i].pr;
    }

    // Copy array for each algorithm
    for (int i = 0; i < n; i++) temp[i] = p[i];
    fcfs(temp, n);

    for (int i = 0; i < n; i++) temp[i] = p[i];
    sjf(temp, n);

    for (int i = 0; i < n; i++) temp[i] = p[i];
    priorityScheduling(temp, n);

    return 0;
}
