#include "functions_definitions.h"
#include "conio.h"

void database_functionality(PlayersDatabase* database)
{
	int zn;
	do
	{
		print_players_database(database);
		zn = getch();
		if (zn == 'A')
		{
			add_player_to_database(database);
		}
		else if (zn == 'D')
		{
			delete_player_from_database(database);
		}
	} while (zn != 'S');
	
	int player_1_index, player_2_index;
	choose_indexes(&player_1_index, &player_2_index);
	start_game(database, &(database->players[player_1_index]), &(database->players[player_2_index]));
}