#include "AI.h"
#include <iostream>
#include "conio.h"

bool ch1(Player* p, Board* t, char& c)
{
	p->can_take_pawns_from_the_board = true;
	AI1_take_pawns_off_the_board(t, p, c);
	if (p->dice1 == 0 && p->dice2 == 0)
		return true;
	return false;
}

// This function will make a move as an AI, if we are unable to make any move, than we return false
void AI1_make_move(Board* t, Player* p)
{
	int d1, d2;
	get_random_numbers(&d1, &d2);
	int ds = d1 + d2;
	p->dice1 = d1;
	p->dice2 = d2;

	char c = p->pawn_char;

	for (int i = N_COLUMNS - 1; i >= 0; i--)
	{
		for (int j = NUMBER_OF_ROWS_IN_COLUMN - 1; j >= 0; j--)
		{
			/*
				Checks whether or not we are able to take pawn out of the board
			*/
			AI1_insert_pawn_from_bar(t, p, p->dice1 + p->dice2, c);
			AI1_insert_pawn_from_bar(t, p, p->dice1, c);
			AI1_insert_pawn_from_bar(t, p, p->dice2, c);

			if (p->dice1 == 0 && p->dice2 == 0) { return; }

			// Update dice_sum variable
			ds = p->dice1 + p->dice2;

			if (check_if_all_pawns_in_home(t, 'B'))
			{
				if (ch1(p, t, c))
					return;
			}
			else
			{
				p->can_take_pawns_from_the_board = false;
			}
			AI1_move_pawn(t, p, i, j, ds, c);
		}
	}
}