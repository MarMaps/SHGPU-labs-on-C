#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env) {
    int n, k;
    double i, res;

    printf("Введите n: ");
    scanf("%d", &n);

    res = 1.0;

    for (k = 1; k <= n * 10; k++) {
        i = k / 10.0;
        res *= 1.0 + sinf(i);
        
    }

    printf("Сумма = %.15lf\n", res);
    return 0;
}