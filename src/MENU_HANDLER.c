#include "MENU_HANDLER.h"

#define TEST 1
#define MICRO 2
#define MINI 4
#define CUTE 10
#define SMALL 20
#define MEDIUM 50
#define BIG 100
#define MASSIVE 1000
#define DONT 10000

int menu_inicial(char OS){

    int option;

    while(true){

        if(OS == 'w') system("clr");
        else if(OS == 'l') system("clear");

        printf("[1] New Game\n");
        printf("[2] Continue\n");

        scanf("%d", &option);

        if(option == 1 || option == 2) break;
    }
    return option;
}

int menu_walls(char OS){
    int option;

    while(true){
        if(OS == 'w') system("clr");
        else if(OS == 'l') system("clear");

        printf("[1] WALLS\n");
        printf("[2] NO WALLS\n");

        scanf("%d", &option);

        if(option == 1 || option == 2) break;

    }
    return option;
}

int menu_tamanho_mundo(char OS){

    int map_size;

    while(true){
        if(OS == 'l') system("clear");
        else if(OS == 'w') system("clr");

        printf("[0] TEST\n");
        printf("[1] MICRO\n");
        printf("[2] MINI\n");
        printf("[3] CUTE\n");
        printf("[4] SMALL\n");
        printf("[5] MEDIUM\n");
        printf("[6] BIG\n");
        printf("[7] MASSIVE\n");
        printf("[8] CUSTOM\n");
        printf("Choose a option: ");


        scanf("%d", &map_size);

        if(map_size == 0){
            map_size = TEST;
            break;
        }

        if(map_size == 1){
            map_size = MICRO;
            break;
        }

        else if(map_size == 2){
            map_size = MINI;
            break;
        }

        else if(map_size == 3){
            map_size = CUTE;
            break;
        }

        else if(map_size == 4){
            map_size = SMALL;
            break;
        }

        else if(map_size == 5){
            map_size = MEDIUM;
            break;
        }

        else if(map_size == 6){
            map_size = BIG;
            break;

        }

        else if(map_size == 7){
            map_size = MASSIVE;
            break;

        }
        else if(map_size == 8){
            printf("Type a number: ");
            scanf("%d", &map_size);
            break;

        }

    }

    return map_size;
}
