#include "functions_definitions.h"
#include "conio.h"
#include "interfaces.h"

#include <iostream>

void plays(PlayersDatabase* d)
{
	int extra_space_between_players = 3;
	for (int i = 0; i < d->number_of_players; ++i)
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 2 + extra_space_between_players * i);
		std::cout << "Player " << i << ":";
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 4 + extra_space_between_players * i);
		std::cout << "Player score: " << d->players[i].points;
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + (2 * i) + 5 + extra_space_between_players * i);
		std::cout << "Player name: " << d->players[i].name;
	}
}

void bots(PlayersDatabase* database)
{
	gotoxy(1, TOP_LEFT_Y_CORNER_COORDINATE);
	std::cout << "List of AI bots:";
	int space = 0;
	for (size_t i = 1; i < MAX_NUMBER_OF_AI_PLAYERS + 1; i++)
	{
		if (i == 2) { space = 6; }
		gotoxy(1, TOP_LEFT_Y_CORNER_COORDINATE + 2 + space);
		std::cout << "Bot " << i << ": ";
		gotoxy(1, TOP_LEFT_Y_CORNER_COORDINATE + 4 + space);
		std::cout << "Bot score: " << database->players[4 + i].points;
		gotoxy(1, TOP_LEFT_Y_CORNER_COORDINATE + 5 + space);
		std::cout << "Bot name: " << database->players[4 + i].name;
		gotoxy(1, TOP_LEFT_Y_CORNER_COORDINATE + 6 + space);
		std::cout << "Bot id: " << 4 + i; // Bot ids are 5 and 6
	}
}

void print_players_database(PlayersDatabase* d)
{
	// At the beginning let's clear the screen
	clrscr();

	// Print database interface
	print_database_interface();

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE);
	std::cout << "List of players:";

	// If list is empty we want to give some info to the user
	if (d->number_of_players == 0)
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, TOP_LEFT_Y_CORNER_COORDINATE + 2);
		std::cout << "List is empty";
	}
	// If it's not empty we just print the players data
	else
	{
		plays(d);
	}
	bots(d);
}