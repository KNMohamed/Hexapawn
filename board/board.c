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

/*int calculateCOMPMOVE(pieces b[ROWS][COLS], int *positions, int numOfPositions){
	bool canMove = false;
	int currentPos;
	int i,j;
	for(i = 0; i < numOfPositions; i++){
		currentPos = positions[i];
		case(currentPos){
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:

		}
	}
}*/

int *getVacantLocations(pieces b[ROWS][COLS], int *count, int position){
	int *neighbors = malloc(sizeof(int)*3); //3 possible moves going forward	
	switch(position){
		case 1:
		case 2:
		case 3:
			if(position + 2 > 3)					//Check Diagonal left Availability
				if(b[1][(position + 2)%4] == SPACE)
					neighbors[(*count)++] = position + 2;
			if(b[1][(position+3)%4] == SPACE)		//Check Middle Availability
				neighbors[(*count)++] = position + 3;
			if(position + 4 < 7)					//Check Diagonal Right Availability 
				if(b[1][(position+4)%4] == SPACE)
					neighbors[(*count)++] = position + 4;
			break;
		case 4:
		case 5:
		case 6:
			if(position + 2 > 6)					//Check Diagonal left Availability
				if(b[2][(position + 2)%7] == SPACE)
					neighbors[(*count)++] = position + 2;
			if(b[2][(position+3)%7] == SPACE)		//Check Middle Availability
				neighbors[(*count)++] = position + 3;
			if(position + 4 < 10)					//Check Diagonal Right Availability 
				if(b[2][(position+4)%7] == SPACE)
					neighbors[(*count)++] = position + 4;
			break;			
	}
	return neighbors;
}

int randNumber(){
	int randomNum;
	srand(time(NULL));
	randomNum = (rand() % 9) + 1;
	return randomNum;
}
