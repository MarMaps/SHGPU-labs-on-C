#include <stdio.h>

int main(int argc, char **argv, char **env) 
{
    int i, zn;
    double res_1, res_2, res;
    
    //a)
    for (i = 1; i <= 10000; i++) {
        if (i % 2 == 0) {
            res -= 1.0 / i;
        }
        else {
            res += 1.0 / i;
        } 
    }
    printf("a) %lf\n", res);
    
    //б)
    for (i = 1; i <= 9999; i += 2) {
        res_1 += 1.0 / i; 
    }

    for (i = 2; i <= 10000; i += 2) {
        res_2 += 1.0 / i;
    }

    res = res_1 - res_2;
    printf("б) %lf\n", res);

    //в
    res = 0.0;
    zn = 1;
    for (i = 1; i <= 10000; i++) {
        res += zn * (1.0 / i);
        zn *= -1;
    }
    printf("в) %lf\n", res);

    //г
    res_1 = 1.0 / 9999;
    for (i = 9997; i >= 1; i -= 2) {
        res_1 += 1.0 / i; 
    }

    res_2 = 1.0 / 10000;
    for (i = 9998; i >= 1; i -= 2) {
        res_2 += 1.0 / i;
    }

    res = res_1 - res_2;
    printf("г) %lf\n", res);
    return 0;
}