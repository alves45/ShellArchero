// thanks for your code Tefek https://www.youtube.com/watch?v=oR12ibEHa4E

#include <stdio.h>
#include <malloc.h>
#include "../../src/types/rustTypes.h"
#include "../../src/types/image.h"

image *loadImage(char *path)
{
    image *img = NULL;
    FILE *f = fopen(path, "rb");

    if (f == NULL)
    {
        puts("Opening failed...");
        return img;
    }

    u8 *result;
    fseek(f, 0, SEEK_END);
    u32 size = ftell(f);

    if (size > u32MAX)
    {
        puts("Size is too big!");
        fclose(f);
        return img;
    }

    fseek(f, 0, SEEK_SET);
    result = malloc((u32)size);

    if (size != fread(result, sizeof(u8), (u32)size, f))
    {
        free(result);
        puts("Reading failed...");
        fclose(f);
        return img;
    }

    fclose(f);

    if (size < 54)
    {
        free(result);
        puts("Invalid file...");
        return img;
    }

    if (result[0] != 'B' || result[1] != 'M')
    {
        free(result);
        puts("Incorrect file header...");
        return img;
    }

    u32 specifiedSize = result[2] | result[3] << 8 | result[4] << 16 | result[5] << 24;

    if (specifiedSize != size)
    {
        free(result);
        puts("File sizes don't match...");
        return img;
    }

    u32 pdOffset = result[10] | result[11] << 8 | result[12] << 16 | result[13] << 24;

    u32 width = result[18] | result[19] << 8 | result[20] << 16 | result[21] << 24;
    u32 height = result[22] | result[23] << 8 | result[24] << 16 | result[25] << 24;

    u32 bpp = result[28] | result[29] << 8;
    int noCompression = result[30] == 0 && result[31] == 0 && result[32] == 0 && result[33] == 0;

    if (bpp != 24 || !noCompression || width < 1 || height < 1 || width > 64000 || height > 64000)
    {
        free(result);
        puts("Unsupported BMP format, only 24 bits per pixel are supported...");
        return img;
    }

    int bytesPerPixel = (int)(bpp / 8);

    u32 rowBytes = (width * bytesPerPixel + 3) / 4 * 4;
    u32 usedRowBytes = width * bytesPerPixel;
    u32 imageBytes = rowBytes * height;

    if (pdOffset > size || pdOffset + imageBytes > size)
    {
        free(result);
        puts("Invalid offset specified...");
        return img;
    }

    img = malloc(sizeof(image));
    img->height = height;
    img->width = width;
    u32 imgSize = width * height;
    img->pixels = (pixel *)malloc(sizeof(pixel) * imgSize);
    pixel *ptr = img->pixels;
    u8 *srcPtr = &result[pdOffset];

    for (u32 i = 0; i < imgSize; ++i)
    {
        pixel *p = (img->pixels + sizeof(pixel) * i);
        p->r = *srcPtr;
        p->g = *(srcPtr + 1);
        p->b = *(srcPtr + 2);

        srcPtr += bytesPerPixel;

        if (i % width == 0)
        {
            srcPtr += rowBytes - usedRowBytes;
        }
    }

    free(result);

    return img;
}

void release(image *img)
{
    if (img)
    {
        if (img->pixels)
            free(img->pixels);

        free(img);
    }
}