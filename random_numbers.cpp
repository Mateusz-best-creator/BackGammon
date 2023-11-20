#include <iostream>
#include <time.h> // for random numbers

void get_random_numbers(int* num1, int* num2)
{
	// Seed the random number generator with the current time
	srand((unsigned int)time(NULL));

	// Generate two random numbers between 1 and 6
	*num1 = rand() % 6 + 1;
	*num2 = rand() % 6 + 1;
}