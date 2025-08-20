#include <stdio.h>

#define PAL(n) ((n) >= 0 && (n) <= 9999) && ((n) / 1000 == (n) % 10) && (((n) / 100) % 10 == ((n) / 10) % 10)

int palindrome(int n)
{
	if (n < 0 || n > 9999) {
		return 0;
	}
	
	int n1 = n / 1000;
	int n2 = (n / 100) % 10;
	int n3 = (n / 10) % 10;
	int n4 = n % 10;

	return n1 == n4 && n2 == n3;
}

int main()
{
	int n;
	printf("число n: ");
	scanf("%d", &n);

	printf("макроопределение: \n");
	if (PAL(n)) {
		printf("%d - палиндром\n", n);
	} else {
		printf("%d - не палиндром\n", n);
	}
	printf("\n");

	printf("функция: \n");
	if (palindrome(n)) {
		printf("%d - палиндром\n", n);
	} 
	else {
		printf("%d - не палиндром\n", n);
	}

	return 0;
}
