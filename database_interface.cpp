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
	std::cout << "\t4. [S] -> start playing a game,";
	gotoxy(60, TOP_LEFT_Y_CORNER_COORDINATE + 5);
	std::cout << "\t  you will have to choose indexes of a players";
}