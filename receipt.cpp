//
// Created by bennet on 10/11/16.
//

#include <iostream>
#include "receipt.h"
#include "drinkitem.h"

Receipt::Receipt(DrinkItem &drinkPurchased, double amountPaid)
{
    insufficientFunds = true;
    emptyOption = true;

    drink = drinkPurchased;

    this->amountPaid = amountPaid;
}

//	Returns true if the purchase completed without any errors.
bool Receipt::success() const
{
    if (insufficient())
    {
        return false;
    }
    else if (empty())
    {
        return false;
    }

    return true;
}

//	Return true if the amount pass for the purchase was less than the purchase price. Note that the price
//	should be checked before you check the quantity. If the amount is insufficient you should not check the
//  quantity.
bool Receipt::insufficient() const
{
    if (amountPaid < drink.getPrice())
        return true;
    else
        return false;
}

//	Return true if the quantity was 0.
bool Receipt::empty() const
{
    if (drink.getQuantity() == 0)
        return true;
    else
        return false;
}

//	Return the amount of change that is due to the purchaser of the drink. This amount is valid only if
//	success() returns true. If either insufficient() or empty() returns true the getChange() member
//	function must return 0.0.
double Receipt::getChange() const
{
    if (success()) {
        // std::cout << "amount paid: " << amountPaid << " drink price: " << drink.getPrice();
        return amountPaid - drink.getPrice();
    }
    else
        return 0.0;
}

Receipt::~Receipt()
{

}