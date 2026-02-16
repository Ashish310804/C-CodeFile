#include <stdio.h>
int main() {
    int var1 = 10, var2 = 20, var3 = 30;
    int *arr[3];
    arr[0] = &var1;
    arr[1] = &var2;
    arr[2] = &var3;
    for (int i = 0; i < 3; i++) {
        printf("Value at arr[%d] = %d\n", i, *arr[i]);
    }
    return 0;
}
