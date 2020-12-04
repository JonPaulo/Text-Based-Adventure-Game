/*********************************************************************
** Program name: Final Project - game.hpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Game Class. Holds all of the spaces and functions
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include "item.hpp"

class Game
{
private:
	int timeLimit; // 4. HEALTH / TIME LIMIT
	int choice;
	Space* currentLocation;
	Space* livingRoom;
	Space* kitchen;
	Space* backyard;
	Space* bedroom;
	Space* bathroom;
	Space* garage;
	Space* frontYard;
	Space* store;
	Space* car;
	Space* outside;
	bool gameOn;
	bool gameWon;
	std::array<Item, 7> items; // 3. CONTAINER
	double money;
	bool rememberedPassword;
public:
	Game();
	~Game();

	void play();
	void garageDialogue();
	void carDialogue();
	void livingRoomDialogue();
	void bedroomDialogue();
	void bathroomDialogue();
	void kitchenDialogue();
	void frontYardDialogue();
	void backYardDialogue();
	void storeDialogue();
	void outsideDialogue();

	void checkInventory();
	double checkBalance();

	bool checkRememberedPassword();
	void changeRememberedPassword(bool);

	void intNumChoice(std::string question, int& answer, int min, int max);
};

#endif
