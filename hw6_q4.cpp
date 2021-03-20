//
// Created by Yegor Chernyshev on 2/19/21.
//

#import <iostream>
#import <string>
#import <cmath>
using namespace std;

// Function Declarations
void printDivisors(int num);

int main() {

    int userNum = 0;

    while(userNum < 2) {
        cout<<"Please enter a positive integer >=2: ";
        cin>>userNum;
    }

    printDivisors(userNum);

    return 0;
}

void printDivisors(int num) {
    int maxDivisor = sqrt((double)num);
    string lowerDivisors;
    string upperDivisors;

    // Iteration of Divisors from i to sqrt(num)
    for (int i=1; i<maxDivisor; i++) {

        if (num%i == 0) {
            cout<<i<<" ";
        }
    }

    for (int i=maxDivisor; i > 0; i--) {
        if (num%i == 0) {
            int divisorTwo = (num / i);
            cout<<divisorTwo<<" ";
        }
    }
}
