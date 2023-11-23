#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

// Modules for sleep_for function
#include <thread>
#include <chrono>

void add_player_to_database(PlayersDatabase* database)
{
	clrscr();
	// Check if we are able to add the player
	if (database->number_of_players == MAX_NUMBER_OF_PLAYERS)
	{
		gotoxy(1, 1);
		std::cout << "Sorry, but we can't add another player.";
		std::cout << "\nMaximum number of players = " << MAX_NUMBER_OF_PLAYERS << " going back...";
		// Sleep for 2 seconds
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return;
	}

	gotoxy(1, 1);
	std::cout << "Give the length of the name: ";
	int length;
	length = getche();
	length -= 48;
	
	gotoxy(1, 2);
	std::cout << "Give the name for a player ";

	// Dynamically initialize the array of chars + 1 for '\0' character
	char* name = new char[length + 1];
	int zn;
	for (size_t i = 0; i < length; ++i)
	{
		zn = getche();
		name[i] = zn;
	}
	name[length] = '\0';

	// Now create a brand new player
	Player* new_player = new Player{ 0, 'R', 2, 0, 0, false, {}, 0, name };

	// Add player to a database
	database->players[database->number_of_players] = *new_player;
	database->number_of_players++;
}