#include "functions_definitions.h"

void initialize_table(Board* table_s)
{
    // For now initialize everything to empty space
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            table_s->table[i][j] = ' ';
        }
    }

    // Initialize left and right walls
    for (int i = 0; i < HEIGHT; ++i)
    {
        table_s->table[i][0] = ':';
        table_s->table[i][1] = ':';
        table_s->table[i][WIDTH - 1] = ':';
        table_s->table[i][WIDTH - 2] = ':';
    }

    // Initialize top and bottom rows
    for (int j = 0; j < WIDTH; ++j)
    {
        table_s->table[0][j] = '=';
        table_s->table[HEIGHT - 1][j] = '=';
    }

    char bar_string[] = { "[BAR]" };
    // Initialize middle column (BAR)
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = (WIDTH - 1) / 2; j < (WIDTH - 1) / 2 + 3; ++j)
        {
            table_s->table[i][j] = '=';
        }
    }

    int counter = 0;
    for (int i = WIDTH / 2 - 2; i < WIDTH / 2 + 3; ++i)
    {
        table_s->table[HEIGHT / 2][i] = bar_string[counter];
        counter++;
    }

    // Initialize columns in our game (we will place pons between these columns)
    int initial_x_coordinate_1_part = 1;
    int initial_y_coordinate_1_part = 4;
    initialize_1_part_of_columns(initial_x_coordinate_1_part, initial_y_coordinate_1_part, table_s);

    int initial_x_coordinate_2_part = 10;
    int initial_y_coordinate_2_part = 4;
    initialize_1_part_of_columns(initial_x_coordinate_2_part, initial_y_coordinate_2_part, table_s);

    int initial_x_coordinate_3_part = 1;
    int initial_y_coordinate_3_part = 39;
    initialize_1_part_of_columns(initial_x_coordinate_3_part, initial_y_coordinate_3_part, table_s);

    int initial_x_coordinate_4_part = 10;
    int initial_y_coordinate_4_part = 39;
    initialize_1_part_of_columns(initial_x_coordinate_4_part, initial_y_coordinate_4_part, table_s);

    initialize_pawns(table_s->pawns);

    // Initialize bars for both players
    for (int i = 0; i < BAR_SIZE; ++i)
    {
        table_s->player_1_bar[i] = 'E';
        table_s->player_2_bar[i] = 'E';
    }

    // Initialize all pawns
    print_bottom_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + WIDTH - 5, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT - 2);
    print_top_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + 5, TOP_LEFT_Y_CORNER_COORDINATE + 1);
}