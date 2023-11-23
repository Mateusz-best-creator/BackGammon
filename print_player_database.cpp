#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

void print_players_database(PlayersDatabase* database)
{
	// At the beginning let's clear the screen
	clrscr();

	// Print database interface
	print_database_interface();

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE);
	std::cout << "List of players:";

	// If list is empty we want to give some info to the user
	if (database->number_of_players == 0)
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + 2);
		std::cout << "List is empty";
	}
	// If it's not empty we just print the players data
	else
	{
		int extra_space_between_players = 3;
		for (int i = 0; i < database->number_of_players; ++i)
		{
			gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 2 + extra_space_between_players * i);
			std::cout << "Player " << i + 1 << ":";
			gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 4 + extra_space_between_players * i);
			std::cout << "Player score: " << database->players[i].points;
			gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 5 + extra_space_between_players * i);
			std::cout << "Player name: " << database->players[i].name;
		}
	}
	int zn;
	do
	{
		zn = getch();
		if (zn == 'A')
		{
			add_player_to_database(database);
		}
	} while (zn != 'S');

}