/*********************************************************************
** Program name: Final Project - room.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Contains Room Subclass functions.
*********************************************************************/
#include "space.hpp"

Room::Room()
{
	safe = true;
	cabinet = false;
	tv = false;
}

/*********************************************************************
** Description: Returns state of safe being locked or unlocked
*********************************************************************/
bool Room::safeLocked()
{
	return safe;
}

/*********************************************************************
** Description: Changes lock state of safe
*********************************************************************/
void Room::safeIsLocked(bool choice)
{
	safe = choice;
}

/*********************************************************************
** Description: Message displayed for watching TV
*********************************************************************/
void Room::watchTV(std::string message)
{
	if (tv == false)
	{
		std::cout << message << std::endl;
		tv = true;
	}
	else
	{
		std::cout << "Spongebob is on television. Nothing happens." << std::endl;
	}
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Room::spaceDescription()
{
	std::cout << "Ahh. The generic room. 4 walls, indoors, has stuff inside it." << std::endl;
}

/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Room::atmosphere()
{
	int chance = rand() % 7 + 1;
	if (chance <= 1)
	{
		std::cout << "A large draft of hot air just blew inside. It bothered you. -1 hunger point.\n" << std::endl;
		return -1;
	}
	else
	{
		return 0;
	}
}