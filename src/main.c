#include <stdio.h>
#include <malloc.h>
#include "types/image.h"
#include "types/rustTypes.h"
#include "sprites.h"
#include "spritesConverter.c"

#define clear() printf("\033[H\033[J")
#define hideCursor() printf("\e[?25l")
#define showCursor() printf("\e[?25h")
#define textColor(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)
#define bgColor(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)
#define gotoxy(x, y) printf("\x1b[%d;%df", y, x)
#define filterColor 90
void main()
{
    clear();
    initializeImages();
    u32 count = 0;
    image img = smallDying;
    pixel *p;
    printf("%d     %d   \n", img.height, img.width);
    for (u32 i = 0; i < img.height; i++)
    {
        for (u32 j = 0; j < img.width; j++)
        {
            pixel p = img.pixels[count++];
            bgColor(p.r, p.g, p.b);
            gotoxy(j, i);
            if (p.g < (p.b + filterColor) && p.g < (p.r + filterColor))
                printf(" ");
        }
    }
}
// u32 count = 0;
// // printf("height: %d    width: %d    size:%d", smallRunDown.height, smallRunDown.width, sizeof(smallRunDownPixels));
// pixel *p;
// image img = gimp_image;
// u32 size = img.height * img.width;
// pixel *goodPixel = malloc(size * sizeof(pixel));
// i32 j2 = 0;
// // goodPixel = img.pixels;
// // for (u32 i = 0; i < size; i++)
// //     goodPixel[i] = img.pixels[size - i];
// for (u32 i = 0; img.height > i; i++)
// {
//     for (u32 j = 0; j < img.width; j++)
//     {
//         // pixel *p = &goodPixel[j + img.width * i];
//         pixel *p = &img.pixels[count++];
//         bgColor(p->b, p->g, p->b);
//         gotoxy(j2 + j, i);
//         if (p->b != 0 && p->g != 0 && p->b != 0)
//             printf(" ");
//     }
// }
