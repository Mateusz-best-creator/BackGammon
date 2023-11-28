#include "AI.h"
#include "conio.h"
#include "board.h"

void AI2_insert_pawn_from_bar(Board* table_s, Player* player_AI, int dice_value, char AI_pawn_char)
{
	if (player_AI->dice1 == 0 && player_AI->dice2 == 0) { return; }
	dice_value--; // We subtract 1 beacuse we index column from 0!
	int player_AI_pawns_on_bar = 0;
	for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (table_s->player_2_bar[i] == AI_pawn_char) { player_AI_pawns_on_bar++; }
	}
	// Moving the pawn from the bar to the board
	if (player_AI_pawns_on_bar > 0)
	{
		if (table_s->pawns[dice_value][0] == 'E' || (table_s->pawns[dice_value][0] == AI_pawn_char &&
			table_s->pawns[dice_value][NUMBER_OF_ROWS_IN_COLUMN - 1] != AI_pawn_char))
		{
			for (size_t i = 0; i < NUMBER_OF_ROWS_IN_COLUMN - 1; ++i)
			{
				if (table_s->pawns[dice_value][i] == 'E')
				{
					table_s->pawns[dice_value][i] = AI_pawn_char;
					if (dice_value == player_AI->dice1 + player_AI->dice2) { player_AI->dice1 = 0; player_AI->dice2 = 0; }
					else if (dice_value == player_AI->dice1) { player_AI->dice1 = 0; }
					else if (dice_value == player_AI->dice2) { player_AI->dice2 = 0; }
					table_s->player_2_bar[player_AI_pawns_on_bar - 1] = 'E';
					player_AI_pawns_on_bar--;
					break;
				}
			}
		}
		print_table(table_s);
	}
}