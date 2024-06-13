#include <stdio.h>

int main()
{ 
    int i, n, tmp, a, res, count, zn;

    printf("введите n: ");
    scanf("%d", &n); 

    tmp = n;
    count = 0;

    while (tmp != 0) {   
        count = count + 1;
        tmp = tmp / 10;
    }

    if (count % 2 == 0) {
        zn = -1;
    }
    else {
        zn = 1; 
    }

    res = 0;
    while (n != 0) {
        a = n % 10;
        res += a * zn;
        zn = zn * (-1);
        n = n / 10;
    }

    printf("сумма цифр = %d\n", res);

    return 0;
}