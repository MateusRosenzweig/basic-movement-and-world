#ifndef CHARACTER_HANDLE_H
#define CHARACTER_HANDLE_H

#include <stdlib.h>

typedef struct character Character;

Character* create_character(char skin, int pos_X, int pos_Y);

void change_character_action(char new_action, Character *c);

char current_character_action(Character *c);

void change_characterX_position(int new_x, Character *c);

int current_characterX_position(Character *c);

void change_characterY_position(int new_y, Character *c);

int current_characterY_position(Character *c);

char current_character_skin(Character *c);

void change_character_skin(char new_skin, Character *c);

void destroy_character(Character *c);

#endif
