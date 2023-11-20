#define _CRT_SECURE_NO_WARNINGS

// Include all header files
#include<stdio.h>
#include "conio.h"
#include <stdlib.h>

#include "functions_definitions.h"


int main()
{
	// if the program is compiled in pure C, then we need to initialize
	// the library ourselves; __cplusplus is defined only if a C++ compiler
	// is used

#ifndef __cplusplus
	Conio2_Init();
#endif

	// Initialize the game
	gotoxy(40, 10);
	cputs("Choose type of the game:");
	gotoxy(40, 12);
	cputs("[1] -> play with other player");
	gotoxy(75, 12);
	cputs("[2] -> play with AI");
	int zn;
	zn = getch();
	clrscr();
	if (zn == '1')
	{
		start_game();
	}
	else
	{
		//start_game_with_ai();
	}
}
