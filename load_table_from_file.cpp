#include "functions_definitions.h"
#include "conio.h"
#include "board.h"
#include <stdio.h>
#include <iostream>

void br_case(char character, int first_value, int second_value, Board* table)
{
    if (character == 'B' || character == 'R')
    {
        table->pawns[first_value][second_value] = character;
    }
}

void p_case(char character, int first_value, int second_value, Player* player_1, Player* player_2)
{
    // Set the points for players
    if (character == 'P')
    {
        player_1->points = first_value;
        player_2->points = second_value;
    }
}

void d_case(char character, int first_value, int second_value, Player* player_1, Player* player_2)
{
    if (character == 'D')
    {
        player_1->number_of_removed_pawns = first_value;
        player_2->number_of_removed_pawns = second_value;
        // Set removed pawns for first player
        for (size_t i = 0; i < first_value; ++i)
        {
            player_1->removed_pawns[i] = 'B';
        }
        // Set removed pawns for second player
        for (size_t i = 0; i < first_value; ++i)
        {
            player_2->removed_pawns[i] = 'R';
        }
    }
}

void a_case(char character, int first_value, int second_value, Board* table)
{
    if (character == 'A')
    {
        // Set pawns on bar for first player
        for (size_t i = 0; i < first_value; ++i)
        {
            table->player_1_bar[i] = 'B';
        }
        // Set pawns on bar for second player
        for (size_t i = 0; i < second_value; ++i)
        {
            table->player_2_bar[i] = 'R';
        }
    }
}

void process(Board* table, char character, int first_value, int second_value, Player* player_1, Player* player_2)
{
    br_case(character, first_value, second_value, table);
    p_case(character, first_value, second_value, player_1, player_2);
    d_case(character, first_value, second_value, player_1, player_2);
    a_case(character, first_value, second_value, table);
}

void clear(Board* table)
{
    // We need to clear all the pawns that are initialized by default
    for (size_t i = 0; i < NUMBER_OF_COLUMNS; ++i)
    {
        for (size_t j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
        {
            table->pawns[i][j] = 'E'; // E means empty
        }
    }
}

Board* load_table_from_file(Player* player_1, Player* player_2)
{
    gotoxy(1, 1);
    Board* table = new Board();
    initialize_table(table);

    clear(table);

    FILE* file;

    if (fopen_s(&file, "game_to_load.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return table;
    }

    unsigned int first_value, second_value;
    char character;

    // Read and process the content of the file
    while (fscanf_s(file, " %c %d %d", &character, sizeof(character), &first_value, &second_value) == 3) {
        // Set the pawns on the board
        process(table, character, first_value, second_value, player_1, player_2);
    }

    // Close the file
    fclose(file);

    return table;
}