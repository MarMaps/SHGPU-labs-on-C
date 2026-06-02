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
	const char *name = "sambashare";

    pw =getpwnam(name);
    
    ngroups = 0;
    
    //с ngroups=0 вернёт -1 но запишет реальное кол-во в ngroups
    getgrouplist(name, pw->pw_gid, NULL, &ngroups);

    printf("группы: %d\n", ngroups);

    groups = malloc(sizeof(*groups)* ngroups);

    // Второй вызов — реально заполняет массив
    getgrouplist(name, pw->pw_gid, groups, &ngroups);

    for (int i = 0; i < ngroups; i++) {
        gr = getgrgid(groups[i]);
        if (gr != NULL) {
            printf("группа %s: одногруппники", gr->gr_name);
            for (int j = 0; gr->gr_mem[j] != NULL; j++) {
				const char *member_name = gr->gr_mem[j];
				if (strcmp(member_name, name) == 0) 
					continue;
					
				printf(" %s", member_name);
				
			}
			printf("\n");
        }
    }

    free(groups);
    return 0;
}
