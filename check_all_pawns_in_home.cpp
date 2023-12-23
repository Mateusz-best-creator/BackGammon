#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void check_if_pawns_in_home(Board* table_s, Player* player_1, Player* player_2, char player_sign)
{
	if (check_if_all_pawns_in_home(table_s, player_sign))
	{
		if (player_sign == 'B')
		{
			player_1->can_take_pawns_from_the_board = true;
		}
		else
		{
			player_2->can_take_pawns_from_the_board = true;
		}
	}
	/*
		There may be the case that player was able to take pawns off the board,
		but sth happened and now he is not able to do this
	*/
	else
	{
		if (player_sign == 'B')
		{
			player_1->can_take_pawns_from_the_board = false;
		}
		else
		{
			player_2->can_take_pawns_from_the_board = false;
		}
	}
}

bool check_if_all_pawns_in_home(Board* table_s, char player_sign)
{
	// Check the board itself
	for (int i = 0; i < N_COLUMNS; ++i)
	{
		for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
		{
			if (player_sign == 'B')
			{
				if (table_s->pawns[i][j] == player_sign && i > 5)
				{
					return false;
				}
			}
			else
			{
				if (table_s->pawns[i][j] == player_sign && i < 18)
				{
					return false;
				}
			}
		}
	}

	// Check the bars
	for (size_t i = 0; i < BAR_SIZE; ++i)
	{
		if (player_sign == 'B')
		{
			if (table_s->player_1_bar[i] == player_sign)
			{
				return false;
			}
		}
		else
		{
			if (table_s->player_2_bar[i] == player_sign)
			{
				return false;
			}
		}
	}

	return true;
}