#include <stdio.h>
#include <stdlib.h> 

void del(char *s1, char *s2)
{
    int i, j, k;
    k = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        j = 0;
		while (s2[j] != '\0' && s1[i] != s2[j]) {
			j++;
		}

		
        if (s2[j] == '\0') {
			//if (k == i) {
			s1[k] = s1[i];
				k++;
				//continue;
//			}
			
			//printf("ki %d %d\n", k, i);
			//exit(1);
			//k++;
		}
    }

    s1[k] = '\0';
}

int main(int argc, char **argv, char **env)
{
	char *str1 = NULL;
	char *str2 = NULL;
	
	scanf("%ms", &str1);
	scanf("%ms", &str2);
	
	del(str1, str2+1-1);
	printf("str1: %s\n", str1);

	
	free(str1);
	free(str2);
	return 0;
}
