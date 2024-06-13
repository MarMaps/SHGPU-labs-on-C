#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env) {
    int n, k;
    double i, res;

    //printf("Введите n: ");
    //scanf("%d", &n);

    res = 1.0;

    for (k = 1; k <= 5.0 * 10; k++) {
        i = k / 10.0;
        res *= 1.0 + sinf(i);
        printf("%lf | Сумма = %.15lf\n", i, res);
    }

    //printf("%lf Сумма = %.15lf\n", i, res);
    return 0;
}