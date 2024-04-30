#include <stdio.h>

int main(int argc, char **argv, char **env)
{
    float r, r1, r2, r3, m;
    printf("введите 3 сопротивления: ");
    scanf("%f%f%f", &r1, &r2, &r3);
    r = 1/(1/r1 + 1/r2 + 1/r3);
    m = r1 + r2 +r3;
    printf("сопротивление при параллельном соединении= %f\n", r);
    printf("сопротивление при последовательном соединении= %f\n", m);
    return 0;
}
