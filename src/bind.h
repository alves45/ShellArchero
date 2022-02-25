#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <pthread.h>
#ifdef __linux__
#include <unistd.h>  //lib for sleep and usleep
#include <termios.h> //lib for getch
#elif _WIN32
#include <dos.h>   //lib for sleep and usleep
#include <conio.h> //lib for getch
#endif

#ifdef __linux__
#ifndef getchLinux
#define getchLinux 1
#include "getchLinux.c" //getch for linux is define here
#endif
#endif

#ifndef types
#define types
#include "types.h"
#endif

#ifndef sprites
#define sprites 1
#include "sprites.h"
#endif

#ifndef spritesConverter
#define spritesConverter 1
#include "spritesConverter.c"
#endif

#ifndef updateScreen_lib
#define updateScreen_lib 1
#include "updateScreen.c"
#endif

#ifndef globalVariables
#define globalVariables 1
#include "globalVariables.h"
#endif

#ifndef tools
#define tools 1
#include "tools.c"
#endif
