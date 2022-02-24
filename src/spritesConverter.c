#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "types/image.h"
#include "types/rustTypes.h"
#include "sprites.h"
#include "tools.c"

// shrink( imageDst, imageSrc )
#define countImages 11
#define allImages                                                                                                                                                           \
    {                                                                                                                                                                       \
        &greatGood, &greatRunLeft, &greatRunUp, &smallDying, &greatRunDown, &greatRunRight2, &greatStopLeft, &smallRunDown, &greatRunLeft2, &greatRunRight, &greatStopRight \
    }
#define rallImages                                                                                                                                                                     \
    {                                                                                                                                                                                  \
        &rgreatGood, &rgreatRunLeft, &rgreatRunUp, &rsmallDying, &rgreatRunDown, &rgreatRunRight2, &rgreatStopLeft, &rsmallRunDown, &rgreatRunLeft2, &rgreatRunRight, &rgreatStopRight \
    }

image rgreatGood, rgreatRunLeft, rgreatRunUp, rsmallDying, rgreatRunDown, rgreatRunRight2, rgreatStopLeft, rsmallRunDown, rgreatRunLeft2, rgreatRunRight, rgreatStopRight;

void initializeImages()
{
    image *imgList[] = allImages;
    for (u8 index = 0; index < countImages; index++)
    {
        image *img = imgList[index];
        u32 countPixels = img->height * img->width;
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
