#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../../src/types/rustTypes.h"
#include "../../src/types/image.h"

image *loadImage(char *location)
{
    image *img;
    FILE *f = fopen(location, "rb");

    if (f == NULL)
    {
        printf("//Opening failed...%s\n", location);
        return img;
    }

    unsigned char *result;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);

    if (size > SIZE_MAX)
    {
        printf("//Size is too big!%s\n", location);
        fclose(f);
        return img;
    }

    fseek(f, 0, SEEK_SET);
    result = (unsigned char *)malloc((size_t)size);
    char *result2 = result;

    if (size != fread(result, sizeof(unsigned char), (size_t)size, f))
    {
        free(result);
        printf("//Reading failed...%s\n", location);
        fclose(f);
        return img;
    }

    fclose(f);

    if (size < 54)
    {
        free(result);
        printf("//Invalid file...%s\n", location);
        return img;
    }

    if (result[0] != 'B' || result[1] != 'M')
    {
        free(result);
        printf("//Incorrect file header...%s\n", location);
        return img;
    }

    size_t specifiedSize = result[2] | result[3] << 8 | result[4] << 16 | result[5] << 24;

    if (specifiedSize != size)
    {
        free(result);
        printf("//File sizes don't match...%s\n", location);
        return img;
    }

    size_t pdOffset = result[10] | result[11] << 8 | result[12] << 16 | result[13] << 24;

    unsigned long width = result[18] | result[19] << 8 | result[20] << 16 | result[21] << 24;
    unsigned long height = result[22] | result[23] << 8 | result[24] << 16 | result[25] << 24;

    unsigned long bpp = result[28] | result[29] << 8;
    int noCompression = result[30] == 0 && result[31] == 0 && result[32] == 0 && result[33] == 0;

    if (bpp != 24 || !noCompression || width < 1 || height < 1 || width > 64000 || height > 64000)
    {
        free(result);
        printf("//Unsupported BMP format, only 24 bits per pixel are supported...%s\n", location);
        return img;
    }

    int bytesPerPixel = (int)(bpp / 8);

    size_t rowBytes = (width * bytesPerPixel + 3) / 4 * 4;

    printf("//Bytes per row: %lu\n", rowBytes);

    size_t usedRowBytes = width * bytesPerPixel;
    size_t imageBytes = rowBytes * height;

    if (pdOffset > size || pdOffset + imageBytes > size)
    {
        free(result);
        printf("//Invalid offset specified...%s\n", location);
        return img;
    }

    img = malloc(sizeof(image));
    img->height = height;
    img->width = width;

    size_t imgSize = width * height;
    char *data = malloc(imgSize * sizeof(pixel));

    printf("//Offset: %lu\n", pdOffset);

    for (size_t i = 0; i < imgSize * sizeof(pixel); ++i)
    {
        data[i] = result[pdOffset + i];
        if (i % (width * sizeof(pixel)) == 0)
        {
            pdOffset += rowBytes - usedRowBytes;
        }
    }
    img->pixels = (pixel *)data;
    free(result2);
    return img;
}

void releaseImage(image *img)
{
    if (img)
    {
        if (img->pixels)
            free(img->pixels);
        free(img);
    }
}
