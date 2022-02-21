#include <stdio.h>
#include <malloc.h>
#include "../../src/types/rustTypes.h"
#include "loadImage.c"
#include "../../src/types/image.h"

// use "make sprites2c"

void main()
{
    image *img = loadImage("images/bmp.bmp");

    printf("%d", u8MAX);
}
