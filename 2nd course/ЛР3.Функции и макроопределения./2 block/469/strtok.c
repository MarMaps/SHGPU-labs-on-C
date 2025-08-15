#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Это строка, разделенная запятыми, точками и пробелами.";
  const char *delim = ",. ";
  char *token;

  // Получаем первый токен
  token = strtok(str, delim);

  // Пока есть токены, выводим их
  while (token != NULL) {
    printf("Токен: %s\n", token);
    // Получаем следующий токен
    token = strtok(NULL, delim);
  }

  return 0;
}
