#include <iostream>
#include "functions_definitions.h"
#include "conio.h"



bool check_if_all_pawns_in_home(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN], int player_index)
{
	for (int i = 0; i < NUMBER_OF_COLUMNS; ++i)
	{
		for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
		{
			if (player_index == 1)
			{
				if (pawns[i][j] == 'B' && i >= 6)
				{
					return false;
				}
			}
			else
			{
				if (pawns[i][j] == 'R' && i <= 17)
				{
					return false;
				}
			}
		}
	}

	return true;
}