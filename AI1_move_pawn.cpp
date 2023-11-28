#include "AI.h"

void AI1_move_pawn(Board* table_s, Player* player_AI, int i, int j, int dice_sum, char AI_pawn_char)
{
	bool inserted = false;
	/*
		Here we want to move the pawn which is the closest to the home by dice_sum if possible.
	*/
	if (i - dice_sum >= 0 && table_s->pawns[i][j] == AI_pawn_char && dice_sum != 0)
	{
		inserted = AI1_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, dice_sum);
		if (inserted)
		{
			player_AI->dice1 = 0;
			player_AI->dice2 = 0;
		}
	}
	/*
		Here we want to move the pawn which are closest to the home by dice1 if possible
	*/
	if (i - player_AI->dice1 >= 0 && table_s->pawns[i][j] == AI_pawn_char && player_AI->dice1 != 0)
	{
		inserted = AI1_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, player_AI->dice1);
		if (inserted)
		{
			player_AI->dice1 = 0;
		}
	}
	if (i - player_AI->dice2 >= 0 && table_s->pawns[i][j] == AI_pawn_char && player_AI->dice2 != 0)
	{
		inserted = AI1_check_insert_conditions(table_s, player_AI, i, j, AI_pawn_char, player_AI->dice2);
		if (inserted)
		{
			player_AI->dice2 = 0;
		}
	}
}