//
// Created by Yegor Chernyshev on 2/27/21.
// 

#include <iostream>
using namespace std;

// Constants
const int MAX_ARRAY_SIZE = 20;

// Function Declarations
int minInArray(int arr[], int arrSize);

int main() {

    int userNumbers[MAX_ARRAY_SIZE];
    int index, userNum, minValue;

    cout<<"Please enter 20 integers separated by a space:"<<endl;

    for (index = 0; index < (MAX_ARRAY_SIZE-1); index++) {
        cin>>userNum;
        userNumbers[index] = userNum;
    }

    minValue = minInArray(userNumbers, MAX_ARRAY_SIZE);
    cout<<"The minimum value is "<<minValue<<", and it is located in the following indices:";

    for(index = 0; index < (MAX_ARRAY_SIZE-1); index++) {
        if (minValue == userNumbers[index]) {
            cout<<" "<<index;
        }
    }

    return 0;
}

/*
 *  This function is given arr, an array of integers, and its logical size, arrSize. When called,
 *  it returns the minimum value in arr.
 * */
int minInArray(int arr[], int arrSize) {
    int index, smallestNumber = arr[0];
    for (index = 0; index<(arrSize-1); index++) {
        if (arr[index] < smallestNumber) {
            smallestNumber = arr[index];
        }
    }

    return smallestNumber;
}
