#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int x1, y1, size;
} square_t;

void fill_squares(square_t* squares, int* idx, int x, int y, int size, int iter) {
	if (iter == 0) {
        return;
    }
    
    int new_size = size / 3;
	
	int cx = x + new_size;
    int cy = y + new_size;
    squares[*idx] = (square_t){cx, cy, new_size};
    (*idx)++;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            int next_x = x + i * new_size;
            int next_y = y + j * new_size;
            // Рекурсивно вызываем для этого меньшего квадрата,
            // уменьшая глубину итераций на 1
            fill_squares(squares, idx, next_x, next_y, new_size, iter - 1);
        }
    }
}

int main(int argc, char **argv)
{
	int base_size, iter, r,g,b, image_size;
	RGB base_color, r_color;
	
	printf("размер стороны ковра: ");
	scanf("%d", &base_size);
	printf("итерации: ");
    scanf("%d", &iter);
    printf("цвет исходного квадрата: ");
    scanf("%d %d %d", &r, &g, &b);
    base_color = (RGB){r, g, b};
    printf("цвет изымаемых квадратов: ");
    scanf("%d %d %d", &r, &g, &b);
    r_color = (RGB){r, g, b};
    
    image_size = base_size;
    RGB** image = (RGB**)malloc(image_size * sizeof(RGB*));
    for (int y = 0; y < image_size; y++) {
        image[y] = (RGB*)malloc(image_size * sizeof(RGB));
        for (int x = 0; x < image_size; x++) {
            image[y][x] = base_color;
        }
    }
    //size_t total_b = (image_size * sizeof(RGB*)) + (image_size * image_size * sizeof(RGB));
	//printf("общий объем памяти: %zuб\n", total_b);
	long long r_squares = 0;
    long long step = 1;// 8^0
    for (int i = 0; i < iter; i++) {
        r_squares += step;
        step *= 8;
    }
	square_t* squares = (square_t*)malloc(r_squares * sizeof(square_t));

    int idx = 0;
    fill_squares(squares, &idx, 0, 0, base_size, iter);
    
    for (int i = 0; i < r_squares; i++) {
        square_t sq = squares[i];
        for (int y = sq.y1; y < sq.y1 + sq.size && y < base_size; y++) {
            for (int x = sq.x1; x < sq.x1 + sq.size && x < base_size; x++) {
				image[y][x] = r_color;    
            }
        }
    }

    printf("P3\n%d %d\n255\n", image_size, image_size);
    for (int y = 0; y < image_size; y++) {
        for (int x = 0; x < image_size; x++) {
            RGB px = image[y][x];
            printf("%d %d %d ", px.r, px.g, px.b);
        }
        printf("\n");
    }

	FILE *f = fopen("res.ppm", "w");
    if (f) {
        fprintf(f, "P3\n%d %d\n255\n", image_size, image_size);
        for (int y = 0; y < image_size; y++) {
            for (int x = 0; x < image_size; x++) {
                RGB px = image[y][x];
                fprintf(f, "%d %d %d", px.r, px.g, px.b);
                if (x < image_size - 1) fprintf(f, " ");
            }
            fprintf(f, "\n");
        }
        fclose(f);
    }
    
    for (int y = 0; y < image_size; y++) {
		free(image[y]);
	}
	free(image);
	free(squares);
	return 0;
}

