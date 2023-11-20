#include "functions_definitions.h"

void initialize_column(int initial_x, int initial_y, Board* table_s)
{
    for (int i = 0; i < 6; ++i)
    {
        table_s->table[initial_x + i][initial_y] = '|';
        table_s->table[initial_x + i][initial_y + 2] = '|';
    }
}

void initialize_1_part_of_columns(int x_coordinate, int y_coordinate, Board* table_s) // In total we have 4 parts
{
    for (int i = y_coordinate; i < y_coordinate + 5 * 6; i += 5)
    {
        initialize_column(x_coordinate, i, table_s);
    }
}