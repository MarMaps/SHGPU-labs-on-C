#include <stdio.h>
#define REV(x,y) ((x)=(x) * 10 + (y) % 10 )

void polind(int x)
{
	int reverse = 0;
	if (x > 999 && x <= 9999) {
		int temp = x;
 
		while(temp != 0) {
			REV(reverse, temp);
			temp /= 10;
		}
 
   if (x == reverse)
      printf("%d явл палиндромом\n", x);
   else
      printf("%d не явл палиндромом\n", x);
	}
	
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	
	polind(n);
	return 0;
}

/*#include <stdio.h>
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
        printf("явл палиндромом\n", str);
    } else {
        printf("не явл палиндромом\n", str);
    }

    return 0;
}*/
