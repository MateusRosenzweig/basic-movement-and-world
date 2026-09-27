#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MAP_HANDLER.h"
#include "CHARACTER_HANDLER.h"
#include "MENU_HANDLER.h"

#if defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>

#endif


int main(){

    char OS;

    #if defined(_WIN64) || defined(_WIN32)
    OS = 'w';
    #elif defined(__linux__)
    OS = 'l';
    #endif

    int option = menu_walls(OS);
    int map_size = menu_tamanho_mundo(OS);

    World *earth = create_world(map_size, 10, option);

    Character *player = create_character('P', 1, 1);

    start_world(earth, player);

    #if defined(__linux__)
        struct termios oldt, newt;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    #elif defined(_WIN32) || defined(_WIN64)
        HANDLE hIn;
        DWORD oldMode, newMode;
        DWORD read;

        hIn = GetStdHandle(STD_INPUT_HANDLE);

        GetConsoleMode(hIn, &oldMode);

        newMode = oldMode;
        newMode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
        SetConsoleMode(hIn, newMode);

    #endif

    srand(time(NULL));

    while(current_character_action(player) != 'q'){
        char new_action;

        scanf("%c", &new_action);

        change_character_action(new_action, player);
        character_movement(player, earth);
        print_current_chunk(earth, OS);
    }



    #if defined(__linux__)
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #elif defined(_WIN32) || defined(_WIN64)
        SetConsoleMode(hIn, oldMode);
    #endif

    destroy_character(player);
    destroy_world(earth);

    return 0;
}
