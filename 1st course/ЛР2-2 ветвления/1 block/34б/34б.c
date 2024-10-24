#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	float x, y, z;
	float eps = 0.000001;
	printf("введите x, y, z: ");
	scanf("%f%f%f", &x, &y, &z);
	
	if (fabs(x - z) < eps) {
		if (fabs(x - y) < eps)
			printf("max: %f - x,y,z\nmin: %f - x,y,z\n", x, y);
		else if (x > y)
			printf("max:\n %f - x\n %f - z\nmin: %f - y\n", x, z, y);
		else
			printf("max: %f - y\nmin:\n %f - x\n %f - z\n", y, x, z);
	}
	
	else if (z > x) {
		if (fabs(x - y) < eps)
			printf("max: %f - z\nmin:\n %f - x\n %f - y\n", z, x, y);
		else if (x < y && fabs(z - y) < eps)
			printf("max:\n %f - y\n %f - z\nmin: %f - x\n", y, z, x);
		else if (x > y)
			printf("max: %f - z\nmin: %f - y\n", z, y);
		else if (x < y && y > z)
			printf("max: %f - y\nmin: %f - x\n", y, x);
		else if (x < y && y < z)
			printf("max: %f - z\nmin: %f - x\n", z, x);
	}
	
	else if (z < x) {
		if (fabs(x - y) < eps)
			printf("max:\n %f - x\n %f - y\nmin: %f - z\n", x, y, z);
		else if (x > y && fabs(z - y) < eps)
			printf("max: %f - x\nmin:\n %f - y\n %f - z\n", x, y, z);
		else if (x > y && z > y)
			printf("max: %f - x\nmin: %f - y\n", x, y);
		else if (x > y && z < y)
			printf("max: %f - x\nmin: %f - z\n", x, z);
		else if (x < y)
			printf("max: %f - y\nmin: %f - z\n", y, z);
	}
	return 0;
}
