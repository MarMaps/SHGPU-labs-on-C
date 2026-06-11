#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>

void reg_file(const char *path, mode_t mode) {
    FILE *f = fopen(path, "w");
    if (f == NULL) {
        perror("Ошибка создания файла");
        return;
    }
    fclose(f);
    chmod(path, mode & 07777);
}

void sim_link(const char *orig, const char *new) {
    char buf[PATH_MAX];
    int len = readlink(orig, buf, sizeof(buf) - 1);
    if (len < 0) {
        perror("Ошибка чтения ссылки");
        return;
    }
    buf[len] = '\0'; 
    symlink(buf, new);
}

void copy_dir(const char *orig_dir, const char *new_dir) {
    DIR *d = opendir(orig_dir);
    if (!d) return;

    struct dirent *entry;
    char orig_path[PATH_MAX];
    char new_path[PATH_MAX];
    struct stat st;

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(orig_path, sizeof(orig_path), "%s/%s", orig_dir, entry->d_name);
        snprintf(new_path, sizeof(new_path), "%s/%s", new_dir, entry->d_name);

        if (lstat(orig_path, &st) == -1) continue;

        if (S_ISDIR(st.st_mode)) {
            mkdir(new_path, st.st_mode & 07777);
            chmod(new_path, st.st_mode & 07777);
            copy_dir(orig_path, new_path);
        } 
        else if (S_ISLNK(st.st_mode)) {
            sim_link(orig_path, new_path);
        } 
        else {
            reg_file(new_path, st.st_mode);
        }
    }
    closedir(d);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        return 1;
    }

    struct stat st;
    if (lstat(argv[1], &st) == -1) {
        perror("каталог не найден");
        return 1;
    }

    mkdir(argv[2], st.st_mode & 07777);
    chmod(argv[2], st.st_mode & 07777);

    copy_dir(argv[1], argv[2]);

    printf("копия создана\n");
    return 0;
}
