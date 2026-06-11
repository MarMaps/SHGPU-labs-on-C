#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

void dir_info(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) {
        printf("не удалось открыть папку %s\n", path);
        return;
    }

    struct dirent *entry;
    char fullpath[PATH_MAX];
    struct stat st;

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &st) == -1) {
            printf("Не удалось получить информацию о %s\n", entry->d_name); 
            continue;
        }

        printf("Имя: %s -> ", entry->d_name);
        
        if (S_ISDIR(st.st_mode)) {
            printf("тип: папка\n");
        }
        else if (S_ISLNK(st.st_mode)) {
            printf("тип: симв ссылка\n");
        }
        else {
            printf("тип: файл \n");
        }
    }
    
    closedir(d);
}

int main(int argc, char **argv) {
    const char *start_path;

    if (argc > 1) {
        start_path = argv[1];
    } else {
        start_path = ".";
    }
    
    printf("Содержимое каталога: %s\n\n", start_path);
    dir_info(start_path);
    return 0;
}
