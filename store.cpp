/*********************************************************************
** Program name: Final Project - store.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Store Subclass. Holds an inventory for items that
				decreases per use.
*********************************************************************/
#include "space.hpp"

Store::Store()
{
	item0 = 1;
	item1 = 1;
	item2 = 1;
	item3 = 1;
	item4 = 1;
}

Store::Store(int stockCount)
{
	item0 = stockCount;
	item1 = stockCount;
	item2 = stockCount;
	item3 = stockCount;
	item4 = stockCount;
}

/*********************************************************************
** Description: Returns true if selected item is still in stock
*********************************************************************/
bool Store::inStock(int item)
{
	switch (item)
	{
	case 1:
		if (item0 > 0)
		{
			item0--;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2:
		if (item1 > 0)
		{
			item1--;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (item2 > 0)
		{
			item2--;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 4:
		if (item3 > 0)
		{
			item3--;
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 5:
		if (item4 > 0)
		{
			item4--;
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
}

/*********************************************************************
** Description: Describes subclass
*********************************************************************/
void Store::spaceDescription()
{
	std::cout << "Grocery Store. Has nice A/C." << std::endl;
}

/*********************************************************************
** Description: Space's atmosphere has chance in affecting player health
*********************************************************************/
int Store::atmosphere()
{
	int chance = rand() % 6 + 1;
	if (chance <= 1)
	{
		std::cout << "The nice air cools you. You feel better. +3 hunger points" << std::endl;
		return 4;
	}
	else
	{
		return 0;
	}
}