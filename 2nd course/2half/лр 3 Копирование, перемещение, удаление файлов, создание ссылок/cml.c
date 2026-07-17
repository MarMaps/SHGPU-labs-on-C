#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_S 4096

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

int copy_file(const char *nach, const char *res)
{
	FILE *nach_f = fopen(nach, "rb");
	if (nach_f == NULL) {
		printf("ошибка открытия исходного файла");
		return 0;
	}
	FILE *res_f = fopen(res, "wb");
	if (res_f == NULL) {
		printf("ошибка открытия результирующего файла");
		fclose(res_f);
		return 0;
	}
	
	char buf[BUFFER_S];
	size_t bytes_read;
	size_t bytes_write;
	while ((bytes_read = fread(buf, 1, BUFFER_S, nach_f)) > 0) {
		bytes_write = fwrite(buf, 1, bytes_read, res_f);
		if (bytes_write != bytes_read) {//?
			printf("ошибка записи");
			fclose(nach_f);
			fclose(res_f);
			return 0;
		}
	}
	fclose(nach_f);
	fclose(res_f);
	return 1;
}

int main(int argc, char **argv)
{
	/*int h_flag = 0, l_flag = 0, m_flag = 0;
    char *nach = NULL, *res = NULL;
    
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
        nach = argv[2];
        res = argv[3];
    } else { //нет опции
        nach = argv[1];
        res = argv[2];
    }
    //printf("опции: h=%d, l=%d, m=%d\n", h_flag, l_flag, m_flag);
    //printf("исходный: %s, результирующий: %s\n", nach, res);
    
    if (!file_exists(nach)) {
		printf("ошибка: исходный файл не существует\n");
        return 1;
	}
	
	if (!is_regular_file_or_link(nach)) {
		printf("ошибка: исходный файл существует, но не является регулярным файлом или ссылкой\n");
        return 1;
	}
	
	int res_exists = file_exists(res);
	//printf("%d", target_exists);
    if (res_exists && !is_regular_file_or_link(res))
    {
        printf("ошибка: результирующий файл существует, но не является обычным файлом или ссылкой\n");
        return 1;
    } 
	if (h_flag) {
        if (link(nach, res) != 0) {
            perror("ошибка создания жесткой ссылки");
            return 1;
        }
        printf("жесткая ссылка создана: '%s' -> '%s'\n", res, nach);
    }
    else if (l_flag)
    {
        if (symlink(nach, res) != 0)
        {
            perror("ошибка создания символической ссылки");
            return 1;
        }
        printf("символическая ссылка создана: '%s' -> '%s'\n", res, nach);
    }
    else if (m_flag)
    {
        if (rename(nach, res) != 0)
        {
            perror("ошибка перемещения файла");
            return 1;
        }
        printf("файл перемещен: '%s' -> '%s'\n", nach, res);
    }
    else
    {
        if (!copy_file(nach, res))
            return 1;
        printf("файл скопирован: '%s' -> '%s'\n", nach, res);
    }*/
    //тесты 3 дня
    if (copy_file("a.txt", "copy_of_a.txt"))
        printf("Копирование успешно\n");

    if (rename("copy_of_a.txt", "renamed.txt") == 0)
        printf("Переименование успешно\n");
    else
        printf("rename");

    if (link("a.txt", "hardlink.txt") == 0)
        printf("Жесткая ссылка создана\n");
    else
        printf("link");

    if (symlink("a.txt", "symlink.txt") == 0)
        printf("Символическая ссылка создана\n");
    else
        printf("symlink");
        
	return 0;
}

