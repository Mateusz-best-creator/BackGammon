#include "functions_definitions.h"
#include "conio.h"

#include <iostream>

// Modules for sleep_for function
#include <thread>
#include <chrono>

void choose_indexes(int* player_1_index, int* player_2_index)
{
	clrscr();
	gotoxy(1, 1);
	std::cout << "Index for player 1: ";
	*player_1_index = getche();
	*player_1_index -= 48;

	std::cout << "\nIndex for player 2: ";
	*player_2_index = getche();
	*player_2_index -= 48;

	gotoxy(1, 3);
	std::cout << "Starting the game...";
	// Sleep for 2 seconds
	std::this_thread::sleep_for(std::chrono::seconds(2));
	clrscr();
}