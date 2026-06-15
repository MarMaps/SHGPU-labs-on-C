#include <stdio.h>
#include <math.h>

int main() {
    int n, tmp, start, end;
    printf("введите n: ");
    scanf("%d", &n);

    start = pow(10, n - 1);
    end = pow(10, n) - 1;

    printf("числа армстронга с %d цифрами:\n", n);

    for (int i = start; i <= end; i++) {
        int sum = 0;
        tmp = i;

        while (tmp > 0) {
            int digit = tmp % 10;
            sum += pow(digit, n);
            tmp /= 10;
    }

        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
