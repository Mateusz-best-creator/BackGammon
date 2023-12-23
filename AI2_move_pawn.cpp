#include "AI.h"

void move_2(Player* player_AI, Board* table_s, char AI_pawn_char, bool& inserted, int i, int j)
{
	/*
		Here we want to move the pawn which are closest to the home by dice1 if possible
	*/
	if (table_s->pawns[i][j] == AI_pawn_char && i + player_AI->dice1 < NUMBER_OF_COLUMNS && player_AI->dice1 != 0)
	{
		inserted = AI2_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, player_AI->dice1);
		if (inserted)
		{
			player_AI->dice1 = 0;
		}
	}
	if (table_s->pawns[i][j] == AI_pawn_char && i + player_AI->dice2 < NUMBER_OF_COLUMNS && player_AI->dice2 != 0)
	{
		inserted = AI2_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, player_AI->dice2);
		if (inserted)
		{
			player_AI->dice2 = 0;
		}
	}
}

void AI2_move_pawn(Board* table_s, Player* player_AI, int i, int j, int dice_sum, char AI_pawn_char)
{
	bool inserted = false;
	/*
		Here we want to move the pawn which is the closest to the home by dice_sum if possible.
	*/
	if (table_s->pawns[i][j] == AI_pawn_char && i + dice_sum < NUMBER_OF_COLUMNS && dice_sum != 0)
	{
		inserted = AI2_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice_sum);
		if (inserted)
		{
			player_AI->dice1 = 0;
			player_AI->dice2 = 0;
		}
	}
	move_2(player_AI, table_s, AI_pawn_char, inserted, i, j);
}