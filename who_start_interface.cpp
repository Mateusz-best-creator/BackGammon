#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

/*
This function will randomly generate two integers(using another function)
and then print which player should start the game
*/
void print_which_player_begins(int& player_index) // Pass by reference
{
	int color;
	int player_1_first_dice, player_2_first_dice;
	get_random_numbers(&player_1_first_dice, &player_2_first_dice);
	if (player_1_first_dice >= player_2_first_dice)
	{
		player_index = 1;
		color = LIGHTCYAN;
	}
	else
	{
		player_index = 2;
		color = LIGHTRED;
	}
	textcolor(color);
	gotoxy(100, 16);
	std::cout << "Player " << player_index << " begins. Player 1 first dice = " << player_1_first_dice << " Player 2 first dice = " << player_2_first_dice;
	
}