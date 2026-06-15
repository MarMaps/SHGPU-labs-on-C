#include <stdio.h>
#include <limits.h>

int main()
{
    signed char x1;
    unsigned char x2;

    int i_x1_incr = 0, i_x1_decr = 0,
        i_x2_incr = 0, i_x2_decr = 0;
    
    printf("введите символ x signed: ");
    scanf("%c", &x1);

    printf("введите символ x unsigned: ");
    scanf(" %c", &x2);
    
    printf("изначально x signed = %d\n", x1);
    printf("изначально x unsigned = %d\n", x2);

    //инкремент
	printf("тип signed char-инкремент:\n");
    signed char x1_incr = x1;
    while (x1_incr != SCHAR_MAX) { //127
        x1_incr++;
        i_x1_incr++;
        printf("x = %d|", x1_incr);
        printf("кол-во операций: %d\n", i_x1_incr);
    }
    x1_incr++;
    i_x1_incr++;
    printf("для перехода через границу: x = %d | кол-во операций: %d\n",x1_incr, i_x1_incr);
    printf("\n");

    printf("тип unsigned char-инкремент:\n");
    unsigned char x2_incr = x2;
    while (x2_incr != UCHAR_MAX) { //255
        x2_incr++;
        i_x2_incr++;
        printf("x = %d|", x2_incr);
        printf("кол-во операций: %d\n", i_x2_incr);
    }
    x2_incr++;
    i_x2_incr++;
    printf("для перехода через границу: x = %d | кол-во операций: %d\n",x2_incr, i_x2_incr);
    printf("\n");

    //декремент
    printf("тип signed char-декремент:\n");
    signed char x1_decr = x1;
    while (x1_decr != SCHAR_MIN) { //-128
        x1_decr--;
        i_x1_decr++;
        printf("x = %d|", x1_decr);
        printf("кол-во операций: %d\n", i_x1_decr);
    }
    x1_decr--;
    i_x1_decr++;
    printf("для перехода через границу: x = %d | кол-во операций: %d\n",x1_decr, i_x1_decr);
    printf("\n");

    printf("тип unsigned char-декремент:\n");
    unsigned char x2_decr = x2;
    while (x2_decr != 0) { //или CHAR_MIN
        x2_decr--;
        i_x2_decr++;
        printf("x = %d|", x2_decr);
        printf("кол-во операций: %d\n", i_x2_decr);
    }
    x2_decr--;
    i_x2_decr++;
    printf("для перехода через границу: x = %d | кол-во операций: %d\n",x2_decr, i_x2_decr);
    printf("\n");
    
    printf("x schar после инкрементов = %d\n", x1_incr);
    printf("x schar после декрементов = %d\n", x1_decr);
    printf("x uchar после инкрементов = %d\n", x2_incr);
    printf("x uchar после декрементов = %d\n", x2_decr);

    return 0;
}
