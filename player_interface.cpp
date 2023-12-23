#include <iostream>
#include "conio.h"
#include "functions_definitions.h"

void dices(int player_index, int& dice1, int& dice2, Player* player_1, Player* player_2)
{
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
}

void p_moves(int& dice1, int& dice2)
{
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
}

void i_1(int player_index)
{
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
}

void i_2()
{
	std::cout << ") you want to move.";
	gotoxy(100, 31);
	std::cout << "\t2. Click enter, move the cursor to the field where you want to place the pawn.";
	gotoxy(100, 32);
	std::cout << "\t3. If a move is possible the board will be updated, otherwise you lose your move.";
}

void i_3()
{
	gotoxy(100, 33);
	std::cout << "\t4. If you are taking your pawns out of the board and your pawns are at columns";
	gotoxy(100, 34);
	std::cout << "\t   1, 3, 5 and your dices are : 2 and 4, then you have to click [F] and try again,";
	gotoxy(100, 35);
	std::cout << "\t   if you get 2 on at least one dice you can take pawn from column 2 out of the board.";
}

void print_player_interface(int player_index, Player* player_1, Player* player_2)
{
	int dice1 = 0, dice2 = 0;
	dices(player_index, dice1, dice2, player_1, player_2);
	p_moves(dice1, dice2);

	// Print first part of the instructions
	i_1(player_index);
	// Print second part of the instructions
	i_2();
	i_3();
}