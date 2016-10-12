#include "drinkitem.h"

DrinkItem::DrinkItem()
{
	name = "";
	
	price = 0.0;
	sales = 0.0;

	quantity = 0;
	purchased = 0; 
};

DrinkItem::DrinkItem(std::string name, double price, unsigned int quantity)
{
	this->name = name;
	
	this->price = price;
	sales = 0.0;

	this->quantity = quantity;
	purchased = 0; 
};

double DrinkItem::getPrice() const
{
    return price;
}

double DrinkItem::getSales() const
{
    return sales;
}

unsigned int DrinkItem::getQuantity() const
{
    return quantity;
}

unsigned int DrinkItem::getPurchased() const
{
    return purchased;
}

std::string DrinkItem::getName() const
{
    return name;
}

void DrinkItem::setPrice(double newPrice)
{
    price = newPrice;
}

void DrinkItem::setName(std::string newName)
{
    name = newName;
}

// Updates the drink quantity by the specified amount
void DrinkItem::addDrinks(unsigned int amount)
{
    quantity += amount;
}

bool DrinkItem::purchase()
{
    if (quantity > 0)
    {
        quantity--;
        purchased++;
        sales += price;
        return true;
    }
    else
    {
        return false;
    }

}

DrinkItem::~DrinkItem()
{

}