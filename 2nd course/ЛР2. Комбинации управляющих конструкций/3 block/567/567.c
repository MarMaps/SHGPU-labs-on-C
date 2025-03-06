#include <stdio.h>

int main() {
    int x;
    printf("число n: ");
    scanf("%d", &x);


    int fact = 1;
    for (int i = 1; i <= x; i++) {
        fact *= i;
    }

    int res_a = 0;
    int res_b = 0;
    int res_c = 0;

    for (int i = 1; i * (i + 1) * (i + 2) <= fact; i++) {
        if (i * (i + 1) * (i + 2) == fact) {
            res_a = i;
            res_b = i + 1;
            res_c = i + 2;
            printf("%d!= %d = %d*%d*%d\n", x, fact, res_a, res_b, res_c);
            break;
        }
    }

    return 0;
}
