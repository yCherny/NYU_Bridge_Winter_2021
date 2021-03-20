//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
using namespace std;

int main() {

    int userInput;
    int index;

    int numberBeingEvaluated;
    int currentDigit, oddDigitCount, evenDigitCount;

    cout<<"Please input a positive integer: ";
    cin>>userInput;

    for (index=1; index<userInput; index++) {

        numberBeingEvaluated = index;

        oddDigitCount = 0;
        evenDigitCount = 0;

        while (numberBeingEvaluated > 0) {
            currentDigit = numberBeingEvaluated % 10;
            numberBeingEvaluated = (numberBeingEvaluated / 10);

            if (currentDigit % 2 == 0) {
                if (currentDigit != 0) {
                    evenDigitCount++;
                }
            } else {
                oddDigitCount++;
            }
        }

        if (evenDigitCount > oddDigitCount) {
            cout<<index<<endl;
        }
    }

    return 0;
}
