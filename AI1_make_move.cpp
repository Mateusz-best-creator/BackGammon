#include "AI.h"
#include <iostream>
#include "conio.h"

// This function will make a move as an AI, if we are unable to make any move, than we return false
void AI1_make_move(Board* table_s, Player* player_AI)
{
	int dice1, dice2;
	get_random_numbers(&dice1, &dice2);
	int dice_sum = dice1 + dice2;
	player_AI->dice1 = dice1;
	player_AI->dice2 = dice2;

	const char AI_pawn_char = 'B';

	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; j++)
		{
			if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return; }

			// Update dice_sum variable
			dice_sum = player_AI->dice1 + player_AI->dice2;

			if (check_if_all_pawns_in_home(table_s, 'B'))
			{
				AI1_take_pawns_off_the_board(table_s, player_AI, AI_pawn_char);
				if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return; }
			}
			AI1_move_pawn(table_s, player_AI, i, j, dice_sum, AI_pawn_char);
			/*
				Checks whether or not we are able to take pawn out of the board
			*/
			AI1_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1 + player_AI->dice2, AI_pawn_char);
			AI1_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1, AI_pawn_char);
			AI1_insert_pawn_from_bar(table_s, player_AI, player_AI->dice2, AI_pawn_char);
		}
	}
}