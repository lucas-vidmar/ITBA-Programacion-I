#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>

bool init(void); //inicializa
bool setpin (int p, bool state); //cambia el estado de la led, p=pinnumber, state en false apagado
bool output(void); //set as output

#endif

