#include "functions_definitions.h"
#include "conio.h"
#include <iostream>

void print_startup_options_interface(int color_theme)
{
	// we set the text color
	textcolor(color_theme);

	gotoxy(100, 8);
	cputs("Select: ");
	gotoxy(100, 10);
	cputs("[P] = play the game");
	gotoxy(100, 12);
	cputs("[C] = change color");
	gotoxy(100, 14);
	cputs("[Q] = quit game");
}

void print_playing_interface(int color_theme)
{
	textcolor(color_theme);

	gotoxy(100, 8);
	cputs("Select: ");
	gotoxy(100, 10);
	cputs("[F] = finish your move");
	gotoxy(100, 12);
	cputs("[Q] = quit playing mode");
}