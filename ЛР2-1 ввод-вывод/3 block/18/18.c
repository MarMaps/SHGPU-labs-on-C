#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float alfa, beta, gamma, r, a, b, c;
    printf("введите углы: ");
    scanf("%f%f%f", &alfa, &beta, &gamma);
    printf("введите радиус: ");
    scanf("%f", &r);
    alfa = alfa * M_PI / 180;
    beta = beta * M_PI / 180;
    gamma = gamma * M_PI / 180;
    a = 2*r * sinf(alfa);
    b = 2*r * sinf(beta);
    c = 2*r * sinf(gamma);
    printf("стороны треугольника =%f, %f, %f\n", a,b,c);
    return 0;
}
