#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float a, b, c, D;
	float eps = 0.000001;
	float x_1, x_2, x;

	scanf("%f%f%f", &a, &b, &c);

	D = b * b - 4 * a * c;

	if (fabs(a - 0) < eps) {
	 	printf("по условию число 'a' не равно нулю\n");
	}

	else {
		printf("D = %f\n", D);
		if (D > 0) {
			printf("уравнение имеет два действительных корня:\n");
			x_1 = (-b + sqrt(D)) / (2 * a);
			printf("x1 = %f\n", x_1);
			x_2 = (-b - sqrt(D)) / (2 * a);
			printf("x2 = %f\n", x_2);
		}

		else if (fabs(D - 0) < eps) {
			printf("уравнение имеет один действительный корень:\n");
			x = -b / (2 * a);
			printf("%f\n", x); 
		}

		else {
			printf("уравнение не имеет действительных корней\n");
		}
	}
	return 0;
}