#include "functions_definitions.h"
#include "conio.h"

#include <stdio.h>
#include <iostream>

void load_table_from_file()
{
    gotoxy(1, 1);
    Board* table = new Board();

    FILE* file;
    if (fopen_s(&file, "game_to_load.txt", "r") != 0) {  // Open the file for reading
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    int array[HEIGHT][WIDTH];

    int character;
    
    // Read characters from the file until the end is reached
    while ((character = fgetc(file)) != EOF) {
        // Process each character as needed
        putchar(character);
    }

    // Close the file
    fclose(file);
    /*
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }*/
}