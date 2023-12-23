#include <iostream>
#include "functions_definitions.h"
#include "conio.h"
#include "interfaces.h"

void set(Player* player1)
{
	// settitle sets the window title
	settitle("Mateusz Wieczorek - Data Engineering group 3, id = 197743");

	// hide the blinking cursor
	_setcursortype(_NOCURSOR);

	// Create static interface for our game
	textbackground(BLACK);

	// Print the title
	textcolor(WHITE);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 2);
	cputs("BackGammon Game v1.0.0");

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 3);
	cputs("Score: ");

	// Print the scores
	textcolor(LIGHTCYAN);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 8, 4);
	std::cout << player1->name << " (B) = " << player1->points;
}

void print_top_interface(Player* player1, Player* player2, bool playing)
{
	set(player1);
	textcolor(LIGHTRED);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 8, 5);
	std::cout << player2->name << " (R) = " << player2->points;

	if (playing) { print_playing_interface(); }
	else { print_startup_options_interface(); }
}