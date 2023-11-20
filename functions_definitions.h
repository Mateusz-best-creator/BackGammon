#pragma once

// Here we will define all constants that we will use throughout our game
#define TOP_LEFT_X_CORNER_COORDINATE 20 // Based on the size of the screen we should adjust these values
#define TOP_LEFT_Y_CORNER_COORDINATE 8

#define HEIGHT 17
#define WIDTH 70

#define NUMBER_OF_COLUMNS 24
#define NUMBER_OF_ROWS_IN_COLUMN 6

#define NUMBER_OF_INDEXES 12

#define BAR_SIZE 7

struct Board
{
    char table[HEIGHT][WIDTH];
    char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN];
    char player_1_bar[BAR_SIZE];
    char player_2_bar[BAR_SIZE];
};

struct Player
{
    int points;
    char pawn_char;
    int player_index;
    bool can_take_pieces_of_the_board = false;
};

void start_game();

void print_top_interface(Player* player_1, Player* player_2, int color_theme);

/*
    Helper functions to initialize and print the table
*/
void print_bar(char table[][WIDTH], char bar_table[BAR_SIZE], int x, int y);
void initialize_1_part_of_columns(int x_coordinate, int y_coordinate, Board* table_s);
void initialize_pawns(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN]);
void print_top_pawns(char table[][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN],
    int initial_x_coordinate, int initial_y_coordinate);
void print_bottom_pawns(char table[HEIGHT][WIDTH], char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN],
    int initial_x_coordinate, int initial_y_coordinate);

void initialize_table(Board* table_s);
void print_table(Board* table_s);

// _s -> it means that it is structure
void initialize_table(Board* table_s);

void print_table(Board* table_s);

// Function to play the game
bool play(Player* player_1, Player* player_2, Board* table_s, int player_index, int color_theme);

// Funtion for displaying player's interface
void print_player_interface(int player_index, int dice1, int dice2);

// Function for generating two random integers
void get_random_numbers(int* num1, int* num2);

// This function will display for us which player starts the game
void print_which_player_begins(int& player_index);

// This function will tell us if all pawns of a given player are in home
bool check_if_all_pawns_in_home(char pawns[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS_IN_COLUMN], int player_index);

// This function allows us to make a move
void move(Board* table_s, int& zn, int& star_x,
    int& star_y, int& background_color, int& zero,
    bool& inserting_element, char player_sign);

void grab_drop_pawn(Board* table_s, int& star_x, int& star_y,
    char player_sign, bool& inserting_element, int& background_color);

// This function allows us to save state of the game to a file
void write_to_file(const char board[][WIDTH]);

// This function allows us to save state of the game to a binary file
void write_to_binary_file(const char table[][WIDTH]);

// This function allows us to insert a pawn to a specific column
bool insert_pawn(Board* table_s, int column_index, int row_index, const char player_sign);