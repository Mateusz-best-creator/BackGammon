#include <iostream>
#include "conio.h"
#include "functions_definitions.h"

void vis_cases(int& zn, int& index, int& number_of_states, bool& print_database,
	Board* table_of_boards, Player* table_of_player_1, Player* table_of_player_2)
{
	do
	{
		zn = getch();

		switch (zn)
		{
		case 'N':
			if (index < number_of_states - 1) { index++; }
			print_visualization_interface(table_of_boards, table_of_player_1, table_of_player_2, index);
			break;
		case 'P':
			if (index > 0) { index--; }
			print_visualization_interface(table_of_boards, table_of_player_1, table_of_player_2, index);
			break;
		case 'D':
			print_database = true;
			break;
		case 'Q':
			break;
		default:
			gotoxy(1, 1);
			std::cout << "Wrong symbol";
			zn = 'Q';
			break;
		}
	} while (zn != 'Q' && print_database == false);
}

void visualization(Board* table_of_boards, Player* table_of_player_1, Player* table_of_player_2, int number_of_states)
{
	int index = 0;
	int zn = 0;

	print_visualization_interface(table_of_boards, table_of_player_1, table_of_player_2, index);

	bool print_database = false;

	vis_cases(zn, index, number_of_states, print_database, table_of_boards, table_of_player_1, table_of_player_2);

	if (print_database)
	{
		clrscr();
		PlayersDatabase* database = create_database();
		database_functionality(database);
		return;
	}
}

