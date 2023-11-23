#include "functions_definitions.h"

PlayersDatabase* create_database()
{
	// Initialize two starting players
	Player* player_1 = new Player{ 0, 'B', 1, 0, 0, false, {}, 0, {"Mateusz"} };
	Player* player_2 = new Player{ 0, 'R', 2, 0, 0, false, {}, 0, {"Ola"} };

	PlayersDatabase* database = new PlayersDatabase();

	// Add two initial players, later we will be able to add more
	database->players[0] = *player_1;
	database->players[1] = *player_2;
	database->number_of_players = 2;
	
	return database;
}