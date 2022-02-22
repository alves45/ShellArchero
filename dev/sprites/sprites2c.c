#include <stdio.h>
#include <malloc.h>
#include "../../src/types/rustTypes.h"
#include "loadImage.c"
#include "../../src/types/image.h"
#include <dirent.h>
#include <string.h>
// use "make sprites2c" for convert the sprites in to C code.
#define extensionImageSupported "bmp"
#define CFilePath "../../src/sprites.c"
#define imagesDirPath "dev/sprites/images/bmps/"

#include <stdio.h>
#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <dos.h>
#endif

#define clear() printf("\033[H\033[J")
#define hideCursor() printf("\e[?25l")
#define showCursor() printf("\e[?25h")
#define textColor(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)
#define bgColor(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)
#define gotoxy(x, y) printf("\x1b[%d;%df", y, x)

typedef struct
{
    i16 x;
    i16 y;
} position;

void main()
{
    // DIR *dir;
    // dir = opendir(imagesDirPath);
    // if (dir == NULL)
    // {
    //     printf("Read directory error");
    //     return;
    // }
    // typedef struct dirent dirent; // Why this not included in dirent libray?????
    // dirent *imageFile;
    // while ((imageFile = readdir(dir)) != NULL)
    // {
    //     u16 offsetName = strlen(imageFile->d_name) - sizeof extensionImageSupported + 1;
    //     if (strcmp(extensionImageSupported, (imageFile->d_name + offsetName)) != 0)
    //     {
    //         printf("Image not suported %s\n", imageFile->d_name);
    //         continue;
    //     }
    //     u16 sizeImagePath = strlen(imagesDirPath) + strlen(imageFile->d_name) + 1;
    //     char *imagePath = malloc(sizeImagePath);
    //     memset(imagePath, 0, sizeImagePath); // becase the string use NULL for ended
    //     strcat(imagePath, imagesDirPath);
    //     strcat(imagePath, imageFile->d_name);
    //     printf("%s\n", imagePath);
    //     loadImage(imagePath);
    //     free(imagePath);
    // img->
    // }

    image *img = loadImage("dev/sprites/images/bmps/great_good.bmp");
    clear();
    hideCursor();
    for (u16 i = 0; i < img->height; i++)
    {
        for (u16 j = 0; j < img->width; j++)
        {
            pixel *p = &(img->pixels[j + i * img->height]);
            gotoxy(i, j);
            bgColor(p->r, p->g, p->g);
            printf(" ");
        }
    }
    // image *img = loadImage("images/bmp.bmp");
}
