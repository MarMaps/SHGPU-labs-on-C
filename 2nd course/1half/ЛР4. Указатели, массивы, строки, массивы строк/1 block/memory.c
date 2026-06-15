#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> // для malloc_usable_size

int main() {
    int n = 3;
    int **matrix = malloc(n * sizeof(int *));
    printf("matrix: запрошено %zu байт, реально %zu байт\n",
           n * sizeof(int*), malloc_usable_size(matrix));

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
        printf("row %d: запрошено %zu байт, реально %zu байт\n",
               i, n * sizeof(int), malloc_usable_size(matrix[i]));
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
