#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *str1 = NULL;
	char *str2 = NULL;
	
	scanf("%ms", &str1);
	scanf("%ms", &str2);

 int i, j, k; k = 0; for (i = 0; (str1)[i] != '\0'; i++) { j = 0; while ((str2+1-1)[j] != '\0' && (str1)[i] != (str2+1-1)[j]) { j++; } if ((str2+1-1)[j] == '\0') { (str1)[k] = (str1)[i]; k++; } } (str1)[k] = '\0';;
 int i, j, k; k = 0; for (i = 0; (str1)[i] != '\0'; i++) { j = 0; while ((str2+1-1)[j] != '\0' && (str1)[i] != (str2+1-1)[j]) { j++; } if ((str2+1-1)[j] == '\0') { (str1)[k] = (str1)[i]; k++; } } (str1)[k] = '\0';;
 printf("str1: %s\n", str1);


 free(str1);
 free(str2);
 return 0;
}

