#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void start_game(PlayersDatabase* database, Player* player_1, Player* player_2)
{
	// We need to do some preprocessing
	player_1->pawn_char = 'B';
	player_2->pawn_char = 'R';
	player_1->player_index = 1;
	player_2->player_index = 2;

	int zn = 0;

	// This variable will indicate if user entered [P] to play for the first time
	bool first_time = true;

	// Initialize the board with default pawn places
	Board* table = new Board();
	initialize_table(table);

	// This index will keep track which player now makes a move
	int player_index = 1;

	// Print initial state of the game
	write_to_file(table->table);

	// This boolean value will indicate if we want to stop the game
	bool stop_playing = false;

	// This value will indicate if we want to start a new game
	bool start_a_new_game = false;

	// This boolean value will indicate whether or not we want to go to our database interface
	bool go_to_database;

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

				stop_playing = play(player_1, player_2, table, player_index, start_a_new_game);
				// Change player_index
				if (player_index == 1) { player_index = 2; }
				else { player_index = 1; }

				// Print state of the game to the file
				write_to_file(table->table);
			} while (!stop_playing);
		}

		else if (zn == 'D')
		{
			go_to_database = true;
			break;
		}

		if (start_a_new_game)
		{
			clrscr();
			break;
		}
		go_to_database = false;
	} while (zn != 'Q' && zn != 'q');

	_setcursortype(_NORMALCURSOR);	// show the cursor so it will be visible after the program ends

	// After the game free the memory to avoid memory leaks
	delete table;


	// After everything check if we want to start a new game
	if (start_a_new_game)
	{
		start_game(database, player_1, player_2);
		return;
	}

	if (go_to_database)
	{
		database_functionality(database);
		return;
	}

	if (!start_a_new_game)
	{
		// After the game free the memory
		//delete[] database;
		return;
	}
}