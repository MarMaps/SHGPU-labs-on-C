#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float x, y, z, a, b, a1, b1;
    scanf("%f%f%f", &x, &y, &z);
    a = y + (x/(y*y+fabs(x*x/(y+pow(x, 3)/3))));
    b = 1 + pow(tan(z/2), 2);
    printf("г) a= %f\n", a);
    printf("b= %f\n", b);
    a1 = (2 * cosf(x-M_PI/6))/(0.5 + pow(sinf(y), 2));
    b1 = 1 + pow(z, 2)/(3 + pow(z, 2)/5);
    printf("д) a= %f\n", a1);
    printf("b= %f\n", b1);
    return 0;
}
