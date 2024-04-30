#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float a, a2, a5, a17;
	printf("введите а: ");
	scanf("%f", &a);
	a2 = a*a;
	a5 = a2*a2*a;
	a17 = a5*a5*a5*a2;
	printf("a^2 = %f\na^5 = %f\na^17 = %f\n", a2, a5, a17);
	return 0;
	}
