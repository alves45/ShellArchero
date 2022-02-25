#include "bind.h"

void main()
{
    printf("Iniciando o jogo...\n");
    printf("O game precisa de bastante zoom out no console!!!\n");
    printf("Tecle ESC para sair a qualquer momento... (menos nos proximos 3 segundos)\n");
    initializeImages();
    sleep(3);
    hideCursor();
    clear();
    printf("sdfsdfsdf\n");
    pthread_t threads[NUM_THREADS];
    for (u8 thread = 0; thread < NUM_THREADS; thread++)
    {
        pthread_create(&threads[thread], NULL, updateScreen, 0);
    }
    while (1)
    {
        u8 key = (u8)getch();
        // if (key == KEY_ESC)
        // if (key == KEY_DOWN)
    }
}
