//
// Created by Yegor Chernyshev on 2/27/21.
// 

#import <iostream>
using namespace std;

// Function Declarations
void printArray(int arr[], int arrSize);      // Test Function Provided
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {

    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

// Testing Function Provided in HW8
void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

// Functions
void reverseArray(int arr[], int arrSize) {
    int index = 0;
    int arrSizeHalved = (int)(arrSize/2);
    int temporaryInt;

    // While The Center of the Array is Not Reached, Swap the Elements in the Opposite Indexes.
    while(index < arrSizeHalved) {
        int mirroredIndex = (arrSize - (index + 1));
        temporaryInt = arr[index];
        arr[index] = arr[mirroredIndex];
        arr[mirroredIndex] = temporaryInt;
        index++;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int index = 0;
    int elementsRemovedCount = 0;

    while(index < arrSize) {
        if (arr[index] % 2 != 0) {
            // Odd Element -> Move the Remaining Elements to the Left
            int moveIndex = index;

            while(moveIndex < arrSize) {
                arr[moveIndex] = arr[moveIndex + 1];
                moveIndex++;
            }

            elementsRemovedCount++;
        } else {
            index++;
        }
    }

    arrSize = arrSize - elementsRemovedCount;
}

void splitParity(int arr[], int arrSize) {
    int index = 0;
    int lastOddPosition = arrSize;

    while (index < arrSize) {
        int temporaryInt;

        if (arr[index] % 2 == 0) {

            while ((arr[lastOddPosition] % 2 == 0) && (lastOddPosition > index)) {
                lastOddPosition--;
            }

            // Swap the Even and Odd Elements
            temporaryInt = arr[index];
            arr[index] = arr[lastOddPosition];
            arr[lastOddPosition] = temporaryInt;
        }

        index++;
    }
}
