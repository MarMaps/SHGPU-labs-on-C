#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float x, y, z;
	float eps = 0.000001;

	scanf("%f%f%f", &x, &y, &z);
	if ((x + y) > z && (y + z) > x && (x + z) > y) {
		printf("треугольник существует\n");

		if ((x*x + y*y) > z*z && (y*y + z*z) > x*x && (x*x + z*z) > y*y) {
			printf("треугольник является остроугольным\n");
		}

		else {
		printf("треугольник не является остроугольным\n");
		}

		if ((fabs(x - y) < eps) && (fabs(y - z) < eps) && (fabs(x - z) < eps)) {
			printf("треугольник равносторонний\n");
		}

		else if ((fabs(x - y) < eps) || (fabs(y - z) < eps) || (fabs(x - z) < eps)) {
			printf("треугольник равнобедренный\n");
		}

		else if ((fabs((x*x + y*y) - z*z) < eps) || (fabs((y*y + z*z) - x*x) < eps) || (fabs((x*x + z*z) - y*y) < eps)) {
			printf("треугольник прямоугольный\n");
		}
	}

	else {
		printf("треугольника не существует\n");
	}

	return 0;
}