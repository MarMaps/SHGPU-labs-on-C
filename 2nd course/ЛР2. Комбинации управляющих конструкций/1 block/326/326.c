#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    int sum1, sum2;

    for (x1 = 1; ; x1++) { 
        for (y1 = 1; y1 <= x1; y1++) {
            sum1 = pow(x1, 3) + pow(y1, 3);
            //printf("x1: %d | y1: %d\n", x1, y1);

            for (x2 = 1; x2 <= x1; x2++) {
                for (y2 = 1; y2 <= x2; y2++) {
                    sum2 = pow(x2, 3) + pow(y2, 3);
                    //printf("x2: %d | y2: %d\n", x2, y2);

                    if (sum1 == sum2 && (x1 != x2 || y1 != y2)) {
                        printf("наименьшее число: %d\n", sum1);
                        printf("его пары:\n");
                        printf("%d^3 + %d^3\n", x1, y1);
                        printf("%d^3 + %d^3\n", x2, y2);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
