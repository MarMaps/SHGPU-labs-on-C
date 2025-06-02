#include <stdio.h>
#include <string.h>

void zamena(char *str, int start_pos)
{
	if (start_pos < 0 || start_pos > strlen(str)) {
		printf("выход за границу\n");
		return;
	}

	for (int i = start_pos; i < strlen(str); i++) {
		if (str[i] == '0') {
			str[i] = '1';
		}
		else if (str[i] == '1') {
			str[i] = '0';
		}
	}
	printf("итог: %s", str);
}

int main()
{
	char str[1000];
	int start_pos;

	printf("строка: ");
	fgets(str, sizeof(str), stdin);

	printf("позиция: ");
	scanf("%d", &start_pos);

	zamena(str, start_pos);
	
	return 0;
}
