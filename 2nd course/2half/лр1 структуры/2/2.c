#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int x1, y1;
    int size;
} square_t;

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
    size_t total_b = (image_size * sizeof(RGB*)) + (image_size * image_size * sizeof(RGB));
	printf("общий объем памяти: %zu б\n", total_b);
    
    for (int y = 0; y < image_size; y++) {
		free(image[y]);
	}
	free(image);

	return 0;
}

