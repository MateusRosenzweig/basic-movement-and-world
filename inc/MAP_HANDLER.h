#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include <stdio.h>
#include <time.h>
#include "CHARACTER_HANDLER.h"
#include "STACK.h"

#if defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>

#endif

typedef struct world World;

World* create_world(int world_size, int chunk_size, int option);

//some bullshit for main informatio purposes
int return_world_size(World *w);

int return_chunk_size(World *w);

int return_gridX_size(World *w);

int return_gridY_size(World *w);

void start_world(World *w, Character *p);

void print_current_chunk(World *w, char OS);

void character_movement(Character *player, World *w);

void destroy_world(World *w);

#endif
