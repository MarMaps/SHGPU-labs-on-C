#include<stdio.h>

int main()
{
    int n, sum;
    
    printf("введите число:");
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        sum = 0;
        
        for (int i2 = 1; i2 < i; i2++) {
            if (i % i2 == 0) {
                sum += i2;
            }
        }
    
        if (sum == i) {
            printf("число %d совершенное\n", i);
        }
    }
    return 0;
}
