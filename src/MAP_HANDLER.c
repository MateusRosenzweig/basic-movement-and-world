#include "MAP_HANDLER.h"

int CHUNK_SIZE = 50;

struct world{
    int world_size;
    int chunk_size;

    char chunk_map[500][500];

    int *current_Grid_X;
    int *current_Grid_Y;

    FILE *world_snapshot;
};

void generate_world_baseplate_no_walls(World *w){

    for(int k = 0; k < w->world_size; k++){
        for(int l = 0; l < w->world_size; l++){

            for(int i = 0; i < CHUNK_SIZE; i++){
                for(int j = 0; j < CHUNK_SIZE; j++){
                    w->chunk_map[i][j] = ' ';
                }
            }


            char temp[100];
            snprintf(temp, sizeof(temp), "map[%d][%d].txt", k, l);

            w->world_snapshot = fopen(temp, "w");

            for(int i = 0; i < CHUNK_SIZE; i++){
                for(int j = 0; j < CHUNK_SIZE; j++){
                    fprintf(w->world_snapshot, "%c", w->chunk_map[i][j]);
                }
                fprintf(w->world_snapshot, "\n");
            }


            fclose(w->world_snapshot);
        }
    }

}

void generate_world_baseplate_walls(World *w){

    for(int k = 0; k < w->world_size; k++){
        for(int l = 0; l < w->world_size; l++){

            for(int i = 0; i < CHUNK_SIZE; i++){
                for(int j = 0; j < CHUNK_SIZE; j++){
                    if((i == 0 && k == 0) || (i == CHUNK_SIZE - 1 && k == w->world_size-1)){
                        w->chunk_map[i][j] = '#';
                    }
                    else if((j == 0 && l == 0 ) || (j == CHUNK_SIZE - 1 && l == w->world_size - 1)){
                        w->chunk_map[i][j] = '#';
                    }

                    else w->chunk_map[i][j] = ' ';
                }
            }


            char temp[100];
            snprintf(temp, sizeof(temp), "map[%d][%d].txt", k, l);

            w->world_snapshot = fopen(temp, "w");

            for(int i = 0; i < CHUNK_SIZE; i++){
                for(int j = 0; j < CHUNK_SIZE; j++){
                    fprintf(w->world_snapshot, "%c", w->chunk_map[i][j]);
                }
                fprintf(w->world_snapshot, "\n");
            }


            fclose(w->world_snapshot);
        }
    }

}

World* create_world(int world_size, int chunk_size, int option){
    World *new = malloc(sizeof(World));

    new->world_size = world_size;
    new->chunk_size = chunk_size;

    CHUNK_SIZE = new->chunk_size;

    new->current_Grid_X = malloc(sizeof(int));
    new->current_Grid_Y = malloc(sizeof(int));

    *(new->current_Grid_X) = 0;
    *(new->current_Grid_Y) = 0;

    new->world_snapshot = NULL;

    if(option == 1) generate_world_baseplate_walls(new);
    else if(option == 2) generate_world_baseplate_no_walls(new);

    return new;
}


int return_world_size(World *w){
    return w->world_size;
}

int return_chunk_size(World *w){
    return w->chunk_size;
}

int return_gridX_size(World *w){
    return *(w->current_Grid_X);
}


int return_gridY_size(World *w){
    return *(w->current_Grid_Y);
}

void start_world(World *w, Character *p){
    w->world_snapshot = fopen("map[0][0].txt", "r");

    for(int i = 0; i < CHUNK_SIZE; i++){
        for(int j = 0; j < CHUNK_SIZE;){
            char c = fgetc(w->world_snapshot);
            if(c != '\n'){
                w->chunk_map[i][j] = c;
                j++;
            }
        }
    }

    fclose(w->world_snapshot);

    w->chunk_map[current_characterY_position(p)][current_characterX_position(p)] = current_character_skin(p);

}

