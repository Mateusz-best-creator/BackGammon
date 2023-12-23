#define _CRT_SECURE_NO_WARNINGS

// Include all header files
#include<stdio.h>
#include "conio.h"
#include <stdlib.h>

#include "functions_definitions.h"

void case2(FILE* file, PlayersDatabase* database, bool& load_from_file)
{
	fopen_s(&file, "state_of_the_game_visually.txt", "w");
	fclose(file);
	fopen_s(&file, "state_of_the_game.txt", "w");
	fclose(file);
	start_game(database, &(database->players[0]), &(database->players[1]), load_from_file);
}

void case1(FILE* file, PlayersDatabase* database)
{
	fopen_s(&file, "state_of_the_game_visually.txt", "w");
	fclose(file);
	fopen_s(&file, "state_of_the_game.txt", "w");
	fclose(file);
	database_functionality(database);
}

void info()
{
	// Initialize the game
	gotoxy(10, 10);
	cputs("Choose type of the game:");
	gotoxy(10, 12);
	cputs("[1] -> play with other player");
	gotoxy(45, 12);
	cputs("[2] -> load game from file");
	gotoxy(75, 12);
	cputs("[3] -> visualize the game from loaded file");
}

int main()
{
	// if the program is compiled in pure C, then we need to initialize
	// the library ourselves; __cplusplus is defined only if a C++ compiler
	// is used

#ifndef __cplusplus
	Conio2_Init();
#endif

	// Clear and close the files
	FILE* file = nullptr;

	// Initialize players database
	PlayersDatabase* database = create_database();

	info();
	int zn;
	zn = getch();
	clrscr();
	bool load_from_file = true;
	if (zn == '1')
	{
		case1(file, database);
	}
	else if (zn == '2')
	{
		case2(file, database, load_from_file);
	}
	else if (zn == '3')
	{
		visualize_game(&(database->players[0]), &(database->players[1]));
	}
}
