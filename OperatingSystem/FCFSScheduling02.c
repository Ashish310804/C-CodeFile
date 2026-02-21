#include <stdio.h>

void sortByArrival(int n, int pid[], int at[], int bt[]) {
    int temp,i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival time
                temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                // Swap burst time
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                // Swap process id
                temp = pid[j]; pid[j] = pid[j + 1]; pid[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(int n, int at[], int bt[], int ct[], int tat[], int wt[]) {
    int currentTime = 0,i;
    for (i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];   // CPU idle till process arrives
        }
        ct[i] = currentTime + bt[i];
        currentTime = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

void display(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[]) {
    int i;
	float totalTAT = 0, totalWT = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }
    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
}

int main() {
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    // Input inside main
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    sortByArrival(n, pid, at, bt);
    calculateTimes(n, at, bt, ct, tat, wt);
    display(n, pid, at, bt, ct, tat, wt);
    return 0;
}

