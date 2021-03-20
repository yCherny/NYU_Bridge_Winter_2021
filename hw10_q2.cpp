//
// Created by Yegor Chernyshev on 3/16/21.
// 

#include <iostream>
using namespace std;

// Constant Declarations
const int n = 6;

// Function Declarations
int* findMissing(int arr[], int n, int& resArrSize);

int main() {

    int resArraySize = 0;
    int arr[n] = {3, 1, 3, 0, 6, 4};

    int * missingNumbers;

    missingNumbers = findMissing(arr, n, resArraySize);

    cout<<"[";
    int index;
    for (index = 0; index < resArraySize; index++) {
        if (index == 0) {
            cout<<missingNumbers[index];
        } else {
            cout<<", "<<missingNumbers[index];
        }
    }
    cout<<"]";

    delete [] missingNumbers;
    missingNumbers = nullptr;

    return 0;
}

// Functions
int* findMissing(int arr[], int n, int& resArrSize) {
    int index;
    int comparisonArray[n+1];
    int * missingArray = new int[n];

    // Generates Array of Size (n+1) with the Entire Range from {0...n}
    for (index = 0; index < (n+1); index++) {
        comparisonArray[index] = index;
    }

    // Compares Values in Range to those in Argument Array
    // If a Value in the Range is Found at Least Once in the Passed in Array -> Flips Value at Index in Range to -1
    for (index = 0; index < n; index++) {
        int numberEvaluated = arr[index];
        if (numberEvaluated == comparisonArray[numberEvaluated]) {
            comparisonArray[numberEvaluated] = -1;
        }
    }

    // Finds Remaining Values in Range NOT Flipped to -1, Counts Them and Appends to 'missingArray'
    for (index = 0; index < (n+1); index++) {
        if (comparisonArray[index] != -1) {
            missingArray[resArrSize] = comparisonArray[index];
            resArrSize++;
        }
    }

    return missingArray;
}
