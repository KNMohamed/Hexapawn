#include "hexapawn.h"
#include "board/board.h"

int main(){
	pieces board[3][3];
	pieces chosen_piece;
	bool isTurn = false;	//White = 0, Black = 1

	displayInstruction();	
	initBoard(board);

	while(1){
		int *positions;
		int *neighbors;
		int numberOfNeighbors = 0;
		int numberOfPieces = 0;
		int i;
		printf("The Current Board:\n");
		printBoard(board);
		if(isTurn){
			positions = getPositions(board,&numberOfPieces,WHITE);		
		}else{
			positions = getPositions(board,&numberOfPieces,BLACK);
			neighbors = getVacantLocations(board,&numberOfNeighbors,6);
			free(neighbors);
		}
		free(positions);
		break;
	}
	return 0;
}

void displayInstruction(){
	printf("THIS PROGRAM PLAYS THE GAME OF HEXAPAWN\n");
	printf("HEXAPAWN IS PLAYED WITH CHESS PAWNS ON A 3X3 BOARD\n");
	printf("ENTER A NUMBER CORRESPONDING WITH A PIECE YOU WOULD LIKE TO MOVE\n");
	printf("AND THEN ENTER A LOCATION TO MOVE TO\n");
	printf("REGULAR RULES OF CHESS APPLY (INCLUDING THE ENPESSANT RULE)\n");
	printf("YOU WILL PLAY AS WHITE AND THE COMPUTER WILL PLAY AS BLACK\n");

	int i,j;
	int counter = 1;
	printf("+---+---+---+\n");
	for(i = 1; i <= 3; i++){
		printf("|");
		for(j = 1; j <= 3; j++){
			printf(" %d ",counter++);
		printf("|");
		}
		printf("\n");
		printf("+---+---+---+\n");
	}
	printf("\n");
}
