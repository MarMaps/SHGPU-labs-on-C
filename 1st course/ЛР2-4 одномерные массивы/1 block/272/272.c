#include <stdio.h>

int main(int argc, char **argv, char **env) 
{   
    //с 2001 по 2023
    float rainfall_Sochi[23] = {1994, 1899, 1465, 1704, 1756, 1887, 1817, 1566, 1712, 1553, 1781, 
                                1354, 1880, 1527, 1595, 1695, 1494, 1616, 1424, 1004, 2008, 1797, 1563};

    float average_quantity = 0.0;
    float deviation = 0.0;

    for (int i = 0; i < 23; i++) {
        average_quantity += rainfall_Sochi[i];
        //*потом убрать*/printf("%f\n", rainfall_Sochi[i]);
    }
    average_quantity /= 23;
    printf("среднее количество осадков: %f\n", average_quantity);

    printf("отклонение от среднего:\n");
    for (int i = 0; i < 23; i++) {
        deviation = rainfall_Sochi[i] - average_quantity;
        printf("%f\n", deviation);
    }
    return 0;
}