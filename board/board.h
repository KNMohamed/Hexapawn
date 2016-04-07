#ifndef BOARD_H
#define BOARD_H

#include "../hexapawn.h"

typedef enum pieces{ WHITE, BLACK, SPACE }pieces;

/***********
*Initialize the board
***********/
void initBoard(pieces b[ROWS][COLS]);

/***********
*Print current board orientation
************/
void printBoard(pieces b[ROWS][COLS]);

/**************
*Get Number of Alive pieces and their places on the board for a respective player
**************/
int *getPositions(pieces b[ROWS][COLS],int *numOfPieces, pieces colour);

/**************
*Get Vacant locations for black AI player
*Count is a reference to the number of spots
**************/
int *getVacantLocations(pieces b[ROWS][COLS], int *count, int position);

/*********
*Generate random number 1-9 
**********/
int randNumber();

#endif
