#include "functions_definitions.h"
#include "conio.h"

#include <stdio.h>
#include <iostream>

Board* load_table_from_file()
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

    unsigned int column, row;
    char pawn_character;

    // Read and process the content of the file
    while (fscanf_s(file, " %c %d %d", &pawn_character, sizeof(pawn_character), &column, &row) == 3) {
        if (pawn_character == 'B' || pawn_character == 'R')
        {
            table->pawns[column][row] = pawn_character;
        }
        else
        {
            printf("Unknown operation: %c\n", pawn_character);
        }
    }

    // Close the file
    fclose(file);

    return table;
}