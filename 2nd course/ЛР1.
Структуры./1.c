#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int x1, y1; // левый верхний угол
    int x2, y2; // правый нижний угол
    RGB color;
} Rectangle;

void draw_rectangle(RGB* image, int width, int height,
                   int x1, int y1, int x2, int y2, RGB color) {
    // Определяем границы прямоугольника
    int left = (x1 < x2) ? x1 : x2;
    int right = (x1 < x2) ? x2 : x1;
    int top = (y1 < y2) ? y1 : y2;
    int bottom = (y1 < y2) ? y2 : y1;

    // Ограничиваем границы размерами изображения
    if (left < 0) left = 0;
    if (right >= width) right = width - 1;
    if (top < 0) top = 0;
    if (bottom >= height) bottom = height - 1;

    // Закрашиваем прямоугольник
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            image[y * width + x] = color;
        }
    }
}

int main() {
    int width, height;
    scanf("%d %d", &width, &height);

    // Создаем изображение (одномерный массив для простоты)
    RGB* image = malloc(width * height * sizeof(RGB));
    
    // Заливаем белым цветом
    for (int i = 0; i < width * height; i++) {
        image[i] = (RGB){255, 255, 255};
    }

    // Читаем прямоугольники
    Rectangle* rectangles = NULL;
    int rect_count = 0;
    
    while (1) {
        int x1, y1, x2, y2, r, g, b;
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r, &g, &b);

        // Проверка на конец ввода
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && r == 0 && g == 0 && b == 0) {
            break;
        }

        // Добавляем прямоугольник в массив
        rect_count++;
        printf("Size of Rectangle: %zu bytes\n", sizeof(Rectangle));
        rectangles = realloc(rectangles, rect_count * sizeof(Rectangle));
        rectangles[rect_count-1] = (Rectangle){
            x1, y1, x2, y2, {(unsigned char)r, (unsigned char)g, (unsigned char)b}
        };
    }

    // Рисуем все прямоугольники с рамками
    for (int i = 0; i < rect_count; i++) {
        Rectangle rect = rectangles[i];
        // Сначала рисуем черную рамку
        draw_rectangle(image, width, height, rect.x1-1, rect.y1-1, rect.x2+1, rect.y2+1,  (RGB){0, 0, 0});
        // Затем сам прямоугольник
        draw_rectangle(image, width, height, rect.x1, rect.y1, rect.x2, rect.y2, rect.color);
    }

    // Выводим изображение в формате PPM P3
    printf("P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            RGB pixel = image[y * width + x];
            printf("%d %d %d |", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }

    // Освобождаем память
    free(image);
    free(rectangles);

    return 0;
}
