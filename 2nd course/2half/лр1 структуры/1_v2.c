#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char r, g, b;
} RGB;

typedef struct
{
    int x1, y1;
    int x2, y2;
    RGB color;
} rect_t;

void draw_rectangle(RGB **image, int width, int height,
                    int x1, int y1, int x2, int y2, RGB color)
{
    int left, right, top, bottom; 
    if (x1 < x2) {
		left = x1;
		right = x2;
	} else {
		left = x2;
		right = x1;
	}
	if (y1 < y2) {
		top = y1;
		bottom = y2;
	} else {
		top = y2;
		bottom = y1;
	}

    if (left < 0) left = 0;
    if (right >= width) right = width - 1;
    if (top < 0) top = 0;
    if (bottom >= height) bottom = height - 1;

    for (int y = top; y <= bottom; y++){
        for (int x = left; x <= right; x++){
            image[y][x] = color;
        }
    }
}

void draw_rectangle_with_border(RGB **image, int width, int height,
                                int x1, int y1, int x2, int y2, RGB color)
{
    draw_rectangle(image, width, height, x1 - 1, y1 - 1, x2 + 1, y2 + 1, (RGB){0, 0, 0});
    draw_rectangle(image, width, height, x1, y1, x2, y2, color);
}

int main()
{
    int width, height;
    scanf("%d %d", &width, &height);

    RGB **image = (RGB **)malloc(height * sizeof(RGB *));
    for (int i = 0; i < height; i++){
        image[i] = (RGB *)malloc(width * sizeof(RGB));
        for (int j = 0; j < width; j++)
        {
            image[i][j] = (RGB){255, 255, 255};
        }
    }

    rect_t *rects = NULL;
    int rect_count = 0;

    while (1){
        int x1, y1, x2, y2, r, g, b;
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r, &g, &b);

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && r == 0 && g == 0 && b == 0)
        {
            break;
        }
        rect_count++;
        rects = (rect_t *)realloc(rects, rect_count * sizeof(rect_t));
        rects[rect_count - 1] = (rect_t){x1, y1, x2, y2, (RGB){(unsigned char)r, (unsigned char)g, (unsigned char)b}};
    }

    for (int r = 0; r < rect_count; r++){
        draw_rectangle_with_border(image, width, height,
                                   rects[r].x1, rects[r].y1,
                                   rects[r].x2, rects[r].y2,
                                   rects[r].color);
    }

    printf("P3\n");
    printf("%d %d\n", width, height);
    printf("255\n");

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            printf("%d %d %d ", image[y][x].r, image[y][x].g, image[y][x].b);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++){
        free(image[i]);
    }
    free(image);
    free(rects);

    return 0;
}
