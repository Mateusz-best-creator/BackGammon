#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

void add_player_to_database(PlayersDatabase* database)
{
	clrscr();
	gotoxy(1, 1);
	std::cout << "Give the length of the name: ";
	int length;
	length = getche() - 48;

	gotoxy(1, 2);
	std::cout << "Give name for a player ";

	// Dynamically initialize the array of chars + 1 for '\0' character
	char* name = new char[length + 1];
	std::cin.ignore(); // Ignore the newline character left in the buffer
	std::cin.getline(name, length + 1);

	// Now create a brand new player
	Player* new_player = new Player{ 0, 'R', 2, 0, 0, false, {}, 0, name };

	// Add player to a database
	database->players[database->number_of_players] = *new_player;
	database->number_of_players++;
}