#include <stdio.h>

// Function to calculate Completion, Turnaround and Waiting Times
void calculateTimes(int n, int at[], int bt[], int pr[], int ct[], int tat[], int wt[]) {
    int completed = 0, time = 0;
    int done[20] = {0};  // keeps track of finished processes

    while (completed < n) {
        int i, idx = -1, bestPriority = 9999;

        // Find process with highest priority (lowest number = higher priority)
        for (i = 0; i < n; i++) {
            if (at[i] <= time && !done[i]) {
                if (pr[i] < bestPriority) {
                    bestPriority = pr[i];
                    idx = i;
                }
                else if (pr[i] == bestPriority) {
                    // if same priority ? choose process with earlier arrival
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1) {
            // No process has arrived yet ? idle time
            time++;
        } else {
            // Execute chosen process completely (Non-preemptive)
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        }
    }
}

// Function to display results
void display(int n, int at[], int bt[], int pr[], int ct[], int tat[], int wt[]) {
    int i;
	float totalTAT = 0, totalWT = 0;

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int i,at[n], bt[n], pr[n], ct[n], tat[n], wt[n];

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    calculateTimes(n, at, bt, pr, ct, tat, wt);
    display(n, at, bt, pr, ct, tat, wt);

    return 0;
}

