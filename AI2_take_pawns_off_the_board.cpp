#include "AI.h"

void AI2_take_pawns_off_the_board(Board* t, Player* p, char c)
{
	int column_index = N_COLUMNS - p->dice2;
	if (p->dice1 != 0)
	{
		for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
		{
			if (t->pawns[column_index][row] == c)
			{
				t->pawns[column_index][row] = 'E';
				p->removed_pawns[p->number_of_removed_pawns] = 'R';
				p->number_of_removed_pawns++;
				p->dice1 = 0;
				// After we removed one pawn we want to break from loop
				break;
			}
		}
	}
	if (p->dice2 != 0)
	{
		for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
		{
			if (t->pawns[column_index][row] == c)
			{
				t->pawns[column_index][row] = 'E';
				p->removed_pawns[p->number_of_removed_pawns] = 'R';
				p->number_of_removed_pawns++;
				p->dice2 = 0;
				// After we removed one pawn we want to break from loop
				break;
			}
		}
	}
}