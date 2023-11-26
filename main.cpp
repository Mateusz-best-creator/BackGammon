#define _CRT_SECURE_NO_WARNINGS

// Include all header files
#include<stdio.h>
#include "conio.h"
#include <stdlib.h>

#include "functions_definitions.h"
#include "AI.h"


int main()
{
	// if the program is compiled in pure C, then we need to initialize
	// the library ourselves; __cplusplus is defined only if a C++ compiler
	// is used

#ifndef __cplusplus
	Conio2_Init();
#endif

	// Clear and close the file
	FILE* file;
	fopen_s(&file, "state_of_the_game_readable.txt", "w");
	fclose(file);

	// Initialize players database
	PlayersDatabase* database = create_database();

	// Initialize the game
	gotoxy(10, 10);
	cputs("Choose type of the game:");
	gotoxy(10, 12);
	cputs("[1] -> play with other player");
	gotoxy(45, 12);
	cputs("[2] -> load game from file");
	int zn;
	zn = getch();
	clrscr();
	bool load_from_file = true;
	if (zn == '1')
	{
		database_functionality(database);
	}
	else if (zn == '2')
	{
		start_game(database, &(database->players[0]), &(database->players[1]), load_from_file);
	}
}
