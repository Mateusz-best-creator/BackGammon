#include "functions_definitions.h"

bool check_if_player_won(Player* player)
{
	if (player->number_of_removed_pawns == NUMBER_OF_PAWNS_FOR_ONE_PLAYER)
	{
		player->points += 1;
		return true;
	}
	return false;
}