#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};


void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int shortestJobIndex = -1;
        int shortestRemainingTime = -1;

        // Find the process with the shortest remaining time at the current time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (shortestRemainingTime == -1 || processes[i].remainingTime < shortestRemainingTime) {
                    shortestJobIndex = i;
                    shortestRemainingTime = processes[i].remainingTime;
                }
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }

        // Execute the process for one time unit
        processes[shortestJobIndex].remainingTime--;
        currentTime++;

        if (processes[shortestJobIndex].remainingTime == 0) {
            // Process has completed
            completedProcesses++;
            processes[shortestJobIndex].turnaroundTime = currentTime - processes[shortestJobIndex].arrivalTime;
            processes[shortestJobIndex].waitingTime = processes[shortestJobIndex].turnaroundTime - processes[shortestJobIndex].burstTime;
        }
    }
}


int main() {
    int n;
    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Process %d:", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateTimes(processes, n);
     printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    return 0;
}