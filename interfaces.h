#pragma once

#include "functions_definitions.h"

/*
    Functions for printing the interfaces
*/
void print_top_interface(Player* player_1, Player* player_2, bool playing);
void print_player_interface(int player_index, Player* player_1, Player* player_2);
void print_startup_options_interface();
void print_playing_interface();
void print_removed_pawns_interface(Player* player_1, Player* player_2);
void print_database_interface();