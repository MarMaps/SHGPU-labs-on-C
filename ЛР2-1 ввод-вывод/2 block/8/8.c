#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float r, s, p, a, q;
	int n, m;
	printf("введите количество углов описанного n-угольника: ");
	scanf("%d", &n);
	printf("введите радиус окружности: ");
	scanf("%f", &r);
	printf("введите количество углов вписанного n-угольника: ");
	scanf("%d", &m);
	s = (2 * r) * (sinf(M_PI/n));
	p = n * s;
	a = (2 * r) * (tanf(M_PI/m));
	q = m * a; 
	printf("периметр описанного n-угольника= %f\n", p);
	printf("периметр вписанного n-угольника= %f\n", q);
	return 0;
}
