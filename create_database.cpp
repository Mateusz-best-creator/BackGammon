#include "functions_definitions.h"

PlayersDatabase* create_database()
{
	// Initialize two starting players
	Player* player_1 = new Player{ 0, 'B', 1, 0, 0, false, {}, 0, {"Mateusz"} };
	Player* player_2 = new Player{ 0, 'R', 2, 0, 0, false, {}, 0, {"Ola"} };

	// Initialize AI player
	Player* player_AI_1 = new Player{ 0, 'B', 2, 0, 0, false, {}, 0, {"AI1"} };
	Player* player_AI_2 = new Player{ 0, 'R', 2, 0, 0, false, {}, 0, {"AI2"} };

	PlayersDatabase* database = new PlayersDatabase();

	// Add two initial players, later we will be able to add more
	database->players[0] = *player_1;
	database->players[1] = *player_2;
	database->number_of_players = 2;

	// AI bot will be treated differently
	database->players[5] = *player_AI_1;
	database->players[6] = *player_AI_2;

	return database;
}