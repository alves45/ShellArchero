#include "bind.h"

void main()
{
    printf("Iniciando o jogo...\n");
    printf("O game precisa de bastante zoom out no console!!!\n");
    printf("use awsd para movimentacao\n");
    printf("Tecle Q para sair a qualquer momento... tecle qualquer coisa para continuar\n");
    initializeImages();
    getch();
    hideCursor();
    clear();
    // pthread_t threads[NUM_THREADS];
    // for (u8 thread = 0; thread < NUM_THREADS; thread++)
    // {
    //     pthread_create(&threads[thread], NULL, updateScreen, 0);
    // }
    person.health = 255;
    person.posi.x = 2;
    person.posi.y = 2;
    person.oldPosi = person.posi;
    person.speed = 1;
    person.state = &greatGood;
    person.oldState = &greatGood;
    while (1)
    {
        u8 key = getch();
        switch (key)
        {
        case 'q':
        case 'Q':
            goto EndWhile;
            break;
        case 'w':
        case 'W':
            person.posi.y -= person.speed;
            person.state = &greatRunUp;
            break;
        case 's':
        case 'S':
            person.posi.y += person.speed;
            person.state = &greatRunDown;
            break;
        case 'a':
        case 'A':
            person.posi.x -= person.speed;
            person.state = &greatRunRight2;
            break;
        case 'd':
        case 'D':
            person.posi.x += person.speed;
            person.state = &greatRunLeft2;
            break;
        default:
            break;
        }
        updateScreen();
    }
EndWhile:
    printf("\nBye\n");
}
