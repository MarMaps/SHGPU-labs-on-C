#include <stdio.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    float a, b, c, s, p, ha, hb, hc, ma, mb, mc, la, lb, lc;
    scanf("%f%f%f", &a, &b, &c);
    p = (a + b + c)/2;
    s = sqrt(p * (p-a) * (p-b) * (p-c));
    ha = 2 * s / a;
    hb = 2 * s / b;
    hc = 2 * s / c;
    printf("высоты:\n%f\n%f\n%f\n",ha, hb, hc);
    ma = sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2))/2;
    mb = sqrt(2 * pow(a, 2) + 2 * pow(c, 2) - pow(b, 2))/2;
    mc = sqrt(2 * pow(a, 2) + 2 * pow(b, 2) - pow(c, 2))/2;
    printf("медианы:\n%f\n%f\n%f\n",ma, mb, mc);
    la = (1/(b + c)) * sqrt((b*c) * (b+c+a) * (b+c-a));
    lb = (1/(a + c)) * sqrt((a*c) * (a+c+b) * (a+c-b));
    lc = (1/(a + b)) * sqrt((a*b) * (a+b+c) * (a+b-c));
    printf("биссектрисы:\n%f\n%f\n%f\n",la, lb, lc);
    return 0;
}
