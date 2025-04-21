#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int x = n; x <= m; x++)
    {
        int sum_x = 1;
        for (int i = 2; i <= (int)sqrt(x); i++)
        {
            if (x % i == 0)
            {
                sum_x += i;
                if (i != x/i)
                    sum_x += x/i;
            }
        }

        if (sum_x > x && sum_x <= m) //чтоы не дублировать пары
        {
            int sum_y = 1;
            for (int i = 2; i <= (int)sqrt(sum_x); i++) {
                if (sum_x % i == 0)
                {
                    sum_y += i;
                    if (i != sum_x/i)
                        sum_y += sum_x/i;
                }
            }

            if (sum_y == x)
            {
                printf("дружественная пара: %d %d\n", x, sum_x);
            }
        }
    }

    return 0;
}
