#include "functions_definitions.h"
#include <iostream>
#include "conio.h"
#include <thread>
#include <chrono>
// This function will make a move as an AI, if we are unable to make any move, than we return false
bool AI_make_move(Board* table_s, Player* player_AI)
{
	int dice1, dice2;
	get_random_numbers(&dice1, &dice2);
	int dice_sum = dice1 + dice2;
	player_AI->dice1 = dice1;
	player_AI->dice2 = dice2;

	gotoxy(1, 4);
	std::cout << dice1 << " " << dice2;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	const char AI_pawn_char = 'R';

	bool inserted = false;

	for (int i = NUMBER_OF_COLUMNS - 1; i >= 0; --i)
	{
		// Update dice variables
		dice1 = player_AI->dice1;
		dice2 = player_AI->dice2;
		dice_sum = player_AI->dice1 + player_AI->dice2;

		for (int j = NUMBER_OF_ROWS_IN_COLUMN - 1; j >= 0; j--)
		{
			if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return true; }
			/*
				Checks whether or not we are able to take pawn out of the board
			*/
			if (check_if_all_pawns_in_home(table_s, AI_pawn_char))
			{
				if (dice1 != 0)
				{
					int column_index = NUMBER_OF_COLUMNS - dice1;
					for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
					{
						if (table_s->pawns[column_index][row] == AI_pawn_char)
						{
							table_s->pawns[column_index][row] = 'E';
							player_AI->removed_pawns[player_AI->number_of_removed_pawns] = 'R';
							player_AI->number_of_removed_pawns++;
							player_AI->dice1 = 0;
							break;
						}
					}
				}
				if (dice2 != 0)
				{
					int column_index = NUMBER_OF_COLUMNS - dice2;
					for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
					{
						if (table_s->pawns[column_index][row] == AI_pawn_char)
						{
							table_s->pawns[column_index][row] = 'E';
							player_AI->removed_pawns[player_AI->number_of_removed_pawns] = 'R';
							player_AI->number_of_removed_pawns++;
							player_AI->dice2;
							break;
						}
					}
				}
			}
			/*
				Here we want to move the pawn which is the closest to the home by dice_sum if possible.
			*/
			if (table_s->pawns[i][j] == AI_pawn_char && i + dice_sum < NUMBER_OF_COLUMNS && dice_sum != 0)
			{
				inserted = check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice_sum);
				dice1 = 0;
				dice2 = 0;
				dice_sum = 0;
				player_AI->dice1 = 0;
				player_AI->dice2 = 0;
				return true;
			}
			/*
				Here we want to move the pawn which are closest to the home by dice1 if possible
			*/
			else if (table_s->pawns[i][j] == AI_pawn_char && i + dice1 < NUMBER_OF_COLUMNS && dice1 != 0)
			{
				check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice1);
				dice1 = 0;
				player_AI->dice1 = 0;
				break;
			}
			else if (table_s->pawns[i][j] == AI_pawn_char && i + dice2 < NUMBER_OF_COLUMNS && dice2 != 0)
			{
				check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice2);
				dice2 = 0;
				player_AI->dice2 = 0;
				break;
			}
		}
	}

	// If we were unable to make any move than we have to return false 
	return false;
}