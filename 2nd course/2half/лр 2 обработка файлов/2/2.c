#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *f = fopen(argv[1], "r+b"); 
    if (f == NULL) {
        printf("не удалось открыть файл.\n");
        return 1;
    }
    
    unsigned char signature[2];
    int smeshenie = 0;
    int width = 0, height = 0, bits_on_pixel = 0;

    //сигнатура(что в файле есть BM)
    fread(signature, 1, 2, f);
    if (signature[0] != 'B' || signature[1] != 'M') {
        printf("это не BMP файл\n");
        fclose(f); return 1;
    }

    fseek(f, 10, SEEK_SET);
    fread(&smeshenie, 4, 1, f);

    fseek(f, 18, SEEK_SET);
    fread(&width, 4, 1, f);
    fread(&height, 4, 1, f);

    fseek(f, 28, SEEK_SET);
    fread(&bits_on_pixel, 2, 1, f);

    if (width != height) {
        printf("изображение не квадратное\n");
        fclose(f); return 1;
    }
    if (bits_on_pixel != 24) {
        printf("поддерживается только 24-битный BMP\n");
        fclose(f); return 1;
    }

    printf("размер: %dx%d, битность: %d, данные начинаются с байта: %d\n", width, height, bits_on_pixel, smeshenie);

    fclose(f);
    
	return 0;
}

