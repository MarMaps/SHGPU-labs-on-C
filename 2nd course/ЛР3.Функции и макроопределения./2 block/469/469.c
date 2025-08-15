#include <stdio.h>
#include <string.h>

void vir(char *s, int n)
{
    if (n <= (int)strlen(s)) return;

    char buff_s[100];
    strncpy(buff_s, s, sizeof(buff_s));
    buff_s[sizeof(buff_s)-1] = '\0';

    char *words[100];
    int spaces[100] = {0};
    int word_count = 0;
    int pos = 0;

    while (buff_s[pos] != '\0') {
        words[word_count] = &buff_s[pos];

        while (buff_s[pos] != '\0' && buff_s[pos] != ' ') {
			pos++;
		}

        if (buff_s[pos] == '\0') {
            spaces[word_count] = 0;
            word_count++;
            break;
        }

        buff_s[pos++] = '\0';

        int cnt = 1;
        while (buff_s[pos] == ' ') { 
			cnt++; 
			pos++; 
		}
        spaces[word_count] = cnt;
        word_count++;
    }

    if (word_count == 1) {
        s[0] = '\0';
        int pad = n - (int)strlen(words[0]);
        if (pad < 0) {
			pad = 0;
		}
        for (int i = 0; i < pad; i++) {
			strcat(s, " ");
		}
        strcat(s, words[0]);
        return;
    }

    int letters = 0;
    for (int k = 0; k < word_count; ++k) {
		letters += (int)strlen(words[k]);
	}
    int gaps = word_count - 1;

    int current_len = letters;
    for (int k = 0; k < gaps; ++k) {
		current_len += spaces[k];
	}

    int extra = n - current_len;

    while (extra > 0) {
        int min_spaces = spaces[0];
        for (int k = 1; k < gaps; ++k) {
            if (spaces[k] < min_spaces) {
				min_spaces = spaces[k];
			}
        }

        for (int k = 0; k < gaps && extra > 0; ++k) {
            if (spaces[k] == min_spaces) {
                spaces[k]++;
                extra--;
            }
        }
    }

    s[0] = '\0';
    for (int k = 0; k < word_count; ++k) {
        strcat(s, words[k]);
        if (k < gaps) {
            for (int j = 0; j < spaces[k]; ++j) strcat(s, " ");
        }
    }
}

int main(int argc, char **argv)
{
    char s[100] = "";
    printf("s = ");
    fgets(s, sizeof(s), stdin);
    char *p = strchr(s, '\n');
    if (p) *p = '\0';

    int n;
    printf("новая длина: ");
    scanf("%d", &n);

    vir(s, n);

    printf("s = %s\n", s);
    printf("len = %zu\n", strlen(s));
    return 0;
}
