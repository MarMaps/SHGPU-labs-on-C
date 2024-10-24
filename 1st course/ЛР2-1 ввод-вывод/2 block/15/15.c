#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float x, y, z, r, q;
    printf("введите катет и гипотенузу: ");
    scanf("%f%f", &x, &y);
    z = sqrt(pow(y, 2)-pow(x, 2));
	r = (x+z-y)/2;
    q = y/2;
    printf("второй катет= %f\n", z);
    printf("радиус вписанной окружности= %f\n", r);
    printf("радиус описанной окружности= %f\n", q);
    return 0;
}
