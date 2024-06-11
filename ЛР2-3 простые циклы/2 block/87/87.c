#include <stdio.h>

int main(int argc, char **argv, char **env) 
{   
    int n, m, i, sum, tmp;

    printf("введите чило n: ");
    scanf("%d", &n);
    printf("введите чило m: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        sum += n % 10;
        n /= 10;
    }
    printf("сумма = %d\n", sum);
    return 0;
}