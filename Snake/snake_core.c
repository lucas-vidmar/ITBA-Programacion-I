/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake_core.h"


/*Esta funcion inicializa la estructura de la serpiente. Devuelve un puntero a la estructura si se pudo realizar. De lo contrario, devuelve NULL.*/
snake_core_vars_t* init_snake_struct(){
    snake_core_vars_t* snake_core_vars = (snake_core_vars_t*) malloc(sizeof(snake_core_vars_t));
    if (snake_core_vars == NULL){
        fprintf(stderr,"Error, can't allocate memory");
        return NULL;     
    }
    
    //NEED TO INITIALIZE SNAKE BODY POSITION.***************************************************************************************
    
    snake_core_vars->snake_body[0].x_coord = 8;
    snake_core_vars->snake_body[0].y_coord = 3;
    snake_core_vars->snake_body[1].x_coord = 8;
    snake_core_vars->snake_body[1].y_coord = 2;
    snake_core_vars->snake_body[2].x_coord = 8;
    snake_core_vars->snake_body[2].y_coord = 1;
    
    //***************************
    snake_core_vars->snake_length = INIT_LENGTH;
    snake_core_vars->food[X_COORD] = UNKNOWN;
    snake_core_vars->food[Y_COORD] = UNKNOWN;
    snake_core_vars->game_status = PLAY;
    snake_core_vars->grow_up = 0;
    snake_core_vars->lives = LIVES;
    snake_core_vars->level = UNKNOWN;
    snake_core_vars->game_height = GAME_HEIGHT;
    snake_core_vars->game_width = GAME_WIDTH;
    snake_core_vars->speed = UNKNOWN;
    snake_core_vars->snake_dir = LOGIC_KEY_DOWN;
    snake_core_vars->effective_dir = LOGIC_KEY_DOWN;
    snake_core_vars->score = UNKNOWN;
    
    //NEED TO INITIALIZE HIGHESTSCORES.***********************************************************************************************
    
    
    return snake_core_vars;
}

/*Libera la memoria dinamica.*/
void destroy_snake_struct(snake_core_vars_t* snake_core_vars){
    free(snake_core_vars);
}

/*Evalua si la direccion presionada es valida*/
void handle_game_key_press(snake_core_vars_t* snake_core_vars , int key){
    if (snake_core_vars->game_status == PLAY){ // is the game playing?
        if ( (key+2)%4 != snake_core_vars->effective_dir ){ // check if key pressed represent the opposed direction
            printf("effective");
            
            snake_core_vars->snake_dir = key;
        }
    }
}


/*Evalua la direccion de moviemiento y modifica la posicion de la serpiente.*/
void calculate_newPos(snake_core_vars_t* snake_core_vars){
  
    int move, k, length;
    int x_head, y_head;
    
    x_head = snake_core_vars->snake_body[HEAD].x_coord; //obtiene las coordenadas de la cabeza de la serpiente para despues reubicarla segun a donde se mueva.
    y_head = snake_core_vars->snake_body[HEAD].y_coord;
    
    move = snake_core_vars->snake_dir;
    snake_core_vars->effective_dir = snake_core_vars->snake_dir;
    
    /*Dependiendo a que direccion se mueve, incrementa/decrementa los valores de las coordenadas x/y.
     Considerar que las coordenadas pueden ser negativas o exceder el maximo del ancho o alto del juego.
     Esto luego se va a evaluar para determinar si se choco con los bordes */
    switch(move){ 
        case LOGIC_KEY_UP:
            y_head --;
        break;
        case LOGIC_KEY_DOWN:
            y_head ++;
        break;
        case LOGIC_KEY_LEFT:
            x_head --;
        break;
        case LOGIC_KEY_RIGHT:
            x_head ++;
        break;
    }
    
    length = snake_core_vars->snake_length;
    
    int bottom_x = snake_core_vars->snake_body[length-1].x_coord;
    int bottom_y = snake_core_vars->snake_body[length-1].y_coord;
    
    for(k = length-1; k > 0; k--){ // shift all positions
        snake_core_vars->snake_body[k].x_coord = snake_core_vars->snake_body[k-1].x_coord;
        snake_core_vars->snake_body[k].y_coord = snake_core_vars->snake_body[k-1].y_coord;
    }
    snake_core_vars->snake_body[HEAD].x_coord = x_head;
    snake_core_vars->snake_body[HEAD].y_coord = y_head;
   
    //HAY QUE EVALUAR SI INCREMENTA LA LONGITUD. **********************************************************************************
    check_food_eaten(snake_core_vars);
    if(snake_core_vars->grow_up != 0){
        snake_core_vars->snake_length ++;
        snake_core_vars->snake_body[length].x_coord = bottom_x;
        snake_core_vars->snake_body[length].y_coord = bottom_y;
        snake_core_vars->grow_up = 0;
    }
}

