#include <iostream>
#include "functions_definitions.h"
#include "conio.h"
#include "board.h"

void p_indexes(int i, int extra, const char tifl[], const char tisl[], const char bifl[])
{
    // Top indexes
    gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + extra, TOP_LEFT_Y_CORNER_COORDINATE - 1);
    putch(tifl[i - 1]);
    gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + 1 + extra, TOP_LEFT_Y_CORNER_COORDINATE - 1);
    putch(tisl[i - 1]);

    // bottom indexes
    if (bifl[i - 1] != '0')
    {
        gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + extra, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT);
        putch(bifl[i - 1]);
    }
}

void print(Board* table_s, int i, int j)
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

void p_content(Board* table_s)
{
    // Print bottom pawns
    print_bottom_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + WIDTH - 5, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT - 2);

    // Print top pawns
    print_top_pawns(table_s->table, table_s->pawns, TOP_LEFT_X_CORNER_COORDINATE + 5, TOP_LEFT_Y_CORNER_COORDINATE + 1);
    // Print entire content of the table
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            print(table_s, i, j);
        }
        std::cout << "\n";
    }
}

void i_bar(Board* table_s)
{
    // Print bars of both players
    initialize_bar(table_s->table, table_s->player_1_bar, TOP_LEFT_X_CORNER_COORDINATE + (WIDTH / 2), TOP_LEFT_Y_CORNER_COORDINATE + 1);
    initialize_bar(table_s->table, table_s->player_2_bar, TOP_LEFT_X_CORNER_COORDINATE + (WIDTH / 2), TOP_LEFT_Y_CORNER_COORDINATE + 1 + 8);
}

void print_table(Board* table_s)
{
    const char tifl[] = { "111111122222" };
    const char tisl[] = { "345678901234" };

    const char bifl[] = { "111000000000" };
    const char bisl[] = { "210987654321" };

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
        p_indexes(i, extra, tifl, tisl, bifl);
        gotoxy(TOP_LEFT_X_CORNER_COORDINATE + (i * 5) + 1 + extra, TOP_LEFT_Y_CORNER_COORDINATE + HEIGHT);
        putch(bisl[i - 1]);
    }

    p_content(table_s);
    i_bar(table_s);
}