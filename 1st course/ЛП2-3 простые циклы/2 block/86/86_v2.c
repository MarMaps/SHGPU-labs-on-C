#include <stdio.h>

int main(int argc, char **argv, char **env) {
    int n, sum, zn, last; 
    
    printf("Введите число: ");
    scanf("%d", &n);

    sum = 0;
    zn = 1;

    while (n != 0) {
        last = n % 10;  // Извлекаем последнюю цифру
        sum += zn * last; // Добавляем или вычитаем цифру из суммы
        zn = -zn;        // Меняем знак
        n /= 10;             // Убираем последнюю цифру из числа
    }

    printf("сумма цифр: %d\n", sum);

    return 0;
}