/*Calcula de forma aleatoria la posicion de la comida*/
void set_food(snake_core_vars_t* snake_core_vars){
    
    int mat[GAME_HEIGHT][GAME_WIDTH];                   //should be static
    int i , j , k, foodpos;
    int food_x , food_y;
    int length = snake_core_vars->snake_length;
    
    srand(time(NULL));
    
    /*clear matrix*/
    for(i=GAME_HEIGHT-1;i>=0;i--){
        for(j=GAME_WIDTH-1;j>=0;j--){
            mat[i][j]=0;
        }
    }
    
    /*Set snake body positions in the matrix as occupied(1) */
    for(k=length-1;k>=0;k--){
        mat[snake_core_vars->snake_body[k].y_coord][snake_core_vars->snake_body[k].x_coord]=1;
    }
    
    foodpos = rand() % (GAME_HEIGHT*GAME_WIDTH-length);
    
    for(i=0;(i<GAME_HEIGHT)&&foodpos;i++){
        for(j=0;(j<GAME_WIDTH)&&foodpos;j++){
            if(mat[i][j]==0){
                foodpos--;
            }
        }
    }
    ///prestar atencion porque en el test dio x=16 y=16
    
    
    
    if(foodpos==0){
        snake_core_vars->food[X_COORD] = j;
        snake_core_vars->food[Y_COORD] = i;
        printf("x=%d\n",i);
        printf("y=%d\n",j);
    }
    else{
        printf("Players wins.\nWait, what? That's impossible!\n");
        //DECIDE WHAT TO DO HERE.***********************************************************************************************************
    }
 
}


/*Evalua si llego a la comida*/
void check_food_eaten(snake_core_vars_t* snake_core_vars){
    
    if((snake_core_vars->snake_body[HEAD].x_coord==snake_core_vars->food[X_COORD])&&(snake_core_vars->snake_body[HEAD].y_coord==snake_core_vars->food[Y_COORD])){
        snake_core_vars->grow_up = 1;
        set_food(snake_core_vars);
    }
    
}


/*Evalua si se choco con alguna pared o si se mordio a si mismo*/
int check_collision(snake_core_vars_t* snake_core_vars){
   
    int i;
    
    int length = snake_core_vars->snake_length;
    
    if((snake_core_vars->snake_body[HEAD].x_coord<0)||(snake_core_vars->snake_body[HEAD].x_coord>=GAME_WIDTH)||(snake_core_vars->snake_body[HEAD].y_coord<0)||(snake_core_vars->snake_body[HEAD].y_coord>=GAME_HEIGHT)){
        return COLLISION;
    }
    else{
        for(i = 1; i < length; i++){
            if((snake_core_vars->snake_body[HEAD].x_coord==(snake_core_vars->snake_body[i].x_coord))&&(snake_core_vars->snake_body[HEAD].y_coord==(snake_core_vars->snake_body[i].y_coord))){
                return COLLISION;
            }

        }
    }
    return NO_COLLISION;
}


