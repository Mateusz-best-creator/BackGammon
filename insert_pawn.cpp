#include "functions_definitions.h"
#include "conio.h"
#include "board.h"

#include <iostream>
//nie zrobione
static int how_many_moves_can_make = 2;
static bool did_not_increment_moves = true;

// Check move
void c_mv(const char& ps, int& ci, int&  dif, int& sci)
{
	if (ps == 'B')
	{
		dif = NUMBER_OF_COLUMNS - ci;
		sci = 24;
	}
	else
	{
		dif = ci + 1;
		sci = 0;
	}
}

// First cases
bool f_cases(int& dif, int& ci, int& sci, bool& ipfb, const char& ps)
{
	if (ipfb)
	{
		c_mv(ps, ci, dif, sci);
	}
	else if (ps == 'B') { dif = sci - ci; }
	else { dif = ci - sci; }

	if ((ci < sci && ps == 'R' && !ipfb) ||
		(ci > sci && ps == 'B' && !ipfb))
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 31);
		std::cout << "You can't move back.";
		return false;
	}
}

// Zbicie piona
void z_pawn(Board* t, int& ci, const char& ps, const char& enemy_player_sign,Player* p1, Player* p2, int& player_2_pawns_on_bar, int& player_1_pawns_on_bar)
{
	t->pawns[ci][0] = ps;

	if (enemy_player_sign == 'R')
	{
		player_2_pawns_on_bar++;
		update_bar_pawns(t->player_2_bar, 'R', player_2_pawns_on_bar);
	}
	else
	{
		player_1_pawns_on_bar++;
		update_bar_pawns(t->player_1_bar, 'B', player_1_pawns_on_bar);
	}
	print_table(t); // Show the bar immediately

	// Check if all pawns of the player are in home, after inserting the pawn
	check_if_pawns_in_home(t, p1, p2, ps);
}

void cant_i(Board* t, int&ci, const char&ps, Player* p1, Player* p2)
{
	for (int i = 1; i < NUMBER_OF_ROWS_IN_COLUMN; ++i)
	{
		if (t->pawns[ci][i] == 'E')
		{
			t->pawns[ci][i] = ps;
			break;
		}
	}
	// Check if all pawns of the player are in home, after inserting the pawn
	check_if_pawns_in_home(t, p1, p2, ps);
}

void end_dices(int& difference, int* d1, int* d2)
{
	// Update dice values if we inserted the pawn properly
	if (difference != 0)
	{
		if (difference == *d1)
		{
			if (how_many_moves_can_make > 2)
			{
				how_many_moves_can_make--;
			}
			else
			{
				*d1 = 0;
			}
		}
		else if (difference == *d2)
		{
			if (how_many_moves_can_make > 2)
			{
				how_many_moves_can_make--;
			}
			else
			{
				*d2 = 0;
			}
		}
		else if (*d1 + *d2 == difference)
		{
			*d1 = 0;
			*d2 = 0;
			did_not_increment_moves = true;
		}
	}
}

bool c_diff(int& dif, int*d1, int*d2, const char ps, int& ci)
{
	if (dif != *d1 + *d2 && dif != *d1 && dif != *d2)
	{
		int dice_sum;
		if (how_many_moves_can_make == 3) { dice_sum = 3 * *d1; }
		else if (how_many_moves_can_make == 4) { dice_sum = 4 * *d2; }
		else { dice_sum = *d1 + *d2; }
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 30);
		std::cout << "You cannot insert your pawn [" << ps << "] in " << ci + 1 << " column.";
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 31);
		std::cout << "You have " << dice_sum << " moves left";

		return false;
	}
	return true;
}

// Update global variables
void ugv(int* dice1, int*dice2)
{
	if (*dice1 == *dice2 && did_not_increment_moves && *dice1 != 0 && *dice2 != 0)
	{
		how_many_moves_can_make = 4; did_not_increment_moves = false;
	}
	if (*dice1 != *dice2) { did_not_increment_moves = true; }
}

void update_bar_pawns(char bar[BAR_SIZE], char player_sign, int pawns_on_bar)
{
	for (int i = 0; i < pawns_on_bar; ++i)
	{
		bar[i] = player_sign;
	}
}

// All remaining cases
void all_cas(Board* t, int& ci, Player* p1, Player* p2, const char& ps, int& p2pob, int& p1pob, char& en_s)
{
	// Case when the entire column is empty
	if (t->pawns[ci][0] == 'E')
	{
		t->pawns[ci][0] = ps;
		// Check if all pawns of the player are in home, after inserting the pawn
		check_if_pawns_in_home(t, p1, p2, ps);
	}

	// zbicie piona
	else if (t->pawns[ci][0] == en_s && t->pawns[ci][1] == 'E')
	{
		z_pawn(t, ci, ps, en_s, p1, p2, p2pob, p1pob);
	}

	// Case when player insert the pawn (the same color)
	else if (t->pawns[ci][0] == ps)
	{
		cant_i(t, ci, ps, p1, p2);
	}
}

bool insert_pawn(Board* t, int ci, int ri, const char ps,
	Player* p1, Player* p2, int sci, bool& ipfb)
{
	int* d1, * d2;
	// Get the dice values
	if (ps == 'B')
	{
		d1 = &p1->dice1;
		d2 = &p1->dice2;
	}
	else
	{
		d1 = &p2->dice1;
		d2 = &p2->dice2;
	}

	ugv(d1, d2);

	// Check if we are able to make a move based on dice1 and dice2 values
	// We pass dice1 and dice2 by reference!
	int dif;
	f_cases(dif, ci, sci, ipfb, ps);

	if (!c_diff(dif, d1, d2, ps, ci))
		return false;

	char en_s = (ps == 'R') ? 'B' : 'R';

	int p1pob = 0;
	int p2pob = 0;

	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (t->player_1_bar[i] == 'B') { p1pob++; }
		if (t->player_2_bar[i] == 'R') { p2pob++; }
	}
	if (t->pawns[ci][5] != 'E') { return false; }



	all_cas(t, ci, p1, p2, ps, p2pob, p1pob, en_s);



	return true;
}