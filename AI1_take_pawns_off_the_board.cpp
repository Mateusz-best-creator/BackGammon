#include "AI.h"

void AI1_take_pawns_off_the_board(Board* t, Player* p, char c)
{
	if (p->dice1 != 0)
	{
		int column_index = p->dice1 - 1;
		for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
		{
			if (t->pawns[column_index][row] == c)
			{
				t->pawns[column_index][row] = 'E';
				p->removed_pawns[p->number_of_removed_pawns] = p->pawn_char;
				p->number_of_removed_pawns++;
				p->dice1 = 0;
				// After we removed one pawn we want to break from loop
				break;
			}
		}
	}
	if (p->dice2 != 0)
	{
		int column_index = p->dice2 - 1;
		for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
		{
			if (t->pawns[column_index][row] == c)
			{
				t->pawns[column_index][row] = 'E';
				p->removed_pawns[p->number_of_removed_pawns] = p->pawn_char;
				p->number_of_removed_pawns++;
				p->dice2 = 0;
				// After we removed one pawn we want to break from loop
				break;
			}
		}
	}
}

