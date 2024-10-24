#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env) {
    int n, i;
    float sum, sum_sin;
    printf("введите n: ");
    scanf("%d", &n);

    sum = 0;
    sum_sin = 0;

    for (i = 1; i <= n; i++) {
        sum_sin += sinf(i);
        sum += 1 / sum_sin;
    }

    printf("сумма = %f\n", sum);
    return 0;
}
