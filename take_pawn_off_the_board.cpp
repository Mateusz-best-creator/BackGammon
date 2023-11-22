#include "functions_definitions.h"
#include "conio.h"
#include <iostream>

void update_player_removed_paws(Player* player, Board* table_s, int column_index, int row_index)
{
	player->removed_pawns[player->number_of_removed_pawns] = player->pawn_char;
	player->number_of_removed_pawns++;

	table_s->pawns[column_index - 1][0] = 'E';
	int how_many_pawns_in_column = 0;
	for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (table_s->pawns[column_index][i] == player->pawn_char) { how_many_pawns_in_column++; }
	}
	for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (i < how_many_pawns_in_column)
		{
			table_s->pawns[column_index][i] = player->pawn_char;
		}
		else { table_s->pawns[column_index][i] = 'E'; }
	}
}

void remove_pawn(Player* player, Board* table_s, int column_index, int row_index)
{
	if (column_index == player->dice1)
	{
		player->dice1 = 0;
		update_player_removed_paws(player, table_s, column_index, row_index);
	}
	if (column_index == player->dice2)
	{
		player->dice2 = 0;
		update_player_removed_paws(player, table_s, column_index, row_index);
		return;
	}
}

bool take_pawn_off_the_board(Player* player_1, Player* player_2, Board* table_s,
	int column_index, int row_index, char player_sign)
{
	if (player_sign == 'B' && player_1->can_take_pawns_from_the_board)
	{
		remove_pawn(player_1, table_s, column_index, row_index);
		return true;
	}
	else if (player_sign == 'R' && player_2->can_take_pawns_from_the_board)
	{
		remove_pawn(player_2, table_s, column_index, row_index);
		return true;
	}
	return false;
}

