#include <iostream>
#include "functions_definitions.h"
#include "conio.h"

void print_table(Board* table_s)
{
    const char top_indexes_first_letter[] = { "111111122222" };
    const char top_indexes_second_letter[] = { "345678901234" };

    const char bottom_indexes_first_letter[] = { "111000000000" };
    const char bottom_indexes_second_letter[] = { "210987654321" };

    int extra = 0;
    // Print top and bottom indexes
    textcolor(table_s->color);
    for (int i = 1; i <= NUMBER_OF_INDEXES; ++i)
    {
        if (i == NUMBER_OF_INDEXES / 2 + 1)
        {
            // Extra spaces when we are at the second half of the board
            extra = 4;
        }
        // Top indexes
        gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + extra, TOP_LEFT_Y_CORNER_COORDINATE - 1);
        putch(top_indexes_first_letter[i - 1]);
        gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + 1 + extra, TOP_LEFT_Y_CORNER_COORDINATE - 1);
        putch(top_indexes_second_letter[i - 1]);

        // bottom indexes
        if (bottom_indexes_first_letter[i - 1] != '0')
        {
            gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + extra, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT);
            putch(bottom_indexes_first_letter[i - 1]);
        }
        gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + 1 + extra, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT);
        putch(bottom_indexes_second_letter[i - 1]);
    }

    // Print bottom pawns
    print_bottom_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + WIDTH - 5, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT - 2);

    // Print top pawns
    print_top_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + 5, TOP_LEFT_Y_CORNER_COORDINATE + 1);

    // Print entire content of the table
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            gotoxy(TOP_LEFT_X_CORNER_COORDINATE + j, TOP_LEFT_Y_CORNER_COORDINATE + i);
            char table_char = table_s->table[i][j];

            // Case where we display 'BAR' string
            if ((table_char == 'R' && table_s->table[i][j - 1] == 'A') || (table_char == 'B' && table_s->table[i][j + 1] == 'A')) {} // do nothing
            else if (table_char == 'R') { textcolor(LIGHTRED); }
            else if (table_char == 'B') { textcolor(LIGHTCYAN); }
            // Put the pawn on the screen
            putch(table_s->table[i][j]);
            // reset text color
            textcolor(table_s->color);
        }
        std::cout << "\n";
    }

    // Print bars of both players
    initialize_bar(table_s->table, table_s->player_1_bar, TOP_LEFT_X_CORNER_COORDINATE + (WIDTH / 2), TOP_LEFT_Y_CORNER_COORDINATE + 1);
    initialize_bar(table_s->table, table_s->player_2_bar, TOP_LEFT_X_CORNER_COORDINATE + (WIDTH / 2), TOP_LEFT_Y_CORNER_COORDINATE + 1 + 8);
}