//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
#include <string>
using namespace std;

// Roman Numeral Constants
const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

// Appearance Constraints
const int limitDLV = 1;
const int limitCXI = 4;

int main() {

    int userNumber, remainingValue;
    int mCount, dCount, cCount, lCount, xCount, vCount, iCount;
    string romanOutput;

    cout<<"Enter decimal number:"<<endl;
    cin>>userNumber;

    // Initialization
    remainingValue = userNumber;
    mCount = 0;
    dCount = 0;
    cCount = 0;
    lCount = 0;
    xCount = 0;
    vCount = 0;
    iCount = 0;

    // Conversion
    while(remainingValue > 0) {
         if (remainingValue >= M) {
             mCount++;
             remainingValue -= M;
             romanOutput += "M";
         } else if (remainingValue >= D && dCount < limitDLV) {
             dCount++;
             remainingValue -= D;
             romanOutput += "D";
         } else if (remainingValue >= C && cCount < limitCXI) {
             cCount++;
             remainingValue -= C;
             romanOutput += "C";
         } else if (remainingValue >= L && lCount < limitDLV) {
             lCount++;
             remainingValue -= L;
             romanOutput += "L";
         } else if (remainingValue >= X && xCount < limitCXI) {
             xCount++;
             remainingValue -= X;
             romanOutput += "X";
         } else if (remainingValue >= V && vCount < limitDLV) {
             vCount++;
             remainingValue -= V;
             romanOutput += "V";
         } else if (remainingValue >= I && iCount < limitCXI) {
             iCount++;
             remainingValue -= I;
             romanOutput += "I";
         }
    }

    cout<<userNumber<<" is "<<romanOutput<<endl;

    return 0;
}
