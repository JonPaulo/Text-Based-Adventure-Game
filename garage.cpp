/*********************************************************************
** Program name: Final Project - garage.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Contains Garage Subclass functions.
*********************************************************************/
#include "space.hpp"

Garage::Garage()
{
	carlocked = true;
	lightsOn = false;
	collectedUnderLights = false;
}

/*********************************************************************
** Description: Returns state of car being locked or unlocked
*********************************************************************/
void Garage::lockCar(bool choice)
{
	carlocked = choice;
}

/*********************************************************************
** Description: Changes lock state of car
*********************************************************************/
bool Garage::isCarLocked()
{
	return carlocked;
}

/*********************************************************************
** Description: Turns garage lights on or off. Changes visibility.
*********************************************************************/
void Garage::switchLights()
{
	std::cout << "*******************************************************************************" << std::endl;
	if (lightsOn == false)
	{
		std::cout << "Light turned on. It becomes easier to see things now." << std::endl;
		lightsOn = true;
	}
	else
	{
		std::cout << "Lights turned off." << std::endl;
		lightsOn = false;
	}
	std::cout << "*******************************************************************************" << std::endl;
}

/*********************************************************************
** Description: Checks if light is on or off
*********************************************************************/
bool Garage::getLightStatus()
{
	return lightsOn;
}


/*********************************************************************
** Description: Checks state to see if user has collected coins under lights
*********************************************************************/
bool Garage::hasCollectedUnderLights()
{
	return collectedUnderLights;
}

/*********************************************************************
** Description: Changes state if user has collected coins under lights
*********************************************************************/
void Garage::changeCollectUnderLights(bool choice)
{
	collectedUnderLights = choice;
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Garage::spaceDescription()
{
	std::cout << "The garage. Cars usually live here." << std::endl;
}

/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Garage::atmosphere()
{
	int chance = rand() % 4 + 1;
	if (chance <= 1)
	{
		std::cout << "The garage is scorching inside. It bothers you. -5 hunger points.\n" << std::endl;
		return -5;
	}
	else
	{
		return 0;
	}
}