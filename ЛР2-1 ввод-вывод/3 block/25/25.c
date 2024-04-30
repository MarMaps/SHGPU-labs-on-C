#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float x1, y1, x2, y2, x3, y3, x, y, z, p, p1, s;
    printf("введите первую вершину x1, y1: ");
    scanf("%f%f", &x1, &y1);
    printf("введите вторую верщину x2, y2: ");
    scanf("%f%f", &x2, &y2);
    printf("введите третью вершину x3, y3: ");
    scanf("%f%f", &x3, &y3);
    x = sqrt(pow(x2 - x1,2) + pow(y2 - y1, 2));
    y = sqrt(pow(x3 - x2,2) + pow(y3 - y2, 2));
    z = sqrt(pow(x1 - x3,2) + pow(y1 - y3, 2));
    p = x + y + z;
    printf("периметр= %f\n", p);
    p1 = p / 2;
    s = sqrt(p1 * (p1-x) * (p1-y) * (p1-z));
    printf("площадь= %f\n", s);
    return 0;
}
