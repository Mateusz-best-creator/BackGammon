#include "functions_definitions.h"

void print_bar(char table[][WIDTH], char bar_table[BAR_SIZE], int x, int y)
{
    // Print bars of one player
    for (int i = 0; i < BAR_SIZE; ++i)
    {
        char pawn = bar_table[i];
        if (pawn == 'E') { pawn = '='; }

        int table_y_coordinate = x - TOP_LEFT_X_CORNER_COORDINATE;
        int table_x_coordinate = y - TOP_LEFT_Y_CORNER_COORDINATE + i;

        table[table_x_coordinate][table_y_coordinate] = pawn;
    }
}