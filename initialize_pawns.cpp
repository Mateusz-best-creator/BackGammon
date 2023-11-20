#include "functions_definitions.h"

void initialize_pawns(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN])
{
    /*
        E -> empty place
        R -> this means that given pawn belongs to "Red" player
        B -> this means that given pawn belongs to "Blue" player
    */
    for (int i = 0; i < NUMBER_OF_COLUMNS; ++i)
    {
        for (int j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
        {
            pawns[i][j] = 'E';
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        pawns[5][i] = 'B';
        pawns[12][i] = 'B';
        pawns[11][i] = 'R';
        pawns[18][i] = 'R';
    }

    for (int i = 0; i < 3; ++i)
    {
        pawns[7][i] = 'B';
        pawns[16][i] = 'R';
    }

    for (int i = 0; i < 2; ++i)
    {
        pawns[23][i] = 'B';
        pawns[0][i] = 'R';
    }
}