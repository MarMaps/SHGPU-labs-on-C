#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float x, y, g, s, a, b, c;
	printf("введите катеты: ");
	scanf("%f%f", &x,&y);
	g = sqrt(x * x + y * y);
	s = x * y / 2;
	a = atan(x/y) * 180/M_PI;
	b = 90 - a;
	c = 90;
	printf("гипоненуза =%f\n", g);
	printf("площадь =%f\n", s);
	printf("величины углов: \n%f\n%f\n%f\n", a,b,c);
	return 0;
}

