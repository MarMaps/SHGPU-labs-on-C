#include <stdio.h>

int main(int argc, char **argv, char **env) {
    int m, n, sum, max_sum, max_num, num;
    
    printf("введите диапазон от m до n: ");
    scanf("%d %d", &m, &n);

    max_num = m;
    num = m;
    
    while(num <= n) {
        sum = 0;

        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }

        printf("сумма делителей числа %d = %d\n", num, sum);

        
        if (sum > max_sum) {
            max_sum = sum;
            max_num = num;
        }
        num++;
    }

    printf("число с максимальной суммой делителей: %d (сумма = %d)\n", max_num, max_sum);
    
    return 0;
}
