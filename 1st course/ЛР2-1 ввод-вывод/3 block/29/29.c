#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float x, y, x2,y2,x2y,xy,x2y2,xy2, p;
	printf("введите x,y: ");
	scanf("%f%f", &x, &y);
	x2 = x*x;
	y2 = y*y;
	x2y = x*x*y;
	xy = x*y;
	x2y2 = (x*x)*(y*y);
	xy2 = x*(y*y);
	p = 3*x2y2 - 2*xy2 - 7*x2y - 4*y2 + 15*xy + 2*x2 - 3*x + 10*y + 6;
	printf("ответ: %f\n", p);
	return 0;
	}
