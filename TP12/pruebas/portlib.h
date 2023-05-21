#ifndef PORTLIB_H
#define PORTLIB_H

enum{PORTA,PORTB,PORTD};

void bitSet(int bit, int puerto);
void bitClr(int bit, int puerto);
int bitGet(int bit, int puerto);
void bitToggle(int bit, int puerto);
void maskOn(int puerto, int mask);
void maskOff(int puerto, int mask);
void maskToggle(int puerto, int mask);

#endif



