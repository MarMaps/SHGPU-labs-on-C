#include <stdio.h>
#include <dirent.h>
#include <string.h>

void list_dir(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) {
        printf("не получилось открыть каталог %s\n", path);
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) 
            continue;
            
        printf("%s\n", entry->d_name);
    }
    
    closedir(d);
}

int main(int argc, char *argv[]) {
	 list_dir(".");
	return 0;
}
