#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float a, b, c;
	printf("введите a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);
	
	if (a < b && b < c){
		printf("1 условие верно\n");
	}
	else {
		printf("1 условие неверно\n");
	}
	
	if (a <= b && b <= c){
		printf("2 условие верно\n");
	}
	else {
		printf("2 условие неверно\n");
	}
	
	if (a >= b && b >= c){
		printf("3 условие верно\n");
	}
	else {
		printf("3 условие неверно\n");
	}
	return 0;
	}
