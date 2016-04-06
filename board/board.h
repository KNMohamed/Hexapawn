#ifndef BOARD_H
#define BOARD_H

#include "../hexapawn.h"

typedef enum pieces{ WHITE, BLACK, SPACE }pieces;
void initBoard(pieces b[ROWS][COLS]);
void printBoard(pieces b[ROWS][COLS]);
int *getPositions(pieces b[ROWS][COLS],int *numOfPieces, pieces colour);
int calculateCOMPMOVE(int *positions);
#endif
