#include <stdio.h>

int main(int argc, char **argv, char **env) 
{   
    double a, sum;
    int i;

    printf("введите a: ");
    scanf("%lf", &a);

    sum = 0.0;
    for (i = 1; a >= sum; i++) {
            sum += 1.0 / i;
            printf("%lf\n", sum);
        }
    return 0;
}