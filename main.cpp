/*********************************************************************
** Program name: Final Project - main.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Main. Starts the game. Fastest way to win on the bottom.
*********************************************************************/
#include "game.hpp"

int main()
{
	// 1. THEME: DON'T STARVE TO DEATH
	std::cout << "Welcome to Jon Paulo Bautista's final project!\n" << std::endl;
	std::cout << "1. The object of the game is to find enough money to cook a burger." << std::endl;
	std::cout << "2. There is money laying around the house. Use it to buy ingredients at the\n   store." << std::endl;
	std::cout << "3. Once you cook your burger, you win the game!" << std::endl;
	std::cout << "4. Be careful, every action you take uses energy and you might starve to death!" << std::endl;
	std::cout << "5. The refrigerator shows your inventory.\n" << std::endl;
	std::cout << "FASTEST ROUTE TO WIN is commented in main.cpp." << std::endl;
	std::cout << "Vertically expanding the console is recommended.\n" << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << "^^^^^ READ FIRST ^^^^^" << std::endl;
	std::cout << "^^^^^ READ FIRST ^^^^^" << std::endl;
	std::cout << "^^^^^ READ FIRST ^^^^^\n" << std::endl;

	// Random seed generator
	unsigned seed;
	seed = time(0);
	srand(seed);

	Game game;
	game.play();

	return 0;
}

// Fastest order to win: 1st row, then 2nd row, then 3rd row from left to right
// Only split into 3 columns for readability purposes

// 2,5,3,3, 5,3,1,5, 7,2,2,2,
// 7,1,4,5, 1,3,1,5, 1,5,7,4,
// 4,4,4,2, 3,4,5,6, 1,1,7