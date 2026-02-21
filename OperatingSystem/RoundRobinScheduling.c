#include <stdio.h>

void enqueue(int queue[], int *rear, int value) {
    queue[++(*rear)] = value;
}

int dequeue(int queue[], int *front, int rear) {
    if (*front > rear) {
        return -1;
    }
    return queue[(*front)++];
}

int isEmpty(int front, int rear) {
    if (front>rear){
    	return 1;
	}
	else{
		return 0;
	}
}

void calculateTimes(int n, int at[], int bt[], int ct[], int tat[], int wt[], int tq) {
    int remaining[20], time = 0, completed = 0, i;
    int queue[50], front = 0, rear = -1;   //   Ready Queue
    int visited[20] = {0};                 // Process already enqueued or not

    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }
    enqueue(queue, &rear, 0);
    visited[0] = 1;
    while (completed < n) {
        if (isEmpty(front, rear)) {
            time++;
            for (i = 0; i < n; i++) {
                if (!visited[i] && at[i] <= time) {
                    enqueue(queue, &rear, i);
                    visited[i] = 1;
                }
            }
            continue;
        }
        int i = dequeue(queue, &front, rear);
        if (remaining[i] > tq) {
            time += tq;
            remaining[i] -= tq;
        } else {
            time += remaining[i];
            remaining[i] = 0;
            completed++;
            ct[i]  = time;
            tat[i] = ct[i] - at[i];
            wt[i]  = tat[i] - bt[i];
        }
        int j;
		for (j = 0; j < n; j++) {
            if (!visited[j] && at[j] <= time) {
                enqueue(queue, &rear, j);
                visited[j] = 1;
            }
        }
        if (remaining[i] > 0) {
            enqueue(queue, &rear, i);
        }
    }
}

void display(int n, int at[], int bt[], int ct[], int tat[], int wt[]) {
    int i;
	float totalTAT = 0, totalWT = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
}

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int i,at[n], bt[n], ct[n], tat[n], wt[n];

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    calculateTimes(n, at, bt, ct, tat, wt, tq);
    display(n, at, bt, ct, tat, wt);

    return 0;
}

