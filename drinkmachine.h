#pragma once

#include <array>
#include <iostream>

#include "drinkitem.h"
#include "receipt.h"

class DrinkMachine
{
public:
	DrinkMachine();
    // The destructor will write the current list of items back to the output file, drink.txt. This will include the
    // new quantity values for the DrinkItem objects.
    ~DrinkMachine();

    // Returns the current number of DrinkItem entries being used by the drink machine.
    unsigned int size() const;
    // Returns the maximum number of DrinkItem entries allowed.
    unsigned int max_size() const;

    // Return a reference to the drink item at the specified index.
    DrinkItem& at(unsigned int index);

    // Returns a const reference to the specified drink item. This allows you to use a function that uses a
    //        const DrinkItem reference. You cannot update the DrinkItem object in this case.
    const DrinkItem& at(unsigned int index) const;

    // Return true if the drink item at index drinkId has a quantity of 1 or more. Return false otherwise.
    bool available(unsigned int drinkId) const;

    // Get the price of the item at the specified index.
    double getPrice(unsigned int drinkId) const;

    Receipt purchase(unsigned int drinkId, double amount);

    // Add amount number of drinks to the drink at drinkId
    void addDrinks(unsigned int drinkId, unsigned int amount);

    // Print the contents of the drink machine.
    void print(std::ostream& outStream) const;

    double sales() const;

    double sales(unsigned int drinkId) const;

private:
	// For this assignment this will have a value of 1.
	unsigned int versionNumber;

	// Contains the actual number of DrinkItem objects being used in the drink item array.
	unsigned int numDrinkItems;

	DrinkItem* drinkItemArray;
	unsigned int maxNumDrinkItems;

    DrinkItem parseLineToDrinkItem(std::ifstream& drinkFile);

    std::ifstream* drinkFile;
};