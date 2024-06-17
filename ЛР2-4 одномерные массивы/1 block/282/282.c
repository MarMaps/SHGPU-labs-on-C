#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	int n;
	
	printf("введите n: ");
	scanf("%d", &n);

	double a[2 * n];
	double a_2[2 * n];

	printf("введите количество элементов массива %d(2n): ", 2 * n);
	
	for (int i = 0; i < 2 * n; i++) {
		scanf("%lf", &a[i]);
	}

	//б)
	for (int i = 0, j = 2 * n - 1; i < n; i++, j--) {
		a_2[2 * i] = a[i];
		a_2[2 * i + 1] = a[j];
		//printf("%lf\n", a[i]);
		//printf("%lf\n", a[j]);
	}

	printf("б)\n");
	for (int i = 0; i < 2 * n; i++) {
		printf("%lf\n", a_2[i]);
		
	}

	//в)
	printf("в)\n");
	for (int i = 0, j = 2 * n - 1; i < n; i++, j--) {
		a_2[2 * i] = a[i];
		a_2[2 * i + 1] = a[j];
		printf("%lf\n", a[i] + a[j]);
	}

	return 0;
}
