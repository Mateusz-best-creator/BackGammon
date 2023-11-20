#include <iostream>
#include "conio.h"
#include "functions_definitions.h"

void print_player_interface(int player_index, Player* player_1, Player* player_2)
{
	int dice1, dice2;
	// Display which player now makes a move
	if (player_index == 1)
	{
		textcolor(LIGHTCYAN);
		dice1 = player_1->dice1;
		dice2 = player_1->dice2;
	}
	else
	{
		textcolor(LIGHTRED);
		dice1 = player_2->dice1;
		dice2 = player_2->dice2;
	}
	gotoxy(100, 18);
	std::cout << "Player ";
	gotoxy(107, 18);
	std::cout << player_index;
	gotoxy(108, 18);
	std::cout << " turn";

	textcolor(LIGHTGRAY);
	gotoxy(100, 20);
	std::cout << "You get : " << dice1 << " for first dice and " << dice2 << " for second dice  Sum = " << dice1 + dice2 << std::endl;

	// Display all possible moves that player can perform based on dice1 and dice2
	gotoxy(100, 22);
	std::cout << "Possible moves : ";
	if (dice1 != dice2)
	{
		gotoxy(100, 24);
		std::cout << "\tMove one pawn by " << dice1 + dice2;
		gotoxy(100, 25);
		std::cout << "\tMove two pawns, first by " << dice1 << " Second by " << dice2;
	}
	else
	{
		gotoxy(100, 24);
		std::cout << "\tMove four pawns by " << dice1;
	}

	// Print some instructions what player has to do
	gotoxy(100, 27);
	std::cout << "INSTRUCTIONS : ";
	gotoxy(100, 29);
	std::cout << "\t0. If you finished your move type [F] and then type [P] again to make a move as an another player.";
	gotoxy(100, 30);
	char pawn_symbol;
	if (player_index == 1) { pawn_symbol = 'B'; }
	else { pawn_symbol = 'R'; }
	std::cout << "\t1. Place the cursor ('*') on the field of the pawn (your pawn symbol: ";
	if (player_index == 1) { textcolor(LIGHTCYAN); }
	else { textcolor(LIGHTRED); }
	std::cout << pawn_symbol;
	textcolor(LIGHTGRAY);
	std::cout << ") you want to move.";
	gotoxy(100, 31);
	std::cout << "\t2. Click enter, move the cursor to the field where you want to place the pawn.";
	gotoxy(100, 32);
	std::cout << "\t3. If a move is possible the board will be updated, otherwise you lose your move.";
}