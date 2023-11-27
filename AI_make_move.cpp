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
	
	/*
	gotoxy(1, 4);
	std::cout << player_AI->dice1 << " " << player_AI->dice2;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	*/
	
	const char AI_pawn_char = 'R';

	bool inserted = false;

	for (int i = NUMBER_OF_COLUMNS - 1; i >= 0; i--)
	{
		for (int j = NUMBER_OF_ROWS_IN_COLUMN - 1; j >= 0; j--)
		{	
			/*
				Checks whether or not we are able to take pawn out of the board
			*/
			AI_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1 + player_AI->dice2, AI_pawn_char);
			AI_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1, AI_pawn_char);
			AI_insert_pawn_from_bar(table_s, player_AI, player_AI->dice2, AI_pawn_char);

			if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return true; }

			// Update dice variables
			dice1 = player_AI->dice1;
			dice2 = player_AI->dice2;
			dice_sum = player_AI->dice1 + player_AI->dice2;

			if (check_if_all_pawns_in_home(table_s, 'R'))
			{
				if (player_AI->dice1 != 0)
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
							// After we removed one pawn we want to break from loop
							break;
						}
					}
				}
				if (player_AI->dice2 != 0)
				{
					int column_index = NUMBER_OF_COLUMNS - dice2;
					for (int row = NUMBER_OF_ROWS_IN_COLUMN - 1; row >= 0; row--)
					{
						if (table_s->pawns[column_index][row] == AI_pawn_char)
						{
							table_s->pawns[column_index][row] = 'E';
							player_AI->removed_pawns[player_AI->number_of_removed_pawns] = 'R';
							player_AI->number_of_removed_pawns++;
							player_AI->dice2 = 0;
							// After we removed one pawn we want to break from loop
							break;
						}
					}
				}
				if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return true; }
			}
			/*
				Here we want to move the pawn which is the closest to the home by dice_sum if possible.
			*/
			else if (table_s->pawns[i][j] == AI_pawn_char && i + dice_sum < NUMBER_OF_COLUMNS && dice_sum != 0)
			{
				inserted = check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice_sum);
				if (inserted)
				{
					player_AI->dice1 = 0;
					player_AI->dice2 = 0;
					return true;
				}
			}
			/*
				Here we want to move the pawn which are closest to the home by dice1 if possible
			*/
			else if (table_s->pawns[i][j] == AI_pawn_char && i + player_AI->dice1 < NUMBER_OF_COLUMNS && player_AI->dice1 != 0)
			{
				inserted = check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice1);
				if (inserted)
				{
					player_AI->dice1 = 0;
					continue;
				}
			}
			else if (table_s->pawns[i][j] == AI_pawn_char && i + player_AI->dice2 < NUMBER_OF_COLUMNS && player_AI->dice2 != 0)
			{
				inserted = check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice2);
				if (inserted)
				{
					player_AI->dice2 = 0;
					continue;
				}
			}
		}
	}
	// If we were unable to make any move than we have to return false 
	return false;
}