#include <stdio.h>

#define SQR(a) ((a)*(a))
#define SUMM(a,b) (a+b)

void treyg(float x, float y, float z)
{
	if (SUMM(x,y) > z && SUMM(y,z) > x && SUMM(x,z) > y) {
		printf("треугольник существует\n");

		if ((SQR(x) + SQR(y)) > SQR(z) && (SQR(y) + SQR(z)) > SQR(x) && (SQR(x) + SQR(z)) > SQR(y)) {
			printf("треугольник явл остроугольным\n");
		}

		else {
		printf("треугольник не явл остроугольным\n");
		}

	}

	else {
		printf("треугольника не существует\n");	
	}
}

int main(int argc, char **argv, char **env)
{
	float x_i, y_i, z_i;

	scanf("%f%f%f", &x_i, &y_i, &z_i);
	treyg(x_i, y_i, z_i);

	return 0;
}
