//
// Created by Yegor Chernyshev on 3/16/21.
// 

#include <iostream>
#include <vector>
using namespace std;

// Constant Declarations
int TERM = -1;

// Function Declarations
void programOne();
void programTwo();

// Program One Functions
void getArrayInput(int &input, int* &numbers, int &arrSize);
void expandArray(int* &arr, int &arrSize);
void arrayNumberSearch(int *numbers, int &arrSize);

// Program Two Functions
void getVectorizedInput(int &input, vector<int> &numbers);
void vectorNumberSearch(vector<int> &numbers);

int main() {
    // Program 1:
    programOne();
    cout<<"\n"<<endl;
    // Program 2:
    programTwo();
    return 0;
}

// Program One [Array-Based]
void programOne() {
    int size = 5;
    int userInput = 0;
    int * userNumbersArray = new int[size];
    getArrayInput(userInput, userNumbersArray, size);

    arrayNumberSearch(userNumbersArray, size);
    delete [] userNumbersArray;
    userNumbersArray = nullptr;
}

void getArrayInput(int &input, int* &numbers, int &arrSize) {
    int numberOfNumbers = 0;
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;

    while(input != TERM) {
        cin>>input;

        if (numberOfNumbers == arrSize) {
            expandArray(numbers, arrSize);
        }

        numbers[numberOfNumbers] = input;
        numberOfNumbers++;
    }
}

void expandArray(int* &arr, int &arrSize) {
    int index;
    int * tempArray = new int[arrSize * 2];
    for (index = 0; index < arrSize; index++) {
        tempArray[index] = arr[index];
    }

    arrSize = arrSize * 2;
    delete [] arr;
    arr = tempArray;
}

void arrayNumberSearch(int *numbers, int &arrSize) {
    int foundIndexes[arrSize];
    int foundCount = 0;
    int num, index;

    cout<<"Please enter a number you want to search."<<endl;
    cin>>num;

    for (index = 0; index < arrSize; index++) {
        if (numbers[index] == num) {
            foundIndexes[foundCount] = index;
            foundCount++;
        }
    }

    if (foundCount > 0) {
        cout<<to_string(num)<<" shows in lines ";
        for (index = 0; index < foundCount; index++) {
            int foundIndex = foundIndexes[index] + 1;
            if (index == 0) {
                cout<<foundIndex;
            } else {
                cout<<", "<<foundIndex;
            }
        }
        cout<<".";
    } else {
        cout<<to_string(num)<<" NOT FOUND.";
    }
}

// Program Two [Vectorization]
void programTwo() {
    vector<int> userNumbers;
    int userInput = 0;
    getVectorizedInput(userInput, userNumbers);
    vectorNumberSearch(userNumbers);
}

// Functions
void getVectorizedInput(int &input, vector<int> &numbers) {

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;

    while(input != TERM) {
        cin>>input;
        numbers.push_back(input);
    }
}

void vectorNumberSearch(vector<int> &numbers) {
    int num, index;
    vector<int> lines;

    cout<<"Please enter a number you want to search."<<endl;
    cin>>num;

    for (index = 0; index < numbers.size(); index++) {
        if (numbers[index] == num) {
            lines.push_back(index);
        }
    }

    if (!lines.empty()) {
        cout<<to_string(num)<<" shows in lines ";
        for (index = 0; index < lines.size(); index++) {
            int foundIndex = lines[index] + 1;
            if (index == 0) {
                cout<<foundIndex;
            } else {
                cout<<", "<<foundIndex;
            }
        }
        cout<<".";
    } else {
        cout<<to_string(num)<<" NOT FOUND.";
    }
}
