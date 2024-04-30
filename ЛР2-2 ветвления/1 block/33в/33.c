#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float x, y;
	printf("введите x, y: ");
	scanf("%f%f", &x, &y);
	
	if (x > y){
		printf("max = %f - x\n", x);
	}
	else {
		printf("max = %f - y\n", y);
	}
	
	if (x < y){
		printf("min = %f - x\n", x);
	}
	else {
		printf("min = %f - y\n", y);
	}
	return 0;
	}
