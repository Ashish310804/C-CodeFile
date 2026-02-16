#include <stdio.h>
#include <math.h>
void computeStatistics(int *arr, int n, float *sum, float *mean, float *std_dev) {
    int i;
    *sum = 0;
    for (i = 0; i < n; i++) {
        *sum += arr[i];
    }
    *mean = *sum / n;
    float variance = 0;
    for (i = 0; i < n; i++) {
        variance += pow(arr[i] - *mean, 2);
    }
    *std_dev = sqrt(variance / n);
}
int main() {
    int n, i, arr[20];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    float sum, mean, std_dev;
    computeStatistics(arr, n, &sum, &mean, &std_dev);
    printf("Sum: %f\n", sum);
    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", std_dev);
    return 0;
}
