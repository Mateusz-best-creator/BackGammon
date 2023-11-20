#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void print_top_interface(Player* player1, Player* player2, int color_theme, bool playing)
{
	// settitle sets the window title
	settitle("Mateusz Wieczorek - Data Engineering group 3, id = 197743");

	// hide the blinking cursor
	_setcursortype(_NOCURSOR);

	// Create static interface for our game
	textbackground(BLACK);

	// Print the title
	textcolor(WHITE);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 3);
	cputs("BackGammon Game v1.0.0");

	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 5);
	cputs("Score: ");

	// Print the scores
	textcolor(LIGHTCYAN);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 8, 5);
	cputs("Me (B) = ");
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 17, 5);
	std::cout << player1->points;

	textcolor(LIGHTRED);
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 21, 5);
	cputs("You (R) = ");
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE + 31, 5);
	std::cout << player2->points;

	if (playing) { print_playing_interface(color_theme); }
	else { print_startup_options_interface(color_theme); }
}