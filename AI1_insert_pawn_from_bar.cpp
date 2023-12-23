#include "AI.h"
#include "conio.h"
#include "board.h"

void AI1_insert_pawn_from_bar(Board* t, Player* p, int dv, char c)
{
	if (p->dice1 == 0 && p->dice2 == 0) { return; }
	int ppow = 0;
	for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (t->player_1_bar[i] == c) { ppow++; }
	}
	// Moving the pawn from the bar to the board
	if (ppow > 0)
	{
		if (t->pawns[N_COLUMNS - dv][0] == 'E' ||
			(t->pawns[N_COLUMNS - dv][0] == c &&
				t->pawns[N_COLUMNS - dv][NUMBER_OF_ROWS_IN_COLUMN - 1] != c))
		{
			for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN - 1; ++i)
			{
				if (t->pawns[N_COLUMNS - dv][i] == 'E')
				{
					t->pawns[N_COLUMNS - dv][i] = c;
					if (dv == p->dice1 + p->dice2) { p->dice1 = 0; p->dice2 = 0; }
					else if (dv == p->dice1) { p->dice1 = 0; }
					else if (dv == p->dice2) { p->dice2 = 0; }
					t->player_1_bar[ppow - 1] = 'E';
					ppow--;
					break;
				}
			}
		}
		print_table(t);
	}
}