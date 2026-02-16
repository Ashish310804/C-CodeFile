#include <stdio.h>
int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if(n >= 1) {
        printf("%d, ", t1);
    }
    if(n >= 2) {
        printf("%d, ", t2);
    }
    for(int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d, ", nextTerm);
    }
    return 0;
}
