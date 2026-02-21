#include <stdio.h>
#include <limits.h>
//Preemptive SJF(SRTF)
void calculateTimes(int n, int at[], int bt[], int ct[], int tat[], int wt[]) {
	int remaining[20],completed = 0, time = 0, i ;
	for(i=0;i<n;i++){					//copying burst time of processes
		remaining[i] = bt[i];
	}

	while(completed<n){
		int idx = -1, minbt = 10000,i;
		for(i=0;i<n;i++){
				if(at[i] <= time && remaining[i] < minbt && remaining[i] > 0){
					minbt = remaining[i];
					idx = i;
				}
		}

		if(idx == -1){
			time++;
			continue;
		}
		remaining[idx]--;
		time++;

		if(remaining[idx] == 0){
			completed++;
			ct[idx] = time;
			tat[idx] = ct[idx] - at[idx];
			wt[idx] = tat[idx] - bt[idx];
		}
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
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    calculateTimes(n, at, bt, ct, tat, wt);
    display(n, pid, at, bt, ct, tat, wt);
    return 0;
}

