/*********************************************************************
** Program name: Final Project - item.hpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Item Class. Object contains a value and a name.
*********************************************************************/
#include "item.hpp"

Item::Item()
{
	this->name = "error";
	value = 0;

	haveItem = false;
}
Item::Item(std::string name, double value)
{
	this->name = name;
	this->value = value;

	haveItem = false;
}

/*********************************************************************
** Description: Adds or subtracts value of the object
*********************************************************************/
void Item::changeValue(double value)
{
	this->value += value;
}

/*********************************************************************
** Description: Get/Set functions for Item class
*********************************************************************/
std::string Item::getName()
{
	return name;
}

void Item::setItem(bool choice)
{
	haveItem = choice;
}

bool Item::getItem()
{
	return haveItem;
}

void Item::setValue(double value)
{
	this->value = value;
}

double Item::getValue()
{
	return value;
}