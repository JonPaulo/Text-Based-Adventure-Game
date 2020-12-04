/*********************************************************************
** Program name: Final Project - outside.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Outside Subclass. Walk around and find money or starve more
*********************************************************************/
#include "space.hpp"

Outside::Outside()
{
	chance = rand() % 3 + 1; // 1-in-3 chnace
	randomMoney = rand() % 30 + 10; // $0.10-$0.40 randomly generated
}

/*********************************************************************
** Description: Generates chance of finding money on the floor
*********************************************************************/
int Outside::generateLuck()
{
	chance = rand() % 3 + 1;
	return chance;
}

/*********************************************************************
** Description: Returns random cash value
*********************************************************************/
double Outside::generateFloorCash()
{
	randomMoney = rand() % 30 + 10;
	randomMoney *= 0.01;
	return randomMoney;
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Outside::spaceDescription()
{
	std::cout << "Ahh. The great outdoors. May luck be on you side." << std::endl;
}

/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Outside::atmosphere()
{
	chance = rand() % 5 + 1;
	if (chance <= 2)
	{
		std::cout << "It is hot outside. Your body has been affected by the heat. -3 hunger points.\n" << std::endl;
		return -3;
	}
	else
	{
		return 0;
	}
}