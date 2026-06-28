#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *f = fopen(argv[1], "r+b"); 
    if (f == NULL) {
        printf("не удалось открыть файл.\n");
        return 1;
    }
    
    int smeshenie = 0;
    int width = 0, height = 0, bits_on_pixel = 0;

    fseek(f, 10, SEEK_SET);
    fread(&smeshenie, 4, 1, f);

    fseek(f, 18, SEEK_SET);
    fread(&width, 4, 1, f);
    fread(&height, 4, 1, f);

    fseek(f, 28, SEEK_SET);
    fread(&bits_on_pixel, 2, 1, f);

    if (width != height) {
        printf("изображение не квадратное\n");
        fclose(f);
        return 1;
    }

    printf("размер: %dx%d, битность: %d, данные начинаются с байта: %d\n", width, height, bits_on_pixel, smeshenie);
    long width_row = (width * 3 + 3) - (width * 3 + 3)%4;
    printf("ширина строки в байтах: %ld\n", width_row);
    
    unsigned char color[3] = {0, 0, 0}; 
    long pos;

    for (int i = 0; i < height; i++) {
        pos = smeshenie + i * width_row + i * 3;
        fseek(f, pos, SEEK_SET);
        fwrite(color, 1, 3, f);

        pos = smeshenie + i * width_row + (height - i - 1) * 3;
        fseek(f, pos, SEEK_SET);
        fwrite(color, 1, 3, f);
    }

    fclose(f);

    
	return 0;
}

