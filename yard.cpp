/*********************************************************************
** Program name: Final Project - yard.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Yard Subclass.
*********************************************************************/
#include "space.hpp"

Yard::Yard()
{
	shed = false;
	grass = false;
}

/*********************************************************************
** Description: Returns true if grass has been mowed.
*********************************************************************/
bool Yard::grassStatus()
{
	return grass;
}

/*********************************************************************
** Description: Mowing grass adds more health (works only once)
*********************************************************************/
void Yard::mowGrass()
{
	std::cout << "*******************************************************************************" << std::endl;
	if (grass == false)
	{
		std::cout << "Mowing the grass..." << std::endl;
		std::cout << "That made me feel better. I totally forgot I was even hungry." << std::endl;
		std::cout << "+15 hunger points" << std::endl;
		grass = true;
	}
	else
	{
		std::cout << "You already mowed the grass." << std::endl;
	}
	std::cout << "*******************************************************************************" << std::endl;
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Yard::spaceDescription()
{
	std::cout << "A standard yard. Has some pretty grass for pets to play on." << std::endl;
}

/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Yard::atmosphere()
{
	int chance = rand() % 5 + 1;
	if (chance <= 2)
	{
		std::cout << "It is hot outside. Your body has been affected by the heat. -2 hunger points.\n" << std::endl;
		return -2;
	}
	else
	{
		return 0;
	}
}