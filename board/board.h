#ifndef BOARD_H
#define BOARD_H

#include "../hexapawn.h"

typedef struct board{
	char data[3][3];
}board;

char getPiece();
#endif
