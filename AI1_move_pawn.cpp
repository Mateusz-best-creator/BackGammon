#include "AI.h"

void AI1_move_pawn(Board* t, Player* p, int i, int j, int dc, char c)
{
	bool ins = false;
	/*
		Here we want to move the pawn which is the closest to the home by dice_sum if possible.
	*/
	if (i - dc >= 0 && t->pawns[i][j] == c && dc != 0)
	{
		ins = AI1_check_insert_conditions(t, p, i, j, c, dc);
		if (ins)
		{
			p->dice1 = 0;
			p->dice2 = 0;
		}
	}
	/*
		Here we want to move the pawn which are closest to the home by dice1 if possible
	*/
	if (i - p->dice1 >= 0 && t->pawns[i][j] == c && p->dice1 != 0)
	{
		ins = AI1_check_insert_conditions(t, p, i, j, c, p->dice1);
		if (ins)
		{
			p->dice1 = 0;
		}
	}
	if (i - p->dice2 >= 0 && t->pawns[i][j] == c && p->dice2 != 0)
	{
		ins = AI1_check_insert_conditions(t, p, i, j, c, p->dice2);
		if (ins)
		{
			p->dice2 = 0;
		}
	}
}