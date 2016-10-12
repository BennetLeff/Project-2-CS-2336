#pragma once

#include "drinkitem.h"

class Receipt
{
public:
	Receipt(DrinkItem& drinkPurchased, double amountPaid);
	~Receipt();

    //	Returns true if the purchase completed without any errors.
	bool success() const;

    //	Return true if the amount pass for the purchase was less than the purchase price. Note that the price
    //	should be checked before you check the quantity. If the amount is insufficient you should not check the
    //  quantity.
	bool insufficient() const;

    //	Return true if the quantity was 0.
    bool empty() const;

    //	Return the amount of change that is due to the purchaser of the drink. This amount is valid only if
    //	success() returns true. If either insufficient() or empty() returns true the getChange() member
    //	function must return 0.0.
	double getChange() const;

private:
    bool insufficientFunds, emptyOption;
    double amountPaid = 0.0;
    DrinkItem drink;
};