/*********************************************************************
** Program name: Final Project - item.hpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Item Class. Object contains a value and a name.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item
{
private:
	std::string name;
	bool haveItem;
	double value;
public:
	Item();
	Item(std::string, double);
	std::string getName();

	void setItem(bool);
	bool getItem();
	void setValue(double);
	void changeValue(double);
	double getValue();
};

#endif // !ITEM_HPP

