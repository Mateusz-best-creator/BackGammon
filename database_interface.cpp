#include "functions_definitions.h"
#include "conio.h"

#include <iostream>


void print_database_interface()
{
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE);
	std::cout << "Options:";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 2);
	std::cout << "\t1. [A] -> add player to the database";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 3);
	std::cout << "\t2. [D] -> delete player from the database";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 4);
	std::cout << "\t3. [P] -> pick two indexes of players you want to play";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 5);
	std::cout << "\t4. [S] -> start playing a game with chosen players, if indexes";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 6);
	std::cout << "\tare not specified two initial players are chosen by default";
}