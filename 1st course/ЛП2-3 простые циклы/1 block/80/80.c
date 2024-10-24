#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env) 
{   
    double x, res, fact, zn;
    int i, n;

    //для проверки
    double res_2;

    printf("введите x: ");
    scanf("%lf", &x);

    printf("введите n: ");
    scanf("%d", &n);

    if ((n % 2) == 0 ) {
        printf("ошибка: число n должно быть нечётным\n");
        return 0;
    }

    res = 0.0;
    fact = 1;

    for (i = 1; i <= n; i += 2) {
        if (i > 1) {
            fact *= i * (i - 1);
        }
    zn = pow(x, i) / fact;

    if ((i / 2) % 2 == 1) {
        zn = -zn;
    }
    res += zn;
    }
    printf("результат: %lf\n", res);

    //проверка
    res_2 = 4 - (pow(4, 3) / (1*2*3)) + (pow(4, 5) / (1*2*3*4*5)) -
    (pow(4, 7) / (1*2*3*4*5*6*7)) + (pow(4, 9) / (1*2*3*4*5*6*7*8*9));
    printf("результат(проверки): %lf\n", res_2);

    return 0;
}