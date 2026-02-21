#include <stdio.h>
int main() {
    int arr[10], n, i, max;
    printf("Enter the number of elements (max 10): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[0];  // Initialize max with the first element
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Largest element: %d\n", max);
    return 0;
}
