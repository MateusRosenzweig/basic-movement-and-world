#include "CHARACTER_HANDLER.h"

struct character{

    char skin;
    int *pos_X;
    int *pos_Y;
    char action;

};


Character* create_character(char skin, int pos_X, int pos_Y){
    Character *new = malloc(sizeof(Character));

    new->skin = skin;
    new->pos_X = malloc(sizeof(int));
    new->pos_Y = malloc(sizeof(int));
    *(new->pos_X) = pos_X;
    *(new->pos_Y) = pos_Y;
    new->action = 'l';

    return new;
}

void change_character_action(char new_action, Character *c){
    c->action = new_action;
}

char current_character_action(Character *c){
    return c->action;
}

void change_characterX_position(int new_x, Character *c){
    *(c->pos_X) = new_x;
}

int current_characterX_position(Character *c){
    return *(c->pos_X);
}

void change_characterY_position(int new_y, Character *c){
    *(c->pos_Y) = new_y;
}

int current_characterY_position(Character *c){
    return *(c->pos_Y);
}

char current_character_skin(Character *c){
    return c->skin;
}

void change_character_skin(char new_skin, Character *c){
    c->skin = new_skin;

}

void destroy_character(Character *c){

    free(c->pos_X);
    free(c->pos_Y);

    free(c);
    c = NULL;

}
