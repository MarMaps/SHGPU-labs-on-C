#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help() {
    printf("общий вид: cml [-h|-l|-m] исходный_файл результирующий_файл\n");
    printf("опции:\n");
    printf("-h - создать жесткую ссылку\n");
    printf("-l - создать символическую ссылку\n");
    printf("-m - переместить/переименовать файл\n");
    printf("если опций нет, файл будет скопирован\n");
}

int main(int argc, char **argv)
{
	int h_flag = 0, l_flag = 0, m_flag = 0;
    char *ish = NULL, *cel = NULL;
    
    //пров на колво аргументов
    if (argc < 3 || argc > 4) {
        printf("ошибка: неверное количество аргументов\n");
        help();
        return 1;
    }
    
    if (argc == 4) {//есть опция
        if (strcmp(argv[1], "-h") == 0) {
            h_flag = 1;
        } else if (strcmp(argv[1], "-l") == 0) {
            l_flag = 1;
        } else if (strcmp(argv[1], "-m") == 0) {
            m_flag = 1;
        } else {
            printf("ошибка: неизвестная опция '%s'\n", argv[1]);
            help();
            return 1;
        }
        ish = argv[2];
        cel = argv[3];
    } else { //нет опции
        ish = argv[1];
        cel = argv[2];
    }
    
    printf("опции: h=%d, l=%d, m=%d\n", h_flag, l_flag, m_flag);
    printf("исходный: %s, целевой: %s\n", ish, cel);
	return 0;
}

