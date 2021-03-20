//
// Created by Yegor Chernyshev on 3/12/21.
// 

#include <iostream>
using namespace std;

// Constant Declarations
const int SIZE = 6;

// Function Declarations
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void showArray(int* arr, int arrSize);

int main() {

    // Variables
    int arr[SIZE] = {3, -1, -3, 0, 6, 4};
    int posArraySize;

    // Pointers
    int *ptrPosArraySize = &posArraySize;
    int *posNums1;
    int *posNums2;

    posNums1 = getPosNums1(arr, SIZE, posArraySize);
    showArray(posNums1, posArraySize);
    cout<<"getPostNums1: [Base Address of Array: "<<&posNums1<<" | Array's Logical Size: "<<posArraySize<<" | Value at Base Address: "<<*posNums1<<"]"<<endl;

    posNums2 = getPosNums2(arr, SIZE, &posArraySize);
    showArray(posNums2, posArraySize);
    cout<<"getPostNums2: [Base Address of Array: "<<&posNums2<<" | Array's Logical Size Address: "<<&ptrPosArraySize<<" | Value at Base Address: "<<*posNums2<<" | Value at Array's Logical Size Address: "<<*ptrPosArraySize<<"]"<<endl;

    getPosNums3(arr, SIZE, posNums1, *ptrPosArraySize);
    showArray(posNums1, *ptrPosArraySize);
    cout<<"getPostNums3: [Base Address of Array: "<<&posNums1<<" | Array's Logical Size Address: "<<&posArraySize<<" | Value at Base Address: "<<*posNums1<<" | Value at Array's Logical Size Address: "<<posArraySize<<"]"<<endl;

    getPosNums4(arr, SIZE, &posNums2, ptrPosArraySize);
    showArray(posNums2, *ptrPosArraySize);
    cout<<"getPostNums3: [Base Address of Array: "<<&posNums2<<" | Array's Logical Size Address: "<<ptrPosArraySize<<" | Value at Base Address: "<<*posNums1<<" | Value at Array's Logical Size Address: "<<*ptrPosArraySize<<"]"<<endl;

    // Deallocate Resources
    delete [] posNums1;
    delete [] posNums2;

    // Nullify Pointers
    posNums1 = nullptr;
    posNums2 = nullptr;

    return 0;
}


// Returns the Base Address of the Array
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    // Generates New Array
    int* newArray = new int [arrSize];

    // Copies Positive Numbers from Original Array into New Array
    int index, newArrayIndex = 0;
    for (index = 0; index < arrSize; index++) {
        if (arr[index] > 0) {
            newArray[newArrayIndex] = arr[index];
            newArrayIndex++;
        }
    }

    outPosArrSize = newArrayIndex;
    return newArray;
}

// Returns the Base Address of the Array
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    // Generates New Array
    int* newArray = new int [arrSize];

    // Copies Positive Numbers from Original Array into New Array
    int index, newArrayIndex = 0;
    for (index = 0; index < arrSize; index++) {
        if (arr[index] > 0) {
            newArray[newArrayIndex] = arr[index];
            newArrayIndex++;
        }
    }

    // Uses Dereferencing Operator to Get the Data at ouPosArrSizePtr and Update its Raw Value with newArrayIndex
    *outPosArrSizePtr = newArrayIndex;
    return newArray;
}

// Updates Output Parameter With the Base Address of the Array
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    // Generates New Array
    int* newArray = new int [arrSize];

    // Copies Positive Numbers from Original Array into New Array
    int index, newArrayIndex = 0;
    for (index = 0; index < arrSize; index++) {
        if (arr[index] > 0) {
            newArray[newArrayIndex] = arr[index];
            newArrayIndex++;
        }
    }

    // Return Output
    outPosArr = newArray;
    outPosArrSize = newArrayIndex;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {

    // Generates New Array
    int* newArray = new int [arrSize];

    // Copies Positive Numbers from Original Array into New Array
    int index, newArrayIndex = 0;
    for (index = 0; index < arrSize; index++) {
        if (arr[index] > 0) {
            newArray[newArrayIndex] = arr[index];
            newArrayIndex++;
        }
    }

    // Return Output
    *outPosArrPtr = newArray;
    outPosArrSizePtr = &newArrayIndex;
}

void showArray(int* arr, int arrSize) {
    int index = 0;
    cout<<"[";
    for (index = 0; index < arrSize; index++) {
        if (index == 0) {
            cout<<arr[index];
        } else {
            cout<<", "<<arr[index];
        }
    }
    cout<<"]"<<endl;
}
