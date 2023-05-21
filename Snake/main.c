#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include "hard_rpi.h"
#include "snake_core.h"

/*
 * 
 */
bool do_exit = false;
bool next= false;
int state;



void * thread1(){
    int key, collision;
    joy_t* joystick = init_hard_rpi();
    state=START;
    snake_core_vars_t* snake_core_vars = init_snake_struct();
    
    turn_on_display();
    
    while(do_exit == false){
        switch(state){
            case START:
                //show logo until botton pressed
                
                refresh_joy(joystick);
                if(joystick->joy_switch == J_PRESS){
                    state=PLAY;
                    set_food(snake_core_vars);
                    
                    turn_off_display();
                    
                    show_snake_display(snake_core_vars);
                    
                }
                
                break;
            case INIT_MENU:
                //select difficulty
                break;
            case PLAY:
                //do all the stuff here
               
                refresh_joy(joystick);
                if(joystick->joy_switch == J_PRESS){
                    state=GAME_OVER;
                }
                
                if((key=process_snake_move(joystick))!= -1){
                     printf("here......\n");
                    handle_game_key_press(snake_core_vars ,key);
                }
                
                if(next==true){
                    calculate_newPos(snake_core_vars);
                    next=false;
                    
                    if((collision=check_collision(snake_core_vars))==COLLISION){
			printf("collision");
                        state=GAME_OVER;
                        turn_on_display();
                    }
                    else{
                        show_snake_display(snake_core_vars);
                    }
                }
                
                
                
                break;
            case PAUSE:
                //can choose to: continue, restart, music on/off, quit
                break;
            case GAME_OVER:
                //show score and highest score
                refresh_joy(joystick);
                if(joystick->joy_switch == J_PRESS){
                    state=QUIT;
                }
                break;
            case QUIT:
                turn_off_display();
                destroy_snake_struct(snake_core_vars);
                destroy_joy_struct(joystick);
                do_exit = true;
                break;
        }
    }
    
}

void * thread2(){
    
    while(do_exit == false){
        printf("timer_on\n");
        usleep(300000);
        next=true;
        
    }
}



int main(void) {

    
    pthread_t tid1 , tid2;
    pthread_create(&tid1,NULL,thread1,NULL);
    pthread_create(&tid2,NULL,thread2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    
}

