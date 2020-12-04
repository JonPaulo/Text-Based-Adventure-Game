/*********************************************************************
** Program name: Final Project - car.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Contains Car Subclass functions.
*********************************************************************/
#include "space.hpp"

Car::Car()
{
	gloveCompartment = false;
	centerConsole = false;
}

/*********************************************************************
** Description: Checks if glove compartment has been searched
*********************************************************************/
bool Car::haveCheckedGloveCompartment()
{
	return gloveCompartment;
}
/*********************************************************************
** Description: Changes check state of glove compartment
*********************************************************************/
void Car::checkedGloveCompartment(bool choice)
{
	this->gloveCompartment = choice;
}

/*********************************************************************
** Description: Checks if center console has been searched
*********************************************************************/
bool Car::haveCheckedCenterConsole()
{
	return centerConsole;
}

/*********************************************************************
** Description: Changes check state of center console
*********************************************************************/
void Car::checkedCenterConsole(bool choice)
{
	centerConsole = choice;
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Car::spaceDescription()
{
	std::cout << "These things go pretty fast and take people to far places." << std::endl;
}


/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Car::atmosphere()
{
	int chance = rand() % 5 + 1;
	if (chance <= 1)
	{
		std::cout << "The greenhouse effect from the car burn you up. -3 hunger points.\n" << std::endl;
		return -3;
	}
	else
	{
		return 0;
	}
}