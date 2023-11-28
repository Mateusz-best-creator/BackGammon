#pragma once
#include <cstring>

// Here we will define all constants that we will use throughout our game
#define TOP_LEFT_X_CORNER_COORDINATE 20 // Based on the size of the screen we should adjust these values
#define TOP_LEFT_Y_CORNER_COORDINATE 8

#define HEIGHT 17
#define WIDTH 70

#define NUMBER_OF_COLUMNS 24
#define NUMBER_OF_ROWS_IN_COLUMN 6

#define NUMBER_OF_INDEXES 12

#define BAR_SIZE 7

#define NUMBER_OF_PAWNS_FOR_ONE_PLAYER 15

struct Board
{
    char table[HEIGHT][WIDTH];
    char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN];
    char player_1_bar[BAR_SIZE];
    char player_2_bar[BAR_SIZE];
    int color;
};

struct Player
{
    int points;
    char pawn_char;
    int player_index;
    int dice1, dice2;
    bool can_take_pawns_from_the_board;
    char removed_pawns[NUMBER_OF_PAWNS_FOR_ONE_PLAYER];
    int number_of_removed_pawns;
    const char* name;
};

#define MAX_NUMBER_OF_PLAYERS 5
#define MAX_NUMBER_OF_AI_PLAYERS 1

struct PlayersDatabase
{
    Player* players = new Player[MAX_NUMBER_OF_PLAYERS + MAX_NUMBER_OF_AI_PLAYERS];
    int number_of_players;

    // Constructor
    PlayersDatabase() : players(new Player[MAX_NUMBER_OF_PLAYERS + MAX_NUMBER_OF_AI_PLAYERS]), number_of_players(0) {}

    // Destructor to release the memory
    ~PlayersDatabase()
    {
        delete[] players;
    }
};

void start_game(PlayersDatabase* database, Player* player_1, Player* player_2, bool& load_from_file);

// Function to play the game
bool play(Player* player_1, Player* player_2, Board* table_s, int player_index, bool& start_a_new_game);


// This function will display for us which player starts the game
void print_which_player_begins(int& player_index);

// Function for generating two random integers
void get_random_numbers(int* num1, int* num2);

// This function will tell us if all pawns of a given player are in home
bool check_if_all_pawns_in_home(Board* table_s, char player_sign);
void check_if_pawns_in_home(Board* table_s, Player* player_1, Player* player_2, char player_sign);

// This function allows us to make a move
void move(Board* table_s, int& zn, int& star_x,
    int& star_y, int& background_color, int& zero,
    bool& inserting_element, char player_sign,
    Player* player_1, Player* player_2);

void grab_drop_pawn(Board* table_s, int& star_x, int& star_y,
    char player_sign, bool& inserting_element, int& background_color,
    Player* player_1, Player* player_2);

/*
    Functions for saving state of the game to a file
*/
// This function allows us to save state of the game to a file
void write_to_file_visually(const char board[][WIDTH], Player* player_1, Player* player_2);
void write_to_file(Board* table_s, Player* player_1, Player* player_2);

// This function allows us to save state of the game to a binary file
void write_to_binary_file(const char table[][WIDTH]);

// This function allows us to insert a pawn to a specific column
bool insert_pawn(Board* table_s, int column_index, int row_index, const char player_sign,
    Player* player_1, Player* player_2, int start_column_index, bool& inserting_pawn_from_bar);

// function that updates the bar
bool update_bar(char bar[], char player_sign, int row_index);

void update_bar_pawns(char bar[BAR_SIZE], char player_sign, int pawns_on_bar);

bool take_pawn_off_the_board(Player* player_1, Player* player_2, Board* table_s,
    int column_index, int row_index, char player_sign);

bool check_if_player_won(Player* player);

/*
    All functions that cover the functionality of the database
*/

// This function print the entire database of players in our game
void print_players_database(PlayersDatabase* database);

// Create and initial our database of players
PlayersDatabase* create_database();

void add_player_to_database(PlayersDatabase* database);

void database_functionality(PlayersDatabase* database);

void delete_player_from_database(PlayersDatabase* database);

void choose_indexes(int* player_1_index, int* player_2_index);

Board* load_table_from_file(Player* player_1, Player* player_2);

/*
    Functions for visualizing the game from the file
*/

void visualize_game(Player* player_1, Player* player_2);
void visualization(Board* table_of_boards, Player* table_of_player_1, Player* table_of_player_2, int number_of_states);
void print_visualization_interface(Board* table_of_boards, Player* table_of_player_1, Player* table_of_player_2, int index);