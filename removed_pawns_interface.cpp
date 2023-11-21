#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

void print_removed_pawns(char pawn_char, char removed_pawns[], int number_of_removed_pawns)
{
	if (pawn_char == 'B') { textcolor(LIGHTCYAN); }
	else { textcolor(LIGHTRED); }
	for (int i = 0; i < number_of_removed_pawns; ++i)
	{
		std::cout << pawn_char << " ";
	}
	textcolor(LIGHTGRAY);
}

void print_removed_pawns_interface(Player* player_1, Player* player_2)
{
	int player_1_removed_pawns = player_1->number_of_removed_pawns;
	int player_2_removed_pawns = player_2->number_of_removed_pawns;

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 40);
	std::cout << "Player 1 removed pawns : ";
	print_removed_pawns(player_1->pawn_char, player_1->removed_pawns, player_1_removed_pawns);

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 42);
	std::cout << "Player 2 removed pawns : ";
	print_removed_pawns(player_2->pawn_char, player_2->removed_pawns, player_2_removed_pawns);
}