//
// Created by bennet on 10/9/16.
//

#include "drinkmachine.h"
#include <fstream>
#include <string>
#include <iomanip>

DrinkMachine::DrinkMachine()
{
    maxNumDrinkItems = 25;

    std::ifstream drinkFile ("./drink.txt", std::ifstream::in);
    std::ofstream backup;
    backup.open ("./drink_backup.txt", std::ofstream::out);

    const int ID_WIDTH = 6;
    const int NAME_WIDTH = 25;
    const int PRICE_WIDTH = 10;
    const int QTY_WIDTH = 8;


    std::string line;

    // this line contains the number of drink items
    getline(drinkFile, line);

    numDrinkItems = std::stoi(line);

    drinkItemArray = new DrinkItem[numDrinkItems];

    int count = 0;
    while(count < numDrinkItems)
    {
        // parse each line and store it in an array of drink items
        drinkItemArray[count] = parseLineToDrinkItem(drinkFile);
        count++;
    }

    backup << numDrinkItems << std::endl;

    for (int i = 0; i < numDrinkItems; i++)
    {
        auto drink = drinkItemArray[i];

        backup << std::left << std::setw(NAME_WIDTH) << drink.getName()
               << std::right << std::setw(PRICE_WIDTH) << drink.getPrice()
               << std::setw(QTY_WIDTH) << drink.getQuantity()
               << std::endl;
    }

    drinkFile.close();
    backup.close();
}

// Parses each line name, price and quantity
DrinkItem DrinkMachine::parseLineToDrinkItem(std::ifstream& drinkFile)
{
    std::string temp_name, temp_price, temp_quantity;

    drinkFile >> temp_name >> temp_price >> temp_quantity;

    return DrinkItem(temp_name, std::stod(temp_price), std::stoi(temp_quantity));
}

// Returns the current number of DrinkItem entries being used by the drink machine.
unsigned int DrinkMachine::size() const
{
    return numDrinkItems;
}

// Returns the maximum number of DrinkItem entries allowed.
unsigned int DrinkMachine::max_size() const
{
    return maxNumDrinkItems;
}


// Return a reference to the drink item at the specified index.
DrinkItem& DrinkMachine::at(unsigned int index)
{
    return drinkItemArray[index];
}

// Returns a const reference to the specified drink item. This allows you to use a function that uses a
// const DrinkItem reference. You cannot update the DrinkItem object in this case.
const DrinkItem& DrinkMachine::at(unsigned int index) const
{
    return drinkItemArray[index];
}

// Return true if the drink item at index drinkId has a quantity of 1 or more. Return false otherwise.
bool DrinkMachine::available(unsigned int drinkId) const
{
    if (drinkItemArray[drinkId].getQuantity() > 0)
        return true;
    else
        return false;
}

// Get the price of the item at the specified index.
double DrinkMachine::getPrice(unsigned int drinkId) const
{
    return drinkItemArray[drinkId].getPrice();
}

Receipt DrinkMachine::purchase(unsigned int drinkId, double amount)
{
    auto receipt = Receipt(drinkItemArray[drinkId], amount);

    if (receipt.success())
        drinkItemArray[drinkId].purchase();

    return receipt;
}

void DrinkMachine::addDrinks(unsigned int drinkId, unsigned int amount)
{
    drinkItemArray[drinkId].addDrinks(amount);
}

void DrinkMachine::print(std::ostream& outStream) const
{
    const int ID_WIDTH = 6;
    const int NAME_WIDTH = 25;
    const int PRICE_WIDTH = 10;
    const int QTY_WIDTH = 8;

    // output some headers
    std::cout << std::setw(ID_WIDTH) << "ID #" << " ";
    std::cout << std::left << std::setw(NAME_WIDTH) << "Name" << std::right;
    std::cout << std::setw(PRICE_WIDTH) << "Price $";
    std::cout << std::setw(QTY_WIDTH) << "Qty";
    std::cout << std::setw(QTY_WIDTH) << "Sold";
    std::cout << std::setw(QTY_WIDTH) << "Sales ?";
    std::cout << std::endl;

    for (int i = 0; i < numDrinkItems; i++)
    {
        auto drink = drinkItemArray[i];

        std::cout << std::setw(ID_WIDTH) << i << " ";
        std::cout << std::left << std::setw(NAME_WIDTH) << drink.getName();
        std::cout << std::right << std::setw(PRICE_WIDTH) << drink.getPrice();
        std::cout << std::setw(QTY_WIDTH) << drink.getQuantity();
        std::cout << std::setw(QTY_WIDTH) << drink.getPurchased();
        std::cout << std::setw(QTY_WIDTH) << drink.getSales();
        std::cout << std::endl;
    }
}

double DrinkMachine::sales() const
{
    double total = 0.0;

    for (int i = 0; i < numDrinkItems; i++)
    {
        total += drinkItemArray[i].getSales();
    }

    return total;
}

double DrinkMachine::sales(unsigned int drinkId) const
{
    return drinkItemArray[drinkId].getSales();
}

DrinkMachine::~DrinkMachine()
{
    std::ofstream ofs;
    ofs.open ("./drink.txt", std::ofstream::out);

    const int ID_WIDTH = 6;
    const int NAME_WIDTH = 25;
    const int PRICE_WIDTH = 10;
    const int QTY_WIDTH = 8;

    ofs << numDrinkItems << std::endl;

    for (int i = 0; i < numDrinkItems; i++)
    {
        auto drink = drinkItemArray[i];

        ofs << std::left << std::setw(NAME_WIDTH) << drink.getName()
            << std::right << std::setw(PRICE_WIDTH) << drink.getPrice()
            << std::setw(QTY_WIDTH) << drink.getQuantity()
            << std::endl;
    }

    ofs.close();
}
