#include "AI.h"
#include "board.h"


void count2(Board* t, int& p1pob, int& pAIpob)
{
	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (t->player_1_bar[i] == 'B') { p1pob++; }
		if (t->player_2_bar[i] == 'R') { pAIpob++; }
	}
}

bool AI2_check_insert_conditions(Board* t, Player* p, int i, int j, const char c, int dv)
{
	int p1pob = 0;
	int pAIpob = 0;

	count2(t, p1pob, pAIpob);

	// Empty column
	if (t->pawns[i + dv][0] == 'E')
	{
		t->pawns[i][j] = 'E';
		t->pawns[i + dv][0] = c;
		return true;
	}
	// Zbicie piona
	else if (t->pawns[i + dv][0] == 'B' && t->pawns[i + dv][1] == 'E')
	{
		t->pawns[i][j] = 'E';
		t->pawns[i + dv][0] = c;
		t->player_1_bar[p1pob] = 'B';
		p1pob++;
		print_table(t); // Show new bar immediately
		return true;
	}
	// Column is arleady occupied by AI pawns and we are able to insert the pawn
	else if (t->pawns[i + dv][0] == c &&
		t->pawns[i + dv][NUMBER_OF_ROWS_IN_COLUMN - 1] != c) // Case when column is fully occupied
	{
		for (size_t k = 0; k < NUMBER_OF_ROWS_IN_COLUMN; ++k)
		{
			if (t->pawns[i + dv][k] == 'E')
			{
				t->pawns[i + dv][k] = 'R';
				t->pawns[i][j] = 'E';
				return true;
			}
		}
	}

	return false;
}