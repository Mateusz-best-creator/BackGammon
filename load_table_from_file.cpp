#include "functions_definitions.h"
#include "conio.h"
#include "board.h"
#include <stdio.h>
#include <iostream>

Board* load_table_from_file(Player* player_1, Player* player_2)
{
    gotoxy(1, 1);
    Board* table = new Board();
    initialize_table(table);

    // We need to clear all the pawns that are initialized by default
    for (size_t i = 0; i < NUMBER_OF_COLUMNS; ++i)
    {
        for (size_t j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
        {
            table->pawns[i][j] = 'E'; // E means empty
        }
    }

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
        if (character == 'B' || character == 'R')
        {
            table->pawns[first_value][second_value] = character;
        }
        else if (character == 'N')
        {
            // In this file we store only one state of the game, so we don't need to care about N symbols
            continue;
        }
        // Set the points for players
        else if (character == 'P')
        {
            player_1->points = first_value;
            player_2->points = second_value;
        }
        // Set the pawns on bar for both players
        else if (character == 'A')
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
        // Set dropped pawns for both players
        else if (character == 'D')
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
        else
        {
            continue;
        }
    }

    // Close the file
    fclose(file);

    return table;
}