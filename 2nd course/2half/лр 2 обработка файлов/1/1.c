#include <stdio.h>

int main(int argc, char **argv) {
    int flag_lines = 0;
    int flag_words = 0;
    int flag_bytes = 0;
    int flag = 0;
    char *filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                char opt = argv[i][j];
                if (opt == 'l') {
					flag_lines = 1;
					flag = 1;
				}
                else if (opt == 'w') {
					flag_words = 1;
					flag = 1;
				}
                else if (opt == 'c') {
					flag_bytes = 1;
					flag = 1;
				}
                else {
                    printf("неизвестная опция: -%c\n", opt);
                    return 1;
                }
            }
        } else {
            filename = argv[i];
        }
    }

    if (!flag) {
        flag_lines = flag_words = flag_bytes = 1; 
    }

    if (filename == NULL) {
        return 1;
    }

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("не удалось открыть файл: %s\n", filename);
        return 1;
    }

    long bytes = 0;
    long lines = 0;
    long words = 0;
    int in_word = 0;
    int ch;

    while ((ch = fgetc(f)) != EOF) {
        bytes++;

        if (ch == '\n') {
            lines++;
        }

        if (ch < 33) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        words++;
    }

    if (flag_lines) printf("%ld ", lines);
    if (flag_words) printf("%ld ", words);
    if (flag_bytes) printf("%ld ", bytes);
    printf("%s\n", filename);

    fclose(f);
    return 0;
}
