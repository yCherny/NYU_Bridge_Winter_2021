/* Yegor Chernyshev NYU Bridge 2021*/

#include <iostream>
using namespace std;

const int CENTS_IN_DOLLAR = 100, QUARTER_VALUE = 25, DIME_VALUE = 10, NICKEL_VALUE = 5;

int main() {

    int dollarAmount, centAmount;
    int quartersNeeded, dimesNeeded, nickelsNeeded, penniesNeeded;
    int centsRemaining;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space: "<<endl;
    cin>>dollarAmount>>centAmount;
    cout<<dollarAmount<<" dollars and "<<centAmount<<" cents are:"<<endl;

    /* Math */
    centsRemaining = (dollarAmount * CENTS_IN_DOLLAR) + centAmount;

    quartersNeeded = (centsRemaining / QUARTER_VALUE);
    centsRemaining -= (quartersNeeded * QUARTER_VALUE);

    dimesNeeded = (centsRemaining / DIME_VALUE);
    centsRemaining -= (dimesNeeded * DIME_VALUE);

    nickelsNeeded = (centsRemaining / NICKEL_VALUE);
    centsRemaining -= (nickelsNeeded * NICKEL_VALUE);

    penniesNeeded = (centsRemaining);

    cout<<quartersNeeded<<" quarters, "<<dimesNeeded<<" dimes, "<<nickelsNeeded<<" nickels and "<< penniesNeeded<<" pennies"<<endl;

    return 0;
}
