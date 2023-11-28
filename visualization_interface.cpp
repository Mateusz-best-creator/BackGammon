#include <iostream>
#include "functions_definitions.h"
#include "conio.h"
#include "board.h"

void print_visualization_interface(Board* table_of_boards, Player* table_of_player_1, Player* table_of_player_2, int index)
{
	clrscr();

	gotoxy(95, 7);
	std::cout << "[N] -> next state of the game";
	gotoxy(95, 8);
	std::cout << "[P] -> previous state of the game";
	gotoxy(95, 9);
	std::cout << "[D] -> database";
	gotoxy(95, 10);
	std::cout << "[Q] -> quit";

	gotoxy(20, 2);
	std::cout << "Visualization of the BackGammon game at state: " << index;

	gotoxy(20, 4);
	std::cout << table_of_player_1[index].name << ": " << table_of_player_1[index].points;

	gotoxy(20, 5);
	std::cout << table_of_player_2[index].name << ": " << table_of_player_2[index].points;

	gotoxy(20, 7);
	print_table(&table_of_boards[index]);

	gotoxy(20, 30);
	std::cout << "Player 1 removed pawns: ";
	for (size_t i = 0; i < table_of_player_1[index].number_of_removed_pawns; i++)
	{
		gotoxy(42 + i + 2, 30);
		textcolor(LIGHTCYAN);
		std::cout << "B";
	}
	textcolor(LIGHTGRAY);
	gotoxy(20, 32);
	std::cout << "Player 2 removed pawns: ";
	for (size_t i = 0; i < table_of_player_2[index].number_of_removed_pawns; i++)
	{
		gotoxy(42 + i + 2, 32);
		textcolor(LIGHTRED);
		std::cout << 'R';
	}
	textcolor(LIGHTGRAY);
}

