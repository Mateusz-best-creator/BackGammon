#include <stdio.h>
#include "functions_definitions.h"

void write_to_file(Board* table_s, Player* player_1, Player* player_2)
{
    FILE* file;

    // Open the file using fopen_s
    if (fopen_s(&file, "state_of_the_game.txt", "a") != 0) {
        return;
    }

    fprintf(file, "N 0 0\n"); // First indicate we start a new state

    // Write players points
    int p1 = player_1->points, p2 = player_2->points;
    fprintf(file, "P ");
    fprintf(file, "%d ", p1);
    fprintf(file, "%d\n", p2);

    // Write players deleted pawns
    int r1 = player_1->number_of_removed_pawns, r2 = player_2->number_of_removed_pawns;
    fprintf(file, "D ");
    fprintf(file, "%d ", r1);
    fprintf(file, "%d\n", r2);

    // Print pawns that are on the bar
    int b1 = 0, b2 = 0;
    for (size_t i = 0; i < BAR_SIZE; i++)
    {
        if (table_s->player_1_bar[i] == 'B') { b1++; }
        if (table_s->player_2_bar[i] == 'R') { b2++; }
    }
    fprintf(file, "A ");
    fprintf(file, "%d ", b1);
    fprintf(file, "%d\n", b2);

    // Write blue and red pawns
    for (size_t column = 0; column < NUMBER_OF_COLUMNS; column++)
    {
        for (size_t row = 0; row < NUMBER_OF_ROWS_IN_COLUMN; row++)
        {
            if (table_s->pawns[column][row] == 'B')
            {
                fprintf(file, "B ");
                fprintf(file, "%d ", column);
                fprintf(file, "%d\n", row);
            }
            else if (table_s->pawns[column][row] == 'R')
            {
                fprintf(file, "R ");
                fprintf(file, "%d ", column);
                fprintf(file, "%d\n", row);
            }
        }
    }

    fclose(file);
}