#include "functions_definitions.h"
#include "conio.h"
#include <iostream>

// Boolean that represents that we are inserting the pawn from the bar
static bool inserting_pawn_from_bar = false;

void not_insert(int& start_column_index, int column_index, Board* table_s, int row_index, char player_sign)
{
	start_column_index = column_index;
	// Update pawns array, delete some element
	table_s->pawns[column_index][row_index] = 'E';

	// Update pawns in the column, so there will be no "gaps" between them
	int pawns_in_column = 0;
	for (int i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (table_s->pawns[column_index][i] == player_sign) { pawns_in_column++; }
	}
	for (int i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (i < pawns_in_column)
		{
			table_s->pawns[column_index][i] = player_sign;
		}
		else
		{
			table_s->pawns[column_index][i] = 'E';
		}
	}
}

void permission(Board* table_s, int column_index, int row_index, char player_sign, bool& inserting_element, bool& inserted,
	Player* player_1, Player* player_2, int& start_column_index, int& background_color)
{
	// First check if a player has a "permission" to move a pawn, if it's not his pawn he can't make a move using it
	if (table_s->pawns[column_index][row_index] == player_sign || inserting_element)
	{

		if (inserting_element)
		{
			inserted = insert_pawn(table_s, column_index, row_index, player_sign,
				player_1, player_2, start_column_index, inserting_pawn_from_bar);
			if (inserted && inserting_pawn_from_bar) { inserting_pawn_from_bar = false; }
		}
		else
		{
			not_insert(start_column_index, column_index, table_s, row_index, player_sign);
		}
		if (inserted)
		{
			// Only if we succesfully inserted the element we want to change the background and "inserted" variable
			inserting_element = !inserting_element;
			background_color = LIGHTGREEN;

			int player_index;
			if (player_sign == 'B') { player_index = 1; }
			else { player_index = 2; }
		}
	}
}

void c_index(int column_index, Board* table_s, int row_index, bool& inserting_element, char player_sign)
{
	if (column_index == -2) // We take the pawn from the bar
	{
		if (player_sign == 'B')
		{
			inserting_element = update_bar(table_s->player_1_bar, player_sign, row_index);
		}
		else
		{
			inserting_element = update_bar(table_s->player_2_bar, player_sign, row_index);
		}
		inserting_pawn_from_bar = true;
		return;
	}
}

void c_remove(Player* player_1, Player* player_2, Board* table_s, char player_sign, bool& took_pawn_from_the_board, int column_index, int row_index)
{
	// Case when we want to remove the pawn from the board
	if ((player_sign == 'B' && player_1->can_take_pawns_from_the_board) ||
		(player_sign == 'R' && player_2->can_take_pawns_from_the_board))
	{
		took_pawn_from_the_board = take_pawn_off_the_board(player_1, player_2, table_s, column_index + 1, row_index, player_sign);
	}
	if (took_pawn_from_the_board)
	{
		if (player_sign == 'B') { player_1->number_of_removed_pawns++; }
		else { player_2->number_of_removed_pawns++; }
		return;
	}
}

void star_greater_15(int& column_index, int& star_x, int& star_y, int& row_index)
{
	// Means we are at the botom of the board
		// Now we need to update the pawn table (description how this formula works will be in the paper)
	column_index = (star_x - 25) / 5;
	row_index = star_y - 18;

	// Get the index of an array where our star is pointing (from 1 - 12, bottom board for now)
	int indexes_on_bottom_board[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	column_index = (column_index > 6)
		? indexes_on_bottom_board[column_index - 1] : indexes_on_bottom_board[column_index];

	if (row_index == 5) { row_index = 0; }
	else if (row_index == 4) { row_index = 1; }
	else if (row_index == 3) { row_index = 2; }
	else if (row_index == 2) { row_index = 3; }
	else if (row_index == 1) { row_index = 4; }
	else if (row_index == 0) { row_index = 5; }
}

void star_smaller_15(int& column_index, int star_x, int star_y, int& row_index)
{
	column_index = (star_x - 25) / 5 + 13;
	row_index = star_y - 9;
	if (star_x > 55) { column_index--; }
}

void cases(Player* player_1, Player* player_2, Board* table_s, char player_sign,
	bool& took_pawn_from_the_board, int column_index, int row_index, bool& inserting_element, int& background_color)
{
	c_remove(player_1, player_2, table_s, player_sign, took_pawn_from_the_board, column_index, row_index);

	bool inserted = true;

	// These two variables will represent column and index from where we moved our pawn
	static int start_column_index = 0;

	c_index(column_index, table_s, row_index, inserting_element, player_sign);

	permission(table_s, column_index, row_index, player_sign, inserting_element, inserted,
		player_1, player_2, start_column_index, background_color);
}

void grab_drop_pawn(Board* table_s, int& star_x, int& star_y,
	char player_sign, bool& inserting_element, int& background_color,
	Player* player_1, Player* player_2)
{
	int column_index, row_index;
	if (star_x == 55) // Case when we want to insert the pawn from the bar to the board
	{
		column_index = -1;
		row_index = star_y - 17;
	}
	else if (star_y > 15)
	{
		star_greater_15(column_index, star_x, star_y, row_index);
	}
	else
	{
		star_smaller_15(column_index, star_x, star_y, row_index);
	}

	// beacuse we index from 0
	column_index--;
	bool took_pawn_from_the_board = false;

	cases(player_1, player_2, table_s, player_sign, took_pawn_from_the_board, column_index, row_index, inserting_element, background_color);
}