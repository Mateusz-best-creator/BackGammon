#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void move(Board* table_s, int& zn, int& star_x,
	int& star_y, int& background_color, int& zero,
	bool& inserting_element, char player_sign) // Passing most values by reference
{
	int table_column = 0, table_row = 0;
	// we do not want the key 'H' to play role of "up arrow"
		// so we check if the first code is zero
	if (zn == 0) {
		zero = 1;		// if this is the case then we read
		zn = getch();		// the next code knowing that this
		if (zn == 0x48) star_y--;	// will be a special key
		else if (zn == 0x50) star_y++;
		else if (zn == 0x4b) star_x--;
		else if (zn == 0x4d) star_x++;

		/*
		gotoxy(1, 3);
		std::cout << star_x << " " << star_y;
		*/

		//	If we are out of the board we need to adjust the coordinates
		if (star_y > TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT - 2) star_y--;
		if (star_y < TOP_LEFT_Y_CORNER_COORDINATE + 1) star_y++;
		if (star_x < TOP_LEFT_X_CORNER_COORDINATE + 2) star_x++;
		if (star_x > TOP_LEFT_X_CORNER_COORDINATE + WIDTH - 3) star_x--;
	}
	else if (zn == 0x0d)
	{
		grab_drop_pawn(table_s, star_x, star_y, player_sign, inserting_element, background_color);
	}
}