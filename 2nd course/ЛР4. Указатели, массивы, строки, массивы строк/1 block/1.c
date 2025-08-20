#include <stdio.h>
#include <stdlib.h>

//1
void matrix_content(int **m, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

//2
void reset_to_zero(int **m, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
		}
	}
}

//3
void random_value(int **m, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = rand() % 101;
		}
	}
	
}

//4
void change_el(int **m, int n)
{
	int x, y, new;
	printf("координаты: ");
	scanf("%d %d", &x, &y);
	printf("на какое значение: ");
	scanf("%d", &new);
	if (x < 0 || x >= n || y < 0 || y >= n) {
		printf("выход за границы\n");
		return;
	}
	m[x][y] = new;
}

//5
void rotate_matrix(int **m, int n)
{
	int direction;
	printf("направление(1-по часовой, 2-против): ");
	scanf("%d", &direction);
	
	int **temp = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		temp[i] = (int *)malloc(n * sizeof(int));
	}

	if (direction == 1) { //по часовой
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[j][n - 1 - i] = m[i][j];
			}
		}
	}
	else if (direction == 2) { //против
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[n - 1 - j][i] = m[i][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = temp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		free(temp[i]);
	}
	free(temp);
}

//6
void transpose_matrix(int **m, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
}

int main(int argc, char **argv)
{
	int n;
	
	printf("размер матрицы N*N: ");
	scanf("%d", &n);
	int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
    
    int choice;
    
    do 
    {
		printf("Меню управления. Цифра: ");
		scanf("%d", &choice);
    
		switch(choice)
		{
			case 1:
				matrix_content(matrix, n);
				break;
			case 2:
				reset_to_zero(matrix, n);
				break;
			case 3:
				random_value(matrix, n);
				break;
			case 4:
				change_el(matrix, n);
				break;
			case 5:
				rotate_matrix(matrix, n);
				break;
			case 6:
				transpose_matrix(matrix, n);
				break;
		}
    
	} while (choice != 0);
    
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
