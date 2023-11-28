#include "AI.h"
#include <iostream>
#include "conio.h"
#include <thread>
#include <chrono>
// This function will make a move as an AI, if we are unable to make any move, than we return false
void AI2_make_move(Board* table_s, Player* player_AI)
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

	for (int i = NUMBER_OF_COLUMNS - 1; i >= 0; i--)
	{
		for (int j = NUMBER_OF_ROWS_IN_COLUMN - 1; j >= 0; j--)
		{
			/*
				Checks whether or not we are able to take pawn out of the board
			*/
			AI2_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1 + player_AI->dice2, AI_pawn_char);
			AI2_insert_pawn_from_bar(table_s, player_AI, player_AI->dice1, AI_pawn_char);
			AI2_insert_pawn_from_bar(table_s, player_AI, player_AI->dice2, AI_pawn_char);

			if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return; }

			// Update dice_sum variable
			dice_sum = player_AI->dice1 + player_AI->dice2;

			if (check_if_all_pawns_in_home(table_s, 'R'))
			{
				AI2_take_pawns_off_the_board(table_s, player_AI, AI_pawn_char);
				if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return; }
			}
			AI2_move_pawn(table_s, player_AI, i, j, dice_sum, AI_pawn_char);
		}
	}
}