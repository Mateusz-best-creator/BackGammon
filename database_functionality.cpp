#include "functions_definitions.h"
#include "conio.h"

// Update player
void upla(Player* p)
{
	p->number_of_removed_pawns = 0;
}

void database_functionality(PlayersDatabase* d)
{
	int zn;
	do
	{
		print_players_database(d);
		zn = getch();
		if (zn == 'A')
		{
			add_player_to_database(d);
		}
		else if (zn == 'D')
		{
			delete_player_from_database(d);
		}
	} while (zn != 'S');


	int p1_i, p2_i;
	choose_indexes(&p1_i, &p2_i);
	bool read_from_file = false;

	upla(&(d->players[p1_i]));
	upla(&(d->players[p2_i]));

	start_game(d, &(d->players[p1_i]), &(d->players[p2_i]), read_from_file);
}