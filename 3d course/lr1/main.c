#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    //if (argc != 2) {
    //    printf("Использование: %s <имя_пользователя>\\n", argv[0]);
    //    return 1;
    //}

    const char *username = argv[1];

    // Получаем запись о пользователе
    struct passwd *pw = getpwnam(username);
    if (pw == NULL) {
        printf("Пользователь '%s' не найден\\n", username);
        return 1;
    }

    printf("Пользователь: %s\n", pw->pw_name);
    printf("UID: %d\n", pw->pw_uid);
    printf("Основной GID: %d\n", pw->pw_gid);

    // Узнаём сколько групп у пользователя
    int ngroups = 0;
    // Первый вызов с ngroups=0 вернёт -1, но запишет реальное количество в ngroups
    getgrouplist(username, pw->pw_gid, NULL, &ngroups);

    printf("Количество групп: %d\n", ngroups);

    // Выделяем память под массив GID
    gid_t *groups = malloc(ngroups * sizeof(gid_t));

    // Второй вызов — реально заполняет массив
    getgrouplist(username, pw->pw_gid, groups, &ngroups);

    // Выводим имя каждой группы
    printf("Группы:\n");
    for (int i = 0; i < ngroups; i++) {
        struct group *gr = getgrgid(groups[i]);
        if (gr != NULL) {
            printf("  - %s (GID: %d)\n", gr->gr_name, groups[i]);
        }
    }

    free(groups);
    return 0;
}