#include <stdio.h>

#define SUSH_T(a,b,c) (((a)+(b))>(c) && ((b)+(c))>(a) && (((a)+(c))>(b)))
#define OSTR_T(a,b,c) (((a)*(a)+(b)*(b))>(c)*(c) && ((a)*(a)+(c)*(c))>(b)*(b) && ((b)*(b)+(c)*(c))>(a)*(a))

int f_sush_t(float a, float b, float c) {
	return ((a+b)>c && (a+c)>b && (b+c)>a);
}

int f_ostr_t(float a, float b, float c) {
	return ((a*a+b*b)>c*c && (a*a+c*c)>b*b && (b*b+c*c)>a*a);
}


int main(int argc, char **argv, char **env)
{
	float x, y, z;
	scanf("%f%f%f", &x, &y, &z);
	
	printf("макроопределения: \n");
	if (SUSH_T(x, y, z)) {
		printf("треуг существует\n");

		if (OSTR_T(x, y, z)) {
			printf("треуг явл строугольным\n");
		} else {
			printf("треуг не остроугольный\n");
		}
	} else {
		printf("треуг не существует\n");
	}
	printf("\n");
	
	printf("функции: \n");
	if (f_sush_t(x, y, z)) {
		printf("треуг существует\n");

		if (f_ostr_t(x, y, z)) {
			printf("треуг явл строугольным\n");
		} else {
			printf("треуг не остроугольный\n");
		}
	} else {
		printf("треуг не существует\n");
	}

	return 0;
}
