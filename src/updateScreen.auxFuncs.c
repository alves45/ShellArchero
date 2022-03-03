#include "bind.h"

#define clear() printf("\033[H\033[J")
#define hideCursor() printf("\e[?25l")
#define showCursor() printf("\e[?25h")
#define textColor(r, g, b) printf("\x1b[38;2;%d;%d;%dm", r, g, b)

#define bgColor(r, g, b) printf("\x1b[48;2;%d;%d;%dm", r, g, b)
// #define bgColor(r, g, b) printf("\x1b[41m")  // test performace for windows (very sad)

#define gotoxy(x, y) printf("\x1b[%d;%df", y, x)
#define checkPixelColor(p) p->g < (p->b + FILTER_COLOR) && p->g < (p->r + FILTER_COLOR)

/*

Color	Foreground	Background
Black ■	<ESC>[30m	<ESC>[40m
Red ■	<ESC>[31m	<ESC>[41m
Green ■	<ESC>[32m	<ESC>[42m
Yellow ■	<ESC>[33m	<ESC>[43m
Blue ■	<ESC>[34m	<ESC>[44m
Magenta ■	<ESC>[35m	<ESC>[45m
Cyan ■	<ESC>[36m	<ESC>[46m
Light gray ■	<ESC>[37m	<ESC>[47m
Dark gray ■	<ESC>[90m	<ESC>[100m
Light red ■	<ESC>[91m	<ESC>[101m
Light green ■	<ESC>[92m	<ESC>[102m
Light yellow ■	<ESC>[93m	<ESC>[103m
Light blue ■	<ESC>[94m	<ESC>[104m
Light magenta ■	<ESC>[95m	<ESC>[105m
Light cyan ■	<ESC>[96m	<ESC>[106m
White ■	<ESC>[97m	<ESC>[107m
Bold	<ESC>[1m	-
Underline	<ESC>[4m	-
No underline	<ESC>[24m	-
Negative(reverse the foreground and background)	<ESC>[7m	-
Positive(no negative)	<ESC>[27m	-
Default	<ESC>[0m	-

#ifndef MY_LIB_H_INCLUDED
#define MY_LIB_H_INCLUDED

#include <time.h>
#include <windows.h>

//*****************************************************************************
//          Rotina de tempo em milisegundos
//  ex: para dar um tempo de 1s colocar o valor 1000
//      delay(1000)
//*****************************************************************************
void delay(unsigned int mili_secs)
{
  clock_t tempo;
  tempo = mili_secs + clock();
  while (tempo > clock());
}
//*****************************************************************************
//                       Definição de cores
//*****************************************************************************
enum DOS_COLORS {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
        LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
        LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
//*****************************************************************************
//                       Posição do texto na tela
//*****************************************************************************
void gotoxy(int x, int y)
{
  HANDLE hOut;
  COORD Position;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  Position.X = x;
  Position.Y = y;
  SetConsoleCursorPosition(hOut,Position);
}
//*****************************************************************************
//                       Cor do texto
//*****************************************************************************
void textcolor(int cor)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, cor);
}
//*****************************************************************************
//                       Cor do fundo de tela
//*****************************************************************************
void textbackground (int iColor)
{
  HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
//  BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
  bufferInfo.wAttributes &= 0x000F;
  SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}
//*****************************************************************************
//                       Limpar a tela
//*****************************************************************************
void clrscr(void)
{
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
     GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, TEXT(' '),
                   dwConSize, coordScreen, &cCharsWritten);

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
                               dwConSize, coordScreen, &cCharsWritten);

    SetConsoleCursorPosition(hConsole, coordScreen);
}
//*****************************************************************************
//
//*****************************************************************************






#endif // MY_LIB_H_INCLUDED


*/