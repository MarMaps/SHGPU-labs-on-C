#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int x1, y1;
    int x2, y2; 
    RGB color;
} rect_t;

void draw_rectangle(RGB* image, int width, int height,
                   int x1, int y1, int x2, int y2, RGB color) {
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

    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            image[y * width + x] = color;
        }
    }
}

int main() {
	freopen("r.txt", "r", stdin);
	
    int width, height;
    scanf("%d %d", &width, &height);

    RGB* image = malloc(width * height * sizeof(RGB));

    rect_t* rects = malloc(sizeof(rect_t)); 
    
    int rect_count = 1;
    rects[0] = (rect_t){0, 0, width-1, height-1, {255, 255, 255}};
    
    while (1) {
        int x1, y1, x2, y2, r, g, b;
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r, &g, &b);

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && r == 0 && g == 0 && b == 0) {
            break;
        }
	
		rects = realloc(rects, (rect_count + 1) * sizeof(rect_t));
        rects[rect_count] = (rect_t){x1, y1, x2, y2, {r, g, b}};
        rect_count++;
    }

    for (int i = 0; i < rect_count; i++) {
        if (i == 0) {
            draw_rectangle(image, width, height, rects[i].x1, rects[i].y1, rects[i].x2, rects[i].y2, rects[i].color);
        } else {
            draw_rectangle(image, width, height,rects[i].x1, rects[i].y1, rects[i].x2, rects[i].y2,(RGB){0, 0, 0});
            draw_rectangle(image, width, height,rects[i].x1+1, rects[i].y1+1, rects[i].x2-1, rects[i].y2-1, rects[i].color);
        }
    }
    
	printf("P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            RGB px = image[y * width + x];
            printf("%d %d %d", px.r, px.g, px.b);
            if (x < width - 1) printf(" ");
        }
        printf("\n");
    }
	
	FILE *f = fopen("res.ppm", "w"); 
	if (f) {
		fprintf(f,"P3\n%d %d\n255\n", width, height);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				RGB px = image[y * width + x];
				fprintf(f, "%d %d %d", px.r, px.g, px.b);
				if (x < width - 1) fprintf(f, " ");
			}
			fprintf(f,"\n");
		}
		fclose(f);
	}
	
    free(image);
    free(rects);

    return 0;
}
