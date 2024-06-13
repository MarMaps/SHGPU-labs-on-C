#include <stdio.h>

int main(int argc, char **argv, char **env) 
{
	int n, i, k, res, p;

	printf("введите n: ");
	scanf("%d", &n);

	res = 0;
	for (i = 1; i <= n; i++) {
		p = 1;
		for (k = i; k <= i * 2; k++) {
			p = p * k;
		}
	res += p;
	}

	printf("сумма = %d\n", res);
	return 0;
}