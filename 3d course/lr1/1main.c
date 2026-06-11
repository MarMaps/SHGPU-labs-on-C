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
    const char *name = "root";

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
            
            int c = 0;
            while (gr->gr_mem[c] != NULL) {
                c++;
            }
            //отдельгая переменная для передачи gr_mem, массив туда положить gr->gr_mem, заполнить его значениями
            char **arr = malloc((c + 1) * sizeof(char*));
            for (int g = 0; g < c; g++) {
                arr[g] = strdup(gr->gr_mem[g]);
            }
            arr[c] = NULL; 

            for (int j = 0; arr[j] != NULL; j++) {//здесь в gr->gr_mem[j] != NULL; сравнивать с переменной коорую придумалв(arr)
                const char *member_name = arr[j];

                if (strcmp(member_name, name) == 0) {
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
                    print_users[print_count] = strdup(member_name);
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
                }
            }
            
            for (int g = 0; g < c; g++) {
                free(arr[g]);
            }
            free(arr);
        }
    }

    for (int i = 0; i < print_count; i++) {
        free(print_users[i]);
    }
    free(print_users);
    free(groups);
    return 0;
}
