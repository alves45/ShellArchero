#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <string.h>
#include "../../src/types/rustTypes.h"
#include "../../src/types/image.h"
#include "image2c.c"
// #include "../"
// use "make sprites2c" for convert the sprites in to C code.
#define extensionImageSupported "bmp"
#define CFilePath "../../src/sprites.c"
#define imagesDirPath "dev/sprites/images/bmps/"

void main()
{
    printf("#include \"types/image.h\"\n");
    printf("#include \"types/rustTypes.h\"\n");
    DIR *dir;
    dir = opendir(imagesDirPath);
    if (dir == NULL)
    {
        printf("Read directory error");
        return;
    }
    typedef struct dirent dirent; // Why this not included in dirent libray?????
    dirent *imageFile;
    while ((imageFile = readdir(dir)) != NULL)
    {
        u16 offsetName = strlen(imageFile->d_name) - sizeof extensionImageSupported + 1;
        if (strcmp(extensionImageSupported, (imageFile->d_name + offsetName)) != 0)
        {
            // printf("Image not suported %s\n", imageFile->d_name);
            continue;
        }
        u16 sizeImagePath = strlen(imagesDirPath) + strlen(imageFile->d_name) + 1;
        char *imagePath = malloc(sizeImagePath);
        memset(imagePath, 0, sizeImagePath); // becase the string use NULL for ended
        strcat(imagePath, imagesDirPath);
        strcat(imagePath, imageFile->d_name);
        // printf("%s\n", imagePath);
        image2c(imagePath);
    }
}
