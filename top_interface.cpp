#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void print_top_interface(Player* player1, Player* player2, int color_theme)
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

	// we set the text color
	textcolor(color_theme);

	gotoxy(100, 8);
	cputs("Select: ");
	gotoxy(100, 10);
	cputs("[P] = play the game");
	gotoxy(100, 12);
	cputs("[F] = finish your move");
	gotoxy(100, 14);
	cputs("[C] = change color");
	gotoxy(100, 16);
	cputs("[Q] = quit game");
}