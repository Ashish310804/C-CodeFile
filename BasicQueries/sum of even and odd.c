#include <stdio.h>
int main() {
    int n, i, evenSum = 0, oddSum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        }
        else {
            oddSum += arr[i];
        }
    }
    printf("Sum of even numbers = %d\n", evenSum);
    printf("Sum of odd numbers = %d\n", oddSum);
    return 0;
}
