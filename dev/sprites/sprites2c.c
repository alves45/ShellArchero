#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <string.h>
#include "../../src/types/rustTypes.h"
#include "../../src/types/image.h"
#include "image2c.c"
#include "loadImage.c"

// use "make sprites2c" for convert the sprites in to C code.
#define extensionImageSupported "bmp"
// #define imagesDirPath "dev/sprites/images/fromGimp/"
#define imagesDirPath "images/fromGimp2/"

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
        char *imagePath = calloc(sizeof(char), sizeImagePath);
        strcat(imagePath, imagesDirPath);
        strcat(imagePath, imageFile->d_name);
        char *imageName = calloc(sizeof(char), sizeImagePath);
        char *imagePath2 = calloc(sizeof(char), sizeImagePath);
        strcpy(imagePath2, imagePath);
        GetLeafName(imagePath, imageName);
        FixName(imageName);
        printf("#ifndef %s_define\n#define %s_define 1\n", imageName, imageName);
        printf("const char %sPixels [] = {\n", imageName);
        image *img = loadImage(imagePath2);
        printf("};\n");
        printf("const image %s = {.height = %d, .width = %d, .pixels = (pixel *)%sPixels};\n\n", imageName, img->height, img->width, imageName);
        printf("#endif\n\n\n\n");
        free(imagePath);
        free(imageName);
        free(imagePath2);
        releaseImage(img);
    }
}
