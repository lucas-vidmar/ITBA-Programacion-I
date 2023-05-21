#ifndef SNAKE_CORE_H
#define SNAKE_CORE_H

#include <stdint.h>

#define HEAD 0
#define X_COORD 0
#define Y_COORD 1

#define HIGHESTSCORES_FILE "highestscore.txt"

#define INIT_LENGTH 3
#define MAX_LENGTH (16*16)


#define XY_AXIS 2
#define LIVES 1

#define UNKNOWN -1

#define CANT_LEVELS 3
#define GAME_HEIGHT 16
#define GAME_WIDTH 16


enum collision_state {COLLISION , NO_COLLISION};

enum keys {LOGIC_KEY_UP , LOGIC_KEY_RIGHT , LOGIC_KEY_DOWN , LOGIC_KEY_LEFT};

enum state {START , INIT_MENU , PLAY , PAUSE , GAME_OVER , QUIT};




typedef struct{
    uint8_t x_coord;
    uint8_t y_coord;
}snake_body_t;

/*
 This structure is used to manage the information needed in the game.
 */

typedef struct { 
    
    snake_body_t snake_body[MAX_LENGTH];
    unsigned int snake_length; 
    int food[XY_AXIS];
    int game_status;
    int lives; 
    int level; 
    int grow_up;
    
    int game_height;
    int game_width;
    double speed; 
    int snake_dir;
    int effective_dir;
    
    int score; 
    int highestscores[CANT_LEVELS]; 

    
    
    double time_ref; 
    double call_time;
    
}snake_core_vars_t;


/*Esta funcion inicializa la estructura de la serpiente. Devuelve un puntero a la estructura si se pudo realizar. De lo contrario, devuelve NULL.*/
snake_core_vars_t* init_snake_struct();

/*Libera la memoria dinamica.*/
void destroy_snake_struct(snake_core_vars_t* snake_core_vars);

/*Evalua si la direccion presionada es valida*/
void handle_game_key_press(snake_core_vars_t* snake_core_vars , int key);

/*Evalua la direccion de moviemiento y modifica la posicion de la serpiente.*/
void calculate_newPos(snake_core_vars_t* snake_core_vars);

/*Calcula de forma aleatoria la posicion de la comida*/
void set_food(snake_core_vars_t* snake_core_vars);

/*Evalua si llego a la comida*/
void check_food_eaten(snake_core_vars_t* snake_core_vars);

/*Evalua si se choco con alguna pared o si se mordio a si mismo*/
int check_collision(snake_core_vars_t* snake_core_vars);





#endif /* SNAKE_CORE_H */

