#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    double k, v, s, d;
	scanf ("%lf", &k);
	v = k * k * k;
	s = 4 * (k * k);
	d = k * sqrt(3);
	printf("объем куба =%lf\n", v);
	printf("площадь боковой поверхности =%lf\n", s);
	printf("расстояние между углами куба =%lf\n", d);
    return 0;
}
