#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define MAXCOL 50
#define MAXFIL 100


int evaluate(char[MAXFIL][MAXCOL], int, int, int, int);
int request(void);
void generate(char[MAXFIL][MAXCOL], int);
void print(char mat [MAXFIL][MAXCOL],int, int);
void miscellaneous(void);
void nxtgeneration(char[MAXFIL][MAXCOL],int ,int);
void generationleap(char[MAXFIL][MAXCOL],char[MAXFIL][MAXCOL] ,int ,int);

#endif
