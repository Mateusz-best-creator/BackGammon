#include "functions_definitions.h"
#include "conio.h"

// function for printing pawns that are at the bottom
void print_bottom_pawns(char table[HEIGHT][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN], int initial_x_coordinate, int initial_y_coordinate)
{
    int counter = 0;
    int extra_middle_space = 0;
    for (int i = 0; i < 12; ++i)
    {
        if (i > 5)
        {
            extra_middle_space = 5;
        }

        for (int j = 0; j < 6; ++j)
        {
            int x = initial_x_coordinate - i * 5 - extra_middle_space;
            int y = initial_y_coordinate - j;

            int table_y_coordinate = x - TOP_LEFT_X_CORNER_COORDINATE;
            int table_x_coordinate = y - TOP_LEFT_Y_CORNER_COORDINATE;

            char pawn = pawns[i][j];
            if (pawn == 'E') { pawn = ' '; }
            table[table_x_coordinate][table_y_coordinate] = pawn;

        }
    }
}

// function for printing pawns that are at the top
void print_top_pawns(char table[][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN], int initial_x_coordinate, int initial_y_coordinate)
{
    int extra_middle_space = 0;
    int counter = 0;
    for (int i = 12; i < NUMBER_OF_COLUMNS; ++i)
    {
        if (i > 17)
        {
            extra_middle_space = 5;
        }

        for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
        {
            int x = initial_x_coordinate + (i - 12) * 5 + extra_middle_space;
            int y = initial_y_coordinate + j;

            int table_y_coordinate = x - TOP_LEFT_X_CORNER_COORDINATE;
            int table_x_coordinate = y - TOP_LEFT_Y_CORNER_COORDINATE;

            char pawn = pawns[i][j];
            if (pawn == 'E') { pawn = ' '; }
            table[table_x_coordinate][table_y_coordinate] = pawn;
        }
    }
}