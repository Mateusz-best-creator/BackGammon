#include <iostream>
#include "functions_definitions.h"
#include "conio.h"
#include "interfaces.h"
#include "board.h"

bool prepare_game(Player* player_1, Player* player_2, int& player_index, Board* table_s,
	int& background_color, int& star_x, int& star_y, int& zn, int& zero)
{
	if ((player_1->dice1 == 0 && player_1->dice2 == 0 && player_index == 1) ||
		(player_2->dice1 == 0 && player_2->dice2 == 0 && player_index == 2))
	{
		// It means that player cannot make another moves
		return true;
	}
	// Print table
	print_table(table_s);

	// Print interface for removed pawns
	print_removed_pawns_interface(player_1, player_2);

	// Set some visual attributes
	textbackground(background_color);

	// Put our star on the screen
	gotoxy(star_x, star_y);
	putch('*');
	zero = 0;
	zn = getch();
	background_color = 0; // Reset background color
	textbackground(background_color);
	return false;
}

void game_loop(Player* player_1, Player* player_2, int& player_index, Board* table_s, int& background_color,
	int& star_x, int& star_y, int& zero, int& zn, bool& inserting_element, bool& start_a_new_game, char& player_sign)
{
	do
	{
		if (prepare_game(player_1, player_2, player_index, table_s, background_color, star_x, star_y, zn, zero))
			break;

		// Determine player pawn sign ("R" or "B")
		player_sign = player_index == 1 ? player_1->pawn_char : player_2->pawn_char;
		move(table_s, zn, star_x, star_y, background_color,
			zero, inserting_element, player_sign, player_1, player_2);

		// After making some move check if the player won the game
		if (player_index == 1)
		{
			if (check_if_player_won(player_1))
			{
				start_a_new_game = true;
				return;
			}
		}
		else
		{
			if (check_if_player_won(player_2))
			{
				start_a_new_game = true;
				return;
			}
		}

	} while (zn != 'F' && zn != 'Q');
	clrscr();
}

void di(Player* player_1, Player* player_2, Board* table_s, int& player_index, int& dice1, int& dice2, char& player_sign)
{
	get_random_numbers(&dice1, &dice2);
	int dice_sum = dice1 + dice2;

	// Update dice values
	if (player_index == 1)
	{
		player_1->dice1 = dice1;
		player_1->dice2 = dice2;
	}
	else
	{
		player_2->dice1 = dice1;
		player_2->dice2 = dice2;
	}
	// Print the entire interface for player
	print_player_interface(player_index, player_1, player_2);
}

bool play(Player* player_1, Player* player_2, Board* table_s, int player_index, bool& start_a_new_game)
{
	textcolor(LIGHTGRAY);
	// Generate two random numbers and display them
	int dice1, dice2;
	char player_sign;
	di(player_1, player_2, table_s, player_index, dice1, dice2, player_sign);


	int zn = 0, background_color = 0, zero = 0;

	// Initialize start coordinates for our '*' pointer, roughly in the middle of the board
	int star_x = 55, star_y = 16;

	// Print the top interface
	print_top_interface(player_1, player_2, true);

	bool inserting_element = false;

	game_loop(player_1, player_2, player_index, table_s, background_color, star_x, star_y,
		zero, zn, inserting_element, start_a_new_game, player_sign);

	// Stop playing the game
	if (zn == 'Q') return true;
	return false;
}