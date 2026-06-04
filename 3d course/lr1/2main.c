#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h> 
#include <unistd.h>
#include <stdbool.h>  

const char* get_file_type(mode_t mode) {
    if (S_ISDIR(mode))  return "каталог";
    if (S_ISFIFO(mode)) return "fifo-канал";
    if (S_ISLNK(mode))  return "символическая ссылка";
    if (S_ISCHR(mode))  return "символьное устройство";
    if (S_ISBLK(mode))  return "блочное устройство";
    if (S_ISSOCK(mode)) return "сокет";
    return "обычный файл";
}

void print_spec_prava(mode_t mode) {
    bool flag = false;
    printf("спецправа: ");
    
    if (mode & S_ISUID) {
        printf("SUID(запуск от имени хозяина)");
        flag = true;
    }
    
    if (mode & S_ISGID) {
        if (flag) printf(", ");
        printf("SGID (запуск от имени группы)");
        flag = true;
    }
    
    if (mode & S_ISVTX) {
        if (flag) printf(", ");
        printf("sticky(пожелание сохранения в ОЗУ после завершения)");
        flag = true;
    }
    
    if (!flag) {
        printf("нет");
    }
    
    printf("\n");
}

void otctup(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

void print_file_info(const char *fullpath, const char *filename, struct stat *st, int depth) {
    otctup(depth);
    printf("файл: %s\n", fullpath);
    
    otctup(depth);
    printf("тип: %s\n", get_file_type(st->st_mode));
    
    struct passwd *pw = getpwuid(st->st_uid);
    otctup(depth);
    if (pw != NULL) {
        printf("хозяин: %s (%d)\n", pw->pw_name, st->st_uid);
    } else {
        printf("хозяин: неизвестно (%d)\n", st->st_uid);
    }
    
    struct group *gr = getgrgid(st->st_gid);
    otctup(depth);
    if (gr != NULL) {
        printf("группа: %s (%d)\n", gr->gr_name, st->st_gid);
    } else {
        printf("группа: неизвестно (%d)\n", st->st_gid); }
    
    otctup(depth);
    printf("права хозяина: ");
    if (st->st_mode & S_IRUSR) printf("чтение ");
    if (st->st_mode & S_IWUSR) printf("запись ");
    if (st->st_mode & S_IXUSR) printf("выполнение ");
    if (!(st->st_mode & (S_IRUSR | S_IWUSR | S_IXUSR))) printf("нет прав");
    printf("\n");
    
    otctup(depth);
    printf("права группы: ");
    if (st->st_mode & S_IRGRP) printf("чтение ");
    if (st->st_mode & S_IWGRP) printf("запись ");
    if (st->st_mode & S_IXGRP) printf("выполнение ");
    if (!(st->st_mode & (S_IRGRP | S_IWGRP | S_IXGRP))) printf("нет прав");
    printf("\n");
    
    otctup(depth);
    printf("права остальных: ");
    if (st->st_mode & S_IROTH) printf("чтение ");
    if (st->st_mode & S_IWOTH) printf("запись ");
    if (st->st_mode & S_IXOTH) printf("выполнение ");
    if (!(st->st_mode & (S_IROTH | S_IWOTH | S_IXOTH))) printf("нет прав");
    printf("\n");
    
    //спецправа
    otctup(depth);
    print_spec_prava(st->st_mode);   
    printf("\n");
}

void recurs_dir(const char *path, int depth) {
    DIR *d = opendir(path);
    
    if (d == NULL) {
        otctup(depth);
        printf("недоступен %s: ", path);
        if (errno == EACCES) {
            printf("нет прав на чтение каталога\n");
        } else if (errno == ENOENT) {
            printf("каталог не существует\n");
        } else if (errno == ENOTDIR) {
            printf("это не каталог\n");
        } else {
            printf("%s\n", strerror(errno));
        }
        return;
    }
    
    struct dirent *entry;
    char fullpath[1024];
    
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        //полный путь
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        
        struct stat st;
        if (lstat(fullpath, &st) == -1) {
            otctup(depth);
            printf("не удалось получить информацию о %s: %s\n", 
                   fullpath, strerror(errno));
            continue;
        }
        
        print_file_info(fullpath, entry->d_name, &st, depth);
        
        //если каталог-торекурсия
        if (S_ISDIR(st.st_mode)) {
            recurs_dir(fullpath, depth + 1);
        }
    }
    
    closedir(d);
}

int main(int argc, char *argv[]) {
    const char *start_path;

    if (argc > 1) {
        start_path = argv[1];
    } else {
        start_path = ".";
    }
    
    printf("содержимое каталога: %s\n\n", start_path);
    recurs_dir(start_path, 0);
    
    return 0;
}

