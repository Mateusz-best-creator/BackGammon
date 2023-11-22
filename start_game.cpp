#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void start_game()
{
	int zn = 0;

	// This variable will indicate if user entered [P] to play for the first time
	bool first_time = true;

	// Initialize the board with default pawn places
	Board* table = new Board();
	initialize_table(table);

	// Initialize both players
	Player* player_1 = new Player{ 0, 'B', 1, 0, 0, false, {}, 0 };
	Player* player_2 = new Player{ 0, 'R', 2, 0, 0, false, {}, 0 };

	// This index will keep track which player now makes a move
	int player_index = 1;

	// Clear and close the file
	FILE* file;
	fopen_s(&file, "state_of_the_game_readable.txt", "w");
	fclose(file);
	// Print initial state of the game
	write_to_file(table->table);

	bool stop_playing = false;

	do
	{
		print_table(table);
		print_top_interface(player_1, player_2, false);
		zn = getch();

		if (zn == 'C')
		{
			table->color++;
			if (table->color > 15)
			{
				table->color = 0;
			}
		}
		else if (zn == 'P')
		{
			// If player typed "P" we will start a game in a loop
			do
			{
				clrscr();

				// Print who start the game
				if (first_time)
				{
					first_time = false;
					print_which_player_begins(player_index);
				}

				stop_playing = play(player_1, player_2, table, player_index);
				// Change player_index
				if (player_index == 1) { player_index = 2; }
				else { player_index = 1; }

				// Print state of the game to the file
				write_to_file(table->table);
			} while (!stop_playing);

		}
	} while (zn != 'Q' && zn != 'q');

	_setcursortype(_NORMALCURSOR);	// show the cursor so it will be visible after the program ends

	// After the game free the memory to avoid memory leaks
	delete table;

	// After the game free the memory
	delete player_1;
	delete player_2;
}