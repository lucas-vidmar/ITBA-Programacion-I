/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hard_rpi.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define JOY_THRESHOLD 20     // 10-100 Joystick threshold (sensitivity)
#define JOY_AXES_MIN 1
#define JOY_AXES_MAX 10

joy_t* init_hard_rpi(void){
    
    clrscr();                   		
    joy_init();                 
    display_init();              
    set_joy_axis(JOY_ROTATE);	  
    set_display_axis(NORMAL);	 
    set_joy_direction(J_INV_TRUE,J_INV_TRUE); 
    joy_t* joystick = (joy_t*) malloc(sizeof(joy_t));
    if (joystick == NULL){
        fprintf(stderr,"Error, can't allocate memory");
        return NULL;     
    }
    return joystick;
 
}
void destroy_joy_struct(joy_t* joystick){
    free(joystick);
}

void refresh_joy(joy_t* joystick){
    joystick_update(); 
    joystick->joy_switch = joystick_get_switch_value(); 
    joystick->joy_coord = joystick_get_coord();
}

int process_snake_move(joy_t* joystick){
    
    int x_coord, y_coord;
    
    refresh_joy(joystick); 
    x_coord = joystick->joy_coord.x;
    y_coord = joystick->joy_coord.y;
    
    if((y_coord < JOY_AXES_MAX)&&(y_coord > -JOY_AXES_MAX)&&(x_coord > JOY_THRESHOLD)){
        return LOGIC_KEY_RIGHT;
    }
    else if((y_coord < JOY_AXES_MAX)&&(y_coord > -JOY_AXES_MAX)&&(x_coord < -JOY_THRESHOLD)){
        return LOGIC_KEY_LEFT;
    }
    else if((x_coord < JOY_AXES_MAX)&&(x_coord > -JOY_AXES_MAX)&&(y_coord > JOY_THRESHOLD)){
        return LOGIC_KEY_DOWN;
    }
    else if((x_coord < JOY_AXES_MAX)&&(x_coord > -JOY_AXES_MAX)&&(y_coord < -JOY_THRESHOLD)){
        return LOGIC_KEY_UP;
    }
    else{
        return -1;
        
    }
    
    
}

void show_snake_display(snake_core_vars_t* snake_core_vars){
    display_clear();
    int counter;
    uint8_t x,y;
    
    for(counter=0;counter<(snake_core_vars->snake_length);counter++){
        x = snake_core_vars->snake_body[counter].x_coord;
        y = snake_core_vars->snake_body[counter].y_coord;
        display_write(x , y , D_ON);
        
        
    }
    
    //show food
    display_write(snake_core_vars->food[X_COORD],snake_core_vars->food[Y_COORD],D_ON);
    
    display_update();
    
}

void turn_on_display(void){
    int i,j;
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            display_write(i,j,D_ON);
        }
    }
    display_update();
        
}

void turn_off_display(void){
    int i,j;
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            display_write(i,j,D_OFF);
        }
    }
    display_update();
        
}