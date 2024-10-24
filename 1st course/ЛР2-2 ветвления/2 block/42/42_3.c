#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
	float x, y, z;
	float eps = 0.000001;
	float x_min, y_min, z_min;
	float x_max, y_max, z_max;
	
	printf("введите 3 числа: ");
	scanf("%f%f%f", &x, &y, &z);
	
	if (x < y && x < z && y < z) {
	    z_max = 2 * (x * y * z);   
	    x_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x_min, y, z_max);
	}
	else if (z < x && z < y && y < x) {
	    x_max = 2 * x * y * z;   
	    z_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x_max, y, z_min);
	}
	
	else if (x < y && x < z && z < y) {
	    y_max = 2 * x * y * z;
	    x_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x_min, y_max, z);
	}
	else if (y < x && y < z && x < z) {
	    z_max = 2 * x * y * z;
	    y_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x, y_min, z_max);
	}
	
	else if (y < x && y < z && z < x) {
	    x_max = 2 * x * y * z;
	    y_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x_max, y_min, z);
	}
	else if (z < x && y > x) { 
	    y_max = 2 * x * y * z;
	    z_min = (x + y + z)/2;
	    printf("%f\n%f\n%f\n", x, y_max, z_min);
	}
	
	else if ((fabs(x - y) < eps) || (fabs(y - z) < eps) || (fabs(x - z) < eps)) {
		printf("по условию числа не должны быть равны\n");
	}
	return 0;
	}
