#include "AI.h"
#include "board.h"

void count(Board* t, int& player_AI_pawns_on_bar, int& player_2_pawns_on_bar)
{
	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (t->player_1_bar[i] == 'B') { player_AI_pawns_on_bar++; }
		if (t->player_2_bar[i] == 'R') { player_2_pawns_on_bar++; }
	}
}

bool AI1_check_insert_conditions(Board* t, Player* p, int i, int j, const char c, int dv)
{
	int pAIpob = 0;
	int p2pob = 0;

	count(t, pAIpob, p2pob);
	
	// Empty column
	if (t->pawns[i - dv][0] == 'E')
	{
		t->pawns[i][j] = 'E';
		t->pawns[i - dv][0] = c;
		return true;
	}
	// Zbicie piona
	else if (t->pawns[i - dv][0] == 'R' && t->pawns[i - dv][1] == 'E')
	{
		t->pawns[i][j] = 'E';
		t->pawns[i + dv][0] = c;
		t->player_2_bar[p2pob] = 'R';
		p2pob++;
		print_table(t); // Show new bar immediately
		return true;
	}
	// Column is arleady occupied by AI pawns and we are able to insert the pawn
	else if (t->pawns[i - dv][0] == c &&
		t->pawns[i - dv][NUMBER_OF_ROWS_IN_COLUMN - 1] != c) // Case when column is fully occupied
	{
		for (size_t k = 0; k < NUMBER_OF_ROWS_IN_COLUMN; ++k)
		{
			if (t->pawns[i - dv][k] == 'E')
			{
				t->pawns[i - dv][k] = 'B';
				t->pawns[i][j] = 'E';
				return true;
			}
		}
	}

	return false;
}

