include <stdio.h>

int main(int argc, char **argv, char **env)
{
	float a, b, c;
	printf("введите 3 числа: ");
	scanf("%f%f%f", &a, &b, &c);
	
	
	if (1 <= a && a <= 3){
		printf("число %f принадлежит интервалу\n", a);
	}
	else if (a < 1) {
            printf("число %f меньше 1\n", a);
        } else {
            printf("число %f больше 3\n", a);
        }
	
	if (1 <= b && b <= 3){
		printf("число %f принадлежит интервалу\n", b);
	}
	else if (b < 1) {
            printf("число %f меньше 1\n", b);
        } else {
            printf("число %f больше 3\n", b);
        }
	
	if (1 <= c && c <= 3){
		printf("число %f принадлежит интервалу\n", c);
	}
	else if (c < 1) {
            printf("число %f меньше 1\n", c);
        } else {
            printf("число %f больше 3\n", c);
        }
        
    if (!(1 <= a && a <= 3) && !(1 <= b && b <= 3) && !(1 <= c && c <= 3)) {
        printf("ни одно из чисел не принадлежит интервалу\n");
    }
    return 0;
	}
