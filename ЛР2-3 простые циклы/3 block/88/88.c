#include <stdio.h>

int main(int argc, char **argv, char **env) 
{   
    int n, i, last, n_2;

    printf("введите чило n: ");
    scanf("%d", &n);

    n_2 = 0;
    while (n > 0) {
        last = n % 10;
        n /= 10;
        n_2 *= 10;
        n_2 += last;
    }

    printf("%d\n", n_2);
    return 0;
}