#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	signed char x1, y1;
	unsigned char x2, y2;
	
	int i1_1 = 0, i1_2 = 0,
		i2_1 = 0, i2_2 = 0;
	
	printf("введите x y типа signed char: ");
	scanf("%hhi %hhi", &x1, &y1);
	
	printf("введите x y типа unsigned char: ");
	scanf("%hhu %hhu", &x2, &y2);
	
	printf("изначально signed: x = %d y = %d\n", x1, y1);
    printf("изначально unsigned: x = %d y = %d\n", x2, y2);
    printf("\n");
    
    printf("x=x+y - signed: \n");
    signed char sx1 = x1;
    signed char sy1 = y1;

    while (sx1 <= SCHAR_MAX) { //127
    	signed char temp_sx1 = sx1;//temp_sx1 для хранения предыдущего знач
		sx1 = sx1 + sy1;
		i1_1++;

		printf("x(%d) = x(%d) + y(%d)\n", sx1, temp_sx1, sy1);
		printf("кол-во операций: %d\n", i1_1);
		//для проверки
		if ((sy1 > 0 && sx1 < temp_sx1) || (sy1 < 0 && sx1 > temp_sx1)) {
            printf("произошел переход через границу\n");
            printf("кол-во операций: %d %hhd \n", i1_1, sx1);
            
            break;
        }
	}
    printf("\n");

    printf("x=x+y - unsigned: \n");
    unsigned char ux1 = x2;
    unsigned char uy1 = y2;

    while (ux1 <= UCHAR_MAX) { //255
    	unsigned char temp_ux1 = ux1;
    	ux1 = ux1 + uy1;
    	i1_2++;

    	//printf("x(%d) = x(%d) + y(%d)\n", ux1, temp_ux1, uy1);
		//printf("кол-во операций: %d\n", i1_2);
		//для проверки
		if ((uy1 > 0 && ux1 < temp_ux1) || (uy1 < 0 && ux1 > temp_ux1)) {
			printf("кол-во операций: %d\n", i1_2);
            printf("произошел переход через границу\n");
            break;
        }
    }
    printf("\n");

    printf("x=x-y - signed: \n");
    signed char sx2 = x1;
    signed char sy2 = y1;

    while (sx2 >= SCHAR_MIN) { //-128
    	signed char temp_sx2 = sx2;
    	sx2 = sx2 - sy2;
    	i2_1++;

    	//printf("x(%d) = x(%d) - y(%d)\n", sx2, temp_sx2, sy2);
		//printf("кол-во операций: %d\n", i2_1);
		//для проверки
		if ((sy2 > 0 && sx2 > temp_sx2) || (sy2 < 0 && sx2 < temp_sx2)) {
			printf("кол-во операций: %d\n", i2_1);
            printf("произошел переход через границу\n");
            break;
        }
    }
    printf("\n");
    
    printf("x=x-y - unsigned: \n");
    unsigned char ux2 = x2;
    unsigned char uy2 = y2;
    
    while (ux2 >= 0) {
		unsigned char temp_ux2 = ux2;
		ux2 = ux2 - uy2;
		i2_2++;
		
		//printf("x(%d) = x(%d) - y(%d)\n", ux2, temp_ux2, uy2);
		//printf("кол-во операций: %d\n", i2_2);
		//для проверки
		if ((uy2 > 0 && ux2 > temp_ux2) || (uy2 < 0 && ux2 < temp_ux2)) {
			printf("кол-во операций: %d\n", i2_2);
            printf("произошел переход через границу\n");
            break;
		}
	}
	
	return 0;
}

