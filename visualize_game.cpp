#include "functions_definitions.h"
#include "board.h"
#include <stdio.h>

void visualize_game(Player* player_1, Player* player_2)
{
    Board* table = new Board();
    initialize_table(table);

    FILE* file;

    if (fopen_s(&file, "state_of_the_game.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }
    unsigned int first_value, second_value;
    char character;
    int number_of_states_of_the_game = 0;
    // Read and process the content of the file
    while (fscanf_s(file, " %c %d %d", &character, sizeof(character), &first_value, &second_value) == 3) {
        if (character == 'N')
        {
            number_of_states_of_the_game++;
        }
    }

    // Close the file
    fclose(file);
    if (number_of_states_of_the_game == 0) { return; }

    // Open file again
    if (fopen_s(&file, "state_of_the_game.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return;
    }

    Board* table_of_boards = new Board[number_of_states_of_the_game];
    Player* table_of_player_1 = new Player[number_of_states_of_the_game];
    Player* table_of_player_2 = new Player[number_of_states_of_the_game];

    int index = -1;

    while (fscanf_s(file, " %c %d %d", &character, sizeof(character), &first_value, &second_value) == 3) 
    {
        if (character == 'N')
        {
            index++;
            
            // Initialize some values
            table_of_player_1[index].name = player_1->name;
            table_of_player_2[index].name = player_2->name;
            table_of_player_1[index].number_of_removed_pawns = 0;
            table_of_player_2[index].number_of_removed_pawns = 0;
            table_of_player_1[index].points = 0;
            table_of_player_2[index].points = 0;

            // Initialize table and remove all pawns
            initialize_table(&table_of_boards[index]);
            for (size_t i = 0; i < NUMBER_OF_COLUMNS; ++i)
            {
                for (size_t j = 0; j < NUMBER_OF_ROWS_IN_COLUMN; ++j)
                {
                    table_of_boards[index].pawns[i][j] = 'E'; // E means empty
                }
            }
        }
        // Set the pawns on the board
        else if (character == 'B' || character == 'R')
        {
            table_of_boards[index].pawns[first_value][second_value] = character;
        }
        // Set the points for players
        else if (character == 'P')
        {
            table_of_player_1[index].points = first_value;
            table_of_player_2[index].points = second_value;
        }
        // Set the pawns on bar for both players
        else if (character == 'A')
        {
            // Set pawns on bar for first player
            for (size_t i = 0; i < first_value; ++i)
            {
                table_of_boards[index].player_1_bar[i] = 'B';
            }
            // Set pawns on bar for second player
            for (size_t i = 0; i < second_value; ++i)
            {
                table_of_boards[index].player_2_bar[i] = 'R';
            }
        }
        // Set dropped pawns for both players
        else if (character == 'D')
        {
            table_of_player_1[index].number_of_removed_pawns = first_value;
            table_of_player_2[index].number_of_removed_pawns = second_value;
            
            // Set removed pawns for first player
            for (size_t i = 0; i < first_value; ++i)
            {
                table_of_player_1[index].removed_pawns[i] = 'B';
            }
            // Set removed pawns for second player
            for (size_t i = 0; i < second_value; ++i)
            {
                table_of_player_2[index].removed_pawns[i] = 'R';
            }
        }
        else
        {
            printf("Unknown operation: %c\n", character);
        }
    }
    // Close the file
    fclose(file);

    visualization(table_of_boards, table_of_player_1, table_of_player_2, number_of_states_of_the_game);
}