

#include "bind.h"

#define NUM_THREADS 1
#define COUNT_IMAGES 11
#define FILTER_COLOR 90
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define allImages                                                                                                                                                           \
    {                                                                                                                                                                       \
        &greatGood, &greatRunLeft, &greatRunUp, &smallDying, &greatRunDown, &greatRunRight2, &greatStopLeft, &smallRunDown, &greatRunLeft2, &greatRunRight, &greatStopRight \
    }

map thisMap = {.s = {.height = 100, .width = 100}, .color = {.r = 255, .g = 255, .b = 255}};
// object person;
