#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void check_if_pawns_in_home(Board* table_s, Player* player_1, Player* player_2, char player_sign)
{
	if (check_if_all_pawns_in_home(table_s->pawns, player_sign))
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

bool check_if_all_pawns_in_home(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN], char player_sign)
{
	for (int i = 0; i < NUMBER_OF_COLUMNS; ++i)
	{
		for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
		{
			if (player_sign == 'B')
			{
				if (pawns[i][j] == player_sign && i > 5)
				{
					return false;
				}
			}
			else
			{
				if (pawns[i][j] == player_sign && i <= 17)
				{
					return false;
				}
			}
		}
	}

	return true;
}