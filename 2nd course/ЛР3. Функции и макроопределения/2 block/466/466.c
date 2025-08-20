#include <stdio.h>
#include <stdlib.h>

void zamena(char *str, int pos) 
{
	for (int i = pos; str[i] != '\0'; i++) {
		if (str[i] == '0') {
			str[i] = '1';
		} else if (str[i] == '1') {
			str[i] = '0';
		}
	}
}

int main(int argc, char **argv, char **env)
{
	char *str = NULL;
	printf("строка символов: ");
	scanf("%ms", &str);
	
	int pos;
	printf("позиция: ");
	scanf("%d", &pos);

	zamena(str, pos);

	printf("%s\n", str);
	free(str);

	return 0;
}
