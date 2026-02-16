#include <stdio.h>
// Recursive function to check if a number is prime
int is_prime(int n, int i) {
    // Base case: if n is less than 2, it's not prime
    if (n < 2) {
        return 0;
    }
    // Base case: if n is 2, it's prime
    if (n == 2) {
        return 1;
    }
    // Base case: if n is divisible by i, it's not prime
    if (n % i == 0) {
        return 0;
    }
    // Recursive case: check if n is divisible by i+1
    if (i * i <= n) {
        return is_prime(n, i + 1);
    }
    // If n is not divisible by any number up to sqrt(n), it's prime
    return 1;
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (is_prime(num, 2)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}
