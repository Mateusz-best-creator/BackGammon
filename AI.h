#pragma once

#include "functions_definitions.h"

bool AI_make_move(Board* table_s, Player* player_1, Player* player_AI);
bool check_insert_conditions(Board* table_s, int i, int j, const char AI_pawn_char, int* dice_value);