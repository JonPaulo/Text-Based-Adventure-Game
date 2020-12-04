/*********************************************************************
** Program name: Final Project - space.hpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Space Class. Creates a room with specific variables
				and actions.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include "item.hpp"

class Space
{
private:
	Space *top;
	Space *right;
	Space *left;
	Space *bottom;
	int location;
	bool collectedMoney;
public:
	Space();
	~Space();

	// 2. KEEPING TRACK WHERE THE PLAYER IS
	void setRooms(Space*, Space*, Space*, Space*);
	void setLocation(int);
	int getLocation();
	void printLocation();
	Space *goTo(std::string);

	bool collectedMoneyStatus();
	void changeCollectedMoneyStatus(bool);

	// Pure Virtual Functions
	virtual void spaceDescription() = 0;
	virtual int atmosphere() = 0;

	// Subclass-specific functions
	virtual void openCar();
	virtual void lockCar(bool);
	virtual bool isCarLocked();
	virtual bool haveCheckedGloveCompartment();
	virtual void checkedGloveCompartment(bool);
	virtual bool safeLocked();
	virtual void safeIsLocked(bool);
	virtual bool haveCheckedCenterConsole();
	virtual void checkedCenterConsole(bool);
	virtual bool grassStatus();
	virtual void mowGrass();
	virtual int generateLuck();
	virtual double generateFloorCash();
	virtual void watchTV(std::string);
	virtual void switchLights();
	virtual void changeCollectUnderLights(bool);
	virtual bool getLightStatus();
	virtual bool hasCollectedUnderLights();
	virtual bool inStock(int);
};

#endif

/*********************************************************************
** Description: Room subclass of Space
				**They have TVs which give information.
*********************************************************************/
class Room : public Space
{
private:
	bool cabinet;
	bool safe;
	bool tv;
public:
	Room();
	bool safeLocked();
	void safeIsLocked(bool);

	void watchTV(std::string);
	void spaceDescription();
	int atmosphere();
};

/*********************************************************************
** Description: Garage subclass of Space
				**Contains a locked car.
*********************************************************************/
class Garage : public Space
{
private:
	bool carlocked;
	bool lightsOn;
	bool collectedUnderLights;
public:
	Garage();
	void lockCar(bool);
	bool isCarLocked();

	void switchLights();
	bool getLightStatus();
	bool hasCollectedUnderLights();
	void changeCollectUnderLights(bool);
	void spaceDescription();
	int atmosphere();
};

/*********************************************************************
** Description: Car subclass of Space
				**Has compartments that use bools to collect things
				one time
				**Can collect money under seat if garage lights are on
*********************************************************************/
class Car : public Space
{
private:
	bool gloveCompartment;
	bool centerConsole;
public:
	Car();

	bool haveCheckedGloveCompartment();
	void checkedGloveCompartment(bool);

	bool haveCheckedCenterConsole();
	void checkedCenterConsole(bool);
	void spaceDescription();
	int atmosphere();
};

/*********************************************************************
** Description: Outside subclass of Space
				**Generates floor money
*********************************************************************/
class Outside : public Space
{
private:
	int chance;
	double randomMoney;
public:
	Outside();
	int generateLuck();
	double generateFloorCash();
	void spaceDescription();
	int atmosphere();
};

/*********************************************************************
** Description: Yard subclass of Space
				**Can mow grass for more health
*********************************************************************/
class Yard : public Space
{
private:
	bool shed;
	bool grass;
public:
	Yard();
	bool grassStatus();
	void mowGrass();
	void spaceDescription();
	int atmosphere();
};

/*********************************************************************
** Description: Store subclass of Space
				**Holds a stock inventory for things to sell
*********************************************************************/
class Store : public Space
{
private:
	int item0;
	int item1;
	int item2;
	int item3;
	int item4;
public:
	Store();
	Store(int);
	bool inStock(int);
	void spaceDescription();
	int atmosphere();
};