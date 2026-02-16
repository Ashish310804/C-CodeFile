#include <stdio.h>
int main() {
    int arr[10], n, i, target;
    printf("Enter the number of elements (max 10): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element: ");
    scanf("%d", &target);
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d.\n", i);
            break;
        }
    }
    if (i == n) {
        printf("Element not found in the array.\n");
    }
    return 0;
}

