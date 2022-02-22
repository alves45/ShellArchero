// thanks for your code Tefek https://www.youtube.com/watch?v=oR12ibEHa4E

#include <stdio.h>
#include <malloc.h>
#include "../../src/types/rustTypes.h"
#include "../../src/types/image.h"

extern image *loadImage(char *path)
{
    image *img = NULL;
    FILE *f = fopen(path, "rb");

    if (f == NULL)
    {
        printf("Opening failed...%s\n", path);
        return img;
    }
    u8 *result;
    fseek(f, 0, SEEK_END);
    u32 size = ftell(f);

    if (size > u32MAX)
    {
        printf("Size is too big!%s\n", path);
        fclose(f);
        return img;
    }

    fseek(f, 0, SEEK_SET);
    result = malloc(size);

    if (size != fread(result, sizeof(u8), (u32)size, f))
    {
        free(result);
        printf("Reading failed...%s\n", path);
        fclose(f);
        return img;
    }

    fclose(f);

    if (size < 54)
    {
        free(result);
        printf("Invalid file...%s\n", path);
        return img;
    }

    if (result[0] != 'B' || result[1] != 'M')
    {
        free(result);
        printf("Incorrect file header...%s\n", path);
        return img;
    }

    u32 specifiedSize = result[2] | result[3] << 8 | result[4] << 16 | result[5] << 24;

    if (specifiedSize != size)
    {
        free(result);
        printf("File sizes don't match...%s\n", path);
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
        printf("Unsupported BMP format, only 24 bits per pixel are supported...%s\n", path);
        return img;
    }

    int bytesPerPixel = (int)(bpp / 8);

    u32 rowBytes = (width * bytesPerPixel + 3) / 4 * 4;
    u32 usedRowBytes = width * bytesPerPixel;
    u32 imageBytes = rowBytes * height;

    if (pdOffset > size || pdOffset + imageBytes > size)
    {
        free(result);
        printf("Invalid offset specified...%s\n", path);
        return img;
    }
    img = malloc(sizeof(image));
    img->height = height;
    img->width = width;
    u32 imgSize = (width * height);
    img->pixels = malloc(sizeof(pixel) * imgSize);
    u8 *srcPtr = &result[pdOffset];
    u8 *pixels = (u8 *)img->pixels;
    for (u32 i = 0; i < imgSize; ++i)
    {
        pixels[i] = *srcPtr++;
        if (i % width == 0)
        {
            srcPtr += rowBytes - usedRowBytes;
        }
    }
    free(result);

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