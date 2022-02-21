#include "rustTypes.h"

typedef struct
{
    u8 r;
    u8 g;
    u8 b;
} pixel;

typedef struct
{
    u16 width;
    u16 height;
    pixel *pixels;
} image;
