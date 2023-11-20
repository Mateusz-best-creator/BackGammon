#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

/*

*/

void update_bar_pawns(char bar[BAR_SIZE], char player_sign, int pawns_on_bar)
{
	for (int i = 0; i < pawns_on_bar; ++i)
	{
		bar[i] = player_sign;
	}
}

bool insert_pawn(Board* table_s, int column_index, int row_index, const char player_sign)
{
	char enemy_player_sign = (player_sign == 'R') ? 'B' : 'R';

	int player_1_pawns_on_bar = 0;
	int player_2_pawns_on_bar = 0;

	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (table_s->player_1_bar[i] == 'B') { player_1_pawns_on_bar++; }
		if (table_s->player_2_bar[i] == 'R') { player_2_pawns_on_bar++; }
	}

	// Case when the entire column is empty
	if (table_s->pawns[column_index][0] == 'E')
	{
		table_s->pawns[column_index][0] = player_sign;
	}

	// zbicie piona
	else if (table_s->pawns[column_index][0] == enemy_player_sign && table_s->pawns[column_index][1] == 'E')
	{
		table_s->pawns[column_index][0] = player_sign;

		if (enemy_player_sign == 'R')
		{
			player_2_pawns_on_bar++;
			update_bar_pawns(table_s->player_2_bar, 'R', player_2_pawns_on_bar);
		}
		else
		{
			player_1_pawns_on_bar++;
			update_bar_pawns(table_s->player_1_bar, 'B', player_1_pawns_on_bar);
		}
		print_table(table_s); // Show the bar immediately
	}

	// Case when player insert the pawn (the same color)
	else if (table_s->pawns[column_index][0] == player_sign)
	{
		for (int i = 1; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
		{
			if (table_s->pawns[column_index][i] == 'E')
			{
				table_s->pawns[column_index][i] = player_sign;
				break;
			}
		}
	}

	// Case when playe cannot insert the pawn
	else if (table_s->pawns[column_index][0] == enemy_player_sign)
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 30);
		std::cout << "You cannot insert your pawn [" << player_sign << "] in " << column_index + 1 << " column";
		return false; // false will indicate that we were unable to insert the pawn at given position
	}
	return true;
}