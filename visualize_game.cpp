#include "functions_definitions.h"
#include "board.h"
#include <stdio.h>

void D_case(int& in, unsigned int& fv, unsigned int& sv, Board* tb, Player* tb1, Player* tb2, Player* p1, Player* p2)
{
    tb1[in].number_of_removed_pawns = fv;
    tb2[in].number_of_removed_pawns = sv;

    // Set removed pawns for first player
    for (size_t i = 0; i < fv; ++i)
    {
        tb1[in].removed_pawns[i] = 'B';
    }
    // Set removed pawns for second player
    for (size_t i = 0; i < sv; ++i)
    {
        tb2[in].removed_pawns[i] = 'R';
    }
}

void A_case(Board* tb, unsigned int& fv, unsigned int& sv, int& in)
{
    // Set pawns on bar for first player
    for (size_t i = 0; i < fv; ++i)
    {
        tb[in].player_1_bar[i] = 'B';
    }
    // Set pawns on bar for second player
    for (size_t i = 0; i < sv; ++i)
    {
        tb[in].player_2_bar[i] = 'R';
    }
}

void N_case(int& in, Board* tb, Player* tb1, Player* tb2, Player* p1, Player* p2)
{
    in++;

    // Initialize some values
    tb1[in].name = p1->name;
    tb2[in].name = p2->name;
    tb1[in].number_of_removed_pawns = 0;
    tb2[in].number_of_removed_pawns = 0;
    tb1[in].points = 0;
    tb2[in].points = 0;

    // Initialize table and remove all pawns
    initialize_table(&tb[in]);
    for (size_t i = 0; i < N_COLUMNS; ++i)
    {
        for (size_t j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
        {
            tb[in].pawns[i][j] = 'E'; // E means empty
        }
    }
}

void p_file(FILE* f, char& c, int& in, unsigned int& fv, unsigned int& sv, Board* tb, Player* tb1, Player* tb2, Player* p1, Player* p2)
{
    while (fscanf_s(f, " %c %d %d", &c, sizeof(c), &fv, &sv) == 3)
    {
        if (c == 'N')
        {
            N_case(in, tb, tb1, tb2, p1, p2);
        }
        // Set the pawns on the board
        else if (c == 'B' || c == 'R')
        {
            tb[in].pawns[fv][sv] = c;
        }
        // Set the points for players
        else if (c == 'P')
        {
            tb1[in].points = fv;
            tb2[in].points = sv;
        }
        // Set the pawns on bar for both players
        else if (c == 'A')
        {
            A_case(tb, fv, sv, in);
        }
        // Set dropped pawns for both players
        else if (c == 'D')
        {
            D_case(in, fv, sv, tb, tb1, tb2, p1, p2);
        }
        else
        {
            printf("Unknown operation: %c\n", c);
        }
    }
}

void visualize_game(Player* p1, Player* p2)
{
    Board* table = new Board();
    initialize_table(table);

    FILE* f;

    if (fopen_s(&f, "state_of_the_game.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }
    unsigned int fv, sv;
    char c;
    int n = 0;
    // Read and process the content of the file
    while (fscanf_s(f, " %c %d %d", &c, sizeof(c), &fv, &sv) == 3) {
        if (c == 'N')
        {
            n++;
        }
    }

    // Close the file
    fclose(f);
    if (n == 0) { return; }

    // Open file again
    if (fopen_s(&f, "state_of_the_game.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }

    Board* tb = new Board[n];
    Player* tb1 = new Player[n];
    Player* tb2 = new Player[n];

    int in = -1;

    p_file(f, c, in, fv, sv, tb, tb1, tb2, p1, p2);
    // Close the file
    fclose(f);

    visualization(tb, tb1, tb2, n);
}