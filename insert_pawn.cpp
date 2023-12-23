#include "functions_definitions.h"
#include "conio.h"
#include "board.h"

#include <iostream>

static int how_many_moves_can_make = 2;
static bool did_not_increment_moves = true;

void can_i(Board* t, int& ci, const char& ps, Player* p1, Player* p2)
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

void c_diff(int& dif, int* d1, int* d2, const char ps, int& ci)
{
	int dice_sum;
	if (how_many_moves_can_make == 3) { dice_sum = 3 * *d1; }
	else if (how_many_moves_can_make == 4) { dice_sum = 4 * *d2; }
	else { dice_sum = *d1 + *d2; }
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 30);
	std::cout << "You cannot insert your pawn [" << ps << "] in " << ci + 1 << " column.";
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 31);
	std::cout << "You have " << dice_sum << " moves left";
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

void update_bar_pawns(char bar[BAR_SIZE], char player_sign, int pawns_on_bar)
{
	for (int i = 0; i < pawns_on_bar; ++i)
	{
		bar[i] = player_sign;
	}
}


// Update global variables
void ugv(int* dice1, int* dice2)
{
	if (*dice1 == *dice2 && did_not_increment_moves && *dice1 != 0 && *dice2 != 0)
	{
		how_many_moves_can_make = 4; did_not_increment_moves = false;
	}
	if (*dice1 != *dice2) { did_not_increment_moves = true; }
}

void say(const char ps, int& ci)
{
	gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 30);
	std::cout << "You cannot insert your pawn [" << ps << "] in " << ci + 1 << " column";
}

bool cas(Board* t, int ci, int ri, const char ps,
	Player* p1, Player* p2, int sci, bool& ipfb, char& eps, int& p2pob, int&p1pob)
{
	if (t->pawns[ci][0] == 'E')
	{
		t->pawns[ci][0] = ps;
		// Check if all pawns of the player are in home, after inserting the pawn
		check_if_pawns_in_home(t, p1, p2, ps);
	}

	// zbicie piona
	else if (t->pawns[ci][0] == eps && t->pawns[ci][1] == 'E')
	{
		t->pawns[ci][0] = ps;

		if (eps == 'R')
		{
			p2pob++;
			update_bar_pawns(t->player_2_bar, 'R', p2pob);
		}
		else
		{
			p1pob++;
			update_bar_pawns(t->player_1_bar, 'B', p1pob);
		}
		print_table(t); // Show the bar immediately

		// Check if all pawns of the player are in home, after inserting the pawn
		check_if_pawns_in_home(t, p1, p2, ps);
	}

	// Case when player insert the pawn (the same color)
	else if (t->pawns[ci][0] == ps)
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

	// Case when player cannot insert the pawn
	else if (t->pawns[ci][0] == eps)
	{
		say(ps, ci);
		return false; // false will indicate that we were unable to insert the pawn at given position
	}
	return true;
}

bool c_ci(int& ci, int& sci, const char& ps, bool&ipfb)
{
	if ((ci < sci && ps == 'R' && !ipfb) ||
		(ci > sci && ps == 'B' && !ipfb))
	{
		gotoxy(TOP_LEFT_X_CORNER_COORDINATE, 31);
		std::cout << "You can't move back.";
		return false;
	}
}

bool u_bars(Board* t, int&p1pob, int&p2pob, int ci, int ri, const char ps,
	Player* p1, Player* p2, int sci, bool& ipfb, char& eps)
{
	for (int i = 0; i < BAR_SIZE; ++i)
	{
		if (t->player_1_bar[i] == 'B') { p1pob++; }
		if (t->player_2_bar[i] == 'R') { p2pob++; }
	}
	if (t->pawns[ci][5] != 'E') { return false; }
	// Case when the entire column is empty
	if (!cas(t, ci, ri, ps, p1, p2, sci, ipfb, eps, p2pob, p1pob))
	{
		return false;
	}
	return true;
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
	if (ipfb)
	{
		if (ps == 'B')
		{
			dif = N_COLUMNS - ci;
			sci = 24;
		}
		else
		{
			dif = ci + 1;
			sci = 0;
		}
	}
	else if (ps == 'B') { dif = sci - ci; }
	else { dif = ci - sci; }

	if (!c_ci(ci, sci, ps, ipfb))
		return false;

	if (dif == 0)
	{
		// just continue
	}
	else if (dif != *d1 + *d2 && dif != *d1 && dif != *d2)
	{
		c_diff(dif, d1, d2, ps, ci);
		return false;
	}

	char eps = (ps == 'R') ? 'B' : 'R';

	int p1pob = 0;
	int p2pob = 0;

	if (!u_bars(t, p1pob, p2pob, ci, ri, ps, p1, p2, sci, ipfb, eps))
	{
		return false;
	}

	end_dices(dif, d1, d2);
	return true;
}