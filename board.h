#pragma once

#include "functions_definitions.h"

/*
    Helper functions to initialize and print the table
*/
void initialize_bar(char table[][WIDTH], char bar_table[BAR_SIZE], int x, int y);
void initialize_1_part_of_columns(int x_coordinate, int y_coordinate, Board* table_s);
void initialize_pawns(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN]);
void print_top_pawns(char table[][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN],
    int initial_x_coordinate, int initial_y_coordinate);
void print_bottom_pawns(char table[HEIGHT][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN],
    int initial_x_coordinate, int initial_y_coordinate);

void initialize_table(Board* table_s);
void print_table(Board* table_s);

// _s -> it means that it is structure
void initialize_table(Board* table_s);