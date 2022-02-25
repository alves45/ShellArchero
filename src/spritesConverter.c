#include "bind.h"

void initializeImages()
{
    image *imgList[] = allImages;
    for (u8 index = 0; index < COUNT_IMAGES; index++)
    {
        image *img = imgList[index];
        u32 countPixels = img->size.height * img->size.width;
        u32 sizeData = countPixels * sizeof(pixel);
        pixel *pixels = malloc(sizeData);
        for (u32 i = 0; i < countPixels; i++)
        {
            pixels[i] = img->pixels[countPixels - i];
            u8 temp = pixels[i].r;
            pixels[i].r = pixels[i].b;
            pixels[i].b = temp;
        }
        for (u32 i = 0; countPixels > i; i++)
            img->pixels[i] = pixels[i];
        free(pixels);
    }
}
