//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int userNumber, remainderValue, remainingValue, index;
    int binaryRepresentation;

    cout<<"Enter decimal number: "<<endl;
    cin>>userNumber;

    // Algorithm
    index = 0;
    binaryRepresentation = 0;
    remainingValue = userNumber;
    while (remainingValue > 0) {
        remainderValue = (remainingValue % 2);
        remainingValue = (remainingValue / 2);
        binaryRepresentation += (int)(remainderValue * pow((double)10, (double)index));
        index++;
    }

    cout<<"The binary representation of "<<userNumber<<" is "<<binaryRepresentation;

    return 0;
}
