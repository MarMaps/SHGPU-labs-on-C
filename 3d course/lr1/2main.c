//сделать формат вывода "файл", сделать рекурсию, сделать "Если содержимое очередного подкаталога оказывается недоступным - 
//сообщить об этом факте для каждого каталога и причинах его возникновения."
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

//функция для спец прав
void print_special_permissions(mode_t mode) {
    int has_special = 0;
    printf("спецправа: ");
    
    if (mode & S_ISUID) {
        printf("SUID (запуск от имени хозяина)");
        has_special = 1;
    }
    
    if (mode & S_ISGID) {
        if (has_special) printf(", ");
        printf("SGID (запуск от имени группы)");
        has_special = 1;
    }
    
    if (mode & S_ISVTX) {
        if (has_special) printf(", ");
        printf("Sticky (пожелание сохранения в ОЗУ после завершения)");
        has_special = 1;
    }
    
    if (!has_special) {
        printf("нет");
    }
    
    printf("\n");
}

void list_dir(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) {
        printf("не получилось открыть каталог %s\n", path);
        return;
    }
    
    struct dirent *entry;
    char fullpath[1024];  //для полного пути к файлу
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) 
            continue;
        
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);           
        
        struct stat st;
        if (stat(fullpath, &st) == -1) {
            printf("ошибка получения информации о файле %s\n", entry->d_name);
            continue;
        }
        printf("\nфайл: %s\n", entry->d_name);
        
        //тип
        const char* get_type(mode_t mode){
			if (S_ISDIR(mode))  return "каталог";
			if (S_ISFIFO(mode)) return "fifo-канал";
			if (S_ISLNK(mode))  return "ссылка";
			if (S_ISCHR(mode))  return "символьное устройство";
			if (S_ISBLK(mode))  return "блочное устройство";
			if (S_ISSOCK(mode)) return "сокет";
			return "обычный файл";
		}
        printf("тип: %s\n", get_type(st.st_mode));
        
        //хозяин
		struct passwd *pw = getpwuid(st.st_uid);
		printf("хозяин: %s (%d)\n", pw->pw_name, st.st_uid);
		
		//группа
		struct group *gr = getgrgid(st.st_gid);
		printf("группа: %s (%d)\n", gr->gr_name, st.st_gid);
		
		//права хозяина
        printf("права хозяина: ");
        if (st.st_mode & S_IRUSR) printf("чтение ");
        if (st.st_mode & S_IWUSR) printf("запись ");
        if (st.st_mode & S_IXUSR) printf("выполнение ");
        if (!(st.st_mode & (S_IRUSR | S_IWUSR | S_IXUSR))) printf("нет прав");
        printf("\n");
        
        //права группы
        printf("права группы: ");
        if (st.st_mode & S_IRGRP) printf("чтение ");
        if (st.st_mode & S_IWGRP) printf("запись ");
        if (st.st_mode & S_IXGRP) printf("выполнение ");
        if (!(st.st_mode & (S_IRGRP | S_IWGRP | S_IXGRP))) printf("нет прав");
        printf("\n");
        
        //права остальных
        printf("права остальных: ");
        if (st.st_mode & S_IROTH) printf("чтение ");
        if (st.st_mode & S_IWOTH) printf("запись ");
        if (st.st_mode & S_IXOTH) printf("выполнение ");
        if (!(st.st_mode & (S_IROTH | S_IWOTH | S_IXOTH))) printf("нет прав");
        printf("\n");
        
        print_special_permissions(st.st_mode);
    }
    
    closedir(d);
}



int main(int argc, char *argv[]) {
	 list_dir(".");
	return 0;
}

