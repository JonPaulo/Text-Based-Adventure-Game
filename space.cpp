/*********************************************************************
** Program name: Final Project - space.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Space Class. Creates a room with specific variables
				and actions.
*********************************************************************/
#include "space.hpp"

Space::Space()
{
	top = NULL;
	right = NULL;
	left = NULL;
	bottom = NULL;
	collectedMoney = false;
}

Space::~Space()
{

}

/*********************************************************************
** Description: Set adjacent rooms to current space
*********************************************************************/
void Space::setRooms(Space* top, Space* right, Space* left, Space* bottom)
{
	this->top = top;
	this->right = right;
	this->left = left;
	this->bottom = bottom;
}

void Space::setLocation(int location)
{
	this->location = location;
}

int Space::getLocation()
{
	return location;
}

/*********************************************************************
** Description: Move to new location
*********************************************************************/
Space *Space::goTo(std::string direction)
{
	if (direction == "top")
	{
		if (top != NULL)
		{
			return top;
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Invalid Direction." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
	}
	else if (direction == "left")
	{
		if (left != NULL)
		{
			return left;
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Invalid Direction." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
	}
	else if (direction == "right")
	{
		if (right != NULL)
		{
			return right;
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Invalid Direction." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
	}
	else if (direction == "bottom")
	{
		if (bottom != NULL)
		{
			return bottom;
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Invalid Direction." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
	}
	return this;
}

/*********************************************************************
** Description: Room functions
*********************************************************************/
bool Space::safeLocked()
{
	return 0;
}

void Space::safeIsLocked(bool)
{

}

void Space::watchTV(std::string)
{

}

/*********************************************************************
** Description: Garage functions
*********************************************************************/
void Space::lockCar(bool)
{

}

bool Space::isCarLocked()
{
	return true;
}

void Space::switchLights()
{

}
void Space::changeCollectUnderLights(bool)
{

}

bool Space::getLightStatus()
{
	return 0;
}

bool Space::hasCollectedUnderLights()
{
	return 0;
}
/*********************************************************************
** Description: Car functions
*********************************************************************/
bool Space::haveCheckedCenterConsole()
{
	return 0;
}

void Space::checkedCenterConsole(bool choice)
{

}

bool Space::haveCheckedGloveCompartment()
{
	return false;
}


void Space::checkedGloveCompartment(bool)
{

}

/*********************************************************************
** Description: Outside functions
*********************************************************************/
void Space::openCar()
{

}

bool Space::collectedMoneyStatus()
{
	return collectedMoney;
}

void Space::changeCollectedMoneyStatus(bool choice)
{
	collectedMoney = choice;
}

int Space::generateLuck()
{
	return 0;
}

double Space::generateFloorCash()
{
	return 0;
}

/*********************************************************************
** Description: Yard functions
*********************************************************************/
bool Space::grassStatus()
{
	return 0;
}

void Space::mowGrass()
{

}
/*********************************************************************
** Description: Store functions
*********************************************************************/
bool Space::inStock(int)
{
	return false;
}

/*********************************************************************
** Description: Prints the location for various spaces
*********************************************************************/
void Space::printLocation()
{
	std::cout << "\nCurrent Location: " << std::endl;

	if (location == 1)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][x][ ][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 2)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [x]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 3)
	{
		std::cout << "   [x]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 4)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[x][ ][ ][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 5)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[x][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 6)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][x][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 7)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[ ][x][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 8)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [x]      " << std::endl;
	}
	else if (location == 9)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][x]" << std::endl;
		std::cout << "[ ][ ][ ]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
	else if (location == 10)
	{
		std::cout << "   [ ]      " << std::endl;
		std::cout << "   [ ]      " << std::endl;
		std::cout << "[ ][ ][ ][ ]" << std::endl;
		std::cout << "[ ][ ][x]   " << std::endl;
		std::cout << "   [ ]      " << std::endl;
	}
}
