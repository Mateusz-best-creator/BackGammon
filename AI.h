#pragma once

#include "functions_definitions.h"
/*
    Functions that allows us to create an AI player
*/
bool AI_make_move(Board* table_s, Player* player_AI);
bool AI_check_insert_conditions(Board* table_s, Player* player_AI, int i, int j, const char AI_pawn_char, int dice_value);
void AI_insert_pawn_from_bar(Board* table_s, Player* player_AI, int dice_value, char AI_pawn_char);
void AI_take_pawns_off_the_board(Board* table_s, Player* player_AI, char AI_pawn_char);
void AI_move_pawn(Board* table_s, Player* player_AI, int i, int j, int dice_sum, char AI_pawn_char);