#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float x, y, z;
	float eps = 0.000001;
	float sum;
	float x_min, y_min, z_min;
	float x2_min, y2_min;
	printf("введите 3 числа: ");
	scanf("%f%f%f", &x, &y, &z);
	
	sum = x + y + z;
	
	if ((fabs(x - y) < eps) || (fabs(y - z) < eps) || (fabs(x - z) < eps)) {
		printf("числа не являются попрано различимыми\n");
	}
	
	else if (sum < 1) {
		if (x < y && x < z) {
			x_min = (y + z)/2;
			printf("%f\n%f\n%f\n", x_min, y, z);
			}
		else if (y < x && y < z) {
			y_min = (x + z)/2;
			printf("%f\n%f\n%f\n", x, y_min, z);
			}
		else if (z < x && z < y) {
			z_min = (x + y)/2;
			printf("%f\n%f\n%f\n", x, y, z_min);
			}
	}
	
	else if (sum >= 1) {
		if (x < y && x < z) {
			x2_min = (y + z)/2;
			printf("%f\n%f\n%f\n", x2_min, y, z);
			}
		else if (y < x && y < z) {
			y2_min = (x + z)/2;
			printf("%f\n%f\n%f\n", x, y2_min, z);
			}
		else {
			printf("%f\n%f\n%f\n", x, y, z);
			} 
	}
	return 0;
}
