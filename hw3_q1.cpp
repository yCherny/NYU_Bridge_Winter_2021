//
// Created by Yegor Chernyshev on 1/29/21.
//

#include <iostream>
using namespace std;

const double TAX_RATE_CONVERSION = 100.0;
const double HALF_OFF_PROMOTION = 0.5;
const double CLUB_DISCOUNT = 0.1;

int main() {

    double firstItemPrice, secondItemPrice, taxRate;
    double basePrice, priceAfterDiscounts, taxRateDecimal, finalCost;
    char hasClubCard;

    cout<<"Enter price of first item: ";
    cin>>firstItemPrice;

    cout<<"Enter price of second item: ";
    cin>>secondItemPrice;

    cout<<"Does customer have a club card? (Y/N): ";
    cin>>hasClubCard;

    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;

    // MATH
    basePrice = firstItemPrice + secondItemPrice;

    // Calculates Which Item is Cheaper and Gets the Half Off Discount
    if (firstItemPrice > secondItemPrice) {
        secondItemPrice -= (secondItemPrice * HALF_OFF_PROMOTION);
    } else {
        firstItemPrice -= (firstItemPrice * HALF_OFF_PROMOTION);
    }

    priceAfterDiscounts = firstItemPrice + secondItemPrice;

    // If Customer is a Club Member -> Additional 10% Off
    if (hasClubCard == 'Y' || hasClubCard == 'y') {
        priceAfterDiscounts -= (priceAfterDiscounts * CLUB_DISCOUNT);
    }

    // Taxes Applied
    taxRateDecimal = (taxRate / TAX_RATE_CONVERSION);
    finalCost = priceAfterDiscounts + (priceAfterDiscounts * taxRateDecimal);

    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<priceAfterDiscounts<<endl;
    cout<<"Total price: "<<finalCost<<endl;



    return 0;
}
