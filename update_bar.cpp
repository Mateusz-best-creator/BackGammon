#include "functions_definitions.h"

bool update_bar(char bar[], char player_sign, int row_index)
{
	if (row_index < -1 && player_sign == 'R') { return false; }
	if (row_index > -1 && player_sign == 'B') { return false; }

	int pawns_in_bar = 0;

	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (bar[i] == player_sign) { pawns_in_bar++; }
	}
	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (i < pawns_in_bar - 1) // -1 beacuse we take one pawn from bar to the board
		{
			bar[i] = player_sign;
		}
		else
		{
			bar[i] = '=';
		}
	}

	return true;
}