void print_current_chunk(World *w, char OS){

    if(OS == 'l') system("clear");
    else if(OS == 'w') system("clr");


    for(int i = 0; i < CHUNK_SIZE; i++){
        for(int j = 0; j < CHUNK_SIZE; j++){
            printf("%c ", w->chunk_map[i][j]);
        }
        if(i == 0) printf("  currentGrid: %d %d", *(w->current_Grid_Y), *(w->current_Grid_X));
        printf("\n");
    }
}



void change_chunk_grid(World *w,int y, int x){
    char File_Name[100];

    *(w->current_Grid_Y) += y;
    *(w->current_Grid_X) += x;

    if(*(w->current_Grid_Y) > w->world_size - 1) *(w->current_Grid_Y) = 0;
    else if(*(w->current_Grid_Y) < 0) *(w->current_Grid_Y) = w->world_size - 1;

    if(*(w->current_Grid_X) > w->world_size - 1) *(w->current_Grid_X) = 0;
    else if(*(w->current_Grid_X) < 0) *(w->current_Grid_X) = w->world_size - 1;

    snprintf(File_Name, sizeof(File_Name), "map[%d][%d].txt", *(w->current_Grid_Y), *(w->current_Grid_X));
    w->world_snapshot = fopen(File_Name, "r");

    for(int i = 0; i < CHUNK_SIZE; i++){
        for(int j = 0; j < CHUNK_SIZE;){
            char c = fgetc(w->world_snapshot);
            if(c != '\n'){
                w->chunk_map[i][j] = c;
                j++;
            }
        }
    }

    fclose(w->world_snapshot);

}

void character_movement(Character *player, World *w){

    switch (current_character_action(player)){
        case 'w':
            if(current_characterY_position(player) - 1 < 0){
                change_chunk_grid(w, -1, 0);
                change_characterY_position(CHUNK_SIZE - 1, player);
            }else{
                if(w->chunk_map[current_characterY_position(player)-1][current_characterX_position(player)] == ' '){
                    w->chunk_map[current_characterY_position(player)][current_characterX_position(player)] = ' ';
                    change_characterY_position(current_characterY_position(player) - 1, player);
                }
            }

            break;

        case 's':
            if(current_characterY_position(player) + 1 > CHUNK_SIZE - 1){
                change_chunk_grid(w, 1, 0);
                change_characterY_position(0, player);
            }else{
                if(w->chunk_map[current_characterY_position(player)+1][current_characterX_position(player)] == ' '){
                    w->chunk_map[current_characterY_position(player)][current_characterX_position(player)] = ' ';
                    change_characterY_position(current_characterY_position(player) + 1, player);
                }
            }

            break;

        case 'a':
            if(current_characterX_position(player) - 1 < 0){
                change_chunk_grid(w, 0, -1);
                change_characterX_position(CHUNK_SIZE - 1, player);
            }else{
                if(w->chunk_map[current_characterY_position(player)][current_characterX_position(player)-1] == ' '){
                    w->chunk_map[current_characterY_position(player)][current_characterX_position(player)] = ' ';
                    change_characterX_position(current_characterX_position(player) - 1, player);
                }
            }

            break;

        case 'd':
            if(current_characterX_position(player) + 1 > CHUNK_SIZE - 1){
                change_chunk_grid(w, 0, 1);
                change_characterX_position(0, player);
            }else{
                if(w->chunk_map[current_characterY_position(player)][current_characterX_position(player)+1] == ' '){
                    w->chunk_map[current_characterY_position(player)][current_characterX_position(player)] = ' ';
                    change_characterX_position(current_characterX_position(player) + 1, player);
                }
            }

            break;

        default:
            return;
    }

    w->chunk_map[current_characterY_position(player)][current_characterX_position(player)] = current_character_skin(player);
}

void destroy_world(World *w){
    free(w->current_Grid_X);
    free(w->current_Grid_Y);

    char file_name[100];

    for(int i = 0; i < w->world_size; i++){
        for(int j = 0; j < w->world_size; j++){
            snprintf(file_name, sizeof(file_name), "map[%d][%d].txt", i, j);
            remove(file_name);
        }
    }

    free(w);
    w = NULL;

}

