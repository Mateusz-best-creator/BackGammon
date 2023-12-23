#include "functions_definitions.h"
#include "board.h"

void init_e(Board* table_s)
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            table_s->table[i][j] = ' ';
        }
    }
}

void init_w(Board* table_s)
{
    // Initialize left and right walls
    for (int i = 0; i < HEIGHT; ++i)
    {
        table_s->table[i][0] = ':';
        table_s->table[i][1] = ':';
        table_s->table[i][WIDTH - 1] = ':';
        table_s->table[i][WIDTH - 2] = ':';
    }
}

void init_r(Board* table_s)
{
    // Initialize top and bottom rows
    for (int j = 0; j < WIDTH; ++j)
    {
        table_s->table[0][j] = '=';
        table_s->table[HEIGHT - 1][j] = '=';
    }
}

void init_b(Board* table_s)
{
    // Initialize middle column (BAR)
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = (WIDTH - 1) / 2; j < (WIDTH - 1) / 2 + 3; ++j)
        {
            table_s->table[i][j] = '=';
        }
    }
}

void part1(Board* table_s)
{
    // Initialize columns in our game (we will place pons between these columns)
    int initial_x_coordinate_1_part = 1;
    int initial_y_coordinate_1_part = 4;
    initialize_1_part_of_columns(initial_x_coordinate_1_part, initial_y_coordinate_1_part, table_s);
}

void part2(Board* table_s)
{
    int initial_x_coordinate_2_part = 10;
    int initial_y_coordinate_2_part = 4;
    initialize_1_part_of_columns(initial_x_coordinate_2_part, initial_y_coordinate_2_part, table_s);
}

void part3(Board* table_s)
{
    int initial_x_coordinate_3_part = 1;
    int initial_y_coordinate_3_part = 39;
    initialize_1_part_of_columns(initial_x_coordinate_3_part, initial_y_coordinate_3_part, table_s);
}

void part4(Board* table_s)
{
    int initial_x_coordinate_4_part = 10;
    int initial_y_coordinate_4_part = 39;
    initialize_1_part_of_columns(initial_x_coordinate_4_part, initial_y_coordinate_4_part, table_s);
}

void initi_all_columns(Board* table_s)
{
    part1(table_s);
    part2(table_s);
    part3(table_s);
    part4(table_s);
}

void print_pawns(Board* table_s)
{
    // Initialize all pawns
    print_bottom_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + WIDTH - 5, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT - 2);
    print_top_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + 5, TOP_LEFT_Y_CORNER_COORDINATE + 1);
}

void initialize_table(Board* table_s)
{
    table_s->color = 7; // Set our board color, defaults to LIGHTGRAY
    // For now initialize everything to empty space
    init_e(table_s);
    init_w(table_s);
    init_r(table_s);
    init_b(table_s);

    char bar_string[] = { "[BAR]" };

    int counter = 0;
    for (int i = WIDTH / 2 - 2; i < WIDTH / 2 + 3; ++i)
    {
        table_s->table[HEIGHT / 2][i] = bar_string[counter];
        counter++;
    }

    initi_all_columns(table_s);
    initialize_pawns(table_s->pawns);

    // Initialize bars for both players
    for (int i = 0; i < BAR_SIZE; ++i)
    {
        table_s->player_1_bar[i] = 'E';
        table_s->player_2_bar[i] = 'E';
    }
    print_pawns(table_s);
}