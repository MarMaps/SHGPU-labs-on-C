#include <stdio.h>

int main(int argc, char **argv) 
{
    int m, n, sum, max_sum, max_num, num;

    printf("диапазон от m до n: ");
    scanf("%d %d", &m, &n);

    max_num = m;
    max_sum = 0;

    for (num = m; num <= n; num++) {
        sum = 0;

        if (num < 0) {
            for (int i = num; i <= -1; i++) {
                if (num % i == 0) {
					//printf("%d", i);
                    sum += i;
                }
            }
        }
        
        else {
            for (int i = 1; i <= num; i++) {
                if (num % i == 0) {
					//printf("%d", i);
                    sum += i;
                }
            }
        }

        printf("сумма делителей числа %d = %d\n", num, sum);

        if (sum > max_sum) {
            max_sum = sum;
            max_num = num;
        }
    }

    printf("число с макс суммой делителей: %d(сумма = %d)\n", max_num, max_sum);

    return 0;
}
//если цисло отрицательное то учитывать только отриц делители
