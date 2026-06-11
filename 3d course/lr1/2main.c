#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h> 
#include <unistd.h>
#include <limits.h>

const char* get_file_type(mode_t mode) {
    if (S_ISDIR(mode))  return "каталог";
    if (S_ISFIFO(mode)) return "fifo-канал";
    if (S_ISLNK(mode))  return "символическая ссылка";
    if (S_ISCHR(mode))  return "символьное устройство";
    if (S_ISBLK(mode))  return "блочное устройство";
    if (S_ISSOCK(mode)) return "сокет";
    return "обычный файл";
}

void print_spec_prava(mode_t mode, int is_dir) {
    int flag = 0;
    printf("спецправа: ");
    
    if (mode & S_ISUID) {
        if (is_dir) printf("игнорируется для каталогов");
        else printf("SUID (запуск от имени хозяина)");
        flag = 1;
    }
    
    if (mode & S_ISGID) {
        if (flag) printf(", ");
        if (is_dir) printf("новые файлы наследуют группу каталога");
        else printf("SGID (запуск от имени группы)");
        flag = 1;
    }
    
    if (mode & S_ISVTX) {
        if (flag) printf(", ");
        if (is_dir) printf("удалять файлы могут только владельцы");
        else printf("Sticky (пожелание сохранения в ОЗУ после завершения)");
        flag = 1;
    }
    
    if (!flag) {
        printf("нет");
    }
    
    printf("\n");
}

void otstup(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

void print_file_info(const char *fullpath, const char *filename, struct stat *st, int depth) {
    int is_dir = S_ISDIR(st->st_mode);
    
    otstup(depth);
    printf("файл: %s\n", fullpath);
    
    otstup(depth);
    printf("тип: %s\n", get_file_type(st->st_mode));
    
    struct passwd *pw = getpwuid(st->st_uid);
    otstup(depth);
    if (pw != NULL) {
        printf("хозяин: %s (%d)\n", pw->pw_name, st->st_uid);
    } else {
        printf("хозяин: неизвестно (%d)\n", st->st_uid);
    }
    
    struct group *gr = getgrgid(st->st_gid);
    otstup(depth);
    if (gr != NULL) {
        printf("группа: %s (%d)\n", gr->gr_name, st->st_gid);
    } else {
        printf("группа: неизвестно (%d)\n", st->st_gid);
    }
    
    // права хозяина
    otstup(depth);
    printf("права хозяина: ");
    if (st->st_mode & S_IRUSR) {
        if (is_dir) printf("просмотр содержимого каталога ");
        else printf("чтение ");
    }
    if (st->st_mode & S_IWUSR) {
        if (is_dir) printf("создание, удаление и переименование файлов ");
        else printf("запись ");
    }
    if (st->st_mode & S_IXUSR) {
        if (is_dir) printf("вход в каталог ");
        else printf("выполнение ");
    }
    if (!(st->st_mode & (S_IRUSR | S_IWUSR | S_IXUSR))) {
        if (is_dir) printf("доступ к каталогу запрещён");
        else printf("нет прав");
    }
    printf("\n");
    
    // права группы
    otstup(depth);
    printf("права группы: ");
    if (st->st_mode & S_IRGRP) {
        if (is_dir) printf("просмотр содержимого каталога ");
        else        printf("чтение ");
    }
    if (st->st_mode & S_IWGRP) {
        if (is_dir) printf("создание, удаление и переименование файлов ");
        else        printf("запись ");
    }
    if (st->st_mode & S_IXGRP) {
        if (is_dir) printf("вход в каталог ");
        else        printf("выполнение ");
    }
    if (!(st->st_mode & (S_IRGRP | S_IWGRP | S_IXGRP))) {
        if (is_dir) printf("доступ к каталогу запрещён");
        else        printf("нет прав");
    }
    printf("\n");
    
    // права остальных
    otstup(depth);
    printf("права остальных: ");
    if (st->st_mode & S_IROTH) {
        if (is_dir) printf("просмотр содержимого каталога ");
        else        printf("чтение ");
    }
    if (st->st_mode & S_IWOTH) {
        if (is_dir) printf("создание, удаление и переименование файлов ");
        else        printf("запись ");
    }
    if (st->st_mode & S_IXOTH) {
        if (is_dir) printf("вход в каталог ");
        else        printf("выполнение ");
    }
    if (!(st->st_mode & (S_IROTH | S_IWOTH | S_IXOTH))) {
        if (is_dir) printf("доступ к каталогу запрещён");
        else        printf("нет прав");
    }
    printf("\n");
    
    // спецправа
    otstup(depth);
    print_spec_prava(st->st_mode, is_dir);   
    printf("\n");
}

void recurs_dir(const char *path, int depth) {
    DIR *d = opendir(path);
    
    if (d == NULL) {
        otstup(depth);
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
    char fullpath[PATH_MAX];
    /*struct stat buf;
    lstat(".", &buf);
    printf("%d", buf.f_namelen);
    __fsword_t fullpath = buf.f_namelen;*/
    
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        
        struct stat st;
        if (lstat(fullpath, &st) == -1) {
		//if (stat(fullpath, &st) == -1) { 
            otstup(depth);
            printf("не удалось получить информацию о %s: %s\n", 
                   fullpath, strerror(errno));
            continue;
        }
        
        print_file_info(fullpath, entry->d_name, &st, depth);
        
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
