/*********************************************************************
** Program name: Final Project - game.cpp
** Author: Jon Paulo Bautista
** Date: 06/06/19
** Description: Game Class. Holds all of the spaces and functions
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Description: Assigns everything for all of the spaces
*********************************************************************/
Game::Game()
{
	timeLimit = 100;
	currentLocation;
	gameOn = true;
	gameWon = false;
	money = 0.00;
	rememberedPassword = false;

	livingRoom = new Room();
	kitchen = new Room();
	backyard = new Yard();
	bedroom = new Room();
	bathroom = new Room();
	garage = new Garage();
	frontYard = new Yard();
	store = new Store();
	car = new Car();
	outside = new Outside();

	// top, right, left, bottom
	livingRoom->setRooms(kitchen, garage, bedroom, frontYard);
	kitchen->setRooms(backyard, NULL, NULL, livingRoom);
	backyard->setRooms(NULL, NULL, NULL, kitchen);
	bedroom->setRooms(NULL, livingRoom, NULL, bathroom);
	bathroom->setRooms(bedroom, NULL, NULL, NULL);
	garage->setRooms(NULL, car, livingRoom, NULL);
	frontYard->setRooms(livingRoom, outside, NULL, store);
	store->setRooms(frontYard, NULL, NULL, NULL);
	car->setRooms(NULL, NULL, garage, NULL);
	outside->setRooms(NULL, outside, frontYard, store);
	currentLocation = livingRoom;

	// Set Location
	livingRoom->setLocation(1);
	kitchen->setLocation(2);
	backyard->setLocation(3);
	bedroom->setLocation(4);
	bathroom->setLocation(5);
	garage->setLocation(6);
	frontYard->setLocation(7);
	store->setLocation(8);
	car->setLocation(9);
	outside->setLocation(10);

	// Items
	Item burgerBuns("Burger Buns", 1.00); // [0]
	Item lettuce("Lettuce", 0.75); // [1]
	Item tomato("Tomato", 0.5); // [2]
	Item krabbyPatty("Krabby Patty", 3); // [3]
	Item secretSauce("Secret Sauce", 2.00); // [4]
	Item carKey("Car Keys", 0); // [5]
	Item shedKey("Mysterious Key", 0); // [6]
	items = { burgerBuns, lettuce, tomato, krabbyPatty, secretSauce, carKey, shedKey };
}

/*********************************************************************
** Description: Frees memory
*********************************************************************/
Game::~Game()
{
	delete livingRoom;
	delete bedroom;
	delete garage;
	delete bathroom;
	delete frontYard;
	delete kitchen;
	delete backyard;
	delete car;
	delete store;
	delete outside;
}

/*********************************************************************
** Description: The function that allows the game to play
*********************************************************************/
void Game::play()
{
	while (gameOn == true)
	{
		std::cout << "Hunger Health: " << timeLimit << std::endl;
		timeLimit--;
		switch (currentLocation->getLocation())
		{
		case 1:
			livingRoomDialogue();
			break;
		case 2:
			kitchenDialogue();
			break;
		case 3:
			backYardDialogue();
			break;
		case 4:
			bedroomDialogue();
			break;
		case 5:
			bathroomDialogue();
			break;
		case 6:
			garageDialogue();
			break;
		case 7:
			frontYardDialogue();
			break;
		case 8:
			storeDialogue();
			break;
		case 9:
			carDialogue();
			break;
		case 10:
			outsideDialogue();
			break;
		}

		if (timeLimit <= 0)
		{
			gameOn = false;
		}
	}
	if (gameWon == false)
	{
		std::cout << "YOU HAVE STARVED TO DEATH. YOU LOSE" << std::endl;
	}
}

