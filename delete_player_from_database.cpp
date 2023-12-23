#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

// Modules for sleep_for function
#include <thread>
#include <chrono>

bool min(PlayersDatabase* database)
{
	clrscr();
	if (database->number_of_players == 0)
	{
		gotoxy(1, 1);
		std::cout << "Sorry, but we can't remove another player.";
		std::cout << "\nCurrently we don't have any players inside our database, going back...";
		// Sleep for 2 seconds
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return true;
	}
	return false;
}

void delete_player_from_database(PlayersDatabase* d)
{
	if (min(d))
		return;
	gotoxy(1, 1);
	std::cout << "Give index of a player to be removed: ";
	int index;
	index = getche();
	index -= 48;
	if (index > d->number_of_players || index < 0)
	{
		std::cout << "\nWrong index value, going back...";
		// Sleep for 2 seconds
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return;
	}
	std::cout << "\nRemoving player " << index << "...";

	for (int i = 0; i < d->number_of_players; ++i)
	{
		if (i == index)
		{
			// Found the player, remove and shift others
			for (int j = i; j < d->number_of_players - 1; ++j)
			{
				d->players[j] = d->players[j + 1];
			}

			// Decrement number of players
			d->number_of_players--;
		}
	}
}

