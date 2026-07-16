#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void help() {
    printf("общий вид: cml [-h|-l|-m] исходный_файл результирующий_файл\n");
    printf("опции:\n");
    printf("-h - создать жесткую ссылку\n");
    printf("-l - создать символическую ссылку\n");
    printf("-m - переместить/переименовать файл\n");
    printf("если опций нет, файл будет скопирован\n");
}

int is_regular_file_or_link(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return 0;

    return S_ISREG(st.st_mode) || S_ISLNK(st.st_mode);
}

int file_exists(const char *path)
{
    struct stat st;
    return stat(path, &st) == 0;
}

int main(int argc, char **argv)
{
	int h_flag = 0, l_flag = 0, m_flag = 0;
    char *ish = NULL, *res = NULL;
    
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
        res = argv[3];
    } else { //нет опции
        ish = argv[1];
        res = argv[2];
    }
    //printf("опции: h=%d, l=%d, m=%d\n", h_flag, l_flag, m_flag);
    //printf("исходный: %s, результирующий: %s\n", ish, res);
    
    if (!file_exists(ish)) {
		printf("ошибка: исходный файл не существует\n");
        return 1;
	}
	
	if (!is_regular_file_or_link(ish)) {
		printf("ошибка: исходный файл существует, но не является регулярным файлом или ссылкой\n");
        return 1;
	}
	
	int res_exists = file_exists(res);
	//printf("%d", target_exists);
    if (res_exists && !is_regular_file_or_link(res))
    {
        printf("ошибка: результирующий файл существует, но не является обычным файлом или ссылкой\n");
        return 1;
    } else if (!res_exists) {
		printf("ошибка: результирующего файла не существует\n");
		return 1;
	}
	
	return 0;
}

