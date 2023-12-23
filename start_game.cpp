#include <iostream>

// Modules for sleep_for function
#include <thread>
#include <chrono>

// All header files
#include "functions_definitions.h"
#include "AI.h"
#include "conio.h"
#include "interfaces.h"
#include "board.h"

void AI_both(Player* player_1, Player* player_2, Board* table, bool& first_time, int& player_index)
{
	// Show the board for 2 seconds in case AI vs AI
	if (player_1->name == "AI1" && player_2->name == "AI2")
	{
		print_table(table);
		print_removed_pawns_interface(player_1, player_2);
		std::this_thread::sleep_for(std::chrono::seconds(0));
	}
	clrscr();

	// Print who start the game
	if (first_time)
	{
		first_time = false;
		print_which_player_begins(player_index);
	}
}

bool AI2(Player* player_1, Player* player_2, PlayersDatabase* database, Board* table, int& player_index)
{
	AI2_make_move(table, player_2);
	if (check_if_player_won(player_2))
	{
		// Clear the removed pawns array
		for (size_t i = 0; i < NUMBER_OF_PAWNS_FOR_ONE_PLAYER; i++)
		{
			player_2->removed_pawns[i] = 'E';
		}
		player_2->number_of_removed_pawns = 0;
		database_functionality(database);
		return true;
	}
	if (player_index == 1) { player_index = 2; }
	else { player_index = 1; }
	// Print state of the game to the file
	write_to_file_visually(table->table, player_1, player_2);
	write_to_file(table, player_1, player_2);
	return false;
}

bool AI1(Player* player_1, Player* player_2, PlayersDatabase* database, Board* table, int& player_index)
{
	AI1_make_move(table, player_1);
	if (check_if_player_won(player_1))
	{
		// Clear the removed pawns array
		for (size_t i = 0; i < NUMBER_OF_PAWNS_FOR_ONE_PLAYER; i++)
		{
			player_1->removed_pawns[i] = 'E';
		}
		player_1->number_of_removed_pawns = 0;
		database_functionality(database);
		return true;
	}
	if (player_index == 1) { player_index = 2; }
	else { player_index = 1; }
	// Print state of the game to the file
	write_to_file_visually(table->table, player_1, player_2);
	write_to_file(table, player_1, player_2);
	return false;
}

void P_case(Player* p1, Player* p2, PlayersDatabase* db, Board* t, int& pi, bool& ft,
	bool& sp, bool& sng)
{
	// If player typed "P" we will start a game in a loop
	do
	{
		AI_both(p1, p2, t, ft, pi);

		// First AI bot makes a move
		if (pi == 1 && p1->name == "AI1")
		{
			if (AI1(p1, p2, db, t, pi))
				return;
			else
				continue;
		}

		// Second IA bot makes a move
		if (pi == 2 && p2->name == "AI2")
		{
			if (AI2(p1, p2, db, t, pi))
				return;
			continue;
		}

		sp = play(p1, p2, t, pi, sng);
		// Change player_index
		if (pi == 1) { pi = 2; }
		else { pi = 1; }

		if (!sp)
		{
			// Print state of the game to the file
			write_to_file_visually(t->table, p1, p2);
			write_to_file(t, p1, p2);
		}
	} while (!sp);
}

bool end(Board* t, bool& sng, PlayersDatabase* dt, Player* p1, Player* p2, bool& rf, bool& gdt)
{
	_setcursortype(_NORMALCURSOR);	// show the cursor so it will be visible after the program ends

	// After the game free the memory to avoid memory leaks
	delete t;

	// After everything check if we want to start a new game
	if (sng)
	{
		start_game(dt, p1, p2, rf);
		return true;
	}

	if (gdt)
	{
		database_functionality(dt);
		return true;
	}

	if (!sng)
	{
		// After the game free the memory
		//delete[] database;
		return true;
	}
	return false;
}

Board* pre(PlayersDatabase* d, Player* p1, Player* p2, bool& rf)
{
	// We need to do some preprocessing before we start a game
	p1->pawn_char = 'B';
	p2->pawn_char = 'R';
	p1->player_index = 1;
	p2->player_index = 2;

	// Initialize the board with default pawn places
	Board* t = new Board();

	// In case we read from file
	if (rf)
	{
		t = load_table_from_file(p1, p2);
	}
	else
	{
		initialize_table(t);
	}
	rf = false;
	print_table(t);
	// This index will keep track which player now makes a move

	// Print initial state of the game
	write_to_file_visually(t->table, p1, p2);
	write_to_file(t, p1, p2);
	return t;
}

void start_game(PlayersDatabase* d, Player* p1, Player* p2, bool& rf)
{
	Board* t = pre(d, p1, p2, rf);
	int player_index = 1;
	int zn = 0;

	// This variable will indicate if user entered [P] to play for the first time
	bool fst = true;

	// This boolean value will indicate if we want to stop the game
	bool stp = false;

	// This value will indicate if we want to start a new game
	bool sng = false;

	// This boolean value will indicate whether or not we want to go to our database interface
	bool gtd;

	do
	{
		print_table(t);
		print_top_interface(p1, p2, false);
		zn = getch();

		if (zn == 'C')
		{
			t->color++;
			if (t->color > 15)
			{
				t->color = 0;
			}
		}
		else if (zn == 'P')
		{
			P_case(p1, p2, d, t, player_index, fst, stp, sng);
		}

		else if (zn == 'D')
		{
			gtd = true;
			break;
		}

		if (sng)
		{
			clrscr();
			break;
		}
		gtd = false;
	} while (zn != 'Q' && zn != 'q');

	if (end(t, sng, d, p1, p2, rf, gtd))
		return;
}