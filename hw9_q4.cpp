//
// Created by Yegor Chernyshev on 3/11/21.
// 

#include <iostream>
using namespace std;

// Constant Declarations
const int SIZE = 6;

// Functions Declaration
void oddsKeepEvensFlip(int arr[], int arraySize);

int main() {

    int i;
    int arr[SIZE] = {5, 2, 11, 7, 6, 4};
    int arrSize = SIZE;

    oddsKeepEvensFlip(arr, arrSize);

    // Simply Outputs the Result to the Console for Easier Review
    cout<<"[";
    for (i = 0; i < arrSize; i++) {
        if (i ==0 ) {
            cout<<arr[i];
        } else {
            cout<<", "<<arr[i];
        }
    }
    cout<<"]";

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arraySize) {

    // Retrieve the Number of Even Numbers in Array
    int i, numberOfEvens = 0;
    for (i = 0; i < arraySize; i++) {
        if (arr[i] % 2 == 0) {
            numberOfEvens++;
        }
    }

    // Delegate temporary array for even numbers and their sorting
    int evenIndex = 0;
    int tempArray[numberOfEvens];
    for (i = 0; i < arraySize; i++) {
        if (arr[i] % 2 == 0) {
            tempArray[evenIndex] = arr[i];
            evenIndex++;
        }
    }

    int lastIndex;
    int flipCount = (int)(numberOfEvens / 2);
    for (i = 0; i < flipCount; i++) {

        lastIndex = (numberOfEvens - i) - 1;

        int currentNumber = tempArray[i];
        int lastNumber = tempArray[lastIndex];

        tempArray[i] = lastNumber;
        tempArray[lastIndex] = currentNumber;
    }

    // Sort Odds of Main Array
    int lastOddIndex = 0;
    int lastEvenIndex = 0;

    for (i = 0; i < arraySize; i++) {
        if (arr[i] % 2 != 0) {
            // Number is Odd
            int lastNumber = arr[lastEvenIndex];
            arr[lastEvenIndex++] = arr[i];
            arr[i] = lastNumber;
            lastOddIndex = lastEvenIndex;
        }
    }

    // Combining the Odd and Even Sorted Arrays
    for (i = 0; i < numberOfEvens; i++) {
        arr[lastOddIndex + i] = tempArray[i];
    }
}
