// Noughts And Crosses.c: This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"

#define GRID 9

void Welcome();
void runsTheGame(int turn);
void Board(char underscores[]);
int CheckWinner(char underscores[]);

void main() {

	int turn = 0;

	Welcome();
	runsTheGame(turn);
}

void runsTheGame(int turn) {

	printf("\n\n\n\t\t\t     The Grid     ");
	printf("\n\t\t\t _________________");
	printf("\n\t\t\t|__1__|__2__|__3__|");
	printf("\n\t\t\t|__4__|__5__|__6__|");
	printf("\n\t\t\t|__7__|__8__|__9__|");
	printf("\n\n\n");
	printf("\t\t       Hit any key to begin!");
	char underscores[GRID];
	for (int i = 0; i < 9; i++) {
		underscores[i] = '_';
	}
	while (turn < 9) {
		getchar();
		printf("\nPlayer %d enter your character [X or O] and the grid number you want it to ", (turn % 2) + 1);
		printf("\nEnter your character: ");
		char input = getc(stdin);
		int gridNum = 0;

		if (input == "\n") {
			input = getc(stdin);
		}

		if (input == 'x' || input == 'o') {
			input = toupper(input);
		}

		if (input == 'X' || input == 'O') {
			printf("\nAnd enter the number of the area you want to put it in: ");
			scanf("%d", &gridNum);
			if (gridNum == '\n') {
				scanf("%d", &gridNum);
			}
			
			if (underscores[gridNum - 1] != '_') {
				printf("\nThat space is alreay taken!");
				printf("\nEnter another number: ");
				scanf("%d", &gridNum);
				if (gridNum == '\n') {
					scanf("%d", &gridNum);
				}
				underscores[gridNum - 1] = input;
				system("cls");
			}
			else {
				underscores[gridNum - 1] = input;
				system("cls");
			}
			Board(underscores);
			turn++;
		}
		else {
			printf("\nThat is not a correct character, please enter a valid character.\n");
		}
		if (CheckWinner(underscores) == 1) {
			printf("\nPlayer %d is the winner!", turn % 2);
			break;
		}
		else {
			continue;
		}
	} /* End of while loop*/
	
}
void Welcome() {

	printf("\n\n\t   This is a simple 9 grid game of noughts and crosses.\n\n");
}

void Board(char underscores[]) {

		printf("\n\n\n\t\t\t     The Grid     ");
		printf("\n\t\t\t _________________");
		printf("\n\t\t\t|__%c__|__%c__|__%c__|", underscores[0], underscores[1], underscores[2]);
		printf("\n\t\t\t|__%c__|__%c__|__%c__|", underscores[3], underscores[4], underscores[5]);
		printf("\n\t\t\t|__%c__|__%c__|__%c__|", underscores[6], underscores[7], underscores[8]);
		printf("\n\n\n");
	
}
int CheckWinner(char underscores[]) {

	if (underscores[0] == underscores[1] && underscores[1] == underscores[2] && underscores[0] != '_')
	{
		return 1;
	}
	else if (underscores[3] == underscores[4] && underscores[4] == underscores[5] && underscores[3] != '_')
	{
		return 1;
	}
	else if (underscores[6] == underscores[7] && underscores[7] == underscores[8] && underscores[6] != '_')
	{
		return 1;
	}
	else if (underscores[0] == underscores[3] && underscores[3] == underscores[6] && underscores[0] != '_')
	{
		return 1;
	}
	else if (underscores[1] == underscores[4] && underscores[4] == underscores[7] && underscores[4] != '_')
	{
		return 1;
	}
	else if (underscores[2] == underscores[5] && underscores[5] == underscores[8] && underscores[2] != '_')
	{
		return 1;
	}
	else if (underscores[0] == underscores[4] && underscores[4] == underscores[8] && underscores[0] != '_')
	{
		return 1;
	}
	else if (underscores[2] == underscores[4] && underscores[4] == underscores[6] && underscores[2] != '_')
	{
		return 1;
	}
	
	
	else {
		
		return 0;
	
	}
}
