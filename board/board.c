#include "board.h"

void initBoard(pieces b[ROWS][COLS]){
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			switch(i){
				case 0:
					b[i][j] = BLACK;
					break;
				case 1:
					b[i][j] = SPACE;
					break;
				case 2:
					b[i][j] = WHITE;
					break;		
			}
		}
	}
}

void printBoard(pieces b[ROWS][COLS]){
	int i,j;
	printf("+---+---+---+\n");
	for(i = 0; i < 3; i++){
		printf("|");
		for(j = 0; j < 3; j++){
			 switch(b[i][j]){
				case BLACK:
					printf(" B ");
					break;
				case WHITE:
					printf(" W ");
					break;
				case SPACE:
					printf(" . ");
					break;
			}
		printf("|");
		}
		printf("\n");
		printf("+---+---+---+\n");
	}
}

int *getPositions(pieces b[ROWS][COLS], int *numOfPieces, pieces colour){
	int *positions = malloc(sizeof(int)*3);	//Maximum of three pieces
	int position = 1;
	int i,j;
	if(!positions)
		return NULL;	

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(b[i][j] == colour)
				positions[(*numOfPieces)++] = position;
			position++;
		}
	}
	return positions;
}