/*********************************************************************
** Description: Dialogue for the garage space
*********************************************************************/
void Game::garageDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are in the garage." << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::cout << "You see your car, a table, and a light switch.\n" << std::endl;

	std::string message = "1. Up: \n" +
		std::string("2. Left: Living Room\n") +
		std::string("3. Right: Check the car\n") +
		std::string("4. Down: \n\n") +
		std::string("5. Check the table\n") +
		std::string("6. Flip light switch\n");

	intNumChoice(message, choice, 1, 6);
	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		if (currentLocation->isCarLocked() == true)
		{
			intNumChoice("The car is locked. Use car keys?\n1. Yes\n2. No", choice, 1, 2);
			switch (choice)
			{
			case 1:
				if (items[5].getItem() == true)
				{
					currentLocation->lockCar(false);
					std::cout << "*******************************************************************************" << std::endl;
					std::cout << "Unlocked the car!" << std::endl;
					std::cout << "*******************************************************************************" << std::endl;
					currentLocation = currentLocation->goTo("right");
				}
				else
				{
					std::cout << "*******************************************************************************" << std::endl;
					std::cout << "You don't have your car keys with you!\n" << std::endl;
					std::cout << "*******************************************************************************" << std::endl;
				}
				break;
			case 2:
				break;
			}
		}
		else
		{
			currentLocation = currentLocation->goTo("right");
		}
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (checkRememberedPassword() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Found a piece of paper. \"Password to safe is 1234.\"." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			changeRememberedPassword(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Piece of paper says \"Password to safe is 1234.\"." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 6:
		currentLocation->switchLights();
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the car space
*********************************************************************/
void Game::carDialogue()
{
	currentLocation->printLocation();
	currentLocation->spaceDescription();
	std::cout << "You are in the car." << std::endl;
	std::cout << "The car has no gas.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: \n" +
	std::string("2. Left: Garage\n") +
	std::string("3. Right: \n") +
	std::string("4. Down: \n\n") +
	std::string("5. Check glove compartment\n") +
	std::string("6. Check under the seat\n") +
	std::string("7. Check the center console\n");

	intNumChoice(message, choice, 1, 7);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (currentLocation->haveCheckedGloveCompartment() == false)
		{
			if (currentLocation->collectedMoneyStatus() == false)
			{
				std::cout << "*******************************************************************************" << std::endl;
				std::cout << "Found 4 quarters! +$1.00" << std::endl;
				std::cout << "*******************************************************************************" << std::endl;
				money += 1.00;
				currentLocation->changeCollectedMoneyStatus(true);
			}
			else
			{
				std::cout << "*******************************************************************************" << std::endl;
				std::cout << "Nothing was found." << std::endl;
				std::cout << "*******************************************************************************" << std::endl;
			}
		}
		break;
	case 6:
		if (garage->getLightStatus() == true && garage->hasCollectedUnderLights() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Found $1.12! I wouldn't have seen this if it weren't for the lights." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			money += 1.12;
			garage->changeCollectUnderLights(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Nothing is under the seat." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 7:
		if (currentLocation->haveCheckedCenterConsole() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Found $0.31!" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			money += .31;
			currentLocation->checkedCenterConsole(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "There is nothing here." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the living room space
*********************************************************************/
void Game::livingRoomDialogue()
{
	currentLocation->printLocation();
	currentLocation->spaceDescription();
	std::cout << "\nYou are in the living room." << std::endl;
	std::cout << "There is a table, a shelf, and a TV.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: Kitchen\n" +
	std::string("2. Left: Bedroom\n") +
	std::string("3. Right: Garage\n") +
	std::string("4. Down: Front Yard\n\n") +
	std::string("5. Check the table\n") +
	std::string("6. Check the shelf\n") +
	std::string("7. Watch TV\n");

	intNumChoice(message, choice, 1, 7);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		std::cout << "*******************************************************************************" << std::endl;
		std::cout << "On the table you see a grocery list.\n" << std::endl;
		std::cout << "\"Items needed to make a burger:" << std::endl;
		std::cout << " Burger Buns: $1.00" << std::endl;
		std::cout << " Lettuce: $0.75" << std::endl;
		std::cout << " Tomato: $.50" << std::endl;
		std::cout << " Krabby Patty: $3.00" << std::endl;
		std::cout << " Secret Sauce: $2.00\"" << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
		// Total = $7.25
		break;
	case 6:
		std::cout << "*******************************************************************************" << std::endl;
		std::cout << "There is nothing on the shelf." << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
		break;
	case 7:
		std::cout << "*******************************************************************************" << std::endl;
		currentLocation->watchTV("You watch TV. Then you remember that you left the \npassword for the safe on the garage table.");
		std::cout << "*******************************************************************************" << std::endl;
		break;
	}

}

/*********************************************************************
** Description: Dialogue for the bedroom space
*********************************************************************/
void Game::bedroomDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are in the bedroom." << std::endl;
	std::cout << "You see your cabinet, bed, safe, and TV.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: \n" +
		std::string("2. Left: \n") +
		std::string("3. Right: Living Room\n") +
		std::string("4. Down: Bathroom\n\n") +
	std::string("5. Check cabinet\n") +
	std::string("6. Check bed\n") +
	std::string("7. Check safe\n") +
	std::string("8. Watch TV\n");

	intNumChoice(message, choice, 1, 8);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (items[5].getItem() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Found your car keys!" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			items[5].setItem(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "There is nothing here" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 6:
		std::cout << "*******************************************************************************" << std::endl;
		std::cout << "Your bed is clean. Nothing is on it." << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
		break;
	case 7:
		if (currentLocation->safeLocked() == true)
		{
			intNumChoice("The safe is locked. Type in password?\n1. Yes\n2. No", choice, 1, 2);
			switch (choice)
			{
			case 1:
				if (rememberedPassword == true)
				{
					std::cout << "*******************************************************************************" << std::endl;
					std::cout << "Safe opened." << std::endl;
					std::cout << "Found a key. I don't remember what it was used for." << std::endl;
					std::cout << "*******************************************************************************" << std::endl;
					items[6].setItem(true);
					currentLocation->safeIsLocked(false);
				}
				else
				{
					std::cout << "*******************************************************************************" << std::endl;
					std::cout << "You don't remember the password. Unable to open safe." << std::endl;
					std::cout << "*******************************************************************************" << std::endl;
				}
				break;
			case 2:
				break;
			}
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Nothing is here." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 8:
		std::cout << "*******************************************************************************" << std::endl;
		currentLocation->watchTV("You watch TV. On TV they talk about how people keep dropping coins on the \nstreets.");
		std::cout << "*******************************************************************************" << std::endl;
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the bathroom space
*********************************************************************/
void Game::bathroomDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are in the bathroom.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: Bedroom\n" +
	std::string("2. Left: \n") +
	std::string("3. Right: \n") +
	std::string("4. Down: \n\n") +
	std::string("5. Check counter\n") +
	std::string("6. Check bathtub");

	intNumChoice(message, choice, 1, 6);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (currentLocation->collectedMoneyStatus() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "You found a dollar sitting on the counter. +$1.00" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			money += 1.00;
			currentLocation->changeCollectedMoneyStatus(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Nothing was found." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 6:
		std::cout << "*******************************************************************************" << std::endl;
		std::cout << "Yep. It's definitely a bathtub. Nothing is here." << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the kitchen space
*********************************************************************/
void Game::kitchenDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are in the kitchen." << std::endl;
	std::cout << "There is a cupboard, a fridge, and cooking supplies.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: Backyard\n" +
		std::string("2. Left: \n") +
		std::string("3. Right: \n") +
		std::string("4. Down: Living Room\n\n") +

		std::string("5. Check cupboard\n") +
		std::string("6. Check the fridge\n") +
		std::string("7. Cook\n");

	intNumChoice(message, choice, 1, 7);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (currentLocation->collectedMoneyStatus() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "You found a dollar hidden in the cupboard. +$1.00" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			money += 1.00;
			currentLocation->changeCollectedMoneyStatus(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Nothing was found." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 6:
		checkInventory();
		break;
	case 7:
		if (items[0].getItem() == true && items[1].getItem() == true && items[2].getItem() == true && items[3].getItem() == true && items[4].getItem() == true)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Cooking burger..." << std::endl;
			std::cout << "Cooking finished." << std::endl;
			std::cout << "Eating burger..." << std::endl;
			std::cout << "Eating finished!\n" << std::endl;
			std::cout << "Congratulations! You are no longer hungry! You have won the game!" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			gameOn = false;
			gameWon = true;
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Insufficient ingredients. Cannot cook a meal." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the front yard space
*********************************************************************/
void Game::frontYardDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are on the front yard." << std::endl;
	currentLocation->spaceDescription();

	timeLimit += currentLocation->atmosphere();

	std::string message = "\n1. Up: Living Room\n" +
	std::string("2. Left: \n") +
	std::string("3. Right: Go For a walk\n") +
	std::string("4. Down: Store\n\n") +
	std::string("5. Mow the lawn");

	intNumChoice(message, choice, 1, 5);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (currentLocation->grassStatus() == false)
		{
			timeLimit += 16;
		}
		currentLocation->mowGrass();
		break;
	}
}

/*********************************************************************
** Description: Dialogue for the backyard space
*********************************************************************/
void Game::backYardDialogue()
{
	currentLocation->printLocation();
	std::cout << "You are in the backyard." << std::endl;
	currentLocation->spaceDescription();
	std::cout << "There is a table and a shed.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	std::string message = "1. Up: \n" +
	std::string("2. Left: \n") +
	std::string("3. Right: \n") +
	std::string("4. Down: Kitchen\n\n") +
	std::string("5. Check Table\n") +
	std::string("6. Mow the grass\n") +
	std::string("7. Check the shed\n");

	intNumChoice(message, choice, 1, 7);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
		break;
	case 5:
		if (items[0].getItem() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "Found burger buns!" << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
			items[0].setItem(true);
		}
		else
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "There is nothing here." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		break;
	case 6:
		if (currentLocation->grassStatus() == false)
		{
			timeLimit += 16;
		}
		currentLocation->mowGrass();
		break;
	case 7:
		if (items[6].getItem() == false)
		{
			std::cout << "*******************************************************************************" << std::endl;
			std::cout << "It is locked." << std::endl;
			std::cout << "*******************************************************************************" << std::endl;
		}
		else
		{
			if (currentLocation->collectedMoneyStatus() == false)
			{
				std::cout << "*******************************************************************************" << std::endl;
				std::cout << "Used mysterious key to unlock the shed." << std::endl;
				std::cout << "Found $3.00! It looks like it's been sitting here for a while." << std::endl;
				std::cout << "*******************************************************************************" << std::endl;
				money += 3;
				currentLocation->changeCollectedMoneyStatus(true);
			}
			else
			{
				std::cout << "*******************************************************************************" << std::endl;
				std::cout << "There is nothing here." << std::endl;
				std::cout << "*******************************************************************************" << std::endl;
			}
		}
	}
}


/*********************************************************************
** Description: Dialogue for the outside space
*********************************************************************/
void Game::outsideDialogue()
{
	currentLocation->printLocation();
	currentLocation->spaceDescription();
	std::cout << "You are on a walk.\n" << std::endl;

	timeLimit += currentLocation->atmosphere();

	double floorMoney = currentLocation->generateFloorCash();

	std::cout << "*******************************************************************************" << std::endl;
	switch (currentLocation->generateLuck())
	{
	case 1:
		std::cout << "You found some money on the floor! +$" << floorMoney << std::endl;
		std::cout << "Your walk took some energy so you got hungrier. -3 hunger points" << std::endl;
		timeLimit -= 3;
		money += floorMoney;
		break;
	case 2:
		std::cout << "Nothing special happened on your walk and you only got hungrier." << std::endl;
		std::cout << "-10 hunger health." << std::endl;
		timeLimit -= 9;
		break;
	case 3:
		std::cout << "Nothing special happened on your walk and you only got hungrier." << std::endl;
		std::cout << "-10 hunger health." << std::endl;
		timeLimit -= 9;
		break;
	}
	std::cout << "*******************************************************************************" << std::endl;

	std::string message = "\n1. Up: \n" +
	std::string("2. Left: Go back home (front yard)\n") +
	std::string("3. Right: Keep Walking\n") +
	std::string("4. Down: Grocery Store\n\n");

	intNumChoice(message, choice, 1, 4);

	switch (choice)
	{
	case 1:
		currentLocation = currentLocation->goTo("top");
		break;
	case 2:
		currentLocation = currentLocation->goTo("left");
		break;
	case 3:
		currentLocation = currentLocation->goTo("right");
		break;
	case 4:
		currentLocation = currentLocation->goTo("bottom");
	}
}

/*********************************************************************
** Description: Dialogue for the Store Space
*********************************************************************/
void Game::storeDialogue()
{
	checkInventory();
	currentLocation->printLocation();

	timeLimit += currentLocation->atmosphere();

	std::cout << "Welcome to the store! What would you like to buy?" << std::endl;
	std::string message = "1. Burger Buns: $1.00\n" +
		std::string("2. Lettuce: $0.75\n") +
		std::string("3. Tomato: $0.50\n") +
		std::string("4. Krabby Patty: $3.00\n") +
		std::string("5. Secret Sauce: $2.00\n") +
		std::string("\n6. Leave the market\n");

	intNumChoice(message, choice, 1, 6);

	std::cout << "*******************************************************************************" << std::endl;
	switch (choice)
	{
	case 1:
		if (money >= 1)
		{
			if (currentLocation->inStock(choice) == true)
			{
				items[0].setItem(true);
				std::cout << "Bought burger buns! -$1.00" << std::endl;
				money -= 1;
			}
			else
			{
				std::cout << "Out of stock!" << std::endl;
			}
		}
		else
		{
			std::cout << "Not enough money." << std::endl;
		}
		break;
	case 2:
		if (money >= 0.75)
		{
			if (currentLocation->inStock(choice) == true)
			{
				items[1].setItem(true);
				std::cout << "Bought lettuce! -$0.75" << std::endl;
				money -= 0.75;
			}
			else
			{
				std::cout << "Out of stock!" << std::endl;
			}
		}
		else
		{
			std::cout << "Not enough money." << std::endl;
		}
		break;
	case 3:
		if (money >= 0.50)
		{
			if (currentLocation->inStock(choice) == true)
			{
				items[2].setItem(true);
				std::cout << "Bought tomato! -$0.50" << std::endl;
				money -= 0.50;
			}
			else
			{
				std::cout << "Out of stock!" << std::endl;
			}
		}
		else
		{
			std::cout << "Not enough money." << std::endl;
		}
		break;
	case 4:
		if (money >= 3)
		{
			if (currentLocation->inStock(choice) == true)
			{
				items[3].setItem(true);
				std::cout << "Bought krabby patties! -$3.00" << std::endl;
				money -= 3.00;
			}
			else
			{
				std::cout << "Out of stock!" << std::endl;
			}
		}
		else
		{
			std::cout << "Not enough money." << std::endl;
		}
		break;
	case 5:
		if (money >= 2)
		{
			if (currentLocation->inStock(choice) == true)
			{
				items[4].setItem(true);
				std::cout << "Bought the secret sauce! -$2.00" << std::endl;
				money -= 2.00;
			}
			else
			{
				std::cout << "Out of stock!" << std::endl;
			}
		}
		else
		{
			std::cout << "Not enough money." << std::endl;
		}
		break;
	case 6: // Quit
		std::cout << "Left the market." << std::endl;
		currentLocation = currentLocation->goTo("top");
		break;
	}
	std::cout << "*******************************************************************************\n" << std::endl;

}

/*********************************************************************
** Description: Check current inventory
*********************************************************************/
void Game::checkInventory()
{
	int counter = 0;
	std::cout << "===============================================================================" << std::endl;
	std::cout << "Current Inventory: " << std::endl;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].getItem() == true)
		{
			std::cout << items[i].getName() << std::endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Your inventory is empty." << std::endl;
	}
	std::cout << "\nCurrent cash holdings: $" << money << std::endl;
	std::cout << "===============================================================================" << std::endl;
}

/*********************************************************************
** Description: Check current balance
*********************************************************************/
double Game::checkBalance()
{
	return money;
}

/*********************************************************************
** Description: Check if user remembered password
*********************************************************************/
bool Game::checkRememberedPassword()
{
	return rememberedPassword;
}

/*********************************************************************
** Description: Change state if user remembers password
*********************************************************************/
void Game::changeRememberedPassword(bool choice)
{
	rememberedPassword = choice;
}

/*********************************************************************
** Description: Input Validation function
*********************************************************************/
void Game::intNumChoice(std::string question, int& answer, int min, int max)
{
	bool valid;
	char character;
	std::string input;
	int countNegatives = 0;

	do
	{
		countNegatives = 0;
		std::cout << question.c_str() << std::endl;
		std::cin >> (input);

		valid = true;

		for (int i = 0; (i < input.length()) && (valid == true); i++)
		{
			character = tolower((input)[i]);
			if (character == 45 || character > 47 && character < 58)
			{
				valid = true;
			}
			else
			{
				valid = false;
				std::cout << "Please enter a valid integer." << std::endl;
			}

			if (character == 45)
			{
				countNegatives++;
			}

		}

		// Check for negative numbers
		if (countNegatives > 1)
		{
			valid = false;
			std::cout << "Having more than one \"-\" is invalid." << std::endl;
		}
		else if (countNegatives == 1) // "-" only allowed in beginning
		{
			if (input.length() < 2) // There can't only be "-"
			{
				valid = false;
				std::cout << "- is not a number." << std::endl;
			}
			else if (tolower(input[0]) != 45)
			{
				valid = false;
				std::cout << "Negative numbers must be typed correctly." << std::endl;
			}
		}

		std::cout << "--------------------------------------------------------------------------------" << std::endl;

		if (valid == true)
		{
			answer = std::stoi(input);
		}

	} while ((valid == false) || (answer < min) || (answer > max));
}