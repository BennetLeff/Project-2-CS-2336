#pragma once

#include <string>

class DrinkItem
{
public:
	DrinkItem();
	DrinkItem(std::string name, double price, unsigned int quantity);
	~DrinkItem();

    double getPrice() const;
    double getSales() const;
    unsigned int getQuantity() const;
    unsigned int getPurchased() const;

    std::string getName() const;

    void setPrice(double newPrice);
    void setName(std::string newName);

    // Updates the drink quantity by the specified amount
    void addDrinks(unsigned int amount);

    /*
     * If there is at least 1 drink
     * remaining the purchase member function will subtract 1 drink from the number of drinks, add 1 to the
     * drinks purchased, add the cost of the drink to sales, and return a true value. Otherwise return false.
     */
    bool purchase();

private:
	// Drink name (type of drink – read in from a file).
	std::string name;

	 /*
      * Drink cost (the retail cost of one drink). This is the price the customer will pay for one
      * drink of this type. This is also read in from a file.
      */
	double price;

	/* 
	 * Number of drinks, of this type, in the machine. Initial value is read in from a file.
	 * This is also updated by the program.
     */
	unsigned int quantity;

    // Drinks purchased. Initially 0. Updated whenever a drink is purchased.
	unsigned int purchased;

	/* 
	 * This is used to keep track of the amount of money paid for all of the drinks purchased.
	 * Every time there is a successful purchase the amount of the purchase should be added to sales.
	 * You need to initially set this to 0.
	 */
	double sales; 
	
};