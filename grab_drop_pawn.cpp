#include "functions_definitions.h"
#include "conio.h"
#include <iostream>

void grab_drop_pawn(Board* table_s, int& star_x, int& star_y,
	char player_sign, bool& inserting_element, int& background_color)
{
	int column_index, row_index;

	if (star_y > 15)
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
	else
	{
		column_index = (star_x - 25) / 5 + 13;
		row_index = star_y - 9;
		if (star_x > 55) { column_index--; }
	}

	// beacuse we index from 0
	column_index--;

	bool inserted = true;

	// First check if a player has a "permission" to move a pawn
	if (table_s->pawns[column_index][row_index] == player_sign || inserting_element)
	{

		if (inserting_element)
		{
			inserted = insert_pawn(table_s, column_index, row_index, player_sign);
		}
		else
		{
			// Update pawns array, delete some element
			table_s->pawns[column_index][row_index] = 'E';
		}
		if (inserted)
		{
			inserting_element = !inserting_element;
			background_color = LIGHTGREEN;
		}
	}
}