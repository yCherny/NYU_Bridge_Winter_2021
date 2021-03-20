//
// Created by Yegor Chernyshev on 2/19/21.
//

#include <iostream>

using namespace std;

// Function Declarations
int fib(int n);

int main() {

    int userNum, factResult;

    cout<<"Please enter a positive integer: ";
    cin>>userNum;

    factResult = fib(userNum);
    cout<<factResult<<endl;

    return 0;
}

// Fibonacci Sequence
int fib(int n) {
    // Fibonacci Begins at F3
    int currentSum;
    int previousSum = 0;
    int newSum = 1;

    for (int i = 0; i < (n-1); i++) {
        currentSum = newSum;
        newSum = currentSum + previousSum;
        previousSum = currentSum;
    }

    return newSum;
}
