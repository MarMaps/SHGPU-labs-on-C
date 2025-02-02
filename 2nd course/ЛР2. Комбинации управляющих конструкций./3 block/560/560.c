#include <stdio.h>

int main() {
    int n, m;

    printf("введите диапазон (n m): ");
    scanf("%d %d", &n, &m);

    for (int x = n; x <= m; x++) {
        int sum_x = 0;

        for (int i = 1; i < x; i++) {
            if (x % i == 0) {
                sum_x += i;
            }
        }

        int y = sum_x;
 
        if (y > x && y <= m) {
            int sum_y = 0;//, j = 1;

            for (int j = 1; j < y; j++) {
                if (y % j == 0) {
                    sum_y += j;
                }
            }

            if ((sum_y == x) && (sum_x == y)) {
                printf("дружественная пара: %d и %d\n", x, y);
            }
        }
    }

    return 0;
}
