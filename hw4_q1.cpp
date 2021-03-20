//
// Created by Yegor Chernyshev on 2/2/21.
//

#include <iostream>
using namespace std;

int main() {

    // Section A
    cout<<"section a"<<endl;

    int nWhile, startWhile, currentWhile;

    cout<<"Please enter a positive integer: ";
    cin>>nWhile;

    startWhile = 0;
    currentWhile = 0;
    while(startWhile < nWhile) {
        startWhile++;
        currentWhile += 2;
        cout<<currentWhile<<endl;
    }

    // Section B
    cout<<"section b"<<endl;

    int nFor, startFor, currentFor;

    cout<<"Please enter a positive integer: ";
    cin>>nFor;

    currentFor = 0;
    for (startFor = 0; startFor < nFor; startFor++) {
        currentFor += 2;
        cout<<currentFor<<endl;
    }

    return 0;
}
