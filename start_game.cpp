#include <iostream>
#include "functions_definitions.h"
#include "conio.h"
#include <stdlib.h>

void start_game()
{
	int zn = 0, color_theme = 7;

	// This variable will indicate if user entered [P] to play for the first time
	bool first_time = true;

	// Initialize the board with default pawn places
	Board* table = (Board*)malloc(sizeof(Board));
	initialize_table(table);

	// Initialize both players
	Player* player_1 = (Player*)malloc(sizeof(Player));
	Player* player_2 = (Player*)malloc(sizeof(Player));

	// Initialize all "startup" variables
	player_1->pawn_char = 'B';
	player_2->pawn_char = 'R';

	player_1->points = 0;
	player_2->points = 0;

	player_1->player_index = 1;
	player_2->player_index = 2;

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
		print_top_interface(player_1, player_2, color_theme);
		zn = getch();

		if (zn == 'C')
		{
			color_theme++;
			if (color_theme > 15)
			{
				color_theme = 0;
			}
		}
		else if (zn == 'P')
		{
			if (first_time)
			{
				first_time = false;
				print_which_player_begins(player_index);
			}
			// If player typed "P" we will start a game in a loop
			do
			{
				stop_playing = play(player_1, player_2, table, player_index, color_theme);
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
	free(table);

	// After the game free the memory
	free(player_1);
	free(player_2);
}