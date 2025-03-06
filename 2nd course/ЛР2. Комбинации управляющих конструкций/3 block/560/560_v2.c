#include <stdio.h>
#include <math.h>

int main() {
    int n, m;

    printf("диапазон (n m): ");
    scanf("%d %d", &n, &m);

    for (int x = n; x <= m; x++) {
        int sum_x = 1;
        int cor_x = sqrt(x);

        for (int i = 2; i <= cor_x; i++) {
            if (x % i == 0) {
                sum_x += i;
                
                if (i != x / i) {
					sum_x += x / i;
				//printf("x: %d | sum_x: %d\n", x, sum_x);
				}
            }
        
        }

        int y = sum_x;

        if (y > x && y <= m) { //чтобы не дублировать пары
            int sum_y = 1;
            int cor_y = sqrt(y);

            for (int j = 2; j <= cor_y; j++) {
                if (y % j == 0) {
                    sum_y += j;
                    
                    if (j != y / j) {
						sum_y += y / j;
						//printf("y: %d | sum_y: %d\n", y, sum_y);
					}
                }
            }

            if (sum_y == x) {
                printf("дружественная пара: %d и %d\n", x, y);
            }
        }
    }

    return 0;
}
