#include "AI.h"

void remove_1(Board* table_s, int column_index, char AI_pawn_char, Player* player_AI)
{
	for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
	{
		if (table_s->pawns[column_index][row] == AI_pawn_char)
		{
			table_s->pawns[column_index][row] = 'E';
			player_AI->removed_pawns[player_AI->number_of_removed_pawns] = player_AI->pawn_char;
			player_AI->number_of_removed_pawns++;
			player_AI->dice1 = 0;
			break;
		}
	}
}

void AI1_take_pawns_off_the_board(Board* table_s, Player* player_AI, char AI_pawn_char)
{
	if (player_AI->dice1 != 0)
	{
		int column_index = player_AI->dice1 - 1;
		remove_1(table_s, column_index, AI_pawn_char, player_AI);
	}
	if (player_AI->dice2 != 0)
	{
		int column_index = player_AI->dice2 - 1;
		for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
		{
			if (table_s->pawns[column_index][row] == AI_pawn_char)
			{
				table_s->pawns[column_index][row] = 'E';
				player_AI->removed_pawns[player_AI->number_of_removed_pawns] = player_AI->pawn_char;
				player_AI->number_of_removed_pawns++;
				player_AI->dice2 = 0;
				break;
			}
		}
	}
}

