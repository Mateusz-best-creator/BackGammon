#include "AI.h"
#include "conio.h"
#include "board.h"

void AI2_insert_pawn_from_bar(Board* t, Player* p, int dv, char c)
{
	if (p->dice1 == 0 && p->dice2 == 0) { return; }
	dv--; // We subtract 1 beacuse we index column from 0!
	int ppob = 0;
	for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (t->player_2_bar[i] == c) { ppob++; }
	}
	// Moving the pawn from the bar to the board
	if (ppob > 0)
	{
		if (t->pawns[dv][0] == 'E' || (t->pawns[dv][0] == c &&
			t->pawns[dv][NUMBER_OF_ROWS_IN_COLUMN - 1] != c))
		{
			for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN - 1; ++i)
			{
				if (t->pawns[dv][i] == 'E')
				{
					t->pawns[dv][i] = c;
					if (dv == p->dice1 + p->dice2) { p->dice1 = 0; p->dice2 = 0; }
					else if (dv == p->dice1) { p->dice1 = 0; }
					else if (dv == p->dice2) { p->dice2 = 0; }
					t->player_2_bar[ppob - 1] = 'E';
					ppob--;
					break;
				}
			}
		}
		print_table(t);
	}
}