#include <stdio.h>

int main(int argc, char **argv, char **env)
{
    float a, b, s, v, y, d;
	scanf("%f%f", &a, &b);
	s = a + b;
	v = a - b;
	y = a * b;
	d = a / b;
	printf("сумма =%f\n", s);
	printf("разность =%f\n", v);
	printf("произведение =%f\n", y);
	printf("отношение =%f\n", d);
    return 0;
}
