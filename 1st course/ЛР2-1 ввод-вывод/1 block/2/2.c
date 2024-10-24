#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float x, y, a, b;
	scanf("%f%f", &x, &y);
	a = (fabs(x) - fabs(y)) / (1 + fabs(x * y));
	printf("%f\n", a);
	b = (x - y) / (1 + x * y);
	printf("без модулей: %f\n", b);
    return 0;
}
