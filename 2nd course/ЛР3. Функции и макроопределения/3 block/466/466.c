#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define ZAMENA(str,pos) \
	for (int i = (pos); (str)[i] != '\0'; i++) { \
		if ((str)[i] == '0') { \
			(str)[i] = '1'; \
		} else if ((str)[i] == '1') { \
			(str)[i] = '0'; \
		} \
	} \

int main(int argc, char **argv, char **env)
{
	char *str = NULL;
	printf("строка символов: ");
	scanf("%ms", &str);
	
	int k = strlen(str);
	printf("%d\n", k);
	
	int pos;
	printf("позиция: ");
	scanf("%d", &pos);

	ZAMENA(str-1+1, pos+1-1);

	printf("%s\n", str);
	
	free(str);

	return 0;
}
