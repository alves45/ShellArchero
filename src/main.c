#include <stdio.h>
#include <malloc.h>
#include "types/image.h"
#include "types/rustTypes.h"
#include "sprites.h"
#define clear() printf("\033[H\033[J")
#define hideCursor() printf("\e[?25l")
#define showCursor() printf("\e[?25h")
#define textColor(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)
#define bgColor(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)
#define gotoxy(x, y) printf("\x1b[%d;%df", y, x)

void main()
{
    u16 count = 0;
    // printf("height: %d    width: %d    size:%d", smallRunDown.height, smallRunDown.width, sizeof(smallRunDownPixels));
    pixel *p;
    u32 size = smallRunDown.height * smallRunDown.width;
    pixel *goodPixel = malloc(size * sizeof(pixel));
    for (u32 i = 0; i < size; i++)
        goodPixel[i] = smallRunDown.pixels[size - i];
    for (u16 i = 0; smallRunDown.height > i; i++)
    {
        for (u16 j = 0; j < smallRunDown.width; j++)
        {
            pixel *p = &goodPixel[count++];
            bgColor(p->b, p->g, p->b);
            gotoxy(j, i);
            printf(" ");
        }
        count++;
    }
}