/*
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int ngroups;
    gid_t *groups;
    struct passwd *pw;
    struct group *gr;
    const char *name = "marina";

    pw = getpwnam(name);
    if (pw == NULL) {
        printf("Пользователь '%s' не найден!\n", name);
        return 1;
    }

    ngroups = 0;
    getgrouplist(name, pw->pw_gid, NULL, &ngroups);

    groups = malloc(sizeof(*groups) * ngroups);
    getgrouplist(name, pw->pw_gid, groups, &ngroups);

    char **print_users = malloc(1000 * sizeof(char*));
    int print_count = 0;

    for (int i = 0; i < ngroups; i++) {
        gr = getgrgid(groups[i]);
        if (gr != NULL) {
            printf("\n[DEBUG] Проверяем группу: %s (gid: %d)\n", gr->gr_name, groups[i]);
            
            for (int j = 0; gr->gr_mem[j] != NULL; j++) {
                const char *member_name = gr->gr_mem[j];
                printf("[DEBUG]   Найдено сырое имя в памяти: '%s'\n", member_name);

                if (strcmp(member_name, name) == 0) {
                    printf("[DEBUG]   Пропускаем самого себя.\n");
                    continue;
                }

                int flag = 0;
                for (int p = 0; p < print_count; p++) {
                    if (strcmp(print_users[p], member_name) == 0) {
                        flag = 1;
                        break;
                    }
                }
                
                if (!flag) {
                    printf("[DEBUG]   Имя уникально, добавляем в список: '%s'\n", member_name);
                    print_users[print_count] = strdup(member_name);
                    print_count++;
                    
                    printf("одногруппник %s (группы:", member_name);
                    for (int k = 0; k < ngroups; k++) {
                        // ВОТ ЗДЕСЬ ПРОИСХОДИТ ПОДМЕНА! getgrgid затирает данные gr
                        struct group *g2 = getgrgid(groups[k]);
                        if (g2 != NULL) {
                            for (int m = 0; g2->gr_mem[m] != NULL; m++) {
                                if (strcmp(g2->gr_mem[m], member_name) == 0) {
                                    printf(" %s", g2->gr_name);
                                    break;
                                }
                            }
                        }
                    }
                    printf(")\n");
                } else {
                    printf("[DEBUG]   Имя '%s' уже есть в списке, пропускаем.\n", member_name);
                }
            }
        }
    }

    for (int i = 0; i < print_count; i++) {
        free(print_users[i]);
    }
    free(print_users);
    free(groups);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int ngroups;
    gid_t *groups;
    struct passwd *pw;
    struct group *gr;
    const char *name = "marmaps";

    pw = getpwnam(name);
    if (pw == NULL) {
        printf("Ошибка: Пользователь '%s' не найден в системе.\n", name);
        return 1;
    }

    ngroups = 0;
    getgrouplist(name, pw->pw_gid, NULL, &ngroups);
    groups = malloc(sizeof(*groups) * ngroups);
    getgrouplist(name, pw->pw_gid, groups, &ngroups);

    char **print_users = malloc(1000 * sizeof(char*));
    int print_count = 0;

    for (int i = 0; i < ngroups; i++) {
        gr = getgrgid(groups[i]);
        if (gr != NULL) {
            for (int j = 0; gr->gr_mem[j] != NULL; j++) {
                char *member_name = strdup(gr->gr_mem[j]);
                if (member_name == NULL) continue;

                if (strcmp(member_name, name) == 0) {
                    free(member_name);
                    continue;
                }

                int flag = 0;
                for (int p = 0; p < print_count; p++) {
                    if (strcmp(print_users[p], member_name) == 0) {
                        flag = 1;
                        break;
                    }
                }
                
                if (!flag) {
                    print_users[print_count] = member_name;
                    print_count++;
                    
                    printf("одногруппник %s (группы:", member_name);
                    
                    for (int k = 0; k < ngroups; k++) {
                        struct group *g2 = getgrgid(groups[k]);
                        if (g2 != NULL) {
                            for (int m = 0; g2->gr_mem[m] != NULL; m++) {
                                if (strcmp(g2->gr_mem[m], member_name) == 0) {
                                    printf(" %s", g2->gr_name);
                                    break;
                                }
                            }
                        }
                    }
                    printf(")\n");
                } else {
                    free(member_name);
                }
            }
        }
    }

    for (int i = 0; i < print_count; i++) {
        free(print_users[i]);
    }
    free(print_users);
    free(groups);
    
    return 0;
}
