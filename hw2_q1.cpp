/* Yegor Chernyshev NYU Bridge 2021*/

#include <iostream>
using namespace std;

const int CENTS_IN_DOLLAR = 100, QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5;

int main() {

    int pennies, nickels, dimes, quarters;
    int penniesTotal, nickelsTotal, dimesTotal, quartersTotal;
    int dollarTotal, coinsRemaining;

    cout<<"Please enter number of coins:"<<endl;

    cout<<"# of quarters: ";
    cin>>quarters;

    cout<<"# of dimes: ";
    cin>>dimes;

    cout<<"# of nickels: ";
    cin>>nickels;

    cout<<"# of pennies: ";
    cin>>pennies;

    /* Basic math to count total dollar value */
    quartersTotal = quarters * QUARTER_VALUE;
    dimesTotal = dimes * DIME_VALUE;
    nickelsTotal = nickels * NICKEL_VALUE;
    penniesTotal = pennies;

    dollarTotal = (penniesTotal+nickelsTotal+dimesTotal+quartersTotal) / CENTS_IN_DOLLAR;
    coinsRemaining = (penniesTotal+nickelsTotal+dimesTotal+quartersTotal) % CENTS_IN_DOLLAR;

    cout<<"The total is "<<dollarTotal<<" dollars and "<<coinsRemaining<<" cents"<<endl;

    return 0;
}
