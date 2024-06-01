#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float x, y, z;
	printf("введите x, y, z: ");
	scanf("%f%f%f", &x, &y, &z);
	
	if (x > y && x > z) {
		printf ("max = %f - x\n", x);
	}
	else if (y > x && y > z) {
		printf ("max = %f - y\n", y);
	}
	else {
		printf ("max = %f - z\n", z);
	}
	
	if (x < y && x < z) {
		printf ("min = %f - x\n", x);
	}
	else if (y < x && y < z) {
		printf ("min = %f - y\n", y);
	}
	else {
		printf ("min = %f - z\n", z);
	}
	return 0;
	}
