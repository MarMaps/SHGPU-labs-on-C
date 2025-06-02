#include <stdio.h>
#define MAX_DIGITS 4

#define PAL(s) (s[0] == s[3] && s[1] == s[2])

void intTOstring(int n, char *s) {
    sprintf(s, "%04d", n);
}

int main() {
    int n;
    char str[5];

    printf("введите число: ");
    scanf("%d", &n);

    intTOstring(n, str);

    if (PAL(str)) {
        printf("%s явл палиндромом\n", str);
    } else {
        printf("%s не явл палиндромом\n", str);
    }

    return 0;
}
