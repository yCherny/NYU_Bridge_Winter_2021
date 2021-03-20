//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Section A
    cout<<"section a"<<endl;

    int sequenceLength, index;
    double fixedLengthInput, fixedLengthProduct;
    double fixedLengthGeometricMean;

    cout<<"Please enter the length of the sequence: ";
    cin>>sequenceLength;
    cout<<"Please enter your sequence: "<<endl;

    fixedLengthProduct = 1;
    for (index = 0; index < sequenceLength; index++) {
        cin>>fixedLengthInput;
        fixedLengthProduct *= fixedLengthInput;
    }

    fixedLengthGeometricMean = pow(fixedLengthProduct, (1/(double)sequenceLength));
    cout<<"The geometric mean is: "<<fixedLengthGeometricMean<<endl;

    // Section B
    cout<<"section b"<<endl;

    int inputLength;
    double endlessLengthInput, endlessLengthProduct;
    double endlessLengthGeometricMean;

    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:"<<endl;

    endlessLengthProduct = 1;
    inputLength = 0;
    while (endlessLengthInput != -1) {
        cin>>endlessLengthInput;

        if (endlessLengthInput != -1) {
            inputLength++;
            endlessLengthProduct *= endlessLengthInput;
        }
    }

    endlessLengthGeometricMean = pow(endlessLengthProduct, (1/(double)inputLength));
    cout<<"The geometric mean is: "<<endlessLengthGeometricMean<<endl;

    return 0;
}
