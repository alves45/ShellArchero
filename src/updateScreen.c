#include "bind.h"

#define clear() printf("\033[H\033[J")
#define hideCursor() printf("\e[?25l")
#define showCursor() printf("\e[?25h")
#define textColor(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)
#define bgColor(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)
#define gotoxy(x, y) printf("\x1b[%d;%df", y, x)
#define checkPixelColor(p) p->g < (p->b + FILTER_COLOR) && p->g < (p->r + FILTER_COLOR)

void drawImg(image *img, position posit)
{
    u32 count = 0;
    pixel *p;
    for (u32 i = 0; i < img->size.height; i++)
    {
        for (u32 j = 0; j < img->size.width; j++)
        {
            p = &(img->pixels[count++]);
            if (checkPixelColor(p))
            {
                gotoxy(j + posit.x, i + posit.y);
                bgColor(p->r, p->g, p->b);
                printf(" ");
            }
        }
    }
}

void drawImgNone(image *img, position posit)
{
    u32 count = 0;
    pixel *p;
    for (u32 i = 0; i < img->size.height; i++)
    {
        for (u32 j = 0; j < img->size.width; j++)
        {
            p = &(img->pixels[count++]);
            if (checkPixelColor(p))
            {
                gotoxy(j + posit.x, i + posit.y);
                bgColor(0, 0, 0);
                printf(" ");
            }
        }
    }
}

void drawnBorder()
{
    pixel p = thisMap.color;
    bgColor(p.r, p.g, p.b);
    for (u16 i = 0; i < thisMap.s.width + 1; i++)
    {
        gotoxy(i, 0);
        printf(" ");
        gotoxy(i, thisMap.s.height);
        printf(" ");
    }
    for (u16 i = 0; i < thisMap.s.height + 1; i++)
    {
        gotoxy(0, i);
        printf(" ");
        gotoxy(thisMap.s.width, i);
        printf(" ");
    }
}
void *updateScreen()
{
    drawnBorder();
    drawImgNone(person.oldState, person.oldPosi);
    person.oldState = person.state;
    person.oldPosi = person.posi;
    drawImg(person.state, person.posi);
}
