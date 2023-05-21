#ifndef HARD_RPI_H
#define HARD_RPI_H

#include "snake_core.h"
#include "disdrv.h"
#include "joydrv.h"
#include "termlib.h"
typedef struct {
    jcoord_t joy_coord; // Joy Coordenates
    jswitch_t joy_switch; // Joy Switch

} joy_t;

joy_t* init_hard_rpi(void);
void destroy_joy_struct(joy_t* joystick);
void refresh_joy(joy_t* joystick);
int process_snake_move(joy_t* joystick);
void show_snake_display(snake_core_vars_t* snake_core_vars);
void turn_on_display(void);
void turn_off_display(void);



#endif /* HARD_RPI_H */

